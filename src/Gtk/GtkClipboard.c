
#include "GtkClipboard.h"

PHP_METHOD(GtkClipboard, clear) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_clipboard_clear(GTK_CLIPBOARD(obj->gtk4_gpointer));

}

PHP_METHOD(GtkClipboard, get_display) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_clipboard_get_display(GTK_CLIPBOARD(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkClipboard, get_owner) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_clipboard_get_owner(GTK_CLIPBOARD(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkClipboard, get_selection) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GdkAtom ret = gtk_clipboard_get_selection(GTK_CLIPBOARD(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = (gpointer *)ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkClipboard, request_contents) {

}

PHP_METHOD(GtkClipboard, request_image) {

}

PHP_METHOD(GtkClipboard, request_rich_text) {

}

PHP_METHOD(GtkClipboard, request_targets) {

}

PHP_METHOD(GtkClipboard, request_text) {

}

PHP_METHOD(GtkClipboard, request_uris) {

}

PHP_METHOD(GtkClipboard, set_can_store) {

}

PHP_METHOD(GtkClipboard, set_image) {
	zend_object * pixbuf;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(pixbuf)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_pixbuf = (gtk4_gobject_object*)((char*)(pixbuf) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_clipboard_set_image(GTK_CLIPBOARD(obj->gtk4_gpointer), (GdkPixbuf*)(gtk4_pixbuf->gtk4_gpointer));

}

PHP_METHOD(GtkClipboard, set_text) {
	char * text;
	size_t text_len;
	long len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(text, text_len)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_clipboard_set_text(GTK_CLIPBOARD(obj->gtk4_gpointer), text, len);

}

PHP_METHOD(GtkClipboard, set_with_data) {

}

PHP_METHOD(GtkClipboard, set_with_owner) {

}

PHP_METHOD(GtkClipboard, store) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_clipboard_store(GTK_CLIPBOARD(obj->gtk4_gpointer));

}

PHP_METHOD(GtkClipboard, wait_for_contents) {

}

PHP_METHOD(GtkClipboard, wait_for_image) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_clipboard_wait_for_image(GTK_CLIPBOARD(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkClipboard, wait_for_rich_text) {

}

PHP_METHOD(GtkClipboard, wait_for_targets) {

}

PHP_METHOD(GtkClipboard, wait_for_text) {

}

PHP_METHOD(GtkClipboard, wait_for_uris) {

}

PHP_METHOD(GtkClipboard, wait_is_image_available) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_clipboard_wait_is_image_available(GTK_CLIPBOARD(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkClipboard, wait_is_rich_text_available) {
	zend_object * buffer;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(buffer)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_buffer = (gtk4_gobject_object*)((char*)(buffer) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_clipboard_wait_is_rich_text_available(GTK_CLIPBOARD(obj->gtk4_gpointer), GTK_TEXT_BUFFER(gtk4_buffer->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkClipboard, wait_is_target_available) {

}

PHP_METHOD(GtkClipboard, wait_is_text_available) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_clipboard_wait_is_text_available(GTK_CLIPBOARD(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkClipboard, wait_is_uris_available) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_clipboard_wait_is_uris_available(GTK_CLIPBOARD(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkClipboard, get) {

}

PHP_METHOD(GtkClipboard, get_default) {
	zend_object * display;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(display)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *gtk4_display = (gtk4_gobject_object*)((char*)(display) - XtOffsetOf(gtk4_gobject_object, std));

	gpointer *ret = (gpointer *)gtk_clipboard_get_default((GdkDisplay*)(gtk4_display->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkClipboard, get_for_display) {

}

