<?php


// ---------------------
/*namespace Test;

use Gtk;
use G;

$app = new Gtk\Application("testbruno.com.br", G\Application\Flags::NONE);

function activated($app=NULL, $b=NULL, $c=NULL)
{
	$window = $app->window_new();
	$window->set_title("Janela 1");

	
	$windows = $app->get_windows();
	
	$windows[0]->show_all();

	echo "\n -----------\n";
	echo "inhibit\n";
	$id = $app->inhibit($windows[0], Gtk\Application\Inhibit\Flags::SWITCH, "pq eu quero");
	var_dump($id);

	echo "\n -----------\n";
	echo "is_inhibited\n";
	var_dump($app->is_inhibited(Gtk\Application\Inhibit\Flags::SWITCH));


	echo "\n -----------\n";
	echo "uninhibit\n";
	$app->uninhibit($id);

	echo "\n -----------\n";
	echo "is_inhibited\n";
	var_dump($app->is_inhibited(Gtk\Application\Inhibit\Flags::SWITCH));

}


$app->connect("activate", "Test\activated");



$app->run($argc, $argv);*/















// ---------------------
/*class Test
{
	protected $app;

	public function __construct($argc, $argv)
	{
		$this->app = new Gtk\Application(1,1);

		$this->app->connect("activate", [$this, "activated"]);

		$this->app->run($argc, $argv);
	}

	public function activated($a=NULL, $b=NULL, $c=NULL)
	{
		echo "\n\t-- OK\n";
		$window = $this->app->window_new();
		$window->show_all();
	}
}

new Test($argc, $argv);*/





// ---------------------
Gtk::init(NULL);

class Test
{
	protected $window;

	public function __construct()
	{
		$this->window = new Gtk\Window(Gtk\Window\Type::TOPLEVEL);
		$this->window->set_icon_list(["/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk3/logo.png"]);
		$this->window->connect("destroy", [$this, "callback_test"]);
		
		echo "-- Resize: \n";
		var_dump($this->window->get_size());
		$this->window->set_default_size(1280, 720);
		var_dump($this->window->get_size());


		echo "-- Position: \n";
		var_dump($this->window->get_position());
		$this->window->move((1920/2)-(1280/2), (1080/2)-(720/2));
		var_dump($this->window->get_position());

		$this->window->show_all();

	}

	static public function callback_test($window)
	{
		echo "-- Destroy: OK\n";

		Gtk::main_quit();
	}
}


$test = new Test();

Gtk::main();


// ---------------------
/*Gtk::init(NULL);

$obj = new Gtk\Window(Gtk\Window\Type::TOPLEVEL);
$obj->connect("destroy", "callback_test");
// Working with callbacks
function callback_test($window=NULL)
{
	
	// var_dump($obj->get_title());

	// echo "\n-- param \$a\n";
	// var_dump($a);

	// echo "\n-- param \$b\n";
	// var_dump($b);

	// echo "\n-- param \$c\n";
	// var_dump($c);

	// echo "\n-- param \$d\n";
	// var_dump($d);

	// echo "\n-- param \$e\n";
	// var_dump($e);

	var_dump($window->get_position());
	// echo "\n-- GtkWindow->test()\n";
	
	Gtk::main_quit();
}

$obj->set_title("TEST GTK4");

$obj->show_all();




Gtk::main();*/


/*

// Random prop test

$obj1 = new Gtk\Window();
var_dump($obj1->test());

sleep(1);

$obj2 = new Gtk\Window();
var_dump($obj2->test());

var_dump($obj1->test());

*/