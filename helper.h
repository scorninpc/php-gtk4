#ifndef _PHPGTK_HELPER_H_
#define _PHPGTK_HELPER_H_

	#include <php.h>
	#include "src/G/GObject.h"

	gtk4_gobject_object *gtk4_get_current_object(zval *object);
	gtk4_gobject_object *gtk4_create_new_object(zend_class_entry *ce);

#endif