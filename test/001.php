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
	$window->set_default_size(500, 300);

	$window = $app->window_new();
	$window->set_title("Janela 2");
	$window->set_default_size(500, 300);
	
	$windows = $app->get_windows();
	$windows[0]->show_all();
	$windows[1]->show_all();

	// echo "\n -----------\n";
	// echo "inhibit\n";
	// $id = $app->inhibit($windows[0], Gtk\Application\Inhibit\Flags::SWITCH, "pq eu quero");
	// var_dump($id);

	// echo "\n -----------\n";
	// echo "is_inhibited\n";
	// var_dump($app->is_inhibited(Gtk\Application\Inhibit\Flags::SWITCH));


	// echo "\n -----------\n";
	// echo "uninhibit\n";
	// $app->uninhibit($id);

	// echo "\n -----------\n";
	// echo "is_inhibited\n";
	// var_dump($app->is_inhibited(Gtk\Application\Inhibit\Flags::SWITCH));

}

$app->connect("activate", "Test\activated");



$app->run($argc, $argv);
*/














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

echo Gtk::get_major_version() . "." . Gtk::get_minor_version() . "\n";

class Test
{
	protected $window;

	public function __construct()
	{
		$this->window = new Gtk\Window(Gtk\Window\Type::TOPLEVEL);
		$this->window->set_icon_list(["/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk3/logo.png"]);
		$this->window->connect("destroy", [$this, "callback_test"]);
		$this->window->connect("button-press-event", [$this, "callback_button_press"]);
		$this->window->connect("key-press-event", [$this, "callback_key_press"]);
		
		$this->window->set_title("TEST");

		// echo "-- Resize: \n";
		// var_dump($this->window->get_size());
		$this->window->set_default_size(1280, 720);
		// var_dump($this->window->get_size());


		// echo "-- Position: \n";
		// var_dump($this->window->get_position());
		// $this->window->move((1920/2)-(1280/2), (1080/2)-(720/2));
		// var_dump($this->window->get_position());
		$this->window->set_position(Gtk\Window\Position::CENTER);


		$display = Gdk\Display::get_default();


		$this->window->show_all();

		// var_dump($this->window->get_title());
		// $this->window->child_get_property(new Gtk\Window(Gtk\Window\Type::TOPLEVEL), "icon-name"); // TESTE THIS WHEN CREATE GTKLABEL

	}

	public function callback_button_press($widget=NULL, $event=NULL, $s=NULL)
	{
		echo "-- Button press\n";

		echo "\$widget\n";

		echo "\n\n\$event\n";
		echo $event->get_axis(Gdk\Axis\Use::X) . "x" . $event->get_axis(Gdk\Axis\Use::Y) . "\n";
		echo "Button: " . $event->get_button() . "\n";
		echo "Cliques: " . $event->get_click_count() . "\n";
		echo "Coordenadas:";
		var_dump($event->get_coords());
		var_dump($event->get_root_coords());
		echo "\n";
		// $event->get_event_type();
	}

	public function callback_key_press($widget=NULL, $event=NULL, $s=NULL)
	{
		echo "-- Key press\n";

		echo "\$widget\n";

		echo "\n\n\$event\n";
		echo "Key: " . chr($event->get_keyval()) . " (" . $event->get_keycode() . ")\n";
		echo "\n";
		// $event->get_event_type();
	}

	public function callback_test($widget=NULL, $a=NULL, $b=NULL, $c=NULL, $d=NULL)
	{
		echo "-- Destroy: OK\n";
		var_dump($widget);

		$widget->set_title("FOIIIIII \o/");

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