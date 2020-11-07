#ifndef _PHPGTK_gtkapplicationwindow_H_
#define _PHPGTK_gtkapplicationwindow_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../G/GObject.h"

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplicationwindow_set_show_menubar, 0, 0, 1)
	ZEND_ARG_INFO(0, show_menubar)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplicationWindow, set_show_menubar);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplicationwindow_get_show_menubar, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplicationWindow, get_show_menubar);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplicationwindow_get_id, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplicationWindow, get_id);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplicationwindow_set_help_overlay, 0, 0, 1)
	ZEND_ARG_INFO(0, help_overlay)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplicationWindow, set_help_overlay);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkapplicationwindow_get_help_overlay, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkApplicationWindow, get_help_overlay);

// -------------------
static zend_class_entry *gtk4_gtkapplicationwindow_ce = NULL;
static const zend_function_entry gtkapplicationwindow_functions[] = {
	PHP_ME(GtkApplicationWindow, set_show_menubar, arginfo_gtkapplicationwindow_set_show_menubar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplicationWindow, get_show_menubar, arginfo_gtkapplicationwindow_get_show_menubar, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplicationWindow, get_id, arginfo_gtkapplicationwindow_get_id, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplicationWindow, set_help_overlay, arginfo_gtkapplicationwindow_set_help_overlay, ZEND_ACC_PUBLIC)
	PHP_ME(GtkApplicationWindow, get_help_overlay, arginfo_gtkapplicationwindow_get_help_overlay, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif