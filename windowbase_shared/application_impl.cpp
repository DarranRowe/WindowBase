#include "application_impl.hpp"
#include "application_helper.hpp"
#include <ShObjIdl.h>

namespace application::details
{
	static application_impl *g_app_inst{ nullptr };
	static std::mutex g_app_inst_mutex;

	void application_impl::add_ref_impl() noexcept
	{
		if (g_app_inst == nullptr)
		{
			helper::writeln_debugger(L"Instance found to be nullptr in add_ref_impl.");
		}
		_ASSERTE(g_app_inst != nullptr);
		std::scoped_lock lock{ g_app_inst_mutex };
		g_app_inst->add_ref();
	}

	void application_impl::release_impl() noexcept
	{
		if (g_app_inst == nullptr)
		{
			helper::writeln_debugger(L"Instance found to be nullptr in release_impl.");
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
			helper::writeln_debugger(L"Instance not null in make_new_instance.");
			return g_app_inst;
		}

		try
		{
			//The implementation is created with 1 reference.
			impl = new application_impl;
		}
		catch (std::bad_alloc &)
		{
			helper::writeln_debugger(L"std::bad_alloc thrown in make_new_instance.");
		}
		catch (...)
		{
			helper::writeln_debugger(L"Unknown exception thrown in make_new_instance.");
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
			helper::write_debugger(LR"(GetCurrentProcessExplicitAppUserModelID failed.
This potentially means the AUMID wasn't set for the process.
)");
			return std::nullopt;
		}

		return std::optional(aumid.get());
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

	uint32_t application_impl::add_callback(pump_callback_wrapper callback, HWND window, uint32_t identifier, uint32_t tid)
	{
		std::unique_ptr<callback_information> ci{ std::make_unique<callback_information>(callback_information{ std::move(callback), window, identifier }) };

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
		auto &tpi{ get_pump_info_for_thread(tid) };

		tpi.in_message_pump = true;

		MSG msg{};

		while (GetMessageA(&msg, nullptr, 0, 0))
		{
			bool dispatch_message{ true };

			{
				std::shared_lock sl{ tpi.callback_mutex };

				for (auto &pci : tpi.callback_info)
				{
					callback_information &ci{ *pci.second.get() };
					if (ci.window_handle == nullptr)
					{
						//This is a simple callback.
						auto sc_result{ ci.callback_wrapper(msg) };
						//We only want to change this flag when the result is false.
						//Changing it when true runs the risk of running DispatchMessage
						//if one callback returns false and then the following one returns true
						//if multiple callbacks are registered.
						//We also only set the flag to itself, so if it has changed, then we keep
						//that change.
						dispatch_message = sc_result == true ? dispatch_message : sc_result;
					}
					else
					{
						//This is a window callback.
						if (windowing::window_base::has_window_message_callback(ci.window_handle, ci.callback_identifier))
						{
							auto &mc{ windowing::window_base::get_window_message_callback(ci.window_handle, ci.callback_identifier) };
							auto wc_result{ mc.invoke(msg) };
							dispatch_message = wc_result == true ? dispatch_message : wc_result;
						}
					}
				}
			}

			if (dispatch_message)
			{
				DispatchMessageA(&msg);
			}
		}

		int result{ static_cast<int>(msg.wParam) };

		tpi.in_message_pump = false;

		return result;
	}

	int application_impl::run_unicode_message_pump(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		tpi.in_message_pump = true;

		MSG msg{};

		while (GetMessageW(&msg, nullptr, 0, 0))
		{
			bool dispatch_message{ true };

			{
				std::shared_lock sl{ tpi.callback_mutex };

				for (auto &pci : tpi.callback_info)
				{
					callback_information &ci{ *pci.second.get() };
					if (ci.window_handle == nullptr)
					{
						//This is a simple callback.
						auto sc_result{ ci.callback_wrapper(msg) };
						//We only want to change this flag when the result is false.
						//Changing it when true runs the risk of running DispatchMessage
						//if one callback returns false and then the following one returns true
						//if multiple callbacks are registered.
						//We also only set the flag to itself, so if it has changed, then we keep
						//that change.
						dispatch_message = sc_result == true ? dispatch_message : sc_result;
					}
					else
					{
						//This is a window callback.
						if (windowing::window_base::has_window_message_callback(ci.window_handle, ci.callback_identifier))
						{
							auto &mc{ windowing::window_base::get_window_message_callback(ci.window_handle, ci.callback_identifier) };
							auto wc_result{ mc.invoke(msg) };
							dispatch_message = wc_result == true ? dispatch_message : wc_result;
						}
					}
				}
			}

			if (dispatch_message)
			{
				DispatchMessageW(&msg);
			}
		}

		int result{ static_cast<int>(msg.wParam) };

		tpi.in_message_pump = false;

		return result;
	}

	int application_impl::run_ansi_game_message_pump(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };
		bool continue_loop{ true };

		tpi.in_message_pump = true;
		MSG msg{};

		while (continue_loop)
		{
			if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
			{
				if (msg.message != WM_QUIT)
				{
					bool dispatch_message{ true };

					{
						std::shared_lock sl{ tpi.callback_mutex };

						for (auto &pci : tpi.callback_info)
						{
							callback_information &ci{ *pci.second.get() };
							if (ci.window_handle == nullptr)
							{
								//This is a simple callback.
								auto sc_result{ ci.callback_wrapper(msg) };
								//We only want to change this flag when the result is false.
								//Changing it when true runs the risk of running DispatchMessage
								//if one callback returns false and then the following one returns true
								//if multiple callbacks are registered.
								//We also only set the flag to itself, so if it has changed, then we keep
								//that change.
								dispatch_message = sc_result == true ? dispatch_message : sc_result;
							}
							else
							{
								//This is a window callback.
								if (windowing::window_base::has_window_message_callback(ci.window_handle, ci.callback_identifier))
								{
									auto &mc{ windowing::window_base::get_window_message_callback(ci.window_handle, ci.callback_identifier) };
									auto wc_result{ mc.invoke(msg) };
									dispatch_message = wc_result == true ? dispatch_message : wc_result;
								}
							}
						}
					}

					if (dispatch_message)
					{
						DispatchMessageA(&msg);
					}
				}
				else
				{
					continue_loop = false;
				}
			}
			else
			{
				std::shared_lock sl{ tpi.callback_mutex };
				
				_ASSERTE(tpi.callback_work_information);

				work_callback_wrapper &ci{ *tpi.callback_work_information.get() };
				
				auto result{ ci() };
				continue_loop = result;
			}
		}

		int result{ static_cast<int>(msg.wParam) };

		tpi.in_message_pump = false;

		return result;
	}

