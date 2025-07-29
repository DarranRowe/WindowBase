#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <array>
#include <cstdio>
#include <string>
#include <version>

#if __has_include(<fmt/format.h>)
//The usage of FMT must be header only for ARM64.
//This library is built as ARM64X, so it contains the native
//ARM64 version and the EC version in one. VCPKG doesn't build
//fmt as ARM64X, so not setting this will result in linker errors.
#if (!(defined FMT_HEADER_ONLY)) && (defined WINDOWBASE_BUILD)
#define FMT_HEADER_ONLY 1
#endif
#include <fmt/format.h>
#include <fmt/xchar.h>
inline static constexpr bool format_fmt = true;
inline static constexpr bool format_std = false;
#else
#ifdef __cpp_lib_format
#include <format>
#define STD_FORMAT_INCLUDED
inline static constexpr bool format_fmt = false;
inline static constexpr bool format_std = true;
#else
inline static constexpr bool format_fmt = false;
inline static constexpr bool format_std = false;
#endif
#endif

template <typename T, size_t N>
char (*array_number_of(T(&)[N]))[N];

#define ARRAY_SIZE(A) (sizeof(*array_number_of(A)))

namespace window_base
{
	namespace utf_convert
	{
		inline constexpr bool char_is_utf8()
		{
			using uc = unsigned char;

			auto &c{ "\u00a0" };
			if constexpr (ARRAY_SIZE(c) != 3)
			{
				return false;
			}

			if (uc(c[0]) != uc(0xc2) || uc(c[1]) != uc(0xa0))
			{
				return false;
			}

			return true;
		}

#ifndef __cpp_char8_t
		inline static constexpr bool utf8_in_char = char_is_utf8();
		inline static constexpr bool utf8_char8_t = false;
		using char8_t = char;
		using u8string_t = std::string;
#else
		inline static constexpr bool utf8_in_char = false;
		inline static constexpr bool utf8_char8_t = true;
		using u8string_t = std::u8string;
#endif

		inline static constexpr const char16_t high_surrogate_prefix{ static_cast<char16_t>(0xD800) };
		inline static constexpr const char16_t low_surrogate_prefix{ static_cast<char16_t>(0xDC00) };
		inline static constexpr const char16_t surrogate_begin{ static_cast<char16_t>(0xD800) };
		inline static constexpr const char16_t high_surrogate_begin{ static_cast<char16_t>(0xD800) };
		inline static constexpr const char16_t low_surrogate_begin{ static_cast<char16_t>(0xDC00) };
		inline static constexpr const char16_t surrogate_end{ static_cast<char16_t>(0xE000) };
		inline static constexpr const char16_t surrogate_valid_bit_mask{ static_cast<char16_t>(0x03FF) };
		inline static constexpr const char32_t surrogate_prime_value{ static_cast<char32_t>(0x10000) };

		inline static constexpr const char32_t unicode_invalid{ static_cast<char32_t>(0xffffffff) };
		inline static constexpr const char32_t unicode_max{ static_cast<char32_t>(0x10ffff) };
		inline static constexpr const char32_t utf16_surrogate_limit{ static_cast<char32_t>(0x10000) };
		inline static constexpr const char32_t utf8_one_byte_limit{ static_cast<char32_t>(0x0080) };
		inline static constexpr const char32_t utf8_two_byte_limit{ static_cast<char32_t>(0x0800) };
		inline static constexpr const char32_t utf8_three_byte_limit{ static_cast<char32_t>(0x10000) };

		inline static constexpr const char8_t utf8_follow_byte_prefix{ static_cast<char8_t>(0x80) };
		inline static constexpr const char8_t utf8_two_byte_prefix{ static_cast<char8_t>(0xc0) };
		inline static constexpr const char8_t utf8_three_byte_prefix{ static_cast<char8_t>(0xe0) };
		inline static constexpr const char8_t utf8_four_byte_prefix{ static_cast<char8_t>(0xf0) };
		inline static constexpr const char8_t utf8_follow_valid_bit_mask{ static_cast<char8_t>(0x3f) };
		inline static constexpr const char8_t utf8_one_byte_valid_bit_mask{ static_cast<char8_t>(0x7f) };
		inline static constexpr const char8_t utf8_two_byte_valid_bit_mask{ static_cast<char8_t>(0x1f) };
		inline static constexpr const char8_t utf8_three_byte_valid_bit_mask{ static_cast<char8_t>(0x0f) };
		inline static constexpr const char8_t utf8_four_byte_valid_bit_mask{ static_cast<char8_t>(0x07) };
		inline static constexpr const char8_t utf8_null_char{ static_cast<char8_t>(0x00) };
		inline static constexpr const int32_t utf8_code_unit_max{ 4 };

