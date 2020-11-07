<?php

require_once(dirname(__FILE__) . "/scheme.php");
require_once(dirname(__FILE__) . "/Type.php");
require_once(dirname(__FILE__) . "/Templates/TClass.php");
require_once(dirname(__FILE__) . "/Templates/TMethod.php");

class Run
{

	private $classes;
	private $types;

	public function Run($defs_file)
	{
		$this->parser = new Defs_Parser($defs_file, 4.0);
		$this->parser->start_parsing();


		// foreach($this->parser->functions as $key => $function) {
		// 	// echo $key . "\n";
		// 	if(strpos($key, "gtk_widget_set_") !== FALSE) {
		// 		var_dump($function);
		// 		die();
		// 	}
		// }

		// foreach($this->parser->objects as $object) {
		// 	if($object->name == "GtkWidget") {
		// 		var_dump($object);
		// 		 echo "\\" . $object->in_module . "\\" . $object->name . "\n";
		// 	}
		// }

		// foreach($this->parser->constructors as $constructor) {
		// 	if($constructor->is_constructor_of != "GtkWindow") {
		// 		continue;
		// 	}

		// 	echo $constructor->is_constructor_of . "\n";
		// 	var_dump($constructor);
		// }

		// foreach($this->parser->methods as $method) {
		// 	echo $method->of_object . "::" . $method->name . "\n";
		// }

		// die();

		// var_dump($this->parser->enums);
		// die();

		$types = \Type::getInstance()->parseEnums($this->parser);
		

		// Loop all constructors
		foreach($this->parser->constructors as $method) {
			$object_name = $method->is_constructor_of;

			// If class not exists yet, create new template
			if(!isset($this->classes[$object_name])) {
				$this->classes[$object_name] = new \Templates\TClass();
			}

			// Add method to class template
			$this->classes[$object_name]->addMethod($method, TRUE);
		}





		// Loop all parsed def methods
		foreach($this->parser->methods as $method) {

			$object_name = $method->of_object;

			// If class not exists yet, create new template
			if(!isset($this->classes[$object_name])) {
				$this->classes[$object_name] = new \Templates\TClass();
			}

			// Add method to class template
			$this->classes[$object_name]->addMethod($method);
		}




		$module = "Gtk";

		// Loop classes for parse
		foreach($this->classes as $class) {


			if($class->getName() != "GtkApplicationWindow") {
				continue;
			}




			$class->parse();

			$dir = "/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/src/" . $module . "/";
			$header_file = $dir . $class->getName() . ".h";
			$code_file = $dir . $class->getName() . ".c";


			file_put_contents($header_file, $class->getHeaderContent());
			file_put_contents($code_file, $class->getCodeContent());
		}
			




	}



}

// new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/atk_methods.defs");
// new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gio_methods.defs");
// new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gdk.defs");

new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk_methods.defs");