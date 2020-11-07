<?php

require_once(dirname(__FILE__) . "/scheme.php");
require_once(dirname(__FILE__) . "/Type.php");

$ignore_list = include(dirname(__FILE__) . "/ignore.php");
$override_list = include(dirname(__FILE__) . "/override.php");



class Merge_Parser extends Defs_Parser {
	function handle_include()
	{
		/* pass */
	}
}




// ------------------
// Merge GTK defs






$classes = [];

// ------------------
// Atk
$atk_parser = new Defs_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/atk_methods.defs");
$atk_parser->start_parsing();

\Type::getInstance()->parseEnums($atk_parser);




// ------------------
// G
$new_defs = new Merge_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gio_methods.defs");
$old_defs = new Merge_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gio_enums.defs");
$new_defs->start_parsing();
$old_defs->start_parsing(TRUE);
$new_defs->merge($old_defs, TRUE);
$fp = fopen("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gio.defs", 'wa');
$new_defs->write_defs($fp);


$g_parser = new Defs_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gio.defs");
$g_parser->start_parsing();

\Type::getInstance()->parseEnums($g_parser);








// ------------------
// Run constants
$output_c = "";
$enums = \Type::getInstance()->getEnums();
foreach($g_parser->enums as $enum) {
	// echo $enum->c_name . "\n";
	if($enum->c_name != "GApplicationFlags") {
		continue;
	}


	$output_c .= sprintf("	zend_class_entry tmp_test_ce;\n");
	$output_c .= sprintf("	INIT_CLASS_ENTRY(tmp_test_ce, \"%s\", NULL);\n", \Type::getInstance()->_createNamespace(\Type::getInstance()->_createNamespace($enum->c_name)));
	$output_c .= sprintf("	zend_class_entry *c2 = zend_register_internal_class(&tmp_test_ce);\n");
	$output_c .= sprintf("	c2->ce_flags |= ZEND_ACC_FINAL;\n");



	
	
	

	foreach($enum->values as $value) {
		$output_c .= sprintf("	zend_declare_class_constant_long(c2, \"%s\", sizeof(\"%s\") - 1, %s);\n", str_replace("-", "_", strtoupper($value[0])), str_replace("-", "_", strtoupper($value[0])), $value[1]);
	}

	var_dump($enum);
	
}

die("\n\n" . $output_c . "\n");



















// ------------------
// Gtk
// $gtk_parser = new Defs_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk_methods.defs");
// $gtk_parser->start_parsing();

$new_defs = new Merge_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk_methods.defs");
$old_defs = new Merge_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk_enums.defs");
$new_defs->start_parsing();
$old_defs->start_parsing(TRUE);
$new_defs->merge($old_defs, TRUE);
$fp = fopen("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk.defs", 'wa');
$new_defs->write_defs($fp);


$gtk_parser = new Defs_Parser("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk.defs");
$gtk_parser->start_parsing();

\Type::getInstance()->parseEnums($gtk_parser);

// Loop all parsed def methods
foreach(array_merge($gtk_parser->methods, $gtk_parser->constructors) as $method) {

	if($method->deprecated) {
		continue;
	}

	if(isset($ignore_list[$method->c_name])) {
		continue;
	}

	if(isset($method->is_constructor_of)) {
		$name = $method->is_constructor_of;
	}
	else {
		$name = $method->of_object;
	}

	// If class not exists yet, create new template
	if(!isset($classes[$name])) {
		$classes[$name] = new gtkClass("Gtk", $name);
	}

	// Add method to class template
	$classes[$name]->addMethod($method);
}





// ------------------
// Run all classes for parse
foreach($classes as $class) {

	if($class->getClassName() != "GtkApplication") {
		continue;
	}

	$class->parse($override_list);
}

















// ------------------
// Class
class gtkClass
{
	private $methods = [];

	public $class_name;
	public $class_type;
	public $module_name;

