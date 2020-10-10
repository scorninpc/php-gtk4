/* gtk4 extension for PHP (c) 2020 Bruno P. Gonçalves */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <php.h>
#include "ext/standard/info.h"
#include "php_gtk4.h"
#include "gtk4_arginfo.h"

/**
 * Php Gtk Classes
 */
#include "gtk4.h"


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
	// Create class
	zend_class_entry tmp_g_object_ce;
    INIT_CLASS_ENTRY(tmp_g_object_ce, "G\\Object", g_gobject_functions);
    gtk4_g_gobject_ce = zend_register_internal_class(&tmp_g_object_ce);
    gtk4_g_gobject_ce->create_object = g_object_create_object;

    zend_class_entry tmp_gtk_ce;
    INIT_CLASS_ENTRY(tmp_gtk_ce, "Gtk", gtk_functions);
    gtk4_gtk_ce = zend_register_internal_class(&tmp_gtk_ce);

    zend_class_entry tmp_gtk_window_ce;
    INIT_CLASS_ENTRY(tmp_gtk_window_ce, "Gtk\\Window", gtk_window_functions);
    gtk4_gtk_window_ce = zend_register_internal_class_ex(&tmp_gtk_window_ce, gtk4_g_gobject_ce);	// extends GObject
	
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
