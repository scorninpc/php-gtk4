#ifndef _PHPGTK_HELPER_H_
#define _PHPGTK_HELPER_H_

	#include <php.h>
	#include <zend_exceptions.h>

	#include "src/G/GObject.h"

	gtk4_gobject_object *gtk4_get_current_object(zval *object);
	gtk4_gobject_object *gtk4_create_new_object(zend_class_entry *ce);
	zend_class_entry *gtk4_get_ce_by_name(char *class_name);
	char *gtk4_get_namespace(const char *class);
	char *gtk4_exception(int code, char *format, ...);
	GValue zval_to_gvalue(zval *z_value);
	zval *gvalue_to_zval(GValue gz_value);

#endif