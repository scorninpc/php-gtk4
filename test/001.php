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
	echo "\n-- param \$a\n";
	var_dump($a);

	echo "\n-- param \$b\n";
	var_dump($b);

	echo "\n-- param \$c\n";
	var_dump($c);

	echo "\n-- param \$d\n";
	var_dump($d);


	\Gtk::main_quit();
}

$obj = new \Gtk\Window();
$obj->connect("destroy", "callback_test", "1", "2", 3, [1,2,3]);

$obj->show_all();
\Gtk::main();

