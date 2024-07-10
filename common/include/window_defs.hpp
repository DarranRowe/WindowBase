#pragma once

#ifndef __cplusplus
#error C++ Compiler Required
#endif

namespace windowing
{
	enum class prop_type
	{
		instance,
		mouse_track,
		mouse_track_hook,
		register_callback,
		message_callback
	};
}