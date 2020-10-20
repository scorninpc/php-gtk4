#include "AtkPlug.h"
// -------------------
PHP_METHOD(AtkPlug, __construct)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	obj->gtk4_gpointer = (gpointer)atk_plug_new();
}

// -------------------
PHP_METHOD(AtkPlug, get_id)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	atk_plug_get_id(ATK_PLUG(obj->gtk4_gpointer));
}

