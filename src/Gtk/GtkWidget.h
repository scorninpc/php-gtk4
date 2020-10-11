
#ifndef _PHPGTK_GTKWIDGET_H_
#define _PHPGTK_GTKWIDGET_H_

	#include <php.h>
	#include <gtk/gtk.h>

	#include "../G/GObject.h"

	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_construct, 0, 0, 0)
	ZEND_END_ARG_INFO()

	PHP_METHOD(GtkWidget, __construct);
	
	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_show_all, 0, 0, 0)
	ZEND_END_ARG_INFO()

	PHP_METHOD(GtkWidget, show_all);
	


	// ----------------
	static zend_class_entry *gtk4_gtk_widget_ce = NULL;
	static const zend_function_entry gtk_widget_functions[] = {
		// PHP_ME(GtkWidget, __construct, arginfo_gtkwidget_construct, ZEND_ACC_PUBLIC)
		PHP_ME(GtkWidget, show_all, arginfo_gtkwidget_show_all, ZEND_ACC_PUBLIC)
		PHP_FE_END
	};	


#endif