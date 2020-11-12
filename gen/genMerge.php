<?php

require_once(dirname(__FILE__) . "/scheme.php");


class Merge_Parser extends Defs_Parser
{
	function handle_include($args)
	{}
}

class genMerge
{
	private $new_defs;

	public function __construct($file1, $file2)
	{
		$this->new_defs = new Merge_Parser($file1);
		$old_defs = new Merge_Parser($file2);

		$this->new_defs->start_parsing();
		$old_defs->start_parsing(TRUE);

		$this->new_defs->merge($old_defs, TRUE);
	}

	public function save($file)
	{
		$fp = fopen($file, "w");
		$this->new_defs->write_defs($fp);
		fclose($fp);
	}
}
