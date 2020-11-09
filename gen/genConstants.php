<?php


class genConstants
{
	private $parsers = [];
	private $constants_c = "";

	public function addParser($parser)
	{
		$this->parsers[] = $parser;
	}

	public function parse()
	{
		$override_list = include(dirname(__FILE__) . "/override.php");

		
		$this->constants_c = "";


		foreach($this->parsers as $parser) {

			foreach($parser->enums as $enum) {

				// if($enum->c_name != "GtkApplicationInhibitFlags") {
				// 	continue;
				// }

				$this->constants_c .= sprintf("	zend_class_entry tmp_%s_ce;\n", strtolower($enum->c_name));
				$this->constants_c .= sprintf("	INIT_CLASS_ENTRY(tmp_%s_ce, \"%s\", NULL);\n", strtolower($enum->c_name), \Type::getInstance()->createNamespace(\Type::getInstance()->createNamespace($enum->c_name)));
				$this->constants_c .= sprintf("	zend_class_entry *%s_ce = zend_register_internal_class(&tmp_%s_ce);\n", strtolower($enum->c_name), strtolower($enum->c_name));
				$this->constants_c .= sprintf("	%s_ce->ce_flags |= ZEND_ACC_FINAL;\n", strtolower($enum->c_name));

				foreach($enum->values as $value) {
					if(isset($override[$value[1]])) {
						$this->constants_c .= $override[$value[1]] . "\n";
					}
					else {
						$this->constants_c .= sprintf("	zend_declare_class_constant_long(%s_ce, \"%s\", sizeof(\"%s\") - 1, %s);\n", strtolower($enum->c_name), str_replace("-", "_", strtoupper($value[0])), str_replace("-", "_", strtoupper($value[0])), $value[1]);
					}
				}

				$this->constants_c .= "\n";
			}


		}


		return $this->constants_c;


	}
}