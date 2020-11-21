
#include "GtkWidget.h"

PHP_METHOD(GtkWidget, __construct) {
	GType type;
	char * first_property_name;
	size_t first_property_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(type)
		Z_PARAM_STRING(first_property_name, first_property_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	obj->gtk4_gpointer = (gpointer *)gtk_widget_new(type, first_property_name);

	if(obj->gtk4_gpointer == NULL) php_printf("\n\nERROR ON OBJECT CREATION [GtkWidget] (@todo: add exception)\n\n");
}

PHP_METHOD(GtkWidget, activate) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_activate(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, add_accelerator) {
	char * accel_signal;
	size_t accel_signal_len;
	zend_object * accel_group;
	long accel_key;
	zend_long accel_mods;
	zend_long accel_flags;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STRING(accel_signal, accel_signal_len)
		Z_PARAM_OBJ(accel_group)
		Z_PARAM_LONG(accel_key)
		Z_PARAM_LONG(accel_mods)
		Z_PARAM_LONG(accel_flags)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_accel_group = (gtk4_gobject_object*)((char*)(accel_group) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_add_accelerator(GTK_WIDGET(obj->gtk4_gpointer), accel_signal, GTK_ACCEL_GROUP(gtk4_accel_group->gtk4_gpointer), accel_key, accel_mods, accel_flags);

}

PHP_METHOD(GtkWidget, add_device_events) {
	zend_object * device;
	zend_long events;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(device)
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_add_device_events(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer), events);

}

PHP_METHOD(GtkWidget, add_events) {
	long events;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_add_events(GTK_WIDGET(obj->gtk4_gpointer), events);

}

PHP_METHOD(GtkWidget, add_mnemonic_label) {
	zend_object * label;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(label)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_label = (gtk4_gobject_object*)((char*)(label) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_add_mnemonic_label(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_label->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, can_activate_accel) {
	long signal_id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(signal_id)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_can_activate_accel(GTK_WIDGET(obj->gtk4_gpointer), signal_id);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, child_focus) {
	zend_long direction;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_child_focus(GTK_WIDGET(obj->gtk4_gpointer), direction);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, child_notify1) {
	char * child_property;
	size_t child_property_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(child_property, child_property_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_child_notify(GTK_WIDGET(obj->gtk4_gpointer), child_property);

}

PHP_METHOD(GtkWidget, compute_expand) {
	zend_long orientation;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_compute_expand(GTK_WIDGET(obj->gtk4_gpointer), orientation);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, create_pango_context) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_create_pango_context(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, create_pango_layout) {
	char * text;
	size_t text_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(text, text_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_create_pango_layout(GTK_WIDGET(obj->gtk4_gpointer), text);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, destroy) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_destroy(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, device_is_shadowed) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_device_is_shadowed(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, draw) {

}

PHP_METHOD(GtkWidget, error_bell) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_error_bell(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, event) {
	zend_object * event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_event(GTK_WIDGET(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, freeze_child_notify) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_freeze_child_notify(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, get_accessible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_accessible(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_action_group) {
	char * prefix;
	size_t prefix_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(prefix, prefix_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_action_group(GTK_WIDGET(obj->gtk4_gpointer), prefix);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_allocated_baseline) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_allocated_baseline(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_allocated_height) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_allocated_height(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_allocated_size) {

}

PHP_METHOD(GtkWidget, get_allocated_width) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_allocated_width(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_allocation) {

}

PHP_METHOD(GtkWidget, get_ancestor) {
	GType widget_type;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget_type)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_ancestor(GTK_WIDGET(obj->gtk4_gpointer), widget_type);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_app_paintable) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_app_paintable(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_can_default) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_can_default(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_can_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_can_focus(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_child_requisition) {
	// zend_object * requisition;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(requisition)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_requisition = (gtk4_gobject_object*)((char*)(requisition) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_get_child_requisition(GTK_WIDGET(obj->gtk4_gpointer), GTK_REQUISITION(gtk4_requisition->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, get_child_visible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_child_visible(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_clip) {

}

PHP_METHOD(GtkWidget, get_clipboard) {
	// zend_object * selection;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(selection)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_selection = (gtk4_gobject_object*)((char*)(selection) - XtOffsetOf(gtk4_gobject_object, std));


	// gpointer *ret = (gpointer *)gtk_widget_get_clipboard(GTK_WIDGET(obj->gtk4_gpointer), (GdkAtom*)(gtk4_selection->gtk4_gpointer));

	// char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	// zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	// gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	// intern->gtk4_gpointer = ret;

	// RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_composite_name) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// const char *ret = gtk_widget_get_composite_name(GTK_WIDGET(obj->gtk4_gpointer));

	// if(!ret) {
	// 	RETURN_NULL();
	// }

	// RETURN_STRING(ret);
}

PHP_METHOD(GtkWidget, get_device_enabled) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_get_device_enabled(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_device_events) {
	zend_object * device;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(device)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	zend_long ret = gtk_widget_get_device_events(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_direction) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_direction(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_display) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_display(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_double_buffered) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// bool ret = gtk_widget_get_double_buffered(GTK_WIDGET(obj->gtk4_gpointer));

	// RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_events) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_events(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_focus_on_click) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_focus_on_click(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_font_map) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_font_map(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_font_options) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_font_options(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_frame_clock) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_frame_clock(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_halign) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_halign(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_has_tooltip) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_has_tooltip(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_has_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_has_window(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_hexpand) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_hexpand(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_hexpand_set) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_hexpand_set(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_mapped) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_mapped(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_margin_bottom) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_margin_bottom(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_margin_end) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_margin_end(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_margin_left) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// long ret = gtk_widget_get_margin_left(GTK_WIDGET(obj->gtk4_gpointer));

	// RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_margin_right) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// long ret = gtk_widget_get_margin_right(GTK_WIDGET(obj->gtk4_gpointer));

	// RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_margin_start) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_margin_start(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_margin_top) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_margin_top(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_modifier_mask) {
	zend_long intent;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(intent)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_modifier_mask(GTK_WIDGET(obj->gtk4_gpointer), intent);

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_name) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_widget_get_name(GTK_WIDGET(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWidget, get_no_show_all) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_no_show_all(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_opacity) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	float ret = gtk_widget_get_opacity(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_DOUBLE(ret);
}

PHP_METHOD(GtkWidget, get_pango_context) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_pango_context(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_parent) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_parent(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_parent_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_parent_window(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_path) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_path(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_pointer) {
	// long x;
	// long y;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(x)
	// 	Z_PARAM_LONG(y)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_pointer(GTK_WIDGET(obj->gtk4_gpointer), x, y);

}

PHP_METHOD(GtkWidget, get_preferred_height) {
	// long minimum_height;
	// long natural_height;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(minimum_height)
	// 	Z_PARAM_LONG(natural_height)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_preferred_height(GTK_WIDGET(obj->gtk4_gpointer), minimum_height, natural_height);

}

PHP_METHOD(GtkWidget, get_preferred_height_and_baseline_for_width) {
	// long width;
	// long minimum_height;
	// long natural_height;
	// long minimum_baseline;
	// long natural_baseline;

	// ZEND_PARSE_PARAMETERS_START(5, 5)
	// 	Z_PARAM_LONG(width)
	// 	Z_PARAM_LONG(minimum_height)
	// 	Z_PARAM_LONG(natural_height)
	// 	Z_PARAM_LONG(minimum_baseline)
	// 	Z_PARAM_LONG(natural_baseline)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_preferred_height_and_baseline_for_width(GTK_WIDGET(obj->gtk4_gpointer), width, minimum_height, natural_height, minimum_baseline, natural_baseline);

}

PHP_METHOD(GtkWidget, get_preferred_height_for_width) {
	// long width;
	// long minimum_height;
	// long natural_height;

	// ZEND_PARSE_PARAMETERS_START(3, 3)
	// 	Z_PARAM_LONG(width)
	// 	Z_PARAM_LONG(minimum_height)
	// 	Z_PARAM_LONG(natural_height)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_preferred_height_for_width(GTK_WIDGET(obj->gtk4_gpointer), width, minimum_height, natural_height);

}

PHP_METHOD(GtkWidget, get_preferred_size) {
	
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GtkRequisition *minimum_size;
	GtkRequisition *natural_size;

	gtk_widget_get_preferred_size(GTK_WIDGET(obj->gtk4_gpointer), minimum_size, natural_size);


	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, minimum_size->width);
	add_next_index_long(&ret_arr, minimum_size->height);
	add_assoc_long_ex(&ret_arr, "minimum_width", strlen("minimum_width"),  minimum_size->width);
	add_assoc_long_ex(&ret_arr, "minimum_height", strlen("minimum_height"),  minimum_size->height);

	add_next_index_long(&ret_arr, natural_size->width);
	add_next_index_long(&ret_arr, natural_size->height);
	add_assoc_long_ex(&ret_arr, "natural_width", strlen("natural_width"),  natural_size->width);
	add_assoc_long_ex(&ret_arr, "natural_height", strlen("natural_height"),  natural_size->height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
}

PHP_METHOD(GtkWidget, get_preferred_width) {
	// long minimum_width;
	// long natural_width;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(minimum_width)
	// 	Z_PARAM_LONG(natural_width)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_preferred_width(GTK_WIDGET(obj->gtk4_gpointer), minimum_width, natural_width);

}

PHP_METHOD(GtkWidget, get_preferred_width_for_height) {
	// long height;
	// long minimum_width;
	// long natural_width;

	// ZEND_PARSE_PARAMETERS_START(3, 3)
	// 	Z_PARAM_LONG(height)
	// 	Z_PARAM_LONG(minimum_width)
	// 	Z_PARAM_LONG(natural_width)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_preferred_width_for_height(GTK_WIDGET(obj->gtk4_gpointer), height, minimum_width, natural_width);

}

PHP_METHOD(GtkWidget, get_realized) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_realized(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_receives_default) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_receives_default(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_request_mode) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_request_mode(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_requisition) {
	// zend_object * requisition;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(requisition)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_requisition = (gtk4_gobject_object*)((char*)(requisition) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_get_requisition(GTK_WIDGET(obj->gtk4_gpointer), GTK_REQUISITION(gtk4_requisition->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, get_root_window) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gpointer *ret = (gpointer *)gtk_widget_get_root_window(GTK_WIDGET(obj->gtk4_gpointer));

	// char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	// zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	// gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	// intern->gtk4_gpointer = ret;

	// RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_scale_factor) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_widget_get_scale_factor(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_screen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_screen(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_sensitive) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_sensitive(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_settings) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_settings(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_size_request) {
	// long width;
	// long height;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(width)
	// 	Z_PARAM_LONG(height)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_get_size_request(GTK_WIDGET(obj->gtk4_gpointer), width, height);

}

PHP_METHOD(GtkWidget, get_state) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// zend_long ret = gtk_widget_get_state(GTK_WIDGET(obj->gtk4_gpointer));

	// RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_state_flags) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_state_flags(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_style_context) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_style_context(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_support_multidevice) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_support_multidevice(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_template_child) {
	GType widget_type;
	char * name;
	size_t name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget_type)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_template_child(GTK_WIDGET(obj->gtk4_gpointer), widget_type, name);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_tooltip_markup) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_widget_get_tooltip_markup(GTK_WIDGET(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWidget, get_tooltip_text) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const char *ret = gtk_widget_get_tooltip_text(GTK_WIDGET(obj->gtk4_gpointer));

	if(!ret) {
		RETURN_NULL();
	}

	RETURN_STRING(ret);
}

PHP_METHOD(GtkWidget, get_tooltip_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_tooltip_window(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_toplevel) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_toplevel(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_valign) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_valign(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_valign_with_baseline) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	zend_long ret = gtk_widget_get_valign_with_baseline(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, get_vexpand) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_vexpand(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_vexpand_set) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_vexpand_set(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_visible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_get_visible(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, get_visual) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_visual(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, get_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_widget_get_window(GTK_WIDGET(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, grab_default) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_grab_default(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, grab_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_grab_focus(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, has_default) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_has_default(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, has_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_has_focus(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, has_grab) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_has_grab(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, has_screen) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_has_screen(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, has_visible_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_has_visible_focus(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, hide) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_hide(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, hide_on_delete) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_hide_on_delete(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, in_destruction) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_in_destruction(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, init_template) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_init_template(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, input_shape_combine_region) {
	// zend_object * region;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(region)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_region = (gtk4_gobject_object*)((char*)(region) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_input_shape_combine_region(GTK_WIDGET(obj->gtk4_gpointer), (gtk4_region->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, insert_action_group) {
	char * name;
	size_t name_len;
	zend_object * group;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(name, name_len)
		Z_PARAM_OBJ(group)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_group = (gtk4_gobject_object*)((char*)(group) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_insert_action_group(GTK_WIDGET(obj->gtk4_gpointer), name, G_ACTION_GROUP(gtk4_group->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, intersect) {
	zend_object * area;
	zend_object * intersection;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(area)
		Z_PARAM_OBJ(intersection)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_area = (gtk4_gobject_object*)((char*)(area) - XtOffsetOf(gtk4_gobject_object, std));


	gtk4_gobject_object *gtk4_intersection = (gtk4_gobject_object*)((char*)(intersection) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_intersect(GTK_WIDGET(obj->gtk4_gpointer), (GdkRectangle*)(gtk4_area->gtk4_gpointer), (GdkRectangle*)(gtk4_intersection->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_ancestor) {
	zend_object * ancestor;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(ancestor)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_ancestor = (gtk4_gobject_object*)((char*)(ancestor) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_is_ancestor(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_ancestor->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_composited) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// bool ret = gtk_widget_is_composited(GTK_WIDGET(obj->gtk4_gpointer));

	// RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_drawable) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_is_drawable(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_focus) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_is_focus(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_sensitive) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_is_sensitive(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_toplevel) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_is_toplevel(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, is_visible) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_is_visible(GTK_WIDGET(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, keynav_failed) {
	zend_long direction;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_keynav_failed(GTK_WIDGET(obj->gtk4_gpointer), direction);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, list_accel_closures) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gtk_widget_list_accel_closures(GTK_WIDGET(obj->gtk4_gpointer));

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

PHP_METHOD(GtkWidget, list_action_prefixes) {

	// ZEND_PARSE_PARAMETERS_START(0, 0)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// const char *ret = gtk_widget_list_action_prefixes(GTK_WIDGET(obj->gtk4_gpointer));

	// if(!ret) {
	// 	RETURN_NULL();
	// }

	// RETURN_STRING(ret);
}

PHP_METHOD(GtkWidget, list_mnemonic_labels) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gtk_widget_list_mnemonic_labels(GTK_WIDGET(obj->gtk4_gpointer));

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

PHP_METHOD(GtkWidget, map) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_map(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, mnemonic_activate1) {
	bool group_cycling;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(group_cycling)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_widget_mnemonic_activate(GTK_WIDGET(obj->gtk4_gpointer), group_cycling);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, override_background_color) {
	// zend_long state;
	// zend_object * color;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(state)
	// 	Z_PARAM_OBJ(color)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_color = (gtk4_gobject_object*)((char*)(color) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_override_background_color(GTK_WIDGET(obj->gtk4_gpointer), state, (GdkRGBA*)(gtk4_color->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, override_color) {
	// zend_long state;
	// zend_object * color;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_LONG(state)
	// 	Z_PARAM_OBJ(color)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_color = (gtk4_gobject_object*)((char*)(color) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_override_color(GTK_WIDGET(obj->gtk4_gpointer), state, (GdkRGBA*)(gtk4_color->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, override_cursor) {
	// zend_object * cursor;
	// zend_object * secondary_cursor;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_OBJ(cursor)
	// 	Z_PARAM_OBJ(secondary_cursor)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_cursor = (gtk4_gobject_object*)((char*)(cursor) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk4_gobject_object *gtk4_secondary_cursor = (gtk4_gobject_object*)((char*)(secondary_cursor) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_override_cursor(GTK_WIDGET(obj->gtk4_gpointer), (GdkRGBA*)(gtk4_cursor->gtk4_gpointer), (GdkRGBA*)(gtk4_secondary_cursor->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, override_font) {
	// zend_object * font_desc;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(font_desc)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_font_desc = (gtk4_gobject_object*)((char*)(font_desc) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_override_font(GTK_WIDGET(obj->gtk4_gpointer), PANGO_FONT_DESCRIPTION(gtk4_font_desc->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, override_symbolic_color) {
	// char * name;
	// size_t name_len;
	// zend_object * color;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_STRING(name, name_len)
	// 	Z_PARAM_OBJ(color)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_color = (gtk4_gobject_object*)((char*)(color) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_override_symbolic_color(GTK_WIDGET(obj->gtk4_gpointer), name, (GdkRGBA*)(gtk4_color->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_allocate) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_allocate(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_compute_expand) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_compute_expand(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_draw) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_draw(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_draw_area) {
	long x;
	long y;
	long width;
	long height;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_draw_area(GTK_WIDGET(obj->gtk4_gpointer), x, y, width, height);

}

PHP_METHOD(GtkWidget, queue_draw_region) {
	// zend_object * region;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(region)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_region = (gtk4_gobject_object*)((char*)(region) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_queue_draw_region(GTK_WIDGET(obj->gtk4_gpointer), (gtk4_region->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_resize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_resize(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, queue_resize_no_redraw) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_queue_resize_no_redraw(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, realize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_realize(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, region_intersect) {
	// zend_object * region;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(region)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_region = (gtk4_gobject_object*)((char*)(region) - XtOffsetOf(gtk4_gobject_object, std));


	// gpointer *ret = (gpointer *)gtk_widget_region_intersect(GTK_WIDGET(obj->gtk4_gpointer), (gtk4_region->gtk4_gpointer));

	// char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	// zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	// gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	// intern->gtk4_gpointer = ret;

	// RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, register_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_register_window(GTK_WIDGET(obj->gtk4_gpointer), (GdkWindow*)(gtk4_window->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, remove_accelerator) {
	zend_object * accel_group;
	long accel_key;
	zend_long accel_mods;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ(accel_group)
		Z_PARAM_LONG(accel_key)
		Z_PARAM_LONG(accel_mods)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_accel_group = (gtk4_gobject_object*)((char*)(accel_group) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_remove_accelerator(GTK_WIDGET(obj->gtk4_gpointer), GTK_ACCEL_GROUP(gtk4_accel_group->gtk4_gpointer), accel_key, accel_mods);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, remove_mnemonic_label) {
	zend_object * label;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(label)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_label = (gtk4_gobject_object*)((char*)(label) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_remove_mnemonic_label(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_label->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, remove_tick_callback) {
	long id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_remove_tick_callback(GTK_WIDGET(obj->gtk4_gpointer), id);

}

PHP_METHOD(GtkWidget, render_icon_pixbuf) {
	// char * stock_id;
	// size_t stock_id_len;
	// zend_long size;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_STRING(stock_id, stock_id_len)
	// 	Z_PARAM_LONG(size)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gpointer *ret = (gpointer *)gtk_widget_render_icon_pixbuf(GTK_WIDGET(obj->gtk4_gpointer), stock_id, size);

	// char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	// zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	// gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	// intern->gtk4_gpointer = ret;

	// RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkWidget, reparent) {
	// zend_object * new_parent;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(new_parent)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_new_parent = (gtk4_gobject_object*)((char*)(new_parent) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_reparent(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_new_parent->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, reset_style) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_reset_style(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, send_expose) {
	// zend_object * event;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(event)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	// long ret = gtk_widget_send_expose(GTK_WIDGET(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event->gtk4_gpointer));

	// RETURN_LONG(ret);
}

PHP_METHOD(GtkWidget, send_focus_change) {
	zend_object * event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event = (gtk4_gobject_object*)((char*)(event) - XtOffsetOf(gtk4_gobject_object, std));


	bool ret = gtk_widget_send_focus_change(GTK_WIDGET(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, set_accel_path) {
	char * accel_path;
	size_t accel_path_len;
	zend_object * accel_group;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(accel_path, accel_path_len)
		Z_PARAM_OBJ(accel_group)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_accel_group = (gtk4_gobject_object*)((char*)(accel_group) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_accel_path(GTK_WIDGET(obj->gtk4_gpointer), accel_path, GTK_ACCEL_GROUP(gtk4_accel_group->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_allocation) {
	// zend_object * allocation;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(allocation)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_allocation = (gtk4_gobject_object*)((char*)(allocation) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_set_allocation(GTK_WIDGET(obj->gtk4_gpointer), GTK_ALLOCATION(gtk4_allocation->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_app_paintable) {
	bool app_paintable;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(app_paintable)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_app_paintable(GTK_WIDGET(obj->gtk4_gpointer), app_paintable);

}

PHP_METHOD(GtkWidget, set_can_default) {
	bool can_default;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(can_default)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_can_default(GTK_WIDGET(obj->gtk4_gpointer), can_default);

}

PHP_METHOD(GtkWidget, set_can_focus) {
	bool can_focus;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(can_focus)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_can_focus(GTK_WIDGET(obj->gtk4_gpointer), can_focus);

}

PHP_METHOD(GtkWidget, set_child_visible) {
	bool is_visible;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(is_visible)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_child_visible(GTK_WIDGET(obj->gtk4_gpointer), is_visible);

}

PHP_METHOD(GtkWidget, set_clip) {
	// zend_object * clip;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(clip)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_clip = (gtk4_gobject_object*)((char*)(clip) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_set_clip(GTK_WIDGET(obj->gtk4_gpointer), GTK_ALLOCATION(gtk4_clip->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_composite_name) {
	// char * name;
	// size_t name_len;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_STRING(name, name_len)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_composite_name(GTK_WIDGET(obj->gtk4_gpointer), name);

}

PHP_METHOD(GtkWidget, set_device_enabled) {
	zend_object * device;
	bool enabled;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(device)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_device_enabled(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer), enabled);

}

PHP_METHOD(GtkWidget, set_device_events) {
	zend_object * device;
	zend_long events;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(device)
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_device = (gtk4_gobject_object*)((char*)(device) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_device_events(GTK_WIDGET(obj->gtk4_gpointer), (GdkDevice*)(gtk4_device->gtk4_gpointer), events);

}

PHP_METHOD(GtkWidget, set_direction) {
	zend_long dir;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dir)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_direction(GTK_WIDGET(obj->gtk4_gpointer), dir);

}

PHP_METHOD(GtkWidget, set_double_buffered) {
	// bool double_buffered;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_BOOL(double_buffered)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_double_buffered(GTK_WIDGET(obj->gtk4_gpointer), double_buffered);

}

PHP_METHOD(GtkWidget, set_events) {
	long events;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_events(GTK_WIDGET(obj->gtk4_gpointer), events);

}

PHP_METHOD(GtkWidget, set_focus_on_click) {
	bool focus_on_click;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(focus_on_click)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_focus_on_click(GTK_WIDGET(obj->gtk4_gpointer), focus_on_click);

}

PHP_METHOD(GtkWidget, set_font_map) {
	zend_object * font_map;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(font_map)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_font_map = (gtk4_gobject_object*)((char*)(font_map) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_font_map(GTK_WIDGET(obj->gtk4_gpointer), PANGO_FONT_MAP(gtk4_font_map->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_font_options) {
	// zend_object * options;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(options)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_options = (gtk4_gobject_object*)((char*)(options) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_set_font_options(GTK_WIDGET(obj->gtk4_gpointer), (gtk4_options->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_halign) {
	zend_long align;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_halign(GTK_WIDGET(obj->gtk4_gpointer), align);

}

PHP_METHOD(GtkWidget, set_has_tooltip) {
	bool has_tooltip;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(has_tooltip)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_has_tooltip(GTK_WIDGET(obj->gtk4_gpointer), has_tooltip);

}

PHP_METHOD(GtkWidget, set_has_window) {
	bool has_window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(has_window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_has_window(GTK_WIDGET(obj->gtk4_gpointer), has_window);

}

PHP_METHOD(GtkWidget, set_hexpand) {
	bool expand;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_hexpand(GTK_WIDGET(obj->gtk4_gpointer), expand);

}

PHP_METHOD(GtkWidget, set_hexpand_set) {
	bool set;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(set)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_hexpand_set(GTK_WIDGET(obj->gtk4_gpointer), set);

}

PHP_METHOD(GtkWidget, set_mapped) {
	bool mapped;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(mapped)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_mapped(GTK_WIDGET(obj->gtk4_gpointer), mapped);

}

PHP_METHOD(GtkWidget, set_margin_bottom) {
	long margin;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_margin_bottom(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_margin_end) {
	long margin;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_margin_end(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_margin_left) {
	// long margin;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_LONG(margin)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_margin_left(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_margin_right) {
	// long margin;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_LONG(margin)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_margin_right(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_margin_start) {
	long margin;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_margin_start(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_margin_top) {
	long margin;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_margin_top(GTK_WIDGET(obj->gtk4_gpointer), margin);

}

PHP_METHOD(GtkWidget, set_name) {
	char * name;
	size_t name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_name(GTK_WIDGET(obj->gtk4_gpointer), name);

}

PHP_METHOD(GtkWidget, set_no_show_all) {
	bool no_show_all;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(no_show_all)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_no_show_all(GTK_WIDGET(obj->gtk4_gpointer), no_show_all);

}

PHP_METHOD(GtkWidget, set_opacity) {
	// float opacity;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_DOUBLE(opacity)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_opacity(GTK_WIDGET(obj->gtk4_gpointer), opacity);

}

PHP_METHOD(GtkWidget, set_parent) {
	zend_object * parent;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(parent)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_parent = (gtk4_gobject_object*)((char*)(parent) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_parent(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_parent->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_parent_window) {
	zend_object * parent_window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(parent_window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_parent_window = (gtk4_gobject_object*)((char*)(parent_window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_parent_window(GTK_WIDGET(obj->gtk4_gpointer), (GdkWindow*)(gtk4_parent_window->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_realized) {
	bool realized;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(realized)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_realized(GTK_WIDGET(obj->gtk4_gpointer), realized);

}

PHP_METHOD(GtkWidget, set_receives_default) {
	bool receives_default;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(receives_default)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_receives_default(GTK_WIDGET(obj->gtk4_gpointer), receives_default);

}

PHP_METHOD(GtkWidget, set_redraw_on_allocate) {
	bool redraw_on_allocate;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(redraw_on_allocate)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_redraw_on_allocate(GTK_WIDGET(obj->gtk4_gpointer), redraw_on_allocate);

}

PHP_METHOD(GtkWidget, set_sensitive) {
	bool sensitive;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sensitive)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_sensitive(GTK_WIDGET(obj->gtk4_gpointer), sensitive);

}

PHP_METHOD(GtkWidget, set_size_request) {
	long width;
	long height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_size_request(GTK_WIDGET(obj->gtk4_gpointer), width, height);

}

PHP_METHOD(GtkWidget, set_state) {
	// zend_long state;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_LONG(state)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_set_state(GTK_WIDGET(obj->gtk4_gpointer), state);

}

PHP_METHOD(GtkWidget, set_state_flags) {
	zend_long flags;
	bool clear;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(flags)
		Z_PARAM_BOOL(clear)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_state_flags(GTK_WIDGET(obj->gtk4_gpointer), flags, clear);

}

PHP_METHOD(GtkWidget, set_support_multidevice) {
	bool support_multidevice;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(support_multidevice)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_support_multidevice(GTK_WIDGET(obj->gtk4_gpointer), support_multidevice);

}

PHP_METHOD(GtkWidget, set_tooltip_markup) {
	char * markup;
	size_t markup_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(markup, markup_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_tooltip_markup(GTK_WIDGET(obj->gtk4_gpointer), markup);

}

PHP_METHOD(GtkWidget, set_tooltip_text) {
	char * text;
	size_t text_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(text, text_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_tooltip_text(GTK_WIDGET(obj->gtk4_gpointer), text);

}

PHP_METHOD(GtkWidget, set_tooltip_window) {
	zend_object * custom_window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(custom_window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_custom_window = (gtk4_gobject_object*)((char*)(custom_window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_tooltip_window(GTK_WIDGET(obj->gtk4_gpointer), GTK_WINDOW(gtk4_custom_window->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_valign) {
	zend_long align;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_valign(GTK_WIDGET(obj->gtk4_gpointer), align);

}

PHP_METHOD(GtkWidget, set_vexpand) {
	bool expand;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_vexpand(GTK_WIDGET(obj->gtk4_gpointer), expand);

}

PHP_METHOD(GtkWidget, set_vexpand_set) {
	bool set;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(set)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_vexpand_set(GTK_WIDGET(obj->gtk4_gpointer), set);

}

PHP_METHOD(GtkWidget, set_visible) {
	bool visible;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_set_visible(GTK_WIDGET(obj->gtk4_gpointer), visible);

}

PHP_METHOD(GtkWidget, set_visual) {
	zend_object * visual;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(visual)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_visual = (gtk4_gobject_object*)((char*)(visual) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_visual(GTK_WIDGET(obj->gtk4_gpointer), (GdkVisual*)(gtk4_visual->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, set_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_set_window(GTK_WIDGET(obj->gtk4_gpointer), (GdkWindow*)(gtk4_window->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, shape_combine_region) {
	// zend_object * region;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(region)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_region = (gtk4_gobject_object*)((char*)(region) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_shape_combine_region(GTK_WIDGET(obj->gtk4_gpointer), (gtk4_region->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, show) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_show(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, show_all) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_show_all(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, show_now) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_show_now(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, size_allocate) {
	// zend_object * allocation;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(allocation)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_allocation = (gtk4_gobject_object*)((char*)(allocation) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_size_allocate(GTK_WIDGET(obj->gtk4_gpointer), GTK_ALLOCATION(gtk4_allocation->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, size_allocate_with_baseline) {
	// zend_object * allocation;
	// long baseline;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_OBJ(allocation)
	// 	Z_PARAM_LONG(baseline)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_allocation = (gtk4_gobject_object*)((char*)(allocation) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_size_allocate_with_baseline(GTK_WIDGET(obj->gtk4_gpointer), GTK_ALLOCATION(gtk4_allocation->gtk4_gpointer), baseline);

}

PHP_METHOD(GtkWidget, size_request) {
	// zend_object * requisition;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_OBJ(requisition)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_requisition = (gtk4_gobject_object*)((char*)(requisition) - XtOffsetOf(gtk4_gobject_object, std));


	// gtk_widget_size_request(GTK_WIDGET(obj->gtk4_gpointer), GTK_REQUISITION(gtk4_requisition->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, style_get) {
	char * first_property_name;
	size_t first_property_name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(first_property_name, first_property_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_style_get(GTK_WIDGET(obj->gtk4_gpointer), first_property_name);

}

PHP_METHOD(GtkWidget, style_get_property) {
	char * property_name;
	size_t property_name_len;
	zval *gv_value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(property_name, property_name_len)
		Z_PARAM_ZVAL(gv_value)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GValue value = zval_to_gvalue(gv_value);


	gtk_widget_style_get_property(GTK_WIDGET(obj->gtk4_gpointer), property_name, &value);

}

PHP_METHOD(GtkWidget, style_get_valist) {
	// char * first_property_name;
	// size_t first_property_name_len;
	// va_list var_args;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_STRING(first_property_name, first_property_name_len)
	// 	Z_PARAM_ARR(var_args)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk_widget_style_get_valist(GTK_WIDGET(obj->gtk4_gpointer), first_property_name, var_args);

}

PHP_METHOD(GtkWidget, thaw_child_notify) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_thaw_child_notify(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, translate_coordinates) {
	// zend_object * dest_widget;
	// long src_x;
	// long src_y;
	// long dest_x;
	// long dest_y;

	// ZEND_PARSE_PARAMETERS_START(5, 5)
	// 	Z_PARAM_OBJ(dest_widget)
	// 	Z_PARAM_LONG(src_x)
	// 	Z_PARAM_LONG(src_y)
	// 	Z_PARAM_LONG(dest_x)
	// 	Z_PARAM_LONG(dest_y)
	// ZEND_PARSE_PARAMETERS_END();

	// gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	// gtk4_gobject_object *gtk4_dest_widget = (gtk4_gobject_object*)((char*)(dest_widget) - XtOffsetOf(gtk4_gobject_object, std));


	// bool ret = gtk_widget_translate_coordinates(GTK_WIDGET(obj->gtk4_gpointer), GTK_WIDGET(gtk4_dest_widget->gtk4_gpointer), src_x, src_y, dest_x, dest_y);

	// RETURN_BOOL(ret);
}

PHP_METHOD(GtkWidget, trigger_tooltip_query) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_trigger_tooltip_query(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, unmap) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_unmap(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, unparent) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_unparent(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, unrealize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_unrealize(GTK_WIDGET(obj->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, unregister_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_widget_unregister_window(GTK_WIDGET(obj->gtk4_gpointer), (GdkWindow*)(gtk4_window->gtk4_gpointer));

}

PHP_METHOD(GtkWidget, unset_state_flags) {
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_widget_unset_state_flags(GTK_WIDGET(obj->gtk4_gpointer), flags);

}

