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


	/**
	 *
	 */
	public function parse()
	{
		// if($this->_method->name != "get_default_size") {
		// 	return FALSE;
		// }

		$this->_output_h = sprintf("PHP_METHOD(%s, %s);", $this->_method->of_object, $this->_method->name);

		// Recupera a quantidade de parametros
		$param_count = count($this->_method->params);

		// ZEND_BEGIN_ARG_INFO_EX(name, _unused, return_reference, required_num_args)
		$this->_output_c = "ZEND_BEGIN_ARG_INFO_EX(arginfo_" . strtolower($this->_method->of_object) . "_" . strtolower($this->_method->name) . ", 0, 0, " . $param_count . ")\n";
		foreach($this->_method->params as $param) {
			$this->_output_c .= "ZEND_END_ARG_INFO()\n";
		}
		$this->_output_c .= "ZEND_END_ARG_INFO()\n";

		var_dump($this->_method);
 
		echo "\n\n" . $this->_output_c . "\n\n";		
		echo "\n\n" . $this->_output_h . "\n\n";

		// var_dump($this->_method);
	}

}