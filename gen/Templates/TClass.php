<?php

namespace Templates;

class TClass
{
	private $_methods;
	private $_name;

	private $_header_content;
	private $_code_content;

	public function getName()
	{
		return $this->_name;
	}

	/**
	 *
	 */
	public function addMethod($method, $construct=FALSE)
	{
		$method_name = $method->name;

		if(isset($method->of_object)) {
			$this->_name = $method->of_object;
		}
		else if(isset($method->is_constructor_of)) {
			$this->_name = $method->is_constructor_of;
		}

		$this->_methods[$method_name] = new TMethod($method, $this->getName(), $construct);
	}


	/**
	 * Parse
	 */
	public function parse()
	{
		$_output_h = "";
		$_output_c = "";

		// -------------------
		// Start create header 
		$_output_h .= "#ifndef _PHPGTK_" . strtolower($this->getName()) . "_H_\n";
		$_output_h .= "#define _PHPGTK_" . strtolower($this->getName()) . "_H_\n\n";
		$_output_h .= "#include <php.h>\n";
		$_output_h .= "#include <gtk/gtk.h>\n\n";
		$_output_h .= "#include \"../../gtk4.h\"\n\n";


		// -------------------
		// Start create code
		$_output_c .= "#include \"" . $this->getName() . ".h\"\n";


		// -------------------
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

		// -------------------
		// Close header
		$_output_h .= "// -------------------\n";
		$_output_h .= "static zend_class_entry *gtk4_" . strtolower($this->getName()) . "_ce = NULL;\n";
		$_output_h .= "static const zend_function_entry " . strtolower($this->getName()) . "_functions[] = {\n";
		$_output_h .= "\tPHP_FE_END\n";
		$_output_h .= "};\n\n";

		$_output_h .= "#endif";

		// -------------------
		// Store contents
		$this->_header_content = $_output_h;
		$this->_code_content = $_output_c;
	}

	public function getHeaderContent()
	{
		return $this->_header_content;
	}

	public function getCodeContent()
	{
		return $this->_code_content;
	}


}