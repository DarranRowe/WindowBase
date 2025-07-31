#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include "window_base.hpp"
#include "window_class.hpp"

#include <windowsx.h>
#include <shellapi.h>
#include <Dbt.h>

#include "utility.hpp"
#include "output_helpers.hpp"

//The implementation header checks for this to know
//that this header has been included. It contains
//the class definition that it uses.
#define WINDOW_TEMPLATE_INCLUDED 1

namespace window_base::windowing
{
#if (defined UNICODE) || defined (_UNICODE)
	constexpr inline bool window_default_unicode{ true };
#else
	constexpr inline bool window_default_unicode{ false };
#endif

	namespace details
	{
		template <typename T, template <typename> typename, typename = std::void_t<>>
		struct detect : std::false_type {};

		template <typename T, template <typename> typename Op>
		struct detect<T, Op, std::void_t<Op<T>>> : std::true_type {};

		template <typename T, template <typename> typename Op>
		inline constexpr bool detect_v{ detect<T, Op>::value };

		template <typename T, template <typename> typename Op>
		using return_type_t = Op<T>;

		template <typename T, template <typename> typename Op, typename Cmp>
		inline constexpr bool same_return_v{ std::is_same_v<return_type_t<T, Op>, Cmp> };

		template <typename T, template <typename> typename Op, typename Cmp>
		inline constexpr bool convertable_return_v{ std::is_convertible_v<return_type_t<T, Op>, Cmp> };

		template <typename T, template <typename> typename Op>
		inline constexpr bool integral_return_v{ std::is_integral_v<return_type_t<T, Op>> };

		template <typename P1, typename P2>
		uint16_t make_word(P1 p1, P2 p2)
		{
			//These need to be strengthened to check type sizes
			uint16_t result{ (static_cast<uint16_t>(static_cast<uint8_t>(p1)) | (static_cast<uint16_t>(static_cast<uint8_t>(p2)) << 8)) };
			return result;
		}
		template <typename P1, typename P2>
		uint32_t make_dword(P1 p1, P2 p2)
		{
			//These need to be strengthened to check type sizes
			uint32_t result{ (static_cast<uint32_t>(static_cast<uint16_t>(p1)) | (static_cast<uint32_t>(static_cast<uint16_t>(p2)) << 16)) };
			return result;
		}
	}

	enum class virtual_key : uint8_t
	{
		none,
		mouse_left,
		mouse_right,
		cancel,
		mouse_middle,
		mouse_x1,
		mouse_x2,

		key_back = 0x08,
		key_tab,
		key_clear = 0x0c,
		key_return,
		key_shift = 0x10,
		key_control,
		key_menu,
		key_pause,
		key_capital,
		key_kana,
		key_hangul = 0x15,
		key_ime_on,
		key_junja,
		key_final,
		key_hanja,
		key_kanji = 0x19,
		key_ime_off,
		key_escape,
		key_convert,
		key_nonconvert,
		key_accept,
		key_modechange,
		key_space,
		key_prior,
		key_next,
		key_end,
		key_home,
		key_left,
		key_up,
		key_right,
		key_down,
		key_select,
		key_print,
		key_execute,
		key_snapshot,
		key_insert,
		key_delete,
		key_help,
		key_0,
		key_1,
		key_2,
		key_3,
		key_4,
		key_5,
		key_6,
		key_7,
		key_8,
		key_9,
		key_a = 0x41,
		key_b,
		key_c,
		key_d,
		key_e,
		key_f,
		key_g,
		key_h,
		key_i,
		key_j,
		key_k,
		key_l,
		key_m,
		key_n,
		key_o,
		key_p,
		key_q,
		key_r,
		key_s,
		key_t,
		key_u,
		key_v,
		key_w,
		key_x,
		key_y,
		key_z,
		key_lwin,
		key_rwin,
		key_apps,
		key_sleep = 0x5f,
		key_np0,
		key_np1,
		key_np2,
		key_np3,
		key_np4,
		key_np5,
		key_np6,
		key_np7,
		key_np8,
		key_np9,
		key_multiply,
		key_add,
		key_seperator,
		key_subtract,
		key_decimal,
		key_divide,
		key_f1,
		key_f2,
		key_f3,
		key_f4,
		key_f5,
		key_f6,
		key_f7,
		key_f8,
		key_f9,
		key_f10,
		key_f11,
		key_f12,
		key_f13,
		key_f14,
		key_f15,
		key_f16,
		key_f17,
		key_f18,
		key_f19,
		key_f20,
		key_f21,
		key_f22,
		key_f23,
		key_f24,
		key_nav_view,
		key_nav_menu,
		key_nav_up,
		key_nav_down,
		key_nav_left,
		key_nav_right,
		key_nav_accept,
		key_nav_cancel,
		key_numlock,
		key_scroll,
		oem_nec_equal,
		oem_fj_jisho = 0x92,
		oem_fj_masshou,
		oem_fj_touroku,
		oem_fj_loya,
		oem_fj_roya,
		key_lshift = 0xa0,
		key_rshift,
		key_lcontrol,
		key_rcontrol,
		key_lmenu,
		key_rmenu,
		key_br_back,
		key_br_forward,
		key_br_refresh,
		key_br_stop,
		key_br_search,
		key_br_favorites,
		key_br_home,
		key_vol_mute,
		key_vol_down,
		key_vol_up,
		key_media_next,
		key_media_prev,
		key_media_stop,
		key_media_play,
		key_lch_mail,
		key_lch_media,
		key_lch_app1,
		key_lch_app2,
		key_oem_1 = 0xba,
		key_oem_plus,
		key_oem_comma,
		key_oem_minus,
		key_oem_period,
		key_oem_2,
		key_oem_3,
		pad_a = 0xc3,
		pad_b,
		pad_x,
		pad_y,
		pad_rshoulder,
		pad_lshoulder,
		pad_ltrigger,
		pad_rtrigger,
		pad_dup,
		pad_ddown,
		pad_dleft,
		pad_dright,
		pad_menu,
		pad_view,
		pad_left_stick,
		pad_right_stick,
		pad_anlg_lup,
		pad_anlg_ldown,
		pad_anlg_lright,
		pad_anlg_lleft,
		pad_anlg_rup,
		pad_anlg_rdown,
		pad_anlg_rright,
		pad_anlg_rleft,
		key_oem_4,
		key_oem_5,
		key_oem_6,
		key_oem_7,
		key_oem_8,
		key_oem_ax = 0xe1,
		key_oem_102,
		key_ico_help,
		key_ico_00,
		key_process,
		key_ico_clear,
		key_packet,
		key_oem_reset = 0xe9,
		key_oem_jump,
		key_oem_pa1,
		key_oem_pa2,
		key_oem_pa3,
		key_oem_wsctrl,
		key_oem_cusel,
		key_oem_attn,
		key_oem_finish,
		key_oem_copy,
		key_oem_auto,
		key_oem_enlw,
		key_oem_backtab,
		key_attn,
		key_crsel,
		key_exsel,
		key_ereof,
		key_play,
		key_zoom,
		key_noname,
		key_pa1,
		key_oem_clear,
	};

	enum class resize_type
	{
		restored,
		minimized,
		maximized,
		maxshow,
		maxhide
	};
	enum class activate_type
	{
		inactive,
		active,
		clickactive
	};
	enum class endsession_reason : uint32_t
	{
		shutdown_restart = 0x00000000,
		closeapp = 0x00000001,
		critical = 0x40000000,
		logoff = 0x80000000
	};

	ENUM_BITWISE_OPERATORS(endsession_reason);

	enum class showwindow_reason
	{
		showwindow,
		parent_closing,
		other_zoom,
		parent_opening,
		other_unzoom
	};
	enum class hittest_position
	{
		error = -2,
		transparent = -1,
		nowhere = 0,
		client,
		caption,
		sysmenu,
		size_growbox,
		menu,
		hscroll,
		vscroll,
		min_button_reduce,
		max_button_zoom,
		left,
		right,
		top,
		top_left,
		top_right,
		bottom,
		bottom_left,
		bottom_right,
		border,
		close = 20,
		help
	};
	enum class mouse_activate_type
	{
		unknown,
		activate = 1,
		activate_and_eat,
		no_activate,
		no_activate_and_eat
	};
	enum class sizing_from
	{
		unknown,
		left = 1,
		right,
		top,
		top_left,
		top_right,
		bottom,
		bottom_left,
		bottom_right
	};
	enum class set_hot_key_result
	{
		fail_hotkey = -1,
		fail_window = 0,
		success,
		success_duplicate
	};
	enum class compare_item_result
	{
		less = -1,
		equal = 0,
		greater = 1
	};

	enum class input_language_change_flags : uint16_t
	{
		change_unknown = 0x0000,
		change_syscharset = 0x0001,
		change_forward = 0x0002,
		change_backwards = 0x0004
	};

	ENUM_BITWISE_OPERATORS(input_language_change_flags);

	enum class input_language_character_set : uint8_t
	{
		ansi_set = 0,
		default_set = 1,
		symbol_set = 2,

		mac_set = 77,
		shiftjis_set = 128,
		hangul_set = 129,
		johab_set = 130,
		gb2312_set = 134,
		big5_set = 136,
		greek_set = 161,
		turkish_set = 162,
		vietnamese_set = 163,
		hebrew_set = 177,
		arabic_set = 178,
		baltic_set = 186,
		russian_set = 204,
		thai_set = 222,
		easteurope_set = 238,
		oem_set = 255
	};
	enum class notify_format_type
	{
		query = 3,
		requery = 4
	};
	enum class notify_format_result
	{
		error = 0,
		ansi = 1,
		unicode = 2
	};
	enum class style_changing_type
	{
		ex_style = -20,
		style = -16
	};
	enum class icon_type
	{
		small_icon,
		big_icon,
		small_icon2
	};
	enum class nccalcsize_return : uint16_t
	{
		none = 0x0000,
		align_top = 0x0010,
		align_left = 0x0020,
		align_bottom = 0x0040,
		align_right = 0x0080,
		hredraw = 0x0100,
		vredraw = 0x0200,
		validrects = 0x0400
	};

	ENUM_BITWISE_OPERATORS(nccalcsize_return);

	enum class xbutton_type : int16_t
	{
		unknown,
		xbutton_1 = 1,
		xbutton_2 = 2
	};
	enum class input_dev_change_type
	{
		unknown,
		arrival = 1,
		removal
	};
	enum class input_type
	{
		input,
		input_sink
	};

	enum class ime_composition_flags : uint16_t
	{
		unknown,
		comp_read_str = 0x0001,
		comp_read_attr = 0x0002,
		comp_read_clause = 0x0004,
		comp_str = 0x0008,
		comp_attr = 0x0010,
		comp_clause = 0x0020,
		cursor_pos = 0x0080,
		delta_start = 0x0100,
		result_read_str = 0x0200,
		result_read_clause = 0x0400,
		result_str = 0x0800,
		result_clause = 0x1000,
		insert_char = 0x2000,
		no_move_caret = 0x4000
	};

	ENUM_BITWISE_OPERATORS(ime_composition_flags);

