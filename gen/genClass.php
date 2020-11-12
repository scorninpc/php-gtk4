<?php


// ------------------
// Class
class genClass
{
	private $methods = [];

	public $class_name;
	public $class_type;
	public $module;

	public $namespace;

	public function __construct($class_name)
	{
		$this->class_name = $class_name;

		$this->namespace = \Type::getInstance()->createNamespace($class_name);
		$this->module = explode("\\", $this->namespace);
		
		$this->class_type = \Type::getInstance()->getType($class_name);

		$override_list = include(GEN_PATH . "/override.php");
	}

	public function addMethod($method)
	{
		$name = $method->c_name;
		$this->methods[$name] = $method;
	}

	public function getClassName()
	{
		return $this->class_name;
	}

	public function parseParams($params)
	{
		// Parse params type
		$this->parsed_params = [];
		$this->names_params = [];
		foreach($params as $index => $param) {
			
			$this->parsed_params[$index] = \Type::getInstance()->getType($param[0]);
			$this->names_params[$index]['name'] = $param[1];

		}
	}

	public function parse_h()
	{
		$override_list = include(GEN_PATH . "/override.php");

		$output_h = "";
		$output_h .= sprintf("#ifndef _PHPGTK_%s_H_\n", strtoupper($this->class_name));
		$output_h .= sprintf("#define _PHPGTK_%s_H_\n\n", strtoupper($this->class_name));
		
		$output_h .= sprintf("#include <php.h>\n");
		$output_h .= sprintf("#include <gtk/gtk.h>\n\n");

		$output_h .= sprintf("#include \"../../helper.h\"\n\n");
		$output_h .= sprintf("#include \"../G/GObject.h\"\n\n");

		// Loop methods
		foreach($this->methods as $method) {

			$this->parseParams($method->params);

			// Verify constructor
			if(isset($method->is_constructor_of)) {
				$method_name = "__construct";
			}
			else {
				$method_name = $method->name;
			}


			// Count params length
			$params_count = 0;
			foreach($this->parsed_params as $index => $param) {
				if($param['php_type'] == "GError") {
					continue;
				}

				$params_count++;
			}

			// Create arg info
			$output_h .= sprintf("ZEND_BEGIN_ARG_INFO_EX(arginfo_%s_%s, 0, 0, %d)\n", strtolower($this->class_name), strtolower($method_name), $params_count);
			foreach($this->parsed_params as $index => $param) {
				if($param['php_type'] == "GError") {
					continue;
				}
				$output_h .= sprintf("	ZEND_ARG_INFO(0, %s)\n", $this->names_params[$index]['name']);
			}
			$output_h .= "ZEND_END_ARG_INFO()\n\n";

			$output_h .= sprintf("PHP_METHOD(%s, %s);\n\n", $this->class_name, $method_name);
		}

		$output_h .= sprintf("static zend_class_entry *gtk4_%s_ce = NULL;\n", strtolower($this->class_name));
		$output_h .= sprintf("static const zend_function_entry %s_functions[] = {\n", strtolower($this->class_name));

		// Loop methods
		foreach($this->methods as $method) {
			// Verify constructor
			if(isset($method->is_constructor_of)) {
				$method_name = "__construct";
			}
			else {
				$method_name = $method->name;
			}

			$output_h .= sprintf("	PHP_ME(%s, %s, arginfo_%s_%s, ZEND_ACC_PUBLIC)\n", $this->class_name, strtolower($method_name), strtolower($this->class_name), strtolower($method_name));
		}


		$output_h .= sprintf("	PHP_FE_END\n");
		$output_h .= sprintf("};\n\n");
		$output_h .= sprintf("#endif\n");

		return $output_h;
	}


