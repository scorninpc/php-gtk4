<?php

\Gtk::init(NULL);


/*

// Random prop test

$obj1 = new \Gtk\Window();
var_dump($obj1->test());

sleep(1);

$obj2 = new \Gtk\Window();
var_dump($obj2->test());

var_dump($obj1->test());*/










// Working with callbacks
function callback_test($a=NULL, $b=NULL, $c=NULL, $d=NULL)
{
	echo "param \$a = " . $a . "\n";
	echo "param \$b = " . $b . "\n";
	echo "param \$c = " . $c . "\n";
	echo "param \$d = " . $d . "\n";

	\Gtk::main_quit();
}

$obj = new \Gtk\Window();
$obj->connect("destroy", "callback_test", "param a", "param b", "param c", "param d");

$obj->show_all();
\Gtk::main();

