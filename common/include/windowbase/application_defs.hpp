#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <functional>

#include "common_defs.hpp"

#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#define OEMRESOURCE
#define NOMINMAX
#include <Windows.h>
#endif

namespace window_base::application
{
	namespace details
	{
		using message_process_callback = bool(const MSG &);
		using work_process_callback = bool();
	}

	class pump_callback_wrapper
	{
	public:
		pump_callback_wrapper() = delete;
		pump_callback_wrapper(nullptr_t) : m_fun_ptr(nullptr)
		{
		}
		template <typename L>
		pump_callback_wrapper(L l) : m_fun_ptr(l)
		{
		}
		template <typename F>
		pump_callback_wrapper(F *f) : m_fun_ptr([f](const MSG &msg) -> bool {return f(msg); })
		{
		}
		template <typename O, typename M>
		pump_callback_wrapper(O *o, M m) : m_fun_ptr([o, m](const MSG &msg) mutable ->bool {return (o->*m)(msg); })
		{
		}

		pump_callback_wrapper(const pump_callback_wrapper &) = default;
		pump_callback_wrapper(pump_callback_wrapper &&) = default;

		bool invoke(const MSG &msg)
		{
			return m_fun_ptr(msg);
		}
		bool operator()(const MSG &msg)
		{
			return m_fun_ptr(msg);
		}

		operator bool()
		{
			return (m_fun_ptr != nullptr);
		}

	private:
		std::function<details::message_process_callback> m_fun_ptr;
	};

	class work_callback_wrapper
	{
	public:
		work_callback_wrapper() = delete;
		work_callback_wrapper(nullptr_t) : m_fun_ptr(nullptr)
		{
		}
		template <typename L>
		work_callback_wrapper(L l) : m_fun_ptr(l)
		{
		}
		template <typename F>
		work_callback_wrapper(F *f) : m_fun_ptr([f]() -> bool {return f(); })
		{
		}
		template <typename O, typename M>
		work_callback_wrapper(O *o, M m) : m_fun_ptr([o, m]() mutable ->bool {return (o->*m)(); })
		{
		}

		work_callback_wrapper(const work_callback_wrapper &) = default;
		work_callback_wrapper(work_callback_wrapper &&) = default;

		bool invoke()
		{
			return m_fun_ptr();
		}
		bool operator()()
		{
			return m_fun_ptr();
		}

		operator bool()
		{
			return (m_fun_ptr != nullptr);
		}

	private:
		std::function<details::work_process_callback> m_fun_ptr;
	};
}