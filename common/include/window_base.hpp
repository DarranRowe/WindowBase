#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <functional>
#include <memory>
#include <optional>
#include <cstdint>
#include <cinttypes>
#include <string>
#include <string_view>

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#include <windowsx.h>
#include <shellapi.h>
#include <Dbt.h>

#include "window_defs.hpp"

namespace windowing
{
	namespace details
	{
		struct window_data;
	}

	enum class power_notify_type
	{
		unknown,
		acdc_powersource,
		battery_percentage_remaining,
		idle_background_task,
		monitor_power_on,
		power_saving_status,
		powerscheme_personality,
		lidswitch_state_change,
		system_awaymode,
		console_display_state,
		global_user_presence,
		session_display_status,
		session_user_presence,
		suspend_resume //uses RegisterSuspendResumeNotification
	};

	enum class redraw_window_flags : uint16_t
	{
		unknown,
		invalidate = 0x0001,
		internal_paint = 0x0002,
		erase = 0x0004,
		validate = 0x0008,
		no_internal_paint = 0x0010,
		no_erase = 0x0020,
		no_children = 0x0040,
		all_children = 0x0080,
		update_now = 0x0100,
		erase_now = 0x0200,
		frame = 0x0400,
		no_frame = 0x0800
	};

	DEFINE_ENUM_FLAG_OPERATORS(redraw_window_flags);

	using close_callback_type = void(HWND, uint32_t);
	using close_callback_ptr = void (*)(HWND, uint32_t);

	struct register_callback
	{
		virtual uint32_t register_close_callback(std::function<close_callback_type> &) = 0;
		virtual void unregister_close_callback(uint32_t) = 0;
	};

	using message_callback_type = bool(const MSG &);
	using message_callback_ptr_type = bool(*)(const MSG &);
	template <typename C>
	using message_callback_ptm_type = bool(C:: *)(const MSG &);

	struct message_callback
	{
		virtual bool invoke(const MSG &) = 0;
	};

	bool set_property_a(HWND, prop_type, void *);
	void *get_property_a(HWND, prop_type);
	void *remove_property_a(HWND, prop_type);
	bool set_property_w(HWND, prop_type, void *);
	void *get_property_w(HWND, prop_type);
	void *remove_property_w(HWND, prop_type);

	//Public API
	//Modification of this class requires adding the functions to the export list.
	class window_base
	{
	public:
		HWND get_handle() const;
		HINSTANCE get_instance() const;
		uint32_t get_thread_id() const;
		uint32_t get_dpi() const;
		float get_scale() const;
		bool is_window_dpi_aware() const;
		bool is_window_rtl() const;
		bool is_window_unicode() const;

		bool is_active() const;
		bool is_visible() const;
		bool is_enabled() const;
		bool is_minimised() const;
		bool is_maximised() const;
		bool is_arranged() const;

		bool show_window_cmd(int);
		bool show_window_default();
		bool show_window(bool);
		bool show_window_minimised(bool);
		bool show_window_maximised();
		bool minimise_window();
		bool maximise_window();
		bool restore_window();
		bool hide_window();
		bool enable_window();
		bool disable_window();

		void update_window();
		void redraw_window(std::optional<RECT>, HRGN, redraw_window_flags);

		HWND get_parent() const;
		SIZE get_size() const;
		SIZE get_client_size() const;
		POINT get_position() const;

		void set_size(const SIZE &);
		void set_client_size(const SIZE &);
		void set_position(const POINT &);
		void set_size_position(const POINT &, const SIZE &);
		void set_z_order_top();
		void set_z_order_bottom();
		void set_z_order_after(HWND);

		void set_window_aumid_from_process_aumid();
		void set_window_aumid(const std::string_view &);
		void set_window_aumid(const std::wstring_view &);

		std::string get_window_aumid_a() const;
		std::wstring get_window_aumid_w() const;
		template<typename char_type>
		auto get_window_aumid() const ->std::basic_string<char_type>
		{
			if constexpr (std::is_same_v<char_type, char>)
			{
				return get_window_aumid_a();
			}
			if constexpr (std::is_same_v<char_type, wchar_t>)
			{
				return get_window_aumid_w();
			}
		}
		bool window_has_aumid() const;

		void register_power_notification(power_notify_type);
		void unregister_power_notification(power_notify_type);

		register_callback &get_register_interface() const;
		static message_callback &get_window_message_callback(HWND, uint32_t);
		static bool has_window_message_callback(HWND, uint32_t);

	protected:
		explicit window_base(HINSTANCE);
		//destructor needs to be implemented in a place where it can see window_data
		//we don't want the destructors to be public since we only want the window
		//class to be destroyed through the most derived type
		~window_base();

		void notify_window_close();
		void set_window_info(HWND, uint32_t, bool);
		void cleanup_window_info();
		void set_dpi(uint32_t);

		bool has_associated_window() const;

		bool add_message_callback(const std::shared_ptr<message_callback> &, uint32_t);
		void remove_message_callback(uint32_t);
		void clear_message_callbacks();

		bool is_class_registered(const std::string_view &) const;
		bool is_class_registered(const std::wstring_view &) const;
		bool register_class(uint32_t, const std::string_view &, const std::string_view &, int32_t, int32_t, WNDPROC, HBRUSH, HCURSOR, HICON, HICON);
		bool register_class(uint32_t, const std::wstring_view &, const std::wstring_view &, int32_t, int32_t, WNDPROC, HBRUSH, HCURSOR, HICON, HICON);
		bool register_class(const WNDCLASSEXA &);
		bool register_class(const WNDCLASSEXW &);
		HWND create_window(uint32_t, uint32_t, const std::string_view &, const std::string_view &, const POINT &, const SIZE &, HWND, HMENU, void *);
		HWND create_window(uint32_t, uint32_t, const std::wstring_view &, const std::wstring_view &, const POINT &, const SIZE &, HWND, HMENU, void *);

		bool set_property(prop_type, void *);
		void *get_property(prop_type);
		void *remove_property(prop_type);
	private:
		//completely disable copy/move and default constructor
		//this class cannot be copied, and while it is technically movable
		//that is problematic
		//the window will be wrapped by a class that does this
		window_base() = delete;
		window_base(const window_base &) = delete;
		window_base(window_base &&) = delete;

		window_base &operator=(const window_base &) = delete;
		window_base &operator=(window_base &&) = delete;

		std::unique_ptr<details::window_data> m_window_data;
	};
}