
#ifndef _PHPGTK_GTKWINDOW_H_
#define _PHPGTK_GTKWINDOW_H_

	#include <php.h>
	#include <gtk/gtk.h>

	#include "../G/GObject.h"

	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_construct, 0, 0, 0)
	ZEND_END_ARG_INFO()

	PHP_METHOD(GtkWindow, __construct);

	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_set_title, 0, 0, 1)
		ZEND_ARG_INFO(0, title)
	ZEND_END_ARG_INFO()
	PHP_METHOD(GtkWindow, set_title);

	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwindow_get_title, 0, 0, 0)
	ZEND_END_ARG_INFO()
	PHP_METHOD(GtkWindow, get_title);
	
	// ----------------
	static zend_class_entry *gtk4_gtk_window_ce = NULL;
	static const zend_function_entry gtk_window_functions[] = {
		PHP_ME(GtkWindow, __construct, arginfo_gtkwindow_construct, ZEND_ACC_PUBLIC)
		PHP_ME(GtkWindow, set_title, arginfo_gtkwindow_set_title, ZEND_ACC_PUBLIC)
		PHP_ME(GtkWindow, get_title, arginfo_gtkwindow_get_title, ZEND_ACC_PUBLIC)
	    PHP_FE_END
	};

	



#endif