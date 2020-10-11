
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
	static zend_class_entry *gtk4_gtk_window_ce = NULL;
	static const zend_function_entry gtk_window_functions[] = {
		PHP_ME(GtkWindow, __construct, arginfo_gtkwindow_construct, ZEND_ACC_PUBLIC)
	    PHP_FE_END
	};



#endif