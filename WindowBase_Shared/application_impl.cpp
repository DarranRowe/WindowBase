#include "application_impl.hpp"
#include "windowbase/application_helper.hpp"
#include "windowbase/output_helpers.hpp"
#include "windowbase/utility.hpp"

#include <ShObjIdl.h>

#pragma comment(lib, "windowsapp.lib")

namespace window_base::application::details
{
	using utility::conversion::value_convert;
	using output_helpers::debug::format_debugwriteln;

	static application_impl *g_app_inst{ nullptr };
	static std::mutex g_app_inst_mutex;

	using SetThreadCursorCreationScaling_t = UINT(UINT);
	using SetThreadCursorCreationScaling_ptr_t = UINT(WINAPI *)(UINT);
	static std::function<SetThreadCursorCreationScaling_t> s_pSetThreadCursorCreationScaling;

	static bool s_SetThreadCursorCreationScaling_init{};
	static HMODULE user32_mod{ nullptr };

	static void init_SetThreadCursorCreationScaling()
	{
		user32_mod = LoadLibraryExW(L"user32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);

		_ASSERTE(user32_mod != nullptr);

		s_pSetThreadCursorCreationScaling = reinterpret_cast<SetThreadCursorCreationScaling_ptr_t>(GetProcAddress(user32_mod, "SetThreadCursorCreationScaling"));

		s_SetThreadCursorCreationScaling_init = true;
	}

	static UINT SetThreadCursorCreationScalingWrapper(UINT dpi)
	{
		if (!s_SetThreadCursorCreationScaling_init)
		{
			init_SetThreadCursorCreationScaling();
		}

		_ASSERTE(s_pSetThreadCursorCreationScaling != nullptr);

		return s_pSetThreadCursorCreationScaling(dpi);
	}

	void application_impl::add_ref_impl() noexcept
	{
		if (g_app_inst == nullptr)
		{
			format_debugwriteln(L"Instance found to be nullptr in add_ref_impl.");
		}
		_ASSERTE(g_app_inst != nullptr);
		std::scoped_lock lock{ g_app_inst_mutex };
		g_app_inst->add_ref();
	}

	void application_impl::release_impl() noexcept
	{
		if (g_app_inst == nullptr)
		{
			format_debugwriteln(L"Instance found to be nullptr in release_impl.");
		}
		_ASSERTE(g_app_inst != nullptr);
		std::scoped_lock lock{ g_app_inst_mutex };
		auto still_alive{ g_app_inst->release() };
		if (!still_alive)
		{
			g_app_inst = nullptr;
		}
	}

	application_impl *application_impl::make_new_instance() noexcept
	{
		application_impl *impl{ nullptr };

		std::scoped_lock lock{ g_app_inst_mutex };
		if (g_app_inst != nullptr)
		{
			format_debugwriteln(L"Instance not null in make_new_instance.");
			//Since this returns the current instance, the reference count must be
			//incremented.
			g_app_inst->add_ref();
			return g_app_inst;
		}

		try
		{
			//The implementation is created with 1 reference.
			impl = new application_impl;
		}
		catch (std::bad_alloc &)
		{
			format_debugwriteln(L"std::bad_alloc thrown in make_new_instance.");
		}
		catch (...)
		{
			format_debugwriteln(L"Unknown exception thrown in make_new_instance.");
		}

		if (impl)
		{
			g_app_inst = impl;
		}

		return impl;
	}

	application_impl *application_impl::get_current_instance() noexcept
	{
		//We don't use the mutex here.
		//get_current_instance should only ever be called from a live
		//class. This way, we know the reference count is always >= 1.

		return g_app_inst;
	}

	application_impl *application_impl::unsafe_get_current_instance() noexcept
	{
		//For cases such as application::try_get_current_instance.
		//We don't know if there is an existing application, and we could catch
		//it during a release. We use the mutex in this case to be sure
		//that application_impl is fine and we add_ref it.
		//The operation that called this is responsible for removing the extra
		//reference.
		std::scoped_lock lock{ g_app_inst_mutex };
		if (g_app_inst)
		{
			//Be sure that our application implementation is not going anywhere.
			g_app_inst->add_ref();
		}

		return g_app_inst;
	}

	application_impl::application_impl() noexcept
	{
		m_application_thread_id = get_current_thread_id();
	}

	application_impl::~application_impl() noexcept
	{
	}

	void application_impl::add_ref() noexcept
	{
		//This should never happen.
		_ASSERTE(m_refs != 0);
		++m_refs;
	}

	bool application_impl::release() noexcept
	{
		_ASSERTE(m_refs != 0);

		//The return value of this is whether the
		//implementation is considered alive.
		auto refs{ --m_refs };
		if (refs == 0)
		{
			delete this;
			return false;
		}

		return true;
	}

	bool application_impl::is_thread_ui_thread(uint32_t tid) noexcept
	{
		auto current_tid{ get_current_thread_id() };

		//We need to check this.
		//GetGUIThreadInfo will convert a thread to a GUI thread
		//if it isn't already, IsGUIThread will not.
		if (tid == current_tid)
		{
			return IsGUIThread(FALSE) != FALSE;
		}

		GUITHREADINFO gti{ sizeof(GUITHREADINFO) };
		return GetGUIThreadInfo(tid, &gti) != FALSE;
	}

	bool application_impl::is_thread_in_message_pump(uint32_t tid) noexcept
	{
		auto &tdm{ get_data_map() };
		std::shared_lock sl{ tdm.lookup_mutex };

		auto it{ tdm.lookup_map.find(tid) };
		if (it != std::end(tdm.lookup_map))
		{
			return (*it).second->in_message_pump;
		}

		return false;
	}

	void application_impl::set_aumid(const std::wstring_view &aumid) noexcept
	{
		SetCurrentProcessExplicitAppUserModelID(aumid.data());
	}

	std::optional<std::wstring> application_impl::get_aumid() noexcept
	{
		//GetCurrentProcessExplicitAppUserModelID returns E_FAIL if no AUMID has been set.
		//It seems to try to access the memory location without a null check, so assume that
		//E_FAIL means no AUMID.

		wil::unique_cotaskmem_string aumid;
		auto result{ GetCurrentProcessExplicitAppUserModelID(aumid.addressof()) };
		if (FAILED(result))
		{
			format_debugwriteln(LR"(GetCurrentProcessExplicitAppUserModelID failed.
This potentially means the AUMID wasn't set for the process.
)");
			return std::nullopt;
		}

		return std::optional(aumid.get());
	}

	void application_impl::enable_mouse_in_pointer() noexcept
	{
		EnableMouseInPointer(TRUE);
	}

	bool application_impl::is_mouse_in_pointer_enabled() noexcept
	{
		auto result = IsMouseInPointerEnabled();
		return result != FALSE;
	}

	dpi_awareness application_impl::get_process_dpi_awareness() noexcept
	{
		auto ctx{ GetDpiAwarenessContextForProcess(GetCurrentProcess()) };
		return awareness_ctx_to_awareness(ctx);
	}

	dpi_awareness application_impl::get_thread_dpi_awareness() noexcept
	{
		auto ctx{ GetThreadDpiAwarenessContext() };
		return awareness_ctx_to_awareness(ctx);
	}

	dpi_awareness application_impl::set_thread_dpi_awareness(dpi_awareness awareness) noexcept
	{
		auto ctx{ awareness_to_awareness_ctx(awareness) };

		return awareness_ctx_to_awareness( SetThreadDpiAwarenessContext(ctx));
	}

	dpi_hosting_behaviour application_impl::get_thread_dpi_hosting_behaviour() noexcept
	{
		return convert_behaviour_from_api(GetThreadDpiHostingBehavior());
	}

	dpi_hosting_behaviour application_impl::set_thread_dpi_hosting_behaviour(dpi_hosting_behaviour b) noexcept
	{
		return convert_behaviour_from_api(SetThreadDpiHostingBehavior(convert_behaviour_to_api(b)));
	}

	uint32_t application_impl::set_thread_cursor_creation_scaling(uint32_t dpi)
	{
		using utility::conversion::value_convert;

		if (window_base::application::helper::is_at_least_windows_10_build(22000))
		{
			return value_convert<uint32_t>(SetThreadCursorCreationScalingWrapper(value_convert<UINT>(dpi)));
		}

		output_helpers::debug::format_debugwriteln(L"SetThreadCursorCreationScaling is available from Windows 11 (22000), {} detected.", window_base::application::helper::get_windows_10_build());
		return 0;
	}

	void application_impl::send_pump_exit_for_thread(uint32_t tid, int result) noexcept
	{
		post_quit_message_for_thread(tid, result);
	}

	uint32_t application_impl::get_main_thread_id() const noexcept
	{
		return m_application_thread_id;
	}

	bool application_impl::is_current_thread_main_thread() const noexcept
	{
		return get_current_thread_id() == m_application_thread_id;
	}

	uint32_t application_impl::add_callback(pump_callback_wrapper callback, uint32_t identifier, uint32_t tid)
	{
		std::unique_ptr<callback_information> ci{ std::make_unique<callback_information>(callback_information{ std::move(callback), identifier }) };

		auto &tpi{ get_pump_info_for_thread(tid) };
		uint32_t cookie{};

		{
			std::unique_lock sl{ tpi.callback_mutex };
			cookie = tpi.callback_cookie++;

			tpi.callback_info.emplace(std::pair(cookie, std::move(ci)));
		}

		return cookie;
	}

	void application_impl::clear_callbacks(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };
		std::unique_lock sl{ tpi.callback_mutex };
		tpi.callback_info.clear();
	}