	public function parse_c()
	{
		$override_list = include(GEN_PATH . "/override.php");

		$output_c = "";

		// Loop methods
		foreach($this->methods as $method) {
			
			// Verify constructor
			if(isset($method->is_constructor_of)) {
				$method_name = "__construct";
			}
			else {
				$method_name = $method->name;
			}

			
			// Parse return type
			$return_type = \Type::getInstance()->getType($method->return_type);
			
			$this->parseParams($method->params);


			$output_c .= sprintf("PHP_METHOD(%s, %s) {\n", $this->class_name, $method_name);


			// Verify override
			if(isset($override_list[$method->c_name])) {
				$output_c .= $override_list[$method->c_name] . "\n";
			}

			// Generate method
			else {


				// ------------------
				// Parse variables creation
				foreach($this->parsed_params as $index => $param) {

					if($param['php_type'] == "GError") {
						$output_c .= sprintf("	GError **%s;\n", strtolower($this->names_params[$index]['name']));
					}
					else if($param['php_type'] == "STRING") {
						$output_c .= sprintf("	char * %s;\n", strtolower($this->names_params[$index]['name']));
						$output_c .= sprintf("	size_t %s_len;\n", strtolower($this->names_params[$index]['name']));
					}
					else if($param['php_type'] == "OBJ") {
						$output_c .= sprintf("	zend_object * %s;\n", strtolower($this->names_params[$index]['name']));
					}
					else {
						$output_c .= sprintf("	%s %s;\n", $param['c_type'], strtolower($this->names_params[$index]['name']));
					}

				}
				$output_c .= "\n";






				// ------------------
				// Parse params fetch

				// Count params length
				$params_count = 0;
				foreach($this->parsed_params as $index => $param) {
					if($param['php_type'] == "GError") {
						continue;
					}

					$params_count++;
				}


				$output_c .= sprintf("	ZEND_PARSE_PARAMETERS_START(%d, %d)\n", $params_count, $params_count);

				// Loop params
				foreach($this->parsed_params as $index => $param) {

					if($param['php_type'] == "GError") {
						continue;
					}
					else if($param['php_type'] == "STRING") {
						$output_c .= sprintf("		Z_PARAM_STRING(%s, %s_len)\n", strtolower($this->names_params[$index]['name']), strtolower($this->names_params[$index]['name']));
					}
					elseif($param['php_type'] == "OBJ") {
						$output_c .= sprintf("		Z_PARAM_OBJ(%s)\n", strtolower($this->names_params[$index]['name']));
					}
					else {
						$output_c .= sprintf("		Z_PARAM_%s(%s)\n", $param['php_type'], strtolower($this->names_params[$index]['name']));
					}
				}

				$output_c .= sprintf("	ZEND_PARSE_PARAMETERS_END();\n\n");





				// ------------------
				// Get current object pointer
				$output_c .= sprintf("	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());\n\n");






				// ------------------
				// If param are an object, fetch ZEND object of this parameter
				foreach($this->parsed_params as $index => $param) {
					if($param['php_type'] == "OBJ") {
						$output_c .= sprintf("	gtk4_gobject_object *gtk4_%s = (gtk4_gobject_object*)((char*)(%s) - XtOffsetOf(gtk4_gobject_object, std));\n\n\n", strtolower($this->names_params[$index]['name']), strtolower($this->names_params[$index]['name']));
					}
				}





				// ------------------
				// Call method
				$output_c .= "	";
				if(isset($method->is_constructor_of)) {
					$output_c .= "obj->gtk4_gpointer = (gpointer *)";
				}
				else if($method->return_type != "none") {
					
					// If return is an object
					if($return_type['php_type'] == "OBJ") {
						$output_c .= sprintf("gpointer *ret = (gpointer *)");
					}

					// List
					else if($return_type['php_type'] == "GList") {
						$output_c .= sprintf("GList *ret = ");
					}

					// String
					else if($return_type['php_type'] == "STRING") {
						
					}

					else {
						$output_c .= sprintf("%s ret = ", $return_type['c_type']);
					}
				}
				$output_c .= sprintf("%s(", $method->c_name);

				

				// Loop params
				$output_params = "";
				if(!isset($method->is_constructor_of)) {
					$output_params .= ", " . $this->class_type['macro'] . "(obj->gtk4_gpointer)";
				}
				foreach($this->parsed_params as $index => $param) {
					if($param['php_type'] == "OBJ") {
						$output_params .= sprintf(", %s(gtk4_%s->gtk4_gpointer)", $param['macro'], strtolower($this->names_params[$index]['name']));
					}
					else {
						$output_params .= ", " . $this->names_params[$index]['name'];
					}
				}
				$output_c .= substr($output_params, 2) . ");\n\n";

				// Verify creation
				if(isset($method->is_constructor_of)) {
					$output_c .= sprintf("	if(obj->gtk4_gpointer == NULL) php_printf(\"\\n\\nERROR ON OBJECT CREATION [%s] (@todo: add exception)\\n\\n\");\n", $this->class_name);

				}




				// ------------------
				// Parse the return
				if(isset($method->is_constructor_of)) {
				}

				// Return a array
				else if($return_type['php_type'] == "GList") {
					$output_c .= sprintf("	zval ret_arr;\n");
					$output_c .= sprintf("	array_init(&ret_arr);\n\n");

					$output_c .= sprintf("	int ret_arr_len = g_list_length(ret);\n");
					$output_c .= sprintf("	for (int i = 0; i < ret_arr_len; i++) {\n");
					$output_c .= sprintf("		gpointer element_data = g_list_nth_data(ret, i);\n\n");

					$output_c .= sprintf("		char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(element_data));\n");
					$output_c .= sprintf("		zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);\n");
					$output_c .= sprintf("		gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);\n");
					$output_c .= sprintf("		intern->gtk4_gpointer = (gpointer *)element_data;\n\n");

					$output_c .= sprintf("		zval obj1;\n");
					$output_c .= sprintf("		ZVAL_OBJ(&obj1, &intern->std);\n");
					$output_c .= sprintf("		add_next_index_zval(&ret_arr, &obj1);\n");
					$output_c .= sprintf("	}\n\n");
					$output_c .= sprintf("	RETURN_ARR(Z_ARRVAL(ret_arr));\n");

				}

				// Return an object
				else if($return_type['php_type'] == "OBJ") {
					$output_c .= sprintf("	char *ret_cn = gtk4_get_namespace(G_OBJECT_TYPE_NAME(ret));\n");
					$output_c .= sprintf("	zend_class_entry *ret_ce = gtk4_get_ce_by_name(ret_cn);\n");
					$output_c .= sprintf("	gtk4_gobject_object *intern = gtk4_create_new_object(ret_ce);\n");
					$output_c .= sprintf("	intern->gtk4_gpointer = ret;\n\n");

					$output_c .= sprintf("	RETURN_OBJ(&intern->std);\n");
				}

				// Ignore return NULL
				else if($return_type['php_type'] == "NULL") {

				}

				// Return an string
				else if($return_type['php_type'] == "STRING") {

				}

				// Return others
				else {
					$output_c .= sprintf("	RETURN_%s(ret);\n", $return_type['php_type']);
				}


// if($method->c_name == "gtk_application_get_windows") {
// 	die($output_c);
// }


			}
		





			

			$output_c .= "}\n\n";
		}

		return $output_c;
	}
}

