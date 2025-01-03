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
	static inline constexpr char prop_instance_a[]{ "PROP_INSTANCE" };
	static inline constexpr char prop_message_callback_a[]{ "PROP_MESSAGECALLBACK" };
	static inline constexpr char prop_register_callback_a[]{ "PROP_REGISTERCALLBACK" };

	static inline constexpr wchar_t prop_instance_w[]{ L"PROP_INSTANCE" };
	static inline constexpr wchar_t prop_message_callback_w[]{ L"PROP_MESSAGECALLBACK" };
	static inline constexpr wchar_t prop_register_callback_w[]{ L"PROP_REGISTERCALLBACK" };

	namespace details
	{
		enum class prop_type
		{
			instance,
			register_callback,
			message_callback
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
			bool window_unicode{};
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

		class message_callback_container
		{
		public:
			bool add_callback(const std::shared_ptr<message_callback> &, uint32_t) noexcept;
			void remove_callback(uint32_t) noexcept;
			void clear_callbacks() noexcept;
			message_callback *get_callback(uint32_t) const noexcept;
			bool has_callback(uint32_t) const noexcept;
		private:
			std::map<uint32_t, std::shared_ptr<message_callback>> m_map;
		};

		bool set_property_a(HWND, prop_type, void *) noexcept;
		void *get_property_a(HWND, prop_type) noexcept;
		void *remove_property_a(HWND, prop_type) noexcept;
		bool set_property_w(HWND, prop_type, void *) noexcept;
		void *get_property_w(HWND, prop_type) noexcept;
		void *remove_property_w(HWND, prop_type) noexcept;

		bool can_use_win11_features() noexcept;
		bool can_use_win11_22h2_features() noexcept;
	}
}