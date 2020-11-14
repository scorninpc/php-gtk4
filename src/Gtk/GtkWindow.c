
#include "GtkWindow.h"

PHP_METHOD(GtkWindow, __construct) {
	zend_long type;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	obj->gtk4_gpointer = (gpointer *)gtk_window_new(type);

	if(obj->gtk4_gpointer == NULL) php_printf("\n\nERROR ON OBJECT CREATION [GtkWindow] (@todo: add exception)\n\n");
}

PHP_METHOD(GtkWindow, activate_default) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_activate_default(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, activate_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_activate_focus(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, activate_key) {
	zend_object * event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_window_activate_key(GTK_WINDOW(obj->gtk4_gpointer), (GdkEventKey*)(gtk4_event->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, add_accel_group) {
	zend_object * accel_group;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(accel_group)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_accel_group = (gtk4_gobject_object*)((char*)(accel_group) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_add_accel_group(GTK_WINDOW(obj->gtk4_gpointer), GTK_ACCEL_GROUP(gtk4_accel_group->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, add_mnemonic) {
	long keyval;
	zend_object * target;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(keyval)
		Z_PARAM_OBJ(target)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_target = (gtk4_gobject_object*)((char*)(target) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_add_mnemonic(GTK_WINDOW(obj->gtk4_gpointer), keyval, GTK_WIDGET(gtk4_target->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, begin_move_drag) {
	long button;
	long root_x;
	long root_y;
	long timestamp;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(button)
		Z_PARAM_LONG(root_x)
		Z_PARAM_LONG(root_y)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_begin_move_drag(GTK_WINDOW(obj->gtk4_gpointer), button, root_x, root_y, timestamp);

}

PHP_METHOD(GtkWindow, begin_resize_drag) {
	zend_long edge;
	long button;
	long root_x;
	long root_y;
	long timestamp;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(edge)
		Z_PARAM_LONG(button)
		Z_PARAM_LONG(root_x)
		Z_PARAM_LONG(root_y)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_begin_resize_drag(GTK_WINDOW(obj->gtk4_gpointer), edge, button, root_x, root_y, timestamp);

}

PHP_METHOD(GtkWindow, close) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_close(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, deiconify) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_deiconify(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, fullscreen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_fullscreen(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, fullscreen_on_monitor) {
	zend_object * screen;
	long monitor;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(screen)
		Z_PARAM_LONG(monitor)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_screen = (gtk4_gobject_object*)((char*)(screen) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_fullscreen_on_monitor(GTK_WINDOW(obj->gtk4_gpointer), (GdkScreen*)(gtk4_screen->gtk4_gpointer), monitor);

}

PHP_METHOD(GtkWindow, get_accept_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_accept_focus(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_application) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_application(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_attached_to) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_attached_to(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_decorated) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_decorated(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_default_size) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int width;
	int height;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_default_size(GTK_WINDOW(obj->gtk4_gpointer), &width, &height);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, width);
	add_next_index_long(&ret_arr, height);

	add_assoc_long_ex(&ret_arr, "width", strlen("width"), width);
	add_assoc_long_ex(&ret_arr, "height", strlen("height"), height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GtkWindow, get_default_widget) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_default_widget(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_deletable) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_deletable(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_destroy_with_parent) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_destroy_with_parent(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_focus(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_focus_on_map) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_focus_on_map(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_focus_visible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_focus_visible(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_gravity) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_window_get_gravity(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWindow, get_group) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_group(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_hide_titlebar_when_maximized) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_hide_titlebar_when_maximized(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_icon) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_icon(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_icon_list) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gtk_window_get_icon_list(GTK_WINDOW(obj->gtk4_gpointer));

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

PHP_METHOD(GtkWindow, get_icon_name) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_window_get_icon_name(GTK_WINDOW(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWindow, get_mnemonic_modifier) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_window_get_mnemonic_modifier(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWindow, get_mnemonics_visible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_mnemonics_visible(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_modal) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_modal(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_position) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int x;
	int y;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_position(GTK_WINDOW(obj->gtk4_gpointer), &x, &y);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x);
	add_next_index_long(&ret_arr, y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GtkWindow, get_resizable) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_resizable(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_role) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_window_get_role(GTK_WINDOW(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWindow, get_screen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_screen(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_size) {
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int width;
	int height;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_size(GTK_WINDOW(obj->gtk4_gpointer), &width, &height);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, width);
	add_next_index_long(&ret_arr, height);

	add_assoc_long_ex(&ret_arr, "width", strlen("width"), width);
	add_assoc_long_ex(&ret_arr, "height", strlen("height"), height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GtkWindow, get_skip_pager_hint) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_skip_pager_hint(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_skip_taskbar_hint) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_skip_taskbar_hint(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_title) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_window_get_title(GTK_WINDOW(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWindow, get_titlebar) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_titlebar(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_transient_for) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_window_get_transient_for(GTK_WINDOW(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWindow, get_type_hint) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_window_get_type_hint(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWindow, get_urgency_hint) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_get_urgency_hint(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, get_window_type) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_window_get_window_type(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWindow, has_group) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_has_group(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, has_toplevel_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_has_toplevel_focus(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, iconify) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_iconify(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, is_active) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_is_active(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, is_maximized) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_is_maximized(GTK_WINDOW(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, maximize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_maximize(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, mnemonic_activate) {
	long keyval;
	zend_long modifier;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(keyval)
		Z_PARAM_LONG(modifier)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_mnemonic_activate(GTK_WINDOW(obj->gtk4_gpointer), keyval, modifier);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, move) {
	long x;
	long y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_move(GTK_WINDOW(obj->gtk4_gpointer), x, y);

}

PHP_METHOD(GtkWindow, present) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_present(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, present_with_time) {
	long timestamp;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_present_with_time(GTK_WINDOW(obj->gtk4_gpointer), timestamp);

}

PHP_METHOD(GtkWindow, propagate_key_event) {
	zend_object * event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_window_propagate_key_event(GTK_WINDOW(obj->gtk4_gpointer), (GdkEventKey*)(gtk4_event->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, remove_accel_group) {
	zend_object * accel_group;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(accel_group)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_accel_group = (gtk4_gobject_object*)((char*)(accel_group) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_remove_accel_group(GTK_WINDOW(obj->gtk4_gpointer), GTK_ACCEL_GROUP(gtk4_accel_group->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, remove_mnemonic) {
	long keyval;
	zend_object * target;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(keyval)
		Z_PARAM_OBJ(target)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_target = (gtk4_gobject_object*)((char*)(target) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_remove_mnemonic(GTK_WINDOW(obj->gtk4_gpointer), keyval, GTK_WIDGET(gtk4_target->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, resize) {
	long width;
	long height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_resize(GTK_WINDOW(obj->gtk4_gpointer), width, height);

}

PHP_METHOD(GtkWindow, set_accept_focus) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_accept_focus(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_application) {
	zend_object * application;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(application)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_application = (gtk4_gobject_object*)((char*)(application) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_application(GTK_WINDOW(obj->gtk4_gpointer), GTK_APPLICATION(gtk4_application->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_attached_to) {
	zend_object * attach_widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(attach_widget)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_attach_widget = (gtk4_gobject_object*)((char*)(attach_widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_attached_to(GTK_WINDOW(obj->gtk4_gpointer), GTK_WIDGET(gtk4_attach_widget->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_decorated) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_decorated(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_default) {
	zend_object * default_widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(default_widget)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_default_widget = (gtk4_gobject_object*)((char*)(default_widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_default(GTK_WINDOW(obj->gtk4_gpointer), GTK_WIDGET(gtk4_default_widget->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_default_size) {
	long width;
	long height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_default_size(GTK_WINDOW(obj->gtk4_gpointer), width, height);

}

PHP_METHOD(GtkWindow, set_deletable) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_deletable(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_destroy_with_parent) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_destroy_with_parent(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_focus) {
	zend_object * focus;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(focus)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_focus = (gtk4_gobject_object*)((char*)(focus) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_focus(GTK_WINDOW(obj->gtk4_gpointer), GTK_WIDGET(gtk4_focus->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_focus_on_map) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_focus_on_map(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_focus_visible) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_focus_visible(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_geometry_hints) {
	zend_object * geometry_widget;
	zend_object * geometry;
	zend_long geom_mask;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ(geometry_widget)
		Z_PARAM_OBJ(geometry)
		Z_PARAM_LONG(geom_mask)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_geometry_widget = (gtk4_gobject_object*)((char*)(geometry_widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk4_gobject_object *gtk4_geometry = (gtk4_gobject_object*)((char*)(geometry) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_geometry_hints(GTK_WINDOW(obj->gtk4_gpointer), GTK_WIDGET(gtk4_geometry_widget->gtk4_gpointer), (GdkGeometry*)(gtk4_geometry->gtk4_gpointer), geom_mask);

}

PHP_METHOD(GtkWindow, set_gravity) {
	zend_long gravity;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(gravity)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_gravity(GTK_WINDOW(obj->gtk4_gpointer), gravity);

}

PHP_METHOD(GtkWindow, set_has_user_ref_count) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_has_user_ref_count(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_hide_titlebar_when_maximized) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_hide_titlebar_when_maximized(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_icon) {
	zend_object * icon;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(icon)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_icon = (gtk4_gobject_object*)((char*)(icon) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_icon(GTK_WINDOW(obj->gtk4_gpointer), (GdkPixbuf*)(gtk4_icon->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_icon_from_file) {
	char * filename;
	size_t filename_len;
	GError **err;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(filename, filename_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_window_set_icon_from_file(GTK_WINDOW(obj->gtk4_gpointer), filename, err);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWindow, set_icon_list) {
	zval *arr_list;
	GList *list = NULL;


	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(arr_list)
	ZEND_PARSE_PARAMETERS_END();


	// Loop array to create C char array
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(arr_list), zend_ulong long_key, zend_string *str_key, zval *val) {

		// If string
		if(Z_TYPE_P(val) == IS_OBJECT)  {
			gtk4_gobject_object *gtk4_item = (gtk4_gobject_object*)((char*)(val) - XtOffsetOf(gtk4_gobject_object, std));
			list = g_list_append (list, (GdkPixbuf *)gtk4_item->gtk4_gpointer);
		}

	} ZEND_HASH_FOREACH_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_icon_list(GTK_WINDOW(obj->gtk4_gpointer), list);
}

PHP_METHOD(GtkWindow, set_icon_name) {
	char * name;
	size_t name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_icon_name(GTK_WINDOW(obj->gtk4_gpointer), name);

}

PHP_METHOD(GtkWindow, set_keep_above) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_keep_above(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_keep_below) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_keep_below(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_mnemonic_modifier) {
	zend_long modifier;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(modifier)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_mnemonic_modifier(GTK_WINDOW(obj->gtk4_gpointer), modifier);

}

PHP_METHOD(GtkWindow, set_mnemonics_visible) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_mnemonics_visible(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_modal) {
	bool modal;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_modal(GTK_WINDOW(obj->gtk4_gpointer), modal);

}

PHP_METHOD(GtkWindow, set_position) {
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_position(GTK_WINDOW(obj->gtk4_gpointer), position);

}

PHP_METHOD(GtkWindow, set_resizable) {
	bool resizable;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(resizable)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_resizable(GTK_WINDOW(obj->gtk4_gpointer), resizable);

}

PHP_METHOD(GtkWindow, set_role) {
	char * role;
	size_t role_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(role, role_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_role(GTK_WINDOW(obj->gtk4_gpointer), role);

}

PHP_METHOD(GtkWindow, set_screen) {
	zend_object * screen;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(screen)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_screen = (gtk4_gobject_object*)((char*)(screen) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_screen(GTK_WINDOW(obj->gtk4_gpointer), (GdkScreen*)(gtk4_screen->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_skip_pager_hint) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_skip_pager_hint(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_skip_taskbar_hint) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_skip_taskbar_hint(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, set_startup_id) {
	char * startup_id;
	size_t startup_id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(startup_id, startup_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_startup_id(GTK_WINDOW(obj->gtk4_gpointer), startup_id);

}

PHP_METHOD(GtkWindow, set_title) {
	char * title;
	size_t title_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(title, title_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_title(GTK_WINDOW(obj->gtk4_gpointer), title);

}

PHP_METHOD(GtkWindow, set_titlebar) {
	zend_object * titlebar;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(titlebar)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_titlebar = (gtk4_gobject_object*)((char*)(titlebar) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_titlebar(GTK_WINDOW(obj->gtk4_gpointer), GTK_WIDGET(gtk4_titlebar->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_transient_for) {
	zend_object * parent;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(parent)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_parent = (gtk4_gobject_object*)((char*)(parent) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_window_set_transient_for(GTK_WINDOW(obj->gtk4_gpointer), GTK_WINDOW(gtk4_parent->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, set_type_hint) {
	zend_long hint;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(hint)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_type_hint(GTK_WINDOW(obj->gtk4_gpointer), hint);

}

PHP_METHOD(GtkWindow, set_urgency_hint) {
	bool setting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_urgency_hint(GTK_WINDOW(obj->gtk4_gpointer), setting);

}

PHP_METHOD(GtkWindow, stick) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_stick(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, unfullscreen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_unfullscreen(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, unmaximize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_unmaximize(GTK_WINDOW(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWindow, unstick) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_unstick(GTK_WINDOW(obj->gtk4_gpointer));

}

