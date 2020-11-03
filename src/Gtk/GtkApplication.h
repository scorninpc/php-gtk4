#ifndef _PHPGTK_gtkapplication_H_
#define _PHPGTK_gtkapplication_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../G/GObject.h"
#include "../../helper.h"

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, application_id)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, __construct);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_add_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, add_window);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_remove_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, remove_window);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_windows, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_windows);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_app_menu, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_app_menu);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_set_app_menu, 0, 0, 1)
	ZEND_ARG_INFO(0, app_menu)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, set_app_menu);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_menubar, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_menubar);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_set_menubar, 0, 0, 1)
	ZEND_ARG_INFO(0, menubar)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, set_menubar);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_inhibit, 0, 0, 3)
	ZEND_ARG_INFO(0, window)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, reason)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, inhibit);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_uninhibit, 0, 0, 1)
	ZEND_ARG_INFO(0, cookie)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, uninhibit);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_is_inhibited, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, is_inhibited);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_window_by_id, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_window_by_id);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_active_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_active_window);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_list_action_descriptions, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, list_action_descriptions);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_accels_for_action, 0, 0, 1)
	ZEND_ARG_INFO(0, detailed_action_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_accels_for_action);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_actions_for_accel, 0, 0, 1)
	ZEND_ARG_INFO(0, accel)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_actions_for_accel);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_set_accels_for_action, 0, 0, 2)
	ZEND_ARG_INFO(0, detailed_action_name)
	ZEND_ARG_INFO(0, accels)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, set_accels_for_action);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_prefers_app_menu, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, prefers_app_menu);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_get_menu_by_id, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, get_menu_by_id);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplication_window_new, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplication, window_new);

// -------------------
static zend_class_entry *gtk4_gtkapplication_ce = NULL;
static const zend_function_entry gtkapplication_functions[] = {
	PHP_ME(GtkApplication, __construct, arginfo_gtkapplication___construct, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, add_window, arginfo_gtkapplication_add_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, remove_window, arginfo_gtkapplication_remove_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_windows, arginfo_gtkapplication_get_windows, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_app_menu, arginfo_gtkapplication_get_app_menu, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, set_app_menu, arginfo_gtkapplication_set_app_menu, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_menubar, arginfo_gtkapplication_get_menubar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, set_menubar, arginfo_gtkapplication_set_menubar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, inhibit, arginfo_gtkapplication_inhibit, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, uninhibit, arginfo_gtkapplication_uninhibit, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, is_inhibited, arginfo_gtkapplication_is_inhibited, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_window_by_id, arginfo_gtkapplication_get_window_by_id, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_active_window, arginfo_gtkapplication_get_active_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, list_action_descriptions, arginfo_gtkapplication_list_action_descriptions, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_accels_for_action, arginfo_gtkapplication_get_accels_for_action, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_actions_for_accel, arginfo_gtkapplication_get_actions_for_accel, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, set_accels_for_action, arginfo_gtkapplication_set_accels_for_action, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, prefers_app_menu, arginfo_gtkapplication_prefers_app_menu, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, get_menu_by_id, arginfo_gtkapplication_get_menu_by_id, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplication, window_new, arginfo_gtkapplication_window_new, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif