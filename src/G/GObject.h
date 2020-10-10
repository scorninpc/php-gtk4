
#ifndef _PHPGTK_GOBJECT_H_
#define _PHPGTK_GOBJECT_H_

	#include <php.h>
	#include <gtk/gtk.h>

	#include <time.h>
	#include <stdlib.h>


	typedef struct {
		gpointer gtk4_gpointer;
		long test;
		zend_object zo;
	} gtk4_gobject_object;

	// ----------------
	zend_object *g_object_create_object(zend_class_entry *class_type);

	// ----------------
	PHP_METHOD(GObject, __construct);
	PHP_METHOD(GObject, connect);
	PHP_METHOD(GObject, test);

	// ----------------
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gobject_test, 0, 0, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(arginfo_gobject_construct, 0, 0, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gobject_connect, 0, 0, IS_VOID, 0)
		ZEND_ARG_INFO(0, "signal")
		ZEND_ARG_INFO(0, "callback")
		ZEND_ARG_VARIADIC_INFO(0, "params")
	ZEND_END_ARG_INFO()

	// ----------------
	static zend_class_entry *gtk4_g_gobject_ce = NULL;
	static const zend_function_entry g_gobject_functions[] = {
		PHP_ME(GObject, __construct, arginfo_gobject_construct, ZEND_ACC_PUBLIC)
		PHP_ME(GObject, connect, arginfo_gobject_connect, ZEND_ACC_PUBLIC)
		PHP_ME(GObject, test, arginfo_gobject_test, ZEND_ACC_PUBLIC)
		PHP_FE_END
	};	


#endif