
#include "GtkWindow.h"

PHP_METHOD(GtkWindow, __construct)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	obj->gtk4_gpointer = (gpointer *)gtk_window_new(GTK_WINDOW_TOPLEVEL);

	obj->test = 35;
}

PHP_METHOD(GtkWindow, set_title)
{
	char * title;
	size_t title_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(title, title_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	gtk_window_set_title(GTK_WINDOW(obj->gtk4_gpointer), title);
}

PHP_METHOD(GtkWindow, get_title)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	const gchar *ret = gtk_window_get_title(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_STRING(ret);
}
