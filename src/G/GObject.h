
#ifndef _PHPGTK_GOBJECT_H_
#define _PHPGTK_GOBJECT_H_

	#include <php.h>
	#include <gtk/gtk.h>

	#include <time.h>
	#include <stdlib.h>

	// ----------------
	// gtk object structure
	typedef struct {
		gpointer *gtk4_gpointer;
		long test;
		zend_object std;
	} gtk4_gobject_object;

	// ----------------
	// Callback signal info
	typedef struct {
		// Php::Value callback_name;
		// Php::Array callback_params;
		// Php::Object self_widget;
		// Php::Parameters parameters;

		// Store function name
		zend_fcall_info fci;
		zend_fcall_info_cache fcc;

		zval *extra_params;
		int extra_params_n;

		gtk4_gobject_object *self_object;

		// Store signal infos
		guint signal_id;
		const gchar *signal_name;
		GType itype;
		GSignalFlags signal_flags;
		GType return_type;
		guint n_params;
		const GType *param_types;
	} st_callback;


	// ----------------
	static zend_object_handlers g_object_object_handlers;

	// ----------------
	zend_object *g_object_create_object(zend_class_entry *class_type);
	bool connect_callback(gpointer user_data, ...);

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
	static zend_class_entry *gtk4_gobject_ce = NULL;
	static const zend_function_entry gobject_functions[] = {
		PHP_ME(GObject, __construct, arginfo_gobject_construct, ZEND_ACC_PUBLIC)
		PHP_ME(GObject, connect, arginfo_gobject_connect, ZEND_ACC_PUBLIC)
		PHP_ME(GObject, test, arginfo_gobject_test, ZEND_ACC_PUBLIC)
		PHP_FE_END
	};	


	#include "../../helper.h"


#endif