	public function __construct($module_name, $class_name)
	{
		$this->module_name = $module_name;
		$this->class_name = $class_name;
		
		$this->class_type = \Type::getInstance()->getType($class_name);
		
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

	public function parse($override_list)
	{

		$output_c = "";

		// Loop methods
		foreach($this->methods as $method) {
			debug("* Method " . $method->c_name, 1);

			// Verify constructor
			if(isset($method->is_constructor_of)) {
				$method_name = "__construct";
			}
			else {
				$method_name = $method->name;
			}

			
			// Parse return type
			$return_type = \Type::getInstance()->getType($method->return_type);
			
			// Parse params type
			$parsed_params = [];
			foreach($method->params as $index => $param) {
				debug("- Param " . $param[0], 2);
				
				$parsed_params[$index] = \Type::getInstance()->getType($param[0]);
				$names_params[$index]['name'] = $param[1];


			}

			





			$output_c .= sprintf("PHP_METHOD(%s, %s) {\n", $this->class_name, $method_name);


			// Verify override
			if(isset($override_list[$method->c_name])) {
				$output_c .= $override_list[$method->c_name] . "\n";
			}

			// Generate method
			else {


				// ------------------
				// Parse variables creation
				foreach($parsed_params as $index => $param) {

					if($param['php_type'] == "STRING") {
						$output_c .= sprintf("	char * %s;\n", strtolower($names_params[$index]['name']));
						$output_c .= sprintf("	size_t %s_len;\n", strtolower($names_params[$index]['name']));
					}
					else if($param['php_type'] == "OBJ") {
						$output_c .= sprintf("	zend_object * %s;\n", strtolower($names_params[$index]['name']));
					}
					else {
						$output_c .= sprintf("	%s %s;\n", $param['c_type'], strtolower($names_params[$index]['name']));
					}

				}
				$output_c .= "\n";






				// ------------------
				// Parse parans fetch
				$output_c .= sprintf("	ZEND_PARSE_PARAMETERS_START(%d, %d)\n", count($method->params), count($method->params));

				// Loop params
				foreach($parsed_params as $index => $param) {

					if($param['php_type'] == "STRING") {
						$output_c .= sprintf("		Z_PARAM_STRING(%s, %s_len)\n", strtolower($names_params[$index]['name']), strtolower($names_params[$index]['name']));
					}
					elseif($param['php_type'] == "OBJ") {
						$output_c .= sprintf("		Z_PARAM_OBJ(%s)\n", strtolower($names_params[$index]['name']));
					}
					else {
						$output_c .= sprintf("		Z_PARAM_%s(%s)\n", $param['php_type'], strtolower($names_params[$index]['name']));
					}
				}

				$output_c .= sprintf("	ZEND_PARSE_PARAMETERS_END();\n\n");





				// ------------------
				// Get current object pointer
				$output_c .= sprintf("	gtk4_gobject_object *obj = gtk4_get_current_object(getThis());\n\n");






				// ------------------
				// If param are an object, fetch ZEND object of this parameter
				foreach($parsed_params as $index => $param) {
					if($param['php_type'] == "OBJ") {
						$output_c .= sprintf("	gtk4_gobject_object *gtk4_%s = (gtk4_gobject_object*)((char*)(%s) - XtOffsetOf(gtk4_gobject_object, std));\n\n\n", strtolower($names_params[$index]['name']), strtolower($names_params[$index]['name']));
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
					// else {
					// 	$output_c .= sprintf("gpointer *ret = (gpointer *)");
					// }
				}
				$output_c .= sprintf("%s(", $method->c_name);

				

				// Loop params
				$output_params = "";
				if(!isset($method->is_constructor_of)) {
					$output_params .= ", " . $this->class_type['macro'] . "(obj->gtk4_gpointer)";
				}
				foreach($parsed_params as $index => $param) {
					if($param['php_type'] == "OBJ") {
						$output_params .= sprintf(", %s(gtk4_%s->gtk4_gpointer)", $param['macro'], strtolower($names_params[$index]['name']));
					}
					else {
						$output_params .= ", " . $names_params[$index]['name'];
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


// if($method->c_name == "gtk_application_get_windows") {
// 	die($output_c);
// }


			}
		





			debug("\n");

			$output_c .= "}\n\n";
		}

		// echo "\n\n\n";
		// echo $output_c;

		// die("\n\t-- \n");
	}
}

function debug($msg, $count=1)
{
	echo str_repeat("\t", $count) . "" . $msg . "\n";
}