	int application_impl::run_unicode_game_message_pump(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };
		bool continue_loop{ true };

		tpi.in_message_pump = true;
		MSG msg{};

		while (continue_loop)
		{
			if (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
			{
				if (msg.message != WM_QUIT)
				{
					bool dispatch_message{ true };

					{
						std::shared_lock sl{ tpi.callback_mutex };

						for (auto &pci : tpi.callback_info)
						{
							callback_information &ci{ *pci.second.get() };
							if (ci.window_handle == nullptr)
							{
								//This is a simple callback.
								auto sc_result{ ci.callback_wrapper(msg) };
								//We only want to change this flag when the result is false.
								//Changing it when true runs the risk of running DispatchMessage
								//if one callback returns false and then the following one returns true
								//if multiple callbacks are registered.
								//We also only set the flag to itself, so if it has changed, then we keep
								//that change.
								dispatch_message = sc_result == true ? dispatch_message : sc_result;
							}
							else
							{
								//This is a window callback.
								if (windowing::window_base::has_window_message_callback(ci.window_handle, ci.callback_identifier))
								{
									auto &mc{ windowing::window_base::get_window_message_callback(ci.window_handle, ci.callback_identifier) };
									auto wc_result{ mc.invoke(msg) };
									dispatch_message = wc_result == true ? dispatch_message : wc_result;
								}
							}
						}
					}

					if (dispatch_message)
					{
						DispatchMessageW(&msg);
					}
				}
				else
				{
					continue_loop = false;
				}
			}
			else
			{
				std::shared_lock sl{ tpi.callback_mutex };

				_ASSERTE(tpi.callback_work_information);
				work_callback_wrapper &ci{ *tpi.callback_work_information.get() };

				auto result{ ci() };
				continue_loop = result;
			}
		}

		int result{ static_cast<int>(msg.wParam) };

		tpi.in_message_pump = false;

		return result;
	}

	void application_impl::clear_ansi_message_queue(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		tpi.in_message_pump = true;

		MSG msg{};

		while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
		{
			DispatchMessageA(&msg);
		}

		tpi.in_message_pump = false;
	}

	void application_impl::clear_unicode_message_queue(uint32_t tid)
	{
		auto &tpi{ get_pump_info_for_thread(tid) };

		tpi.in_message_pump = true;

		MSG msg{};

		while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
		{
			DispatchMessageW(&msg);
		}

		tpi.in_message_pump = false;
	}

	bool application_impl::convert_thread_to_ui_thread()
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
					helper::writeln_debugger(L"Initialising data for thread {} found existing data.", tid);
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
				helper::writeln_debugger(L"Erasing thread data failed for thread {}.", tid);
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
				helper::writeln_debugger(L"Attempted to obtain non existant thread data for thread {}.", tid);
				__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			}

			return *(*it).second;
		}
	}

	uint32_t application_impl::get_current_thread_id() noexcept
	{
		return static_cast<uint32_t>(GetCurrentThreadId());
	}

	bool application_impl::post_quit_message_for_thread(uint32_t tid, int result) noexcept
	{
		return PostThreadMessageW(static_cast<DWORD>(tid), WM_QUIT, static_cast<WPARAM>(result), 0) != FALSE;
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