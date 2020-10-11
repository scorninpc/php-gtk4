
#include "GtkWindow.h"

PHP_METHOD(GtkWindow, __construct)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	obj->gtk4_gpointer = gtk_window_new(GTK_WINDOW_TOPLEVEL);
}