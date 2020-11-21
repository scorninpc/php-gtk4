<?php

define("GEN_PATH", dirname(__FILE__));
define("SRC_PATH", dirname(__FILE__) . "/../src");

require_once(GEN_PATH . "/scheme.php");
require_once(GEN_PATH . "/Type.php");

require_once(GEN_PATH . "/genConstants.php");
require_once(GEN_PATH . "/genMerge.php");
require_once(GEN_PATH . "/genClass.php");


$gtk_parser = new Merge_Parser(GEN_PATH . "/def/gtk_methods.defs");
$gtk_parser->start_parsing(TRUE);


foreach($gtk_parser->functions as $a) {
	// if(strrpos($a->c_name, "gtk_clip") !== FALSE) {
		echo $a->c_name . "\n";
	// }
}
echo count($gtk_parser->functions) . "\n";

foreach($gtk_parser->methods as $a) {
	if(strrpos($a->c_name, "gtk_clip") !== FALSE) {
		// echo $a->c_name . "\n";
	}
}

foreach($gtk_parser->objects as $a) {
	// if(strrpos($a->c_name, "GtkClip") !== FALSE) {
		// echo $a->c_name . "\n";
	// }
}