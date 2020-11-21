#ifndef _PHPGTK_GTK_H_
	#define _PHPGTK_GTK_H_ 1

	// 
	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_main, 0, 0, IS_VOID, 0)
	ZEND_END_ARG_INFO()

	// 
	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_main_quit, 0, 0, IS_VOID, 0)
	ZEND_END_ARG_INFO()

	// 
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_init, 0, 0, 0)
		ZEND_ARG_INFO(0, argc)
		ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_END_ARG_INFO()

	// 
	PHP_METHOD(Gtk, main);
	PHP_METHOD(Gtk, main_quit);
	PHP_METHOD(Gtk, init);

	// 
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_get_major_version, 0, 0, 0)
	ZEND_END_ARG_INFO()
	PHP_METHOD(Gtk, get_major_version);

	// 
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_get_minor_version, 0, 0, 0)
	ZEND_END_ARG_INFO()
	PHP_METHOD(Gtk, get_minor_version);

	// 
	ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_get_micro_version1, 0, 0, 0)
	ZEND_END_ARG_INFO()
	PHP_METHOD(Gtk, get_micro_version1);

	zend_class_entry *gtk4_gtk_ce;
	const zend_function_entry gtk_functions[] = {
		PHP_ME(Gtk, get_major_version, arginfo_gtk_get_major_version, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_ME(Gtk, get_minor_version, arginfo_gtk_get_minor_version, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_ME(Gtk, get_micro_version1, arginfo_gtk_get_micro_version1, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_ME(Gtk, main, arginfo_gtk_main, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_ME(Gtk, main_quit, arginfo_gtk_main_quit, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_ME(Gtk, init, arginfo_gtk_init, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		PHP_FE_END
	};

#endif