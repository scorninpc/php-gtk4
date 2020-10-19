<?php

namespace Templates;

class TMethod
{
	private $method;

	private $_output_c;
	private $_output_h;


	/**
	 *
	 */
	public function __construct($method)
	{
		$this->_method = $method;
	}

	public function getC()
	{
		return $this->_output_c;
	}

	public function getH()
	{
		return $this->_output_h;
	}

	/**
	 *
	 */
	public function parse()
	{
		// if (
		// 	(strtolower($this->_method->c_name) != "gtk_window_get_title") 
		// 	&&
		// 	(strtolower($this->_method->c_name) != "gtk_window_set_title") 
		// ) {
		// 	return;
		// }

		// Parse the params
		$parsed_params = [];
		foreach($this->_method->params as $param) {
			$parsed_params[] = $this->parseArgInfo($param);
		}

		// Recupera a quantidade de parametros
		$param_count = count($this->_method->params);

		// Write header def of method (args and method def)
		$this->_output_h .= "ZEND_BEGIN_ARG_INFO_EX(arginfo_" . strtolower($this->_method->of_object) . "_" . strtolower($this->_method->name) . ", 0, 0, " . $param_count . ")\n";
		foreach($parsed_params as $param) {
			$this->_output_h .= $param['args'];
		}
		$this->_output_h .= "ZEND_END_ARG_INFO()\n";

		$this->_output_h .= sprintf("PHP_METHOD(%s, %s);", $this->_method->of_object, $this->_method->name);

		// Write C method
		$this->_output_c .= sprintf("PHP_METHOD(%s, %s)\n", $this->_method->of_object, $this->_method->name);
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
		$this->_output_c .= "\tzval *object = getThis();\n";
		$this->_output_c .= "\tgtk4_gobject_object *obj;\n";
		$this->_output_c .= "\tobj = (gtk4_gobject_object*)Z_OBJ_P(object);\n\n";

		// Parse method
		$this->_output_c .= "\t" . $this->parseMethod($this->_method, $parsed_params) . "\n";

		// Parse return
		if($this->_parsed_return) {
			$this->_output_c .= "\n";
			$this->_output_c .= "\t" . $this->_parsed_return . "\n";
		}

		// Close method
		$this->_output_c .= "}";

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

		if($param[0] == "const-char*") {
			$vars .= "\tchar * " . $param[1] . ";\n";
			$vars .= "\tsize_t " . $param[1] . "_len;\n";

			$z_params = "\t\tZ_PARAM_STRING(" . $param[1] . ", " . $param[1] . "_len)\n";
		}

		$args = "\tZEND_ARG_INFO(0, " . $param[1] . ")\n";

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
		$macro = strtoupper(substr($object->of_object, 0, 3) . "_" . substr($object->of_object, 3));

		// Return string
		if($object->return_type == "const-char*") {
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

		$output .= $object->c_name . "(" . $macro . "(obj->gtk4_gpointer)";

		// White params
		foreach($parsed_params as $param) {
			$output .= ", " . $param['c_params'];
		}

		$output .= ");";

		return $output;
	}


}