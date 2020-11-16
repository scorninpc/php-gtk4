#ifndef _PHPGTK_GTKWINDOW_H_
#define _PHPGTK_GTKWINDOW_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_activate_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, activate_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_activate_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, activate_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_activate_key, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, activate_key);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_add_accel_group, 0, 0, 1)
	ZEND_ARG_INFO(0, accel_group)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, add_accel_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_add_mnemonic, 0, 0, 2)
	ZEND_ARG_INFO(0, keyval)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, add_mnemonic);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_begin_move_drag, 0, 0, 4)
	ZEND_ARG_INFO(0, button)
	ZEND_ARG_INFO(0, root_x)
	ZEND_ARG_INFO(0, root_y)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, begin_move_drag);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_begin_resize_drag, 0, 0, 5)
	ZEND_ARG_INFO(0, edge)
	ZEND_ARG_INFO(0, button)
	ZEND_ARG_INFO(0, root_x)
	ZEND_ARG_INFO(0, root_y)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, begin_resize_drag);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_close, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_deiconify, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, deiconify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_fullscreen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, fullscreen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_fullscreen_on_monitor, 0, 0, 2)
	ZEND_ARG_INFO(0, screen)
	ZEND_ARG_INFO(0, monitor)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, fullscreen_on_monitor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_accept_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_accept_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_application, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_application);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_attached_to, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_attached_to);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_decorated, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_decorated);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_default_size, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_default_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_default_widget, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_default_widget);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_deletable, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_deletable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_destroy_with_parent, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_destroy_with_parent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_focus_on_map, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_focus_on_map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_focus_visible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_focus_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_gravity, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_gravity);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_group, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_hide_titlebar_when_maximized, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_hide_titlebar_when_maximized);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_icon, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_icon);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_icon_list, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_icon_list);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_icon_name, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_icon_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_mnemonic_modifier, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_mnemonic_modifier);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_mnemonics_visible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_mnemonics_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_modal, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_modal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_position, 0, 0, 2)
	ZEND_ARG_INFO(0, root_x)
	ZEND_ARG_INFO(0, root_y)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_position);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_resizable, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_resizable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_role, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_role);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_screen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_size, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_skip_pager_hint, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_skip_pager_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_skip_taskbar_hint, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_skip_taskbar_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_title, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_title);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_titlebar, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_titlebar);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_transient_for, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_transient_for);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_type_hint, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_type_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_urgency_hint, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_urgency_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_window_type, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, get_window_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_has_group, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, has_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_has_toplevel_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, has_toplevel_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_iconify, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, iconify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_is_active, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, is_active);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_is_maximized, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, is_maximized);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_maximize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, maximize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_mnemonic_activate, 0, 0, 2)
	ZEND_ARG_INFO(0, keyval)
	ZEND_ARG_INFO(0, modifier)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, mnemonic_activate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_move, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, move);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_present, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, present);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_present_with_time, 0, 0, 1)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, present_with_time);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_propagate_key_event, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, propagate_key_event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_remove_accel_group, 0, 0, 1)
	ZEND_ARG_INFO(0, accel_group)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, remove_accel_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_remove_mnemonic, 0, 0, 2)
	ZEND_ARG_INFO(0, keyval)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, remove_mnemonic);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, resize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_accept_focus, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_accept_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_application, 0, 0, 1)
	ZEND_ARG_INFO(0, application)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_application);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_attached_to, 0, 0, 1)
	ZEND_ARG_INFO(0, attach_widget)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_attached_to);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_decorated, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_decorated);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_default, 0, 0, 1)
	ZEND_ARG_INFO(0, default_widget)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_default_size, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_default_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_deletable, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_deletable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_destroy_with_parent, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_destroy_with_parent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_focus, 0, 0, 1)
	ZEND_ARG_INFO(0, focus)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_focus_on_map, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_focus_on_map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_focus_visible, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_focus_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_geometry_hints, 0, 0, 3)
	ZEND_ARG_INFO(0, geometry_widget)
	ZEND_ARG_INFO(0, geometry)
	ZEND_ARG_INFO(0, geom_mask)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_geometry_hints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_gravity, 0, 0, 1)
	ZEND_ARG_INFO(0, gravity)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_gravity);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_has_user_ref_count, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_has_user_ref_count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_hide_titlebar_when_maximized, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_hide_titlebar_when_maximized);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_icon, 0, 0, 1)
	ZEND_ARG_INFO(0, icon)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_icon);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_icon_from_file, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_icon_from_file);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_icon_list, 0, 0, 1)
	ZEND_ARG_INFO(0, list)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_icon_list);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_icon_name, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_icon_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_keep_above, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_keep_above);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_keep_below, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_keep_below);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_mnemonic_modifier, 0, 0, 1)
	ZEND_ARG_INFO(0, modifier)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_mnemonic_modifier);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_mnemonics_visible, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_mnemonics_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_modal, 0, 0, 1)
	ZEND_ARG_INFO(0, modal)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_modal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_position, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_position);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_resizable, 0, 0, 1)
	ZEND_ARG_INFO(0, resizable)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_resizable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_role, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_role);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_screen, 0, 0, 1)
	ZEND_ARG_INFO(0, screen)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_skip_pager_hint, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_skip_pager_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_skip_taskbar_hint, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_skip_taskbar_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_startup_id, 0, 0, 1)
	ZEND_ARG_INFO(0, startup_id)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_startup_id);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_title, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_title);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_titlebar, 0, 0, 1)
	ZEND_ARG_INFO(0, titlebar)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_titlebar);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_transient_for, 0, 0, 1)
	ZEND_ARG_INFO(0, parent)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_transient_for);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_type_hint, 0, 0, 1)
	ZEND_ARG_INFO(0, hint)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_type_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_urgency_hint, 0, 0, 1)
	ZEND_ARG_INFO(0, setting)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, set_urgency_hint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_stick, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, stick);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_unfullscreen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, unfullscreen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_unmaximize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, unmaximize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_unstick, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWindow, unstick);

