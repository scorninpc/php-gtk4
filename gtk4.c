/* gtk4 extension for PHP (c) 2020 Bruno P. Gonçalves */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>
#include "ext/standard/info.h"
#include "php_gtk4.h"
#include "gtk4_arginfo.h"

/**
 * Php Gtk Classes
 */
#include "gtk4.h"

// ----------------
// static zend_class_entry *gtk4_exception_ce = NULL;
// static const zend_function_entry gtk4_exception_functions[] = {
// 	PHP_FE_END
// };	

/**
 * Old php versions
 */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/**
 * MINIT
 */
static PHP_MINIT_FUNCTION(gtk4)
{
	// Exception class
	zend_class_entry tmp_gtk4_exception_ce;
	INIT_CLASS_ENTRY(tmp_gtk4_exception_ce, "Gtk\\Exception", NULL);
	// gtk4_exception_ce = zend_register_internal_class_ex(&tmp_gtk4_exception_ce, zend_ce_exception);
	zend_register_internal_class_ex(&tmp_gtk4_exception_ce, zend_ce_exception);

	// Create class
	zend_class_entry tmp_g_object_ce;
	INIT_CLASS_ENTRY(tmp_g_object_ce, "G\\Object", g_gobject_functions);
	gtk4_g_gobject_ce = zend_register_internal_class(&tmp_g_object_ce);
	gtk4_g_gobject_ce->create_object = g_object_create_object;

	zend_class_entry tmp_gapplication_ce;
	INIT_CLASS_ENTRY(tmp_gapplication_ce, "G\\Application", gapplication_functions);
	gtk4_gapplication_ce = zend_register_internal_class_ex(&tmp_gapplication_ce, gtk4_g_gobject_ce);	// extends GObject

	zend_class_entry tmp_gtk_ce;
	INIT_CLASS_ENTRY(tmp_gtk_ce, "Gtk", gtk_functions);
	gtk4_gtk_ce = zend_register_internal_class(&tmp_gtk_ce);

	zend_class_entry tmp_gtkapplication_ce;
	INIT_CLASS_ENTRY(tmp_gtkapplication_ce, "Gtk\\Application", gtkapplication_functions);
	gtk4_gtkapplication_ce = zend_register_internal_class_ex(&tmp_gtkapplication_ce, gtk4_gapplication_ce);	// extends GApplication

	zend_class_entry tmp_gtk_widget_ce;
	INIT_CLASS_ENTRY(tmp_gtk_widget_ce, "Gtk\\Widget", gtk_widget_functions);
	gtk4_gtk_widget_ce = zend_register_internal_class_ex(&tmp_gtk_widget_ce, gtk4_g_gobject_ce);	// extends GObject

	zend_class_entry tmp_gtk_window_ce;
	INIT_CLASS_ENTRY(tmp_gtk_window_ce, "Gtk\\Window", gtk_window_functions);
	gtk4_gtk_window_ce = zend_register_internal_class_ex(&tmp_gtk_window_ce, gtk4_gtk_widget_ce);	// extends Widget

	zend_class_entry tmp_gtkapplicationwindow_ce;
	INIT_CLASS_ENTRY(tmp_gtkapplicationwindow_ce, "Gtk\\Application\\Window", gtkapplicationwindow_functions);
	gtk4_gtkapplicationwindow_ce = zend_register_internal_class_ex(&tmp_gtkapplicationwindow_ce, gtk4_gtk_window_ce);	// extends Widget



	zend_class_entry tmp_test_ce;
	INIT_CLASS_ENTRY(tmp_test_ce, "G\\Application\\Flags", NULL);
	zend_class_entry *c2 = zend_register_internal_class(&tmp_test_ce);
	c2->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(c2, "NONE", sizeof("NONE") - 1, G_APPLICATION_FLAGS_NONE);
	zend_declare_class_constant_long(c2, "IS_LAUNCHER", sizeof("IS_LAUNCHER") - 1, G_APPLICATION_IS_LAUNCHER);
	zend_declare_class_constant_long(c2, "NON_UNIQUE", sizeof("NON_UNIQUE") - 1, G_APPLICATION_NON_UNIQUE);
	zend_declare_class_constant_long(c2, "CAN_OVERRIDE_APP_ID", sizeof("CAN_OVERRIDE_APP_ID") - 1, G_APPLICATION_CAN_OVERRIDE_APP_ID);
	// REGISTER_LONG_CONSTANT("G\\APPLICATION\\FLAGS\\NONE", G_APPLICATION_FLAGS_NONE, CONST_CS|CONST_PERSISTENT);

	
	return SUCCESS;
}

/**
 * RINIT
 */
PHP_RINIT_FUNCTION(gtk4)
{
	#if defined(ZTS) && defined(COMPILE_DL_GTK4)
		ZEND_TSRMLS_CACHE_UPDATE();
	#endif

	return SUCCESS;
}

/**
 * MINFO
 */
PHP_MINFO_FUNCTION(gtk4)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gtk4 support", "enabled");
	php_info_print_table_end();
}

/**
 * Module entry
 */
zend_module_entry gtk4_module_entry = {
	STANDARD_MODULE_HEADER,
	"gtk4",							/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(gtk4),				/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(gtk4),				/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(gtk4),				/* PHP_MINFO - Module info */
	"0.1",							/* Version */
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_GTK4
	# ifdef ZTS
		ZEND_TSRMLS_CACHE_DEFINE()
	# endif
	ZEND_GET_MODULE(gtk4)
#endif
