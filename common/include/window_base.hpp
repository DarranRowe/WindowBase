#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <variant>
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
		virtual uint32_t register_close_callback(std::function<close_callback_type> &) noexcept = 0;
		virtual void unregister_close_callback(uint32_t) noexcept = 0;
	};

	using message_callback_type = bool(const MSG &);
	using message_callback_ptr_type = bool(*)(const MSG &);
	template <typename C>
	using message_callback_ptm_type = bool(C:: *)(const MSG &);

	struct message_callback
	{
		virtual bool invoke(const MSG &) = 0;
	};

	using aumid_type = std::variant<std::string, std::wstring>;

	//Public API
	//Modification of this class requires adding the functions to the export list.
	class window_base
	{
	public:
		HWND get_handle() const noexcept;
		HINSTANCE get_instance() const noexcept;
		uint32_t get_thread_id() const noexcept;
		uint32_t get_dpi() const noexcept;
		float get_scale() const noexcept;
		bool is_window_dpi_aware() const noexcept;
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

		void set_window_aumid_from_process_aumid() noexcept;
		void set_window_aumid(const std::string_view &) noexcept;
		void set_window_aumid(const std::wstring_view &) noexcept;

		aumid_type get_window_aumid() const noexcept;
		bool window_has_aumid() const noexcept;

		void register_power_notification(power_notify_type) noexcept;
		void unregister_power_notification(power_notify_type) noexcept;

		register_callback &get_register_interface() const noexcept;
		static message_callback &get_window_message_callback(HWND, uint32_t) noexcept;
		static bool has_window_message_callback(HWND, uint32_t) noexcept;

	protected:
		explicit window_base(HINSTANCE) noexcept;
		//destructor needs to be implemented in a place where it can see window_data
		//we don't want the destructors to be public since we only want the window
		//class to be destroyed through the most derived type
		~window_base() noexcept;

		void notify_window_close() noexcept;
		void set_window_info(HWND, uint32_t, bool, void *) noexcept;
		void cleanup_window_info() noexcept;
		void set_dpi(uint32_t) noexcept;

		bool has_associated_window() const noexcept;

		bool add_message_callback(const std::shared_ptr<message_callback> &, uint32_t) noexcept;
		void remove_message_callback(uint32_t) noexcept;
		void clear_message_callbacks() noexcept;

		static void *raw_inst_from_handle(HWND handle);

		static bool is_class_registered(HINSTANCE, const std::string_view &) noexcept;
		static bool is_class_registered(HINSTANCE, const std::wstring_view &) noexcept;
		static bool register_class(uint32_t, const std::string_view &, const std::string_view &, int32_t, int32_t, WNDPROC, HINSTANCE, HBRUSH, HCURSOR, HICON, HICON) noexcept;
		static bool register_class(uint32_t, const std::wstring_view &, const std::wstring_view &, int32_t, int32_t, WNDPROC, HINSTANCE, HBRUSH, HCURSOR, HICON, HICON) noexcept;
		static bool register_class(const WNDCLASSEXA &) noexcept;
		static bool register_class(const WNDCLASSEXW &) noexcept;
		static HWND create_window(uint32_t, uint32_t, const std::string_view &, const std::string_view &, const POINT &, const SIZE &, HWND, HMENU, void *) noexcept;
		static HWND create_window(uint32_t, uint32_t, const std::wstring_view &, const std::wstring_view &, const POINT &, const SIZE &, HWND, HMENU, void *) noexcept;

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