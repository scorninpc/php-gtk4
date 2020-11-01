#include "AtkPlug.h"
// -------------------
PHP_METHOD(AtkPlug, __construct)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	obj->gtk4_gpointer = (gpointer)atk_plug_new();
}

// -------------------
PHP_METHOD(AtkPlug, get_id)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	atk_plug_get_id(ATK_PLUG(obj->gtk4_gpointer));
}

