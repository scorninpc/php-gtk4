
#include "helper.h"

gtk4_gobject_object *gtk4_get_current_object(zval *object)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(object) + 1)) - 1;

	return obj;
}

gtk4_gobject_object *gtk4_create_new_object(zend_class_entry *ce)
{
	gtk4_gobject_object *intern = ecalloc(1, sizeof(gtk4_gobject_object));
	memset(intern, 0, sizeof(gtk4_gobject_object));

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);

	memcpy(&g_object_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	g_object_object_handlers.offset = XtOffsetOf(gtk4_gobject_object, std);
	g_object_object_handlers.clone_obj = NULL;

	intern->std.handlers = &g_object_object_handlers;

	return intern;
}
