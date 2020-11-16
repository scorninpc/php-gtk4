
#include "GdkEvent.h"

PHP_METHOD(GdkEvent, __construct) {
	zend_long type;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	obj->gtk4_gpointer = (gpointer *)gdk_event_new(type);

	if(obj->gtk4_gpointer == NULL) php_printf("\n\nERROR ON OBJECT CREATION [GdkEvent] (@todo: add exception)\n\n");
}

PHP_METHOD(GdkEvent, copy) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_copy((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, free) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_event_free((GdkEvent*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, get_axis) {
	zend_long axis_use;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(axis_use)
	ZEND_PARSE_PARAMETERS_END();

	double value;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_axis((GdkEvent*)(obj->gtk4_gpointer), axis_use, &value);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(value);
}

PHP_METHOD(GdkEvent, get_button) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();
	
	int button;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_button((GdkEvent*)(obj->gtk4_gpointer), &button);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(button);
}

PHP_METHOD(GdkEvent, get_click_count) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();
	
	int click_count;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_click_count((GdkEvent*)(obj->gtk4_gpointer), &click_count);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(click_count);
}

PHP_METHOD(GdkEvent, get_coords) {
	double x_win;
	double y_win;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_coords((GdkEvent*)(obj->gtk4_gpointer), &x_win, &y_win);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x_win);
	add_next_index_long(&ret_arr, y_win);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x_win);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y_win);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkEvent, get_device) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_device((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_device_tool) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_device_tool((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_event_sequence) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_event_sequence((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_event_type) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gdk_event_get_event_type((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GdkEvent, get_keycode) {
	short unsigned int keycode;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_keycode((GdkEvent*)(obj->gtk4_gpointer), &keycode);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(keycode);
}

PHP_METHOD(GdkEvent, get_keyval) {
	unsigned int keyval;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_keyval((GdkEvent*)(obj->gtk4_gpointer), &keyval);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(keyval);
}

PHP_METHOD(GdkEvent, get_pointer_emulated) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_pointer_emulated((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkEvent, get_root_coords) {
	double x_root;
	double y_root;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_root_coords((GdkEvent*)(obj->gtk4_gpointer), &x_root, &y_root);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x_root);
	add_next_index_long(&ret_arr, y_root);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x_root);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y_root);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkEvent, get_scancode) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gdk_event_get_scancode((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GdkEvent, get_screen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_screen((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_scroll_deltas) {
	double delta_x;
	double delta_y;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_scroll_deltas((GdkEvent*)(obj->gtk4_gpointer), &delta_x, &delta_y);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, delta_x);
	add_next_index_long(&ret_arr, delta_y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), delta_x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), delta_y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkEvent, get_scroll_direction) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	GdkScrollDirection direction;
	
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_scroll_direction((GdkEvent*)(obj->gtk4_gpointer), &direction);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(direction);
}

PHP_METHOD(GdkEvent, get_seat) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_seat((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_source_device) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_source_device((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, get_state) {
	GdkModifierType state;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_state((GdkEvent*)(obj->gtk4_gpointer), &state);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(state);
}

PHP_METHOD(GdkEvent, get_time) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gdk_event_get_time((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GdkEvent, get_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gdk_event_get_window((GdkEvent*)(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GdkEvent, is_scroll_stop_event) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_is_scroll_stop_event((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkEvent, put) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gdk_event_put((GdkEvent*)(obj->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, set_device) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	gdk_event_set_device((GdkEvent*)(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, set_device_tool) {
	zend_object * tool;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(tool)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_tool = (gtk4_gobject_object*)((char*)(tool) - XtOffsetOf(gtk4_gobject_object, std));


	gdk_event_set_device_tool((GdkEvent*)(obj->gtk4_gpointer), (GdkDeviceTool*)(gtk4_tool->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, set_screen) {
	zend_object * screen;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(screen)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_screen = (gtk4_gobject_object*)((char*)(screen) - XtOffsetOf(gtk4_gobject_object, std));


	gdk_event_set_screen((GdkEvent*)(obj->gtk4_gpointer), (GdkScreen*)(gtk4_screen->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, set_source_device) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	gdk_event_set_source_device((GdkEvent*)(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

}

PHP_METHOD(GdkEvent, triggers_context_menu) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_triggers_context_menu((GdkEvent*)(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GdkEvent, get_angle) {
	zend_object * event2;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double angle;

	bool ret = gdk_events_get_angle((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &angle);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(angle);
}

PHP_METHOD(GdkEvent, get_center) {
	zend_object * event2;
	
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double x;
	double y;

	bool ret = gdk_events_get_center((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &x, &y);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x);
	add_next_index_long(&ret_arr, y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GdkEvent, get_distance) {
	zend_object * event2;
	
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());


	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double distance;
	bool ret = gdk_events_get_distance((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &distance);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(distance);
}