	enum class syscommand_request : uint16_t
	{
		unknown,
		size = 0xf000,
		move = 0xf010,
		minimize = 0xf020,
		maximize = 0xf030,
		next_window = 0xf040,
		prev_window = 0xf050,
		close = 0xf060,
		vscroll = 0xf070,
		hscroll = 0xf080,
		mouse_menu = 0xf090,
		key_menu = 0xf100,
		arrange = 0xf110,
		restore = 0xf120,
		task_list = 0xf130,
		screen_save = 0xf140,
		hotkey = 0xf150,
		default_cmd = 0xf160,
		monitor_power = 0xf170,
		context_help = 0xf180
	};
	struct syscommand_info
	{
		syscommand_request request;
		bool is_secure;
	};
	enum class hscrollbar_request
	{
		line_left = 0,
		line_right = 1,
		page_left = 2,
		page_right = 3,
		thumb_position = 4,
		thumb_track = 5,
		left = 6,
		right = 7,
		end_scroll = 8
	};
	enum class vscrollbar_request
	{
		line_up = 0,
		line_down = 1,
		page_up = 2,
		page_down = 3,
		thumb_position = 4,
		thumb_track = 5,
		top = 6,
		bottom = 7,
		end_scroll = 8
	};

	enum class menuselect_flags : uint16_t
	{
		string = 0x0000,
		greyed = 0x0001,
		disabled = 0x0002,
		bitmap = 0x0004,
		checked = 0x0008,
		popup = 0x0010,
		hilite = 0x0080,
		ownerdraw = 0x0100,
		sysmenu = 0x2000,
		mouseselect = 0x8000
	};

	ENUM_BITWISE_OPERATORS(menuselect_flags);

	enum class menuchar_flags
	{
		none = 0x0000,
		popup = 0x0010,
		sysmenu = 0x2000
	};
	enum class menuchar_return_type : int16_t
	{
		ignore,
		close,
		execute,
		select
	};
	enum class enteridle_type
	{
		dialogbox = 0,
		menu = 2
	};
	enum class menudrag_return
	{
		continue_menu,
		end_menu
	};
	enum class menugetobject_return
	{
		no_interface,
		no_error
	};

	enum class uistate_action
	{
		unknown,
		set = 1,
		clear,
		initialize
	};
	enum class uistate_style
	{
		none = 0x00,
		hide_focus = 0x01,
		hide_accel = 0x02,
		active = 0x04
	};

	ENUM_BITWISE_OPERATORS(uistate_style);

	enum class mouse_vkey : uint16_t
	{
		none = 0x0000,
		lbutton = 0x0001,
		rbutton = 0x0002,
		shift = 0x0004,
		control = 0x0008,
		mbutton = 0x0010,
		xbutton1 = 0x0020,
		xbutton2 = 0x0040
	};

	ENUM_BITWISE_OPERATORS(mouse_vkey);

	enum class power_event_type
	{
		none,
		apm_suspend = 4,
		apm_resumesuspend = 7,
		apm_powerstatuschange = 10,
		apm_resumeautomatic = 18,
		apm_powersettingchange = 32787
	};
	enum class get_dlg_code_return : uint16_t
	{
		none,
		want_arrows = 0x0001,
		want_tab = 0x0002,
		want_message = 0x0004,
		has_set_sel = 0x0008,
		def_push_button = 0x0010,
		undef_push_button = 0x0020,
		radio_button = 0x0040,
		want_chars = 0x0080,
		static_ctl = 0x0100,
		button = 0x2000
	};

	ENUM_BITWISE_OPERATORS(get_dlg_code_return);

	enum class pointer_activate_type
	{
		unknown,
		activate = 1,
		no_activate = 3
	};
	enum class session_change_type
	{
		unknown,
		console_connect,
		console_disconnect,
		remote_connect,
		remote_disconnect,
		session_logon,
		session_logoff,
		session_lock,
		session_unlock,
		session_remote_control,
		session_create,
		session_terminate
	};
	enum class clipboard_format
	{
		unknown,
		text,
		bitmap,
		metafile,
		sylk,
		dif,
		tiff,
		oemtext,
		dib,
		palette,
		pendata,
		riff,
		wave,
		unicodetext,
		enhmetafile,
		hdrop,
		locale,
		dibv5,
		ownerdisplay = 0x80,
		dsptext,
		dspbitmap,
		dspmetafilepict,
		dspenhmetafile = 0x8e,
		privatefirst = 0x0200,
		privatelast = 0x02ff,
		gdifirst = 0x0300,
		gdilast = 0x03ff
	};
	enum class hotkey_modifier
	{
		none,
		alt = 0x01,
		control = 0x02,
		shift = 0x04,
		win = 0x08
	};

	ENUM_BITWISE_OPERATORS(hotkey_modifier);

	enum class print_flags
	{
		none,
		check_visible,
		non_client,
		client = 0x04,
		erase_bkgnd = 0x08,
		children = 0x10,
		owned = 0x20
	};

	ENUM_BITWISE_OPERATORS(print_flags);

	enum class devicechange_type : uint16_t
	{
		unknown,
		devnodes_changed = 0x0007,
		querychangeconfig = 0x0017,
		configchanged = 0x0018,
		configchangecancelled = 0x0019,
		devicearrival = 0x8000,
		devicequeryremove = 0x8001,
		devicequeryremovefailed = 0x8002,
		deviceremovepending = 0x8003,
		deviceremovecomplete = 0x8004,
		devicetypespecific = 0x8005,
		customevent = 0x8006,
		userdefined = 0xffff
	};
	enum class appcommand_command : uint8_t
	{
		unknown,
		browser_backward,
		browser_forward,
		browser_refresh,
		browser_stop,
		browser_search,
		browser_favorites,
		browser_home,
		volume_mute,
		volume_down,
		volume_up,
		media_nexttrack,
		media_previoustrack,
		media_stop,
		media_play_pause,
		launch_mail,
		launch_media_select,
		launch_app1,
		launch_app2,
		bass_down,
		bass_boost,
		bass_up,
		treble_down,
		treble_up,
		microphone_volume_mute,
		microphone_volume_down,
		microphone_volume_up,
		cmd_help,
		cmd_find,
		cmd_new,
		cmd_open,
		cmd_close,
		cmd_save,
		cmd_print,
		cmd_undo,
		cmd_redo,
		cmd_copy,
		cmd_cut,
		cmd_paste,
		reply_to_mail,
		forward_mail,
		send_mail,
		spell_check,
		dictate_or_command_control_toggle,
		mic_on_off_toggle,
		correction_list,
		media_play,
		media_pause,
		media_record,
		media_fast_forward,
		media_rewind,
		media_channel_up,
		media_channel_down,
		cmd_delete,
		dwm_flip3d
	};
	enum class appcommand_device : uint16_t
	{
		key,
		oem = 0x1000,
		mouse = 0x8000
	};

	ENUM_BITWISE_OPERATORS(appcommand_device);

	enum class appcommand_keys : uint16_t
	{
		none,
		lbutton = 0x0001,
		rbutton = 0x0002,
		shift = 0x0004,
		control = 0x0008,
		mbutton = 0x0010,
		xbutton1 = 0x0020,
		xbutton2 = 0x0040
	};

	ENUM_BITWISE_OPERATORS(appcommand_keys);

	using next_dlg_ctl_params = std::variant<HWND, bool>;
	using nccalcsize_params = std::variant<std::reference_wrapper<NCCALCSIZE_PARAMS>, std::reference_wrapper<RECT>>;
	using notify_param1 = std::variant<xbutton_type, uint16_t, uint16_t>;
	using notify_param2 = std::variant<std::reference_wrapper<POINT>, HWND>;
	using enteridle_param = std::variant<HWND, HMENU>;
	using devicechange_param = std::variant<std::reference_wrapper<DEV_BROADCAST_HDR>, std::reference_wrapper<_DEV_BROADCAST_USERDEFINED>>;

	struct hot_key_value
	{
		uint8_t vk;
		uint8_t modifier;
	};
	struct keystroke_data
	{
		uint16_t repeat_count;
		uint8_t scan_code;
		uint8_t extended_key : 1;
		uint8_t : 4;
		uint8_t context_code : 1;
		uint8_t previous_state : 1;
		uint8_t transition_state : 1;
	};
	struct menuchar_return
	{
		uint16_t index;
		menuchar_return_type result;
	};
	struct pointer_data
	{
		uint32_t flag_new : 1;
		uint32_t flag_inrange : 1;
		uint32_t flag_incontact : 1;
		uint32_t : 1;
		uint32_t flag_first_button : 1;
		uint32_t flag_second_button : 1;
		uint32_t flag_third_button : 1;
		uint32_t flag_fourth_button : 1;
		uint32_t flag_fifth_button : 1;
		uint32_t : 4;
		uint32_t flag_primary : 1;
		uint32_t flag_confidence : 1;
		uint32_t flag_canceled : 1;
		uint32_t flag_down : 1;
		uint32_t flag_update : 1;
		uint32_t flag_up : 1;
		uint32_t flag_wheel : 1;
		uint32_t flag_hwheel : 1;
		uint32_t flag_capturechange : 1;
		uint32_t flag_hastransform : 1;
	};
	struct appcommand_info
	{
		HWND command_window;
		appcommand_command appcommand;
		appcommand_device device;
		appcommand_keys keys;
	};

	template <bool UnicodeBase = false>
	struct choose_window_base
	{
		using type = window_base_a;
	};
	template <>
	struct choose_window_base<true>
	{
		using type = window_base_w;
	};
	template <bool UnicodeBase>
	using choose_window_base_t = typename choose_window_base<UnicodeBase>::type;

	template <bool UnicodeBase = false>
	struct choose_window_traits
	{
		using type = window_traits_a;
	};
	template <>
	struct choose_window_traits<true>
	{
		using type = window_traits_w;
	};
	template <bool UnicodeBase>
	using choose_window_traits_t = typename choose_window_traits<UnicodeBase>::type;

	template <typename T>
	struct static_assert_wrapper
	{
		inline static constexpr bool s_assert{ false };
	};

	template <typename DerivedType>
	struct class_definitions
	{
		static_assert(static_assert_wrapper<DerivedType>::s_assert, "Unspecialised class_definitions used");
	};

	template <typename DerivedType>
	struct window_definitions
	{
		static_assert(static_assert_wrapper<DerivedType>::s_assert, "Unspecialised window_definitions used");
	};

	struct window_quit_process_t{};
	struct window_default_t{};

	struct window_default_nccreate_t{};

	struct window_mouse_track_t {};
	struct window_ncmouse_track_t {};
	struct window_no_mouse_track_t {};

	struct window_unicode_t {};
	struct window_ansi_t {};

	namespace details
	{
		enum class mouse_policy_value {
			no_mouse_track,
			mouse_track,
			ncmouse_track
		};

		template <typename PolicyType>
		constexpr mouse_policy_value get_mouse_policy_type()
		{
			if constexpr (std::is_same_v<PolicyType, window_no_mouse_track_t>)
			{
				return mouse_policy_value::no_mouse_track;
			}
			else
			{
				if constexpr (std::is_same_v<PolicyType, window_mouse_track_t>)
				{
					return mouse_policy_value::mouse_track;
				}
				else
				{
					return mouse_policy_value::ncmouse_track;
				}
			}
		}

		template <typename ClassType, typename = std::void_t<>>
		struct detect_mouse_policy : std::false_type {};

		template <typename ClassType>
		struct detect_mouse_policy<ClassType, std::void_t<typename ClassType::mouse_track_policy>> : std::true_type {};

		template <typename ClassType>
		inline constexpr const bool detect_mouse_policy_v = detect_mouse_policy<ClassType>::value;

		template <typename ClassType, bool = detect_mouse_policy_v<ClassType>>
		struct mouse_policy_or_default
		{
			using policy = window_no_mouse_track_t;
			inline static constexpr const mouse_policy_value value{ mouse_policy_value::no_mouse_track };
		};

		template <typename ClassType>
		struct mouse_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::mouse_track_policy;
			inline static constexpr const mouse_policy_value value{ get_mouse_policy_type<typename ClassType::mouse_track_policy>() };
		};