static zend_class_entry *gtk4_gtkwindow_ce = NULL;
static const zend_function_entry gtkwindow_functions[] = {
	PHP_ME(GtkWindow, __construct, arginfo_gtkwindow___construct, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, activate_default, arginfo_gtkwindow_activate_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, activate_focus, arginfo_gtkwindow_activate_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, activate_key, arginfo_gtkwindow_activate_key, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, add_accel_group, arginfo_gtkwindow_add_accel_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, add_mnemonic, arginfo_gtkwindow_add_mnemonic, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, begin_move_drag, arginfo_gtkwindow_begin_move_drag, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, begin_resize_drag, arginfo_gtkwindow_begin_resize_drag, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, close, arginfo_gtkwindow_close, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, deiconify, arginfo_gtkwindow_deiconify, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, fullscreen, arginfo_gtkwindow_fullscreen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, fullscreen_on_monitor, arginfo_gtkwindow_fullscreen_on_monitor, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_accept_focus, arginfo_gtkwindow_get_accept_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_application, arginfo_gtkwindow_get_application, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_attached_to, arginfo_gtkwindow_get_attached_to, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_decorated, arginfo_gtkwindow_get_decorated, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_default_size, arginfo_gtkwindow_get_default_size, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_default_widget, arginfo_gtkwindow_get_default_widget, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_deletable, arginfo_gtkwindow_get_deletable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_destroy_with_parent, arginfo_gtkwindow_get_destroy_with_parent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_focus, arginfo_gtkwindow_get_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_focus_on_map, arginfo_gtkwindow_get_focus_on_map, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_focus_visible, arginfo_gtkwindow_get_focus_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_gravity, arginfo_gtkwindow_get_gravity, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_group, arginfo_gtkwindow_get_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_hide_titlebar_when_maximized, arginfo_gtkwindow_get_hide_titlebar_when_maximized, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_icon, arginfo_gtkwindow_get_icon, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_icon_list, arginfo_gtkwindow_get_icon_list, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_icon_name, arginfo_gtkwindow_get_icon_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_mnemonic_modifier, arginfo_gtkwindow_get_mnemonic_modifier, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_mnemonics_visible, arginfo_gtkwindow_get_mnemonics_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_modal, arginfo_gtkwindow_get_modal, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_position, arginfo_gtkwindow_get_position, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_resizable, arginfo_gtkwindow_get_resizable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_role, arginfo_gtkwindow_get_role, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_screen, arginfo_gtkwindow_get_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_size, arginfo_gtkwindow_get_size, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_skip_pager_hint, arginfo_gtkwindow_get_skip_pager_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_skip_taskbar_hint, arginfo_gtkwindow_get_skip_taskbar_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_title, arginfo_gtkwindow_get_title, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_titlebar, arginfo_gtkwindow_get_titlebar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_transient_for, arginfo_gtkwindow_get_transient_for, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_type_hint, arginfo_gtkwindow_get_type_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_urgency_hint, arginfo_gtkwindow_get_urgency_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, get_window_type, arginfo_gtkwindow_get_window_type, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, has_group, arginfo_gtkwindow_has_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, has_toplevel_focus, arginfo_gtkwindow_has_toplevel_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, iconify, arginfo_gtkwindow_iconify, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, is_active, arginfo_gtkwindow_is_active, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, is_maximized, arginfo_gtkwindow_is_maximized, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, maximize, arginfo_gtkwindow_maximize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, mnemonic_activate, arginfo_gtkwindow_mnemonic_activate, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, move, arginfo_gtkwindow_move, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, present, arginfo_gtkwindow_present, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, present_with_time, arginfo_gtkwindow_present_with_time, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, propagate_key_event, arginfo_gtkwindow_propagate_key_event, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, remove_accel_group, arginfo_gtkwindow_remove_accel_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, remove_mnemonic, arginfo_gtkwindow_remove_mnemonic, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, resize, arginfo_gtkwindow_resize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_accept_focus, arginfo_gtkwindow_set_accept_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_application, arginfo_gtkwindow_set_application, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_attached_to, arginfo_gtkwindow_set_attached_to, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_decorated, arginfo_gtkwindow_set_decorated, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_default, arginfo_gtkwindow_set_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_default_size, arginfo_gtkwindow_set_default_size, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_deletable, arginfo_gtkwindow_set_deletable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_destroy_with_parent, arginfo_gtkwindow_set_destroy_with_parent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_focus, arginfo_gtkwindow_set_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_focus_on_map, arginfo_gtkwindow_set_focus_on_map, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_focus_visible, arginfo_gtkwindow_set_focus_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_geometry_hints, arginfo_gtkwindow_set_geometry_hints, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_gravity, arginfo_gtkwindow_set_gravity, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_has_user_ref_count, arginfo_gtkwindow_set_has_user_ref_count, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_hide_titlebar_when_maximized, arginfo_gtkwindow_set_hide_titlebar_when_maximized, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_icon, arginfo_gtkwindow_set_icon, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_icon_from_file, arginfo_gtkwindow_set_icon_from_file, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_icon_list, arginfo_gtkwindow_set_icon_list, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_icon_name, arginfo_gtkwindow_set_icon_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_keep_above, arginfo_gtkwindow_set_keep_above, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_keep_below, arginfo_gtkwindow_set_keep_below, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_mnemonic_modifier, arginfo_gtkwindow_set_mnemonic_modifier, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_mnemonics_visible, arginfo_gtkwindow_set_mnemonics_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_modal, arginfo_gtkwindow_set_modal, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_position, arginfo_gtkwindow_set_position, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_resizable, arginfo_gtkwindow_set_resizable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_role, arginfo_gtkwindow_set_role, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_screen, arginfo_gtkwindow_set_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_skip_pager_hint, arginfo_gtkwindow_set_skip_pager_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_skip_taskbar_hint, arginfo_gtkwindow_set_skip_taskbar_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_startup_id, arginfo_gtkwindow_set_startup_id, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_title, arginfo_gtkwindow_set_title, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_titlebar, arginfo_gtkwindow_set_titlebar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_transient_for, arginfo_gtkwindow_set_transient_for, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_type_hint, arginfo_gtkwindow_set_type_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, set_urgency_hint, arginfo_gtkwindow_set_urgency_hint, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, stick, arginfo_gtkwindow_stick, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, unfullscreen, arginfo_gtkwindow_unfullscreen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, unmaximize, arginfo_gtkwindow_unmaximize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWindow, unstick, arginfo_gtkwindow_unstick, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
