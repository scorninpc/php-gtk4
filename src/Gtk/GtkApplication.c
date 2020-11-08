
#include "GtkApplication.h"

PHP_METHOD(GtkApplication, add_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_application_add_window(GTK_APPLICATION(obj->gtk4_gpointer), GTK_WINDOW(gtk4_window->gtk4_gpointer));

}

PHP_METHOD(GtkApplication, get_accels_for_action) {
	char * detailed_action_name;
	size_t detailed_action_name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(detailed_action_name, detailed_action_name_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_application_get_accels_for_action(GTK_APPLICATION(obj->gtk4_gpointer), detailed_action_name);

}

PHP_METHOD(GtkApplication, get_actions_for_accel) {
	char * accel;
	size_t accel_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(accel, accel_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_application_get_actions_for_accel(GTK_APPLICATION(obj->gtk4_gpointer), accel);

}

PHP_METHOD(GtkApplication, get_active_window) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_get_active_window(GTK_APPLICATION(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, get_app_menu) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_get_app_menu(GTK_APPLICATION(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, get_menu_by_id) {
	char * id;
	size_t id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(id, id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_get_menu_by_id(GTK_APPLICATION(obj->gtk4_gpointer), id);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, get_menubar) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_get_menubar(GTK_APPLICATION(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, get_window_by_id) {
	long id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_get_window_by_id(GTK_APPLICATION(obj->gtk4_gpointer), id);

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, get_windows) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	GList *ret = gtk_application_get_windows(GTK_APPLICATION(obj->gtk4_gpointer));

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

PHP_METHOD(GtkApplication, inhibit) {
	zend_object * window;
	zend_long flags;
	char * reason;
	size_t reason_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ(window)
		Z_PARAM_LONG(flags)
		Z_PARAM_STRING(reason, reason_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	long ret = gtk_application_inhibit(GTK_APPLICATION(obj->gtk4_gpointer), GTK_WINDOW(gtk4_window->gtk4_gpointer), flags, reason);

	RETURN_LONG(ret);
}

PHP_METHOD(GtkApplication, is_inhibited) {
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_application_is_inhibited(GTK_APPLICATION(obj->gtk4_gpointer), flags);

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkApplication, list_action_descriptions) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_application_list_action_descriptions(GTK_APPLICATION(obj->gtk4_gpointer));

}

PHP_METHOD(GtkApplication, prefers_app_menu) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gtk_application_prefers_app_menu(GTK_APPLICATION(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

PHP_METHOD(GtkApplication, remove_window) {
	zend_object * window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(window)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_window = (gtk4_gobject_object*)((char*)(window) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_application_remove_window(GTK_APPLICATION(obj->gtk4_gpointer), GTK_WINDOW(gtk4_window->gtk4_gpointer));

}

PHP_METHOD(GtkApplication, set_accels_for_action) {
	char * detailed_action_name;
	size_t detailed_action_name_len;
	
	zval *accels = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(detailed_action_name, detailed_action_name_len)
		Z_PARAM_ARRAY(accels);
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());


	// 
	int gtk4_accels_size = zend_hash_num_elements(Z_ARR_P(accels));
	const char * c_accels[gtk4_accels_size];

	// Loop array to create C char array
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(accels), zend_ulong long_key, zend_string *str_key, zval *val) {

		// If string
		if(Z_TYPE_P(val) == IS_STRING)  {

			c_accels[long_key] = malloc(strlen(Z_STRVAL_P(val))+1);
			c_accels[long_key] = Z_STRVAL_P(val);
		}

	} ZEND_HASH_FOREACH_END();


	gtk_application_set_accels_for_action(GTK_APPLICATION(obj->gtk4_gpointer), detailed_action_name, c_accels);
}

PHP_METHOD(GtkApplication, set_app_menu) {
	zend_object * app_menu;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(app_menu)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_app_menu = (gtk4_gobject_object*)((char*)(app_menu) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_application_set_app_menu(GTK_APPLICATION(obj->gtk4_gpointer), G_MENU_MODEL(gtk4_app_menu->gtk4_gpointer));

}

PHP_METHOD(GtkApplication, set_menubar) {
	zend_object * menubar;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(menubar)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_menubar = (gtk4_gobject_object*)((char*)(menubar) - XtOffsetOf(gtk4_gobject_object, std));


	gtk_application_set_menubar(GTK_APPLICATION(obj->gtk4_gpointer), G_MENU_MODEL(gtk4_menubar->gtk4_gpointer));

}

PHP_METHOD(GtkApplication, uninhibit) {
	long cookie;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cookie)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_application_uninhibit(GTK_APPLICATION(obj->gtk4_gpointer), cookie);

}

PHP_METHOD(GtkApplication, window_new) {

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gpointer *ret = (gpointer *)gtk_application_window_new(GTK_APPLICATION(obj->gtk4_gpointer));

	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));
	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);
	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);
	intern->gtk4_gpointer = ret;

	RETURN_OBJ(&intern->std);
}

PHP_METHOD(GtkApplication, __construct) {
	char * application_id;
	size_t application_id_len;
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(application_id, application_id_len)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	obj->gtk4_gpointer = (gpointer *)gtk_application_new(application_id, flags);

	if(obj->gtk4_gpointer == NULL) php_printf("\n\nERROR ON OBJECT CREATION [GtkApplication] (@todo: add exception)\n\n");
}

