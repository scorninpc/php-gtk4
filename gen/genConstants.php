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

				// if($enum->c_name != "GApplicationFlags") {
				// 	continue;
				// }

				$this->constants_c .= sprintf("	zend_class_entry tmp_test_ce;\n");
				$this->constants_c .= sprintf("	INIT_CLASS_ENTRY(tmp_test_ce, \"%s\", NULL);\n", \Type::getInstance()->createNamespace(\Type::getInstance()->createNamespace($enum->c_name)));
				$this->constants_c .= sprintf("	zend_class_entry *c2 = zend_register_internal_class(&tmp_test_ce);\n");
				$this->constants_c .= sprintf("	c2->ce_flags |= ZEND_ACC_FINAL;\n");

				foreach($enum->values as $value) {
					if(isset($override[$value[1]])) {
						$this->constants_c .= $override[$value[1]] . "\n";
					}
					else {
						$this->constants_c .= sprintf("	zend_declare_class_constant_long(c2, \"%s\", sizeof(\"%s\") - 1, %s);\n", str_replace("-", "_", strtoupper($value[0])), str_replace("-", "_", strtoupper($value[0])), $value[1]);
					}
				}

				$this->constants_c .= "\n";
			}


		}


		return $this->constants_c;


	}
}