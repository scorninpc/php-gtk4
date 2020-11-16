<?php


$override = [];


// ------------------
// TEMP
$override['gtk_container_propagate_draw']['code'] = "";


// ------------------
// GdkEvent
$override['gdk_event_get_axis']['params'][] = "value";
$override['gdk_event_get_axis']['code'] = <<<EOT
	zend_long axis_use;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(axis_use)
	ZEND_PARSE_PARAMETERS_END();

	double value;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_axis((GdkEvent*)(obj->gtk4_gpointer), axis_use, &value);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(value);
EOT;

$override['gdk_event_get_button']['params'][] = "button";
$override['gdk_event_get_button']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();
	
	int button;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_button((GdkEvent*)(obj->gtk4_gpointer), &button);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(button);
EOT;

$override['gdk_event_get_click_count']['params'][] = "click_count";
$override['gdk_event_get_click_count']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();
	
	int click_count;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_click_count((GdkEvent*)(obj->gtk4_gpointer), &click_count);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(click_count);
EOT;

$override['gdk_event_get_coords']['params'][] = "x_win";
$override['gdk_event_get_coords']['params'][] = "y_win";
$override['gdk_event_get_coords']['code'] = <<<EOT
	double x_win;
	double y_win;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_coords((GdkEvent*)(obj->gtk4_gpointer), &x_win, &y_win);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x_win);
	add_next_index_long(&ret_arr, y_win);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x_win);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y_win);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gdk_event_get_keycode']['params'][] = "keycode";
$override['gdk_event_get_keycode']['code'] = <<<EOT
	short unsigned int keycode;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_keycode((GdkEvent*)(obj->gtk4_gpointer), &keycode);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(keycode);
EOT;

$override['gdk_event_get_keyval']['params'][] = "keyval";
$override['gdk_event_get_keyval']['code'] = <<<EOT
	unsigned int keyval;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_keyval((GdkEvent*)(obj->gtk4_gpointer), &keyval);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(keyval);
EOT;

$override['gdk_event_get_root_coords']['params'][] = "x_root";
$override['gdk_event_get_root_coords']['params'][] = "y_root";
$override['gdk_event_get_root_coords']['code'] = <<<EOT
	double x_root;
	double y_root;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_root_coords((GdkEvent*)(obj->gtk4_gpointer), &x_root, &y_root);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x_root);
	add_next_index_long(&ret_arr, y_root);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x_root);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y_root);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gdk_event_get_scroll_deltas']['params'][] = "delta_x";
$override['gdk_event_get_scroll_deltas']['params'][] = "delta_y";
$override['gdk_event_get_scroll_deltas']['code'] = <<<EOT
	double delta_x;
	double delta_y;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_scroll_deltas((GdkEvent*)(obj->gtk4_gpointer), &delta_x, &delta_y);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, delta_x);
	add_next_index_long(&ret_arr, delta_y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), delta_x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), delta_y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gdk_event_get_scroll_direction']['params'][] = "direction";
$override['gdk_event_get_scroll_direction']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	GdkScrollDirection direction;
	
	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_scroll_direction((GdkEvent*)(obj->gtk4_gpointer), &direction);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(direction);
EOT;

$override['gdk_event_get_state']['params'][] = "state";
$override['gdk_event_get_state']['code'] = <<<EOT
	GdkModifierType state;

	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	bool ret = gdk_event_get_state((GdkEvent*)(obj->gtk4_gpointer), &state);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(state);
EOT;

