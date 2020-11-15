#ifndef _PHPGTK_GTKCONTAINER_H_
#define _PHPGTK_GTKCONTAINER_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_add, 0, 0, 1)
	ZEND_ARG_INFO(0, widget)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, add);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_add_with_properties, 0, 0, 2)
	ZEND_ARG_INFO(0, widget)
	ZEND_ARG_INFO(0, first_prop_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, add_with_properties);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_check_resize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, check_resize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_get, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, first_prop_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_get_property, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, property_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_get_property);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, child_property)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_notify_by_pspec, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, pspec)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_notify_by_pspec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_set, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, first_prop_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_set_property, 0, 0, 3)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, property_name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_set_property);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_child_type, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, child_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_border_width, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_border_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_children, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_children);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_focus_child, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_focus_child);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_focus_hadjustment, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_focus_hadjustment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_focus_vadjustment, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_focus_vadjustment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_get_path_for_child, 0, 0, 1)
	ZEND_ARG_INFO(0, child)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, get_path_for_child);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_propagate_draw, 0, 0, 2)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, cr)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, propagate_draw);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, widget)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, remove);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_set_border_width, 0, 0, 1)
	ZEND_ARG_INFO(0, border_width)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, set_border_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_set_focus_child, 0, 0, 1)
	ZEND_ARG_INFO(0, child)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, set_focus_child);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_set_focus_hadjustment, 0, 0, 1)
	ZEND_ARG_INFO(0, adjustment)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, set_focus_hadjustment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkcontainer_set_focus_vadjustment, 0, 0, 1)
	ZEND_ARG_INFO(0, adjustment)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkContainer, set_focus_vadjustment);

static zend_class_entry *gtk4_gtkcontainer_ce = NULL;
static const zend_function_entry gtkcontainer_functions[] = {
	PHP_ME(GtkContainer, add, arginfo_gtkcontainer_add, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, add_with_properties, arginfo_gtkcontainer_add_with_properties, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, check_resize, arginfo_gtkcontainer_check_resize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_get, arginfo_gtkcontainer_child_get, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_get_property, arginfo_gtkcontainer_child_get_property, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_notify, arginfo_gtkcontainer_child_notify, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_notify_by_pspec, arginfo_gtkcontainer_child_notify_by_pspec, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_set, arginfo_gtkcontainer_child_set, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_set_property, arginfo_gtkcontainer_child_set_property, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, child_type, arginfo_gtkcontainer_child_type, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_border_width, arginfo_gtkcontainer_get_border_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_children, arginfo_gtkcontainer_get_children, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_focus_child, arginfo_gtkcontainer_get_focus_child, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_focus_hadjustment, arginfo_gtkcontainer_get_focus_hadjustment, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_focus_vadjustment, arginfo_gtkcontainer_get_focus_vadjustment, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, get_path_for_child, arginfo_gtkcontainer_get_path_for_child, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, propagate_draw, arginfo_gtkcontainer_propagate_draw, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, remove, arginfo_gtkcontainer_remove, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, set_border_width, arginfo_gtkcontainer_set_border_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, set_focus_child, arginfo_gtkcontainer_set_focus_child, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, set_focus_hadjustment, arginfo_gtkcontainer_set_focus_hadjustment, ZEND_ACC_PUBLIC)
	PHP_ME(GtkContainer, set_focus_vadjustment, arginfo_gtkcontainer_set_focus_vadjustment, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
