#include "GtkApplication.h"



// -------------------
PHP_METHOD(GtkApplication, __construct)
{
	char * application_id;
	size_t application_id_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(application_id, application_id_len)
	ZEND_PARSE_PARAMETERS_END();

	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	obj->gtk4_gpointer = (gpointer)gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
}

// // -------------------
// PHP_METHOD(GtkApplication, run)
// {
	
// 	zval *object = getThis();
// 	gtk4_gobject_object *obj;
// 	obj = (gtk4_gobject_object*)Z_OBJ_P(object);


// 	g_application_run (G_APPLICATION (obj->gtk4_gpointer), 0, NULL);
// }

// -------------------
PHP_METHOD(GtkApplication, add_window)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_add_window(GTK_APPLICATION(obj->gtk4_gpointer), window);
}

// -------------------
PHP_METHOD(GtkApplication, remove_window)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_remove_window(GTK_APPLICATION(obj->gtk4_gpointer), window);
}

// -------------------
PHP_METHOD(GtkApplication, get_windows)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_windows(GTK_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GtkApplication, get_app_menu)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_app_menu(GTK_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GtkApplication, set_app_menu)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_set_app_menu(GTK_APPLICATION(obj->gtk4_gpointer), app_menu);
}

// -------------------
PHP_METHOD(GtkApplication, get_menubar)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_menubar(GTK_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GtkApplication, set_menubar)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_set_menubar(GTK_APPLICATION(obj->gtk4_gpointer), menubar);
}

// -------------------
PHP_METHOD(GtkApplication, add_accelerator)
{
	// char * accelerator;
	// size_t accelerator_len;
	// char * action_name;
	// size_t action_name_len;

	// ZEND_PARSE_PARAMETERS_START(3, 3)
	// 	Z_PARAM_STRING(accelerator, accelerator_len)
	// 	Z_PARAM_STRING(action_name, action_name_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_add_accelerator(GTK_APPLICATION(obj->gtk4_gpointer), accelerator, action_name, parameter);
}

// -------------------
PHP_METHOD(GtkApplication, remove_accelerator)
{
	// char * action_name;
	// size_t action_name_len;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_STRING(action_name, action_name_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_remove_accelerator(GTK_APPLICATION(obj->gtk4_gpointer), action_name, parameter);
}

// -------------------
PHP_METHOD(GtkApplication, inhibit)
{
	// char * reason;
	// size_t reason_len;

	// ZEND_PARSE_PARAMETERS_START(3, 3)
	// 	Z_PARAM_STRING(reason, reason_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_inhibit(GTK_APPLICATION(obj->gtk4_gpointer), window, flags, reason);
}

// -------------------
PHP_METHOD(GtkApplication, uninhibit)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_uninhibit(GTK_APPLICATION(obj->gtk4_gpointer), cookie);
}

// -------------------
PHP_METHOD(GtkApplication, is_inhibited)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gboolean ret = gtk_application_is_inhibited(GTK_APPLICATION(obj->gtk4_gpointer), flags);

	// RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GtkApplication, get_window_by_id)
{

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_get_window_by_id(GTK_APPLICATION(obj->gtk4_gpointer), id);
}

// -------------------
PHP_METHOD(GtkApplication, get_active_window)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_active_window(GTK_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GtkApplication, list_action_descriptions)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_list_action_descriptions(GTK_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GtkApplication, get_accels_for_action)
{
	char * detailed_action_name;
	size_t detailed_action_name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(detailed_action_name, detailed_action_name_len)
	ZEND_PARSE_PARAMETERS_END();

	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_accels_for_action(GTK_APPLICATION(obj->gtk4_gpointer), detailed_action_name);
}

// -------------------
PHP_METHOD(GtkApplication, get_actions_for_accel)
{
	// char * accel;
	// size_t accel_len;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_STRING(accel, accel_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_get_actions_for_accel(GTK_APPLICATION(obj->gtk4_gpointer), accel);
}

// -------------------
PHP_METHOD(GtkApplication, set_accels_for_action)
{
	// char * detailed_action_name;
	// size_t detailed_action_name_len;

	// ZEND_PARSE_PARAMETERS_START(2, 2)
	// 	Z_PARAM_STRING(detailed_action_name, detailed_action_name_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// gtk_application_set_accels_for_action(GTK_APPLICATION(obj->gtk4_gpointer), detailed_action_name, accels);
}

// -------------------
PHP_METHOD(GtkApplication, prefers_app_menu)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gboolean ret = gtk_application_prefers_app_menu(GTK_APPLICATION(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GtkApplication, get_menu_by_id)
{
	char * id;
	size_t id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(id, id_len)
	ZEND_PARSE_PARAMETERS_END();

	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_get_menu_by_id(GTK_APPLICATION(obj->gtk4_gpointer), id);
}

// -------------------
PHP_METHOD(GtkApplication, window_new)
{
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	gtk_application_window_new(GTK_APPLICATION(obj->gtk4_gpointer));
}

