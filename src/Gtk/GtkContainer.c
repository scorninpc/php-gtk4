
#include "GtkContainer.h"

PHP_METHOD(GtkContainer, add) {
	zend_object * widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(widget)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_widget = (gtk4_gobject_object*)((char*)(widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_add(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_widget->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, add_with_properties) {
	zend_object * widget;
	char * first_prop_name;
	size_t first_prop_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(widget)
		Z_PARAM_STRING(first_prop_name, first_prop_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_widget = (gtk4_gobject_object*)((char*)(widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_add_with_properties(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_widget->gtk4_gpointer), first_prop_name);

}

PHP_METHOD(GtkContainer, check_resize) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_container_check_resize(GTK_CONTAINER(obj->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, child_get) {
	zend_object * child;
	char * first_prop_name;
	size_t first_prop_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(child)
		Z_PARAM_STRING(first_prop_name, first_prop_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_child_get(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer), first_prop_name);

}

PHP_METHOD(GtkContainer, child_get_property) {


}

PHP_METHOD(GtkContainer, child_notify) {
	zend_object * child;
	char * child_property;
	size_t child_property_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(child)
		Z_PARAM_STRING(child_property, child_property_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_child_notify(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer), child_property);

}

PHP_METHOD(GtkContainer, child_notify_by_pspec) {
	zend_object * child;
	zend_object * pspec;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(child)
		Z_PARAM_OBJ(pspec)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gtk4_gobject_object *gtk4_pspec = (gtk4_gobject_object*)((char*)(pspec) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_child_notify_by_pspec(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer), G_PARAM_SPEC(gtk4_pspec->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, child_set) {
	zend_object * child;
	char * first_prop_name;
	size_t first_prop_name_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ(child)
		Z_PARAM_STRING(first_prop_name, first_prop_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_child_set(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer), first_prop_name);

}

PHP_METHOD(GtkContainer, child_set_property) {
	zend_object * child;
	char * property_name;
	size_t property_name_len;
	zval *gv_value;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ(child)
		Z_PARAM_STRING(property_name, property_name_len)
		Z_PARAM_ZVAL(gv_value)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	GValue value = zval_to_gvalue(gv_value);


	gtk_container_child_set_property(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer), property_name, &value);

}

PHP_METHOD(GtkContainer, child_type) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_container_child_type(GTK_CONTAINER(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkContainer, get_border_width) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	long ret = gtk_container_get_border_width(GTK_CONTAINER(obj->gtk4_gpointer));

	RETURN_LONG(ret);
}

PHP_METHOD(GtkContainer, get_children) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gtk_container_get_children(GTK_CONTAINER(obj->gtk4_gpointer));

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

PHP_METHOD(GtkContainer, get_focus_child) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_container_get_focus_child(GTK_CONTAINER(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkContainer, get_focus_hadjustment) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_container_get_focus_hadjustment(GTK_CONTAINER(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkContainer, get_focus_vadjustment) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_container_get_focus_vadjustment(GTK_CONTAINER(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkContainer, get_path_for_child) {
	zend_object * child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(child)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gpointer *ret = (gpointer *)gtk_container_get_path_for_child(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkContainer, propagate_draw) {

}

PHP_METHOD(GtkContainer, remove) {
	zend_object * widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(widget)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_widget = (gtk4_gobject_object*)((char*)(widget) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_remove(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_widget->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, set_border_width) {
	long border_width;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(border_width)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_container_set_border_width(GTK_CONTAINER(obj->gtk4_gpointer), border_width);

}

PHP_METHOD(GtkContainer, set_focus_child) {
	zend_object * child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(child)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_child = (gtk4_gobject_object*)((char*)(child) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_set_focus_child(GTK_CONTAINER(obj->gtk4_gpointer), GTK_WIDGET(gtk4_child->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, set_focus_hadjustment) {
	zend_object * adjustment;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(adjustment)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_adjustment = (gtk4_gobject_object*)((char*)(adjustment) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_set_focus_hadjustment(GTK_CONTAINER(obj->gtk4_gpointer), GTK_ADJUSTMENT(gtk4_adjustment->gtk4_gpointer));

}

PHP_METHOD(GtkContainer, set_focus_vadjustment) {
	zend_object * adjustment;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(adjustment)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_adjustment = (gtk4_gobject_object*)((char*)(adjustment) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_container_set_focus_vadjustment(GTK_CONTAINER(obj->gtk4_gpointer), GTK_ADJUSTMENT(gtk4_adjustment->gtk4_gpointer));

}

