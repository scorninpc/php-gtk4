#ifndef _PHPGTK_GDKEVENT_H_
#define _PHPGTK_GDKEVENT_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_copy, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, copy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_free, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, free);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_axis, 0, 0, 1)
	ZEND_ARG_INFO(0, axis_use)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_axis);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_button, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_button);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_click_count, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_click_count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_coords, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_coords);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_device, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_device);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_device_tool, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_device_tool);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_event_sequence, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_event_sequence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_event_type, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_event_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_keycode, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_keycode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_keyval, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_keyval);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_pointer_emulated, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_pointer_emulated);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_root_coords, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_root_coords);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_scancode, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_scancode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_screen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_scroll_deltas, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_scroll_deltas);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_scroll_direction, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_scroll_direction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_seat, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_seat);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_source_device, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_source_device);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_state, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_time, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_time);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_is_scroll_stop_event, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, is_scroll_stop_event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_put, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, put);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_set_device, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, set_device);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_set_device_tool, 0, 0, 1)
	ZEND_ARG_INFO(0, tool)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, set_device_tool);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_set_screen, 0, 0, 1)
	ZEND_ARG_INFO(0, screen)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, set_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_set_source_device, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, set_source_device);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_triggers_context_menu, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, triggers_context_menu);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_angle, 0, 0, 1)
	ZEND_ARG_INFO(0, event2)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_angle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_center, 0, 0, 1)
	ZEND_ARG_INFO(0, event2)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_center);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkevent_get_distance, 0, 0, 1)
	ZEND_ARG_INFO(0, event2)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkEvent, get_distance);

static zend_class_entry *gtk4_gdkevent_ce = NULL;
static const zend_function_entry gdkevent_functions[] = {
	PHP_ME(GdkEvent, __construct, arginfo_gdkevent___construct, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, copy, arginfo_gdkevent_copy, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, free, arginfo_gdkevent_free, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_axis, arginfo_gdkevent_get_axis, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_button, arginfo_gdkevent_get_button, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_click_count, arginfo_gdkevent_get_click_count, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_coords, arginfo_gdkevent_get_coords, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_device, arginfo_gdkevent_get_device, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_device_tool, arginfo_gdkevent_get_device_tool, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_event_sequence, arginfo_gdkevent_get_event_sequence, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_event_type, arginfo_gdkevent_get_event_type, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_keycode, arginfo_gdkevent_get_keycode, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_keyval, arginfo_gdkevent_get_keyval, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_pointer_emulated, arginfo_gdkevent_get_pointer_emulated, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_root_coords, arginfo_gdkevent_get_root_coords, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_scancode, arginfo_gdkevent_get_scancode, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_screen, arginfo_gdkevent_get_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_scroll_deltas, arginfo_gdkevent_get_scroll_deltas, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_scroll_direction, arginfo_gdkevent_get_scroll_direction, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_seat, arginfo_gdkevent_get_seat, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_source_device, arginfo_gdkevent_get_source_device, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_state, arginfo_gdkevent_get_state, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_time, arginfo_gdkevent_get_time, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_window, arginfo_gdkevent_get_window, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, is_scroll_stop_event, arginfo_gdkevent_is_scroll_stop_event, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, put, arginfo_gdkevent_put, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, set_device, arginfo_gdkevent_set_device, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, set_device_tool, arginfo_gdkevent_set_device_tool, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, set_screen, arginfo_gdkevent_set_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, set_source_device, arginfo_gdkevent_set_source_device, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, triggers_context_menu, arginfo_gdkevent_triggers_context_menu, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_angle, arginfo_gdkevent_get_angle, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_center, arginfo_gdkevent_get_center, ZEND_ACC_PUBLIC)
	PHP_ME(GdkEvent, get_distance, arginfo_gdkevent_get_distance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
