
#include "GObject.h"


/*
	
	========================================================================== */


static zend_object_handlers g_object_object_handlers;
zend_object *g_object_create_object(zend_class_entry *class_type) 
{
	gtk4_gobject_object *intern = (gtk4_gobject_object *) emalloc(sizeof(gtk4_gobject_object));
	memset(intern, 0, sizeof(gtk4_gobject_object));

	// zend_object_std_init(&intern->zo, class_type);
	// object_properties_init(&intern->zo, class_type);

	zend_object_std_init(&intern->zo, class_type);
	object_properties_init(&intern->zo, class_type);

	memcpy(&g_object_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	intern->zo.handlers = &g_object_object_handlers;

	return &intern->zo;
}

/*
	
	========================================================================== */
PHP_METHOD(GObject, __construct)
{
	srand(time(NULL));

	// zval *object;
	// object = getThis();

	// gtk4_gobject_object *intern = NULL;
	// intern = (gtk4_gobject_object *)php_intl_messageformatter_fetch_object(Z_OBJ_P(gtk4_g_gobject_ce));
	// assert(tobj != NULL);


	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);


	obj->test = rand()%50;
}


/*
	
	========================================================================== */
PHP_METHOD(GObject, test)
{

	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	/*zval *item, *obj, rv;

	zend_class_entry *ce;
	ce = Z_OBJCE_P(getThis());

	obj = getThis();

	item = zend_read_property(ce, obj, "prop_gpointer", sizeof("prop_gpointer") - 1, 0, &rv);
*/
	
	RETURN_LONG(obj->test);
}

/*
	
	========================================================================== */
PHP_METHOD(GObject, connect)
{

	zend_fcall_info fci;
	zend_fcall_info_cache fcc;

	char *signal_name;
	size_t signal_name_size;

	zval *args;
	int argc;

	ZEND_PARSE_PARAMETERS_START(2, -1)
		Z_PARAM_STRING(signal_name, signal_name_size)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_VARIADIC('+', args, argc)
	ZEND_PARSE_PARAMETERS_END();




/*========================================================================== */

	// GSignalQuery signal_info;

	// if(G_IS_OBJECT(instance)) {
 //        g_signal_query(g_signal_lookup (callback_event, G_OBJECT_TYPE (instance)), &signal_info);
 //    }

 //    if(G_IS_OBJECT_CLASS(instance)) {
 //        g_signal_query(g_signal_lookup (callback_event, G_OBJECT_CLASS_TYPE (instance)), &signal_info);
 //    }


/*========================================================================== */







	// Popula
	zval retval;
	fci.retval = &retval;

	fci.param_count = argc;
	fci.params = args;

	// Call
	if(zend_call_function(&fci, &fcc) == FAILURE) {
		php_error_docref(NULL, E_CORE_ERROR, "Cannot call");
	}

	// Get return
	if(Z_TYPE(retval) == IS_STRING) {
		printf("%s\n", Z_STRVAL_P(&retval));
	}

	// Free ret
	zval_ptr_dtor(&retval);
	zval_ptr_dtor(args);
	php_printf("\t-> GObject::connect called\n");
}