
#include "GdkDisplay.h"

PHP_METHOD(GdkDisplay, beep) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_beep((GdkDisplay*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkDisplay, close) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_close((GdkDisplay*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkDisplay, device_is_grabbed) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gdk_display_device_is_grabbed((GdkDisplay*)(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, flush) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_flush((GdkDisplay*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkDisplay, get_app_launch_context) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_app_launch_context((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_default_cursor_size) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gdk_display_get_default_cursor_size((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GdkDisplay, get_default_group) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_default_group((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_default_screen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_default_screen((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_event) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_event((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_maximal_cursor_size) {
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	unsigned int width;
	unsigned int height;

	gdk_display_get_maximal_cursor_size((GdkDisplay*)(obj->gtk4_gpointer), &width, &height);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, width);
	add_next_index_long(&ret_arr, height);

	add_assoc_long_ex(&ret_arr, "width", strlen("width"), width);
	add_assoc_long_ex(&ret_arr, "height", strlen("height"), height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkDisplay, get_monitor) {
	long monitor_num;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(monitor_num)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_monitor((GdkDisplay*)(obj->gtk4_gpointer), monitor_num);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_monitor_at_point) {
	long x;
	long y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_monitor_at_point((GdkDisplay*)(obj->gtk4_gpointer), x, y);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_monitor_at_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gpointer *ret = (gpointer *)gdk_display_get_monitor_at_window((GdkDisplay*)(obj->gtk4_gpointer), (GdkWindow*)(gtk4_window->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, get_n_monitors) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gdk_display_get_n_monitors((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GdkDisplay, get_name) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gdk_display_get_name((GdkDisplay*)(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GdkDisplay, get_primary_monitor) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_get_primary_monitor((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, has_pending) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_has_pending((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, is_closed) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_is_closed((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, list_seats) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gdk_display_list_seats((GdkDisplay*)(obj->gtk4_gpointer));

	zval ret_arr;
	array_init(&ret_arr);

	int ret_arr_len = g_list_length(ret);
	for (int i = 0; i < ret_arr_len; i++) {
		gpointer element_data = g_list_nth_data(ret, i);

		char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(element_data));
		zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
		gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
		intern->gtk4_gpointer = (gpointer *)element_data;

		zval obj1;
		ZVAL_OBJ(&obj1, &intern->std);
		add_next_index_zval(&ret_arr, &obj1);
	}

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkDisplay, notify_startup_complete) {
	char * startup_id;
	size_t startup_id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(startup_id, startup_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_notify_startup_complete((GdkDisplay*)(obj->gtk4_gpointer), startup_id);

}

PHP_METHOD(GdkDisplay, peek_event) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_display_peek_event((GdkDisplay*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, put_event) {
	zend_object * event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	gdk_display_put_event((GdkDisplay*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event->gtk4_gpointer));

}

PHP_METHOD(GdkDisplay, request_selection_notification) {
	
}

PHP_METHOD(GdkDisplay, set_double_click_distance) {
	long distance;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(distance)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_set_double_click_distance((GdkDisplay*)(obj->gtk4_gpointer), distance);

}

PHP_METHOD(GdkDisplay, set_double_click_time) {
	long msec;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(msec)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_set_double_click_time((GdkDisplay*)(obj->gtk4_gpointer), msec);

}

PHP_METHOD(GdkDisplay, store_clipboard) {
	
}

PHP_METHOD(GdkDisplay, supports_clipboard_persistence) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_clipboard_persistence((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, supports_cursor_alpha) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_cursor_alpha((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, supports_cursor_color) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_cursor_color((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, supports_input_shapes) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_input_shapes((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, supports_selection_notification) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_selection_notification((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, supports_shapes) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_display_supports_shapes((GdkDisplay*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkDisplay, sync) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_display_sync((GdkDisplay*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkDisplay, get_default) {
	gpointer *ret = (gpointer *)gdk_display_get_default();

	char *ret_cn = gtk4_get_namespace("GdkDisplay");
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, manager_get) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gpointer *ret = (gpointer *)gdk_display_manager_get();

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkDisplay, open) {
	char * display_name;
	size_t display_name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(display_name, display_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gpointer *ret = (gpointer *)gdk_display_open(display_name);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

