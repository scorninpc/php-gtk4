<?php


$override = [];

// ------------------
// GtkApplication

$override['gtk_application_set_accels_for_action'] = <<<EOT
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

$override['gtk_window_get_default_size'] = <<<EOT
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

$override['gtk_window_get_size'] = <<<EOT
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

$override['gtk_window_get_position'] = <<<EOT
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

$override['gtk_window_set_icon_list'] = <<<EOT
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

$override['G_APPLICATION_FLAGS_NONE'] = <<<EOT
	zend_declare_class_constant_long(gapplicationflags_ce, "NONE", sizeof("NONE") - 1, G_APPLICATION_FLAGS_NONE);
EOT;

// ------------------
// Return

return $override;