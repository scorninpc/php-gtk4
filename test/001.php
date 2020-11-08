<?php

namespace Test;

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

$app->run($argc, $argv);
















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


/*Gtk::init(NULL);

// Working with callbacks
function callback_test($a=NULL, $b=NULL, $c=NULL, $d=NULL, $e=NULL)
{
	// global $obj;
	
	// var_dump($obj->get_title());

	echo "\n-- param \$a\n";
	var_dump($a);

	echo "\n-- param \$b\n";
	var_dump($b);

	echo "\n-- param \$c\n";
	var_dump($c);

	echo "\n-- param \$d\n";
	var_dump($d);

	echo "\n-- param \$e\n";
	var_dump($e);

	// echo "\n-- GtkWindow->test()\n";
	// var_dump($a->test());

	Gtk::main_quit();
}

$obj = new Gtk\Window();
$obj->connect("destroy", "callback_test", "1", "2", 3, [1,2,3]);

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