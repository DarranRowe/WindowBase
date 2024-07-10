#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <memory>
#include <map>
#include <atomic>
#include <cstdint>
#include <cinttypes>
#include <string_view>

#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>

#include "window_defs.hpp"

namespace windowing
{
	static inline constexpr char prop_instance_a[] = "PROP_INSTANCE";
	static inline constexpr char prop_mousetrack_a[] = "PROP_MOUSETRACK";
	static inline constexpr char prop_mousetrack_hook_a[] = "PROP_MOUSETRACKHOOK";
	static inline constexpr char prop_message_callback_a[] = "PROP_MESSAGECALLBACK";
	static inline constexpr char prop_register_callback_a[] = "PROP_REGISTERCALLBACK";

	static inline constexpr wchar_t prop_instance_w[] = L"PROP_INSTANCE";
	static inline constexpr wchar_t prop_mousetrack_w[] = L"PROP_MOUSETRACK";
	static inline constexpr wchar_t prop_mousetrack_hook_w[] = L"PROP_MOUSETRACKHOOK";
	static inline constexpr wchar_t prop_message_callback_w[] = L"PROP_MESSAGECALLBACK";
	static inline constexpr wchar_t prop_register_callback_w[] = L"PROP_REGISTERCALLBACK";

	static inline constexpr char prop_window_data_a[] = "PROP_WINDOWDATA";
	static inline constexpr wchar_t prop_window_data_w[] = L"PROP_WINDOWDATA";

	namespace details
	{
		struct window_data
		{
			HWND m_handle = nullptr;
			HINSTANCE m_instance = nullptr;
			std::map<power_notify_type, HPOWERNOTIFY> m_power_notify_handles;
			uint32_t m_thread_id{};
			uint32_t m_dpi{};
			float m_scale{};

			bool window_initial_construction_complete = false;
			bool window_unicode = false;
			bool window_shown = false;
		};

		std::unique_ptr<window_data> make_window_data(HINSTANCE inst)
		{
			auto ptr = std::make_unique<window_data>();
			ptr->m_instance = inst;
			return ptr;
		}

		inline static constexpr std::string_view prop_name_from_type_a(prop_type type)
		{
			std::string_view sv;

			switch (type)
			{
			case prop_type::instance:
				sv = std::string_view(prop_instance_a, ARRAYSIZE(prop_instance_a));
				break;
			case prop_type::mouse_track:
				sv = std::string_view(prop_mousetrack_a, ARRAYSIZE(prop_mousetrack_a));
				break;
			case prop_type::mouse_track_hook:
				sv = std::string_view(prop_mousetrack_hook_a, ARRAYSIZE(prop_mousetrack_hook_a));
				break;
			case prop_type::register_callback:
				sv = std::string_view(prop_register_callback_a, ARRAYSIZE(prop_register_callback_a));
				break;
			case prop_type::message_callback:
				sv = std::string_view(prop_message_callback_a, ARRAYSIZE(prop_message_callback_a));
				break;
			}

			return sv;
		}

		inline static constexpr std::wstring_view prop_name_from_type_w(prop_type type)
		{
			std::wstring_view sv;

			switch (type)
			{
			case prop_type::instance:
				sv = std::wstring_view(prop_instance_w, ARRAYSIZE(prop_instance_w));
				break;
			case prop_type::mouse_track:
				sv = std::wstring_view(prop_mousetrack_w, ARRAYSIZE(prop_mousetrack_w));
				break;
			case prop_type::mouse_track_hook:
				sv = std::wstring_view(prop_mousetrack_hook_w, ARRAYSIZE(prop_mousetrack_hook_w));
				break;
			case prop_type::register_callback:
				sv = std::wstring_view(prop_register_callback_w, ARRAYSIZE(prop_register_callback_w));
				break;
			case prop_type::message_callback:
				sv = std::wstring_view(prop_message_callback_w, ARRAYSIZE(prop_message_callback_w));
				break;
			}

			return sv;
		}

		class close_callback_container : public register_callback
		{
		public:
			virtual uint32_t register_close_callback(std::function<close_callback_type> &) override;
			virtual void unregister_close_callback(uint32_t) override;

			void notify_close(HWND);

		private:
			std::atomic_uint32_t m_cookie{};
			std::map<uint32_t, std::function<close_callback_type>> m_callbacks;
		};

		close_callback_container *get_register_callback_container_a(HWND);
		close_callback_container *get_register_callback_container_w(HWND);

		class message_callback_container
		{
		public:
			bool add_callback(const std::shared_ptr<message_callback> &, uint32_t);
			void remove_callback(uint32_t);
			void clear_callbacks();
			message_callback *get_callback(uint32_t) const;
			bool has_callback(uint32_t) const;
		private:
			std::map<uint32_t, std::shared_ptr<message_callback>> m_map;
		};

		
	}
}