		template <typename ClassType>
		using mouse_policy_t = typename mouse_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const mouse_policy_value mouse_policy_v = mouse_policy_or_default<ClassType>::value;

		template <typename ClassType, typename = std::void_t<>>
		struct detect_ncmouse_policy : std::false_type {};

		template <typename ClassType>
		struct detect_ncmouse_policy<ClassType, std::void_t<typename ClassType::ncmouse_track_policy>> : std::true_type {};

		template <typename ClassType>
		inline constexpr const bool detect_ncmouse_policy_v = detect_ncmouse_policy<ClassType>::value;

		template <typename ClassType, bool = detect_ncmouse_policy_v<ClassType>>
		struct ncmouse_policy_or_default
		{
			using policy = window_no_mouse_track_t;
			inline static constexpr const mouse_policy_value value{ mouse_policy_value::no_mouse_track };
		};

		template <typename ClassType>
		struct ncmouse_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::ncmouse_track_policy;
			inline static constexpr const mouse_policy_value value{ get_mouse_policy_type<typename ClassType::ncmouse_track_policy>() };
		};

		template <typename ClassType>
		using ncmouse_policy_t = typename ncmouse_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const mouse_policy_value ncmouse_policy_v = ncmouse_policy_or_default<ClassType>::value;

		template <typename ClassType, typename = std::void_t<>>
		struct detect_process_quit_policy : std::false_type {};

		template <typename ClassType>
		struct detect_process_quit_policy<ClassType, std::void_t<typename ClassType::quit_process_policy>> : std::true_type {};

		template <typename ClassType>
		inline constexpr const bool detect_process_quit_policy_v = detect_process_quit_policy<ClassType>::value;

		template <typename PolicyType>
		constexpr bool get_quit_policy_type()
		{
			static_assert(std::is_same_v<PolicyType, window_default_t> || std::is_same_v<PolicyType, window_quit_process_t>);
			if constexpr (std::is_same_v<PolicyType, window_quit_process_t>)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		template <typename ClassType, bool = detect_process_quit_policy_v<ClassType>>
		struct process_quit_policy_or_default
		{
			using policy = window_default_t;
			inline static constexpr bool value{ false };
		};

		template <typename ClassType>
		struct process_quit_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::quit_process_policy;
			inline static constexpr const bool value{ get_quit_policy_type<typename ClassType::quit_process_policy>() };
		};

		template <typename ClassType>
		using process_quit_policy_t = typename process_quit_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const bool process_quit_policy_v = process_quit_policy_or_default<ClassType>::value;

		template <typename ClassType, typename = std::void_t<>>
		struct detect_default_nccreate_policy : std::false_type {};

		template <typename ClassType>
		struct detect_default_nccreate_policy<ClassType, std::void_t<typename ClassType::default_nccreate_policy>> : std::true_type {};

		template <typename ClassType>
		inline constexpr const bool detect_default_nccreate_policy_v = detect_default_nccreate_policy<ClassType>::value;

		template <typename PolicyType>
		constexpr bool get_nccreate_policy_type()
		{
			static_assert(std::is_same_v<PolicyType, window_default_t> || std::is_same_v<PolicyType, window_default_nccreate_t>);
			if constexpr (std::is_same_v<PolicyType, window_default_nccreate_t>)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		template <typename ClassType, bool = detect_default_nccreate_policy_v<ClassType>>
		struct default_nccreate_policy_or_default
		{
			using policy = window_default_t;
			inline static constexpr const bool value{ false };
		};

		template <typename ClassType>
		struct default_nccreate_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::default_nccreate_policy;
			inline static constexpr const bool value{ get_nccreate_policy_type<typename ClassType::default_nccreate_policy>() };
		};

		template <typename ClassType>
		using default_nccreate_policy_t = typename default_nccreate_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const bool default_nccreate_policy_v = default_nccreate_policy_or_default<ClassType>::value;

		enum class window_charset_value
		{
			unicode,
			ansi
		};

		template <bool PolicyDefault>
		inline constexpr window_charset_value get_charset_policy_type_from_default()
		{
			if constexpr (PolicyDefault)
			{
				return window_charset_value::unicode;
			}
			else
			{
				return window_charset_value::ansi;
			}
		}
		template <typename PolicyType>
		inline constexpr window_charset_value get_charset_policy_type_from_policy()
		{
			static_assert(std::is_same_v<PolicyType, window_unicode_t> || std::is_same_v<PolicyType, window_ansi_t>);
			if constexpr (std::is_same_v<PolicyType, window_unicode_t>)
			{
				return window_charset_value::unicode;
			}
			else
			{
				return window_charset_value::ansi;
			}
		}
		template <window_charset_value CharsetValue>
		inline constexpr bool get_charset_policy_bool_from_value()
		{
			if constexpr (CharsetValue == window_charset_value::unicode)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		template <typename ClassType, typename = std::void_t<>>
		struct detect_window_charset_policy : std::false_type {};

		template <typename ClassType>
		struct detect_window_charset_policy<ClassType, std::void_t<typename ClassType::window_charset_policy>> : std::true_type {};

		template <typename ClassType>
		inline constexpr const bool detect_window_charset_policy_v = detect_window_charset_policy<ClassType>::value;

		template <typename ClassType, bool = detect_window_charset_policy_v<ClassType>>
		struct window_charset_policy_or_default
		{
			//If window_charset_policy is not detected in the class, then we use the default based upon the UNICODE definition.
			using policy = std::conditional_t<window_default_unicode, window_unicode_t, window_ansi_t>;
			inline static constexpr const window_charset_value value{ get_charset_policy_type_from_default<window_default_unicode>() };
		};

		template <typename ClassType>
		struct window_charset_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::window_charset_policy;
			inline static constexpr const window_charset_value value{ get_charset_policy_type_from_policy<typename ClassType::window_charset_policy>() };
		};

		template <typename ClassType>
		using window_charset_policy_t = typename window_charset_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const window_charset_value window_charset_policy_v = window_charset_policy_or_default<ClassType>::value;
	}

	template<typename DerivedType, bool CustomHandler = false, bool UnicodeBase = details::get_charset_policy_bool_from_value<details::window_charset_policy_v<DerivedType>>()>
	class window_t;

	namespace details
	{
		namespace class_detect
		{
			template <typename ClassType, typename = std::void_t<>>
			struct detect_class_definitions : std::false_type {};

			template <typename ClassType>
			struct detect_class_definitions<ClassType, std::void_t<windowing::class_definitions<ClassType>>> : std::true_type {};

			template <typename ClassType>
			inline constexpr const bool detect_class_definitions_v = detect_class_definitions<ClassType>::value;

			template <typename ClassType, typename = std::void_t<>>
			struct detect_class_definitions_typedef : std::false_type {};

			template <typename ClassType>
			struct detect_class_definitions_typedef<ClassType, std::void_t<typename ClassType::class_definitions>> : std::true_type {};

			template <typename ClassType>
			inline constexpr const bool detect_class_definitions_typedef_v{ detect_class_definitions_typedef<ClassType>::value };

			struct class_definition_types
			{
				template <typename T>
				using style_t = decltype(std::declval<T>().style);
				template <typename T>
				using class_extra_t = decltype(std::declval<T>().class_extra);
				template <typename T>
				using window_extra_t = decltype(std::declval<T>().window_extra);
				template <typename T>
				using instance_t = decltype(std::declval<T>().instance);
				template <typename T>
				using icon_t = decltype(std::declval<T>().icon);
				template <typename T>
				using cursor_t = decltype(std::declval<T>().cursor);
				template <typename T>
				using brush_t = decltype(std::declval<T>().brush);
				template <typename T>
				using menu_name_t = decltype(std::declval<T>().menu_name);
				template <typename T>
				using class_name_t = decltype(std::declval<T>().class_name);
				template <typename T>
				using small_icon_t = decltype(std::declval<T>().icon);
				template <typename T>
				using existing_class_name_t = decltype(std::declval<T>().existing_class_name);
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::style_t>>
			struct style_value
			{
				static uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct style_value<T, true>
			{
				using style_t = typename class_definition_types::style_t<T>;

				static uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<style_t>>);
					return T::style;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::class_extra_t>>
			struct class_extra_value
			{
				static int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct class_extra_value<T, true>
			{
				using class_extra_t = typename class_definition_types::class_extra_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<class_extra_t>>);
					return T::class_extra;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::window_extra_t>>
			struct window_extra_value
			{
				static int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct window_extra_value<T, true>
			{
				using window_extra_t = typename class_definition_types::window_extra_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<window_extra_t>>);
					return T::window_extra;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::instance_t>>
			struct instance_value
			{
				static HINSTANCE get_value()
				{
					using utility::conversion::handle_cast;
					//Return the executable's HINSTANCE.
					return handle_cast<HINSTANCE>(GetModuleHandleW(nullptr));
				}
			};

			template <typename T>
			struct instance_value<T, true>
			{
				using instance_t = typename class_definition_types::instance_t<T>;

				static HINSTANCE get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<instance_t>, HINSTANCE>);
					return T::instance;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::icon_t>>
			struct icon_value
			{
				static HICON get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct icon_value<T, true>
			{
				using icon_t = typename class_definition_types::icon_t<T>;

				static HICON get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<icon_t>, HICON>);
					return T::icon;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::cursor_t>>
			struct cursor_value
			{
				static HCURSOR get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct cursor_value<T, true>
			{
				using cursor_t = typename class_definition_types::cursor_t<T>;

				static HCURSOR get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<cursor_t>, HCURSOR>);
					return T::cursor;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::brush_t>>
			struct brush_value
			{
				static HBRUSH get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct brush_value<T, true>
			{
				using brush_t = typename class_definition_types::brush_t<T>;

				static HBRUSH get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<brush_t>, HBRUSH>);
					return T::brush;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::menu_name_t>>
			struct menu_name_value
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_t::my_traits_t;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const typename traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct menu_name_value<T, true>
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_type::traits;
				enum class string_return_type
				{
					unknown,
					c_style,
					basic_string,
					basic_string_view
				};
				template <typename VT>
				static constexpr string_return_type detect_string_type()
				{
					if constexpr (std::is_array_v<VT>)
					{
						if constexpr (std::is_same_v<std::remove_const_t<std::remove_all_extents_t<VT>>, typename traits::char_t>)
						{
							return string_return_type::c_style;
						}
						else
						{
							constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
						}
					}
					else
					{
						if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string<typename traits::char_t>>)
						{
							return string_return_type::basic_string;
						}
						else
						{
							if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string_view<typename traits::char_t>>)
							{
								return string_return_type::basic_string_view;
							}
							else
							{
								constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
							}
						}
					}
				}
				using menu_name_t = typename class_definition_types::menu_name_t<T>;

				static const typename traits::char_t *get_value()
				{
					constexpr auto ret_type{ detect_string_type<menu_name_t>() };
					if constexpr (ret_type == string_return_type::c_style)
					{
						return T::menu_name;
					}
					else
					{
						if constexpr (ret_type == string_return_type::basic_string || ret_type == string_return_type::basic_string_view)
						{
							return T::menu_name.data();
						}
					}
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::class_name_t>>
			struct class_name_value
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_type::traits;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const typename traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct class_name_value<T, true>
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_type::traits;
				enum class string_return_type
				{
					unknown,
					c_style,
					basic_string,
					basic_string_view
				};
				template <typename VT>
				static constexpr string_return_type detect_string_type()
				{
					if constexpr (std::is_array_v<VT>)
					{
						if constexpr (std::is_same_v<std::remove_const_t<std::remove_all_extents_t<VT>>, typename traits::char_t>)
						{
							return string_return_type::c_style;
						}
						else
						{
							constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
						}
					}
					else
					{
						if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string<typename traits::char_t>>)
						{
							return string_return_type::basic_string;
						}
						else
						{
							if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string_view<typename traits::char_t>>)
							{
								return string_return_type::basic_string_view;
							}
							else
							{
								constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
							}
						}
					}
				}
				using class_name_t = typename class_definition_types::class_name_t<T>;

				static const typename traits::char_t *get_value()
				{
					constexpr auto ret_type{ detect_string_type<class_name_t>() };
					if constexpr (ret_type == string_return_type::c_style)
					{
						return T::class_name;
					}
					else
					{
						if constexpr (ret_type == string_return_type::basic_string || ret_type == string_return_type::basic_string_view)
						{
							return T::class_name.data();
						}
					}
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::small_icon_t>>
			struct small_icon_value
			{
				static HICON get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct small_icon_value<T, true>
			{
				using small_icon_t = typename class_definition_types::small_icon_t<T>;

				static HICON get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<small_icon_t>, HICON>);
					return T::small_icon;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::existing_class_name_t>>
			struct existing_class_name_value
			{
				static bool get_value()
				{
					return false;
				}
			};

			template <typename T>
			struct existing_class_name_value<T, true>
			{
				using existing_class_name_t = typename class_definition_types::existing_class_name_t<T>;

				static bool get_value()
				{
					static_assert(std::is_convertible_v<std::remove_const_t<existing_class_name_t>, bool>);
					return T::existing_class_name;
				}
			};
		}

		namespace window_detect
		{
			template <typename ClassType, typename = std::void_t<>>
			struct detect_window_definitions : std::false_type {};

			template <typename ClassType>
			struct detect_window_definitions<ClassType, std::void_t<windowing::window_definitions<ClassType>>> : std::true_type {};

			template <typename ClassType>
			inline constexpr const bool detect_window_definitions_v{ detect_window_definitions<ClassType>::value };

			template <typename ClassType, typename = std::void_t<>>
			struct detect_window_definitions_typedef : std::false_type {};

			template <typename ClassType>
			struct detect_window_definitions_typedef<ClassType, std::void_t<typename ClassType::window_definitions>> : std::true_type {};

			template <typename ClassType>
			inline constexpr const bool detect_window_definitions_typedef_v{ detect_window_definitions_typedef<ClassType>::value };

			struct window_definition_types
			{
				template <typename T>
				using style_t = decltype(std::declval<T>().style);
				template <typename T>
				using ex_style_t = decltype(std::declval<T>().ex_style);
				template <typename T>
				using window_name_t = decltype(std::declval<T>().window_name);
				template <typename T>
				using x_t = decltype(std::declval<T>().x);
				template <typename T>
				using y_t = decltype(std::declval<T>().y);
				template <typename T>
				using width_t = decltype(std::declval<T>().width);
				template <typename T>
				using height_t = decltype(std::declval<T>().height);
				template <typename T>
				using position_t = decltype(std::declval<T>().position);
				template <typename T>
				using size_t = decltype(std::declval<T>().size);
				template <typename T>
				using parent_t = decltype(std::declval<T>().parent);
				template <typename T>
				using menu_t = decltype(std::declval<T>().menu);
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::style_t>>
			struct style_value
			{
				static uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct style_value<T, true>
			{
				using style_t = typename window_definition_types::style_t<T>;

				static uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<style_t>>);
					return T::style;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::ex_style_t>>
			struct ex_style_value
			{
				static uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct ex_style_value<T, true>
			{
				using ex_style_t = typename window_definition_types::ex_style_t<T>;

				static uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<ex_style_t>>);
					return T::ex_style;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::window_name_t>>
			struct window_name_value
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_type::traits;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const typename traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct window_name_value<T, true>
			{
				//T::window_type must be defined.
				//This will be defined as the most derived type.
				//traits is public, so the definition can be obtained
				//through the window type name.
				using traits = typename T::window_type::traits;
				enum class string_return_type
				{
					unknown,
					c_style,
					basic_string,
					basic_string_view
				};
				template <typename VT>
				static constexpr string_return_type detect_string_type()
				{
					if constexpr (std::is_array_v<VT>)
					{
						if constexpr (std::is_same_v<std::remove_const_t<std::remove_all_extents_t<VT>>, typename traits::char_t>)
						{
							return string_return_type::c_style;
						}
						else
						{
							constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
						}
					}
					else
					{
						if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string<typename traits::char_t>>)
						{
							return string_return_type::basic_string;
						}
						else
						{
							if constexpr (std::is_same_v<std::remove_const_t<VT>, std::basic_string_view<typename traits::char_t>>)
							{
								return string_return_type::basic_string_view;
							}
							else
							{
								constexpr auto v{ static_assert_wrapper<VT>::template_not_specialised };
							}
						}
					}
				}
				using window_name_t = typename window_definition_types::window_name_t<T>;

				static const typename traits::char_t *get_value()
				{
					constexpr auto ret_type{ detect_string_type<window_name_t>() };
					if constexpr (ret_type == string_return_type::c_style)
					{
						return T::window_name;
					}
					else
					{
						if constexpr (ret_type == string_return_type::basic_string || ret_type == string_return_type::basic_string_view)
						{
							return T::window_name.data();
						}
					}
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::x_t>>
			struct x_value
			{
				static int32_t get_value()
				{
					return CW_USEDEFAULT;
				}
			};

			template <typename T>
			struct x_value<T, true>
			{
				using x_t = typename window_definition_types::x_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<x_t>>);
					return T::x;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::y_t>>
			struct y_value
			{
				static int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct y_value<T, true>
			{
				using y_t = typename window_definition_types::y_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<y_t>>);
					return T::y;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::width_t>>
			struct width_value
			{
				static int32_t get_value()
				{
					return CW_USEDEFAULT;
				}
			};

			template <typename T>
			struct width_value<T, true>
			{
				using width_t = typename window_definition_types::width_t<T>;

				static uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<width_t>>);
					return T::width;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::height_t>>
			struct height_value
			{
				static int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct height_value<T, true>
			{
				using height_t = typename window_definition_types::height_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<height_t>>);
					return T::height;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::position_t>>
			struct position_value
			{
				static POINT get_value()
				{
					return {CW_USEDEFAULT, 0};
				}
			};

			template <typename T>
			struct position_value<T, true>
			{
				using position_t = typename window_definition_types::position_t<T>;

				static POINT get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<position_t>, POINT>);
					return T::position;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::size_t>>
			struct size_value
			{
				static SIZE get_value()
				{
					return { CW_USEDEFAULT, 0 };
				}
			};

			template <typename T>
			struct size_value<T, true>
			{
				using size_t = typename window_definition_types::size_t<T>;

				static SIZE get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<size_t>, SIZE>);
					return T::size;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::parent_t>>
			struct parent_value
			{
				static HWND get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct parent_value<T, true>
			{
				using parent_t = typename window_definition_types::parent_t<T>;

				static HWND get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<parent_t>, HWND>);
					return T::parent;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::menu_t>>
			struct menu_value_nonchild
			{
				static HMENU get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct menu_value_nonchild<T, true>
			{
				using menu_t = typename window_definition_types::menu_t<T>;

				static HMENU get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<menu_t>, HMENU>);
					return T::menu;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::menu_t>>
			struct menu_value_child
			{
				static int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct menu_value_child<T, true>
			{
				using menu_t = typename window_definition_types::menu_t<T>;

				static int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<menu_t>>);
					return T::menu;
				}
			};
		}
	}

	enum class handler_type
	{
		unknown,
		control,
		menu,
		accelerator
	};

	using command_handler_fun = void(HWND);
	using syscommand_handler_fun = void(syscommand_info, int32_t, int32_t);
	using notify_handler_fun = LRESULT(const NMHDR &);
	using appcommand_handler_fun = void(appcommand_info, int32_t, int32_t);

	struct command_handler_entry
	{
		handler_type type;
		uint16_t identifier;
		uint16_t notification;
		std::function<command_handler_fun> command_handler;
	};
	struct syscommand_handler_entry
	{
		syscommand_request request;
		std::function<syscommand_handler_fun> syscommand_handler;
	};
	struct notify_handler_entry
	{
		uintptr_t identifier;
		uint32_t notification;
		std::function<notify_handler_fun> notify_handler;
	};
	struct appcommand_handler_entry
	{
		appcommand_command command;
		std::function<appcommand_handler_fun> appcommand_handler;
	};

	struct command_handler_list
	{
		std::vector<command_handler_entry> command_handlers;
		std::vector<syscommand_handler_entry> syscommand_handlers;
		std::vector<notify_handler_entry> notify_handlers;
		std::vector<appcommand_handler_entry> appcommand_handlers;
	};

	template<typename DerivedType>
	struct window_post_quit_policy
	{
		static void post_quit_message(int exit_code)
		{
			if constexpr (details::process_quit_policy_v<DerivedType>)
			{
				PostQuitMessage(exit_code);
			}
		}
	};

	template<typename DerivedType, bool UnicodeBase>
	struct window_default_nccreate_policy
	{
		static LRESULT call_defwindowproc_nccreate(HWND wnd, WPARAM wparam, LPARAM lparam)
		{
			if constexpr (details::default_nccreate_policy_v<DerivedType>)
			{
				return choose_window_traits_t<UnicodeBase>::WndDefWindowProc(wnd, WM_NCCREATE, wparam, lparam);
			}
			else
			{
				return TRUE;
			}
		}
	};

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	class track_mouse_policy
	{
	public:
		bool is_mouse_in_window() const
		{
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track ||
				details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				return m_mouse_in_window;
			}
			else
			{
				return false;
			}
		}
		bool is_mouse_in_nclient() const
		{
			return m_mouse_in_nclient;
		}
		bool is_mouse_in_client() const
		{
			return m_mouse_in_client;
		}
		bool is_first_mouse_message() const
		{
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track ||
				details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				return m_first_mouse_message;
			}
			else
			{
				return false;
			}
		}
	protected:
		void track_mouse()
		{
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track ||
				details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				//GetCurrentThreadId is used because this will be called during the WM_NCCREATE message handler.
				//This is one of the messages that Windows will send during the CreateWindowEx call, so this
				//handler will only ever run on the thread that created the window.
				HHOOK hook_mh{ choose_window_traits_t<UnicodeBase>::WndSetWindowsHookEx(WH_MOUSE, my_type::mh_hook, nullptr, GetCurrentThreadId()) };
				HHOOK hook_gm{ choose_window_traits_t<UnicodeBase>::WndSetWindowsHookEx(WH_GETMESSAGE, my_type::gm_hook, nullptr, GetCurrentThreadId()) };

				m_hook_data.gm = hook_gm;
				m_hook_data.mh = hook_mh;

				m_registered_for_tracking = true;
			}
		}
		void untrack_mouse()
		{
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track ||
				details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				m_registered_for_tracking = false;
				UnhookWindowsHookEx(m_hook_data.mh);
				UnhookWindowsHookEx(m_hook_data.gm);
				m_hook_data = {};
			}
		}
		bool tracking()
		{
			return m_registered_for_tracking;
		}
	private:
		using my_t = DerivedType;
		using my_type = track_mouse_policy<DerivedType, CustomHandler, UnicodeBase>;
		using derived_type = window_t<DerivedType, CustomHandler, UnicodeBase>;

		struct hook_data
		{
			HHOOK mh{};
			HHOOK gm{};
		};

		BOOL track_mouse(HWND wnd, bool nc)
		{
			TRACKMOUSEEVENT tme{ sizeof(TRACKMOUSEEVENT), TME_HOVER | TME_LEAVE | (nc == true ? TME_NONCLIENT : 0U), wnd, HOVER_DEFAULT };
			return TrackMouseEvent(&tme);
		}

		void handle_mouse_message(HWND wnd, UINT msg, MOUSEHOOKSTRUCTEX &)
		{
			if ((m_mouse_in_window == true) && (m_first_mouse_message == true))
			{
				m_first_mouse_message = false;
			}
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track)
			{
				if ((msg >= WM_MOUSEFIRST) && (msg <= WM_MOUSELAST) && (m_mouse_in_window == false))
				{
					m_mouse_in_window = true;
					m_mouse_in_client = true;
					m_first_mouse_message = true;
					auto result{ track_mouse(wnd, false) };
					_ASSERTE(result != FALSE);
					if (!result)
					{
						output_helpers::debug::format_debugwriteln(L"TrackMouseEvent failed");
						__fastfail(ERROR_FATAL_APP_EXIT);
					}
				}
			}

			if constexpr (details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				if ((msg >= WM_NCMOUSEMOVE) && (msg <= WM_NCXBUTTONDBLCLK) && (m_mouse_in_window == false))
				{
					m_mouse_in_window = true;
					m_mouse_in_nclient = true;
					m_first_mouse_message = true;
					auto result{ track_mouse(wnd, true) };
					_ASSERTE(result != FALSE);
					if (!result)
					{
						output_helpers::debug::format_debugwriteln(L"TrackMouseEvent failed");
						__fastfail(ERROR_FATAL_APP_EXIT);
					}
				}
			}
		}
		void handle_mouse_hover(HWND wnd)
		{
			//The documentation for WM_MOUSEHOVER and WM_NCMOUSEHOVER states that hover tracking
			//stops after a hover message is sent. Since we want to keep getting these messages
			//we need to re-enable it.
			_ASSERTE((m_mouse_in_window == true) && (m_mouse_in_client == true));
			auto result{ track_mouse(wnd, false) };
			_ASSERTE(result != FALSE);
			if (!result)
			{
				output_helpers::debug::format_debugwriteln(L"TrackMouseEvent failed");
				__fastfail(ERROR_FATAL_APP_EXIT);
			}
		}
		void handle_ncmouse_hover(HWND wnd)
		{
			//The documentation for WM_MOUSEHOVER and WM_NCMOUSEHOVER states that hover tracking
			//stops after a hover message is sent. Since we want to keep getting these messages
			//we need to re-enable it.
			_ASSERTE((m_mouse_in_window == true) && (m_mouse_in_nclient == true));
			auto result{ track_mouse(wnd, true) };
			_ASSERTE(result != FALSE);
			if (!result)
			{
				output_helpers::debug::format_debugwriteln(L"TrackMouseEvent failed");
				__fastfail(ERROR_FATAL_APP_EXIT);
			}
		}

		void handle_mouse_leave(HWND)
		{
			m_mouse_in_client = false;
			m_mouse_in_window = false;
			//Just in case we somehow manage to get a mouse message followed by an immediate leave
			m_first_mouse_message = false;
		}

		void handle_ncmouse_leave(HWND)
		{
			m_mouse_in_nclient = false;
			m_mouse_in_window = false;
			//Just in case we somehow manage to get a mouse message followed by an immediate leave
			m_first_mouse_message = false;
		}

		std::atomic_bool m_mouse_in_window{ false };
		std::atomic_bool m_mouse_in_nclient{ false };
		std::atomic_bool m_mouse_in_client{ false };
		std::atomic_bool m_first_mouse_message{ false };

		hook_data m_hook_data{};
		std::atomic_bool m_registered_for_tracking{ false };

		static my_type *instance_from_handle(HWND wnd)
		{
			using utility::conversion::up_cast;

			auto v{ my_t::inst_from_handle(wnd) };
			if (v != nullptr)
			{
				//v will be set to DerivedType *, we want to cast to
				//window_t<DerivedType> * and then to this type.
				my_type *that{ up_cast<my_type>(up_cast<derived_type>(v)) };

				return that;
			}
			return nullptr;
		}

		static LRESULT CALLBACK gm_hook(_In_ int code, _In_ WPARAM wparam, _In_ LPARAM lparam)
		{
			using utility::conversion::reference_from_param;

			if (code < 0)
			{
				return CallNextHookEx(nullptr, code, wparam, lparam);
			}

			MSG &msg{ reference_from_param<MSG>(lparam) };
			if (msg.hwnd != nullptr)
			{
				my_type *that{ my_type::instance_from_handle(msg.hwnd) };
				if (that == nullptr || !that->tracking())
				{
					return CallNextHookEx(nullptr, code, wparam, lparam);
				}
				else
				{
					if (msg.message == WM_MOUSELEAVE)
					{
						that->handle_mouse_leave(msg.hwnd);
					}
					if (msg.message == WM_NCMOUSELEAVE)
					{
						that->handle_ncmouse_leave(msg.hwnd);
					}
					if (msg.message == WM_MOUSEHOVER)
					{
						that->handle_mouse_hover(msg.hwnd);
					}
					if (msg.message == WM_NCMOUSEHOVER)
					{
						that->handle_ncmouse_hover(msg.hwnd);
					}
					return CallNextHookEx(nullptr, code, wparam, lparam);
				}
			}
			return CallNextHookEx(nullptr, code, wparam, lparam);
		}

		static LRESULT CALLBACK mh_hook(_In_ int code, _In_ WPARAM wparam, _In_ LPARAM lparam)
		{
			using utility::conversion::reference_from_param;
			using utility::conversion::value_convert;

			if (code < 0)
			{
				return CallNextHookEx(nullptr, code, wparam, lparam);
			}

			MOUSEHOOKSTRUCTEX &mh_struct{ reference_from_param<MOUSEHOOKSTRUCTEX>(lparam) };
			if (mh_struct.hwnd != nullptr)
			{
				my_type *that{ my_type::instance_from_handle(mh_struct.hwnd) };
				if (that == nullptr || !that->tracking())
				{
					return CallNextHookEx(nullptr, code, wparam, lparam);
				}
				else
				{
					if (code == HC_ACTION)
					{
						that->handle_mouse_message(mh_struct.hwnd, value_convert<UINT>(wparam), mh_struct);
					}
					
					return CallNextHookEx(nullptr, code, wparam, lparam);
				}
			}
			return CallNextHookEx(nullptr, code, wparam, lparam);
		}
	};

	namespace details
	{
		template <typename Traits>
		struct window_msg_types
		{
			using traits = Traits;
			//0000 - WM_NULL
			//0001
			template <typename T>
			using on_create_t = decltype(std::declval<T>().on_create(std::declval<const typename traits::create_struct_t &>()));
			//0002
			template <typename T>
			using on_destroy_t = decltype(std::declval<T>().on_destroy());
			//0003
			template <typename T>
			using on_move_t = decltype(std::declval<T>().on_move(std::declval<int32_t>(), std::declval<int32_t>()));
			//0004 - none
			//0005
			template <typename T>
			using on_size_t = decltype(std::declval<T>().on_size(std::declval<resize_type>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0006
			template <typename T>
			using on_activate_t = decltype(std::declval<T>().on_activate(std::declval<activate_type>(), std::declval<bool>(), std::declval<HWND>()));
			//0007
			template <typename T>
			using on_setfocus_t = decltype(std::declval<T>().on_setfocus(std::declval<HWND>()));
			//0008
			template <typename T>
			using on_killfocus_t = decltype(std::declval<T>().on_killfocus(std::declval<HWND>()));
			//0009 - none
			//000a
			template <typename T>
			using on_enable_t = decltype(std::declval<T>().on_enable(std::declval<bool>()));
			//000b
			template <typename T>
			using on_setredraw_t = decltype(std::declval<T>().on_setredraw(std::declval<bool>()));
			//000c
			template <typename T>
			using on_settext_t = decltype(std::declval<T>().on_settext(std::declval<const typename traits::char_t *>()));
			//000d
			template <typename T>
			using on_gettext_t = decltype(std::declval<T>().on_gettext(std::declval<uintptr_t>(), std::declval<typename traits::char_t *>()));
			//000e
			template <typename T>
			using on_gettextlength_t = decltype(std::declval<T>().on_gettextlength()); //uintptr_t return
			//000f
			//The version that is called depends on if the simple paint policy is defined.
			//If it is, the paint handler will call BeginPaint and EndPaint automatically.
			template <typename T>
			using simple_on_paint_t = decltype(std::declval<T>().on_paint(std::declval<const PAINTSTRUCT &>()));
			template <typename T>
			using default_on_paint_t = decltype(std::declval<T>().on_paint());
			//0010
			template <typename T>
			using on_close_t = decltype(std::declval<T>().on_close());
			//0011
			template <typename T>
			using on_queryendsession_t = decltype(std::declval<T>().on_queryendsession(std::declval<endsession_reason>())); //bool return
			//0012 WM_QUIT
			//0013
			template <typename T>
			using on_queryopen_t = decltype(std::declval<T>().on_queryopen()); //bool return
			//0014
			template <typename T>
			using on_erasebkgnd_t = decltype(std::declval<T>().on_erasebkgnd(std::declval<HDC>())); //bool return
			//0015
			template <typename T>
			using on_syscolorchange_t = decltype(std::declval<T>().on_syscolorchange());
			//0016
			template <typename T>
			using on_endsession_t = decltype(std::declval<T>().on_endsession(std::declval<bool>(), std::declval<endsession_reason>()));
			//0017 - none
			//0018
			template <typename T>
			using on_showwindow_t = decltype(std::declval<T>().on_showwindow(std::declval<bool>(), std::declval<showwindow_reason>()));
			//0019 - none
			//001a
			template <typename T>
			using on_settingchange_t = decltype(std::declval<T>().on_settingchange(std::declval<uint32_t>(), std::declval<const typename traits::char_t *>()));
			//001b
			template <typename T>
			using on_devmodechange_t = decltype(std::declval<T>().on_devmodechange(std::declval<const typename traits::char_t *>()));
			//001c
			template <typename T>
			using on_activateapp_t = decltype(std::declval<T>().on_activateapp(std::declval<bool>(), std::declval<uint32_t>()));
			//001d
			template <typename T>
			using on_fontchange_t = decltype(std::declval<T>().on_fontchange());
			//001e
			template <typename T>
			using on_timechange_t = decltype(std::declval<T>().on_timechange());
			//001f
			template <typename T>
			using on_cancelmode_t = decltype(std::declval<T>().on_cancelmode());
			//0020
			template <typename T>
			using on_setcursor_t = decltype(std::declval<T>().on_setcursor(std::declval<HWND>(), std::declval<hittest_position>(), std::declval<uint32_t>())); //bool return
			//0021
			template <typename T>
			using on_mouseactivate_t = decltype(std::declval<T>().on_mouseactivate(std::declval<HWND>(), std::declval<hittest_position>(), std::declval<uint32_t>())); //mouse_activate_type return
			//0022
			template <typename T>
			using on_childactivate_t = decltype(std::declval<T>().on_childactivate());
			//0023
			template <typename T>
			using on_queuesync_t = decltype(std::declval<T>().on_queuesync());
			//0024
			template <typename T>
			using on_getminmaxinfo_t = decltype(std::declval<T>().on_getminmaxinfo(std::declval<MINMAXINFO &>()));
			//0025 - none
			//0026 - WM_PAINTICON (not supported for versions 4 and newer)
			//0027 - WM_ICONERASEBKGND (not supported for versions 4 and newer)
			//0028
			template <typename T>
			using on_nextdlgctl_t = decltype(std::declval<T>().on_nextdlgctl(std::declval<next_dlg_ctl_params &>(), std::declval<bool>()));
			//0029 - none
			//002a - WM_SPOOLERSTATUS (not supported for XP and newer)
			//002b
			template <typename T>
			using on_drawitem_t = decltype(std::declval<T>().on_drawitem(std::declval<uint32_t>(), std::declval<const DRAWITEMSTRUCT &>())); //true return value, void type
			//002c
			template <typename T>
			using on_measureitem_t = decltype(std::declval<T>().on_measureitem(std::declval<uint32_t>(), std::declval<const MEASUREITEMSTRUCT &>())); //true return value, void type
			//002d
			template <typename T>
			using on_deleteitem_t = decltype(std::declval<T>().on_deleteitem(std::declval<uint32_t>(), std::declval<const DELETEITEMSTRUCT &>())); //true return value, void type
			//002e
			template <typename T>
			using on_vkeytoitem_t = decltype(std::declval<T>().on_vkeytoitem(std::declval<uint16_t>(), std::declval<uint16_t>(), std::declval<HWND>())); //int32_t return
			//002f
			template <typename T>
			using on_chartoitem_t = decltype(std::declval<T>().on_chartoitem(std::declval<typename traits::char_t>(), std::declval<uint16_t>(), std::declval<HWND>())); //int32_t return
			//0030
			template <typename T>
			using on_setfont_t = decltype(std::declval<T>().on_setfont(std::declval<HFONT>(), std::declval<bool>()));
			//0031
			template <typename T>
			using on_getfont_t = decltype(std::declval<T>().on_getfont()); //HFONT return
			//0032
			template <typename T>
			using on_sethotkey_t = decltype(std::declval<T>().on_sethotkey(std::declval<const hot_key_value &>())); //set_hot_key_result return
			//0033
			template <typename T>
			using on_gethotkey_t = decltype(std::declval<T>().on_gethotkey()); //hot_key_value return
			//0034 - 0036 - none
			//0037
			template <typename T>
			using on_querydragicon_t = decltype(std::declval<T>().on_querydragicon()); //HICON return, this is shared between icon and cursor and can contain either
			//0038 - none
			//0039
			template <typename T>
			using on_compareitem_t = decltype(std::declval<T>().on_compareitem(std::declval<uint32_t>(), std::declval<const COMPAREITEMSTRUCT &>())); //compare_item_result return
			//003a - 003c - none
			//003d
			template <typename T>
			using on_getobject_t = decltype(std::declval<T>().on_getobject(std::declval<uint32_t>(), std::declval<uint32_t>())); //LRESULT return
			//003e - 0040 - none
			//0041 - WM_COMPACTING (16 bit compatibility)
			//0042, 0043 - none
			//0044 - WM_COMMNOTIFY (unsupported message)
			//0045 - none
			//0046
			template <typename T>
			using on_windowposchanging_t = decltype(std::declval<T>().on_windowposchanging(std::declval<WINDOWPOS &>()));
			//0047
			template <typename T>
			using on_windowposchanged_t = decltype(std::declval<T>().on_windowposchanged(std::declval<const WINDOWPOS &>()));
			//0048 - WM_POWER (16 bit compatibility)
			//0049 - none
			//004a
			template <typename T>
			using on_copydata_t = decltype(std::declval<T>.on_copydata(std::declval<HWND>(), std::declval<const COPYDATASTRUCT &>())); //bool return
			//004b - WM_CANCELJOURNAL - (this is a thread message)
			//004c - 004d - none
			//004e
			template <typename T>
			using on_notify_t = decltype(std::declval<T>().on_notify(std::declval<uint32_t>(), std::declval<NMHDR &>())); //LRESULT return
			//004f - none
			//0050
			//this message requires DefWindowProc to be called to accept the change and a return of 0 if it fails,
			//if the handler returns true then it will call DefWindowProc, if it returns false then it will return 0
			template <typename T>
			using on_inputlangchangerequest_t = decltype(std::declval<T>().on_inputlangchangerequest(std::declval<input_language_change_flags>(), std::declval<uint32_t>())); //bool return
			//0051
			template <typename T>
			using on_inputlangchange_t = decltype(std::declval<T>().on_inputlangchange(std::declval<input_language_character_set>(), std::declval<uint16_t>(), std::declval<HKL>()));
			//0052
			template <typename T>
			using on_tcard_t = decltype(std::declval<T>().on_tcard(std::declval<uint32_t>(), std::declval<uint32_t>()));
			//0053
			template <typename T>
			using on_help_t = decltype(std::declval<T>().on_help(std::declval<const HELPINFO &>())); //void return, but true must be returned
			//0054 - WM_USERCHANGED (unsupported from Vista)
			//0055
			template <typename T>
			using on_notifyformat_t = decltype(std::declval<T>().on_notifyformat(std::declval<HWND>(), std::declval<notify_format_type>())); //notify_format_result return
			//0056 - 007a - none
			//007b
			template <typename T>
			using on_contextmenu_t = decltype(std::declval<T>().on_contextmenu(std::declval<HWND>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//007c
			template <typename T>
			using on_stylechanging_t = decltype(std::declval<T>().on_stylechanging(std::declval<style_changing_type>(), std::declval<STYLESTRUCT &>()));
			//007d
			template <typename T>
			using on_stylechanged_t = decltype(std::declval<T>().on_stylechanged(std::declval<style_changing_type>(), std::declval<const STYLESTRUCT &>()));
			//007e
			template <typename T>
			using on_displaychange_t = decltype(std::declval<T>().on_displaychange(std::declval<uint32_t>(), std::declval<uint16_t>(), std::declval<uint16_t>()));
			//007f
			template <typename T>
			using on_geticon_t = decltype(std::declval<T>().on_geticon(std::declval<icon_type>(), std::declval<uint32_t>())); //HICON return
			//0080
			template <typename T>
			using on_seticon_t = decltype(std::declval<T>().on_seticon(std::declval<icon_type>(), std::declval<HICON>())); //HICON return
			//0081
			template <typename T>
			using on_nccreate_t = decltype(std::declval<T>().on_nccreate(std::declval<const typename traits::create_struct_t &>()));
			//0082
			template <typename T>
			using on_ncdestroy_t = decltype(std::declval<T>().on_ncdestroy());
			//0083
			template <typename T>
			using on_nccalcsize_t = decltype(std::declval<T>().on_nccalcsize(std::declval<bool>(), std::declval<nccalcsize_params &>())); //nccalcsize_return return
			//0084
			template <typename T>
			using on_nchittest_t = decltype(std::declval<T>().on_nchittest(std::declval<int32_t>(), std::declval<int32_t>())); //hittest_position return
			//0085
			template <typename T>
			using on_ncpaint_t = decltype(std::declval<T>().on_ncpaint(std::declval<HRGN>()));
			//0086
			template <typename T>
			using on_ncactivate_t = decltype(std::declval<T>().on_ncactivate(std::declval<bool>(), std::declval<HRGN>())); //bool return
			//0087
			template <typename T>
			using on_getdlgcode_t = decltype(std::declval<T>().on_getdlgcode(std::declval<virtual_key>(), std::declval<std::optional<std::reference_wrapper<MSG>>>())); // get_dlg_code_return
			//0088
			template <typename T>
			using on_syncpaint_t = decltype(std::declval<T>().on_syncpaint());
			//0089 - 009f
			//00a0
			template <typename T>
			using on_ncmousemove_t = decltype(std::declval<T>().on_ncmousemove(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a1
			template <typename T>
			using on_nclbuttondown_t = decltype(std::declval<T>().on_nclbuttondown(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a2
			template <typename T>
			using on_nclbuttonup_t = decltype(std::declval<T>().on_nclbuttonup(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a3
			template <typename T>
			using on_nclbuttondblclk_t = decltype(std::declval<T>().on_nclbuttondblclk(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a4
			template <typename T>
			using on_ncrbuttondown_t = decltype(std::declval<T>().on_ncrbuttondown(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a5
			template <typename T>
			using on_ncrbuttonup_t = decltype(std::declval<T>().on_ncrbuttonup(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a6
			template <typename T>
			using on_ncrbuttondblclk_t = decltype(std::declval<T>().on_ncrbuttondblclk(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a7
			template <typename T>
			using on_ncmbuttondown_t = decltype(std::declval<T>().on_ncmbuttondown(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a8
			template <typename T>
			using on_ncmbuttonup_t = decltype(std::declval<T>().on_ncmbuttonup(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00a9
			template <typename T>
			using on_ncmbuttondblclk_t = decltype(std::declval<T>().on_ncmbuttondblclk(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//00aa - none
			//00ab
			template <typename T>
			using on_ncxbuttondown_t = decltype(std::declval<T>().on_ncxbuttondown(std::declval<hittest_position>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, but true must be returned
			//00ac
			template <typename T>
			using on_ncxbuttonup_t = decltype(std::declval<T>().on_ncxbuttonup(std::declval<hittest_position>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, but true must be returned
			//00ad
			template <typename T>
			using on_ncxbuttondblclk_t = decltype(std::declval<T>().on_ncxbuttondblclk(std::declval<hittest_position>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, but true must be returned
			//00ae - 00fd - none
			//00fe
			template <typename T>
			using on_input_device_change_t = decltype(std::declval<T>().on_input_device_change(std::declval<input_dev_change_type>(), std::declval<HANDLE>()));
			//00ff
			template <typename T>
			using on_input_t = decltype(std::declval<T>().on_input(std::declval<input_type>(), std::declval<HRAWINPUT>()));
			//0100
			template <typename T>
			using on_keydown_t = decltype(std::declval<T>().on_keydown(std::declval<virtual_key>(), std::declval<const keystroke_data &>()));
			//0101
			template <typename T>
			using on_keyup_t = decltype(std::declval<T>().on_keyup(std::declval<virtual_key>(), std::declval<const keystroke_data &>()));
			//0102
			template <typename T>
			using on_char_t = decltype(std::declval<T>().on_char(std::declval<typename traits::char_t>(), std::declval<const keystroke_data &>()));
			//0103
			template <typename T>
			using on_deadchar_t = decltype(std::declval<T>().on_deadchar(std::declval<typename traits::char_t>(), std::declval<const keystroke_data &>()));
			//0104
			template <typename T>
			using on_syskeydown_t = decltype(std::declval<T>().on_syskeydown(std::declval<virtual_key>(), std::declval<const keystroke_data &>()));
			//0105
			template <typename T>
			using on_syskeyup_t = decltype(std::declval<T>().on_syskeyup(std::declval<virtual_key>(), std::declval<const keystroke_data &>()));
			//0106
			template <typename T>
			using on_syschar_t = decltype(std::declval<T>().on_syschar(std::declval<typename traits::char_t>(), std::declval<const keystroke_data &>()));
			//0107
			template <typename T>
			using on_sysdeadchar_t = decltype(std::declval<T>().on_sysdeadchar(std::declval<typename traits::char_t>(), std::declval<const keystroke_data &>()));
			//0108 - none
			//0109
			template <typename T>
			using on_unichar_t = decltype(std::declval<T>().on_unichar(std::declval<uint32_t>(), std::declval<const keystroke_data &>()));
			//010a - 010c - none
			//010d - WM_IME_STARTCOMPOSITION
			//010e - WM_IME_ENDCOMPOSITION - (Don't impletent IME messages for now)
			//010f - WM_IME_COMPOSITION - (Don't impletent IME messages for now)
			//0110 - conditionally supported for now
			template <typename T>
			using on_initdialog_t = decltype(std::declval<T>().on_initdialog(std::declval<HWND>(), std::declval<void *>())); //bool return
			//0111
			template <typename T>
			using on_command_t = decltype(std::declval<T>().on_command(std::declval<uint16_t>(), std::declval<uint16_t>(), std::declval<HWND>()));
			//0112
			template <typename T>
			using on_syscommand_t = decltype(std::declval<T>().on_syscommand(std::declval<syscommand_info>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0113
			template <typename T>
			using on_timer_t = decltype(std::declval<T>().on_timer(std::declval<uintptr_t>(), std::declval<TIMERPROC>()));
			//0114
			template <typename T>
			using on_hscroll_t = decltype(std::declval<T>().on_hscroll(std::declval<hscrollbar_request>(), std::declval<uint16_t>(), std::declval<HWND>()));
			//0115
			template <typename T>
			using on_vscroll_t = decltype(std::declval<T>().on_vscroll(std::declval<vscrollbar_request>(), std::declval<uint16_t>(), std::declval<HWND>()));
			//0116
			template <typename T>
			using on_initmenu_t = decltype(std::declval<T>().on_initmenu(std::declval<HMENU>()));
			//0117
			template <typename T>
			using on_initmenupopup_t = decltype(std::declval<T>().on_initmenupopup(std::declval<HMENU>(), std::declval<uint16_t>(), std::declval<bool>()));
			//0118 - none
			//0119
			template <typename T>
			using on_gesture_t = decltype(std::declval<T>().on_gesture(std::declval<uint64_t>(), std::declval<HGESTUREINFO>()));
			//011a
			template <typename T>
			using on_gesturenotify_t = decltype(std::declval<T>().on_gesturenotify(std::declval<const GESTURENOTIFYSTRUCT &>()));
			//011b - 011e - none
			//011f
			template <typename T>
			using on_menuselect_t = decltype(std::declval<T>().on_menuselect(std::declval<uint16_t>(), std::declval<menuselect_flags>(), std::declval<HMENU>()));
			//0120
			template <typename T>
			using on_menuchar_t = decltype(std::declval<T>().on_menuchar(std::declval<typename traits::char_t>(), std::declval<menuchar_flags>(), std::declval<HMENU>())); //menuchar_return return
			//0121
			template <typename T>
			using on_enteridle_t = decltype(std::declval<T>().on_enteridle(std::declval<enteridle_type>(), std::declval<enteridle_param &>()));
			//0122
			template <typename T>
			using on_menurbuttonup_t = decltype(std::declval<T>().on_menurbuttonup(std::declval<uint32_t>(), std::declval<HMENU>()));
			//0123
			template <typename T>
			using on_menudrag_t = decltype(std::declval<T>().on_menudrag(std::declval<uint32_t>(), std::declval<HMENU>())); //menudrag_return return
			//0124
			template <typename T>
			using on_menugetobject_t = decltype(std::declval<T>().on_menugetobject(std::declval<const MENUGETOBJECTINFO &>())); //menugetobjectinfo_return return
			//0125
			template <typename T>
			using on_uninitmenupopup_t = decltype(std::declval<T>().on_uninitmenupopup(std::declval<HMENU>())); //the high order word of lparam does contain a value, but this only supports a single value so we ignore it
			//0126
			template <typename T>
			using on_menucommand_t = decltype(std::declval<T>().on_menucommand(std::declval<uint32_t>(), std::declval<HMENU>()));
			//0127
			template <typename T>
			using on_changeuistate_t = decltype(std::declval<T>().on_changeuistate(std::declval<uistate_action>(), std::declval<uistate_style>()));
			//0128
			template <typename T>
			using on_updateuistate_t = decltype(std::declval<T>().on_updateuistate(std::declval<uistate_action>(), std::declval<uistate_style>()));
			//0129
			template <typename T>
			using on_queryuistate_t = decltype(std::declval<T>().on_queryuistate()); //uistate_style return
			//012a - 0131 - none
			//0132
			template <typename T>
			using on_ctlcolormsgbox_t = decltype(std::declval<T>().on_ctlcolormsgbox(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0133
			template <typename T>
			using on_ctlcoloredit_t = decltype(std::declval<T>().on_ctlcoloredit(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0134
			template <typename T>
			using on_ctlcolorlistbox_t = decltype(std::declval<T>().on_ctlcolorlistbox(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0135
			template <typename T>
			using on_ctlcolorbtn_t = decltype(std::declval<T>().on_ctlcolorbtn(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0136
			template <typename T>
			using on_ctlcolordlg_t = decltype(std::declval<T>().on_ctlcolordlg(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0137
			template <typename T>
			using on_ctlcolorscrollbar_t = decltype(std::declval<T>().on_ctlcolorscrollbar(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0138
			template <typename T>
			using on_ctlcolorstatic_t = decltype(std::declval<T>().on_ctlcolorstatic(std::declval<HDC>(), std::declval<HWND>())); //HBRUSH return
			//0139 - 01e0 - none
			//01e1
			template <typename T>
			using on_gethmenu_t = decltype(std::declval<T>().on_gethmenu()); //HMENU return
			//0200
			template <typename T>
			using on_mousemove_t = decltype(std::declval<T>().on_mousemove(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0201
			template <typename T>
			using on_lbuttondown_t = decltype(std::declval<T>().on_lbuttondown(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0202
			template <typename T>
			using on_lbuttonup_t = decltype(std::declval<T>().on_lbuttonup(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0203
			template <typename T>
			using on_lbuttondblclk_t = decltype(std::declval<T>().on_lbuttondblclk(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0204
			template <typename T>
			using on_rbuttondown_t = decltype(std::declval<T>().on_rbuttondown(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0205
			template <typename T>
			using on_rbuttonup_t = decltype(std::declval<T>().on_rbuttonup(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0206
			template <typename T>
			using on_rbuttondblclk_t = decltype(std::declval<T>().on_rbuttondblclk(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0207
			template <typename T>
			using on_mbuttondown_t = decltype(std::declval<T>().on_mbuttondown(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0208
			template <typename T>
			using on_mbuttonup_t = decltype(std::declval<T>().on_mbuttonup(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0209
			template <typename T>
			using on_mbuttondblclk_t = decltype(std::declval<T>().on_mbuttondblclk(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//020a
			template <typename T>
			using on_mousewheel_t = decltype(std::declval<T>().on_mousewheel(std::declval<mouse_vkey>(), std::declval<int16_t>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//020b
			template <typename T>
			using on_xbuttondown_t = decltype(std::declval<T>().on_xbuttondown(std::declval<mouse_vkey>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, must return true
			//020c
			template <typename T>
			using on_xbuttonup_t = decltype(std::declval<T>().on_xbuttonup(std::declval<mouse_vkey>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, must return true
			//020d
			template <typename T>
			using on_xbuttondblclk_t = decltype(std::declval<T>().on_xbuttondblclk(std::declval<mouse_vkey>(), std::declval<xbutton_type>(), std::declval<int32_t>(), std::declval<int32_t>())); //void return, must return true
			//020e
			template <typename T>
			using on_mousehwheel_t = decltype(std::declval<T>().on_mousehwheel(std::declval<mouse_vkey>(), std::declval<int16_t>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//020f - none
			//0210
			template <typename T>
			using on_parentnotify_t = decltype(std::declval<T>().on_parentnotify(std::declval<uint16_t>(), std::declval<const notify_param1 &>(), std::declval<const notify_param2 &>()));
			//0211
			template <typename T>
			using on_entermenuloop_t = decltype(std::declval<T>().on_entermenuloop(std::declval<bool>()));
			//0212
			template <typename T>
			using on_exitmenuloop_t = decltype(std::declval<T>().on_exitmenuloop(std::declval<bool>()));
			//0213 - WM_NEXTMENU (MDI messages are not implemented)
			//0214
			template <typename T>
			using on_sizing_t = decltype(std::declval<T>().on_sizing(std::declval<sizing_from>(), std::declval<const RECT &>()));
			//0215
			template <typename T>
			using on_capturechanged_t = decltype(std::declval<T>().on_capturechanged(std::declval<HWND>()));
			//0216
			template <typename T>
			using on_moving_t = decltype(std::declval<T>().on_moving(std::declval<const RECT &>()));
			//0217 - none
			//0218
			template <typename T>
			using on_powerbroadcast_t = decltype(std::declval<T>().on_powerbroadcast(std::declval<power_event_type>(), std::declval<std::optional<std::reference_wrapper<POWERBROADCAST_SETTING>>>()));
			//0219
			template <typename T>
			using on_devicechange_t = decltype(std::declval<T>().on_devicechange(std::declval<devicechange_type>(), std::declval<std::optional<devicechange_param>>())); //bool return
			//021a - 021f - none
			//0220 - 0229 - MDI messages (MDI messages are not implemented)
			//022a - 022f - none
			//0230 - WM_MDISETMENU (MDI messages are not implemented)
			//0231
			template <typename T>
			using on_entersizemove_t = decltype(std::declval<T>().on_entersizemove());
			//0232
			template <typename T>
			using on_exitsizemove_t = decltype(std::declval<T>().on_exitsizemove());
			//0233
			template <typename T>
			using on_dropfiles_t = decltype(std::declval<T>().on_dropfiles(std::declval<HDROP>()));
			//0234 - WM_MDIREFRESHMENU (MDI messages are not implemented)
			//0235 - 0237 - none
			//0238 - WM_POINTERDEVICECHANGE
			//0239 - WM_POINTERDEVICEINRANGE
			//023a - WM_POINTERDEVICEOUTOFRANGE
			//023b - 023f - none
			//0240
			template <typename T>
			using on_touch_t = decltype(std::declval<T>().on_touch(std::declval<uint16_t>(), std::declval<HTOUCHINPUT>()));
			//0241
			template <typename T>
			using on_ncpointerupdate_t = decltype(std::declval<T>().on_ncpointerupdate(std::declval<uint16_t>(), std::declval<hittest_position>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0242
			template <typename T>
			using on_ncpointerdown_t = decltype(std::declval<T>().on_ncpointerdown(std::declval<uint16_t>(), std::declval<hittest_position>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0243
			template <typename T>
			using on_ncpointerup_t = decltype(std::declval<T>().on_ncpointerup(std::declval<uint16_t>(), std::declval<hittest_position>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0244 - none
			//0245
			template <typename T>
			using on_pointerupdate_t = decltype(std::declval<T>().on_pointerupdate(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0246
			template <typename T>
			using on_pointerdown_t = decltype(std::declval<T>().on_pointerdown(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0247
			template <typename T>
			using on_pointerup_t = decltype(std::declval<T>().on_pointerup(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0248 - none
			//0249
			template <typename T>
			using on_pointerenter_t = decltype(std::declval<T>().on_pointerenter(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//024a
			template <typename T>
			using on_pointerleave_t = decltype(std::declval<T>().on_pointerleave(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//024b
			template <typename T>
			using on_pointeractivate_t = decltype(std::declval<T>().on_pointeractivate(std::declval<uint16_t>(), std::declval<hittest_position>(), std::declval<const pointer_data &>(), std::declval<HWND>())); //pointer_activate_type return
			//024c
			template <typename T>
			using on_pointercapturechanged_t = decltype(std::declval<T>().on_pointercapturechanged(std::declval<uint16_t>(), std::declval<const pointer_data &>(), std::declval<HWND>()));
			//024d
			template <typename T>
			using on_touchhittesting_t = decltype(std::declval<T>().on_touchhittesting(std::declval<const TOUCH_HIT_TESTING_INPUT &>())); //LRESULT return
			//024e
			template <typename T>
			using on_pointerwheel_t = decltype(std::declval<T>().on_pointerwheel(std::declval<uint16_t>(), std::declval<int16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//024f
			template <typename T>
			using on_pointerhwheel_t = decltype(std::declval<T>().on_pointerhwheel(std::declval<uint16_t>(), std::declval<int16_t>(), std::declval<const pointer_data &>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//0250
			template <typename T>
			using on_pointerhittest_t = decltype(std::declval<T>().on_pointerhittest());
			//0251
			template <typename T>
			using on_pointerroutedto_t = decltype(std::declval<T>().on_pointerroutedto());
			//0252
			template <typename T>
			using on_pointerroutedaway_t = decltype(std::declval<T>().on_pointerroutedaway());
			//0253
			template <typename T>
			using on_pointerroutedreleased_t = decltype(std::declval<T>().on_pointerroutedreleased());
			//0254 - 0280 - none
			//0281 - WM_IME_SETCONTEXT - (Don't impletent IME messages for now)
			//0282 - WM_IME_NOTIFY - (Don't impletent IME messages for now)
			//0283 - WM_IME_CONTROL - (Don't impletent IME messages for now)
			//0284 - WM_IME_COMPOSITIONFULL - (Don't impletent IME messages for now)
			//0285 - WM_IME_SELECT - (Don't impletent IME messages for now)
			//0286 - WM_IME_CHAR - (Don't impletent IME messages for now)
			//0287 - none
			//0288 - WM_IME_REQUEST - (Don't impletent IME messages for now)
			//0289 - 028f - none
			//0290 - WM_IME_KEYDOWN - (Don't impletent IME messages for now)
			//0291 - WM_IME_KEYUP - (Don't impletent IME messages for now)
			//0292 - 029f - none
			//02a0
			template <typename T>
			using on_ncmousehover_t = decltype(std::declval<T>().on_ncmousehover(std::declval<hittest_position>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//02a1
			template <typename T>
			using on_mousehover_t = decltype(std::declval<T>().on_mousehover(std::declval<mouse_vkey>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//02a2
			template <typename T>
			using on_ncmouseleave_t = decltype(std::declval<T>().on_ncmouseleave());
			//02a3
			template <typename T>
			using on_mouseleave_t = decltype(std::declval<T>().on_mouseleave());
			//02a4 - 02b0 - none
			//02b1
			template <typename T>
			using on_wtssession_change_t = decltype(std::declval<T>().on_wtssession_change(std::declval<session_change_type>(), std::declval<uint32_t>()));
			//02b2 - 02df - none
			//02e0
			template <typename T>
			using on_dpichanged_t = decltype(std::declval<T>().on_dpichanged(std::declval<uint16_t>(), std::declval<uint16_t>(), std::declval<const RECT &>()));
			//02e1 - none
			//02e2
			template <typename T>
			using on_dpichanged_beforeparent_t = decltype(std::declval<T>().on_dpichanged_beforeparent());
			//02e3
			template <typename T>
			using on_dpichanged_afterparent_t = decltype(std::declval<T>().on_dpichanged_afterparent());
			//02e4
			template <typename T>
			using on_getdpiscaledsize_t = decltype(std::declval<T>().on_getdpiscaledsize(std::declval<uint16_t>(), std::declval<SIZE &>())); //bool return
			//02e5 - 02ff - none
			//0300
			template <typename T>
			using on_cut_t = decltype(std::declval<T>().on_cut());
			//0301
			template <typename T>
			using on_copy_t = decltype(std::declval<T>().on_copy()); //bool return
			//0302
			template <typename T>
			using on_paste_t = decltype(std::declval<T>().on_paste());
			//0303
			template <typename T>
			using on_clear_t = decltype(std::declval<T>().on_clear());
			//0304
			template <typename T>
			using on_undo_t = decltype(std::declval<T>().on_undo()); //bool return
			//0305
			template <typename T>
			using on_renderformat_t = decltype(std::declval<T>().on_renderformat(std::declval<clipboard_format>()));
			//0306
			template <typename T>
			using on_renderallformats_t = decltype(std::declval<T>().on_renderallformats());
			//0307
			template <typename T>
			using on_destroyclipboard_t = decltype(std::declval<T>().on_destroyclipboard());
			//0308
			template <typename T>
			using on_drawclipboard_t = decltype(std::declval<T>().on_drawclipboard());
			//0309
			template <typename T>
			using on_paintclipboard_t = decltype(std::declval<T>().on_paintclipboard(std::declval<HWND>(), std::declval<const PAINTSTRUCT &>()));
			//030a
			template <typename T>
			using on_vscrollclipboard_t = decltype(std::declval<T>().on_vscrollclipboard(std::declval<HWND>(), std::declval<vscrollbar_request>()));
			//030b
			template <typename T>
			using on_sizeclipboard_t = decltype(std::declval<T>().on_sizeclipboard(std::declval<HWND>(), std::declval<const RECT &>()));
			//030c
			template <typename T>
			using on_askcbformatname_t = decltype(std::declval<T>().on_askcbformatname(std::declval<uintptr_t>(), std::declval<typename traits::char_t *>()));
			//030d
			template <typename T>
			using on_changecbchain_t = decltype(std::declval<T>().on_changecbchain(std::declval<HWND>(), std::declval<HWND>()));
			//030e
			template <typename T>
			using on_hscrollclipboard_t = decltype(std::declval<T>().on_hscrollclipboard(std::declval<HWND>(), std::declval<hscrollbar_request>()));
			//030f
			template <typename T>
			using on_querynewpalette_t = decltype(std::declval<T>().on_querynewpalette()); //bool return
			//0310
			template <typename T>
			using on_paletteischanging_t = decltype(std::declval<T>().on_paletteischanging(std::declval<HWND>()));
			//0311
			template <typename T>
			using on_palettechanged_t = decltype(std::declval<T>().on_palettechanged(std::declval<HWND>()));
			//0312
			template <typename T>
			using on_hotkey_t = decltype(std::declval<T>().on_hotkey(std::declval<int32_t>(), std::declval<hotkey_modifier>()));
			//0313 - 0316 - none
			//0317
			template <typename T>
			using on_print_t = decltype(std::declval<T>().on_print(std::declval<HDC>(), std::declval<print_flags>()));
			//0318
			template <typename T>
			using on_printclient_t = decltype(std::declval<T>().on_printclient(std::declval<HDC>(), std::declval<print_flags>()));
			//0319 - WM_APPCOMMAND
			template <typename T>
			using on_appcommand_t = decltype(std::declval<T>().on_appcommand(std::declval<appcommand_info>(), std::declval<int32_t>(), std::declval<int32_t>()));
			//031a
			template <typename T>
			using on_themechanged_t = decltype(std::declval<T>().on_themechanged());
			//031b - 031c - none
			//031d
			template <typename T>
			using on_clipboardupdate_t = decltype(std::declval<T>().on_clipboardupdate());
			//031e - WM_DWMCOMPOSITIONCHANGED (Not used)
			//031f
			template <typename T>
			using on_dwmncrenderingchanged_t = decltype(std::declval<T>().on_dwmncrenderingchanged(std::declval<bool>()));
			//0320
			template <typename T>
			using on_dwmcolorizationcolorchanged_t = decltype(std::declval<T>().on_dwmncrenderingchanged(std::declval<uint32_t>(), std::declval<bool>()));
			//0321
			template <typename T>
			using on_dwmwindowmaximizedchange_t = decltype(std::declval<T>().on_dwmwindowmaximizedchange(std::declval<bool>()));
			//0322 - none
			//0323
			template <typename T>
			using on_dwmsendiconicthumbnail_t = decltype(std::declval<T>().on_dwmsendiconicthumbnail(std::declval<uint16_t>(), std::declval<uint16_t>()));
			//0324 - 0325
			//0326
			template <typename T>
			using on_dwmsendiconiclivepreviewbitmap_t = decltype(std::declval<T>().on_dwmsendiconiclivepreviewbitmap());
			//0327 - 033e - none
			//033f
			template <typename T>
			using on_gettitlebarinfoex_t = decltype(std::declval<T>().on_gettitlebarinfoex(std::declval<TITLEBARINFOEX &>()));
			//Not a message, but this is a convenient place to place a message related structure.
			template <typename T>
			using get_commandhandler_t = decltype(std::declval<T>().get_commandhandler()); //must return a reference to command_handler_list
		};
	}

	template<typename DerivedType, bool CustomHandler, bool UnicodeBase>
	class window_t : public choose_window_base_t<UnicodeBase>, public track_mouse_policy<DerivedType, CustomHandler, UnicodeBase>
	{
	public:
		using my_base_t = choose_window_base_t<UnicodeBase>;
		using my_traits_t = choose_window_traits_t<UnicodeBase>;
		using my_t = DerivedType;
		using my_tptr = my_t *;
		using my_type = window_t;

		using my_string_t = std::basic_string<typename my_traits_t::char_t>;
		using my_string_view_t = std::basic_string_view<typename my_traits_t::char_t>;

	protected:
		//The check for these member functions need to be in window_t due to this type being a friend of the
		//derived type. If these types are not in a friend, the handlers would have to be public.
		//These are also placed in a structure to wrap them up nicely in the closest we can get to a namespace.
		using window_msg_types = details::window_msg_types<my_traits_t>;

		~window_t() = default;

		using my_base_t::get_handle;
		using my_base_t::raw_inst_from_handle;

		friend class track_mouse_policy<DerivedType, CustomHandler, UnicodeBase>;

		explicit window_t(HINSTANCE inst) : my_base_t(inst) {}

		static LRESULT CALLBACK cbt_hook_proc(int code, WPARAM wparam, LPARAM lparam);

		static bool hook_create();

		static bool create_window(const my_string_view_t &class_name, const my_string_view_t &title, DWORD style, DWORD ex_style, const POINT &top_left, const SIZE &dimentions, DerivedType *that, HWND parent = nullptr, HMENU menu = nullptr);

		LRESULT message_handler(UINT msg, WPARAM wparam, LPARAM lparam);

		//This is used when there is a command table but no
		//on_command. This calls get_commandhandler to get
		//the table of command handlers and then calls the
		//appropriate entry.
		bool on_command_default(uint16_t identifier, uint16_t notification_code, HWND control_handle);

		bool on_syscommand_default(syscommand_info info, int32_t xpos, int32_t ypos);

		std::pair<LRESULT, bool> on_notify_default(const NMHDR &notify_info);

		bool on_appcommand_default(appcommand_info info, int32_t xpos, int32_t ypos);

		std::pair<LRESULT, bool> default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam);

		LRESULT simple_default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam);

		static LRESULT window_proc_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

		static LRESULT window_proc_init_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

		static LRESULT CALLBACK window_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

		static my_tptr inst_from_handle(HWND wnd);

		static void handle_first_message(HWND wnd);

		static void handle_ncdestroy(HWND wnd);

		template <typename ...Types>
		static auto default_create(Types &&...) -> DerivedType *;
	private:
		window_t() = delete;
		window_t(const window_t &) = delete;
		window_t(window_t &&) = delete;
		window_t &operator=(const window_t &) = delete;
		window_t &operator=(window_t &&) = delete;

		static inline std::function<LRESULT(HWND, UINT, WPARAM, LPARAM)> m_proc{ window_proc_init_seh };

		static inline thread_local HHOOK s_create_hook = nullptr;

		template <typename Definitions>
		static std::pair<bool, my_string_t> default_register_from_definition(HINSTANCE inst);

		template <typename Definitions>
		static bool default_create_window_from_definition(DerivedType *ptr, const my_string_t &class_name);

		static bool default_create_on_pointer(DerivedType *, HINSTANCE);
	};
}

#include "window_implementation.hpp"