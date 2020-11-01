
#include "GtkWidget.h"


// PHP_METHOD(_GtkWidget, __construct)
// {

// }

PHP_METHOD(GtkWidget, show_all)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	gtk_widget_show_all(GTK_WIDGET(obj->gtk4_gpointer));
}