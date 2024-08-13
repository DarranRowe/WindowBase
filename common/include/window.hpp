#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

#include <variant>

#include "window_base.hpp"

#include "application.hpp"

#include "application_helper.hpp"

#include <wil/result.h>

namespace windowing
{
#ifdef _WIN64
	using uintptr_t = uint64_t;
	using intptr_t = int64_t;
#else
	using uintptr_t = uint32_t;
	using intptr_t = int32_t;
#endif

#if (defined UNICODE) || defined (_UNICODE)
	constexpr inline bool window_default_unicode = true;
#else
	constexpr inline bool window_default_unicode = false;
#endif

	//These static asserts are for when you return a type that isn't convertable to
	//the expected return type or void.
#ifdef ENABLE_WINDOW_TYPE_STATIC_ASSERTS
	inline static constexpr const bool return_type_assert = true;
#else
	inline static constexpr const bool return_type_assert = false;
#endif

	//On handlers that can work with a default, these asserts are for when the
	//handler really should return a type but the return is void.
#ifdef ENABLE_WINDOW_TYPE_ADDITIONAL_STATIC_ASSERTS
	//Only enable this if we have the asserts enabled.
	inline static constexpr const bool additional_return_type_assert = true && return_type_assert;
#else
	inline static constexpr const bool additional_return_type_assert = false;
#endif

	namespace details
	{
		template <typename T, template <typename> typename, typename = std::void_t<>>
		struct detect : std::false_type {};

		template <typename T, template <typename> typename Op>
		struct detect<T, Op, std::void_t<Op<T>>> : std::true_type {};

		template <typename T, template <typename> typename Op>
		inline constexpr bool detect_v = detect<T, Op>::value;

		template <typename T, template <typename> typename Op>
		using return_type_t = Op<T>;

		template <typename T, template <typename> typename Op, typename Cmp>
		inline constexpr bool same_return_v = std::is_same_v<return_type_t<T, Op>, Cmp>;

		template <typename T, template <typename> typename Op, typename Cmp>
		inline constexpr bool convertable_return_v = std::is_convertible_v<return_type_t<T, Op>, Cmp>;

		template <typename T, template <typename> typename Op>
		inline constexpr bool integral_return_v = std::is_integral_v<return_type_t<T, Op>>;

		//Wrap the CRTP static cast into a function.
		//While this is a safe operation, the static assert helps double
		//check this, and putting the static cast into a function where
		//the cast happens in one location is easier to handle.
		template <typename DerivedType, typename BaseType>
		auto this_cast(BaseType *that) -> DerivedType *
		{
			static_assert(std::is_base_of_v<BaseType, DerivedType>);
			return static_cast<DerivedType *>(that);
		}

		template <typename BaseType, typename DerivedType>
		auto base_cast(DerivedType *that) -> BaseType *
		{
			static_assert(std::is_base_of_v<BaseType, DerivedType>);
			return static_cast<BaseType *>(that);
		}

		//A general static cast from one value type to another.
		//We use this to indicate that this is a cast that we
		//want to do.
		template <typename R, typename Param>
		auto value_cast(Param p) -> R
		{
			return static_cast<R>(p);
		}

		//This will be used to cast the this pointer stored in the window
		//property to the class type. Functionally it is the same as
		//prop_cast, but it is useful to seperate them.
		template <typename DerivedType>
		auto inst_cast(void *that) -> DerivedType *
		{
			return static_cast<DerivedType *>(that);
		}

		//This is for converting LPARAM and WPARAM parameters to
		//a reference type. A pointer is passed in the message
		//parameter, so we cast to a pointer and indirect to the
		//reference.
		//This function puts all of these casts into one location
		//and indicates that this is intentional.
		template <typename R, typename Param>
		auto ref_param_cast(Param p) -> R &
		{
			return *reinterpret_cast<R *>(p);
		}

		template <typename R, typename Param>
		auto ptr_param_cast(Param p) -> R *
		{
			return reinterpret_cast<R *>(p);
		}

		//This is for those parameters that are just different
		//integer types in WPARAM and LPARAM.
		template <typename R, typename Param>
		auto param_cast(Param p) -> R
		{
			return static_cast<R>(p);
		}

		template <typename Param>
		auto hnd_ptr_return_cast(Param p) -> LRESULT
		{
			return reinterpret_cast<LRESULT>(p);
		}
		template <typename Param>
		auto return_cast(Param p) -> LRESULT
		{
			return static_cast<LRESULT>(p);
		}

		template <typename R, typename Param>
		auto handle_cast(Param p) -> R
		{
			return reinterpret_cast<R>(p);
		}

		//Used for casting a value from GetWindowProp to its type.
		template <typename Prop>
		auto prop_cast(void *p) -> Prop *
		{
			return static_cast<Prop *>(p);
		}

		template <typename P1, typename P2>
		uint16_t make_word(P1 p1, P2 p2)
		{
			//These need to be strengthened to check type sizes
			uint16_t result = (static_cast<uint16_t>(static_cast<uint8_t>(p1)) | (static_cast<uint16_t>(static_cast<uint8_t>(p2)) << 8));
			return result;
		}
		template <typename P1, typename P2>
		uint32_t make_dword(P1 p1, P2 p2)
		{
			//These need to be strengthened to check type sizes
			uint32_t result = (static_cast<uint32_t>(static_cast<uint16_t>(p1)) | (static_cast<uint32_t>(static_cast<uint16_t>(p2)) << 16));
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

	DEFINE_ENUM_FLAG_OPERATORS(endsession_reason);

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

	DEFINE_ENUM_FLAG_OPERATORS(input_language_change_flags);

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

	DEFINE_ENUM_FLAG_OPERATORS(nccalcsize_return);

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

	DEFINE_ENUM_FLAG_OPERATORS(ime_composition_flags);

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

	DEFINE_ENUM_FLAG_OPERATORS(menuselect_flags);
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
	DEFINE_ENUM_FLAG_OPERATORS(uistate_style);
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
	DEFINE_ENUM_FLAG_OPERATORS(mouse_vkey);
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
	DEFINE_ENUM_FLAG_OPERATORS(get_dlg_code_return);
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
	DEFINE_ENUM_FLAG_OPERATORS(hotkey_modifier);
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
	DEFINE_ENUM_FLAG_OPERATORS(print_flags);

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
	DEFINE_ENUM_FLAG_OPERATORS(appcommand_device);
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
	DEFINE_ENUM_FLAG_OPERATORS(appcommand_keys);

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
	struct choose_window_traits
	{
		using traits = window_traits_a;
	};
	template <>
	struct choose_window_traits<true>
	{
		using traits = window_traits_w;
	};
	template <bool UnicodeBase>
	using choose_window_traits_t = typename choose_window_traits<UnicodeBase>::traits;
	template <bool UnicodeBase = false>
	struct choose_prop_traits
	{
		using traits = prop_traits_a;
	};
	template <>
	struct choose_prop_traits<true>
	{
		using traits = prop_traits_w;
	};
	template <bool UnicodeBase>
	using choose_prop_traits_t = typename choose_prop_traits<UnicodeBase>::traits;

	template <typename DerivedType>
	struct static_assert_wrapper
	{
		inline static constexpr bool template_not_specialised = false;
		static_assert(template_not_specialised);

	};

	template <typename DerivedType>
	struct class_definitions
	{
		inline static constexpr bool value = static_assert_wrapper<DerivedType>::template_not_specialised;
	};

	template <typename DerivedType>
	struct window_definitions
	{
		inline static constexpr bool value = static_assert_wrapper<DerivedType>::template_not_specialised;
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
			inline static constexpr const mouse_policy_value value = mouse_policy_value::no_mouse_track;
		};

		template <typename ClassType>
		struct mouse_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::mouse_track_policy;
			inline static constexpr const mouse_policy_value value = get_mouse_policy_type<typename ClassType::mouse_track_policy>();
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
		inline constexpr const bool detect_ncmouse_policy_v = detect_mouse_policy<ClassType>::value;

		template <typename ClassType, bool = detect_ncmouse_policy_v<ClassType>>
		struct ncmouse_policy_or_default
		{
			using policy = window_no_mouse_track_t;
			inline static constexpr const mouse_policy_value value = mouse_policy_value::no_mouse_track;
		};

		template <typename ClassType>
		struct ncmouse_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::ncmouse_track_policy;
			inline static constexpr const mouse_policy_value value = get_mouse_policy_type<typename ClassType::mouse_track_policy>();
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
			inline static constexpr bool value = false;
		};

		template <typename ClassType>
		struct process_quit_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::quit_process_policy;
			inline static constexpr const bool value = get_quit_policy_type<typename ClassType::quit_process_policy>();
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
			inline static constexpr const bool value = false;
		};

