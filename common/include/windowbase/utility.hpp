#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

//Since this is guaranteed to be used with a C++ compiler, there is no issues taking a dependency on type_traits
#include <type_traits>

#define ENUM_BITWISE_OPERATORS(ENUMTYPE)\
inline constexpr ENUMTYPE operator| (ENUMTYPE a, ENUMTYPE b) noexcept { using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return ENUMTYPE(static_cast<ut>(a) | static_cast<ut>(b)); }\
inline constexpr ENUMTYPE operator& (ENUMTYPE a, ENUMTYPE b) noexcept { using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return ENUMTYPE(static_cast<ut>(a) & static_cast<ut>(b)); }\
inline constexpr ENUMTYPE operator^ (ENUMTYPE a, ENUMTYPE b) noexcept { using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return ENUMTYPE(static_cast<ut>(a) ^ static_cast<ut>(b)); }\
inline constexpr ENUMTYPE operator~ (ENUMTYPE a) noexcept { using namespace std; return ENUMTYPE(~static_cast<underlying_type_t<ENUMTYPE>>(a)); }\
inline ENUMTYPE &operator|= (ENUMTYPE &a, ENUMTYPE b) noexcept {using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return reinterpret_cast<ENUMTYPE &>(reinterpret_cast<ut &>(a) |= static_cast<ut>(b)); }\
inline ENUMTYPE &operator&= (ENUMTYPE &a, ENUMTYPE b) noexcept {using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return reinterpret_cast<ENUMTYPE &>(reinterpret_cast<ut &>(a) &= static_cast<ut>(b)); }\
inline ENUMTYPE &operator^= (ENUMTYPE &a, ENUMTYPE b) noexcept {using namespace std; typedef underlying_type_t<ENUMTYPE> ut; return reinterpret_cast<ENUMTYPE &>(reinterpret_cast<ut &>(a) ^= static_cast<ut>(b)); }

namespace window_base::utility::conversion
{
	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto value_convert(From v) noexcept -> std::enable_if_t<(std::is_fundamental_v<To> || std::is_enum_v<To>) && (std::is_fundamental_v<From> || std::is_enum_v<From>), To>
	{
		return static_cast<To>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto type_convert(From *v) noexcept -> To *
	{
		return reinterpret_cast<To *>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto pointer_convert(From *v) noexcept -> To *
	{
		return static_cast<To *>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto function_pointer_convert(From *v) noexcept -> To *
	{
		return reinterpret_cast<To *>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto handle_cast(From v) noexcept -> To
	{
		return reinterpret_cast<To>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto unsafe_cast(From v) noexcept -> To
	{
		return reinterpret_cast<To>(v);
	}

	template <typename DerivedType, typename BaseType>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto down_cast(BaseType *that) noexcept -> DerivedType *
	{
		static_assert(std::is_base_of_v<BaseType, DerivedType>);
		return static_cast<DerivedType *>(that);
	}

	template <typename BaseType, typename DerivedType>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto up_cast(DerivedType *that) noexcept -> BaseType *
	{
		static_assert(std::is_base_of_v<BaseType, DerivedType>);
		return static_cast<BaseType *>(that);
	}

	//This must only be used to convert WPARAM
	//and LPARAM to a handle type.
	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto handle_from_param(From v) noexcept -> std::enable_if_t<std::is_integral_v<From>, To>
	{
		return reinterpret_cast<To>(v);
	}

	//This must only be used to convert WPARAM
	//and LPARAM to a pointer to struct type.
	//This is used in cases where WPARAM or LPARAM
	//is used as a pointer.
	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto pointer_from_param(From v) noexcept -> std::enable_if_t<std::is_integral_v<From>, To *>
	{
		return reinterpret_cast<To *>(v);
	}

	//This must only be used to convert WPARAM
	//and LPARAM to a reference to struct type.
	//This is used in cases where WPARAM or LPARAM
	//is used as a pointer.
	template <typename To, typename From>
	inline auto reference_from_param(From v) -> std::enable_if_t<std::is_integral_v<From>, To &>
	{
		return *pointer_from_param<To>(v);
	}

	template <typename T>
	inline auto pointer_deref(T *v) noexcept -> T &
	{
		return *v;
	}

	//Used in cases where there is a structure packed in
	//WPARAM or LPARAM.
	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto pointer_from_param_address(From *v) noexcept -> std::enable_if_t<std::is_integral_v<From>, To *>
	{
		return reinterpret_cast<To *>(v);
	}

	//Used in cases where there is a structure packed in
	//WPARAM or LPARAM.
	template <typename To, typename From>
	inline auto reference_from_param_address(From *v) noexcept -> To &
	{
		return *pointer_from_param_address<To>(v);
	}

	//Used for returns where a handle type is stored
	//in the return.
	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto handle_to_return(From v) noexcept -> To
	{
		return reinterpret_cast<To>(v);
	}

	template <typename To, typename From>
#ifdef _MSC_VER
	[[msvc::intrinsic]]
#endif
	inline auto pointer_to_return(From *v) noexcept -> To
	{
		return reinterpret_cast<To>(v);
	}
}