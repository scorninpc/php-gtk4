#include <php.h>
#include <gtk/gtk.h>

/**
 * main_quit
 */
PHP_METHOD(Gtk, main)
{
	gtk_main();
}

/**
 * main_quit
 */
PHP_METHOD(Gtk, main_quit)
{
	gtk_main_quit();
}

/**
 * initialize	
 */
PHP_METHOD(Gtk, init)
{
	long argc;
	zval *php_argv;

	// Get vars
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
			Z_PARAM_LONG(argc);
			Z_PARAM_ARRAY(php_argv);
	ZEND_PARSE_PARAMETERS_END();

	if(!argc) {
		gtk_init(NULL, NULL);
	}
	else {
		// 
		int php_argv_size = zend_hash_num_elements(Z_ARR_P(php_argv));
		char **c_argv = malloc(sizeof(char *)*php_argv_size);

		// Loop array to create C char array
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(php_argv), zend_ulong long_key, zend_string *str_key, zval *val) {

			// If string
			if(Z_TYPE_P(val) == IS_STRING)  {
				c_argv[long_key] = Z_STRVAL_P(val);
			}

		} ZEND_HASH_FOREACH_END();

		gtk_init((int *)&argc, &c_argv);
	}
}

/**
 * 
 */
PHP_METHOD(Gtk, get_major_version)
{
	RETURN_LONG(gtk_get_major_version());
}

/**
 * 
 */
PHP_METHOD(Gtk, get_minor_version)
{
	RETURN_LONG(gtk_get_minor_version());
}

/**
 * 
 */
PHP_METHOD(Gtk, get_micro_version1)
{
	RETURN_LONG(gtk_get_micro_version());
}