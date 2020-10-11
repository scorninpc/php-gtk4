
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

	zval *varargs;
	int num_varargs;

	ZEND_PARSE_PARAMETERS_START(2, -1)
		Z_PARAM_STRING(signal_name, signal_name_size)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_VARIADIC('*', fci.params, fci.param_count)
		// Z_PARAM_VARIADIC('*', varargs, num_varargs)
	ZEND_PARSE_PARAMETERS_END();

	// Test of param after. Get it from optonal param
	bool after = false;


	// ----------------
	// Get gpointer
	zval *object = getThis();
	gtk4_gobject_object *obj;
	obj = (gtk4_gobject_object*)Z_OBJ_P(object);


	// ----------------
	// Create callback info object
    st_callback *callback_object = (st_callback *)malloc(sizeof(st_callback));
    memset(callback_object, 0, sizeof(st_callback));



    // php_printf("%d", fci.param_count);
    callback_object->fci = fci;
    callback_object->fcc = fcc;


	// ----------------
    // Retriave and store signal query parameters , to be used on callback
    GSignalQuery signal_info;

    if(G_IS_OBJECT(obj->gtk4_gpointer)) {
        g_signal_query(g_signal_lookup (signal_name, G_OBJECT_TYPE (obj->gtk4_gpointer)), &signal_info);
    }

    if(G_IS_OBJECT_CLASS(obj->gtk4_gpointer)) {
        g_signal_query(g_signal_lookup (signal_name, G_OBJECT_CLASS_TYPE (obj->gtk4_gpointer)), &signal_info);
    }

    callback_object->signal_id = signal_info.signal_id;
    callback_object->signal_name = signal_info.signal_name;
    callback_object->itype = signal_info.itype;
    callback_object->signal_flags = signal_info.signal_flags;
    callback_object->return_type = signal_info.return_type;
    callback_object->n_params = signal_info.n_params;
    callback_object->param_types = signal_info.param_types;

    // ----------------
    // Do the connection
    GClosure  *closure;
    closure = g_cclosure_new_swap (G_CALLBACK (connect_callback), callback_object, NULL);
    int ret = g_signal_connect_closure (obj->gtk4_gpointer, signal_name, closure, after);

    // Return handler id
    RETURN_LONG(ret);
}

/*
 * internal callback. All signals connect to this function
 */
bool connect_callback(gpointer user_data, ...)
{
	// Return to st_callback
    st_callback *callback_object = (st_callback *) user_data;

	// Popula
	zval retval;
	callback_object->fci.retval = &retval;

	// Call
	if(zend_call_function(&callback_object->fci, &callback_object->fcc) == FAILURE) {
		php_error_docref(NULL, E_CORE_ERROR, "Cannot call");
	}

	// ----------------
	// php_printf("\n\n[c] params: %d\n", callback_object->fci.param_count);

	// for(int i=0; i<callback_object->fci.param_count;i++) {
	// 	// php_printf("param %d = %s", i, Z_STRVAL(callback_object->fci.params[i]));
	// 	php_printf("param %d\n", Z_TYPE(callback_object->fci.params[i]));
	// }

	// ----------------
	// Free ret
	// zval_ptr_dtor(&retval);
	// zval_ptr_dtor(callback_object->fci.params);

	return 1;
}