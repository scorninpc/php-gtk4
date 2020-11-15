
#include "helper.h"

gtk4_gobject_object *gtk4_get_current_object(zval *object)
{
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(object) + 1)) - 1;

	return obj;
}

gtk4_gobject_object *gtk4_create_new_object(zend_class_entry *ce)
{
	gtk4_gobject_object *intern = ecalloc(1, sizeof(gtk4_gobject_object));
	memset(intern, 0, sizeof(gtk4_gobject_object));

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);

	memcpy(&g_object_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	g_object_object_handlers.offset = XtOffsetOf(gtk4_gobject_object, std);
	g_object_object_handlers.clone_obj = NULL;

	intern->std.handlers = &g_object_object_handlers;

	return intern;
}

zend_class_entry *gtk4_get_ce_by_name(char *class_name)
{
	zend_string *lcname = zend_string_init(class_name, strlen(class_name), 0);
	zend_string *tmp = zend_string_tolower(lcname);
	zend_string_release(lcname);
	lcname = tmp;
	zend_class_entry *ce = zend_lookup_class(lcname);

	if(!ce) {
		// gtk4_exception(-5, "Class %s not found", class_name);
		php_error_docref(NULL, E_ERROR, "Class %s not found", class_name);
	}

	return ce;
}

char *gtk4_get_namespace(const char *class)
{
	char *new = (char *)emalloc(1);
	int new_length = 0;
	
	strcpy(new, "");

	for(int i=0; i<strlen(class); i++) {


		// Verify if is a upper char
		int ch = (int)class[i];

		if(  ( (ch >= 65) && (ch <= 90) ) && (i > 0)  )  {
			new_length += 1;
			
			char *tmp = (char *)erealloc(new, sizeof(char *) * new_length);
			if(!tmp) {
				php_printf("ERROR on realoc\n");
				return "";
			}
			new = tmp;
			
			strcat(new, "\\");
		}


		new_length++;

		char *tmp = (char *)erealloc(new, sizeof(char *) * new_length);
		if(!tmp) {
			php_printf("ERROR on realoc\n");
			return "";
		}
		new = tmp;

		new[new_length-1] = class[i];
		new[new_length] = '\0';
	}

	return new;
}

/**
 * Throw a GTK Exception	
 */
char *gtk4_exception(int code, char *format, ...)
{
	va_list arg;
	char *message;

	va_start(arg, format);
	vspprintf(&message, 0, format, arg);
	va_end(arg);

	// zend_class_entry *ce = zend_exception_get_default();

	// zend_throw_exception(zend_ce_exception, message, code);
	zend_exception_error(zend_throw_exception(gtk4_get_ce_by_name("Gtk\\Exception"), message, code), E_ERROR);
}


/**
 * Convert zval to a GValue
 */
GValue zval_to_gvalue(zval *z_value)
{
	GValue gv_ret = G_VALUE_INIT;

	if(Z_TYPE_P(z_value) == IS_STRING) {
		g_value_init (&gv_ret, G_TYPE_STRING);
		g_value_set_string(&gv_ret, Z_STRVAL_P(z_value));
	}

	return gv_ret;
}

/**
 * Convert zval to a GValue
 */
zval *gvalue_to_zval(GValue gz_value)
{
	zval *z_ret;

	php_printf("\n\nOK1\n\n");

	switch(G_VALUE_TYPE(&gz_value)) {

		// String
		case G_TYPE_STRING:
        {
			php_printf("\n\nOK2\n\n");
			const char *char_str = g_value_get_string(&gz_value);

			php_printf("\n\nOK3\n\n");
			// zend_string *string_str = zend_string_init(char_str, strlen(char_str), 0);
			

			php_printf("\n\nOK4: %s\n\n", char_str);
        	// ZVAL_STR(&z_ret, string_str);
        	// ZVAL_STRING(&z_ret, char_str);
			php_printf("\n\nOK5\n\n");
        }

	}

	return z_ret;
}