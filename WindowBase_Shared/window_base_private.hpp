#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <atomic>

namespace window_base::windowing
{
	static inline constexpr char prop_instance_a[]{ "PROP_INSTANCE" };
	static inline constexpr char prop_message_callback_a[]{ "PROP_MESSAGECALLBACK" };
	static inline constexpr char prop_register_callback_a[]{ "PROP_REGISTERCALLBACK" };
	static inline constexpr char prop_identity_a[]{ "PROP_IDENTITY" };

	static inline constexpr wchar_t prop_instance_w[]{ L"PROP_INSTANCE" };
	static inline constexpr wchar_t prop_message_callback_w[]{ L"PROP_MESSAGECALLBACK" };
	static inline constexpr wchar_t prop_register_callback_w[]{ L"PROP_REGISTERCALLBACK" };
	static inline constexpr wchar_t prop_identity_w[]{ L"PROP_IDENTITY" };
	
	static inline constexpr int32_t identity_version = 1;

	namespace details
	{
		enum class prop_type
		{
			instance,
			register_callback,
			message_callback,
			identity
		};

		struct window_data
		{
			HWND m_handle{};
			HINSTANCE m_instance{};
			std::map<power_notify_type, HPOWERNOTIFY> m_power_notify_handles;
			uint32_t m_thread_id{};
			uint32_t m_dpi{};
			float m_scale{};

			bool window_initial_construction_complete{};
			bool window_shown{};
		};

		inline std::unique_ptr<window_data> make_window_data(HINSTANCE inst) noexcept
		{
			std::unique_ptr<window_data> ptr;

			//It is okay if this fails.
			//The next access will be in window_base::set_window_info.
			ptr.reset(new(std::nothrow) window_data);
			if (ptr)
			{
				ptr->m_instance = inst;
			}
			return ptr;
		}

		inline static constexpr std::string_view prop_name_from_type_a(prop_type type) noexcept
		{
			std::string_view sv;

			switch (type)
			{
			case prop_type::instance:
				sv = std::string_view(prop_instance_a, ARRAYSIZE(prop_instance_a));
				break;
			case prop_type::register_callback:
				sv = std::string_view(prop_register_callback_a, ARRAYSIZE(prop_register_callback_a));
				break;
			case prop_type::message_callback:
				sv = std::string_view(prop_message_callback_a, ARRAYSIZE(prop_message_callback_a));
				break;
			case prop_type::identity:
				sv = std::string_view(prop_identity_a, ARRAYSIZE(prop_identity_a));
				break;
			}

			return sv;
		}

		inline static constexpr std::wstring_view prop_name_from_type_w(prop_type type) noexcept
		{
			std::wstring_view sv;

			switch (type)
			{
			case prop_type::instance:
				sv = std::wstring_view(prop_instance_w, ARRAYSIZE(prop_instance_w));
				break;
			case prop_type::register_callback:
				sv = std::wstring_view(prop_register_callback_w, ARRAYSIZE(prop_register_callback_w));
				break;
			case prop_type::message_callback:
				sv = std::wstring_view(prop_message_callback_w, ARRAYSIZE(prop_message_callback_w));
				break;
			case prop_type::identity:
				sv = std::wstring_view(prop_identity_w, ARRAYSIZE(prop_identity_w));
				break;
			}

			return sv;
		}

		class close_callback_container : public register_callback
		{
		public:
			virtual uint32_t register_close_callback(std::function<close_callback_type> &) noexcept override;
			virtual void unregister_close_callback(uint32_t) noexcept override;

			void notify_close(HWND) noexcept;

		private:
			std::atomic_uint32_t m_cookie{};
			std::map<uint32_t, std::function<close_callback_type>> m_callbacks;
		};

		close_callback_container *get_register_callback_container_a(HWND) noexcept;
		close_callback_container *get_register_callback_container_w(HWND) noexcept;

		bool set_property_a(HWND, prop_type, void *) noexcept;
		void *get_property_a(HWND, prop_type) noexcept;
		void *remove_property_a(HWND, prop_type) noexcept;
		bool set_property_w(HWND, prop_type, void *) noexcept;
		void *get_property_w(HWND, prop_type) noexcept;
		void *remove_property_w(HWND, prop_type) noexcept;

		bool can_use_win11_features() noexcept;
		bool can_use_win11_22h2_features() noexcept;
		bool can_use_win11_24h2_features() noexcept;
	}

	namespace common_impl
	{
		static RECT get_window_rect(HWND wnd) noexcept;
		static RECT get_client_rect(HWND wnd) noexcept;
		static bool is_windowbase_window(HWND wnd) noexcept;
		static dpi_awareness get_dpi_awareness(HWND wnd) noexcept;
		static dpi_hosting_behaviour get_dpi_hosting_behaviour(HWND wnd) noexcept;
		static bool is_window_rtl(HWND wnd, bool unicode_window) noexcept;
		static bool is_active(HWND wnd) noexcept;
		static bool is_visible(HWND wnd) noexcept;
		static bool is_enabled(HWND wnd) noexcept;
		static bool is_minimised(HWND wnd) noexcept;
		static bool is_maximised(HWND wnd) noexcept;
		static bool is_arranged(HWND wnd) noexcept;
		static bool show_window_cmd(HWND wnd, int show_cmd) noexcept;
		static bool show_window_default(HWND wnd) noexcept;
		static bool show_window(HWND wnd, bool activate) noexcept;
		static bool show_window_minimised(HWND wnd, bool activate) noexcept;
		static bool show_window_maximised(HWND wnd) noexcept;
		static bool minimise_window(HWND wnd) noexcept;
		static bool maximise_window(HWND wnd) noexcept;
		static bool restore_window(HWND) noexcept;
		static bool hide_window(HWND wnd) noexcept;
		static bool enable_window(HWND wnd) noexcept;
		static bool disable_window(HWND wnd) noexcept;
		static void update_window(HWND wnd) noexcept;
		static void redraw_window(HWND wnd, std::optional<RECT> rect, HRGN rgn, redraw_window_flags flags) noexcept;
		static HWND get_parent(HWND wnd) noexcept;
		static SIZE get_size(HWND wnd) noexcept;
		static SIZE get_client_size(HWND wnd) noexcept;
		static POINT get_position(HWND wnd) noexcept;
		static void set_size(HWND wnd, const SIZE &new_size) noexcept;
		static void set_client_size(HWND wnd, uint32_t dpi, bool unicode_window, const SIZE &client_size) noexcept;
		static void set_position(HWND wnd, const POINT &position) noexcept;
		static void set_size_position(HWND wnd, const POINT &position, const SIZE &size) noexcept;
		static void set_z_order_top(HWND wnd) noexcept;
		static void set_z_order_bottom(HWND wnd) noexcept;
		static void set_z_order_after(HWND wnd, HWND after_wnd) noexcept;
	}
}