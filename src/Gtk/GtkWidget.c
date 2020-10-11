
#include "GtkWidget.h"


// PHP_METHOD(_GtkWidget, __construct)
// {

// }

PHP_METHOD(GtkWidget, show_all)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_widget_show_all(GTK_WIDGET(obj->gtk4_gpointer));
}