$override['gdk_events_get_angle']['params'][] = "angle";
$override['gdk_events_get_angle']['code'] = <<<EOT
	zend_object * event2;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double angle;

	bool ret = gdk_events_get_angle((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &angle);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(angle);
EOT;

$override['gdk_events_get_center']['params'][] = "x";
$override['gdk_events_get_center']['params'][] = "y";
$override['gdk_events_get_center']['code'] = <<<EOT
	zend_object * event2;
	
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double x;
	double y;

	bool ret = gdk_events_get_center((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &x, &y);
	if(!ret) {
		RETURN_NULL();
	}

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x);
	add_next_index_long(&ret_arr, y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gdk_events_get_distance']['params'][] = "distance";
$override['gdk_events_get_distance']['code'] = <<<EOT
	zend_object * event2;
	
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(event2)
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());


	gtk4_gobject_object *gtk4_event2 = (gtk4_gobject_object*)((char*)(event2) - XtOffsetOf(gtk4_gobject_object, std));

	double distance;
	bool ret = gdk_events_get_distance((GdkEvent*)(obj->gtk4_gpointer), (GdkEvent*)(gtk4_event2->gtk4_gpointer), &distance);
	if(!ret) {
		RETURN_NULL();
	}

	RETURN_LONG(distance);
EOT;

// ------------------
// GtkApplication

$override['gtk_application_set_accels_for_action']['code'] = <<<EOT
	char * detailed_action_name;
	size_t detailed_action_name_len;
	
	zval *accels = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(detailed_action_name, detailed_action_name_len)
		Z_PARAM_ARRAY(accels);
	ZEND_PARSE_PARAMETERS_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());


	// 
	int gtk4_accels_size = zend_hash_num_elements(Z_ARR_P(accels));
	const char * c_accels[gtk4_accels_size];

	// Loop array to create C char array
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(accels), zend_ulong long_key, zend_string *str_key, zval *val) {

		// If string
		if(Z_TYPE_P(val) == IS_STRING)  {

			c_accels[long_key] = malloc(strlen(Z_STRVAL_P(val))+1);
			c_accels[long_key] = Z_STRVAL_P(val);
		}

	} ZEND_HASH_FOREACH_END();


	gtk_application_set_accels_for_action(GTK_APPLICATION(obj->gtk4_gpointer), detailed_action_name, c_accels);
EOT;

// ------------------
// GtkWindow
$override['gtk_window_get_default_size']['params'][0] = "width";
$override['gtk_window_get_default_size']['params'][1] = "height";
$override['gtk_window_get_default_size']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int width;
	int height;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_default_size(GTK_WINDOW(obj->gtk4_gpointer), &width, &height);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, width);
	add_next_index_long(&ret_arr, height);

	add_assoc_long_ex(&ret_arr, "width", strlen("width"), width);
	add_assoc_long_ex(&ret_arr, "height", strlen("height"), height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gtk_window_get_size']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int width;
	int height;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_size(GTK_WINDOW(obj->gtk4_gpointer), &width, &height);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, width);
	add_next_index_long(&ret_arr, height);

	add_assoc_long_ex(&ret_arr, "width", strlen("width"), width);
	add_assoc_long_ex(&ret_arr, "height", strlen("height"), height);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gtk_window_get_position']['code'] = <<<EOT
	ZEND_PARSE_PARAMETERS_START(0, 0)
	ZEND_PARSE_PARAMETERS_END();

	int x;
	int y;

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_get_position(GTK_WINDOW(obj->gtk4_gpointer), &x, &y);

	zval ret_arr;
	array_init(&ret_arr);

	add_next_index_long(&ret_arr, x);
	add_next_index_long(&ret_arr, y);

	add_assoc_long_ex(&ret_arr, "x", strlen("x"), x);
	add_assoc_long_ex(&ret_arr, "y", strlen("y"), y);

	RETURN_ARR(Z_ARRVAL(ret_arr));
EOT;

$override['gtk_window_set_icon_list']['code'] = <<<EOT
	zval *arr_list;
	GList *list = NULL;


	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(arr_list)
	ZEND_PARSE_PARAMETERS_END();


	// Loop array to create C char array
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(arr_list), zend_ulong long_key, zend_string *str_key, zval *val) {

		// If string
		if(Z_TYPE_P(val) == IS_OBJECT)  {
			gtk4_gobject_object *gtk4_item = (gtk4_gobject_object*)((char*)(val) - XtOffsetOf(gtk4_gobject_object, std));
			list = g_list_append (list, (GdkPixbuf *)gtk4_item->gtk4_gpointer);
		}

	} ZEND_HASH_FOREACH_END();

	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());

	gtk_window_set_icon_list(GTK_WINDOW(obj->gtk4_gpointer), list);
EOT;

// ------------------
// Enums

$override['G_APPLICATION_FLAGS_NONE']['code'] = <<<EOT
	zend_declare_class_constant_long(gapplicationflags_ce, "NONE", sizeof("NONE") - 1, G_APPLICATION_FLAGS_NONE);
EOT;

// ------------------
// Return

return $override;