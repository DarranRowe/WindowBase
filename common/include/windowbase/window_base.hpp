#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <atomic>
#include <variant>
#include <functional>
#include <memory>
#include <optional>
#include <cstdint>
#include <cinttypes>
#include <string>
#include <string_view>

#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#endif

#include "utility.hpp"
#include "common_defs.hpp"

namespace window_base::windowing
{
	namespace details
	{
		struct window_data;
		struct window_data_a;
		struct window_data_w;
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

	ENUM_BITWISE_OPERATORS(redraw_window_flags);

	//Public API
	//Modification of this class requires adding the functions to the export list.
	struct window_traits_a
	{
		using char_t = char;

		using cbt_createwnd_t = CBT_CREATEWNDA;
		using create_struct_t = CREATESTRUCTA;
		using wndclassex_t = WNDCLASSEXA;

		static HHOOK WndSetWindowsHookEx(int, HOOKPROC, HINSTANCE, DWORD);
		static LRESULT WndDefWindowProc(HWND, UINT, WPARAM, LPARAM);
		static LONG_PTR WndGetWindowLongPtr(HWND, int);
		static LONG_PTR WndSetWindowLongPtr(HWND, int, LONG_PTR);
	};

	//Public API
	//Modification of this class requires adding the functions to the export list.
	struct window_traits_w
	{
		using char_t = wchar_t;

		using cbt_createwnd_t = CBT_CREATEWNDW;
		using create_struct_t = CREATESTRUCTW;
		using wndclassex_t = WNDCLASSEXW;

		static HHOOK WndSetWindowsHookEx(int, HOOKPROC, HINSTANCE, DWORD);
		static LRESULT WndDefWindowProc(HWND, UINT, WPARAM, LPARAM);
		static LONG_PTR WndGetWindowLongPtr(HWND, int);
		static LONG_PTR WndSetWindowLongPtr(HWND, int, LONG_PTR);
	};

	using close_callback_type = void(HWND, uint32_t);
	using close_callback_ptr = void (*)(HWND, uint32_t);

	struct NOVTABLE EMPTYBASES register_callback
	{
		virtual uint32_t register_close_callback(std::function<close_callback_type> &) noexcept = 0;
		virtual void unregister_close_callback(uint32_t) noexcept = 0;
	};

	//Public API
	//Modification of this class requires modifying the module definition file.
	class window_base_common
	{
	public:
		static bool is_windowbase_window(HWND) noexcept;

		HWND get_handle() const noexcept;
		HINSTANCE get_instance() const noexcept;
		uint32_t get_thread_id() const noexcept;
		uint32_t get_dpi() const noexcept;
		float get_scale() const noexcept;
		dpi_awareness get_dpi_awareness() const noexcept;
		dpi_hosting_behaviour get_dpi_hosting_behaviour() const noexcept;
		bool is_window_rtl() const noexcept;
		bool is_window_unicode() const noexcept;

		bool is_active() const noexcept;
		bool is_visible() const noexcept;
		bool is_enabled() const noexcept;
		bool is_minimised() const noexcept;
		bool is_maximised() const noexcept;
		bool is_arranged() const noexcept;

		bool show_window_cmd(int) noexcept;
		bool show_window_default() noexcept;
		bool show_window(bool) noexcept;
		bool show_window_minimised(bool) noexcept;
		bool show_window_maximised() noexcept;
		bool minimise_window() noexcept;
		bool maximise_window() noexcept;
		bool restore_window() noexcept;
		bool hide_window() noexcept;
		bool enable_window() noexcept;
		bool disable_window() noexcept;

		void update_window() noexcept;
		void redraw_window(std::optional<RECT>, HRGN, redraw_window_flags) noexcept;

		HWND get_parent() const noexcept;
		SIZE get_size() const noexcept;
		SIZE get_client_size() const noexcept;
		POINT get_position() const noexcept;

