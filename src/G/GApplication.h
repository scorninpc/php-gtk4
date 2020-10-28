#ifndef _PHPGTK_gapplication_H_
#define _PHPGTK_gapplication_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../G/GObject.h"

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, application_id)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, __construct);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_application_id, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_application_id);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_application_id, 0, 0, 1)
	ZEND_ARG_INFO(0, application_id)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_application_id);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_dbus_connection, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_dbus_connection);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_dbus_object_path, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_dbus_object_path);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_inactivity_timeout, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_inactivity_timeout);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_inactivity_timeout, 0, 0, 1)
	ZEND_ARG_INFO(0, inactivity_timeout)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_inactivity_timeout);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_flags, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_flags);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_flags, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_flags);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_resource_base_path, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_resource_base_path);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_resource_base_path, 0, 0, 1)
	ZEND_ARG_INFO(0, resource_path)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_resource_base_path);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_action_group, 0, 0, 1)
	ZEND_ARG_INFO(0, action_group)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_action_group);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_add_main_option_entries, 0, 0, 1)
	ZEND_ARG_INFO(0, entries)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, add_main_option_entries);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_add_main_option, 0, 0, 6)
	ZEND_ARG_INFO(0, long_name)
	ZEND_ARG_INFO(0, short_name)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, arg)
	ZEND_ARG_INFO(0, description)
	ZEND_ARG_INFO(0, arg_description)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, add_main_option);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_add_option_group, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, add_option_group);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_option_context_parameter_string, 0, 0, 1)
	ZEND_ARG_INFO(0, parameter_string)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_option_context_parameter_string);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_option_context_summary, 0, 0, 1)
	ZEND_ARG_INFO(0, summary)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_option_context_summary);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_option_context_description, 0, 0, 1)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_option_context_description);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_is_registered, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_is_registered);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_is_remote, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_is_remote);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_register, 0, 0, 2)
	ZEND_ARG_INFO(0, cancellable)
	ZEND_ARG_INFO(0, error)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, register);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_hold, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, hold);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_release, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, release);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_activate, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, activate);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_open, 0, 0, 3)
	ZEND_ARG_INFO(0, files)
	ZEND_ARG_INFO(0, n_files)
	ZEND_ARG_INFO(0, hint)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, open);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_run, 0, 0, 2)
	ZEND_ARG_INFO(0, argc)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, run);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_quit, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, quit);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_set_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, set_default);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_mark_busy, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, mark_busy);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_unmark_busy, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, unmark_busy);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_get_is_busy, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, get_is_busy);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_send_notification, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, notification)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, send_notification);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_withdraw_notification, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, withdraw_notification);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_bind_busy_property, 0, 0, 2)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, bind_busy_property);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gapplication_unbind_busy_property, 0, 0, 2)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

PHP_METHOD(GApplication, unbind_busy_property);

// -------------------
static zend_class_entry *gtk4_gapplication_ce = NULL;
static const zend_function_entry gapplication_functions[] = {
	PHP_ME(GApplication, __construct, arginfo_gapplication___construct, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_application_id, arginfo_gapplication_get_application_id, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_application_id, arginfo_gapplication_set_application_id, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_dbus_connection, arginfo_gapplication_get_dbus_connection, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_dbus_object_path, arginfo_gapplication_get_dbus_object_path, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_inactivity_timeout, arginfo_gapplication_get_inactivity_timeout, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_inactivity_timeout, arginfo_gapplication_set_inactivity_timeout, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_flags, arginfo_gapplication_get_flags, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_flags, arginfo_gapplication_set_flags, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_resource_base_path, arginfo_gapplication_get_resource_base_path, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_resource_base_path, arginfo_gapplication_set_resource_base_path, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_action_group, arginfo_gapplication_set_action_group, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, add_main_option_entries, arginfo_gapplication_add_main_option_entries, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, add_main_option, arginfo_gapplication_add_main_option, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, add_option_group, arginfo_gapplication_add_option_group, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_option_context_parameter_string, arginfo_gapplication_set_option_context_parameter_string, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_option_context_summary, arginfo_gapplication_set_option_context_summary, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_option_context_description, arginfo_gapplication_set_option_context_description, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_is_registered, arginfo_gapplication_get_is_registered, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_is_remote, arginfo_gapplication_get_is_remote, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, register, arginfo_gapplication_register, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, hold, arginfo_gapplication_hold, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, release, arginfo_gapplication_release, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, activate, arginfo_gapplication_activate, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, open, arginfo_gapplication_open, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, run, arginfo_gapplication_run, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, quit, arginfo_gapplication_quit, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, set_default, arginfo_gapplication_set_default, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, mark_busy, arginfo_gapplication_mark_busy, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, unmark_busy, arginfo_gapplication_unmark_busy, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, get_is_busy, arginfo_gapplication_get_is_busy, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, send_notification, arginfo_gapplication_send_notification, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, withdraw_notification, arginfo_gapplication_withdraw_notification, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, bind_busy_property, arginfo_gapplication_bind_busy_property, ZEND_ACC_PUBLIC)
	PHP_ME(GApplication, unbind_busy_property, arginfo_gapplication_unbind_busy_property, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif