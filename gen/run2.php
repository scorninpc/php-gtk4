<?php

define("GEN_PATH", dirname(__FILE__));
define("SRC_PATH", dirname(__FILE__) . "/../src");

require_once(GEN_PATH . "/scheme.php");
require_once(GEN_PATH . "/Type.php");

require_once(GEN_PATH . "/genConstants.php");
require_once(GEN_PATH . "/genMerge.php");
require_once(GEN_PATH . "/genClass.php");

$ignore_list = include(GEN_PATH . "/ignore.php");
// $override_list = include(GEN_PATH . "/override.php");



// ------------------
// Constants
$genConstants = new genConstants();

$classes = [];






// ------------------
// Atk
$atk_parser = new genMerge(GEN_PATH . "/def/atk_methods.defs", GEN_PATH . "/def/atk_enums.defs");
$atk_parser->save(GEN_PATH . "/def/atk.defs");

$atk_parser = new Merge_Parser(GEN_PATH . "/def/atk.defs");
$atk_parser->start_parsing();

\Type::getInstance()->parseEnums($atk_parser);
$genConstants->addParser($atk_parser);



// ------------------
// G
$g_parser = new genMerge(GEN_PATH . "/def/gio_methods.defs", GEN_PATH . "/def/gio_enums.defs");
$g_parser->save(GEN_PATH . "/def/gio.defs");

$g_parser = new Merge_Parser(GEN_PATH . "/def/gio.defs");
$g_parser->start_parsing();

\Type::getInstance()->parseEnums($g_parser);
$genConstants->addParser($g_parser);



// ------------------
// Gtk
$gtk_parser = new genMerge(GEN_PATH . "/def/gtk_methods.defs", GEN_PATH . "/def/gtk_enums.defs");
$gtk_parser->save(GEN_PATH . "/def/gtk.defs");

$gtk_parser = new Merge_Parser(GEN_PATH . "/def/gtk.defs");
$gtk_parser->start_parsing();

\Type::getInstance()->parseEnums($gtk_parser);
$genConstants->addParser($gtk_parser);


// ------------------
// Load methods
$methods = array_merge(
	$atk_parser->constructors,
	$atk_parser->methods,
	$g_parser->constructors,
	$g_parser->methods, 
	$gtk_parser->constructors,
	$gtk_parser->methods,
	);


// ------------------
// Loop all parsed def methods
foreach($methods as $method) {

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
		$classes[$name] = new genClass($name);
	}

	// Add method to class template
	$classes[$name]->addMethod($method);
}





// ------------------
// Run all classes for parse
foreach($classes as $class) {

	if($class->getClassName() != "GtkWindow") {
		continue;
	}

	// Create .c file
	$content_c = sprintf("\n#include \"%s.h\"\n\n", $class->getClassName());
	$content_c .= $class->parse_c();
	$filename = sprintf("%s/%s/%s.c", SRC_PATH, $class->module[0], $class->getClassName());
	file_put_contents($filename, $content_c);

	// Create .h file
	$content_h = $class->parse_h();
	$filename = sprintf("%s/%s/%s.h", SRC_PATH, $class->module[0], $class->getClassName());
	file_put_contents($filename, $content_h);

}


// ------------------
// Create constants
$constants = $genConstants->parse();


// ------------------
// Load objects
$tmp_objects = array_merge(
	$gtk_parser->objects,
	$g_parser->objects, 
	$atk_parser->objects,
);
$objects = [];
foreach($tmp_objects as $object) {
	$objects[$object->c_name] = $object;
}

$init_class = "";
foreach($classes as $class) {

	

	$classname = $class->getClassName();
	if(!isset($objects[$classname])) {
		continue;
	}

	$object = $objects[$classname];
	$namespace = \Type::getInstance()->createNamespace(\Type::getInstance()->createNamespace($classname));


	if(($classname != "GApplication") && ($classname != "GtkApplication") && ($classname != "GtkWidget") && ($classname != "GtkWindow") && ($classname != "GtkApplicationWindow")) {
		continue;
	}

	$init_class .= sprintf("	zend_class_entry tmp_%s_ce;\n", strtolower($classname));
	$init_class .= sprintf("	INIT_CLASS_ENTRY(tmp_%s_ce, \"%s\", %s_functions);\n", strtolower($classname), $namespace, strtolower($classname));

	if($object->parent) {
		$init_class .= sprintf("	gtk4_%s_ce = zend_register_internal_class_ex(&tmp_%s_ce, gtk4_%s_ce);\n", strtolower($classname), strtolower($classname), strtolower($object->parent));
	}
	else {
		$init_class .= sprintf("	gtk4_%s_ce = zend_register_internal_class(&tmp_gtk_ce);\n", strtolower($classname));
	}
	$init_class .= sprintf("\n");
}

die($init_class);


var_dump($objects);
die();


// ------------------
// Create gtk4.c from template
$gtk4 = file_get_contents(GEN_PATH . "/gtk4.c.template");
$gtk4 = sprintf($gtk4, $constants);
file_put_contents(SRC_PATH . "/../gtk4.c", $gtk4);








