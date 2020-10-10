<?php

require_once(dirname(__FILE__) . "/scheme.php");
require_once(dirname(__FILE__) . "/Templates/TClass.php");
require_once(dirname(__FILE__) . "/Templates/TMethod.php");

class Run
{

	private $classes;

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
		// 	echo $constructor->is_constructor_of . "\n";
		// 	var_dump($constructor);
		// }



		foreach($this->parser->methods as $method) {
			$object_name = $method->of_object;

			if(!isset($this->classes[$object_name])) {
				$this->classes[$object_name] = new \Templates\TClass();
			}

			// if($object_name == "GtkWindow") {
			// 	echo $method->name . "\n";
			// }

			$this->classes[$object_name]->addMethod($method);
		}



		foreach($this->classes as $class) {

			if($class->getName() == "GtkWindow") {

				$return = $class->parse();
				// var_dump($return);

			}

		}
			




	}

}

new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gtk.defs");
// new Run("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk4/gen/def/gdk.defs");