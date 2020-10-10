<?php

\Gtk::init(NULL);


$obj1 = new \Gtk\Window();
var_dump($obj1->test());

sleep(1);

$obj2 = new \Gtk\Window();
var_dump($obj2->test());

var_dump($obj1->test());









/*

// Working with callbacks
function callback_test($a=NULL, $b=NULL, $c=NULL)
{
	var_dump($a);
	var_dump($b);
	var_dump($c);

	return "VOLTAAANDO";
}

$obj = new \Gtk\Window();
var_dump($obj);
$obj->connect("test", "callback_test", "param 1", "param 2", "param 3");

\Gtk::main();

*/

