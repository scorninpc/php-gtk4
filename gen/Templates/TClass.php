<?php

namespace Templates;

class TClass
{
	private $_methods;
	private $_name;

	public function getName()
	{
		return $this->_name;
	}

	/**
	 *
	 */
	public function addMethod($method)
	{
		$method_name = $method->name;

		$this->_name = $method->of_object;

		$this->_methods[$method_name] = new TMethod($method);
	}


	/**
	 * Parse
	 */
	public function parse()
	{
		$_output_h = "";
		$_output_c = "";

		// Percorre os metodos
		foreach($this->_methods as $method) {
			$method->parse();

			if(strlen($method->getH()) > 0) {
				$_output_h .= "// -------------------\n";
				$_output_h .= $method->getH() . "\n\n";

				$_output_c .= "// -------------------\n";
				$_output_c .= $method->getC() . "\n\n";
			}
		}

		// var_dump($this->_method);
		echo "\n\n-> .h\n" . $_output_h . "\n\n";
		echo "\n\n-> .c\n" . $_output_c . "\n\n";
	}


}