		void set_size(const SIZE &) noexcept;
		void set_client_size(const SIZE &) noexcept;
		void set_position(const POINT &) noexcept;
		void set_size_position(const POINT &, const SIZE &) noexcept;
		void set_z_order_top() noexcept;
		void set_z_order_bottom() noexcept;
		void set_z_order_after(HWND) noexcept;

		void register_power_notification(power_notify_type) noexcept;
		void unregister_power_notification(power_notify_type) noexcept;

		register_callback &get_register_interface() const noexcept;
	protected:
		window_base_common() noexcept = default;
		~window_base_common() noexcept = default;

		void set_data(details::window_data *) noexcept;
		void notify_window_close() noexcept;

		void set_dpi(uint32_t) noexcept;

		bool has_associated_window() const noexcept;

		static void *raw_inst_from_handle(HWND handle);

	private:
		//completely disable copy/move this class cannot be
		//copied, and while it is technically movable that is
		//problematic
		//the window will be wrapped by a class that does this
		window_base_common(const window_base_common &) = delete;
		window_base_common(window_base_common &&) = delete;

		window_base_common &operator=(const window_base_common &) = delete;
		window_base_common &operator=(window_base_common &&) = delete;

		//The derived class owns this.
		//This pointer is a non owning pointer
		//to the common base of the data.
		details::window_data *m_window_data;
	};

	//Public API
	//Modification of this class requires modifying the module definition file.
	class window_base_a : public window_base_common
	{
	public:
		using base_t = window_base_common;

		void set_window_aumid_from_process_aumid() noexcept;
		void set_window_aumid(const std::string_view &) noexcept;

		std::string get_window_aumid() const noexcept;
		bool window_has_aumid() const noexcept;

	protected:
		explicit window_base_a(HINSTANCE) noexcept;
		//destructor needs to be implemented in a place where it can see window_data
		//we don't want the destructors to be public since we only want the window
		//class to be destroyed through the most derived type
		~window_base_a() noexcept;

		void set_window_info(HWND, uint32_t, void *) noexcept;
		void cleanup_window_info() noexcept;

		static HWND create_window(uint32_t, uint32_t, const std::string_view &, const std::string_view &, const POINT &, const SIZE &, HWND, HMENU, window_base_a *) noexcept;

	private:
		//completely disable copy/move and default constructor
		//this class cannot be copied, and while it is technically movable
		//that is problematic
		//the window will be wrapped by a class that does this
		window_base_a() = delete;
		window_base_a(const window_base_a &) = delete;
		window_base_a(window_base_a &&) = delete;

		window_base_a &operator=(const window_base_a &) = delete;
		window_base_a &operator=(window_base_a &&) = delete;

		std::unique_ptr<details::window_data_a> m_window_data;
	};

	//Public API
	//Modification of this class requires modifying the module definition file.
	class window_base_w : public window_base_common
	{
	public:
		using base_t = window_base_common;

		void set_window_aumid_from_process_aumid() noexcept;
		void set_window_aumid(const std::wstring_view &) noexcept;

		std::wstring get_window_aumid() const noexcept;
		bool window_has_aumid() const noexcept;

	protected:
		explicit window_base_w(HINSTANCE) noexcept;
		//destructor needs to be implemented in a place where it can see window_data
		//we don't want the destructors to be public since we only want the window
		//class to be destroyed through the most derived type
		~window_base_w() noexcept;

		void set_window_info(HWND, uint32_t, void *) noexcept;
		void cleanup_window_info() noexcept;

		static HWND create_window(uint32_t, uint32_t, const std::wstring_view &, const std::wstring_view &, const POINT &, const SIZE &, HWND, HMENU, window_base_w *) noexcept;

	private:
		//completely disable copy/move and default constructor
		//this class cannot be copied, and while it is technically movable
		//that is problematic
		//the window will be wrapped by a class that does this
		window_base_w() = delete;
		window_base_w(const window_base_w &) = delete;
		window_base_w(window_base_w &&) = delete;

		window_base_w &operator=(const window_base_w &) = delete;
		window_base_w &operator=(window_base_w &&) = delete;

		std::unique_ptr<details::window_data_w> m_window_data;
	};
}