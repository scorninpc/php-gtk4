#include "GApplication.h"
// -------------------
PHP_METHOD(GApplication, __construct)
{
	char * application_id;
	size_t application_id_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(application_id, application_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	obj->gtk4_gpointer = (gpointer *)g_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
}

// -------------------
PHP_METHOD(GApplication, get_application_id)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	const gchar *ret = g_application_get_application_id(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_STRING(ret);
}

// -------------------
PHP_METHOD(GApplication, set_application_id)
{
	// char * application_id;
	// size_t application_id_len;

	// ZEND_PARSE_PARAMETERS_START(1, 1)
	// 	Z_PARAM_STRING(application_id, application_id_len)
	// ZEND_PARSE_PARAMETERS_END();

	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// g_application_set_application_id(G_APPLICATION(obj->gtk4_gpointer), application_id);
}

// -------------------
PHP_METHOD(GApplication, get_dbus_connection)
{
	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	// g_application_get_dbus_connection(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, get_dbus_object_path)
{
	
}

// -------------------
PHP_METHOD(GApplication, get_inactivity_timeout)
{
	
}

// -------------------
PHP_METHOD(GApplication, set_inactivity_timeout)
{

	
}

// -------------------
PHP_METHOD(GApplication, get_flags)
{
	
}

// -------------------
PHP_METHOD(GApplication, set_flags)
{

	
}

// -------------------
PHP_METHOD(GApplication, get_resource_base_path)
{
	
}

// -------------------
PHP_METHOD(GApplication, set_resource_base_path)
{
	
}

// -------------------
PHP_METHOD(GApplication, set_action_group)
{

	
}

// -------------------
PHP_METHOD(GApplication, add_main_option_entries)
{

	
}

// -------------------
PHP_METHOD(GApplication, add_main_option)
{

}

// -------------------
PHP_METHOD(GApplication, add_option_group)
{

}

// -------------------
PHP_METHOD(GApplication, set_option_context_parameter_string)
{

}

// -------------------
PHP_METHOD(GApplication, set_option_context_summary)
{

}

// -------------------
PHP_METHOD(GApplication, set_option_context_description)
{

}

// -------------------
PHP_METHOD(GApplication, get_is_registered)
{
	
}

// -------------------
PHP_METHOD(GApplication, get_is_remote)
{
}

// -------------------
PHP_METHOD(GApplication, register)
{

}

// -------------------
PHP_METHOD(GApplication, hold)
{

}

// -------------------
PHP_METHOD(GApplication, release)
{

}

// -------------------
PHP_METHOD(GApplication, activate)
{

}

// -------------------
PHP_METHOD(GApplication, open)
{

}

// -------------------
PHP_METHOD(GApplication, run)
{
	int ret;

	long argc;
	bool argc_is_null = 1;
	zval *php_argv;

	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

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

}

// -------------------
PHP_METHOD(GApplication, quit)
{
	
}

// -------------------
PHP_METHOD(GApplication, set_default)
{
	
}

// -------------------
PHP_METHOD(GApplication, mark_busy)
{
	
}

// -------------------
PHP_METHOD(GApplication, unmark_busy)
{
	
}

// -------------------
PHP_METHOD(GApplication, get_is_busy)
{
	
}

// -------------------
PHP_METHOD(GApplication, send_notification)
{
	
}

// -------------------
PHP_METHOD(GApplication, withdraw_notification)
{
	
}

// -------------------
PHP_METHOD(GApplication, bind_busy_property)
{
	
}

// -------------------
PHP_METHOD(GApplication, unbind_busy_property)
{
	
}

