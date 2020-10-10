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
		// Percorre os metodos
		foreach($this->_methods as $method) {
			$method_text = $method->parse();
		}

		// var_dump($method_text);
	}


}