		struct u16codepoint
		{
			char16_t first;
			char16_t second;
			bool surrogate;
		};

		struct u8codepoint
		{
			char8_t first;
			char8_t second;
			char8_t third;
			char8_t fourth;
			int32_t codeunits;
		};

		inline constexpr char32_t decode_surrogate(char16_t high, char16_t low)
		{
			_ASSERTE((high & high_surrogate_prefix) == high_surrogate_prefix);
			_ASSERTE((low & low_surrogate_prefix) == low_surrogate_prefix);

			const char16_t high_bits{ char16_t(high & surrogate_valid_bit_mask) };
			const char16_t low_bits{ char16_t(low & surrogate_valid_bit_mask) };
			const char32_t c{ static_cast<char32_t>(high_bits) << 10 | static_cast<char32_t>(low_bits) };

			return c + surrogate_prime_value;
		}

		inline constexpr u16codepoint encode_surrogate(char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);
			const char32_t cpp{ cp - surrogate_prime_value };

			const char16_t high_surrogate{ char16_t((static_cast<char16_t>(cpp >> 10) & surrogate_valid_bit_mask) | high_surrogate_prefix) };
			const char16_t low_surrogate{ char16_t((static_cast<char16_t>(cpp) & surrogate_valid_bit_mask) | low_surrogate_prefix) };
			return { high_surrogate, low_surrogate, true };
		}

		inline constexpr char32_t decode_u8(char8_t cu1)
		{
			return char32_t(cu1);
		}

		inline constexpr char32_t decode_u8(char8_t cu1, char8_t cu2)
		{
			const char8_t cu1_bits{ char8_t(cu1 & utf8_two_byte_valid_bit_mask) };
			const char8_t cu2_bits{ char8_t(cu2 & utf8_follow_valid_bit_mask) };
			const char32_t cp{ static_cast<char32_t>(cu1_bits) << 6 | static_cast<char32_t>(cu2_bits) };
			return cp;
		}

		inline constexpr char32_t decode_u8(char8_t cu1, char8_t cu2, char8_t cu3)
		{
			const char8_t cu1_bits{ char8_t(cu1 & utf8_three_byte_valid_bit_mask) };
			const char8_t cu2_bits{ char8_t(cu2 & utf8_follow_valid_bit_mask) };
			const char8_t cu3_bits{ char8_t(cu3 & utf8_follow_valid_bit_mask) };
			const char32_t cp{ static_cast<char32_t>(cu1_bits) << 12 | static_cast<char32_t>(cu2_bits) << 6 | static_cast<char32_t>(cu3_bits) };
			return cp;
		}

		inline constexpr char32_t decode_u8(char8_t cu1, char8_t cu2, char8_t cu3, char8_t cu4)
		{
			const char8_t cu1_bits{ char8_t(cu1 & utf8_four_byte_valid_bit_mask) };
			const char8_t cu2_bits{ char8_t(cu2 & utf8_follow_valid_bit_mask) };
			const char8_t cu3_bits{ char8_t(cu3 & utf8_follow_valid_bit_mask) };
			const char8_t cu4_bits{ char8_t(cu4 & utf8_follow_valid_bit_mask) };
			const char32_t cp = static_cast<char32_t>(cu1_bits) << 18 | static_cast<char32_t>(cu2_bits) << 12 | static_cast<char32_t>(cu3_bits) << 6 | static_cast<char32_t>(cu4_bits);
			return cp;
		}

		inline constexpr u8codepoint encode_u8_one(char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);

