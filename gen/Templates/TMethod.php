<?php


namespace Templates;

class TMethod
{
	private $method;

	private $_output_c;
	private $_output_h;
	private $_output_fe;


	/**
	 *
	 */
	public function __construct($method, $object, $construct=FALSE)
	{
		$this->_method = $method;
		$this->_construct = $construct;
		$this->object_of = $object;
	}

	public function getC()
	{
		return $this->_output_c;
	}

	public function getH()
	{
		return $this->_output_h;
	}

	public function getFE()
	{
		return $this->_output_fe;
	}

	/**
	 *
	 */
	public function parse()
	{

		// if (
		// 	(strtolower($this->_method->c_name) != "atk_action_get_n_actions") 
		// 	// &&
		// 	// (strtolower($this->_method->c_name) != "gtk_window_set_title") 
		// ) {
		// 	return;
		// }


		// Verify if is a constructor
		$this->method_name = $this->_method->name;
		if($this->_construct) {
			$this->method_name = "__construct";
		}

		// Parse the params
		$parsed_params = [];
		foreach($this->_method->params as $param) {
			$parsed_params[] = $this->parseArgInfo($param);
		}

		// Recupera a quantidade de parametros
		$param_count = count($this->_method->params);

		// Write header def of method (args and method def)
		$this->_output_h .= "ZEND_BEGIN_ARG_INFO_EX(arginfo_" . strtolower($this->object_of) . "_" . strtolower($this->method_name) . ", 0, 0, " . $param_count . ")\n";
		foreach($parsed_params as $param) {
			$this->_output_h .= $param['args'];
		}
		$this->_output_h .= "ZEND_END_ARG_INFO()\n\n";

		$this->_output_h .= sprintf("PHP_METHOD(%s, %s);", $this->object_of, $this->method_name);

		// Write C method
		$this->_output_c .= sprintf("PHP_METHOD(%s, %s)\n", $this->object_of, $this->method_name);
		$this->_output_c .= "{\n";

		// Write vars
		foreach($parsed_params as $param) {
			$this->_output_c .= $param['vars'];
		}

		// Write zend parse param 
		if(count($parsed_params) > 0) {

			$this->_output_c .= sprintf("\n\tZEND_PARSE_PARAMETERS_START(%d, %d)\n", $param_count, $param_count);
			foreach($parsed_params as $param) {
				$this->_output_c .= $param['z_params'];
			}
			$this->_output_c .= sprintf("\tZEND_PARSE_PARAMETERS_END();\n\n", $param_count, $param_count);


		}

		// Get gpointer
		$this->_output_c .= "\tgtk4_gobject_object *obj = gtk4_get_current_object(getThis());\n\n";

		// Parse method
		$this->_output_c .= "\t" . $this->parseMethod($this->_method, $parsed_params) . "\n";

		// Parse return
		if($this->_parsed_return) {
			$this->_output_c .= "\n";
			$this->_output_c .= "\t" . $this->_parsed_return . "\n";
		}

		// Close method
		$this->_output_c .= "}";

		// Add FE
		$this->_output_fe = "\tPHP_ME(" . $this->object_of . ", " . $this->method_name . ", arginfo_" . strtolower($this->object_of) . "_" . strtolower($this->method_name) . ", ZEND_ACC_PUBLIC)";

		

		if($this->_construct) 
			die($this->_output_c . "\n");

	}

	/**
	 *
	 */
	public function parseArgInfo($param)
	{
		$vars = "";
		$args = "";
		$z_params = "";
		$c_params = "";

		// -------------------
		// String
		if(($param[0] == "const-char*") || ($param[0] == "const-gchar*")) {
			$vars .= "\tchar * " . $param[1] . ";\n";
			$vars .= "\tsize_t " . $param[1] . "_len;\n";

			$z_params = "\t\tZ_PARAM_STRING(" . $param[1] . ", " . $param[1] . "_len)\n";
		}

		// Boolean
		else if($param[0] == "gboolean") {
			$vars .= "\tbool " . $param[1] . ";\n";

			$z_params = "\t\tZ_PARAM_BOOL(" . $param[1] . ")\n";
		}

		// Integer
		else if($param[0] == "int") {
			$vars .= "\tint " . $param[1] . ";\n";

			$z_params = "\t\tZ_PARAM_LONG(" . $param[1] . ")\n";
		}

		// Close macro
		$args = "\tZEND_ARG_INFO(0, " . $param[1] . ")\n";

		// -------------------
		$c_params = $param[1];


		return [
			'args' => $args,
			'vars' => $vars,
			'z_params' => $z_params,
			'c_params' => $c_params,
		];	
	}

	/**
	 *
	 */
	public function parseMethod($object, $parsed_params)
	{
		$output = "";

		// Macro
		$macro = strtoupper(substr($this->object_of, 0, 3) . "_" . substr($this->object_of, 3));

		// If construct
		if($this->_construct) {
			$output .= "obj->gtk4_gpointer = (gpointer *)";
			$this->_parsed_return = "";
		}

		// Return string
		else if(($object->return_type == "const-char*") || ($object->return_type == "const-gchar*")) {
			$output .= "const gchar *ret = ";
			$this->_parsed_return = "RETURN_STRING(ret);";
		}
		// Return boolean
		else if($object->return_type == "gboolean") {
			$output .= "gboolean ret = ";
			$this->_parsed_return = "RETURN_BOOL(ret);";
		}
		else {
			$this->_parsed_return = "";
		}


		$output .= $object->c_name . "(";

		if(!$this->_construct) {
			$type = new \Type($object->of_object);
			$output .= $type->macro . "(obj->gtk4_gpointer), ";
		}

		// White params
		$output_params = "";
		foreach($parsed_params as $param) {
			$output_params .= ", " . $param['c_params'];
		}
		$output .= substr($output_params, 2);

		$output .= ");";

		return $output;
	}
}