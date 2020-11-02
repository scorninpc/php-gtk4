#include "GApplication.h"
// -------------------
PHP_METHOD(GApplication, __construct)
{
	char * application_id;
	size_t application_id_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(application_id, application_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	obj->gtk4_gpointer = (gpointer *)g_application_new(, application_id, flags);
}

// -------------------
PHP_METHOD(GApplication, get_application_id)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const gchar *ret = g_application_get_application_id(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_STRING(ret);
}

// -------------------
PHP_METHOD(GApplication, set_application_id)
{
	char * application_id;
	size_t application_id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(application_id, application_id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_application_id(G_APPLICATION(obj->gtk4_gpointer), application_id);
}

// -------------------
PHP_METHOD(GApplication, get_dbus_connection)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_get_dbus_connection(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, get_dbus_object_path)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const gchar *ret = g_application_get_dbus_object_path(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_STRING(ret);
}

// -------------------
PHP_METHOD(GApplication, get_inactivity_timeout)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_get_inactivity_timeout(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, set_inactivity_timeout)
{

	ZEND_PARSE_PARAMETERS_START(1, 1)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_inactivity_timeout(G_APPLICATION(obj->gtk4_gpointer), inactivity_timeout);
}

// -------------------
PHP_METHOD(GApplication, get_flags)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_get_flags(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, set_flags)
{

	ZEND_PARSE_PARAMETERS_START(1, 1)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_flags(G_APPLICATION(obj->gtk4_gpointer), flags);
}

// -------------------
PHP_METHOD(GApplication, get_resource_base_path)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	const gchar *ret = g_application_get_resource_base_path(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_STRING(ret);
}

// -------------------
PHP_METHOD(GApplication, set_resource_base_path)
{
	char * resource_path;
	size_t resource_path_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(resource_path, resource_path_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_resource_base_path(G_APPLICATION(obj->gtk4_gpointer), resource_path);
}

// -------------------
PHP_METHOD(GApplication, set_action_group)
{

	ZEND_PARSE_PARAMETERS_START(1, 1)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_action_group(G_APPLICATION(obj->gtk4_gpointer), action_group);
}

// -------------------
PHP_METHOD(GApplication, add_main_option_entries)
{

	ZEND_PARSE_PARAMETERS_START(1, 1)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_add_main_option_entries(G_APPLICATION(obj->gtk4_gpointer), entries);
}

// -------------------
PHP_METHOD(GApplication, add_main_option)
{
	char * long_name;
	size_t long_name_len;
	char * description;
	size_t description_len;
	char * arg_description;
	size_t arg_description_len;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_STRING(long_name, long_name_len)
		Z_PARAM_STRING(description, description_len)
		Z_PARAM_STRING(arg_description, arg_description_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_add_main_option(G_APPLICATION(obj->gtk4_gpointer), long_name, short_name, flags, arg, description, arg_description);
}

// -------------------
PHP_METHOD(GApplication, add_option_group)
{

	ZEND_PARSE_PARAMETERS_START(1, 1)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_add_option_group(G_APPLICATION(obj->gtk4_gpointer), group);
}

// -------------------
PHP_METHOD(GApplication, set_option_context_parameter_string)
{
	char * parameter_string;
	size_t parameter_string_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(parameter_string, parameter_string_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_option_context_parameter_string(G_APPLICATION(obj->gtk4_gpointer), parameter_string);
}

// -------------------
PHP_METHOD(GApplication, set_option_context_summary)
{
	char * summary;
	size_t summary_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(summary, summary_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_option_context_summary(G_APPLICATION(obj->gtk4_gpointer), summary);
}

// -------------------
PHP_METHOD(GApplication, set_option_context_description)
{
	char * description;
	size_t description_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(description, description_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_option_context_description(G_APPLICATION(obj->gtk4_gpointer), description);
}

// -------------------
PHP_METHOD(GApplication, get_is_registered)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gboolean ret = g_application_get_is_registered(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GApplication, get_is_remote)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gboolean ret = g_application_get_is_remote(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GApplication, register)
{

	ZEND_PARSE_PARAMETERS_START(2, 2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gboolean ret = g_application_register(G_APPLICATION(obj->gtk4_gpointer), cancellable, error);

	RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GApplication, hold)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_hold(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, release)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_release(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, activate)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_activate(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, open)
{
	char * hint;
	size_t hint_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STRING(hint, hint_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_open(G_APPLICATION(obj->gtk4_gpointer), files, n_files, hint);
}

// -------------------
PHP_METHOD(GApplication, run)
{
	int argc;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(argc)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_run(G_APPLICATION(obj->gtk4_gpointer), argc, argv);
}

// -------------------
PHP_METHOD(GApplication, quit)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_quit(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, set_default)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_set_default(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, mark_busy)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_mark_busy(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, unmark_busy)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_unmark_busy(G_APPLICATION(obj->gtk4_gpointer));
}

// -------------------
PHP_METHOD(GApplication, get_is_busy)
{
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gboolean ret = g_application_get_is_busy(G_APPLICATION(obj->gtk4_gpointer));

	RETURN_BOOL(ret);
}

// -------------------
PHP_METHOD(GApplication, send_notification)
{
	char * id;
	size_t id_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(id, id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_send_notification(G_APPLICATION(obj->gtk4_gpointer), id, notification);
}

// -------------------
PHP_METHOD(GApplication, withdraw_notification)
{
	char * id;
	size_t id_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(id, id_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_withdraw_notification(G_APPLICATION(obj->gtk4_gpointer), id);
}

// -------------------
PHP_METHOD(GApplication, bind_busy_property)
{
	char * property;
	size_t property_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(property, property_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_bind_busy_property(G_APPLICATION(obj->gtk4_gpointer), object, property);
}

// -------------------
PHP_METHOD(GApplication, unbind_busy_property)
{
	char * property;
	size_t property_len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(property, property_len)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	g_application_unbind_busy_property(G_APPLICATION(obj->gtk4_gpointer), object, property);
}