			return u8codepoint{ static_cast<char8_t>(cp), utf8_null_char, utf8_null_char, utf8_null_char, 1 };
		}

		inline constexpr u8codepoint encode_u8_two(char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);

			const char8_t cu1{ char8_t(utf8_two_byte_prefix | char8_t(cp >> 6) & utf8_two_byte_valid_bit_mask) };
			const char8_t cu2{ char8_t(utf8_follow_byte_prefix | char8_t(cp) & utf8_follow_valid_bit_mask) };
			return u8codepoint{ cu1, cu2, utf8_null_char, utf8_null_char, 2 };
		}

		inline constexpr u8codepoint encode_u8_three(char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);

			const char8_t cu1{ char8_t(utf8_three_byte_prefix | char8_t(cp >> 12) & utf8_three_byte_valid_bit_mask) };
			const char8_t cu2{ char8_t(utf8_follow_byte_prefix | char8_t(cp >> 6) & utf8_follow_valid_bit_mask) };
			const char8_t cu3{ char8_t(utf8_follow_byte_prefix | char8_t(cp) & utf8_follow_valid_bit_mask) };
			return u8codepoint{ cu1, cu2, cu3, utf8_null_char, 3 };
		}

		inline constexpr u8codepoint encode_u8_four(char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);

			const char8_t cu1{ char8_t(utf8_four_byte_prefix | char8_t(cp >> 18) & utf8_four_byte_valid_bit_mask) };
			const char8_t cu2{ char8_t(utf8_follow_byte_prefix | char8_t(cp >> 12) & utf8_follow_valid_bit_mask) };
			const char8_t cu3{ char8_t(utf8_follow_byte_prefix | char8_t(cp >> 6) & utf8_follow_valid_bit_mask) };
			const char8_t cu4{ char8_t(utf8_follow_byte_prefix | char8_t(cp) & utf8_follow_valid_bit_mask) };
			return u8codepoint{ cu1, cu2, cu3, cu4, 4 };
		}

		inline constexpr u16codepoint char32_to_char16(const char32_t cp)
		{
			if (cp >= utf16_surrogate_limit)
			{
				return encode_surrogate(cp);
			}

			return { char16_t(cp), u'\0', false };
		}

		inline constexpr char32_t char16_to_char32(const u16codepoint &c)
		{
			if (c.surrogate)
			{
				return decode_surrogate(c.first, c.second);
			}

			return static_cast<char32_t>(c.first);
		}

		inline constexpr u8codepoint char32_to_char8(const char32_t cp)
		{
			_ASSERTE(cp <= unicode_max);

			if (cp < utf8_one_byte_limit)
			{
				return encode_u8_one(cp);
			}
			if (cp < utf8_two_byte_limit)
			{
				return encode_u8_two(cp);
			}
			if (cp < utf8_three_byte_limit)
			{
				return encode_u8_three(cp);
			}
			return encode_u8_four(cp);
		}

		inline constexpr char32_t char8_to_char32(const u8codepoint &c)
		{
			_ASSERTE(c.codeunits <= utf8_code_unit_max && c.codeunits > 0);

			switch (c.codeunits)
			{
			case 1:
				return decode_u8(c.first);
			case 2:
				return decode_u8(c.first, c.second);
			case 3:
				return decode_u8(c.first, c.second, c.third);
			case 4:
				return decode_u8(c.first, c.second, c.third, c.fourth);
			}

			//This is just to remove a compiler warning.
			//Other safeguards should not allow this invalid character to be returned.
			return unicode_invalid;
		}

		//These do very little validation.
		//The intent is to only use them to convert valid strings, such an existing string literal.
		inline std::u16string to_u16string(const u8string_t &str)
		{
			_ASSERTE(utf8_char8_t || utf8_in_char);

			std::u16string buffer;
			u8codepoint cp{};
			bool in_cp{};
			int32_t cp_current{};
			int32_t cp_max{};
			for (auto &&cu : str)
			{
				if (cu < utf8_follow_byte_prefix)
				{
					//One byte.
					buffer.push_back(char16_t(cu));
				}
				else
				{
					if (cu < utf8_two_byte_prefix)
					{
						//Follow byte.
						_ASSERTE(in_cp == true);
						++cp_current;
						switch (cp_current)
						{
						case 2:
							cp.second = cu;
							break;
						case 3:
							cp.third = cu;
							break;
						case 4:
							cp.fourth = cu;
							break;
						}

						if (cp_current == cp_max)
						{
							auto cp16{ char32_to_char16(char8_to_char32(cp)) };
							buffer.push_back(cp16.first);
							if (cp16.surrogate)
							{
								buffer.push_back(cp16.second);
							}

							cp = {};
							in_cp = false;
							cp_current = 0;
							cp_max = 0;
						}
					}
					else
					{
						if (cu < utf8_three_byte_prefix)
						{
							//Two byte lead.
							cp.first = cu;
							cp.codeunits = 2;
							in_cp = true;
							cp_current = 1;
							cp_max = 2;
						}
						else
						{
							if (cu < utf8_four_byte_prefix)
							{
								//Three byte lead.
								cp.first = cu;
								cp.codeunits = 3;
								in_cp = true;
								cp_current = 1;
								cp_max = 3;
							}
							else
							{
								//Three byte lead.
								cp.first = cu;
								cp.codeunits = 4;
								in_cp = true;
								cp_current = 1;
								cp_max = 4;
							}
						}
					}
				}
			}

			return buffer;
		}

		inline std::u16string to_u16string(const std::u32string &str)
		{
			std::u16string buffer;

			for (auto &&cp : str)
			{
				if (cp < utf16_surrogate_limit)
				{
					buffer.push_back(char16_t(cp));
				}
				else
				{
					auto surrogate = encode_surrogate(cp);
					buffer.push_back(surrogate.first);
					buffer.push_back(surrogate.second);
				}
			}

			return buffer;
		}

		inline std::u32string to_u32string(const u8string_t &str)
		{
			_ASSERTE(utf8_char8_t || utf8_in_char);

			std::u32string buffer;
			u8codepoint cp{};
			bool in_cp{};
			int32_t cp_current{};
			int32_t cp_max{};
			for (auto &&cu : str)
			{
				if (cu < utf8_follow_byte_prefix)
				{
					//One byte.
					buffer.push_back(char16_t(cu));
				}
				else
				{
					if (cu < utf8_two_byte_prefix)
					{
						//Follow byte.
						_ASSERTE(in_cp == true);
						++cp_current;
						switch (cp_current)
						{
						case 2:
							cp.second = cu;
							break;
						case 3:
							cp.third = cu;
							break;
						case 4:
							cp.fourth = cu;
							break;
						}

						if (cp_current == cp_max)
						{
							buffer.push_back(char8_to_char32(cp));

							cp = {};
							in_cp = false;
							cp_current = 0;
							cp_max = 0;
						}
					}
					else
					{
						if (cu < utf8_three_byte_prefix)
						{
							//Two byte lead.
							cp.first = cu;
							cp.codeunits = 2;
							in_cp = true;
							cp_current = 1;
							cp_max = 2;
						}
						else
						{
							if (cu < utf8_four_byte_prefix)
							{
								//Three byte lead.
								cp.first = cu;
								cp.codeunits = 3;
								in_cp = true;
								cp_current = 1;
								cp_max = 3;
							}
							else
							{
								//Three byte lead.
								cp.first = cu;
								cp.codeunits = 4;
								in_cp = true;
								cp_current = 1;
								cp_max = 4;
							}
						}
					}
				}
			}

			return buffer;
		}

		inline std::u32string to_u32string(const std::u16string &str)
		{
			std::u32string buffer;
			u16codepoint cp{};
			bool in_surrogate{};
			bool cp_complete{};

			for (auto &&cu : str)
			{
				if (!in_surrogate)
				{
					_ASSERTE(cu < low_surrogate_begin || cu > surrogate_end);

					cp.first = cu;
					if (cu >= high_surrogate_begin && cu < low_surrogate_begin)
					{
						in_surrogate = true;
						cp.surrogate = true;
					}
					else
					{
						cp_complete = true;
					}
				}
				if (in_surrogate)
				{
					_ASSERTE(cu >= low_surrogate_begin && cu < surrogate_end);
					cp.second = cu;
					cp_complete = true;
				}
				if (cp_complete)
				{
					buffer.push_back(char16_to_char32(cp));
				}
			}

			return buffer;
		}

		inline u8string_t to_u8string(const std::u16string &str)
		{
			_ASSERTE(utf8_char8_t || utf8_in_char);

			u8string_t buffer;
			u16codepoint cp{};
			u8codepoint u8cp{};
			bool in_surrogate{};
			bool cp_complete{};

			for (auto &&cu : str)
			{
				if (!in_surrogate)
				{
					_ASSERTE(cu < low_surrogate_begin || cu > surrogate_end);

					cp.first = cu;
					if (cu >= high_surrogate_begin && cu < low_surrogate_begin)
					{
						in_surrogate = true;
						cp.surrogate = true;
					}
					else
					{
						cp_complete = true;
					}
				}
				if (in_surrogate)
				{
					_ASSERTE(cu >= low_surrogate_begin && cu < surrogate_end);
					cp.second = cu;
					cp_complete = true;
				}
				if (cp_complete)
				{
					u8cp = char32_to_char8(char16_to_char32(cp));

					buffer.push_back(u8cp.first);
					if (u8cp.codeunits >= 2)
					{
						buffer.push_back(u8cp.second);
					}
					if (u8cp.codeunits >= 3)
					{
						buffer.push_back(u8cp.third);
					}
					if (u8cp.codeunits >= 4)
					{
						buffer.push_back(u8cp.fourth);
					}

					cp_complete = false;
					in_surrogate = false;
					u8cp = {};
					cp = {};
				}
			}

			return buffer;
		}

		inline u8string_t to_u8string(const std::u32string &str)
		{
			_ASSERTE(utf8_char8_t || utf8_in_char);

			u8string_t buffer;

			for (auto &&cu : str)
			{
				u8codepoint u8cp = char32_to_char8(cu);

				buffer.push_back(u8cp.first);
				if (u8cp.codeunits >= 2)
				{
					buffer.push_back(u8cp.second);
				}
				if (u8cp.codeunits >= 3)
				{
					buffer.push_back(u8cp.third);
				}
				if (u8cp.codeunits >= 4)
				{
					buffer.push_back(u8cp.fourth);
				}
			}

			return buffer;
		}
	}

	namespace output_helpers
	{
#ifdef FMT_FORMAT_H_
		template <typename Char>
		using string_view_t = std::conditional_t<format_fmt == true, fmt::basic_string_view<Char>, std::basic_string_view<Char>>;
#else
		template <typename Char>
		using string_view_t = std::basic_string_view<Char>;
#endif

		template <typename Char, class... _Args>
		auto make_fmt_format_args(_Args &..._Vals)
		{
#ifdef FMT_FORMAT_H_
			if constexpr (std::is_same_v<Char, char>)
			{
				return fmt::make_format_args<fmt::format_context, _Args...>(_Vals...);
			}
			else
			{
				if constexpr (std::is_same_v<Char, wchar_t>)
				{
					return fmt::make_format_args<fmt::wformat_context, _Args...>(_Vals...);
				}
				else
				{
					return fmt::make_format_args<fmt::buffered_context<Char>, _Args...>(_Vals...);
				}
			}
#endif
		}

		template <typename Char, class... _Args>
		auto make_std_format_args(_Args &..._Vals)
		{
#ifdef _FORMAT_
			if constexpr (std::is_same_v<Char, char>)
			{
				return std::make_format_args<std::format_context, _Args...>(_Vals...);
			}
			else
			{
				return std::make_format_args<std::wformat_context, _Args...>(_Vals...);
			}
#endif
		}

		template <typename Char = char, class... _Args>
		auto make_format_args(_Args &&..._Vals)
		{
			static_assert(format_fmt || format_std, "This can only be used if a formatter library is available");

			if constexpr (format_fmt)
			{
				return make_fmt_format_args<Char>(std::forward<_Args>(_Vals)...);
			}
			if constexpr (format_std)
			{
				return make_std_format_args<Char>(std::forward<_Args>(_Vals)...);
			}
		}

		template<typename Char, typename ...Types>
		inline std::basic_string<Char> format(string_view_t<Char> fmt, Types &&..._Args)
		{
			static_assert(format_fmt || format_std, "This can only be used if a formatter library is available");

#ifdef FMT_FORMAT_H_
			if constexpr (format_fmt)
			{
				return fmt::vformat(fmt, output_helpers::make_format_args<Char>(_Args...));
			}
#endif
#ifdef _FORMAT_
			if constexpr (format_std)
			{
				return std::vformat(fmt, output_helpers::make_format_args<Char>(_Args...));
			}
#endif
		}

		template<typename Char, typename ...Types>
		inline std::basic_string<Char> format(const std::locale &_Loc, string_view_t<Char> fmt, Types &&..._Args)
		{
			static_assert(format_fmt || format_std, "This can only be used if a formatter library is available");

#ifdef FMT_FORMAT_H_
			if constexpr (format_fmt)
			{
				return fmt::vformat(_Loc, fmt, output_helpers::make_format_args<Char>(_Args...));
			}
#endif
#ifdef _FORMAT_
			if constexpr (format_std)
			{
				return std::vformat(_Loc, fmt, output_helpers::make_format_args<Char>(_Args...));
			}
#endif
		}

		namespace debug
		{
			//We are more limited with the debugger.
			//There are only two functions, the A and W versions.
			//Converting from UTF-8 to UTF-16 or UTF-32 to UTF-16 and then using the W
			//version should be relatively fast.
			bool is_debugger_present();
			void output_debug_string(const char *);
			void output_debug_string(const wchar_t *);

			template <typename Char = char>
			struct format_specs
			{
				inline static constexpr const Char(&new_line)[3] = "\r\n";
				inline static constexpr const bool exotic = false;
			};

			template <>
			struct format_specs<wchar_t>
			{
				inline static constexpr const wchar_t(&new_line)[3] = L"\r\n";
				inline static constexpr const bool exotic = false;
			};

			template <>
			struct format_specs<char16_t>
			{
				inline static constexpr const char16_t(&new_line)[3] = u"\r\n";
				inline static constexpr const bool exotic = true;
			};

			template <>
			struct format_specs<char32_t>
			{
				inline static constexpr const char32_t(&new_line)[3] = U"\r\n";
				inline static constexpr const bool exotic = true;
			};

#ifdef __cpp_char8_t
			template <>
			struct format_specs<char8_t>
			{
				inline static constexpr const char8_t(&new_line)[3] = u8"\r\n";
				inline static constexpr const bool exotic = true;
			};
#endif

			template <typename Char>
			inline void debug_output(const std::basic_string<Char> &output_str)
			{
				if constexpr (!format_specs<Char>::exotic)
				{
					output_debug_string(output_str.c_str());
				}
				else
				{
					if constexpr (std::is_same_v<Char, char16_t>)
					{
						output_debug_string(reinterpret_cast<const wchar_t *>(output_str.c_str()));
					}
					if constexpr (std::is_same_v<Char, char32_t>)
					{
						output_debug_string(reinterpret_cast<const wchar_t *>(utf_convert::to_u16string(output_str).c_str()));
					}
#if __cpp_char8_t
					if constexpr (std::is_same_v<Char, char8_t>)
					{
						output_debug_string(reinterpret_cast<const wchar_t *>(utf_convert::to_u16string(output_str).c_str()));
					}
#endif
				}
			}

			template <typename Char, typename ...Types>
			inline void format_debugwrite(string_view_t<Char> fmt, Types &&..._Args)
			{
				if (is_debugger_present())
				{
					auto fmt_string = format<Char>(fmt, std::forward<Types>(_Args)...);
					debug_output(fmt_string);
				}
			}

			template <typename Char, typename ...Types>
			inline void format_debugwrite(const std::locale &_Loc, string_view_t<Char> fmt, Types &&..._Args)
			{
				if (is_debugger_present())
				{
					auto fmt_string = format<Char>(_Loc, fmt, std::forward<Types>(_Args)...);
					debug_output(fmt_string);
				}
			}

			template <typename Char, typename ...Types>
			inline void format_debugwriteln(string_view_t<Char> fmt, Types &&..._Args)
			{
				if (is_debugger_present())
				{
					auto fmt_string = format<Char>(fmt, std::forward<Types>(_Args)...);
					fmt_string += format_specs<Char>::new_line;
					debug_output(fmt_string);
				}
			}

			template <typename Char, typename ...Types>
			inline void format_debugwriteln(const std::locale &_Loc, string_view_t<Char> fmt, Types &&..._Args)
			{
				if (is_debugger_present)
				{
					auto fmt_string = format<Char>(_Loc, fmt, std::forward<Types>(_Args)...);
					fmt_string += format_specs<Char>::new_line;
					debug_output(fmt_string);
				}
			}

			template <typename Char, size_t N, typename ...Types>
			inline void format_debugwrite(const Char(&fmt)[N], Types &&..._Args)
			{
				format_debugwrite<Char>(string_view_t<Char>(fmt, N - 1), std::forward<Types>(_Args)...);
			}

			template <typename Char, size_t N, typename ...Types>
			inline void format_debugwrite(const std::locale &_Loc, const Char(&fmt)[N], Types &&..._Args)
			{
				format_debugwrite<Char>(_Loc, string_view_t<Char>(fmt, N - 1), std::forward<Types>(_Args)...);
			}

			template <typename Char, size_t N, typename ...Types>
			inline void format_debugwriteln(const Char(&fmt)[N], Types &&..._Args)
			{
				format_debugwriteln<Char>(string_view_t<Char>(fmt, N - 1), std::forward<Types>(_Args)...);
			}

			template <typename Char, size_t N, typename ...Types>
			inline void format_debugwriteln(const std::locale &_Loc, const Char(&fmt)[N], Types &&..._Args)
			{
				format_debugwriteln<Char>(_Loc, string_view_t<Char>(fmt, N - 1), std::forward<Types>(_Args)...);
			}
		}
	}
}