	void application_impl::remove_callback(uint32_t cookie, uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };
		std::unique_lock sl{ tpi.callback_mutex };
		auto it{ tpi.callback_info.find(cookie) };
		if (it != tpi.callback_info.end())
		{
			tpi.callback_info.erase(it);
		}
	}

	void application_impl::add_work_callback(work_callback_wrapper callback, uint32_t tid)
	{
		auto wi{ std::make_unique<work_callback_wrapper>(std::move(callback)) };

		auto &tpi{ get_pump_info_for_thread(tid) };

		{
			std::unique_lock sl{ tpi.callback_mutex };

			tpi.callback_work_information.reset(wi.release());
		}
	}

	void application_impl::remove_work_callback(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		{
			std::unique_lock sl{ tpi.callback_mutex };

			tpi.callback_work_information.reset();
		}
	}

	void application_impl::set_message_pump_to_ansi(bool use_ansi, uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		//We don't use any extra locking here.
		//Accessing the structure across threads is not possible.
		tpi.is_pump_ansi = use_ansi;
	}

	bool application_impl::is_message_pump_ansi(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		return tpi.is_pump_ansi;
	}

	int application_impl::run_ansi_message_pump(uint32_t tid)
	{
		return run_message_pump<false>(tid);
	}

	int application_impl::run_unicode_message_pump(uint32_t tid)
	{
		return run_message_pump<true>(tid);
	}

	int application_impl::run_ansi_game_message_pump(uint32_t tid)
	{
		return run_game_message_pump<false>(tid);
	}

	int application_impl::run_unicode_game_message_pump(uint32_t tid)
	{
		return run_game_message_pump<true>(tid);
	}

	void application_impl::clear_ansi_message_queue(uint32_t tid)
	{
		clear_message_queue<false>(tid);
	}

	void application_impl::clear_unicode_message_queue(uint32_t tid)
	{
		clear_message_queue<true>(tid);
	}

	bool application_impl::convert_thread_to_ui_thread() noexcept
	{
		return IsGUIThread(TRUE) != FALSE;
	}

	thread_data_map &application_impl::get_data_map()
	{
		static thread_data_map tdm{};

		return tdm;
	}

	void application_impl::init_data_for_thread(uint32_t tid)
	{
		auto &tdm{ get_data_map() };

		std::pair<std::map<uint32_t, std::unique_ptr<thread_pump_information>>::iterator, bool> emplace_result{};

		{
			std::unique_lock sl{ tdm.lookup_mutex };
			auto find_result{ tdm.lookup_map.find(tid) };
			if (find_result != tdm.lookup_map.end())
			{
				auto &mytpi{ *(*find_result).second.get() };
				mytpi.thread_refs += 1;
			}
			else
			{
				emplace_result = tdm.lookup_map.emplace(std::move(tid), std::make_unique<thread_pump_information>());

				if (emplace_result.second != true)
				{
					format_debugwriteln(L"Initialising data for thread {} found existing data.", tid);
				}
				_ASSERTE(emplace_result.second == true);
			}
		}
	}

	void application_impl::remove_data_for_thread(uint32_t tid)
	{
		auto &tdm{ get_data_map() };

		std::unique_lock sl{ tdm.lookup_mutex };
		auto find_result{ tdm.lookup_map.find(tid) };
		auto &mytpi{ *(*find_result).second.get() };
		auto refs{ --mytpi.thread_refs };

		if (refs == 0)
		{
			auto erase_result{ tdm.lookup_map.erase(tid) };
			if (erase_result != 1)
			{
				format_debugwriteln(L"Erasing thread data failed for thread {}.", tid);
			}
			_ASSERTE(erase_result == 1);
		}
	}

	thread_pump_information &application_impl::get_pump_info_for_thread(uint32_t tid)
	{
		auto &tdm{ get_data_map() };

		{
			std::shared_lock sl{ tdm.lookup_mutex };

			auto it{ tdm.lookup_map.find(tid) };
			_ASSERTE(it != tdm.lookup_map.end());
			if (it == tdm.lookup_map.end())
			{
				format_debugwriteln(L"Attempted to obtain non existant thread data for thread {}.", tid);
				__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			}

			return *(*it).second;
		}
	}

	uint32_t application_impl::get_current_thread_id() noexcept
	{
		return value_convert<uint32_t>(GetCurrentThreadId());
	}

	bool application_impl::post_quit_message_for_thread(uint32_t tid, int result) noexcept
	{
		return PostThreadMessageW(value_convert<DWORD>(tid), WM_QUIT, value_convert<WPARAM>(result), 0) != FALSE;
	}

	bool application_impl::did_initialisation_fail() const
	{
		return m_failure_info.error_code != 0;
	}

	init_failure_information application_impl::get_failure_information() const
	{
		return m_failure_info;
	}
}