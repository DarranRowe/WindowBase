#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <memory>

namespace window_base::application
{
	struct winrt_t {};
	struct com_t {};
	struct ole_t {};

	struct sta_t {};

	inline winrt_t winrt{};
	inline com_t com{};
	inline ole_t ole{};
	inline sta_t sta{};

	namespace details
	{
		struct apartment_impl;
	}

	class apartment
	{
	public:
		apartment(winrt_t) noexcept;
		apartment(winrt_t, sta_t) noexcept;
		apartment(com_t) noexcept;
		apartment(com_t, sta_t) noexcept;
		apartment(ole_t) noexcept;
		~apartment() noexcept;

		void increment_implicit_mta();
		void decrement_implicit_mta();
		uint32_t outstanding_mta_count() const;
		uint32_t init_failure_code() const;

		static bool is_aparmtent_init();
		static bool is_sta_apartment();
		static bool is_nta_apartment();
		static bool is_implicit_mta();

		bool is_winrt_apartment() const;
		bool is_ole_apartment() const;

	private:
		apartment() = delete;
		apartment(const apartment &) = delete;
		apartment operator=(const apartment &) = delete;

		std::unique_ptr<details::apartment_impl> m_impl;
	};
}