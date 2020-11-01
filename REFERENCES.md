## References

https://developer.gnome.org/gtkmm-tutorial/unstable/sec-wrapping-defs-files.html.pt_BR
	./h2def.py /usr/include/atk-1.0/atk/*.h > atk_methods.defs
	./h2def.py /usr/include/gtk-3.0/gtk/*.h > gtk_methods.defs

https://github.com/qzfzz/php7-extension-dev-book/blob/master/11.2.md
	zend_update_property
	zend_update_static_property
	zend_read_property
	zend_read_static_property


https://www.zend.com/using-oop-in-our-example-extension
	REGISTER_INI_ENTRIES
	INIT_CLASS_ENTRY
	zend_declare_class_constant_long
	zend_declare_class_constant


https://stackoverflow.com/questions/37739699/php-extension-working-with-class-objects
	Classes
	INIT_NS_CLASS_ENTRY
	zend_update_property

https://github.com/motecshine/php-ext-example/blob/1a74d6cb9b8cc02c6647c60cbb309f3df0b125c6/closure/closure.c#L16
	Z_PARAM_VARIADIC
	zend_call_function
	zend_unwrap_reference
	ZVAL_COPY_VALUE

https://github.com/haowei4032/logger-src/blob/46e5d48a0f6dd289df8ada74f889c472c85991a2/logger.c#L94
https://www.php.net/manual/pt_BR/internals2.variables.arrays.php
	add_next_index_string
	array_init
	add_next_index_string


https://github.com/p1ncet/obcast/blob/c0763015e1e85d150516de1cae2205bf17d513a9/obcast.c
	zend_objects_new
	object_properties_init
	create_object