		template <typename ClassType>
		struct default_nccreate_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::default_nccreate_policy;
			inline static constexpr const bool value = get_nccreate_policy_type<typename ClassType::default_nccreate_policy>();
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
			inline static constexpr const window_charset_value value = get_charset_policy_type_from_default<window_default_unicode>();
		};

		template <typename ClassType>
		struct window_charset_policy_or_default<ClassType, true>
		{
			using policy = typename ClassType::window_charset_policy;
			inline static constexpr const window_charset_value value = get_charset_policy_type_from_policy<typename ClassType::window_charset_policy>();
		};

		template <typename ClassType>
		using window_charset_policy_t = typename window_charset_policy_or_default<ClassType>::policy;

		template <typename ClassType>
		inline constexpr const window_charset_value window_charset_policy_v = window_charset_policy_or_default<ClassType>::value;
	}

	template<typename DerivedType, bool UnicodeBase = details::get_charset_policy_bool_from_value<details::window_charset_policy_v<DerivedType>>()>
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
			inline constexpr const bool detect_class_definitions_typedef_v = detect_class_definitions_typedef<ClassType>::value;

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
				static const uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct style_value<T, true>
			{
				using style_t = typename class_definition_types::style_t<T>;

				static const uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<style_t>>);
					return T::style;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::class_extra_t>>
			struct class_extra_value
			{
				static const int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct class_extra_value<T, true>
			{
				using class_extra_t = typename class_definition_types::class_extra_t<T>;

				static const int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<class_extra_t>>);
					return T::class_extra;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::window_extra_t>>
			struct window_extra_value
			{
				static const int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct window_extra_value<T, true>
			{
				using window_extra_t = typename class_definition_types::window_extra_t<T>;

				static const int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<window_extra_t>>);
					return T::window_extra;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::instance_t>>
			struct instance_value
			{
				static const HINSTANCE get_value()
				{
					//Return the executable's HINSTANCE.
					return reinterpret_cast<HINSTANCE>(GetModuleHandleW(nullptr));
				}
			};

			template <typename T>
			struct instance_value<T, true>
			{
				using instance_t = typename class_definition_types::instance_t<T>;

				static const HINSTANCE get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<instance_t>, HINSTANCE>);
					return T::instance;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::icon_t>>
			struct icon_value
			{
				static const HICON get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct icon_value<T, true>
			{
				using icon_t = typename class_definition_types::icon_t<T>;

				static const HICON get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<icon_t>, HICON>);
					return T::icon;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::cursor_t>>
			struct cursor_value
			{
				static const HCURSOR get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct cursor_value<T, true>
			{
				using cursor_t = typename class_definition_types::cursor_t<T>;

				static const HCURSOR get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<cursor_t>, HCURSOR>);
					return T::cursor;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::brush_t>>
			struct brush_value
			{
				static const HBRUSH get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct brush_value<T, true>
			{
				using brush_t = typename class_definition_types::brush_t<T>;

				static const HBRUSH get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<brush_t>, HBRUSH>);
					return T::brush;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::menu_name_t>>
			struct menu_name_value
			{
				using traits = typename window_t<typename T::window_type>::traits;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct menu_name_value<T, true>
			{
				using traits = typename window_t<typename T::window_type>::traits;
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
							constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
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
								constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
							}
						}
					}
				}
				using menu_name_t = typename class_definition_types::menu_name_t<T>;

				static const traits::char_t *get_value()
				{
					constexpr auto ret_type = detect_string_type<menu_name_t>();
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
				using traits = typename window_t<typename T::window_type>::traits;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct class_name_value<T, true>
			{
				using traits = typename window_t<typename T::window_type>::traits;
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
							constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
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
								constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
							}
						}
					}
				}
				using class_name_t = typename class_definition_types::class_name_t<T>;

				static const traits::char_t *get_value()
				{
					constexpr auto ret_type = detect_string_type<class_name_t>();
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
				static const HICON get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct small_icon_value<T, true>
			{
				using small_icon_t = typename class_definition_types::small_icon_t<T>;

				static const HICON get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<small_icon_t>, HICON>);
					return T::small_icon;
				}
			};

			template <typename T, bool = details::detect_v<T, class_definition_types::existing_class_name_t>>
			struct existing_class_name_value
			{
				static const bool get_value()
				{
					return false;
				}
			};

			template <typename T>
			struct existing_class_name_value<T, true>
			{
				using existing_class_name_t = typename class_definition_types::existing_class_name_t<T>;

				static const bool get_value()
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
			inline constexpr const bool detect_window_definitions_v = detect_window_definitions<ClassType>::value;

			template <typename ClassType, typename = std::void_t<>>
			struct detect_window_definitions_typedef : std::false_type {};

			template <typename ClassType>
			struct detect_window_definitions_typedef<ClassType, std::void_t<typename ClassType::window_definitions>> : std::true_type {};

			template <typename ClassType>
			inline constexpr const bool detect_window_definitions_typedef_v = detect_window_definitions_typedef<ClassType>::value;

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
				static const uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct style_value<T, true>
			{
				using style_t = typename window_definition_types::style_t<T>;

				static const uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<style_t>>);
					return T::style;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::ex_style_t>>
			struct ex_style_value
			{
				static const uint32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct ex_style_value<T, true>
			{
				using ex_style_t = typename window_definition_types::ex_style_t<T>;

				static const uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<ex_style_t>>);
					return T::ex_style;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::window_name_t>>
			struct window_name_value
			{
				using traits = typename window_t<typename T::window_type>::traits;
				//When the menu_name is not detected, return a nullptr.
				//The type we use is a simple const char_t *.
				//const char *
				//const wchar_t *
				static const traits::char_t *get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct window_name_value<T, true>
			{
				using traits = typename window_t<typename T::window_type>::traits;
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
							constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
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
								constexpr auto v = static_assert_wrapper<VT>::template_not_specialised;
							}
						}
					}
				}
				using window_name_t = typename window_definition_types::window_name_t<T>;

				static const traits::char_t *get_value()
				{
					constexpr auto ret_type = detect_string_type<window_name_t>();
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
				static const int32_t get_value()
				{
					return CW_USEDEFAULT;
				}
			};

			template <typename T>
			struct x_value<T, true>
			{
				using x_t = typename window_definition_types::x_t<T>;

				static const int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<x_t>>);
					return T::x;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::y_t>>
			struct y_value
			{
				static const int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct y_value<T, true>
			{
				using y_t = typename window_definition_types::y_t<T>;

				static const int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<y_t>>);
					return T::y;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::width_t>>
			struct width_value
			{
				static const int32_t get_value()
				{
					return CW_USEDEFAULT;
				}
			};

			template <typename T>
			struct width_value<T, true>
			{
				using width_t = typename window_definition_types::width_t<T>;

				static const uint32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<width_t>>);
					return T::width;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::height_t>>
			struct height_value
			{
				static const int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct height_value<T, true>
			{
				using height_t = typename window_definition_types::height_t<T>;

				static const int32_t get_value()
				{
					static_assert(std::is_integral_v<std::remove_const_t<height_t>>);
					return T::height;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::position_t>>
			struct position_value
			{
				static const POINT get_value()
				{
					return {CW_USEDEFAULT, 0};
				}
			};

			template <typename T>
			struct position_value<T, true>
			{
				using position_t = typename window_definition_types::position_t<T>;

				static const POINT get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<position_t>, POINT>);
					return T::position;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::size_t>>
			struct size_value
			{
				static const SIZE get_value()
				{
					return { CW_USEDEFAULT, 0 };
				}
			};

			template <typename T>
			struct size_value<T, true>
			{
				using size_t = typename window_definition_types::size_t<T>;

				static const SIZE get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<size_t>, SIZE>);
					return T::size;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::parent_t>>
			struct parent_value
			{
				static const HWND get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct parent_value<T, true>
			{
				using parent_t = typename window_definition_types::parent_t<T>;

				static const HWND get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<parent_t>, HWND>);
					return T::parent;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::menu_t>>
			struct menu_value_nonchild
			{
				static const HMENU get_value()
				{
					return nullptr;
				}
			};

			template <typename T>
			struct menu_value_nonchild<T, true>
			{
				using menu_t = typename window_definition_types::menu_t<T>;

				static const HMENU get_value()
				{
					static_assert(std::is_same_v<std::remove_const_t<menu_t>, HMENU>);
					return T::menu;
				}
			};

			template <typename T, bool = details::detect_v<T, window_definition_types::menu_t>>
			struct menu_value_child
			{
				static const int32_t get_value()
				{
					return 0;
				}
			};

			template <typename T>
			struct menu_value_child<T, true>
			{
				using menu_t = typename window_definition_types::menu_t<T>;

				static const int32_t get_value()
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

	template<typename DerivedType, bool UnicodeBase>
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
			using details::this_cast;
			if constexpr (details::mouse_policy_v<DerivedType> == details::mouse_policy_value::mouse_track ||
				details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				//GetCurrentThreadId is used because this will be called during the WM_NCCREATE message handler.
				//This is one of the messages that Windows will send during the CreateWindowEx call, so this
				//handler will only ever run on the thread that created the window.
				HHOOK hook_mh = choose_window_traits_t<UnicodeBase>::WndSetWindowsHookEx(WH_MOUSE, my_type::mh_hook, nullptr, GetCurrentThreadId());
				HHOOK hook_gm = choose_window_traits_t<UnicodeBase>::WndSetWindowsHookEx(WH_GETMESSAGE, my_type::gm_hook, nullptr, GetCurrentThreadId());

				m_hook_data.gm = hook_gm;
				m_hook_data.mh = hook_mh;

				m_registered_for_tracking = true;
			}
		}
		void untrack_mouse()
		{
			using details::this_cast;
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
		using my_type = track_mouse_policy<DerivedType, UnicodeBase>;
		using derived_type = window_t<DerivedType, UnicodeBase>;

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
					auto result = track_mouse(wnd, false);
					_ASSERTE(result == TRUE);
					FAIL_FAST_IF_WIN32_BOOL_FALSE(result);
				}
			}

			if constexpr (details::ncmouse_policy_v<DerivedType> == details::mouse_policy_value::ncmouse_track)
			{
				if ((msg >= WM_NCMOUSEMOVE) && (msg <= WM_NCXBUTTONDBLCLK) && (m_mouse_in_window == false))
				{
					m_mouse_in_window = true;
					m_mouse_in_nclient = true;
					m_first_mouse_message = true;
					auto result = track_mouse(wnd, true);
					_ASSERTE(result == TRUE);
					FAIL_FAST_IF_WIN32_BOOL_FALSE(result);
				}
			}
		}
		void handle_mouse_hover(HWND wnd)
		{
			//The documentation for WM_MOUSEHOVER and WM_NCMOUSEHOVER states that hover tracking
			//stops after a hover message is sent. Since we want to keep getting these messages
			//we need to re-enable it.
			_ASSERTE((m_mouse_in_window == true) && (m_mouse_in_client == true));
			auto result = track_mouse(wnd, false);
			_ASSERTE(result == TRUE);
			FAIL_FAST_IF_WIN32_BOOL_FALSE(result);
		}
		void handle_ncmouse_hover(HWND wnd)
		{
			//The documentation for WM_MOUSEHOVER and WM_NCMOUSEHOVER states that hover tracking
			//stops after a hover message is sent. Since we want to keep getting these messages
			//we need to re-enable it.
			_ASSERTE((m_mouse_in_window == true) && (m_mouse_in_nclient == true));
			auto result = track_mouse(wnd, true);
			_ASSERTE(result == TRUE);
			FAIL_FAST_IF_WIN32_BOOL_FALSE(result);
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

		std::atomic_bool m_mouse_in_window = false;
		std::atomic_bool m_mouse_in_nclient = false;
		std::atomic_bool m_mouse_in_client = false;
		std::atomic_bool m_first_mouse_message = false;

		hook_data m_hook_data{};
		std::atomic_bool m_registered_for_tracking = false;

		static my_type *instance_from_handle(HWND wnd)
		{
			using details::base_cast;
			auto v = my_t::inst_from_handle(wnd);
			if (v != nullptr)
			{
				//v will be set to DerivedType *, we want to cast to
				//window_t<DerivedType> * and then to this type.
				my_type *that = base_cast<my_type>(base_cast<derived_type>(v));

				return that;
			}
			return nullptr;
		}

		static LRESULT CALLBACK gm_hook(_In_ int code, _In_ WPARAM wparam, _In_ LPARAM lparam)
		{
			using details::ref_param_cast;
			if (code < 0)
			{
				return CallNextHookEx(nullptr, code, wparam, lparam);
			}

			MSG &msg = ref_param_cast<MSG>(lparam);
			if (msg.hwnd != nullptr)
			{
				my_type *that = my_type::instance_from_handle(msg.hwnd);
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
		}

		static LRESULT CALLBACK mh_hook(_In_ int code, _In_ WPARAM wparam, _In_ LPARAM lparam)
		{
			using details::ref_param_cast;
			using details::param_cast;

			if (code < 0)
			{
				return CallNextHookEx(nullptr, code, wparam, lparam);
			}

			MOUSEHOOKSTRUCTEX &mh_struct = ref_param_cast<MOUSEHOOKSTRUCTEX>(lparam);
			if (mh_struct.hwnd != nullptr)
			{
				my_type *that = my_type::instance_from_handle(mh_struct.hwnd);
				if (that == nullptr || !that->tracking())
			{
				return CallNextHookEx(nullptr, code, wparam, lparam);
			}
			else
			{
				if (code == HC_ACTION)
				{
					that->handle_mouse_message(mh_struct.hwnd, param_cast<UINT>(wparam), mh_struct);
				}

				return CallNextHookEx(nullptr, code, wparam, lparam);
			}
		}
		}
	};

	class message_callback_impl : public message_callback
	{
	public:
		virtual bool invoke(const MSG &msg) override
		{
			return m_callback(msg);
		}

		message_callback_impl() = delete;
		virtual ~message_callback_impl() = default;
		message_callback_impl(const message_callback_impl &) = default;
		message_callback_impl(message_callback_impl &&) = default;

		message_callback_impl &operator=(const message_callback_impl &) = default;
		message_callback_impl &operator=(message_callback_impl &&) = default;

		message_callback_impl(std::function<message_callback_type> &callback) : m_callback(callback)
		{
		}

		friend inline static std::shared_ptr<message_callback> make_message_callback(message_callback_ptr_type);
		template <typename L>
		friend inline static std::shared_ptr<message_callback> make_message_callback(L lambda);
		template <typename C>
		friend inline static std::shared_ptr<message_callback> make_message_callback(message_callback_ptm_type<C> member, C *c);
	private:
		std::function<message_callback_type> m_callback;
	};

	inline static std::shared_ptr<message_callback> make_message_callback(message_callback_ptr_type fptr)
	{
		std::function<message_callback_type> f{ [fptr](auto &&p)
			{
				return fptr(p);
			} };
		return std::make_shared<message_callback_impl>(f);
	}

	template <typename L>
	inline static std::shared_ptr<message_callback> make_message_callback(L lambda)
	{
		std::function<message_callback_type> f{ lambda };
		return std::make_shared<message_callback_impl>(f);
	}

	template <typename C>
	inline static std::shared_ptr<message_callback> make_message_callback(message_callback_ptm_type<C> member, C *c)
	{
		std::function<message_callback_type> f{ [member, c](auto &&p) {
				return (c->*member)(p);
			} };
		return std::make_shared<message_callback_impl>(f);
	}

	template<typename DerivedType, bool UnicodeBase>
	class window_t : public window_base, public track_mouse_policy<DerivedType, UnicodeBase>
	{
	public:
		using traits = choose_window_traits_t<UnicodeBase>;
		using prop_traits = choose_prop_traits_t<UnicodeBase>;
		using my_t = DerivedType;
		using my_tptr = my_t *;
		using my_type = window_t;

	protected:
		//The check for these member functions need to be in window_t due to this type being a friend of the
		//derived type. If these types are not in a friend, the handlers would have to be public.
		//These are also placed in a structure to wrap them up nicely in the closest we can get to a namespace.
		struct window_msg_types
		{
			//0000 - WM_NULL
			//0001
			template <typename T>
			using on_create_t = decltype(std::declval<T>().on_create(std::declval<const traits::create_struct_t &>()));
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
			using on_settext_t = decltype(std::declval<T>().on_settext(std::declval<const traits::char_t  *>()));
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
			using on_settingchange_t = decltype(std::declval<T>().on_settingchange(std::declval<uint32_t>(), std::declval<const traits::char_t *>()));
			//001b
			template <typename T>
			using on_devmodechange_t = decltype(std::declval<T>().on_devmodechange(std::declval<const traits::char_t *>()));
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
			using on_nccreate_t = decltype(std::declval<T>().on_nccreate(std::declval<const traits::create_struct_t &>()));
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

		~window_t() = default;

		using base_t = window_base;
		using base_t::add_message_callback;
		using base_t::remove_message_callback;
		using base_t::clear_message_callbacks;

		friend class track_mouse_policy<DerivedType, UnicodeBase>;

		explicit window_t(HINSTANCE inst) : base_t(inst) {}

		static LRESULT CALLBACK cbt_hook_proc(int code, WPARAM wparam, LPARAM lparam)
		{
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
					HWND wnd = reinterpret_cast<HWND>(wparam);
					typename traits::cbt_createwnd_t &params = *reinterpret_cast<traits::cbt_createwnd_t *>(lparam);

					my_tptr that = reinterpret_cast<my_tptr>(params.lpcs->lpCreateParams);
					that->set_window_info(wnd, GetCurrentThreadId(), UnicodeBase);

					prop_traits::set_property(wnd, prop_type::instance, params.lpcs->lpCreateParams);
				}

				auto result = CallNextHookEx(my_type::s_create_hook, code, wparam, lparam);
				UnhookWindowsHookEx(my_type::s_create_hook);
				my_type::s_create_hook = nullptr;
				return result;
			}
		}

		static bool hook_create()
		{
			my_type::s_create_hook = traits::WndSetWindowsHookEx(WH_CBT, my_type::cbt_hook_proc, nullptr, GetCurrentThreadId());
			return my_type::s_create_hook != nullptr ? true : false;
		}

		static bool create_window(const std::string_view &class_name, const std::string_view &title, DWORD style, DWORD ex_style, const POINT &top_left, const SIZE &dimentions, DerivedType *that, HWND parent = nullptr, HMENU menu = nullptr)
		{
			if (!hook_create())
			{
				return false;
			}

			//Cast to the derived type to make sure that the pointer we pass to CreateWindowExA is the correct pointer.
			//We can't be sure of the derived class layout, so this is to be sure.
			auto result = base_t::create_window(ex_style, style, class_name, title, top_left, dimentions, parent, menu, that);

			return result == nullptr ? false : true;
		}
		static bool create_window(const std::wstring_view &class_name, const std::wstring_view &title, DWORD style, DWORD ex_style, const POINT &top_left, const SIZE &dimentions, DerivedType *that, HWND parent = nullptr, HMENU menu = nullptr)
		{
			if (!hook_create())
			{
				return false;
			}

			//Cast to the derived type to make sure that the pointer we pass to CreateWindowExW is the correct pointer.
			//We can't be sure of the derived class layout, so this is to be sure.
			auto result = base_t::create_window(ex_style, style, class_name, title, top_left, dimentions, parent, menu, that);

			return result == nullptr ? false : true;
		}

		LRESULT message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
		{
			return traits::WndDefWindowProc(base_t::get_handle(), msg, wparam, lparam);
		}

		//This is used when there is a command table but no
		//on_command. This calls get_commandhandler to get
		//the table of command handlers and then calls the
		//appropriate entry.
		bool on_command_default(uint16_t identifier, uint16_t notification_code, HWND control_handle)
		{
			bool handled = false;
			using wmt = window_msg_types;
			using details::this_cast;
			if constexpr (details::detect_v<DerivedType, wmt::get_commandhandler_t>)
			{
				constexpr const bool return_handler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
				constexpr const bool return_chandler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
				static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
				auto &command_handler = this_cast<DerivedType>(this)->get_commandhandler();

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

		bool on_syscommand_default(syscommand_info info, int32_t xpos, int32_t ypos)
		{
			bool handled = false;
			using wmt = window_msg_types;
			using details::this_cast;
			if constexpr (details::detect_v<DerivedType, wmt::get_commandhandler_t>)
			{
				constexpr const bool return_handler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
				constexpr const bool return_chandler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
				static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
				auto &command_handler = this_cast<DerivedType>(this)->get_commandhandler();

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

		std::pair<LRESULT, bool> on_notify_default(const NMHDR &notify_info)
		{
			bool handled = false;
			LRESULT proc_result{};
			using wmt = window_msg_types;
			using details::this_cast;
			using details::ref_param_cast;
			if constexpr (details::detect_v<DerivedType, wmt::get_commandhandler_t>)
			{
				constexpr const bool return_handler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
				constexpr const bool return_chandler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
				static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
				auto &command_handler = this_cast<DerivedType>(this)->get_commandhandler();

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

		bool on_appcommand_default(appcommand_info info, int32_t xpos, int32_t ypos)
		{
			bool handled = false;
			using wmt = window_msg_types;
			using details::this_cast;
			if constexpr (details::detect_v<DerivedType, wmt::get_commandhandler_t>)
			{
				constexpr const bool return_handler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
				constexpr const bool return_chandler = details::same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
				static_assert(return_handler || return_chandler, "get_commandhandler must return a reference to command_handler_list");
				auto &command_handler = this_cast<DerivedType>(this)->get_commandhandler();

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

		std::pair<LRESULT, bool> default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
		{
			using details::value_cast;
			using details::this_cast;
			using details::ref_param_cast;
			using details::ptr_param_cast;
			using details::param_cast;
			using details::return_cast;
			using details::hnd_ptr_return_cast;
			using details::handle_cast;
			using details::return_type_t;
			using details::detect_v;
			using details::same_return_v;
			using details::convertable_return_v;
			using details::integral_return_v;
			using std::make_pair;
			using wmt = window_msg_types;

			bool handled = false;
			LRESULT proc_result{};

			switch (msg)
			{
			case 0x0000:
			{
				break;
			}
			case WM_CREATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_create_t>)
				{
					constexpr const bool return_bool = same_return_v<DerivedType, wmt::on_create_t, bool>;
					constexpr const bool return_cbool = convertable_return_v<DerivedType, wmt::on_create_t, bool>;
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_create_t, void>;

					if constexpr (return_bool || return_cbool)
					{
						LRESULT result = value_cast<bool>(this_cast<DerivedType>(this)->on_create(ref_param_cast<traits::create_struct_t>(lparam))) == false ? -1 : 0;
						proc_result = result;

					}
					else
					{
						if constexpr (return_type_assert) static_assert(return_void, "on_create with a return that is not convertable to bool or void found. Defaulting to succeed.");
						this_cast<DerivedType>(this)->on_create(ref_param_cast<traits::create_struct_t>(lparam));
						//proc_result is initialised to 0. The handler for WM_CREATE returns 0 to indicate success.
					}

					handled = true;
				}
				break;
			}
			case WM_DESTROY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_destroy_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_destroy_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_destroy with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_destroy();
					handled = true;
				}
				break;
			}
			case WM_MOVE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_move_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_move_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_move with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_move(param_cast<int32_t>(GET_X_LPARAM(lparam)), param_cast<int32_t>(GET_Y_LPARAM(lparam)));
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
				if constexpr (detect_v<DerivedType, wmt::on_size_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_size_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_size with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_size(param_cast<resize_type>(wparam), param_cast<int32_t>(GET_X_LPARAM(lparam)), param_cast<int32_t>(GET_Y_LPARAM(lparam)));
					handled = true;
				}
				break;
			}
			case WM_ACTIVATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_activate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_activate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_activate with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_activate(param_cast<activate_type>(LOWORD(wparam)), param_cast<BOOL>(HIWORD(wparam)) == FALSE ? false : true, handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_SETFOCUS:
			{
				if constexpr (detect_v<DerivedType, wmt::on_setfocus_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_setfocus_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_setfocus with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_setfocus(handle_cast<HWND>(wparam));
					handled = true;
				}
				break;
			}
			case WM_KILLFOCUS:
			{
				if constexpr (detect_v<DerivedType, wmt::on_killfocus_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_killfocus_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_killfocus with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_killfocus(handle_cast<HWND>(wparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_enable_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_enable_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_enable with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_enable(param_cast<BOOL>(wparam) == FALSE ? false : true);
					handled = true;
				}
				break;
			}
			case WM_SETREDRAW:
			{
				if constexpr (detect_v<DerivedType, wmt::on_setredraw_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_setredraw_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_setredraw with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_setredraw(param_cast<BOOL>(wparam) == FALSE ? false : true);
					handled = true;
				}
				break;
			}
			case WM_SETTEXT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_settext_t>)
				{
					static constexpr bool convertable_ret = convertable_return_v<DerivedType, wmt::on_settext_t, bool>;

					//This static_assert is deliberately unconditional.
					//The behaviour of WM_SETTEXT is compromised if you are unable to return a value.
					static_assert(convertable_ret, "on_settext must have a return that is convertable to bool.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_settext(ptr_param_cast<wmt::msg_char_type>(lparam))) == false ? FALSE : TRUE;
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_GETTEXT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_gettext_t>)
				{
					constexpr bool convertable_ret = convertable_return_v<DerivedType, wmt::on_gettext_t, uintptr_t>;
					
					//This static_assert is deliberately unconditional.
					//The behaviour of WM_GETTEXT is compromised if we cannot return a value.
					static_assert(convertable_ret, "on_gettext must have a return that is convertable to uintptr_t.");
					//One of the difficulties of WM_GETTEXT is that the buffer size is passed in through WPARAM, and the characters copied
					//is passed out through LRESULT. This means that the types have a sign mismatch.
					//What's more, there is no indicator as to the maximum size of the string beyond the rich edit control value.
					//This results in the parameters both being assumed to be unsigned and the size of the sizes will change based on whether
					//this is compiled for 32 or 64 bit. The intptr_t and uintptr_t types have been defined to help with this.
					auto result = value_cast<uintptr_t>(this_cast<DerivedType>(this)->on_gettext(param_cast<uintptr_t>(wparam), ptr_param_cast<wmt::msg_char_type>(lparam)));
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_GETTEXTLENGTH:
			{
				if constexpr (detect_v<DerivedType, wmt::on_gettextlength_t>)
				{
					constexpr bool convertable_ret = convertable_return_v<DerivedType, wmt::on_gettextlength_t, uintptr_t>;
					//This static_assert is deliberately unconditional.
					//The behaviour of WM_GETTEXT is compromised if we cannot return a value.
					static_assert(convertable_ret, "on_gettextlength must have a return that is convertable to uintptr_t.");
					auto result = value_cast<uintptr_t>(this_cast<DerivedType>(this)->on_gettextlength());
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_PAINT:
			{
				constexpr const bool simple_paint = detect_v<DerivedType, wmt::simple_on_paint_t>;
				constexpr const bool default_paint = detect_v<DerivedType, wmt::default_on_paint_t>;

				//Detect both overloads.
				static_assert(!(simple_paint && default_paint), "Both paint functions detected, only using on_paint().");
				//If both exist, only use the default version.
				if constexpr (simple_paint && !default_paint)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::simple_on_paint_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_paint with a return that is not void found. Ignoring return.");

					PAINTSTRUCT ps{};
					BeginPaint(get_handle(), &ps);
					this_cast<DerivedType>(this)->on_paint(ps);
					EndPaint(get_handle(), &ps);
					handled = true;
				}
				if constexpr (default_paint)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::default_on_paint_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_paint with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_paint();
					handled = true;
				}
				break;
			}
			case WM_CLOSE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_close_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_close_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_close with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_close();
					handled = true;
				}
				break;
			}
			case WM_QUERYENDSESSION:
			{
				if constexpr (detect_v<DerivedType, wmt::on_queryendsession_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_queryendsession_t, bool>;
					static_assert(convertable_bool, "on_queryendsession with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_queryendsession(param_cast<endsession_reason>(lparam))) == false ? FALSE : TRUE;
					proc_result = return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_queryopen_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_queryopen_t, bool>;
					static_assert(convertable_bool, "on_queryopen with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_queryopen()) == false ? FALSE : TRUE;
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_ERASEBKGND:
			{
				if constexpr (detect_v<DerivedType, wmt::on_erasebkgnd_t>)
				{
					constexpr const bool return_bool = same_return_v<DerivedType, wmt::on_erasebkgnd_t, bool>;
					constexpr const bool return_cbool = convertable_return_v<DerivedType, wmt::on_erasebkgnd_t, bool>;
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_erasebkgnd_t, void>;

					if constexpr (return_bool || return_cbool)
					{
						LRESULT result = value_cast<bool>(this_cast<DerivedType>(this)->on_erasebkgnd(handle_cast<HDC>(wparam))) == false ? FALSE : TRUE;
						proc_result = result;
					}
					else
					{
						if constexpr (return_type_assert) static_assert(return_void, "on_erasebkgnd found that returns a value that isn't void or convertable to bool. Return will be ignored.");
						if constexpr (additional_return_type_assert) static_assert((!return_void), "on_erasebkgnd found that returns void. Using a default value of TRUE.");
						this_cast<DerivedType>(this)->on_erasebkgnd(handle_cast<HDC>(wparam));
						//Assume that we wouldn't be doing this if we were not going to erase the background.
						proc_result = TRUE;
					}
					handled = true;
				}
				break;
			}
			case WM_SYSCOLORCHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syscolorchange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_syscolorchange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_syscolorchange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_syscolorchange();
					handled = true;
				}
				break;
			}
			case WM_ENDSESSION:
			{
				if constexpr (detect_v<DerivedType, wmt::on_endsession_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_endsession_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_endsession with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_endsession(param_cast<BOOL>(wparam) == FALSE ? false : true, param_cast<endsession_reason>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_showwindow_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_showwindow_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_showwindow with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_showwindow(param_cast<bool>(wparam), param_cast<showwindow_reason>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_settingchange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_settingchange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_settingchange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_settingchange(param_cast<uint32_t>(wparam), ptr_param_cast<traits::char_t>(lparam));
					handled = true;
				}
				break;
			}
			case WM_DEVMODECHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_devmodechange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_devmodechange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_devmodechange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_devmodechange(ptr_param_cast<traits::char_t>(lparam));
					handled = true;
				}
				break;
			}
			case WM_ACTIVATEAPP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_activateapp_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_activateapp_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_activateapp with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_activateapp(param_cast<BOOL>(wparam) == FALSE ? false : true, param_cast<uint32_t>(lparam));
					handled = true;
				}
				break;
			}
			case WM_FONTCHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_fontchange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_fontchange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_fontchange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_fontchange();
					handled = true;
				}
				break;
			}
			case WM_TIMECHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_timechange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_timechange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_timechange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_timechange();
					handled = true;
				}
				break;
			}
			case WM_CANCELMODE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_cancelmode_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_cancelmode_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_cancelmode with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_cancelmode();
					handled = true;
				}
				break;
			}
			case WM_SETCURSOR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_setcursor_t>)
				{
					constexpr const bool return_bool = same_return_v<DerivedType, wmt::on_setcursor_t, bool>;
					constexpr const bool return_cbool = convertable_return_v<DerivedType, wmt::on_setcursor_t, bool>;
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_setcursor_t, void>;

					if constexpr (return_bool || return_cbool)
					{
						LRESULT result = this_cast<DerivedType>(this)->on_setcursor(handle_cast<HWND>(wparam), param_cast<hittest_position>(LOWORD(lparam)), param_cast<uint32_t>(HIWORD(lparam))) == false ? FALSE : TRUE;
						proc_result = result;
					}
					else
					{
						if constexpr (return_type_assert) static_assert(return_void, "on_setcursor found that returns a value that isn't void or convertable to bool. Return will be ignored.");
						if constexpr (additional_return_type_assert) static_assert((!return_void), "onsetcursor found that returns void. Using a default value of FALSE.");
						this_cast<DerivedType>(this)->on_setcursor(handle_cast<HWND>(wparam), param_cast<hittest_position>(LOWORD(lparam)), param_cast<uint32_t>(HIWORD(lparam)));
						//Assume that further processing should happen.
						proc_result = FALSE;
					}

					handled = true;
				}
				break;
			}
			case WM_MOUSEACTIVATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mouseactivate_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_mouseactivate_t, mouse_activate_type>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_mouseactivate_t>;
					static_assert(convertable_to_return || integral_return, "on_mouseactivate found that returns a type that isn't convertable to mouse_activate_type.");
					auto result = value_cast<mouse_activate_type>(this_cast<DerivedType>(this)->on_mouseactivate(handle_cast<HWND>(wparam), param_cast<hittest_position>(LOWORD(lparam)), param_cast<uint32_t>(HIWORD(lparam))));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CHILDACTIVATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_childactivate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_childactivate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_childactivate with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_childactivate();
					handled = true;
				}
				break;
			}
			case WM_QUEUESYNC:
			{
				if constexpr (detect_v<DerivedType, wmt::on_queuesync_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_queuesync_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_queuesync with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_queuesync();
					handled = true;
				}
				break;
			}
			case WM_GETMINMAXINFO:
			{
				if constexpr (detect_v<DerivedType, wmt::on_getminmaxinfo_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_getminmaxinfo_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_getminmaxinfo with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_getminmaxinfo(ref_param_cast<MINMAXINFO>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_nextdlgctl_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_nextdlgctl_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_nextdlgctl with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_nextdlgctl(ref_param_cast<next_dlg_ctl_params>(wparam), param_cast<BOOL>(lparam) == FALSE ? false : true);
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
				if constexpr (detect_v<DerivedType, wmt::on_drawitem_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_drawitem_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_drawitem with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_drawitem(param_cast<uint32_t>(wparam), ref_param_cast<DRAWITEMSTRUCT>(lparam));
					proc_result = TRUE;
					handled = true;
				}
				break;
			}
			case WM_MEASUREITEM:
			{
				if constexpr (detect_v<DerivedType, wmt::on_measureitem_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_measureitem_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_measureitem with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_measureitem(param_cast<uint32_t>(wparam), ref_param_cast<MEASUREITEMSTRUCT>(lparam));
					proc_result = TRUE;
					handled = true;
				}
				break;
			}
			case WM_DELETEITEM:
			{
				if constexpr (detect_v<DerivedType, wmt::on_deleteitem_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_deleteitem_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_deleteitem with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_deleteitem(param_cast<uint32_t>(wparam), ref_param_cast<MEASUREITEMSTRUCT>(lparam));
					proc_result = TRUE;
					handled = true;
				}
				break;
			}
			case WM_VKEYTOITEM:
			{
				if constexpr (detect_v<DerivedType, wmt::on_vkeytoitem_t>)
				{
					constexpr const bool convertable_int = convertable_return_v<DerivedType, wmt::on_vkeytoitem_t, int32_t>;
					static_assert(convertable_int, "on_vkeytoitem must have a return that is convertable to int32_t.");
					auto result = this_cast<DerivedType>(this)->on_vkeytoitem(LOWORD(wparam), HIWORD(lparam), handle_cast<HWND>(lparam));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CHARTOITEM:
			{
				if constexpr (detect_v<DerivedType, wmt::on_chartoitem_t>)
				{
					constexpr const bool convertable_int = convertable_return_v<DerivedType, wmt::on_vkeytoitem_t, int32_t>;
					static_assert(convertable_int, "on_vkeytoitem must have a return that is convertable to int32_t.");
					auto result = this_cast<DerivedType>(this)->on_chartoitem(param_cast<traits::char_t>(LOWORD(wparam)), HIWORD(lparam), handle_cast<HWND>(lparam));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_SETFONT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_setfont_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_setfont_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_setfont with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_setfont(handle_cast<HFONT>(wparam), param_cast<BOOL>(LOWORD(lparam)) == FALSE ? false : true);
					handled = true;
				}
				break;
			}
			case WM_GETFONT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_getfont_t>)
				{
					constexpr const bool return_hfont = same_return_v<DerivedType, wmt::on_getfont_t, HFONT>;
					static_assert(return_hfont, "on_getfont must have a return of HFONT.");
					auto result = this_cast<DerivedType>(this)->on_getfont();
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_SETHOTKEY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_sethotkey_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_sethotkey_t, set_hot_key_result>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_sethotkey_t>;
					static_assert(convertable_to_return || integral_return, "on_sethotkey found that returns a type that isn't set_hot_key_result or is convertable to set_hot_key_result.");

					hot_key_value hkv{};
					hkv.vk = param_cast<uint8_t>(LOWORD(wparam));
					hkv.modifier = param_cast<uint8_t>(HIWORD(wparam));

					auto result = value_cast<set_hot_key_result>(this_cast<DerivedType>(this)->on_sethotkey(hkv));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_GETHOTKEY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_gethotkey_t>)
				{
					constexpr const bool return_hot_key_value = same_return_v<DerivedType, wmt::on_gethotkey_t, hot_key_value>;
					static_assert(return_hot_key_value, "on_gethotkey found that returns a type that isn't hot_key_value");
					auto result = this_cast<DerivedType>(this)->on_gethotkey();
					uint16_t ret_val = param_cast<uint16_t>(result.vk) | (param_cast<uint16_t>(result.modifier) << 8);
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
				if constexpr (detect_v<DerivedType, wmt::on_compareitem_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_compareitem_t, compare_item_result>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_compareitem_t>;
					static_assert(convertable_to_return || integral_return, "on_compareitem found that returns a type that isn't convertable to compare_item_result.");
					auto result = value_cast<compare_item_result>(this_cast<DerivedType>(this)->on_compareitem(param_cast<uint32_t>(wparam), ref_param_cast<COMPAREITEMSTRUCT>(lparam)));
					proc_result = return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_getobject_t>)
				{
					constexpr const bool convertable_return = convertable_return_v<DerivedType, wmt::on_getobject_t, LRESULT>;
					static_assert(convertable_return, "on_getobject found that returns a type that isn't convertable to LRESULT.");
					auto result = this_cast<DerivedType>(this)->on_getobject(param_cast<uint32_t>(wparam), param_cast<uint32_t>(lparam));
					proc_result = return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_windowposchanging_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_windowposchanging_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_windowposchanging with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_windowposchanging(ref_param_cast<WINDOWPOS>(lparam));
					handled = true;
				}
				break;
			}
			case WM_WINDOWPOSCHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_windowposchanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_windowposchanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_windowposchanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_windowposchanged(ref_param_cast<WINDOWPOS>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_copydata_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_copydata_t, bool>;
					static_assert(convertable_bool, "on_copydata with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_copydata(handle_cast<HWND>(wparam), ref_param_cast<COPYDATASTRUCT>(lparam))) == false ? FALSE : TRUE;
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
				if constexpr (detect_v<DerivedType, wmt::on_notify_t>)
				{
					constexpr const bool return_complex = convertable_return_v<DerivedType, wmt::on_notify_t, std::pair<LRESULT, bool>>;
					static_assert(return_complex, "on_notify with a return that is not std::pair<LRESULT, bool> found.");
					auto &&[notify_result, notify_handled] = this_cast<DerivedType>(this)->on_notify(param_cast<uint32_t>(wparam), ref_param_cast<NMHDR>(lparam));
					proc_result = notify_result;
					handled = notify_handled;
				}
				else
				{
					if constexpr (detect_v<DerivedType, wmt::get_commandhandler_t>)
					{
						constexpr const bool return_command_list = same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
						constexpr const bool return_ccommand_list = same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
						static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list");
						auto &&[notify_result, notify_handled] = on_notify_default(ref_param_cast<NMHDR>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_inputlangchangerequest_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_inputlanguagechangerequest_t, bool>;
					static_assert(convertable_to_return, "on_inputlanguagechangerequest with a return that is not convertable to bool found.");

					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_inputlangchangerequest(param_cast<input_language_change_flags>(wparam), param_cast<uint32_t>(lparam)));
					//This must call DefWindowProc to handle the request.
					//Setting handled to false will call DefWindowProc automatically.
					handled = !result;
				}
				break;
			}
			case WM_INPUTLANGCHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_inputlangchange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_inputlanguagechange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_inputlanguagechange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_inputlangchange(param_cast<input_language_character_set>(wparam), LOWORD(HandleToUlong(handle_cast<HKL>(lparam))), handle_cast<HKL>(lparam));
					proc_result = TRUE; //The documentation states to return non-zero if the message is handled
					handled = true;
				}
				break;
			}
			case WM_TCARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_tcard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_tcard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_tcard with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_tcard(param_cast<uint32_t>(wparam), param_cast<uint32_t>(lparam));
					handled = true;
				}
				break;
			}
			case WM_HELP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_help_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_help_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_help with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_help(ref_param_cast<HELPINFO>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_notifyformat_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_notifyformat_t, notify_format_result>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_notifyformat_t>;

					static_assert(convertable_to_return || integral_return, "on_notifyformat found with a return that isn't convertable to notify_format_result.");
					auto result = value_cast<notify_format_result>(this_cast<DerivedType>(this)->on_notifyformat(handle_cast<HWND>(wparam), param_cast<notify_format_type>(lparam)));
					proc_result = return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_contextmenu_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_contextmenu_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_contextmenu with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_contextmenu(handle_cast<HWND>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_STYLECHANGING:
			{
				if constexpr (detect_v<DerivedType, wmt::on_stylechanging_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_stylechanging_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_stylechanging with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_stylechanging(param_cast<style_changing_type>(wparam), ref_param_cast<STYLESTRUCT>(lparam));
					handled = true;
				}
				break;
			}
			case WM_STYLECHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_stylechanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_stylechanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_stylechanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_stylechanged(param_cast<style_changing_type>(wparam), ref_param_cast<STYLESTRUCT>(lparam));
					handled = true;
				}
				break;
			}
			case WM_DISPLAYCHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_displaychange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_displaychange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_displaychange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_displaychange(param_cast<uint32_t>(wparam), LOWORD(lparam), HIWORD(lparam));
					handled = true;
				}
				break;
			}
			case WM_GETICON:
			{
				if constexpr (detect_v<DerivedType, wmt::on_geticon_t>)
				{
					constexpr const bool return_hicon = same_return_v<DerivedType, wmt::on_geticon_t, HICON>;
					static_assert(return_hicon, "on_geticon with a return that is not HICON found.");
					auto result = this_cast<DerivedType>(this)->on_geticon(param_cast<icon_type>(wparam), param_cast<uint32_t>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_SETICON:
			{
				if constexpr (detect_v<DerivedType, wmt::on_seticon_t>)
				{
					constexpr const bool return_hicon = same_return_v<DerivedType, wmt::on_seticon_t, HICON>;
					static_assert(return_hicon, "on_seticon with a return that is not HICON found.");
					auto result = this_cast<DerivedType>(this)->on_seticon(param_cast<icon_type>(wparam), handle_cast<HICON>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_NCCREATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nccreate_t>)
				{
					constexpr const bool return_bool = same_return_v<DerivedType, wmt::on_nccreate_t, bool>;
					constexpr const bool return_cbool = convertable_return_v<DerivedType, wmt::on_nccreate_t, bool>;
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_nccreate_t, void>;

					if constexpr (return_bool || return_cbool)
					{
						LRESULT result = this_cast<DerivedType>(this)->on_nccreate(ref_param_cast<traits::create_struct_t>(lparam)) == false ? FALSE : TRUE;
						proc_result = result;
					}
					else
					{
						if constexpr (return_type_assert) static_assert(return_void, "on_nccreate with a return that is not convertable to bool or void found. Defaulting to succed.");
						this_cast<DerivedType>(this)->on_nccreate(ref_param_cast<traits::create_struct_t>(lparam));
						proc_result = TRUE;
					}

					handled = true;
				}
				break;
			}
			case WM_NCDESTROY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncdestroy_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncdestroy_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncdestroy with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncdestroy();
					handled = true;
				}
				break;
			}
			case WM_NCCALCSIZE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nccalcsize_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_nccalcsize_t, nccalcsize_return>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_nccalcsize_t>;
					static_assert(convertable_to_return || integral_return, "on_nccalcsize found that returns a type that isn't convertable to nccalcsize_return.");
					BOOL p = param_cast<BOOL>(wparam);
					nccalcsize_params ncp = (p == FALSE ? nccalcsize_params(*ptr_param_cast<RECT>(lparam)) : nccalcsize_params(*ptr_param_cast<NCCALCSIZE_PARAMS>(lparam)));
					auto result = value_cast<nccalcsize_return>(this_cast<DerivedType>(this)->on_nccalcsize(p == FALSE ? false : true, ncp));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_NCHITTEST:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nchittest_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_nchittest_t, hittest_position>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_ncchittest_t>;
					static_assert(convertable_to_return || integral_return, "on_nccalcsize found that returns a type that isn't convertable to hittest_position.");
					auto result = value_cast<hittest_position>(this_cast<DerivedType>(this)->on_nchittest(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_NCPAINT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncpaint_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncpaint_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncpaint with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncpaint(handle_cast<HRGN>(wparam));
					handled = true;
				}
				break;
			}
			case WM_NCACTIVATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncactivate_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_ncactivate_t, bool>;
					static_assert(convertable_bool, "on_ncactivate found that returns a type that isn't convertable to bool.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_ncactivate(param_cast<BOOL>(wparam) == FALSE ? false : true, handle_cast<HRGN>(lparam))) == false ? FALSE : TRUE;
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_GETDLGCODE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_getdlgcode_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_getdlgcode_t, get_dlg_code_return>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_getdlgcode_t>;
					static_assert(convertable_to_return || integral_return, "on_getdlgcode found that returns a type that isn't convertable to get_dlg_code_return.");
					constexpr bool same_ret = same_return_v<DerivedType, wmt::on_getdlgcode_t, get_dlg_code_return>;
					std::optional<std::reference_wrapper<MSG>> m;
					if (lparam != 0)
					{
						m.emplace(ref_param_cast<MSG>(lparam));
					}

					auto result = value_cast<get_dlg_code_return>(this_cast<DerivedType>(this)->on_getdlgcode(param_cast<uint8_t>(wparam), m));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_SYNCPAINT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syncpaint_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_syncpaint_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_syncpaint with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_syncpaint();
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
				if constexpr (detect_v<DerivedType, wmt::on_ncmousemove_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmousemove_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmousemove with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmousemove(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCLBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nclbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_nclbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_nclbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_nclbuttondown(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCLBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nclbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_nclbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_nclbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_nclbuttonup(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCLBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_nclbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_nclbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_nclbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_nclbuttondblclk(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCRBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncrbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncrbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncrbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncrbuttondown(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCRBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncrbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncrbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncrbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncrbuttonup(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCRBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncrbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncrbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncrbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncrbuttondblclk(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCMBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncmbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmbuttondown(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCMBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncmbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmbuttonup(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCMBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncmbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmbuttondblclk(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_ncxbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncxbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncxbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncxbuttondown(param_cast<hittest_position>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_ncxbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncxbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncxbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncxbuttonup(param_cast<hittest_position>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_ncxbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncxbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncxbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncxbuttondblclk(param_cast<hittest_position>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_input_device_change_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_input_device_change_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_input_device_change with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_input_device_change(param_cast<input_dev_change_type>(wparam), handle_cast<HANDLE>(lparam));
					handled = true;
				}
				break;
			}
			case WM_INPUT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_input_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_input_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_input with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_input(param_cast<input_type>(GET_RAWINPUT_CODE_WPARAM(wparam)), handle_cast<HRAWINPUT>(lparam));
					//If the raw input code is RIM_INPUT, it is documented that DefWindowProc must be called.
					//In this case, we leave the message as unhandled and let it drop through to DefWindowProc.
					handled = GET_RAWINPUT_CODE_WPARAM(wparam) == RIM_INPUT ? false : true;
				}
				break;
			}
			case WM_KEYDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_keydown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_keydown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_keydown with a return that is not void found. Ignoring return.");
					auto &kd = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_keydown(param_cast<virtual_key>(wparam), kd);
					handled = true;
				}
				break;
			}
			case WM_KEYUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_keyup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_keyup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_keyup with a return that is not void found. Ignoring return.");
					auto &kd = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_keyup(param_cast<virtual_key>(wparam), kd);
					handled = true;
				}
				break;
			}
			case WM_CHAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_char_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_char_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_char with a return that is not void found. Ignoring return.");
					auto &key_data = ref_param_cast<keystroke_data>(&lparam);
					//wparam will be either char or wchar_t depending on whether the window was registered with
					//RegisterClass(Ex)A or RegisterClass(Ex)W. The window class automatically uses the appropriate
					//one based upon the UnicodeBase template parameter. This means that we can blindly cast based
					//upon our traits.
					this_cast<DerivedType>(this)->on_char(param_cast<traits::char_t>(wparam), key_data);
					handled = true;
				}
				break;
			}
			case WM_DEADCHAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_deadchar_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_deadchar_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_deadchar with a return that is not void found. Ignoring return.");
					auto &key_data = ref_param_cast<keystroke_data>(&lparam);
					//Like WM_CHAR, the cast is based upon how the window was registered.
					this_cast<DerivedType>(this)->on_deadchar(param_cast<traits::char_t>(wparam), key_data);
					handled = true;
				}
				break;
			}
			case WM_SYSKEYDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syskeydown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_syskeydown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_syskeydown with a return that is not void found. Ignoring return.");
					auto &kd = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_syskeydown(param_cast<virtual_key>(wparam), kd);
					handled = true;
				}
				break;
			}
			case WM_SYSKEYUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syskeyup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_syskeyup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_syskeyup with a return that is not void found. Ignoring return.");
					auto &kd = ref_param_cast(&lparam);
					this_cast<DerivedType>(this)->on_syskeyup(param_cast<virtual_key>(wparam), kd);
					handled = true;
				}
				break;
			}
			case WM_SYSCHAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syschar_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_syschar_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_syschar with a return that is not void found. Ignoring return.");
					auto &key_data = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_syschar(param_cast<traits::char_t>(wparam), key_data);
					handled = true;
				}
				break;
			}
			case WM_SYSDEADCHAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_sysdeadchar_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_sysdeadchar_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_sysdeadchar with a return that is not void found. Ignoring return.");
					auto &key_data = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_sysdeadchar(param_cast<traits::char_t>(wparam), key_data);
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
				if constexpr (detect_v<DerivedType, wmt::on_unichar_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_unichar_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_unichar with a return that is not void found. Ignoring return.");
					auto &kd = ref_param_cast<keystroke_data>(&lparam);
					this_cast<DerivedType>(this)->on_unichar(value_cast<uint32_t>(wparam), kd);
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
				if constexpr (detect_v<DerivedType, wmt::on_command_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_command_t, bool>;
					static_assert(convertable_bool, "on_command with a return that is not convertable to bool found.");
					handled = this_cast<DerivedType>(this)->on_command(LOWORD(wparam), HIWORD(wparam), handle_cast<HWND>(lparam));
				}
				else
				{
					if constexpr (detect_v<DerivedType, wmt::get_commandhandler_t>)
					{
						constexpr const bool return_command_list = same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
						constexpr const bool return_ccommand_list = same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
						static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list.");
						handled = on_command_default(LOWORD(wparam), HIWORD(wparam), handle_cast<HWND>(lparam));
					}
				}
				break;
			}
			case WM_SYSCOMMAND:
			{
				if constexpr (detect_v<DerivedType, wmt::on_syscommand_t> || detect_v<DerivedType, wmt::get_commandhandler_t>)
				{
					syscommand_info info{};
					info.request = value_cast<syscommand_request>(wparam & 0xFFF0);
					info.is_secure = value_cast<bool>(wparam & SCF_ISSECURE);
					if constexpr (detect_v<DerivedType, wmt::on_syscommand_t>)
					{
						constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_syscommand_t, bool>;
						if constexpr (return_type_assert) static_assert(convertable_bool, "on_syscommand with a return that is not convertable to bool found.");
						handled = this_cast<DerivedType>(this)->on_syscommand(info, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					}
					else
					{
						if constexpr (detect_v<DerivedType, wmt::get_commandhandler_t>)
						{
							constexpr const bool return_command_list = same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
							constexpr const bool return_ccommand_list = same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
							static_assert(return_command_list || return_ccommand_list, "get_commandhandler must return a reference to command_handler_list.");
							handled = on_syscommand_default(info, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
						}
					}
				}
				break;
			}
			case WM_TIMER:
			{
				if constexpr (detect_v<DerivedType, wmt::on_timer_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_timer_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_timer with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_timer(param_cast<uintptr_t>(wparam), ptr_param_cast<TIMERPROC>(lparam));
					handled = true;
				}
				break;
			}
			case WM_HSCROLL:
			{
				if constexpr (detect_v<DerivedType, wmt::on_hscroll_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_hscroll_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_hscroll with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_hscroll(param_cast<hscrollbar_request>(LOWORD(wparam)), HIWORD(wparam), handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_VSCROLL:
			{
				if constexpr (detect_v<DerivedType, wmt::on_vscroll_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_vscroll_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_vscroll with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_vscroll(param_cast<vscrollbar_request>(LOWORD(wparam)), HIWORD(wparam), handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_INITMENU:
			{
				if constexpr (detect_v<DerivedType, wmt::on_initmenu_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_initmenu_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_initmenu with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_initmenu(handle_cast<HMENU>(wparam));
					handled = true;
				}
				break;
			}
			case WM_INITMENUPOPUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_initmenupopup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_initmenupopup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_initmenupopup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_initmenupopup(handle_cast<HMENU>(wparam), LOWORD(lparam), param_cast<BOOL>(HIWORD(lparam)) == FALSE ? false : true);
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
				if constexpr (detect_v<DerivedType, wmt::on_gesture_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_gesture_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_gesture with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_gesture(value_cast<uint64_t>(wparam), handle_cast<HGESTUREINFO>(lparam));
					handled = true;
				}
				break;
			}
			case WM_GESTURENOTIFY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_gesturenotify_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_gesturenotify_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_gesturenotify with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_gesturenotify(ref_param_cast<GESTURENOTIFYSTRUCT>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_menuselect_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_menuselect_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_menuselect with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_menuselect(LOWORD(wparam), param_cast<menuselect_flags>(HIWORD(wparam)), handle_cast<HMENU>(lparam));
					handled = true;
				}
				break;
			}
			case WM_MENUCHAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_menuchar_t>)
				{
					constexpr const bool return_menuchar_return = same_return_v<DerivedType, wmt::on_menuchar_t, menuchar_return>;
					static_assert(return_menuchar_return, "on_menuchar found with a return that is not menuchar_return.");
					auto result = this_cast<DerivedType>(this)->on_menuchar(param_cast<wmt::msg_char_type>(LOWORD(wparam)), param_cast<menuchar_flags>(HIWORD(wparam)), handle_cast<HMENU>(lparam));
					auto cmb_result = details::make_dword(result.index, param_cast<uint16_t>(result.result));
					proc_result = return_cast(cmb_result);
					handled = true;
				}
				break;
			}
			case WM_ENTERIDLE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_enteridle_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_enteridle_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_enteridle with a return that is not void found. Ignoring return.");
					enteridle_type ei_param = param_cast<enteridle_type>(wparam);
					enteridle_param v = ei_param == enteridle_type::dialogbox ? handle_cast<HWND>(lparam) : handle_cast<HMENU>(lparam);
					this_cast<DerivedType>(this)->on_enteridle(param_cast<enteridle_type>(wparam), v);
					handled = true;
				}
				break;
			}
			case WM_MENURBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_menurbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_menurbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_menurbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_menurbuttonup(param_cast<uint32_t>(wparam), handle_cast<HMENU>(lparam));
					handled = true;
				}
				break;
			}
			case WM_MENUDRAG:
			{
				if constexpr (detect_v<DerivedType, wmt::on_menudrag_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_menudrag_t, menudrag_return>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_menudrag_t>;
					static_assert(convertable_to_return || integral_return, "on_menudrag found with a return that is not convertable to menudrag_return");
					auto result = value_cast<menudrag_return>(this_cast<DerivedType>(this)->on_menudrag(param_cast<uint32_t>(wparam), handle_cast<HMENU>(lparam)));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_MENUGETOBJECT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_menugetobject_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_menugetobject_t, menugetobject_return>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_menugetobject_t>;
					static_assert(convertable_to_return || integral_return, "on_menugetobject found with a return that isn't menugetobject_return.");
					auto result = value_cast<menugetobject_return>(this_cast<DerivedType>(this)->on_menugetobject(ref_param_cast<MENUGETOBJECTINFO>(lparam)));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_UNINITMENUPOPUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_uninitmenupopup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_uninitmenupopup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_uninitmenupopup with a return that is not void found. Ignoring return.");
					//The high order word of lparam is always set to MF_SYSMENU.
					this_cast<DerivedType>(this)->on_uninitmenupopup(handle_cast<HMENU>(wparam));
					handled = true;
				}
				break;
			}
			case WM_MENUCOMMAND:
			{
				if constexpr (detect_v<DerivedType, wmt::on_menucommand_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_menucommand_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_menucommand with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_menucommand(param_cast<uint32_t>(wparam), handle_cast<HMENU>(lparam));
					handled = true;
				}
				break;
			}
			case WM_CHANGEUISTATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_changeuistate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_changeuistate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_changeuistate with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_changeuistate(param_cast<uistate_action>(LOWORD(wparam)), param_cast<uistate_style>(HIWORD(wparam)));
					handled = true;
				}
				break;
			}
			case WM_UPDATEUISTATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_updateuistate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_updateuistate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_updateuistate with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_updateuistate(param_cast<uistate_action>(LOWORD(wparam)), param_cast<uistate_style>(HIWORD(wparam)));
					handled = true;
				}
				break;
			}
			case WM_QUERYUISTATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_queryuistate_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_queryuistate_t, uistate_style>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_queryuistate_t>;
					static_assert(convertable_to_return || integral_return, "on_queryuistate foun with a return that is not convertable to uistate_style");
					auto result = value_cast<uistate_style>(this_cast<DerivedType>(this)->on_queryuistate());
					proc_result = return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolormsgbox_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolormsgbox_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolormsgbox found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolormsgbox(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLOREDIT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcoloredit_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcoloredit_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcoloredit found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcoloredit(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLORLISTBOX:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolorlistbox_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolorlistbox_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolorlistbox found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolorlistbox(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLORBTN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolorbtn_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolorbtn_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolorbtn found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolorbtn(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLORDLG:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolordlg_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolordlg_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolordlg found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolordlg(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLORSCROLLBAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolorscrollbar_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolorscrollbar_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolorscrollbar found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolorscrollbar(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_CTLCOLORSTATIC:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ctlcolorstatic_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_ctlcolorstatic_t, HBRUSH>;
					static_assert(return_hbrush, "on_ctlcolorstatic found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_ctlcolorstatic(handle_cast<HDC>(wparam), handle_cast<HWND>(lparam));
					proc_result = hnd_ptr_return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_gethmenu_t>)
				{
					constexpr const bool return_hbrush = same_return_v<DerivedType, wmt::on_gethmenu_t, HMENU>;
					static_assert(return_hbrush, "on_gethmenu found with a return that is not HBRUSH.");
					auto result = this_cast<DerivedType>(this)->on_gethmenu();
					proc_result = hnd_ptr_return_cast(result);
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
				if constexpr (detect_v<DerivedType, wmt::on_mousemove_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mousemove_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mousemove with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mousemove(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_LBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_lbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_lbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_lbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_lbuttondown(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_LBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_lbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_lbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_lbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_lbuttonup(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_LBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_lbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_lbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_lbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_lbuttondblclk(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_RBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_rbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_rbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_rbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_rbuttondown(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_RBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_rbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_rbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_rbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_rbuttonup(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_RBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_rbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_rbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_rbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_rbuttondblclk(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_MBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mbuttondown(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_MBUTTONUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mbuttonup(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_MBUTTONDBLCLK:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mbuttondblclk(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_MOUSEWHEEL:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mousewheel_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mousewheel_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mousewheel with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mousewheel(param_cast<mouse_vkey>(LOWORD(wparam)), GET_WHEEL_DELTA_WPARAM(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_XBUTTONDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_xbuttondown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_xbuttondown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_xbuttondown with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_xbuttondown(param_cast<mouse_vkey>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_xbuttonup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_xbuttonup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_xbuttonup with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_xbuttonup(param_cast<mouse_vkey>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_xbuttondblclk_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_xbuttondblclk_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_xbuttondblclk with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_xbuttondblclk(param_cast<mouse_vkey>(wparam), param_cast<xbutton_type>(GET_XBUTTON_WPARAM(wparam)), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_mousehwheel_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mousehwheel_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mousehwheel with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mousehwheel(param_cast<mouse_vkey>(LOWORD(wparam)), GET_WHEEL_DELTA_WPARAM(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_parentnotify_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_parentnotify_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_parentnotify with a return that is not void found. Ignoring return.");
					uint16_t msg = LOWORD(wparam);
					notify_param1 np1{};
					notify_param2 np2{};
					switch (msg)
					{
					case WM_CREATE:
					case WM_DESTROY:
						np1.emplace<1>(HIWORD(wparam));
						np2.emplace(handle_cast<HWND>(lparam));
						break;
					case WM_LBUTTONDOWN:
					case WM_MBUTTONDOWN:
					case WM_RBUTTONDOWN:
						np2.emplace({ GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) });
						break;
					case WM_XBUTTONDOWN:
						np1.emplace<0>(param_cast<xbutton_type>(HIWORD(wparam)));
						np2.emplace({ GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) });
						break;
					case WM_POINTERDOWN:
						np1.emplace<2>(HIWORD(wparam));
						np2.emplace({ GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) });
						break;
					}
					this_cast<DerivedType>(this)->on_parentnotify(LOWORD(wparam), np1, np2);
					handled = true;
				}
				break;
			}
			case WM_ENTERMENULOOP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_entermenuloop_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_entermenuloop_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_entermenuloop with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_entermenuloop(param_cast<bool>(wparam));
					handled = true;
				}
				break;
			}
			case WM_EXITMENULOOP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_exitmenuloop_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_exitmenuloop_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_exitmenuloop with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_exitmenuloop(param_cast<bool>(wparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_sizing_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_sizing_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_sizing with a return that is not void found. Ignoring return.");
					//Even though the documentation states that this must return TRUE if we handle the message,
					//the handler still returns void. It is an unconditional return TRUE, so the return of the
					//handler will never be used in any meaningful way.
					this_cast<DerivedType>(this)->on_sizing(ref_param_cast<RECT>(lparam));
					proc_result = TRUE;
					handled = true;
				}
				break;
			}
			case WM_CAPTURECHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_capturechanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_capturechanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_capturechanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_capturechanged(handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_MOVING:
			{
				if constexpr (detect_v<DerivedType, wmt::on_moving_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_moving_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_moving with a return that is not void found. Ignoring return.");
					//Even though the documentation states that this must return TRUE if we handle the message,
					//the handler still returns void. It is an unconditional return TRUE, so the return of the
					//handler will never be used in any meaningful way.
					this_cast<DerivedType>(this)->on_moving(ref_param_cast<RECT>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_powerbroadcast_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_powerbroadcast_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_powerbroadcast with a return that is not void found. Ignoring return.");
					std::optional<std::reference_wrapper<POWERBROADCAST_SETTING>> ps{};
					auto evt_type = param_cast<power_event_type>(wparam);
					if (evt_type == power_event_type::apm_powersettingchange)
					{
						ps.emplace(ref_param_cast<POWERBROADCAST_SETTING>(lparam));
					}
					this_cast<DerivedType>(this)->on_powerbroadcast(param_cast<power_event_type>(wparam), ps);
					proc_result = TRUE;
					handled = true;
				}
				break;
			}
			case WM_DEVICECHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_devicechange_t>)
				{
					constexpr const bool return_bool = same_return_v<DerivedType, wmt::on_devicechange_t, bool>;
					constexpr const bool return_cbool = convertable_return_v<DerivedType, wmt::on_devicechange_t, bool>;
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_devicechange_t, void>;

					auto change_type = param_cast<devicechange_type>(wparam);
					std::optional<devicechange_param> evt_data_ref{};
					switch (change_type)
					{
					case devicechange_type::devnodes_changed:
					case devicechange_type::querychangeconfig:
					case devicechange_type::configchanged:
					case devicechange_type::configchangecancelled:
						break;
					case devicechange_type::userdefined:
						evt_data_ref.emplace(*ptr_param_cast<_DEV_BROADCAST_USERDEFINED>(lparam));
						break;
					default:
						evt_data_ref.emplace(*ptr_param_cast<DEV_BROADCAST_HDR>(lparam));
						break;
					}

					if constexpr (return_bool || return_cbool)
					{
						auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_devicechange(change_type, evt_data_ref)) == false ? BROADCAST_QUERY_DENY : TRUE;
						proc_result = return_cast(result);
					}
					else
					{
						if constexpr (return_type_assert) static_assert(return_void, "on_devicechange with a return that is not convertable to bool or void found. Defaulting to succeed.");
						this_cast<DerivedType>(this)->on_devicechange(change_type, evt_data_ref);
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
				if constexpr (detect_v<DerivedType, wmt::on_touch_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_touch_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_touch found with a return that is not void. Ignoring return.");
					this_cast<DerivedType>(this)->on_touch(param_cast<uint16_t>(LOWORD(wparam)), handle_cast<HTOUCHINPUT>(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCPOINTERUPDATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncpointerupdate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncpointerupdate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncpointerupdate with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_ncpointerupdate(pointerid, static_cast<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCPOINTERDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncpointerdown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncpointerdown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncpointerdwon with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_ncpointerdown(pointerid, static_cast<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCPOINTERUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncpointerup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncpointerup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncpointerup with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_ncpointerup(pointerid, static_cast<hittest_position>(HIWORD(wparam)), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_pointerupdate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerupdate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerupdate with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerupdate(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_POINTERDOWN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerdown_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerdown_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerdown with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerdown(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_POINTERUP:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerup_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerup_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerup with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerup(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_pointerenter_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerenter_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerenter with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerenter(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_POINTERLEAVE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerleave_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerleave_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerleave with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerleave(pointerid, ptr_flags, GET_X_LPARAM(lparam), GET_X_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_POINTERACTIVATE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointeractivate_t>)
				{
					constexpr const bool convertable_to_return = convertable_return_v<DerivedType, wmt::on_pointeractivate_t, pointer_activate_type>;
					constexpr const bool integral_return = integral_return_v<DerivedType, wmt::on_pointeractivate_t>;
					static_assert(convertable_to_return || integral_return, "on_pointeractivate with a return that is not convertable to pointer_activate_type found.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					auto result = value_cast<pointer_activate_type>(this_cast<DerivedType>(this)->on_pointeractivate(pointerid, param_cast<hittest_position>(HIWORD(wparam)), ptr_flags, handle_cast<HWND>(lparam)));
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_POINTERCAPTURECHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointercapturechanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointercapturechanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointercapturechanged with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointercapturechanged(pointerid, ptr_flags, handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_TOUCHHITTESTING:
			{
				if constexpr (detect_v<DerivedType, wmt::on_touchhittesting_t>)
				{
					constexpr const bool return_lresult = same_return_v<DerivedType, wmt::on_touchhittesting_t, LRESULT>;
					static_assert(return_lresult, "on_touchhittesting with a return that is not LRESULT found.");
					auto result = this_cast<DerivedType>(this)->on_touchhittesting(ref_param_cast<TOUCH_HIT_TESTING_INPUT>(lparam));
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_POINTERWHEEL:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerwheel_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerwheel_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerwheel with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerwheel(pointerid, GET_WHEEL_DELTA_WPARAM(wparam), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_POINTERHWHEEL:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerhwheel_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerhwheel_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerhwheel with a return that is not void found. Ignoring return.");
					auto pointerid = GET_POINTERID_WPARAM(wparam);
					POINTER_INFO pi{};
					GetPointerInfo(pointerid, &pi);
					auto flags = pi.pointerFlags;
					auto &ptr_flags = ref_param_cast<pointer_data>(&flags);

					this_cast<DerivedType>(this)->on_pointerhwheel(pointerid, GET_WHEEL_DELTA_WPARAM(wparam), ptr_flags, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case DM_POINTERHITTEST:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerhittest_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerhittest_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerhittest with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_pointerhittest();
					handled = true;
				}
				break;
			}
			case WM_POINTERROUTEDTO:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerroutedto_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerroutedto_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerroutedto with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_pointerroutedto();
					handled = true;
				}
				break;
			}
			case WM_POINTERROUTEDAWAY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerroutedaway_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerroutedaway_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerroutedaway with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_pointerroutedaway();
					handled = true;
				}
				break;
			}
			case WM_POINTERROUTEDRELEASED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_pointerroutedreleased_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_pointerroutedreleased_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_pointerroutedreleased with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_pointerroutedreleased();
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
				if constexpr (detect_v<DerivedType, wmt::on_ncmousehover_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmousehover_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmousehover with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmousehover(param_cast<hittest_position>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_MOUSEHOVER:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mousehover_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mousehover_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mousehover with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mousehover(param_cast<mouse_vkey>(wparam), GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
					handled = true;
				}
				break;
			}
			case WM_NCMOUSELEAVE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_ncmouseleave_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_ncmouseleave_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_ncmouseleave with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_ncmouseleave();
					handled = true;
				}
				break;
			}
			case WM_MOUSELEAVE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_mouseleave_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_mouseleave_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_mouseleave with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_mouseleave();
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
				if constexpr (detect_v<DerivedType, wmt::on_wtssession_change_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_wtssession_change_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_wtssession_change with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_wtssession_change(param_cast<session_change_type>(wparam), param_cast<uint32_t>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_dpichanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dpichanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dpichanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dpichanged(LOWORD(wparam), HIWORD(wparam), ref_param_cast<RECT>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_dpichanged_beforeparent_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dpichanged_beforeparent_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dpichanged_beforeparent with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dpichanged_beforeparent();
					handled = true;
				}
				break;
			}
			case WM_DPICHANGED_AFTERPARENT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_dpichanged_afterparent_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dpichanged_afterparent_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dpichanged_afterparent with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dpichanged_afterparent();
					handled = true;
				}
				break;
			}
			case WM_GETDPISCALEDSIZE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_getdpiscaledsize_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_getdpiscaledsize_t, bool>;
					static_assert(convertable_bool, "on_getdpiscaledsize with a return that is not convertable to bool detected.");
					auto result = this_cast<DerivedType>(this)->on_getdpiscaledsize(param_cast<uint16_t>(wparam), ref_param_cast<RECT>(lparam)) == false ? FALSE : TRUE;
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
				if constexpr (detect_v<DerivedType, wmt::on_cut_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_cut_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_cut with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_cut();
					handled = true;
				}
				break;
			}
			case WM_COPY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_copy_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_copy_t, bool>;
					static_assert(convertable_bool, "on_copy with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_copy()) == false ? FALSE : TRUE;
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_PASTE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_paste_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_paste_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_paste with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_paste();
					handled = true;
				}
				break;
			}
			case WM_CLEAR:
			{
				if constexpr (detect_v<DerivedType, wmt::on_clear_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_clear_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_clear with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_clear();
					handled = true;
				}
				break;
			}
			case WM_UNDO:
			{
				if constexpr (detect_v<DerivedType, wmt::on_undo_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_undo_t, bool>;
					static_assert(convertable_bool, "on_undo with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_undo()) == false ? FALSE : TRUE;
					proc_result = result;
					handled = true;
				}
				break;
			}
			case WM_RENDERFORMAT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_renderformat_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_renderformat_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_renderformat with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_renderformat(param_cast<clipboard_format>(wparam));
					handled = true;
				}
				break;
			}
			case WM_RENDERALLFORMATS:
			{
				if constexpr (detect_v<DerivedType, wmt::on_renderallformats_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_renderallformats_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_renderallformats with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_renderallformats();
					handled = true;
				}
				break;
			}
			case WM_DESTROYCLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_destroyclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_destroyclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_destroyclipboard with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_destroyclipboard();
					handled = true;
				}
				break;
			}
			case WM_DRAWCLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_drawclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_drawclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_drawclipboard with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_drawclipboard();
					handled = true;
				}
				break;
			}
			case WM_PAINTCLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_paintclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_paintclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_paintclipboard with a return that is not void found. Ignoring return.");
					//The PAINTSTRUCT pointed to by lparam is allocated using GlobalAlloc, it must first be locked.
					auto ps_cache = handle_cast<HGLOBAL>(lparam);

					this_cast<DerivedType>(this)->on_paintclipboard(handle_cast<HWND>(wparam), ref_param_cast<PAINTSTRUCT>(GlobalLock(ps_cache)));
					GlobalUnlock(ps_cache);
					handled = true;
				}
				break;
			}
			case WM_VSCROLLCLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_vscrollclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_vscrollclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_vscrollclipboard with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_vscrollclipboard(handle_cast<HWND>(wparam), param_cast<vscrollbar_request>(lparam));
					handled = true;
				}
				break;
			}
			case WM_SIZECLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_sizeclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_sizeclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_sizeclipboard with a return that is not void found. Ignoring return.");
					//The RECT pointed to by lparam is allocated using GlobalAlloc, it must first be locked.
					auto rc_cache = handle_cast<HGLOBAL>(lparam);
					this_cast<DerivedType>(this)->on_sizeclipboard(handle_cast<HWND>(wparam), *param_cast<RECT *>(GlobalLock(rc_cache)));
					GlobalUnlock(rc_cache);
					handled = true;
				}
				break;
			}
			case WM_ASKCBFORMATNAME:
			{
				if constexpr (detect_v<DerivedType, wmt::on_askcbformatname_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_askcbformatname_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_askcbformatname with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_askcbformatname(param_cast<uintptr_t>(wparam), ptr_param_cast<wmt::msg_char_type>(lparam));
					handled = true;
				}
				break;
			}
			case WM_CHANGECBCHAIN:
			{
				if constexpr (detect_v<DerivedType, wmt::on_changecbchain_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_changecbchain_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_changecbchain with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_changecbchain(handle_cast<HWND>(wparam), handle_cast<HWND>(lparam));
					handled = true;
				}
				break;
			}
			case WM_HSCROLLCLIPBOARD:
			{
				if constexpr (detect_v<DerivedType, wmt::on_hscrollclipboard_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_hscrollclipboard_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_hscrollclipboard with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_hscrollclipboard(handle_cast<HWND>(wparam), param_cast<hscrollbar_request>(lparam));
					handled = true;
				}
				break;
			}
			case WM_QUERYNEWPALETTE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_querynewpalette_t>)
				{
					constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_querynewpalette_t, bool>;
					static_assert(convertable_bool, "on_querynewpalette with a return that is not convertable to bool found.");
					auto result = value_cast<bool>(this_cast<DerivedType>(this)->on_querynewpalette()) == false ? FALSE : TRUE;
					proc_result = return_cast(result);
					handled = true;
				}
				break;
			}
			case WM_PALETTEISCHANGING:
			{
				if constexpr (detect_v<DerivedType, wmt::on_paletteischanging_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_paletteischanging_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_paletteischanging with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_paletteischanging(handle_cast<HWND>(wparam));
					handled = true;
				}
				break;
			}
			case WM_PALETTECHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_palettechanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_palettechanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_palettechanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_palettechanged(handle_cast<HWND>(wparam));
					handled = true;
				}
				break;
			}
			case WM_HOTKEY:
			{
				if constexpr (detect_v<DerivedType, wmt::on_hotkey_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_hotkey_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_hotkey with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_hotkey(param_cast<uint32_t>(wparam), param_cast<hotkey_modifier>(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_print_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_print_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_print with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_print(handle_cast<HDC>(wparam), param_cast<print_flags>(lparam));
					handled = true;
				}
				break;
			}
			case WM_PRINTCLIENT:
			{
				if constexpr (detect_v<DerivedType, wmt::on_printclient_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_printclient_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_printclient with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_printclient(handle_cast<HDC>(wparam), param_cast<print_flags>(lparam));
					handled = true;
				}
				break;
			}
			case WM_APPCOMMAND:
			{
				if constexpr (detect_v<DerivedType, wmt::on_appcommand_t> || detect_v<DerivedType, wmt::get_commandhandler_t>)
				{
					appcommand_info info{ handle_cast<HWND>(wparam),
							value_cast<appcommand_command>(GET_APPCOMMAND_LPARAM(lparam)),
							value_cast<appcommand_device>(GET_DEVICE_LPARAM(lparam)),
							value_cast<appcommand_keys>(GET_KEYSTATE_LPARAM(lparam))
					};
					int32_t mouse_xpos{};
					int32_t mouse_ypos{};
					if ((info.device & appcommand_device::mouse) == appcommand_device::mouse)
					{
						auto pos = GetMessagePos();
						mouse_xpos = GET_X_LPARAM(pos);
						mouse_ypos = GET_Y_LPARAM(pos);
					}
					if constexpr (detect_v<DerivedType, wmt::on_appcommand_t>)
					{
						constexpr const bool convertable_bool = convertable_return_v<DerivedType, wmt::on_appcommand_t, bool>;
						if constexpr (return_type_assert) static_assert(convertable_bool, "on_appcommand with a return that is not convertable to bool found.");
						handled = this_cast<DerivedType>(this)->on_appcommand(info, mouse_xpos, mouse_ypos);
						//The documentation states that this should return true for legacy reasons.
						//It is the same reasons as the xbuttons.
						//We only return true if the message is handled.
						proc_result = handled == false ? FALSE : TRUE;
					}
					else
					{
						if constexpr (detect_v<DerivedType, wmt::get_commandhandler_t>)
						{
							constexpr const bool return_command_list = same_return_v<DerivedType, wmt::get_commandhandler_t, command_handler_list &>;
							constexpr const bool return_ccommand_list = same_return_v<DerivedType, wmt::get_commandhandler_t, const command_handler_list &>;
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
				if constexpr (detect_v<DerivedType, wmt::on_themechanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_themechanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_themechanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_themechanged();
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
				if constexpr (detect_v<DerivedType, wmt::on_clipboardupdate_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_clipboardupdate_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_clipboardupdate with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_clipboardupdate();
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
				if constexpr (detect_v<DerivedType, wmt::on_dwmncrenderingchanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dwmncrenderingchanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dwmncrenderingchanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dwmncrenderingchanged(param_cast<BOOL>(wparam) == FALSE ? false : true);
					handled = true;
				}
				break;
			}
			case WM_DWMCOLORIZATIONCOLORCHANGED:
			{
				if constexpr (detect_v<DerivedType, wmt::on_dwmcolorizationcolorchanged_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dwmcolorizationcolorchanged_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dwmcolorizationcolorchanged with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dwmcolorizationcolorchanged(param_cast<uint32_t>(wparam), param_cast<BOOL>(lparam) == FALSE ? false : true);
					handled = true;
				}
				break;
			}
			case WM_DWMWINDOWMAXIMIZEDCHANGE:
			{
				if constexpr (detect_v<DerivedType, wmt::on_dwmwindowmaximizedchange_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dwmwindowmaximizedchange_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dwmwindowmaximizedchange with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dwmwindowmaximizedchange(handle_cast<HWND>(wparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_dwmsendiconicthumbnail_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dwmsendiconicthumbnail_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dwmsendiconicthumbnail with a return that is not void found. Ignoring return.");
					//x is in the high word. Since we use the standard convention of x first, this requires us
					//to unpack the high value first.
					this_cast<DerivedType>(this)->on_dwmsendiconicthumbnail(HIWORD(lparam), LOWORD(lparam));
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
				if constexpr (detect_v<DerivedType, wmt::on_dwmsendiconiclivepreviewbitmap_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_dwmsendiconiclivepreviewbitmap_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_dwmsendiconiclivepreviewbitmap with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_dwmsendiconiclivepreviewbitmap();
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
				if constexpr (detect_v<DerivedType, wmt::on_gettitlebarinfoex_t>)
				{
					constexpr const bool return_void = same_return_v<DerivedType, wmt::on_gettitlebarinfoex_t, void>;
					if constexpr (return_type_assert) static_assert(return_void, "on_gettitlebarinfoex with a return that is not void found. Ignoring return.");
					this_cast<DerivedType>(this)->on_gettitlebarinfoex(ref_param_cast<TITLEBARINFOEX>(lparam));
					handled = true;
				}
				break;
			}
			default:
				break;
			}

			return make_pair(proc_result, handled);
		}

		LRESULT simple_default_message_handler(UINT msg, WPARAM wparam, LPARAM lparam)
		{
			auto [result, handled] = default_message_handler(msg, wparam, lparam);
			return handled == true ? result : message_handler(msg, wparam, lparam);
		}

		static LRESULT window_proc_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			auto that = my_type::inst_from_handle(wnd);
			LRESULT result{};
			if (that != nullptr)
			{
				result = that->message_handler(msg, wparam, lparam);

				if (msg == WM_NCDESTROY)
				{
					if constexpr (details::detect_v<DerivedType, window_msg_types::on_ncdestroy_t>)
					{
						//WM_NCDESTROY is documented to free internally allocated
						//memory. This would hint that we really want to pass this
						//message on to DefWindowProc too.
						//However, if the derived class doesn't handle WM_NCDESTROY
						//then we don't have to handle it.
						traits::WndDefWindowProc(wnd, msg, wparam, lparam);
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
				result = traits::WndDefWindowProc(wnd, msg, wparam, lparam);
			}

			return result;
		}

		static LRESULT window_proc_init_seh(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			static bool first_message = true;
			//A hook is used to get in front of the first call to this proc. This means that
			//the class instance is placed into the window before this proc is called for the
			//first time.
			auto that = my_type::inst_from_handle(wnd);
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
				LRESULT result = that->message_handler(msg, wparam, lparam);

				if constexpr (details::detect_v<DerivedType, window_msg_types::on_nccreate_t>)
				{
					//Even if the policy is set to call DefWindowProc on WM_NCCREATE, if
					//the message handler calls DefWindowProc, we don't want to follow this
					//policy.
					auto dwp_result = window_default_nccreate_policy<DerivedType, UnicodeBase>::call_defwindowproc_nccreate(wnd, wparam, lparam);
					result = result == FALSE ? FALSE : dwp_result;
				}

				m_proc = window_proc_seh;

				return result;
			}
		}

		static LRESULT CALLBACK window_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			_EXCEPTION_POINTERS *ei = nullptr;
			__try
			{
				return m_proc(wnd, msg, wparam, lparam);
			}
			__except ([&ei](auto &&p) {ei = p; return EXCEPTION_EXECUTE_HANDLER; }(GetExceptionInformation()))
			{
				application::helper::writeln_debugger("Uncaught exception reached the window procedure.");
				RaiseFailFastException(ei->ExceptionRecord, ei->ContextRecord, FAIL_FAST_GENERATE_EXCEPTION_ADDRESS);
			}

			__fastfail(FAST_FAIL_FATAL_APP_EXIT);
			//The compiler complains that not all control paths return a value even though
			//it has to go through RaiseFailFastException and __fastfail.
			return traits::WndDefWindowProc(wnd, msg, wparam, lparam);
		}

		static my_tptr inst_from_handle(HWND wnd)
		{
			using details::inst_cast;
			my_tptr ptr = inst_cast<my_t>(prop_traits::get_property(wnd, prop_type::instance));
			return ptr;
		}

		static void handle_first_message(HWND wnd)
		{
			auto that = inst_from_handle(wnd);
			auto dpi = GetDpiForWindow(wnd);
			that->set_dpi(dpi);
			that->track_mouse();
		}

		static void handle_ncdestroy(HWND wnd)
		{
			//Remove the class pointer from the window and then we delete the class
			auto that = my_type::inst_from_handle(wnd);
			that->notify_window_close();
			that->untrack_mouse();
			that->cleanup_window_info();

			prop_traits::remove_property(wnd, prop_type::instance);
			delete that;

			window_post_quit_policy<DerivedType>::post_quit_message(0);
		}

		template <typename Definitions>
		static std::pair<bool, std::basic_string<typename traits::char_t>> default_register_from_definition(HINSTANCE inst)
		{
			using namespace std;
			using namespace details;
			using namespace details::class_detect;

			using my_definitions = Definitions;
			std::basic_string<typename traits::char_t> my_class_name;
			bool result = false;

			if constexpr (detect_v<my_definitions, class_definition_types::existing_class_name_t>)
			{
				static_assert(detect_v<my_definitions, class_definition_types::class_name_t>);
				my_class_name = std::basic_string<typename traits::char_t>{ my_definitions::class_name };
				result = window_base::is_class_registered(std::basic_string_view<typename traits::char_t>{my_class_name});
			}
			else
			{
				typename traits::wndclassex_t wcx{ sizeof(typename traits::wndclassex_t) };

				wcx.lpfnWndProc = my_type::window_proc;
				wcx.hInstance = inst;
				my_class_name = std::basic_string<typename traits::char_t>{ my_definitions::class_name };

				wcx.style = style_value<my_definitions>::get_value();
				wcx.cbClsExtra = class_extra_value<my_definitions>::get_value();
				wcx.cbWndExtra = window_extra_value<my_definitions>::get_value();
				wcx.hIcon = icon_value<my_definitions>::get_value();
				wcx.hCursor = cursor_value<my_definitions>::get_value();
				wcx.hbrBackground = brush_value<my_definitions>::get_value();
				wcx.lpszMenuName = menu_name_value<my_definitions>::get_value();
				wcx.lpszClassName = my_class_name.data();
				wcx.hIconSm = small_icon_value<my_definitions>::get_value();

				result = window_base::register_class(wcx);
			}

			return { result, my_class_name };
		}

		template <typename Definitions>
		static bool default_create_window_from_definition(DerivedType *ptr, const std::basic_string<typename traits::char_t> &class_name)
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

			auto style_cache = style_value<Definitions>::get_value();
			auto ex_style_cache = ex_style_value<Definitions>::get_value();
			std::basic_string<typename traits::char_t> window_name_cache;
			if constexpr (detect_v<Definitions, window_definition_types::window_name_t>)
			{
				window_name_cache = std::basic_string<typename traits::char_t>{ Definitions::window_name };
			}
			auto parent_cache = parent_value<Definitions>::get_value();
			HMENU menu_cache = nullptr;
			if constexpr (detect_v<Definitions, window_definition_types::menu_t>)
			{
				if (parent_cache)
				{
					constexpr const auto is_integral = std::is_integral_v<window_definition_types::menu_t<Definitions>>;
					if constexpr (is_integral)
					{
						//Parent window is set. Check HMENU for an identifier.
						menu_cache = reinterpret_cast<HMENU>(menu_value_child<Definitions>::get_value());
					}
				}
				else
				{
					constexpr const auto is_hmenu = std::is_same_v<window_definition_types::menu_t<Definitions>, HMENU>;
					if constexpr (is_hmenu)
					{
						menu_cache = menu_value_nonchild<Definitions>::get_value();
					}
				}
			}

			return window_t::create_window(class_name, window_name_cache, style_cache, ex_style_cache, position_cache, size_cache, ptr, parent_cache, menu_cache);
		}

		static auto default_create() -> DerivedType *
		{
			using namespace std;
			using namespace details;

			DerivedType *ptr = nullptr;
			HINSTANCE inst = nullptr;
			std::basic_string<typename traits::char_t> class_name;
			try
			{
				{
					using namespace details::class_detect;
					if constexpr (detect_class_definitions_typedef_v<DerivedType>)
					{
						//This is needed early.
						using my_definitions = typename DerivedType::class_definitions;
						inst = instance_value<my_definitions>::get_value();
						ptr = new DerivedType(inst);

						auto [success, return_class_name] = default_register_from_definition<my_definitions>(inst);

						if (!success)
						{
							delete ptr;
							ptr = nullptr;
						}
						//The class name needs to be stashed for CreateWindowEx.
						class_name = return_class_name;
					}
					else
					{
						if constexpr (detect_class_definitions_v<DerivedType>)
						{
							//This is needed early.
							using my_definitions = class_definitions<DerivedType>;
							inst = instance_value<my_definitions>::get_value();
							ptr = new DerivedType(inst);

							auto [success, return_class_name] = default_register_from_definition<my_definitions>(inst);

							if (!success)
							{
								delete ptr;
								ptr = nullptr;
							}
							//The class name needs to be stashed for CreateWindowEx.
							class_name = return_class_name;
						}
					}
				}

				if (ptr != nullptr)
				{
					{
						using namespace details::window_detect;
						if constexpr (detect_window_definitions_typedef_v<DerivedType>)
						{
							using my_definitions = typename DerivedType::window_definitions;
							if (!default_create_window_from_definition<my_definitions>(ptr, class_name))
							{
								delete ptr;
								ptr = nullptr;
							}
						}
						else
						{
							if constexpr (detect_window_definitions_v<DerivedType>)
							{
								using my_definitions = window_definitions<DerivedType>;
								if (!default_create_window_from_definition<my_definitions>(ptr, class_name))
								{
									delete ptr;
									ptr = nullptr;
								}
							}
						}
					}
				}
			}
			catch (...)
			{
				delete ptr;
				throw;
			}

			return ptr;
		}
	private:
		window_t() = delete;
		window_t(const window_t &) = delete;
		window_t(window_t &&) = delete;
		window_t &operator=(const window_t &) = delete;
		window_t &operator=(window_t &&) = delete;

		static inline std::function<LRESULT(HWND, UINT, WPARAM, LPARAM)> m_proc{ window_proc_init_seh };

		static inline thread_local HHOOK s_create_hook = nullptr;
	};
}