#ifndef WINDOW_TEMPLATE_INCLUDED
#error This header must not be included directly. Include window.hpp.
#endif

namespace window_base::windowing
{
	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT CALLBACK window_t<DerivedType, CustomHandler, UnicodeBase>::cbt_hook_proc(int code, WPARAM wparam, LPARAM lparam)
	{
		using utility::conversion::pointer_convert;
		using utility::conversion::down_cast;
		using utility::conversion::handle_from_param;
		using utility::conversion::reference_from_param;

		if (code < 0 || code != HCBT_CREATEWND)
		{
			return CallNextHookEx(my_type::s_create_hook, code, wparam, lparam);
		}
		else
		{
			{
				//This is dependent on the character set, because of how we use
				//CBT_CREATEWNDX, i.e. we don't touch any string parameters,
				//we can get away with typedefing this type based upon whether
				//we define the window to be ansi or unicode.
				HWND wnd{ handle_from_param<HWND>(wparam) };
				typename my_traits_t::cbt_createwnd_t &params{ reference_from_param<typename my_traits_t::cbt_createwnd_t>(lparam) };

				void *instance{ params.lpcs->lpCreateParams };
				//The pointer passed in to CreateWindowEx is a pointer to window_base. Since this doesn't have to have the
				//same address as the most derived type, the create params is first converted to a window_base * and then
				//to a DerivedType *.
				my_tptr that{ down_cast<my_t>(pointer_convert<my_base_t>(instance)) };
				that->set_window_info(wnd, GetCurrentThreadId(), instance);
			}

			auto result{ CallNextHookEx(my_type::s_create_hook, code, wparam, lparam) };
			UnhookWindowsHookEx(my_type::s_create_hook);
			my_type::s_create_hook = nullptr;
			return result;
		}
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::hook_create()
	{
		my_type::s_create_hook = my_traits_t::WndSetWindowsHookEx(WH_CBT, my_type::cbt_hook_proc, nullptr, GetCurrentThreadId());
		return my_type::s_create_hook != nullptr ? true : false;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::create_window(const my_string_view_t &class_name, const my_string_view_t &title, DWORD style, DWORD ex_style, const POINT &top_left, const SIZE &dimentions, DerivedType *that, HWND parent, HMENU menu)
	{
		using utility::conversion::up_cast;

		if (!hook_create())
		{
			return false;
		}

		//Cast to the derived type to make sure that the pointer we pass to CreateWindowExW is the correct pointer.
		//We can't be sure of the derived class layout, so this is to be sure.
		my_base_t *base_ptr = up_cast<my_base_t>(that);
		auto result{ my_base_t::create_window(ex_style, style, class_name, title, top_left, dimentions, parent, menu, base_ptr) };

		return result == nullptr ? false : true;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT window_t<DerivedType, CustomHandler, UnicodeBase>::message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
	{
		if constexpr (!CustomHandler)
		{
			auto [result, handled] {default_message_handler(msg, wparam, lparam)};

			if (handled)
			{
				return result;
			}
		}

		return my_traits_t::WndDefWindowProc(my_base_t::get_handle(), msg, wparam, lparam);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::on_command_default(uint16_t identifier, uint16_t notification_code, HWND control_handle)
	{
		bool handled{};
		using wmt = window_msg_types;
		using utility::conversion::down_cast;
		if constexpr (details::detect_v<DerivedType, wmt::template get_commandhandler_t>)
		{
			constexpr const bool return_handler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
			constexpr const bool return_chandler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
			static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
			auto &command_handler{ down_cast<DerivedType>(this)->get_commandhandler() };

			for (auto &&entry : command_handler.command_handlers)
			{
				if (entry.type == handler_type::menu)
				{
					_ASSERTE(notification_code == 0);
					_ASSERTE(control_handle == nullptr);
				}
				if (entry.type == handler_type::menu)
				{
					_ASSERTE(notification_code == 1);
					_ASSERTE(control_handle == nullptr);
				}
				if (entry.identifier == identifier && entry.notification == notification_code)
				{
					//Only pass in the control handle here.
					//The function is written specifically for the identifier/notification pair.
					entry.command_handler(control_handle);
					//If the function is called then we see it as handled.
					handled = true;
				}
			}
		}

		return handled;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::on_syscommand_default(syscommand_info info, int32_t xpos, int32_t ypos)
	{
		bool handled{};
		using wmt = window_msg_types;
		using utility::conversion::down_cast;
		if constexpr (details::detect_v<DerivedType, wmt::template get_commandhandler_t>)
		{
			constexpr const bool return_handler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
			constexpr const bool return_chandler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
			static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
			auto &command_handler{ down_cast<DerivedType>(this)->get_commandhandler() };

			for (auto &&entry : command_handler.syscommand_handlers)
			{
				if (entry.request == info.request)
				{
					entry.syscommand_handler(info, xpos, ypos);
					handled = true;
				}
			}
		}

		return handled;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline std::pair<LRESULT, bool> window_t<DerivedType, CustomHandler, UnicodeBase>::on_notify_default(const NMHDR &notify_info)
	{
		bool handled{};
		LRESULT proc_result{};
		using wmt = window_msg_types;
		using utility::conversion::down_cast;

		if constexpr (details::detect_v<DerivedType, wmt::template get_commandhandler_t>)
		{
			constexpr const bool return_handler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
			constexpr const bool return_chandler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
			static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
			auto &command_handler{ down_cast<DerivedType>(this)->get_commandhandler() };

			for (auto &&entry : command_handler.notify_handlers)
			{
				if (entry.identifier == notify_info.idFrom && entry.notification == notify_info.code)
				{
					proc_result = entry.notify_handler(notify_info);
					handled = true;
				}
			}
		}

		return { proc_result, handled };
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::on_appcommand_default(appcommand_info info, int32_t xpos, int32_t ypos)
	{
		bool handled{};
		using wmt = window_msg_types;
		using utility::conversion::down_cast;
		if constexpr (details::detect_v<DerivedType, wmt::template get_commandhandler_t>)
		{
			constexpr const bool return_handler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
			constexpr const bool return_chandler{ details::same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
			static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
			auto &command_handler{ down_cast<DerivedType>(this)->get_commandhandler() };

			for (auto &&entry : command_handler.appcommand_handlers)
			{
				if (entry.command == info.appcommand)
				{
					entry.appcommand_handler(info, xpos, ypos);
					handled = true;
				}
			}
		}

		return handled;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline std::pair<LRESULT, bool> window_t<DerivedType, CustomHandler, UnicodeBase>::default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
	{
		using utility::conversion::down_cast;
		using utility::conversion::value_convert;
		using utility::conversion::pointer_from_param;
		using utility::conversion::reference_from_param;
		using utility::conversion::pointer_convert;
		using utility::conversion::pointer_deref;
		using utility::conversion::pointer_from_param_address;
		using utility::conversion::reference_from_param_address;
		using utility::conversion::handle_cast;
		using utility::conversion::handle_to_return;

		using details::return_type_t;
		using details::detect_v;
		using details::same_return_v;
		using details::convertable_return_v;
		using details::integral_return_v;
		using std::make_pair;
		using wmt = window_msg_types;

		bool handled{};
		LRESULT proc_result{};

		switch (msg)
		{
		case 0x0000:
		{
			break;
		}
		case WM_CREATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_create_t>)
			{
				constexpr const bool return_bool{ same_return_v<DerivedType, wmt::template on_create_t, bool> };
				constexpr const bool return_cbool{ convertable_return_v<DerivedType, wmt::template on_create_t, bool> };

				if constexpr (return_bool || return_cbool)
				{
					LRESULT result{ value_convert<bool>(down_cast<DerivedType>(this)->on_create(reference_from_param<typename my_traits_t::create_struct_t>(lparam))) == false ? -1 : 0 };
					proc_result = result;

				}
				else
				{
					down_cast<DerivedType>(this)->on_create(reference_from_param<typename my_traits_t::create_struct_t>(lparam));
					//proc_result is initialised to 0. The handler for WM_CREATE returns 0 to indicate success.
				}

				handled = true;
			}
			break;
		}
		case WM_DESTROY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_destroy_t>)
			{
				down_cast<DerivedType>(this)->on_destroy();
				handled = true;
			}
			break;
		}
		case WM_MOVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_move_t>)
			{
				down_cast<DerivedType>(this)->on_move(value_convert<int32_t>(GET_X_LPARAM(lparam)), value_convert<int32_t>(GET_Y_LPARAM(lparam)));
				handled = true;
			}
			break;
		}
		case 0x0004:
		{
			break;
		}
		case WM_SIZE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_size_t>)
			{
				down_cast<DerivedType>(this)->on_size(value_convert<resize_type>(wparam), value_convert<int32_t>(GET_X_LPARAM(lparam)), value_convert<int32_t>(GET_Y_LPARAM(lparam)));
				handled = true;
			}
			break;
		}
		case WM_ACTIVATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_activate_t>)
			{
				down_cast<DerivedType>(this)->on_activate(value_convert<activate_type>(LOWORD(wparam)), value_convert<BOOL>(HIWORD(wparam)) == FALSE ? false : true, handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_SETFOCUS:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_setfocus_t>)
			{
				down_cast<DerivedType>(this)->on_setfocus(handle_cast<HWND>(wparam));
				handled = true;
			}
			break;
		}
		case WM_KILLFOCUS:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_killfocus_t>)
			{
				down_cast<DerivedType>(this)->on_killfocus(handle_cast<HWND>(wparam));
				handled = true;
			}
			break;
		}
		case 0x0009:
		{
			break;
		}
		case WM_ENABLE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_enable_t>)
			{
				down_cast<DerivedType>(this)->on_enable(value_convert<BOOL>(wparam) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case WM_SETREDRAW:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_setredraw_t>)
			{
				down_cast<DerivedType>(this)->on_setredraw(value_convert<BOOL>(wparam) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case WM_SETTEXT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_settext_t>)
			{
				static constexpr bool convertable_ret = convertable_return_v<DerivedType, wmt::template on_settext_t, bool>;

				//This static_assert is deliberately unconditional.
				//The behaviour of WM_SETTEXT is compromised if you are unable to return a value.
				static_assert(convertable_ret, "on_settext must have a return that is convertable to bool.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_settext(pointer_from_param<wmt::template msg_char_type>(lparam))) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_GETTEXT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gettext_t>)
			{
				constexpr bool convertable_ret{ convertable_return_v<DerivedType, wmt::template on_gettext_t, uintptr_t> };

				//This static_assert is deliberately unconditional.
				//The behaviour of WM_GETTEXT is compromised if we cannot return a value.
				static_assert(convertable_ret, "on_gettext must have a return that is convertable to uintptr_t.");
				//One of the difficulties of WM_GETTEXT is that the buffer size is passed in through WPARAM, and the characters copied
				//is passed out through LRESULT. This means that the types have a sign mismatch.
				//What's more, there is no indicator as to the maximum size of the string beyond the rich edit control value.
				//This results in the parameters both being assumed to be unsigned and the size of the sizes will change based on whether
				//this is compiled for 32 or 64 bit. The intptr_t and uintptr_t types have been defined to help with this.
				auto result{ value_convert<uintptr_t>(down_cast<DerivedType>(this)->on_gettext(value_convert<uintptr_t>(wparam), pointer_from_param<wmt::template msg_char_type>(lparam))) };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_GETTEXTLENGTH:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gettextlength_t>)
			{
				constexpr bool convertable_ret{ convertable_return_v<DerivedType, wmt::template on_gettextlength_t, uintptr_t> };
				//This static_assert is deliberately unconditional.
				//The behaviour of WM_GETTEXT is compromised if we cannot return a value.
				static_assert(convertable_ret, "on_gettextlength must have a return that is convertable to uintptr_t.");
				auto result{ value_convert<uintptr_t>(down_cast<DerivedType>(this)->on_gettextlength()) };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_PAINT:
		{
			constexpr const bool simple_paint{ detect_v<DerivedType, wmt::template simple_on_paint_t> };
			constexpr const bool default_paint{ detect_v<DerivedType, wmt::template default_on_paint_t> };

			//Detect both overloads.
			static_assert(!(simple_paint && default_paint), "Both paint functions detected, only using on_paint().");
			//If both exist, only use the default version.
			if constexpr (simple_paint && !default_paint)
			{
				PAINTSTRUCT ps{};
				BeginPaint(get_handle(), &ps);
				down_cast<DerivedType>(this)->on_paint(ps);
				EndPaint(get_handle(), &ps);
				handled = true;
			}
			if constexpr (default_paint)
			{
				down_cast<DerivedType>(this)->on_paint();
				handled = true;
			}
			break;
		}
		case WM_CLOSE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_close_t>)
			{
				down_cast<DerivedType>(this)->on_close();
				handled = true;
			}
			break;
		}
		case WM_QUERYENDSESSION:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_queryendsession_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_queryendsession_t, bool> };
				static_assert(convertable_bool, "on_queryendsession with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_queryendsession(value_convert<endsession_reason>(lparam))) == false ? FALSE : TRUE };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_QUIT:
		{
			break;
		}
		case WM_QUERYOPEN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_queryopen_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_queryopen_t, bool> };
				static_assert(convertable_bool, "on_queryopen with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_queryopen()) == false ? FALSE : TRUE };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_ERASEBKGND:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_erasebkgnd_t>)
			{
				constexpr const bool return_bool{ same_return_v<DerivedType, wmt::template on_erasebkgnd_t, bool> };
				constexpr const bool return_cbool{ convertable_return_v<DerivedType, wmt::template on_erasebkgnd_t, bool> };

				if constexpr (return_bool || return_cbool)
				{
					LRESULT result{ value_convert<bool>(down_cast<DerivedType>(this)->on_erasebkgnd(handle_cast<HDC>(wparam))) == false ? FALSE : TRUE };
					proc_result = result;
				}
				else
				{
					down_cast<DerivedType>(this)->on_erasebkgnd(handle_cast<HDC>(wparam));
					//Assume that we wouldn't be doing this if we were not going to erase the background.
					proc_result = TRUE;
				}
				handled = true;
			}
			break;
		}
		case WM_SYSCOLORCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syscolorchange_t>)
			{
				down_cast<DerivedType>(this)->on_syscolorchange();
				handled = true;
			}
			break;
		}
		case WM_ENDSESSION:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_endsession_t>)
			{
				down_cast<DerivedType>(this)->on_endsession(value_convert<BOOL>(wparam) == FALSE ? false : true, value_convert<endsession_reason>(lparam));
				handled = true;
			}
			break;
		}
		case 0x0017:
		{
			break;
		}
		case WM_SHOWWINDOW:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_showwindow_t>)
			{
				down_cast<DerivedType>(this)->on_showwindow(value_convert<bool>(wparam), value_convert<showwindow_reason>(lparam));
				handled = true;
			}
			break;
		}
		case 0x0019:
		{
			break;
		}
		case WM_SETTINGCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_settingchange_t>)
			{
				down_cast<DerivedType>(this)->on_settingchange(value_convert<uint32_t>(wparam), pointer_from_param<typename my_traits_t::char_t>(lparam));
				handled = true;
			}
			break;
		}
		case WM_DEVMODECHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_devmodechange_t>)
			{
				down_cast<DerivedType>(this)->on_devmodechange(pointer_from_param<typename my_traits_t::char_t>(lparam));
				handled = true;
			}
			break;
		}
		case WM_ACTIVATEAPP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_activateapp_t>)
			{
				down_cast<DerivedType>(this)->on_activateapp(value_convert<BOOL>(wparam) == FALSE ? false : true, value_convert<uint32_t>(lparam));
				handled = true;
			}
			break;
		}
		case WM_FONTCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_fontchange_t>)
			{
				down_cast<DerivedType>(this)->on_fontchange();
				handled = true;
			}
			break;
		}
		case WM_TIMECHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_timechange_t>)
			{
				down_cast<DerivedType>(this)->on_timechange();
				handled = true;
			}
			break;
		}
		case WM_CANCELMODE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_cancelmode_t>)
			{
				down_cast<DerivedType>(this)->on_cancelmode();
				handled = true;
			}
			break;
		}
		case WM_SETCURSOR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_setcursor_t>)
			{
				constexpr const bool return_bool{ same_return_v<DerivedType, wmt::template on_setcursor_t, bool> };
				constexpr const bool return_cbool{ convertable_return_v<DerivedType, wmt::template on_setcursor_t, bool> };

				if constexpr (return_bool || return_cbool)
				{
					LRESULT result{ down_cast<DerivedType>(this)->on_setcursor(handle_cast<HWND>(wparam), value_convert<hittest_position>(LOWORD(lparam)), value_convert<uint32_t>(HIWORD(lparam))) == false ? FALSE : TRUE };
					proc_result = result;
				}
				else
				{
					down_cast<DerivedType>(this)->on_setcursor(handle_cast<HWND>(wparam), value_convert<hittest_position>(LOWORD(lparam)), value_convert<uint32_t>(HIWORD(lparam)));
					//Assume that further processing should happen.
					proc_result = FALSE;
				}

				handled = true;
			}
			break;
		}
		case WM_MOUSEACTIVATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mouseactivate_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_mouseactivate_t, mouse_activate_type> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_mouseactivate_t> };
				static_assert(convertable_to_return || integral_return, "on_mouseactivate found that returns a type that isn't convertable to mouse_activate_type.");
				auto result{ value_convert<mouse_activate_type>(down_cast<DerivedType>(this)->on_mouseactivate(handle_cast<HWND>(wparam), value_convert<hittest_position>(LOWORD(lparam)), value_convert<uint32_t>(HIWORD(lparam)))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CHILDACTIVATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_childactivate_t>)
			{
				down_cast<DerivedType>(this)->on_childactivate();
				handled = true;
			}
			break;
		}
		case WM_QUEUESYNC:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_queuesync_t>)
			{
				down_cast<DerivedType>(this)->on_queuesync();
				handled = true;
			}
			break;
		}
		case WM_GETMINMAXINFO:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_getminmaxinfo_t>)
			{
				down_cast<DerivedType>(this)->on_getminmaxinfo(reference_from_param<MINMAXINFO>(lparam));
				handled = true;
			}
			break;
		}
		//WM_PAINTICON and WM_ICONERASEBKGND are not supported for
		//newer versions of Windows. Windows 3.x are the last
		//supported version of Windows.
		case 0x0025:
		case WM_PAINTICON:
		case WM_ICONERASEBKGND:
		{
			break;
		}
		case WM_NEXTDLGCTL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nextdlgctl_t>)
			{
				down_cast<DerivedType>(this)->on_nextdlgctl(reference_from_param<next_dlg_ctl_params>(wparam), value_convert<BOOL>(lparam) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		//WM_SPOOLDERSTATUS is not supported after Windows XP.
		case 0x0029:
		case WM_SPOOLERSTATUS:
		{
			break;
		}
		case WM_DRAWITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_drawitem_t>)
			{
				down_cast<DerivedType>(this)->on_drawitem(value_convert<uint32_t>(wparam), reference_from_param<DRAWITEMSTRUCT>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_MEASUREITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_measureitem_t>)
			{
				down_cast<DerivedType>(this)->on_measureitem(value_convert<uint32_t>(wparam), reference_from_param<MEASUREITEMSTRUCT>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_DELETEITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_deleteitem_t>)
			{
				down_cast<DerivedType>(this)->on_deleteitem(value_convert<uint32_t>(wparam), reference_from_param<MEASUREITEMSTRUCT>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_VKEYTOITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_vkeytoitem_t>)
			{
				constexpr const bool convertable_int{ convertable_return_v<DerivedType, wmt::template on_vkeytoitem_t, int32_t> };
				static_assert(convertable_int, "on_vkeytoitem must have a return that is convertable to int32_t.");
				auto result{ down_cast<DerivedType>(this)->on_vkeytoitem(LOWORD(wparam), HIWORD(lparam), handle_cast<HWND>(lparam)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CHARTOITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_chartoitem_t>)
			{
				constexpr const bool convertable_int{ convertable_return_v<DerivedType, wmt::template on_vkeytoitem_t, int32_t> };
				static_assert(convertable_int, "on_vkeytoitem must have a return that is convertable to int32_t.");
				auto result{ down_cast<DerivedType>(this)->on_chartoitem(value_convert<typename my_traits_t::char_t>(LOWORD(wparam)), HIWORD(lparam), handle_cast<HWND>(lparam)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_SETFONT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_setfont_t>)
			{
				down_cast<DerivedType>(this)->on_setfont(handle_cast<HFONT>(wparam), value_convert<BOOL>(LOWORD(lparam)) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case WM_GETFONT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_getfont_t>)
			{
				constexpr const bool return_hfont{ same_return_v<DerivedType, wmt::template on_getfont_t, HFONT> };
				static_assert(return_hfont, "on_getfont must have a return of HFONT.");
				auto result{ down_cast<DerivedType>(this)->on_getfont() };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_SETHOTKEY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_sethotkey_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_sethotkey_t, set_hot_key_result> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_sethotkey_t> };
				static_assert(convertable_to_return || integral_return, "on_sethotkey found that returns a type that isn't set_hot_key_result or is convertable to set_hot_key_result.");

				hot_key_value hkv{};
				hkv.vk = value_convert<uint8_t>(LOWORD(wparam));
				hkv.modifier = value_convert<uint8_t>(HIWORD(wparam));

				auto result{ value_convert<set_hot_key_result>(down_cast<DerivedType>(this)->on_sethotkey(hkv)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_GETHOTKEY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gethotkey_t>)
			{
				constexpr const bool return_hot_key_value{ same_return_v<DerivedType, wmt::template on_gethotkey_t, hot_key_value> };
				static_assert(return_hot_key_value, "on_gethotkey found that returns a type that isn't hot_key_value");
				auto result{ down_cast<DerivedType>(this)->on_gethotkey() };
				uint16_t ret_val{ value_convert<uint16_t>(result.vk) | (value_convert<uint16_t>(result.modifier) << 8) };
				proc_result = ret_val;
				handled = true;
			}
			break;
		}
		//WM_QUERYDRAGICON is very rare.
		//These days, it is only possible to get it if Explorer isn't running.
		case 0x0034:
		case 0x0035:
		case 0x0036:
		case WM_QUERYDRAGICON:
		case 0x0038:
		{
			break;
		}
		case WM_COMPAREITEM:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_compareitem_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_compareitem_t, compare_item_result> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_compareitem_t> };
				static_assert(convertable_to_return || integral_return, "on_compareitem found that returns a type that isn't convertable to compare_item_result.");
				auto result{ value_convert<compare_item_result>(down_cast<DerivedType>(this)->on_compareitem(value_convert<uint32_t>(wparam), reference_from_param<COMPAREITEMSTRUCT>(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case 0x003a:
		case 0x003b:
		case 0x003c:
		{
			break;
		}
		case WM_GETOBJECT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_getobject_t>)
			{
				constexpr const bool convertable_return{ convertable_return_v<DerivedType, wmt::template on_getobject_t, LRESULT> };
				static_assert(convertable_return, "on_getobject found that returns a type that isn't convertable to LRESULT.");
				auto result{ down_cast<DerivedType>(this)->on_getobject(value_convert<uint32_t>(wparam), value_convert<uint32_t>(lparam)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		//WM_COMPACTING is not used on modern versions of Windows.
		//It was only used for segmented memory address spaces.
		//WM_COMMNOTIFY is an interesting message where it has an
		//id, but wasn't really used by Windows.
		//These messages will never be handled.
		case 0x003e:
		case 0x003f:
		case 0x0040:
		case WM_COMPACTING:
		case 0x0042:
		case 0x0043:
		case WM_COMMNOTIFY:
		case 0x0045:
		{
			break;
		}
		case WM_WINDOWPOSCHANGING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_windowposchanging_t>)
			{
				down_cast<DerivedType>(this)->on_windowposchanging(reference_from_param<WINDOWPOS>(lparam));
				handled = true;
			}
			break;
		}
		case WM_WINDOWPOSCHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_windowposchanged_t>)
			{
				down_cast<DerivedType>(this)->on_windowposchanged(reference_from_param<WINDOWPOS>(lparam));
				handled = true;
			}
			break;
		}
		//WM_POWER was deprecated in favour of WM_POWERNOTIFY.
		case WM_POWER:
		case 0x0049:
		{
			break;
		}
		case WM_COPYDATA:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_copydata_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_copydata_t, bool> };
				static_assert(convertable_bool, "on_copydata with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_copydata(handle_cast<HWND>(wparam), reference_from_param<COPYDATASTRUCT>(lparam))) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		//WM_CANCELJOURNAL is part of the journaling hooks api.
		//This was deprecated.
		case WM_CANCELJOURNAL:
		case 0x004c:
		case 0x004d:
		{
			break;
		}
		case WM_NOTIFY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_notify_t>)
			{
				constexpr const bool return_complex{ convertable_return_v<DerivedType, wmt::template on_notify_t, std::pair<LRESULT, bool>> };
				static_assert(return_complex, "on_notify with a return that is not std::pair<LRESULT, bool> found.");
				auto &&[notify_result, notify_handled] { down_cast<DerivedType>(this)->on_notify(value_convert<uint32_t>(wparam), reference_from_param<NMHDR>(lparam))};
				proc_result = notify_result;
				handled = notify_handled;
			}
			else
			{
				if constexpr (detect_v<DerivedType, wmt::template get_commandhandler_t>)
				{
					constexpr const bool return_command_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
					constexpr const bool return_ccommand_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
					static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list");
					auto &&[notify_result, notify_handled] {on_notify_default(reference_from_param<NMHDR>(lparam))};
					proc_result = notify_result;
					handled = notify_handled;
				}
			}
			break;
		}
		case 0x004f:
		{
			break;
		}
		case WM_INPUTLANGCHANGEREQUEST:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_inputlangchangerequest_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_inputlanguagechangerequest_t, bool> };
				static_assert(convertable_to_return, "on_inputlanguagechangerequest with a return that is not convertable to bool found.");

				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_inputlangchangerequest(value_convert<input_language_change_flags>(wparam), value_convert<uint32_t>(lparam))) };
				//This must call DefWindowProc to handle the request.
				//Setting handled to false will call DefWindowProc automatically.
				handled = !result;
			}
			break;
		}
		case WM_INPUTLANGCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_inputlangchange_t>)
			{
				down_cast<DerivedType>(this)->on_inputlangchange(value_convert<input_language_character_set>(wparam), LOWORD(HandleToUlong(handle_cast<HKL>(lparam))), handle_cast<HKL>(lparam));
				proc_result = TRUE; //The documentation states to return non-zero if the message is handled
				handled = true;
			}
			break;
		}
		case WM_TCARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_tcard_t>)
			{
				down_cast<DerivedType>(this)->on_tcard(value_convert<uint32_t>(wparam), value_convert<uint32_t>(lparam));
				handled = true;
			}
			break;
		}
		case WM_HELP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_help_t>)
			{
				down_cast<DerivedType>(this)->on_help(reference_from_param<HELPINFO>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		//WM_USERCHANGED is not supported.
		case WM_USERCHANGED:
		{
			break;
		}
		case WM_NOTIFYFORMAT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_notifyformat_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_notifyformat_t, notify_format_result> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_notifyformat_t> };

				static_assert(convertable_to_return || integral_return, "on_notifyformat found with a return that isn't convertable to notify_format_result.");
				auto result{ value_convert<notify_format_result>(down_cast<DerivedType>(this)->on_notifyformat(handle_cast<HWND>(wparam), value_convert<notify_format_type>(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case 0x0056:
		case 0x0057:
		case 0x0058:
		case 0x0059:
		case 0x005a:
		case 0x005b:
		case 0x005c:
		case 0x005d:
		case 0x005e:
		case 0x005f:
		case 0x0060:
		case 0x0061:
		case 0x0062:
		case 0x0063:
		case 0x0064:
		case 0x0065:
		case 0x0066:
		case 0x0067:
		case 0x0068:
		case 0x0069:
		case 0x006a:
		case 0x006b:
		case 0x006c:
		case 0x006d:
		case 0x006e:
		case 0x006f:
		case 0x0070:
		case 0x0071:
		case 0x0072:
		case 0x0073:
		case 0x0074:
		case 0x0075:
		case 0x0076:
		case 0x0077:
		case 0x0078:
		case 0x0079:
		case 0x007a:
		{
			break;
		}
		case WM_CONTEXTMENU:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_contextmenu_t>)
			{
				down_cast<DerivedType>(this)->on_contextmenu(handle_cast<HWND>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_STYLECHANGING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_stylechanging_t>)
			{
				down_cast<DerivedType>(this)->on_stylechanging(value_convert<style_changing_type>(wparam), reference_from_param<STYLESTRUCT>(lparam));
				handled = true;
			}
			break;
		}
		case WM_STYLECHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_stylechanged_t>)
			{
				down_cast<DerivedType>(this)->on_stylechanged(value_convert<style_changing_type>(wparam), reference_from_param<STYLESTRUCT>(lparam));
				handled = true;
			}
			break;
		}
		case WM_DISPLAYCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_displaychange_t>)
			{
				down_cast<DerivedType>(this)->on_displaychange(value_convert<uint32_t>(wparam), LOWORD(lparam), HIWORD(lparam));
				handled = true;
			}
			break;
		}
		case WM_GETICON:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_geticon_t>)
			{
				constexpr const bool return_hicon{ same_return_v<DerivedType, wmt::template on_geticon_t, HICON> };
				static_assert(return_hicon, "on_geticon with a return that is not HICON found.");
				auto result{ down_cast<DerivedType>(this)->on_geticon(value_convert<icon_type>(wparam), value_convert<uint32_t>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_SETICON:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_seticon_t>)
			{
				constexpr const bool return_hicon{ same_return_v<DerivedType, wmt::template on_seticon_t, HICON> };
				static_assert(return_hicon, "on_seticon with a return that is not HICON found.");
				auto result{ down_cast<DerivedType>(this)->on_seticon(value_convert<icon_type>(wparam), handle_cast<HICON>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_NCCREATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nccreate_t>)
			{
				constexpr const bool return_bool{ same_return_v<DerivedType, wmt::template on_nccreate_t, bool> };
				constexpr const bool return_cbool{ convertable_return_v<DerivedType, wmt::template on_nccreate_t, bool> };

				if constexpr (return_bool || return_cbool)
				{
					LRESULT result{ down_cast<DerivedType>(this)->on_nccreate(reference_from_param<typename my_traits_t::create_struct_t>(lparam)) == false ? FALSE : TRUE };
					proc_result = result;
				}
				else
				{
					down_cast<DerivedType>(this)->on_nccreate(reference_from_param<typename my_traits_t::create_struct_t>(lparam));
					proc_result = TRUE;
				}

				handled = true;
			}
			break;
		}
		case WM_NCDESTROY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncdestroy_t>)
			{
				down_cast<DerivedType>(this)->on_ncdestroy();
				handled = true;
			}
			break;
		}
		case WM_NCCALCSIZE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nccalcsize_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_nccalcsize_t, nccalcsize_return> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_nccalcsize_t> };
				static_assert(convertable_to_return || integral_return, "on_nccalcsize found that returns a type that isn't convertable to nccalcsize_return.");
				BOOL p = value_convert<BOOL>(wparam);
				nccalcsize_params ncp{ (p == FALSE ? nccalcsize_params(reference_from_param<RECT>(lparam)) : nccalcsize_params(reference_from_param<NCCALCSIZE_PARAMS>(lparam))) };
				auto result{ value_convert<nccalcsize_return>(down_cast<DerivedType>(this)->on_nccalcsize(p == FALSE ? false : true, ncp)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_NCHITTEST:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nchittest_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_nchittest_t, hittest_position> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_ncchittest_t> };
				static_assert(convertable_to_return || integral_return, "on_nccalcsize found that returns a type that isn't convertable to hittest_position.");
				auto result{ value_convert<hittest_position>(down_cast<DerivedType>(this)->on_nchittest(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_NCPAINT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncpaint_t>)
			{
				down_cast<DerivedType>(this)->on_ncpaint(handle_cast<HRGN>(wparam));
				handled = true;
			}
			break;
		}
		case WM_NCACTIVATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncactivate_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_ncactivate_t, bool> };
				static_assert(convertable_bool, "on_ncactivate found that returns a type that isn't convertable to bool.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_ncactivate(value_convert<BOOL>(wparam) == FALSE ? false : true, handle_cast<HRGN>(lparam))) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_GETDLGCODE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_getdlgcode_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_getdlgcode_t, get_dlg_code_return> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_getdlgcode_t> };
				static_assert(convertable_to_return || integral_return, "on_getdlgcode found that returns a type that isn't convertable to get_dlg_code_return.");
				std::optional<std::reference_wrapper<MSG>> m;
				if (lparam != 0)
				{
					m.emplace(reference_from_param<MSG>(lparam));
				}

				auto result{ value_convert<get_dlg_code_return>(down_cast<DerivedType>(this)->on_getdlgcode(value_convert<virtual_key>(wparam), m)) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_SYNCPAINT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syncpaint_t>)
			{
				down_cast<DerivedType>(this)->on_syncpaint();
				handled = true;
			}
			break;
		}
		case 0x0089:
		case 0x008a:
		case 0x008b:
		case 0x008c:
		case 0x008d:
		case 0x008e:
		case 0x008f:
		case 0x0090:
		case 0x0091:
		case 0x0092:
		case 0x0093:
		case 0x0094:
		case 0x0095:
		case 0x0096:
		case 0x0097:
		case 0x0098:
		case 0x0099:
		case 0x009a:
		case 0x009b:
		case 0x009c:
		case 0x009d:
		case 0x009e:
		case 0x009f:
		{
			break;
		}
		case WM_NCMOUSEMOVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmousemove_t>)
			{
				down_cast<DerivedType>(this)->on_ncmousemove(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCLBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nclbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_nclbuttondown(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCLBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nclbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_nclbuttonup(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCLBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_nclbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_nclbuttondblclk(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCRBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncrbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_ncrbuttondown(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCRBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncrbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_ncrbuttonup(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCRBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncrbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_ncrbuttondblclk(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCMBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_ncmbuttondown(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCMBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_ncmbuttonup(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCMBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_ncmbuttondblclk(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case 0x00aa:
		{
			break;
		}
		case WM_NCXBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncxbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_ncxbuttondown(value_convert<hittest_position>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_NCXBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncxbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_ncxbuttonup(value_convert<hittest_position>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_NCXBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncxbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_ncxbuttondblclk(value_convert<hittest_position>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case 0x00ae:
		case 0x00af:
		case 0x00b0:
		case 0x00b1:
		case 0x00b2:
		case 0x00b3:
		case 0x00b4:
		case 0x00b5:
		case 0x00b6:
		case 0x00b7:
		case 0x00b8:
		case 0x00b9:
		case 0x00ba:
		case 0x00bb:
		case 0x00bc:
		case 0x00bd:
		case 0x00be:
		case 0x00bf:
		case 0x00c0:
		case 0x00c1:
		case 0x00c2:
		case 0x00c3:
		case 0x00c4:
		case 0x00c5:
		case 0x00c6:
		case 0x00c7:
		case 0x00c8:
		case 0x00c9:
		case 0x00ca:
		case 0x00cb:
		case 0x00cc:
		case 0x00cd:
		case 0x00ce:
		case 0x00cf:
		case 0x00d0:
		case 0x00d1:
		case 0x00d2:
		case 0x00d3:
		case 0x00d4:
		case 0x00d5:
		case 0x00d6:
		case 0x00d7:
		case 0x00d8:
		case 0x00d9:
		case 0x00da:
		case 0x00db:
		case 0x00dc:
		case 0x00dd:
		case 0x00de:
		case 0x00df:
		case 0x00e0:
		case 0x00e1:
		case 0x00e2:
		case 0x00e3:
		case 0x00e4:
		case 0x00e5:
		case 0x00e6:
		case 0x00e7:
		case 0x00e8:
		case 0x00e9:
		case 0x00ea:
		case 0x00eb:
		case 0x00ec:
		case 0x00ed:
		case 0x00ee:
		case 0x00ef:
		case 0x00f0:
		case 0x00f1:
		case 0x00f2:
		case 0x00f3:
		case 0x00f4:
		case 0x00f5:
		case 0x00f6:
		case 0x00f7:
		case 0x00f8:
		case 0x00f9:
		case 0x00fa:
		case 0x00fb:
		case 0x00fc:
		case 0x00fd:
		{
			break;
		}
		case WM_INPUT_DEVICE_CHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_input_device_change_t>)
			{
				down_cast<DerivedType>(this)->on_input_device_change(value_convert<input_dev_change_type>(wparam), handle_cast<HANDLE>(lparam));
				handled = true;
			}
			break;
		}
		case WM_INPUT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_input_t>)
			{
				down_cast<DerivedType>(this)->on_input(value_convert<input_type>(GET_RAWINPUT_CODE_WPARAM(wparam)), handle_cast<HRAWINPUT>(lparam));
				//If the raw input code is RIM_INPUT, it is documented that DefWindowProc must be called.
				//In this case, we leave the message as unhandled and let it drop through to DefWindowProc.
				handled = GET_RAWINPUT_CODE_WPARAM(wparam) == RIM_INPUT ? false : true;
			}
			break;
		}
		case WM_KEYDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_keydown_t>)
			{
				auto &kd{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_keydown(value_convert<virtual_key>(wparam), kd);
				handled = true;
			}
			break;
		}
		case WM_KEYUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_keyup_t>)
			{
				auto &kd{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_keyup(value_convert<virtual_key>(wparam), kd);
				handled = true;
			}
			break;
		}
		case WM_CHAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_char_t>)
			{
				auto &key_data{ reference_from_param_address<keystroke_data>(&lparam) };
				//wparam will be either char or wchar_t depending on whether the window was registered with
				//RegisterClass(Ex)A or RegisterClass(Ex)W. The window class automatically uses the appropriate
				//one based upon the UnicodeBase template parameter. This means that we can blindly cast based
				//upon our traits.
				down_cast<DerivedType>(this)->on_char(value_convert<typename my_traits_t::char_t>(wparam), key_data);
				handled = true;
			}
			break;
		}
		case WM_DEADCHAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_deadchar_t>)
			{
				auto &key_data{ reference_from_param_address<keystroke_data>(&lparam) };
				//Like WM_CHAR, the cast is based upon how the window was registered.
				down_cast<DerivedType>(this)->on_deadchar(value_convert<typename my_traits_t::char_t>(wparam), key_data);
				handled = true;
			}
			break;
		}
		case WM_SYSKEYDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syskeydown_t>)
			{
				auto &kd{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_syskeydown(value_convert<virtual_key>(wparam), kd);
				handled = true;
			}
			break;
		}
		case WM_SYSKEYUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syskeyup_t>)
			{
				auto &kd{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_syskeyup(value_convert<virtual_key>(wparam), kd);
				handled = true;
			}
			break;
		}
		case WM_SYSCHAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syschar_t>)
			{
				auto &key_data{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_syschar(value_convert<typename my_traits_t::char_t>(wparam), key_data);
				handled = true;
			}
			break;
		}
		case WM_SYSDEADCHAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_sysdeadchar_t>)
			{
				auto &key_data{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_sysdeadchar(value_convert<typename my_traits_t::char_t>(wparam), key_data);
				handled = true;
			}
			break;
		}
		case 0x0108:
		{
			break;
		}
		case WM_UNICHAR:
		{
			//Even though it has fallen out of favour, provide a handler for this message.
			//Unicode windows should just let this get handled by DefWindowProc.
			if constexpr (detect_v<DerivedType, wmt::template on_unichar_t>)
			{
				auto &kd{ reference_from_param_address<keystroke_data>(&lparam) };
				down_cast<DerivedType>(this)->on_unichar(value_convert<uint32_t>(wparam), kd);
				//The documentation indicates that you should return true to indicate that the message was handled.
				//Assume here that by providing a handler, the message should be handled.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case 0x010a:
		case 0x010b:
		case 0x010c:
		{
			break;
		}
		case WM_IME_STARTCOMPOSITION:
		case WM_IME_ENDCOMPOSITION:
		case WM_IME_COMPOSITION:
		case WM_INITDIALOG:
		{
			break;
		}
		case WM_COMMAND:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_command_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_command_t, bool> };
				static_assert(convertable_bool, "on_command with a return that is not convertable to bool found.");
				handled = down_cast<DerivedType>(this)->on_command(LOWORD(wparam), HIWORD(wparam), handle_cast<HWND>(lparam));
			}
			else
			{
				if constexpr (detect_v<DerivedType, wmt::template get_commandhandler_t>)
				{
					constexpr const bool return_command_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
					constexpr const bool return_ccommand_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
					static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list.");
					handled = on_command_default(LOWORD(wparam), HIWORD(wparam), handle_cast<HWND>(lparam));
				}
			}
			break;
		}
		case WM_SYSCOMMAND:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_syscommand_t> || detect_v<DerivedType, wmt::template get_commandhandler_t>)
			{
				syscommand_info info{};
				info.request = value_convert<syscommand_request>(wparam & 0xFFF0);
				info.is_secure = value_convert<bool>(wparam & SCF_ISSECURE);
				if constexpr (detect_v<DerivedType, wmt::template on_syscommand_t>)
				{
					handled = down_cast<DerivedType>(this)->on_syscommand(info, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				}
				else
				{
					if constexpr (detect_v<DerivedType, wmt::template get_commandhandler_t>)
					{
						constexpr const bool return_command_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
						constexpr const bool return_ccommand_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
						static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list.");
						handled = on_syscommand_default(info, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					}
				}
			}
			break;
		}
		case WM_TIMER:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_timer_t>)
			{
				down_cast<DerivedType>(this)->on_timer(value_convert<uintptr_t>(wparam), pointer_from_param<TIMERPROC>(lparam));
				handled = true;
			}
			break;
		}
		case WM_HSCROLL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_hscroll_t>)
			{
				down_cast<DerivedType>(this)->on_hscroll(value_convert<hscrollbar_request>(LOWORD(wparam)), HIWORD(wparam), handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_VSCROLL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_vscroll_t>)
			{
				down_cast<DerivedType>(this)->on_vscroll(value_convert<vscrollbar_request>(LOWORD(wparam)), HIWORD(wparam), handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_INITMENU:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_initmenu_t>)
			{
				down_cast<DerivedType>(this)->on_initmenu(handle_cast<HMENU>(wparam));
				handled = true;
			}
			break;
		}
		case WM_INITMENUPOPUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_initmenupopup_t>)
			{
				down_cast<DerivedType>(this)->on_initmenupopup(handle_cast<HMENU>(wparam), LOWORD(lparam), value_convert<BOOL>(HIWORD(lparam)) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case 0x0118:
		{
			break;
		}
		case WM_GESTURE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gesture_t>)
			{
				down_cast<DerivedType>(this)->on_gesture(value_convert<uint64_t>(wparam), handle_cast<HGESTUREINFO>(lparam));
				handled = true;
			}
			break;
		}
		case WM_GESTURENOTIFY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gesturenotify_t>)
			{
				down_cast<DerivedType>(this)->on_gesturenotify(reference_from_param<GESTURENOTIFYSTRUCT>(lparam));
				//Never mark the message as handled.
				//This is documented to need a return from DefWindowProc.
			}
			break;
		}
		case 0x011b:
		case 0x011c:
		case 0x011d:
		case 0x011e:
		{
			break;
		}
		case WM_MENUSELECT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menuselect_t>)
			{
				down_cast<DerivedType>(this)->on_menuselect(LOWORD(wparam), value_convert<menuselect_flags>(HIWORD(wparam)), handle_cast<HMENU>(lparam));
				handled = true;
			}
			break;
		}
		case WM_MENUCHAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menuchar_t>)
			{
				constexpr const bool return_menuchar_return{ same_return_v<DerivedType, wmt::template on_menuchar_t, menuchar_return> };
				static_assert(return_menuchar_return, "on_menuchar found with a return that is not menuchar_return.");
				auto result{ down_cast<DerivedType>(this)->on_menuchar(value_convert<wmt::template msg_char_type>(LOWORD(wparam)), value_convert<menuchar_flags>(HIWORD(wparam)), handle_cast<HMENU>(lparam)) };
				auto cmb_result{ details::make_dword(result.index, value_convert<uint16_t>(result.result)) };
				proc_result = value_convert<LRESULT>(cmb_result);
				handled = true;
			}
			break;
		}
		case WM_ENTERIDLE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_enteridle_t>)
			{
				enteridle_type ei_param{ value_convert<enteridle_type>(wparam) };
				enteridle_param v = ei_param == enteridle_type::dialogbox ? handle_cast<HWND>(lparam) : handle_cast<HMENU>(lparam);
				down_cast<DerivedType>(this)->on_enteridle(value_convert<enteridle_type>(wparam), v);
				handled = true;
			}
			break;
		}
		case WM_MENURBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menurbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_menurbuttonup(value_convert<uint32_t>(wparam), handle_cast<HMENU>(lparam));
				handled = true;
			}
			break;
		}
		case WM_MENUDRAG:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menudrag_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_menudrag_t, menudrag_return> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_menudrag_t> };
				static_assert(convertable_to_return || integral_return, "on_menudrag found with a return that is not convertable to menudrag_return");
				auto result{ value_convert<menudrag_return>(down_cast<DerivedType>(this)->on_menudrag(value_convert<uint32_t>(wparam), handle_cast<HMENU>(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_MENUGETOBJECT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menugetobject_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_menugetobject_t, menugetobject_return> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_menugetobject_t> };
				static_assert(convertable_to_return || integral_return, "on_menugetobject found with a return that isn't menugetobject_return.");
				auto result{ value_convert<menugetobject_return>(down_cast<DerivedType>(this)->on_menugetobject(reference_from_param<MENUGETOBJECTINFO>(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_UNINITMENUPOPUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_uninitmenupopup_t>)
			{
				//The high order word of lparam is always set to MF_SYSMENU.
				down_cast<DerivedType>(this)->on_uninitmenupopup(handle_cast<HMENU>(wparam));
				handled = true;
			}
			break;
		}
		case WM_MENUCOMMAND:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_menucommand_t>)
			{
				down_cast<DerivedType>(this)->on_menucommand(value_convert<uint32_t>(wparam), handle_cast<HMENU>(lparam));
				handled = true;
			}
			break;
		}
		case WM_CHANGEUISTATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_changeuistate_t>)
			{
				down_cast<DerivedType>(this)->on_changeuistate(value_convert<uistate_action>(LOWORD(wparam)), value_convert<uistate_style>(HIWORD(wparam)));
				handled = true;
			}
			break;
		}
		case WM_UPDATEUISTATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_updateuistate_t>)
			{
				down_cast<DerivedType>(this)->on_updateuistate(value_convert<uistate_action>(LOWORD(wparam)), value_convert<uistate_style>(HIWORD(wparam)));
				handled = true;
			}
			break;
		}
		case WM_QUERYUISTATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_queryuistate_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_queryuistate_t, uistate_style> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_queryuistate_t> };
				static_assert(convertable_to_return || integral_return, "on_queryuistate foun with a return that is not convertable to uistate_style");
				auto result{ value_convert<uistate_style>(down_cast<DerivedType>(this)->on_queryuistate()) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case 0x012a:
		case 0x012b:
		case 0x012c:
		case 0x012d:
		case 0x012e:
		case 0x012f:
		case 0x0130:
		case 0x0131:
		{
			break;
		}
		case WM_CTLCOLORMSGBOX:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolormsgbox_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolormsgbox_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolormsgbox found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolormsgbox(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLOREDIT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcoloredit_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcoloredit_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcoloredit found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcoloredit(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLORLISTBOX:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolorlistbox_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolorlistbox_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolorlistbox found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolorlistbox(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLORBTN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolorbtn_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolorbtn_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolorbtn found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolorbtn(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLORDLG:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolordlg_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolordlg_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolordlg found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolordlg(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLORSCROLLBAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolorscrollbar_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolorscrollbar_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolorscrollbar found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolorscrollbar(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_CTLCOLORSTATIC:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ctlcolorstatic_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_ctlcolorstatic_t, HBRUSH> };
				static_assert(return_hbrush, "on_ctlcolorstatic found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_ctlcolorstatic(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam)) };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case 0x0139:
		case 0x013a:
		case 0x013b:
		case 0x013c:
		case 0x013d:
		case 0x013e:
		case 0x013f:
		case 0x0140:
		case 0x0141:
		case 0x0142:
		case 0x0143:
		case 0x0144:
		case 0x0145:
		case 0x0146:
		case 0x0147:
		case 0x0148:
		case 0x0149:
		case 0x014a:
		case 0x014b:
		case 0x014c:
		case 0x014d:
		case 0x014e:
		case 0x014f:
		case 0x0150:
		case 0x0151:
		case 0x0152:
		case 0x0153:
		case 0x0154:
		case 0x0155:
		case 0x0156:
		case 0x0157:
		case 0x0158:
		case 0x0159:
		case 0x015a:
		case 0x015b:
		case 0x015c:
		case 0x015d:
		case 0x015e:
		case 0x015f:
		case 0x0160:
		case 0x0161:
		case 0x0162:
		case 0x0163:
		case 0x0164:
		case 0x0165:
		case 0x0166:
		case 0x0167:
		case 0x0168:
		case 0x0169:
		case 0x016a:
		case 0x016b:
		case 0x016c:
		case 0x016d:
		case 0x016e:
		case 0x016f:
		case 0x0170:
		case 0x0171:
		case 0x0172:
		case 0x0173:
		case 0x0174:
		case 0x0175:
		case 0x0176:
		case 0x0177:
		case 0x0178:
		case 0x0179:
		case 0x017a:
		case 0x017b:
		case 0x017c:
		case 0x017d:
		case 0x017e:
		case 0x017f:
		case 0x0180:
		case 0x0181:
		case 0x0182:
		case 0x0183:
		case 0x0184:
		case 0x0185:
		case 0x0186:
		case 0x0187:
		case 0x0188:
		case 0x0189:
		case 0x018a:
		case 0x018b:
		case 0x018c:
		case 0x018d:
		case 0x018e:
		case 0x018f:
		case 0x0190:
		case 0x0191:
		case 0x0192:
		case 0x0193:
		case 0x0194:
		case 0x0195:
		case 0x0196:
		case 0x0197:
		case 0x0198:
		case 0x0199:
		case 0x019a:
		case 0x019b:
		case 0x019c:
		case 0x019d:
		case 0x019e:
		case 0x019f:
		case 0x01a0:
		case 0x01a1:
		case 0x01a2:
		case 0x01a3:
		case 0x01a4:
		case 0x01a5:
		case 0x01a6:
		case 0x01a7:
		case 0x01a8:
		case 0x01a9:
		case 0x01aa:
		case 0x01ab:
		case 0x01ac:
		case 0x01ad:
		case 0x01ae:
		case 0x01af:
		case 0x01b0:
		case 0x01b1:
		case 0x01b2:
		case 0x01b3:
		case 0x01b4:
		case 0x01b5:
		case 0x01b6:
		case 0x01b7:
		case 0x01b8:
		case 0x01b9:
		case 0x01ba:
		case 0x01bb:
		case 0x01bc:
		case 0x01bd:
		case 0x01be:
		case 0x01bf:
		case 0x01c0:
		case 0x01c1:
		case 0x01c2:
		case 0x01c3:
		case 0x01c4:
		case 0x01c5:
		case 0x01c6:
		case 0x01c7:
		case 0x01c8:
		case 0x01c9:
		case 0x01ca:
		case 0x01cb:
		case 0x01cc:
		case 0x01cd:
		case 0x01ce:
		case 0x01cf:
		case 0x01d0:
		case 0x01d1:
		case 0x01d2:
		case 0x01d3:
		case 0x01d4:
		case 0x01d5:
		case 0x01d6:
		case 0x01d7:
		case 0x01d8:
		case 0x01d9:
		case 0x01da:
		case 0x01db:
		case 0x01dc:
		case 0x01dd:
		case 0x01de:
		case 0x01df:
		case 0x01e0:
		{
			break;
		}
		case MN_GETHMENU:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gethmenu_t>)
			{
				constexpr const bool return_hbrush{ same_return_v<DerivedType, wmt::template on_gethmenu_t, HMENU> };
				static_assert(return_hbrush, "on_gethmenu found with a return that is not HBRUSH.");
				auto result{ down_cast<DerivedType>(this)->on_gethmenu() };
				proc_result = handle_to_return<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case 0x01e2:
		case 0x01e3:
		case 0x01e4:
		case 0x01e5:
		case 0x01e6:
		case 0x01e7:
		case 0x01e8:
		case 0x01e9:
		case 0x01ea:
		case 0x01eb:
		case 0x01ec:
		case 0x01ed:
		case 0x01ee:
		case 0x01ef:
		case 0x01f0:
		case 0x01f1:
		case 0x01f2:
		case 0x01f3:
		case 0x01f4:
		case 0x01f5:
		case 0x01f6:
		case 0x01f7:
		case 0x01f8:
		case 0x01f9:
		case 0x01fa:
		case 0x01fb:
		case 0x01fc:
		case 0x01fd:
		case 0x01fe:
		case 0x01ff:
		{
			break;
		}
		case WM_MOUSEMOVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mousemove_t>)
			{
				down_cast<DerivedType>(this)->on_mousemove(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_LBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_lbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_lbuttondown(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_LBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_lbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_lbuttonup(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_LBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_lbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_lbuttondblclk(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_RBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_rbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_rbuttondown(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_RBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_rbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_rbuttonup(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_RBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_rbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_rbuttondblclk(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_MBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_mbuttondown(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_MBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_mbuttonup(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_MBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_mbuttondblclk(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_MOUSEWHEEL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mousewheel_t>)
			{
				down_cast<DerivedType>(this)->on_mousewheel(value_convert<mouse_vkey>(LOWORD(wparam)), GET_WHEEL_DELTA_WPARAM(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_XBUTTONDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_xbuttondown_t>)
			{
				down_cast<DerivedType>(this)->on_xbuttondown(value_convert<mouse_vkey>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_XBUTTONUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_xbuttonup_t>)
			{
				down_cast<DerivedType>(this)->on_xbuttonup(value_convert<mouse_vkey>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_XBUTTONDBLCLK:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_xbuttondblclk_t>)
			{
				down_cast<DerivedType>(this)->on_xbuttondblclk(value_convert<mouse_vkey>(wparam), value_convert<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				//The xbutton handlers are documented to return true if the message is handled, this is to allows software
				//that simulates the xbuttons to know if it should do anything.
				//This is a relic of the past, but it should still be done.
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_MOUSEHWHEEL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mousehwheel_t>)
			{
				down_cast<DerivedType>(this)->on_mousehwheel(value_convert<mouse_vkey>(LOWORD(wparam)), GET_WHEEL_DELTA_WPARAM(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case 0x020f:
		{
			break;
		}
		case WM_PARENTNOTIFY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_parentnotify_t>)
			{
				uint16_t msg{ LOWORD(wparam) };
				POINT p{};
				notify_param1 np1{};
				notify_param2 np2{nullptr};
				switch (msg)
				{
				case WM_CREATE:
				case WM_DESTROY:
					np1.emplace<1>(HIWORD(wparam));
					np2.emplace<1>(handle_cast<HWND>(lparam));
					break;
				case WM_LBUTTONDOWN:
				case WM_MBUTTONDOWN:
				case WM_RBUTTONDOWN:
					p = { GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) };
					np2.emplace<0>(p);
					break;
				case WM_XBUTTONDOWN:
					p = { GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) };
					np1.emplace<0>(value_convert<xbutton_type>(HIWORD(wparam)));
					np2.emplace<0>(p);
					break;
				case WM_POINTERDOWN:
					p = { GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) };
					np1.emplace<2>(HIWORD(wparam));
					np2.emplace<0>(p);
					break;
				}
				down_cast<DerivedType>(this)->on_parentnotify(LOWORD(wparam), np1, np2);
				handled = true;
			}
			break;
		}
		case WM_ENTERMENULOOP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_entermenuloop_t>)
			{
				down_cast<DerivedType>(this)->on_entermenuloop(value_convert<bool>(wparam));
				handled = true;
			}
			break;
		}
		case WM_EXITMENULOOP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_exitmenuloop_t>)
			{
				down_cast<DerivedType>(this)->on_exitmenuloop(value_convert<bool>(wparam));
				handled = true;
			}
			break;
		}
		case WM_NEXTMENU:
		{
			break;
		}
		case WM_SIZING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_sizing_t>)
			{
				//Even though the documentation states that this must return TRUE if we handle the message,
				//the handler still returns void. It is an unconditional return TRUE, so the return of the
				//handler will never be used in any meaningful way.
				down_cast<DerivedType>(this)->on_sizing(value_convert<sizing_from>(wparam), reference_from_param<RECT>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_CAPTURECHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_capturechanged_t>)
			{
				down_cast<DerivedType>(this)->on_capturechanged(handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_MOVING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_moving_t>)
			{
				//Even though the documentation states that this must return TRUE if we handle the message,
				//the handler still returns void. It is an unconditional return TRUE, so the return of the
				//handler will never be used in any meaningful way.
				down_cast<DerivedType>(this)->on_moving(reference_from_param<RECT>(lparam));
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case 0x0217:
		{
			break;
		}
		case WM_POWERBROADCAST:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_powerbroadcast_t>)
			{
				std::optional<std::reference_wrapper<POWERBROADCAST_SETTING>> ps{};
				auto evt_type{ value_convert<power_event_type>(wparam) };
				if (evt_type == power_event_type::apm_powersettingchange)
				{
					ps.emplace(reference_from_param<POWERBROADCAST_SETTING>(lparam));
				}
				down_cast<DerivedType>(this)->on_powerbroadcast(value_convert<power_event_type>(wparam), ps);
				proc_result = TRUE;
				handled = true;
			}
			break;
		}
		case WM_DEVICECHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_devicechange_t>)
			{
				constexpr const bool return_bool{ same_return_v<DerivedType, wmt::template on_devicechange_t, bool> };
				constexpr const bool return_cbool{ convertable_return_v<DerivedType, wmt::template on_devicechange_t, bool> };

				auto change_type{ value_convert<devicechange_type>(wparam) };
				std::optional<devicechange_param> evt_data_ref{};
				switch (change_type)
				{
				case devicechange_type::devnodes_changed:
				case devicechange_type::querychangeconfig:
				case devicechange_type::configchanged:
				case devicechange_type::configchangecancelled:
					break;
				case devicechange_type::userdefined:
					evt_data_ref.emplace(reference_from_param<_DEV_BROADCAST_USERDEFINED>(lparam));
					break;
				default:
					evt_data_ref.emplace(reference_from_param<DEV_BROADCAST_HDR>(lparam));
					break;
				}

				if constexpr (return_bool || return_cbool)
				{
					auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_devicechange(change_type, evt_data_ref)) == false ? BROADCAST_QUERY_DENY : TRUE };
					proc_result = value_convert<LRESULT>(result);
				}
				else
				{
					down_cast<DerivedType>(this)->on_devicechange(change_type, evt_data_ref);
					proc_result = TRUE;
				}
				handled = true;
			}
			break;
		}
		case 0x021a:
		case 0x021b:
		case 0x021c:
		case 0x021d:
		case 0x021e:
		case 0x021f:
		case 0x0220:
		case 0x0221:
		case 0x0222:
		case 0x0223:
		case 0x0224:
		case 0x0225:
		case 0x0226:
		case 0x0227:
		case 0x0228:
		case 0x0229:
		case 0x022a:
		case 0x022b:
		case 0x022c:
		case 0x022d:
		case 0x022e:
		case 0x022f:
		case 0x0230:
		case 0x0231:
		case 0x0232:
		case 0x0233:
		case 0x0234:
		case 0x0235:
		case 0x0236:
		case 0x0237:
		case WM_POINTERDEVICECHANGE:
		case WM_POINTERDEVICEINRANGE:
		case WM_POINTERDEVICEOUTOFRANGE:
		case 0x023b:
		case 0x023c:
		case 0x023d:
		case 0x023e:
		case 0x023f:
		{
			break;
		}
		case WM_TOUCH:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_touch_t>)
			{
				down_cast<DerivedType>(this)->on_touch(value_convert<uint16_t>(LOWORD(wparam)), handle_cast<HTOUCHINPUT>(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCPOINTERUPDATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncpointerupdate_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_ncpointerupdate(pointerid, value_convert<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCPOINTERDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncpointerdown_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_ncpointerdown(pointerid, value_convert<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCPOINTERUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncpointerup_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_ncpointerup(pointerid, value_convert<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case 0x0244:
		{
			break;
		}
		case WM_POINTERUPDATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerupdate_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerupdate(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_POINTERDOWN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerdown_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerdown(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_POINTERUP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerup_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerup(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case 0x0248:
		{
			break;
		}
		case WM_POINTERENTER:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerenter_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerenter(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_POINTERLEAVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerleave_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerleave(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_X_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_POINTERACTIVATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointeractivate_t>)
			{
				constexpr const bool convertable_to_return{ convertable_return_v<DerivedType, wmt::template on_pointeractivate_t, pointer_activate_type> };
				constexpr const bool integral_return{ integral_return_v<DerivedType, wmt::template on_pointeractivate_t> };
				static_assert(convertable_to_return || integral_return, "on_pointeractivate with a return that is not convertable to pointer_activate_type found.");
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				auto result{ value_convert<pointer_activate_type>(down_cast<DerivedType>(this)->on_pointeractivate(pointerid, value_convert<hittest_position>(HIWORD(wparam)), ptr_flags, handle_cast<HWND>(lparam))) };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_POINTERCAPTURECHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointercapturechanged_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointercapturechanged(pointerid, ptr_flags, handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_TOUCHHITTESTING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_touchhittesting_t>)
			{
				constexpr const bool return_lresult{ same_return_v<DerivedType, wmt::template on_touchhittesting_t, LRESULT> };
				static_assert(return_lresult, "on_touchhittesting with a return that is not LRESULT found.");
				auto result{ down_cast<DerivedType>(this)->on_touchhittesting(reference_from_param<TOUCH_HIT_TESTING_INPUT>(lparam)) };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_POINTERWHEEL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerwheel_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerwheel(pointerid, GET_WHEEL_DELTA_WPARAM(wparam), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_POINTERHWHEEL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerhwheel_t>)
			{
				auto pointerid{ GET_POINTERID_WPARAM(wparam) };
				POINTER_INFO pi{};
				GetPointerInfo(pointerid, &pi);
				auto flags{ pi.pointerFlags };
				auto &ptr_flags{ reference_from_param<pointer_data>(&flags) };

				down_cast<DerivedType>(this)->on_pointerhwheel(pointerid, GET_WHEEL_DELTA_WPARAM(wparam), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case DM_POINTERHITTEST:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerhittest_t>)
			{
				down_cast<DerivedType>(this)->on_pointerhittest();
				handled = true;
			}
			break;
		}
		case WM_POINTERROUTEDTO:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerroutedto_t>)
			{
				down_cast<DerivedType>(this)->on_pointerroutedto();
				handled = true;
			}
			break;
		}
		case WM_POINTERROUTEDAWAY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerroutedaway_t>)
			{
				down_cast<DerivedType>(this)->on_pointerroutedaway();
				handled = true;
			}
			break;
		}
		case WM_POINTERROUTEDRELEASED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_pointerroutedreleased_t>)
			{
				down_cast<DerivedType>(this)->on_pointerroutedreleased();
				handled = true;
			}
			break;
		}
		case 0x0254:
		case 0x0255:
		case 0x0256:
		case 0x0257:
		case 0x0258:
		case 0x0259:
		case 0x025a:
		case 0x025b:
		case 0x025c:
		case 0x025d:
		case 0x025e:
		case 0x025f:
		case 0x0260:
		case 0x0261:
		case 0x0262:
		case 0x0263:
		case 0x0264:
		case 0x0265:
		case 0x0266:
		case 0x0267:
		case 0x0268:
		case 0x0269:
		case 0x026a:
		case 0x026b:
		case 0x026c:
		case 0x026d:
		case 0x026e:
		case 0x026f:
		case 0x0270:
		case 0x0271:
		case 0x0272:
		case 0x0273:
		case 0x0274:
		case 0x0275:
		case 0x0276:
		case 0x0277:
		case 0x0278:
		case 0x0279:
		case 0x027a:
		case 0x027b:
		case 0x027c:
		case 0x027d:
		case 0x027e:
		case 0x027f:
		case 0x0280:
		case WM_IME_SETCONTEXT:
		case WM_IME_NOTIFY:
		case WM_IME_CONTROL:
		case WM_IME_COMPOSITIONFULL:
		case WM_IME_SELECT:
		case WM_IME_CHAR:
		case 0x0287:
		case WM_IME_REQUEST:
		case 0x0289:
		case 0x028a:
		case 0x028b:
		case 0x028c:
		case 0x028d:
		case 0x028e:
		case 0x028f:
		case WM_IME_KEYDOWN:
		case WM_IME_KEYUP:
		case 0x0292:
		case 0x0293:
		case 0x0294:
		case 0x0295:
		case 0x0296:
		case 0x0297:
		case 0x0298:
		case 0x0299:
		case 0x029a:
		case 0x029b:
		case 0x029c:
		case 0x029d:
		case 0x029e:
		case 0x029f:
		{
			break;
		}
		case WM_NCMOUSEHOVER:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmousehover_t>)
			{
				down_cast<DerivedType>(this)->on_ncmousehover(value_convert<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_MOUSEHOVER:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mousehover_t>)
			{
				down_cast<DerivedType>(this)->on_mousehover(value_convert<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
				handled = true;
			}
			break;
		}
		case WM_NCMOUSELEAVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_ncmouseleave_t>)
			{
				down_cast<DerivedType>(this)->on_ncmouseleave();
				handled = true;
			}
			break;
		}
		case WM_MOUSELEAVE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_mouseleave_t>)
			{
				down_cast<DerivedType>(this)->on_mouseleave();
				handled = true;
			}
			break;
		}
		case 0x02a4:
		case 0x02a5:
		case 0x02a6:
		case 0x02a7:
		case 0x02a8:
		case 0x02a9:
		case 0x02aa:
		case 0x02ab:
		case 0x02ac:
		case 0x02ad:
		case 0x02ae:
		case 0x02af:
		case 0x02b0:
		{
			break;
		}
		case WM_WTSSESSION_CHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_wtssession_change_t>)
			{
				down_cast<DerivedType>(this)->on_wtssession_change(value_convert<session_change_type>(wparam), value_convert<uint32_t>(lparam));
				handled = true;
			}
			break;
		}
		case 0x02b2:
		case 0x02b3:
		case 0x02b4:
		case 0x02b5:
		case 0x02b6:
		case 0x02b7:
		case 0x02b8:
		case 0x02b9:
		case 0x02ba:
		case 0x02bb:
		case 0x02bc:
		case 0x02bd:
		case 0x02be:
		case 0x02bf:
		case 0x02c0:
		case 0x02c1:
		case 0x02c2:
		case 0x02c3:
		case 0x02c4:
		case 0x02c5:
		case 0x02c6:
		case 0x02c7:
		case 0x02c8:
		case 0x02c9:
		case 0x02ca:
		case 0x02cb:
		case 0x02cc:
		case 0x02cd:
		case 0x02ce:
		case 0x02cf:
		case 0x02d0:
		case 0x02d1:
		case 0x02d2:
		case 0x02d3:
		case 0x02d4:
		case 0x02d5:
		case 0x02d6:
		case 0x02d7:
		case 0x02d8:
		case 0x02d9:
		case 0x02da:
		case 0x02db:
		case 0x02dc:
		case 0x02dd:
		case 0x02de:
		case 0x02df:
		{
			break;
		}
		case WM_DPICHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dpichanged_t>)
			{
				down_cast<DerivedType>(this)->on_dpichanged(LOWORD(wparam), HIWORD(wparam), reference_from_param<RECT>(lparam));
				handled = true;
			}
			break;
		}
		case 0x02e1:
		{
			break;
		}
		case WM_DPICHANGED_BEFOREPARENT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dpichanged_beforeparent_t>)
			{
				down_cast<DerivedType>(this)->on_dpichanged_beforeparent();
				handled = true;
			}
			break;
		}
		case WM_DPICHANGED_AFTERPARENT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dpichanged_afterparent_t>)
			{
				down_cast<DerivedType>(this)->on_dpichanged_afterparent();
				handled = true;
			}
			break;
		}
		case WM_GETDPISCALEDSIZE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_getdpiscaledsize_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_getdpiscaledsize_t, bool> };
				static_assert(convertable_bool, "on_getdpiscaledsize with a return that is not convertable to bool detected.");
				auto result{ down_cast<DerivedType>(this)->on_getdpiscaledsize(value_convert<uint16_t>(wparam), reference_from_param<RECT>(lparam)) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case 0x02e5:
		case 0x02e6:
		case 0x02e7:
		case 0x02e8:
		case 0x02e9:
		case 0x02ea:
		case 0x02eb:
		case 0x02ec:
		case 0x02ed:
		case 0x02ee:
		case 0x02ef:
		case 0x02f0:
		case 0x02f1:
		case 0x02f2:
		case 0x02f3:
		case 0x02f4:
		case 0x02f5:
		case 0x02f6:
		case 0x02f7:
		case 0x02f8:
		case 0x02f9:
		case 0x02fa:
		case 0x02fb:
		case 0x02fc:
		case 0x02fd:
		case 0x02fe:
		case 0x02ff:
		{
			break;
		}
		case WM_CUT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_cut_t>)
			{
				down_cast<DerivedType>(this)->on_cut();
				handled = true;
			}
			break;
		}
		case WM_COPY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_copy_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_copy_t, bool> };
				static_assert(convertable_bool, "on_copy with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_copy()) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_PASTE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_paste_t>)
			{
				down_cast<DerivedType>(this)->on_paste();
				handled = true;
			}
			break;
		}
		case WM_CLEAR:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_clear_t>)
			{
				down_cast<DerivedType>(this)->on_clear();
				handled = true;
			}
			break;
		}
		case WM_UNDO:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_undo_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_undo_t, bool> };
				static_assert(convertable_bool, "on_undo with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_undo()) == false ? FALSE : TRUE };
				proc_result = result;
				handled = true;
			}
			break;
		}
		case WM_RENDERFORMAT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_renderformat_t>)
			{
				down_cast<DerivedType>(this)->on_renderformat(value_convert<clipboard_format>(wparam));
				handled = true;
			}
			break;
		}
		case WM_RENDERALLFORMATS:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_renderallformats_t>)
			{
				down_cast<DerivedType>(this)->on_renderallformats();
				handled = true;
			}
			break;
		}
		case WM_DESTROYCLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_destroyclipboard_t>)
			{
				down_cast<DerivedType>(this)->on_destroyclipboard();
				handled = true;
			}
			break;
		}
		case WM_DRAWCLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_drawclipboard_t>)
			{
				down_cast<DerivedType>(this)->on_drawclipboard();
				handled = true;
			}
			break;
		}
		case WM_PAINTCLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_paintclipboard_t>)
			{
				//The PAINTSTRUCT pointed to by lparam is allocated using GlobalAlloc, it must first be locked.
				auto ps_cache{ handle_cast<HGLOBAL>(lparam) };

				down_cast<DerivedType>(this)->on_paintclipboard(handle_cast<HWND>(wparam), reference_from_param<PAINTSTRUCT>(GlobalLock(ps_cache)));
				GlobalUnlock(ps_cache);
				handled = true;
			}
			break;
		}
		case WM_VSCROLLCLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_vscrollclipboard_t>)
			{
				down_cast<DerivedType>(this)->on_vscrollclipboard(handle_cast<HWND>(wparam), value_convert<vscrollbar_request>(lparam));
				handled = true;
			}
			break;
		}
		case WM_SIZECLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_sizeclipboard_t>)
			{
				//The RECT pointed to by lparam is allocated using GlobalAlloc, it must first be locked.
				//Todo -- Make exception safe.
				auto rc_cache{ handle_cast<HGLOBAL>(lparam) };
				down_cast<DerivedType>(this)->on_sizeclipboard(handle_cast<HWND>(wparam), pointer_deref(pointer_convert<RECT>(GlobalLock(rc_cache))));
				GlobalUnlock(rc_cache);
				handled = true;
			}
			break;
		}
		case WM_ASKCBFORMATNAME:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_askcbformatname_t>)
			{
				down_cast<DerivedType>(this)->on_askcbformatname(value_convert<uintptr_t>(wparam), pointer_from_param<wmt::template msg_char_type>(lparam));
				handled = true;
			}
			break;
		}
		case WM_CHANGECBCHAIN:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_changecbchain_t>)
			{
				down_cast<DerivedType>(this)->on_changecbchain(handle_cast<HWND>(wparam), handle_cast<HWND>(lparam));
				handled = true;
			}
			break;
		}
		case WM_HSCROLLCLIPBOARD:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_hscrollclipboard_t>)
			{
				down_cast<DerivedType>(this)->on_hscrollclipboard(handle_cast<HWND>(wparam), value_convert<hscrollbar_request>(lparam));
				handled = true;
			}
			break;
		}
		case WM_QUERYNEWPALETTE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_querynewpalette_t>)
			{
				constexpr const bool convertable_bool{ convertable_return_v<DerivedType, wmt::template on_querynewpalette_t, bool> };
				static_assert(convertable_bool, "on_querynewpalette with a return that is not convertable to bool found.");
				auto result{ value_convert<bool>(down_cast<DerivedType>(this)->on_querynewpalette()) == false ? FALSE : TRUE };
				proc_result = value_convert<LRESULT>(result);
				handled = true;
			}
			break;
		}
		case WM_PALETTEISCHANGING:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_paletteischanging_t>)
			{
				down_cast<DerivedType>(this)->on_paletteischanging(handle_cast<HWND>(wparam));
				handled = true;
			}
			break;
		}
		case WM_PALETTECHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_palettechanged_t>)
			{
				down_cast<DerivedType>(this)->on_palettechanged(handle_cast<HWND>(wparam));
				handled = true;
			}
			break;
		}
		case WM_HOTKEY:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_hotkey_t>)
			{
				down_cast<DerivedType>(this)->on_hotkey(value_convert<uint32_t>(wparam), value_convert<hotkey_modifier>(lparam));
				handled = true;
			}
			break;
		}
		case 0x0313:
		case 0x0314:
		case 0x0315:
		case 0x0316:
		{
			break;
		}
		case WM_PRINT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_print_t>)
			{
				down_cast<DerivedType>(this)->on_print(handle_cast<HDC>(wparam), value_convert<print_flags>(lparam));
				handled = true;
			}
			break;
		}
		case WM_PRINTCLIENT:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_printclient_t>)
			{
				down_cast<DerivedType>(this)->on_printclient(handle_cast<HDC>(wparam), value_convert<print_flags>(lparam));
				handled = true;
			}
			break;
		}
		case WM_APPCOMMAND:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_appcommand_t> || detect_v<DerivedType, wmt::template get_commandhandler_t>)
			{
				appcommand_info info{ handle_cast<HWND>(wparam),
						value_convert<appcommand_command>(GET_APPCOMMAND_LPARAM(lparam)),
						value_convert<appcommand_device>(GET_DEVICE_LPARAM(lparam)),
						value_convert<appcommand_keys>(GET_KEYSTATE_LPARAM(lparam))
				};
				int32_t mouse_xpos{};
				int32_t mouse_ypos{};
				if ((info.device & appcommand_device::mouse) == appcommand_device::mouse)
				{
					auto pos{ GetMessagePos() };
					mouse_xpos = GET_X_LPARAM(pos);
					mouse_ypos = GET_Y_LPARAM(pos);
				}
				if constexpr (detect_v<DerivedType, wmt::template on_appcommand_t>)
				{
					handled = down_cast<DerivedType>(this)->on_appcommand(info, mouse_xpos, mouse_ypos);
					//The documentation states that this should return true for legacy reasons.
					//It is the same reasons as the xbuttons.
					//We only return true if the message is handled.
					proc_result = handled == false ? FALSE : TRUE;
				}
				else
				{
					if constexpr (detect_v<DerivedType, wmt::template get_commandhandler_t>)
					{
						constexpr const bool return_command_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, command_handler_list &> };
						constexpr const bool return_ccommand_list{ same_return_v<DerivedType, wmt::template get_commandhandler_t, const command_handler_list &> };
						static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list.");
						handled = on_appcommand_default(info, mouse_xpos, mouse_ypos);
						//The documentation states that this should return true for legacy reasons.
						//It is the same reasons as the xbuttons.
						//We only return true if the message is handled.
						proc_result = handled == false ? FALSE : TRUE;
					}
				}
			}
			break;
		}
		case WM_THEMECHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_themechanged_t>)
			{
				down_cast<DerivedType>(this)->on_themechanged();
				handled = true;
			}
			break;
		}
		case 0x031b:
		case 0x031c:
		{
			break;
		}
		case WM_CLIPBOARDUPDATE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_clipboardupdate_t>)
			{
				down_cast<DerivedType>(this)->on_clipboardupdate();
				handled = true;
			}
			break;
		}
		case WM_DWMCOMPOSITIONCHANGED:
		{
			break;
		}
		case WM_DWMNCRENDERINGCHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dwmncrenderingchanged_t>)
			{
				down_cast<DerivedType>(this)->on_dwmncrenderingchanged(value_convert<BOOL>(wparam) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case WM_DWMCOLORIZATIONCOLORCHANGED:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dwmcolorizationcolorchanged_t>)
			{
				down_cast<DerivedType>(this)->on_dwmcolorizationcolorchanged(value_convert<uint32_t>(wparam), value_convert<BOOL>(lparam) == FALSE ? false : true);
				handled = true;
			}
			break;
		}
		case WM_DWMWINDOWMAXIMIZEDCHANGE:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dwmwindowmaximizedchange_t>)
			{
				down_cast<DerivedType>(this)->on_dwmwindowmaximizedchange(handle_cast<HWND>(wparam));
				handled = true;
			}
			break;
		}
		case 0x0322:
		{
			break;
		}
		case WM_DWMSENDICONICTHUMBNAIL:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dwmsendiconicthumbnail_t>)
			{
				//x is in the high word. Since we use the standard convention of x first, this requires us
				//to unpack the high value first.
				down_cast<DerivedType>(this)->on_dwmsendiconicthumbnail(HIWORD(lparam), LOWORD(lparam));
				handled = true;
			}
			break;
		}
		case 0x0324:
		case 0x0325:
		{
			break;
		}
		case WM_DWMSENDICONICLIVEPREVIEWBITMAP:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_dwmsendiconiclivepreviewbitmap_t>)
			{
				down_cast<DerivedType>(this)->on_dwmsendiconiclivepreviewbitmap();
				handled = true;
			}
			break;
		}
		case 0x0327:
		case 0x0328:
		case 0x0329:
		case 0x032a:
		case 0x032b:
		case 0x032c:
		case 0x032d:
		case 0x032e:
		case 0x032f:
		case 0x0330:
		case 0x0331:
		case 0x0332:
		case 0x0333:
		case 0x0334:
		case 0x0335:
		case 0x0336:
		case 0x0337:
		case 0x0338:
		case 0x0339:
		case 0x033a:
		case 0x033b:
		case 0x033c:
		case 0x033d:
		case 0x033e:
		{
			break;
		}
		case WM_GETTITLEBARINFOEX:
		{
			if constexpr (detect_v<DerivedType, wmt::template on_gettitlebarinfoex_t>)
			{
				down_cast<DerivedType>(this)->on_gettitlebarinfoex(reference_from_param<TITLEBARINFOEX>(lparam));
				handled = true;
			}
			break;
		}
		default:
			break;
		}

		return make_pair(proc_result, handled);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT window_t<DerivedType, CustomHandler, UnicodeBase>::simple_default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
	{
		auto [result, handled]{ default_message_handler(msg, wparam, lparam) };
		return handled == true ? result : message_handler(msg, wparam, lparam);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT window_t<DerivedType, CustomHandler, UnicodeBase>::window_proc_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		using utility::conversion::value_convert;

		auto that{ my_type::inst_from_handle(wnd) };
		LRESULT result{};
		if (that != nullptr)
		{
			if (msg == WM_DPICHANGED)
			{
				that->set_dpi(value_convert<uint32_t>(LOWORD(wparam)));
			}

			result = that->message_handler(msg, wparam, lparam);

			if (msg == WM_NCDESTROY)
			{
				if constexpr (details::detect_v<DerivedType, window_msg_types::template on_ncdestroy_t>)
				{
					//WM_NCDESTROY is documented to free internally allocated
					//memory. This would hint that we really want to pass this
					//message on to DefWindowProc too.
					//However, if the derived class doesn't handle WM_NCDESTROY
					//then we don't have to handle it.
					my_traits_t::WndDefWindowProc(wnd, msg, wparam, lparam);
				}

				my_type::handle_ncdestroy(wnd);
				//MUST NOT ACCESS ANY CLASS MEMBERS AFTER THIS POINT.
			}
		}
		else
		{
			//The current implementation doesn't state that WM_NCDESTROY is guaranteed
			//to be the last message received.We guard against this and pass any
			//message through to DefWindowProc to be safe.
			result = my_traits_t::WndDefWindowProc(wnd, msg, wparam, lparam);
		}

		return result;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT window_t<DerivedType, CustomHandler, UnicodeBase>::window_proc_init_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		static bool first_message{ true };
		//A hook is used to get in front of the first call to this proc. This means that
		//the class instance is placed into the window before this proc is called for the
		//first time.
		auto that{ my_type::inst_from_handle(wnd) };
		if constexpr (UnicodeBase)
		{
			_ASSERTE(IsWindowUnicode(wnd) != FALSE);
		}
		else
		{
			_ASSERTE(IsWindowUnicode(wnd) == FALSE);
		}
		_ASSERTE(that != nullptr);
		if (first_message)
		{
			my_type::handle_first_message(wnd);
			first_message = false;
		}

		if (msg != WM_NCCREATE)
		{
			return that->message_handler(msg, wparam, lparam);
		}
		else
		{
			LRESULT result{ that->message_handler(msg, wparam, lparam) };

			if constexpr (details::detect_v<DerivedType, window_msg_types::template on_nccreate_t>)
			{
				//Even if the policy is set to call DefWindowProc on WM_NCCREATE, if
				//the message handler calls DefWindowProc, we don't want to follow this
				//policy.
				auto dwp_result{ window_default_nccreate_policy<DerivedType, UnicodeBase>::call_defwindowproc_nccreate(wnd, wparam, lparam) };
				result = result == FALSE ? FALSE : dwp_result;
			}

			m_proc = window_proc_seh;

			return result;
		}
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline LRESULT CALLBACK window_t<DerivedType, CustomHandler, UnicodeBase>::window_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return m_proc(wnd, msg, wparam, lparam);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline auto window_t<DerivedType, CustomHandler, UnicodeBase>::inst_from_handle(HWND wnd) -> my_tptr
	{
		using utility::conversion::pointer_convert;
		using utility::conversion::down_cast;

		my_tptr ptr{ down_cast<my_t>(pointer_convert<my_base_t>(raw_inst_from_handle(wnd))) };
		return ptr;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline void window_t<DerivedType, CustomHandler, UnicodeBase>::handle_first_message(HWND wnd)
	{
		auto that{ inst_from_handle(wnd) };
		auto dpi{ GetDpiForWindow(wnd) };
		that->set_dpi(dpi);
		that->track_mouse();
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline void window_t<DerivedType, CustomHandler, UnicodeBase>::handle_ncdestroy(HWND wnd)
	{
		//Remove the class pointer from the window and then we delete the class
		auto that{ my_type::inst_from_handle(wnd) };
		that->notify_window_close();
		that->untrack_mouse();
		that->cleanup_window_info();
		delete that;

		window_post_quit_policy<DerivedType>::post_quit_message(0);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	template <typename ...Types>
	inline auto window_t<DerivedType, CustomHandler, UnicodeBase>::default_create(Types &&... args) -> DerivedType *
	{
		using namespace std;
		using namespace details;

		//The raw new is used instead of std::make_unique for an important
		//reason. The DerivedType constructors are expected to be private, and the
		//window is expected to be created through a static create function.
		//std::make_unique would therefore not have access to the constructor without
		//declaring std::make_unique<DerivedType> as a friend.
		std::unique_ptr<DerivedType> ptr{ nullptr };
		HINSTANCE inst{};
		my_string_t class_name;
		bool success{ false };
		{
			using namespace details::class_detect;
			if constexpr (detect_class_definitions_typedef_v<DerivedType>)
			{
				//This is needed early.
				using my_definitions = typename DerivedType::class_definitions;
				inst = instance_value<my_definitions>::get_value();
				ptr.reset(new DerivedType(inst, std::forward<Types>(args)...));

				success = default_create_on_pointer(ptr.get(), inst);
			}
			else
			{
				if constexpr (detect_class_definitions_v<DerivedType>)
				{
					//This is needed early.
					using my_definitions = class_definitions<DerivedType>;
					inst = instance_value<my_definitions>::get_value();
					ptr.reset(new DerivedType(inst, std::forward<Types>(args)...));

					success = default_create_on_pointer(ptr.get(), inst);
				}
			}
		}

		return success == true ? ptr.release() : nullptr;
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	template <typename Definitions>
	inline auto window_t<DerivedType, CustomHandler, UnicodeBase>::default_register_from_definition(HINSTANCE inst) -> std::pair<bool, my_string_t>
	{
		using namespace std;
		using namespace details;
		using namespace details::class_detect;

		using my_definitions = Definitions;
		my_string_t my_class_name;
		bool result{ false };

		if constexpr (detect_v<my_definitions, class_definition_types::existing_class_name_t>)
		{
			static_assert(detect_v<my_definitions, class_definition_types::class_name_t>);
			my_class_name = my_string_t{ my_definitions::class_name };
			result = my_base_t::is_class_registered(my_string_view_t{my_class_name});
		}
		else
		{
			typename my_traits_t::wndclassex_t wcx{ };

			wcx.cbSize = sizeof(typename my_traits_t::wndclassex_t);
			wcx.lpfnWndProc = my_type::window_proc;
			wcx.hInstance = inst;
			my_class_name = my_string_t{ my_definitions::class_name };

			wcx.style = style_value<my_definitions>::get_value();
			wcx.cbClsExtra = class_extra_value<my_definitions>::get_value();
			wcx.cbWndExtra = window_extra_value<my_definitions>::get_value();
			wcx.hIcon = icon_value<my_definitions>::get_value();
			wcx.hCursor = cursor_value<my_definitions>::get_value();
			wcx.hbrBackground = brush_value<my_definitions>::get_value();
			wcx.lpszMenuName = menu_name_value<my_definitions>::get_value();
			wcx.lpszClassName = my_class_name.data();
			wcx.hIconSm = small_icon_value<my_definitions>::get_value();

			result = register_class(wcx);
		}

		return { result, my_class_name };
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	template <typename Definitions>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::default_create_window_from_definition(DerivedType *ptr, const my_string_t &class_name)
	{
		using namespace std;
		using namespace details;
		using namespace details::window_detect;

		constexpr const auto position_detected = detect_v<Definitions, window_definition_types::position_t>;
		constexpr const auto x_detected = detect_v<Definitions, window_definition_types::x_t>;
		constexpr const auto y_detected = detect_v<Definitions, window_definition_types::y_t>;

		constexpr const auto size_detected = detect_v<Definitions, window_definition_types::size_t>;
		constexpr const auto width_detected = detect_v<Definitions, window_definition_types::width_t>;
		constexpr const auto height_detected = detect_v<Definitions, window_definition_types::height_t>;

		POINT position_cache{};
		SIZE size_cache{};

		if constexpr (position_detected || x_detected || y_detected)
		{
			//If any of these are detected, then assert on any invalid combination.
			if constexpr (position_detected) static_assert(!(x_detected || y_detected));
			if constexpr (x_detected || y_detected) static_assert(!position_detected);
		}
		else
		{
			//This is the case when none of the position values are
			//detected. Use position value since this will return
			//a pretty good default.
			position_cache = position_value<Definitions>::get_value();
		}
		if constexpr (!position_detected && (x_detected || y_detected))
		{
			//Any missing definitions will default to a pretty good value.
			position_cache.x = x_value<Definitions>::get_value();
			position_cache.y = y_value<Definitions>::get_value();
		}
		if constexpr (position_detected && !(x_detected || y_detected))
		{
			position_cache = position_value<Definitions>::get_value();
		}

		if constexpr (size_detected || width_detected || height_detected)
		{
			//If any of these are detected, then assert on any invalid combination.
			if constexpr (size_detected) static_assert(!(width_detected || height_detected));
			if constexpr (width_detected || height_detected) static_assert(!size_detected);
		}
		else
		{
			//This is the case when none of the size values are
			//detected. Use size value since this will return
			//a pretty good default.
			size_cache = size_value<Definitions>::get_value();
		}
		if constexpr (!size_detected && (width_detected || height_detected))
		{
			//Any missing definitions will default to a pretty good value.
			size_cache.cx = width_value<Definitions>::get_value();
			size_cache.cy = height_value<Definitions>::get_value();
		}
		if constexpr (size_detected && !(width_detected || height_detected))
		{
			size_cache = size_value<Definitions>::get_value();
		}

		auto style_cache{ style_value<Definitions>::get_value() };
		auto ex_style_cache{ ex_style_value<Definitions>::get_value() };
		my_string_t window_name_cache;
		if constexpr (detect_v<Definitions, window_definition_types::window_name_t>)
		{
			window_name_cache = my_string_t{ Definitions::window_name };
		}
		auto parent_cache{ parent_value<Definitions>::get_value() };
		HMENU menu_cache{};
		if constexpr (detect_v<Definitions, window_definition_types::menu_t>)
		{
			if (parent_cache)
			{
				constexpr const auto is_integral{ std::is_integral_v<window_definition_types::menu_t<Definitions>> };
				if constexpr (is_integral)
				{
					using utility::conversion::handle_from_param;
					//Parent window is set. Check HMENU for an identifier.
					menu_cache = handle_from_param<HMENU>(menu_value_child<Definitions>::get_value());
				}
			}
			else
			{
				constexpr const auto is_hmenu{ std::is_same_v<window_definition_types::menu_t<Definitions>, HMENU> };
				if constexpr (is_hmenu)
				{
					menu_cache = menu_value_nonchild<Definitions>::get_value();
				}
			}
		}

		return window_t::create_window(class_name, window_name_cache, style_cache, ex_style_cache, position_cache, size_cache, ptr, parent_cache, menu_cache);
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	inline bool window_t<DerivedType, CustomHandler, UnicodeBase>::default_create_on_pointer(DerivedType *ptr, HINSTANCE inst)
	{
		using namespace details;

		bool result{ true };

		my_string_t class_name;
		{
			using namespace details::class_detect;
			if constexpr (detect_class_definitions_typedef_v<DerivedType>)
			{
				using my_definitions = typename DerivedType::class_definitions;

				auto [success, return_class_name] { default_register_from_definition<my_definitions>(inst) };

				result = success;
				//The class name needs to be stashed for CreateWindowEx.
				class_name = return_class_name;
			}
			else
			{
				if constexpr (detect_class_definitions_v<DerivedType>)
				{
					using my_definitions = class_definitions<DerivedType>;
					auto [success, return_class_name] { default_register_from_definition<my_definitions>(inst) };

					result = success;
					//The class name needs to be stashed for CreateWindowEx.
					class_name = return_class_name;
				}
			}
		}

		if (result == true)
		{
			{
				using namespace details::window_detect;
				if constexpr (detect_window_definitions_typedef_v<DerivedType>)
				{
					using my_definitions = typename DerivedType::window_definitions;
					result = default_create_window_from_definition<my_definitions>(ptr, class_name);
				}
				else
				{
					if constexpr (detect_window_definitions_v<DerivedType>)
					{
						using my_definitions = window_definitions<DerivedType>;
						result = default_create_window_from_definition<my_definitions>(ptr, class_name);
					}
				}
			}
		}

		return result;
	}
}