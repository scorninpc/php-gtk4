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

// exec("rm -rf " . GEN_PATH . "/def/*.cache");
// exec("rm -rf " . GEN_PATH . "/def/atk.defs");
// exec("rm -rf " . GEN_PATH . "/def/gio.defs");
// exec("rm -rf " . GEN_PATH . "/def/gdk.defs");
// exec("rm -rf " . GEN_PATH . "/def/gtk.defs");
$first_run = !file_exists(GEN_PATH . "/def/atk.defs");

// ------------------
// Atk
if($first_run) {
	$atk_parser = new genMerge(GEN_PATH . "/def/atk_methods.defs", GEN_PATH . "/def/atk_enums.defs");
	$atk_parser->save(GEN_PATH . "/def/atk.defs");
}

$atk_parser = new Merge_Parser(GEN_PATH . "/def/atk.defs");
$atk_parser->start_parsing();

\Type::getInstance()->parseEnums($atk_parser);
$genConstants->addParser($atk_parser);



// ------------------
// G
if($first_run) {
	$g_parser = new genMerge(GEN_PATH . "/def/gio_methods.defs", GEN_PATH . "/def/gio_enums.defs");
	$g_parser->save(GEN_PATH . "/def/gio.defs");
}

$g_parser = new Merge_Parser(GEN_PATH . "/def/gio.defs");
$g_parser->start_parsing();

\Type::getInstance()->parseEnums($g_parser);
$genConstants->addParser($g_parser);

// ------------------
// Gdk
if($first_run) {
	$gdk_parser = new genMerge(GEN_PATH . "/def/gdk_methods.defs", GEN_PATH . "/def/gdk_enums.defs");
	$gdk_parser->save(GEN_PATH . "/def/gdk.defs");
}

$gdk_parser = new Merge_Parser(GEN_PATH . "/def/gdk.defs");
$gdk_parser->start_parsing();

\Type::getInstance()->parseEnums($gdk_parser);
$genConstants->addParser($gdk_parser);



// ------------------
// Gtk
if($first_run) {
	$gtk_parser = new genMerge(GEN_PATH . "/def/gtk_methods.defs", GEN_PATH . "/def/gtk_enums.defs");
	$gtk_parser->save(GEN_PATH . "/def/gtk.defs");
}

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
	$gdk_parser->constructors,
	$gdk_parser->methods,
	$gtk_parser->constructors,
	$gtk_parser->methods,
	);


// ------------------
// Create assoc array of objects
$tmp_objects = array_merge(
	$atk_parser->objects,
	$g_parser->objects, 
	$gdk_parser->objects,
	$gtk_parser->objects,
);
$objects = [];
foreach($tmp_objects as $object) {
	$objects[$object->c_name] = $object;
}

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

	// Add o parent
	if((isset($objects[$name])) && (strlen($objects[$name]->parent) > 0)) {
		$parent = $objects[$name]->parent;
	}
	else {
		$parent = "GObject";
	}
	$classes[$name]->setParentName($parent);

	// Some GdkEvent fix
	if($method->name == "s_get_distance") $method->name = "get_distance";
	if($method->name == "s_get_center") $method->name = "get_center";
	if($method->name == "s_get_angle") $method->name = "get_angle";

	// Add method to class template
	$classes[$name]->addMethod($method);
}


// ------------------
// Parse some funcions to the object
$functions = array_merge(
	$atk_parser->functions,
	$g_parser->functions, 
	$gdk_parser->functions,
	$gtk_parser->functions,
	);

$final = [];
$count = 0;
foreach($functions as $function) {
	$final[$function->c_name] = TRUE;

	if($function->deprecated) {
		continue;
	}

	if(isset($ignore_list[$function->c_name])) {
		continue;
	}

	foreach($classes as $class) {

		$class_name = $class->getClassName();

		$pieces = preg_split('/(?=[A-Z])/', trim($class_name));
		unset($pieces[0]);
		$namespace = strtolower(implode("_", $pieces));


		if(strlen($namespace) == 0) {
			continue;
		}

		if(strpos($function->c_name, $namespace) !== FALSE) {
			$class->addMethod($function, str_replace($namespace . "_", "", $function->c_name));
			unset($final[$function->c_name]);
			$count++;
			break;
		}

	}

}


// ------------------
// Run all classes for parse
foreach($classes as $class) {

	if($class->getClassName() != "GtkClipboard") {
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
// Create class hierarchy
$new_classes = [];
$old_classes = $classes;

foreach($classes as $class) {

	$classname = $class->getClassName();
	if(
		($classname != "GApplication") && 
		($classname != "GdkEvent") && 
		($classname != "GdkDisplay") && 
		($classname != "GtkWidget") && 
		($classname != "GtkClipboard") && 
		($classname != "GtkApplication") && 
		($classname != "GtkWidget") && 
		($classname != "GtkWindow") && 
		($classname != "GtkContainer") && 
		($classname != "GtkBin") && 
		($classname != "GtkApplicationWindow")) {
		continue;		
	}

	// Look for parent index
	if(strlen($class->getParentName()) == 0) {
		$index = 0;
	}
	else if($class->getParentName() == "GObject") {
		$index = 0;
	}
	else {
		$index = 0;
		foreach($new_classes as $i => $tmp) {
			if($tmp->getParentName() == $classname) {
				$index = $i+1;
				break;
			}
		}
	}

	array_splice($new_classes, $index, 0, [$class]); 
}

$classes = array_reverse($new_classes);

// ------------------
// Output extension init class
$init_class = "";
foreach($classes as $class) {

	$classname = $class->getClassName();
	// if(!isset($objects[$classname])) {
	// 	continue;
	// }

	// $object = $objects[$classname];
	$namespace = \Type::getInstance()->createNamespace(\Type::getInstance()->createNamespace($classname));

	$init_class .= sprintf("	zend_class_entry tmp_%s_ce;\n", strtolower($classname));
	$init_class .= sprintf("	INIT_CLASS_ENTRY(tmp_%s_ce, \"%s\", %s_functions);\n", strtolower($classname), $namespace, strtolower($classname));

	if($class->getParentName()) {
		$parent = $class->getParentName();
		if($parent == "GInitiallyUnowned") {
			$parent = "GObject";
		}
		$init_class .= sprintf("	gtk4_%s_ce = zend_register_internal_class_ex(&tmp_%s_ce, gtk4_%s_ce);\n", strtolower($classname), strtolower($classname), strtolower($parent));
	}
	else {
		$init_class .= sprintf("	gtk4_%s_ce = zend_register_internal_class(&tmp_gtk_ce);\n", strtolower($classname));
	}
	$init_class .= sprintf("\n");
}

// ------------------
// Create gtk4.c from template
$gtk4 = file_get_contents(GEN_PATH . "/gtk4.c.template");
$gtk4 = sprintf($gtk4, $init_class, $constants);
file_put_contents(SRC_PATH . "/../gtk4.c", $gtk4);








