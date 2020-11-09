<?php


$override = [];

// gtk_application_set_accels_for_action
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

// gtk_window_set_icon_list
$override['gtk_window_set_icon_list'] = "";
$override['gtk_window_activate_key'] = "";
$override['gtk_window_get_default_size'] = "";
$override['gtk_window_get_opacity'] = "";
$override['gtk_window_get_resize_grip_area'] = "";
$override['gtk_window_get_size'] = "";
$override['gtk_window_get_position'] = "";
$override['gtk_window_set_opacity'] = "";
$override['gtk_window_resize_to_geometry'] = "";
$override['gtk_window_parse_geometry'] = "";
$override['gtk_window_propagate_key_event'] = "";
$override['gtk_window_reshow_with_initial_size'] = "";
$override['gtk_window_set_default_geometry'] = "";
$override['gtk_window_set_geometry_hints'] = "";
$override['gtk_window_set_has_resize_grip'] = "";
$override['gtk_window_set_icon_from_file'] = "";
$override['gtk_window_set_wmclass'] = "";
$override['gtk_window_set_type_hint'] = "";
$override['gtk_window_resize_grip_is_visible'] = "";
$override['gtk_window_get_has_resize_grip'] = "";
$override['gtk_window_begin_resize_drag'] = "";
$override['gtk_window_mnemonic_activate'] = "";
$override['gtk_window_set_gravity'] = "";
$override['gtk_window_set_mnemonic_modifier'] = "";

// Enums
$override['G_APPLICATION_FLAGS_NONE'] = <<<EOT
	zend_declare_class_constant_long(gapplicationflags_ce, "NONE", sizeof("NONE") - 1, G_APPLICATION_FLAGS_NONE);
EOT;

return $override;