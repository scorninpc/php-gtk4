#ifndef _PHPGTK_GDKDISPLAY_H_
#define _PHPGTK_GDKDISPLAY_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_beep, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, beep);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_close, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_device_is_grabbed, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, device_is_grabbed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_flush, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_app_launch_context, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_app_launch_context);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_default_cursor_size, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_default_cursor_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_default_group, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_default_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_default_screen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_default_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_event, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_maximal_cursor_size, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_maximal_cursor_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_monitor, 0, 0, 1)
	ZEND_ARG_INFO(0, monitor_num)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_monitor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_monitor_at_point, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_monitor_at_point);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_monitor_at_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_monitor_at_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_n_monitors, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_n_monitors);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_name, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_primary_monitor, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_primary_monitor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_has_pending, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, has_pending);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_is_closed, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, is_closed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_list_seats, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, list_seats);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_notify_startup_complete, 0, 0, 1)
	ZEND_ARG_INFO(0, startup_id)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, notify_startup_complete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_peek_event, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, peek_event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_put_event, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, put_event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_request_selection_notification, 0, 0, 1)
	ZEND_ARG_INFO(0, selection)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, request_selection_notification);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_set_double_click_distance, 0, 0, 1)
	ZEND_ARG_INFO(0, distance)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, set_double_click_distance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_set_double_click_time, 0, 0, 1)
	ZEND_ARG_INFO(0, msec)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, set_double_click_time);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_store_clipboard, 0, 0, 4)
	ZEND_ARG_INFO(0, clipboard_window)
	ZEND_ARG_INFO(0, time_)
	ZEND_ARG_INFO(0, targets)
	ZEND_ARG_INFO(0, n_targets)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, store_clipboard);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_clipboard_persistence, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_clipboard_persistence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_cursor_alpha, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_cursor_alpha);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_cursor_color, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_cursor_color);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_input_shapes, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_input_shapes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_selection_notification, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_selection_notification);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_supports_shapes, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, supports_shapes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_sync, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, sync);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_get_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, get_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_manager_get, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, manager_get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gdkdisplay_open, 0, 0, 1)
	ZEND_ARG_INFO(0, display_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GdkDisplay, open);

static zend_class_entry *gtk4_gdkdisplay_ce = NULL;
static const zend_function_entry gdkdisplay_functions[] = {
	PHP_ME(GdkDisplay, beep, arginfo_gdkdisplay_beep, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, close, arginfo_gdkdisplay_close, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, device_is_grabbed, arginfo_gdkdisplay_device_is_grabbed, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, flush, arginfo_gdkdisplay_flush, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_app_launch_context, arginfo_gdkdisplay_get_app_launch_context, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_default_cursor_size, arginfo_gdkdisplay_get_default_cursor_size, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_default_group, arginfo_gdkdisplay_get_default_group, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_default_screen, arginfo_gdkdisplay_get_default_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_event, arginfo_gdkdisplay_get_event, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_maximal_cursor_size, arginfo_gdkdisplay_get_maximal_cursor_size, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_monitor, arginfo_gdkdisplay_get_monitor, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_monitor_at_point, arginfo_gdkdisplay_get_monitor_at_point, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_monitor_at_window, arginfo_gdkdisplay_get_monitor_at_window, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_n_monitors, arginfo_gdkdisplay_get_n_monitors, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_name, arginfo_gdkdisplay_get_name, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_primary_monitor, arginfo_gdkdisplay_get_primary_monitor, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, has_pending, arginfo_gdkdisplay_has_pending, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, is_closed, arginfo_gdkdisplay_is_closed, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, list_seats, arginfo_gdkdisplay_list_seats, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, notify_startup_complete, arginfo_gdkdisplay_notify_startup_complete, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, peek_event, arginfo_gdkdisplay_peek_event, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, put_event, arginfo_gdkdisplay_put_event, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, request_selection_notification, arginfo_gdkdisplay_request_selection_notification, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, set_double_click_distance, arginfo_gdkdisplay_set_double_click_distance, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, set_double_click_time, arginfo_gdkdisplay_set_double_click_time, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, store_clipboard, arginfo_gdkdisplay_store_clipboard, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_clipboard_persistence, arginfo_gdkdisplay_supports_clipboard_persistence, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_cursor_alpha, arginfo_gdkdisplay_supports_cursor_alpha, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_cursor_color, arginfo_gdkdisplay_supports_cursor_color, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_input_shapes, arginfo_gdkdisplay_supports_input_shapes, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_selection_notification, arginfo_gdkdisplay_supports_selection_notification, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, supports_shapes, arginfo_gdkdisplay_supports_shapes, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, sync, arginfo_gdkdisplay_sync, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, get_default, arginfo_gdkdisplay_get_default, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(GdkDisplay, manager_get, arginfo_gdkdisplay_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(GdkDisplay, open, arginfo_gdkdisplay_open, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
