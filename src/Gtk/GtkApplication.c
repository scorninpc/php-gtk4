#include "GtkApplication.h"



// -------------------
PHP_METHOD(GtkApplication, __construct)
{
	char * application_id;
	size_t application_id_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(application_id, application_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	obj->gtk4_gpointer = (gpointer *)gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
}

// -------------------
PHP_METHOD(GtkApplication, window_new)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	GtkWidget *ret = gtk_application_window_new(GTK_APPLICATION(obj->gtk4_gpointer));







	// zval *php_obj;
	// object_init_ex(php_obj, gtk4_gtk_window_ce);

	// gtk4_gobject_object *intern = (gtk4_gobject_object *) emalloc(sizeof(gtk4_gobject_object));
	// memset(intern, 0, sizeof(gtk4_gobject_object));
	
	// intern->std = *Z_OBJ_P(php_obj);
	// intern->gtk4_gpointer = (gpointer *)ret;





	// php_printf("\n\tCriando\n");

	// zend_object zov;

	// gtk4_gobject_object *intern;
	// intern = emalloc(sizeof *intern);

	// php_printf("\n\tCriado handle\n");

	// zov.handle = zend_objects_store_put(intern, NULL, NULL, NULL);
	
	// intern->std.handlers = &g_object_object_handlers;

	// php_printf("\n\tObjeto criado\n");

	// zend_object_std_init((zend_object *) intern, gtk4_gtk_window_ce);

	// php_printf("\n\tInterno criado\n");

	// intern->gtk4_gpointer = (gpointer *)ret;


	// php_printf("\n\tTudo criado\n");
	




	php_printf("\n\tRecuperando CE\n");

	zend_class_entry *ce = NULL; 
	zend_string *class_name = zend_string_init("Gtk\\Window", sizeof("Gtk\\Window") - 1, false);
	ce = zend_lookup_class(class_name);




	/*php_printf("\n\tCriando\n");
	
	zend_object *object;


	php_printf("\n\tObjeto\n");


	object = zend_objects_new(ce);
	
	php_printf("\n\tObjeto init\n");

	object_properties_init(object, ce);
	
	php_printf("\n\tObjeto handlers\n");

	object->handlers = &g_object_object_handlers;

	


	php_printf("\n\tCriando internal\n");*/





	gtk4_gobject_object *intern = ecalloc(1, sizeof(gtk4_gobject_object));
	memset(intern, 0, sizeof(gtk4_gobject_object));

	intern->gtk4_gpointer = (gpointer *)ret;
	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);

	memcpy(&g_object_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	g_object_object_handlers.offset = XtOffsetOf(gtk4_gobject_object, std);
	g_object_object_handlers.clone_obj = NULL;

	intern->std.handlers = &g_object_object_handlers;







	php_printf("\n\tCriado\n");



	if (intern == NULL) {
		php_printf("\n\tNULL\n");

		RETURN_NULL();
	}

	
	php_printf("\n\tOK\n");

	RETURN_OBJ(&intern->std);

}
/*
// -------------------
PHP_METHOD(GtkApplication, run)
{
	int ret;

	long argc;
	bool argc_is_null = 1;
	zval *php_argv;

	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// Get vars
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
			Z_PARAM_LONG_EX(argc, argc_is_null, 1, 0);
			Z_PARAM_ARRAY(php_argv);
	ZEND_PARSE_PARAMETERS_END();

	
	if(argc_is_null) {
		argc = 0;
	}
	
	int php_argv_size = argc;
	char **c_argv = malloc(sizeof(char *)*php_argv_size);

	// Loop array to create C char array
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(php_argv), zend_ulong long_key, zend_string *str_key, zval *val) {

		// If string
		if(Z_TYPE_P(val) == IS_STRING)  {
			c_argv[long_key] = Z_STRVAL_P(val);
		}

	} ZEND_HASH_FOREACH_END();

	// Call
	ret = g_application_run(G_APPLICATION(obj->gtk4_gpointer), argc, c_argv);

	// Return
	RETURN_LONG(ret);

}*/

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



