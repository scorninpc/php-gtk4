#ifndef _PHPGTK_GTKCLIPBOARD_H_
#define _PHPGTK_GTKCLIPBOARD_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_clear, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get_display, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get_display);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get_owner, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get_owner);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get_selection, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get_selection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_contents, 0, 0, 3)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_contents);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_image, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_image);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_rich_text, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_rich_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_targets, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_targets);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_text, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_request_uris, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, request_uris);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_set_can_store, 0, 0, 2)
	ZEND_ARG_INFO(0, targets)
	ZEND_ARG_INFO(0, n_targets)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, set_can_store);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_set_image, 0, 0, 1)
	ZEND_ARG_INFO(0, pixbuf)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, set_image);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_set_text, 0, 0, 2)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, set_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_set_with_data, 0, 0, 5)
	ZEND_ARG_INFO(0, targets)
	ZEND_ARG_INFO(0, n_targets)
	ZEND_ARG_INFO(0, get_func)
	ZEND_ARG_INFO(0, clear_func)
	ZEND_ARG_INFO(0, user_data)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, set_with_data);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_set_with_owner, 0, 0, 5)
	ZEND_ARG_INFO(0, targets)
	ZEND_ARG_INFO(0, n_targets)
	ZEND_ARG_INFO(0, get_func)
	ZEND_ARG_INFO(0, clear_func)
	ZEND_ARG_INFO(0, owner)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, set_with_owner);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_store, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, store);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_contents, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_contents);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_image, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_image);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_rich_text, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_rich_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_targets, 0, 0, 2)
	ZEND_ARG_INFO(0, targets)
	ZEND_ARG_INFO(0, n_targets)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_targets);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_text, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_for_uris, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_for_uris);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_is_image_available, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_is_image_available);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_is_rich_text_available, 0, 0, 1)
	ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_is_rich_text_available);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_is_target_available, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_is_target_available);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_is_text_available, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_is_text_available);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_wait_is_uris_available, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, wait_is_uris_available);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get, 0, 0, 1)
	ZEND_ARG_INFO(0, selection)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get_default, 0, 0, 1)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkclipboard_get_for_display, 0, 0, 2)
	ZEND_ARG_INFO(0, display)
	ZEND_ARG_INFO(0, selection)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkClipboard, get_for_display);

static zend_class_entry *gtk4_gtkclipboard_ce = NULL;
static const zend_function_entry gtkclipboard_functions[] = {
	PHP_ME(GtkClipboard, clear, arginfo_gtkclipboard_clear, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get_display, arginfo_gtkclipboard_get_display, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get_owner, arginfo_gtkclipboard_get_owner, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get_selection, arginfo_gtkclipboard_get_selection, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_contents, arginfo_gtkclipboard_request_contents, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_image, arginfo_gtkclipboard_request_image, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_rich_text, arginfo_gtkclipboard_request_rich_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_targets, arginfo_gtkclipboard_request_targets, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_text, arginfo_gtkclipboard_request_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, request_uris, arginfo_gtkclipboard_request_uris, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, set_can_store, arginfo_gtkclipboard_set_can_store, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, set_image, arginfo_gtkclipboard_set_image, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, set_text, arginfo_gtkclipboard_set_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, set_with_data, arginfo_gtkclipboard_set_with_data, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, set_with_owner, arginfo_gtkclipboard_set_with_owner, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, store, arginfo_gtkclipboard_store, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_contents, arginfo_gtkclipboard_wait_for_contents, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_image, arginfo_gtkclipboard_wait_for_image, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_rich_text, arginfo_gtkclipboard_wait_for_rich_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_targets, arginfo_gtkclipboard_wait_for_targets, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_text, arginfo_gtkclipboard_wait_for_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_for_uris, arginfo_gtkclipboard_wait_for_uris, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_is_image_available, arginfo_gtkclipboard_wait_is_image_available, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_is_rich_text_available, arginfo_gtkclipboard_wait_is_rich_text_available, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_is_target_available, arginfo_gtkclipboard_wait_is_target_available, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_is_text_available, arginfo_gtkclipboard_wait_is_text_available, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, wait_is_uris_available, arginfo_gtkclipboard_wait_is_uris_available, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get, arginfo_gtkclipboard_get, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get_default, arginfo_gtkclipboard_get_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkClipboard, get_for_display, arginfo_gtkclipboard_get_for_display, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
