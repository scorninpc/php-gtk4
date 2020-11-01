
#include "GObject.h"


/*
	
	========================================================================== */
zend_object *g_object_create_object(zend_class_entry *class_type) 
{
	php_printf("\n\t++ Creating\n");

	gtk4_gobject_object *intern = ecalloc(1, sizeof(gtk4_gobject_object));
	memset(intern, 0, sizeof(gtk4_gobject_object));

	// zend_object_std_init(&intern->std, class_type);
	// object_properties_init(&intern->std, class_type);

	intern->gtk4_gpointer = NULL;
	zend_object_std_init(&intern->std, class_type);
	object_properties_init(&intern->std, class_type);


	memcpy(&g_object_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	g_object_object_handlers.offset = XtOffsetOf(gtk4_gobject_object, std);
	g_object_object_handlers.clone_obj = NULL;

	intern->std.handlers = &g_object_object_handlers;

	return &intern->std;
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


	// zval *object = getThis();
	// gtk4_gobject_object *obj;
	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);


	// obj->test = rand()%50;
}


/*
	
	========================================================================== */
PHP_METHOD(GObject, test)
{

	// zval *object = getThis();
	// gtk4_gobject_object *obj;

	// obj = (gtk4_gobject_object*)Z_OBJ_P(object);

	/*zval *item, *obj, rv;

	zend_class_entry *ce;
	ce = Z_OBJCE_P(getThis());

	obj = getThis();

	item = zend_read_property(ce, obj, "prop_gpointer", sizeof("prop_gpointer") - 1, 0, &rv);
*/

	// RETURN_LONG(obj->test);
	// RETURN_ZVAL(object, 1, 0);
}

/*
	
	========================================================================== */
PHP_METHOD(GObject, connect)
{


	zend_fcall_info fci;
	zend_fcall_info_cache fcc;

	char *signal_name;
	size_t signal_name_size;

	// ----------------
	// Create callback info object
    st_callback *callback_object = malloc(sizeof(st_callback));

	// ----------------
	ZEND_PARSE_PARAMETERS_START(2, -1)
		Z_PARAM_STRING(signal_name, signal_name_size)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_VARIADIC('*', callback_object->extra_params, callback_object->extra_params_n)
	ZEND_PARSE_PARAMETERS_END();

	// Test of param after. Get it from optonal param
	bool after = false;

	// ----------------
	// Get gpointer
	zval *object = getThis();
	gtk4_gobject_object *obj = ((gtk4_gobject_object*)(Z_OBJ_P(getThis()) + 1)) - 1;

	callback_object->fci = fci;
	callback_object->fcc = fcc;
	callback_object->self = object;
	callback_object->self_object = obj;


	// ----------------
	// Retriave and store signal query parameters , to be used on callback
	GSignalQuery signal_info;

	if(G_IS_OBJECT(obj->gtk4_gpointer)) {
		g_signal_query(g_signal_lookup(signal_name, G_OBJECT_TYPE (obj->gtk4_gpointer)), &signal_info);
	}

	if(G_IS_OBJECT_CLASS(obj->gtk4_gpointer)) {
		g_signal_query(g_signal_lookup(signal_name, G_OBJECT_CLASS_TYPE (obj->gtk4_gpointer)), &signal_info);
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
	closure = g_cclosure_new_swap(G_CALLBACK (connect_callback), callback_object, NULL);
	int ret = g_signal_connect_closure(obj->gtk4_gpointer, signal_name, closure, after);

	// Return handler id
	RETURN_LONG(ret);
}

/*
 * internal callback. All signals connect to this function
 */
bool connect_callback(gpointer user_data, ...)
{
	// Return to st_callback
	st_callback *callback_object = (st_callback *)user_data;

	int params_n = callback_object->extra_params_n + 1;

	// ----------------
	zval retval;
	callback_object->fci.retval = &retval;
	callback_object->fci.param_count = params_n;
	callback_object->fci.params = safe_emalloc(sizeof(zval *), params_n, 0);

	// ZVAL_COPY_VALUE(&callback_object->fci.params[0], callback_object->self);
	callback_object->fci.params[0] = *callback_object->self;

	for(int i=0; i<callback_object->extra_params_n; i++) {
		callback_object->fci.params[i+1] = callback_object->extra_params[i];
	}

	// ----------------





	// ----------------
	// Call
	if(zend_call_function(&callback_object->fci, &callback_object->fcc) == FAILURE) {
		php_error_docref(NULL, E_CORE_ERROR, "Cannot call");
	}



/*
	int params_n = 3;//callback_object->extra_params_n + 1;

	// ----------------
	// Populate fci for call
	zend_fcall_info fci = {0};
	fci = callback_object->fci;
	
	zval retval;
	fci.retval = &retval;

	fci.param_count = params_n;

	// alloc parameters
	fci.params = safe_emalloc(sizeof(zval *), params_n, 0);
	// fci.params = emalloc(fci.param_count * sizeof *fci.params);
    // memset(callback_object, 0, sizeof(zval));

	// self
	// zval *self = callback_object->self;
	// ZVAL_COPY_VALUE(&fci.params[0], self);
	fci.params[0] = callback_object->self;

	// Add extra parameters
	/*for(int i=0; i<callback_object->extra_params_n; i++) {
		fci.params[i+1] = callback_object->extra_params[i];
	}* /

	zval p1;
	ZVAL_STRING(&p1, "param1");
	// fci.params[1] = p1;
	ZVAL_COPY_VALUE(&fci.params[1], &p1);

	zval p2;
	ZVAL_STRING(&p2, "param2");
	fci.params[2] = p2;
	*/

	

	return 1;
}