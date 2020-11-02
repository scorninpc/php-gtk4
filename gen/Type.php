<?php

class Type
{
	public $type;
	public $pointers;
	public $const;

	public $macro;
	
	public $is_object;

	public function __construct($type)
	{
		$this->type = $type;

		list($this->type, $this->pointers, $this->const) = $this->_normalize($type);

		if($type == "none") {
			return NULL;
		}
		else if(substr($type, 0, 3) == "Gtk") {

			$this->is_object = TRUE;
			$this->macro = "GTK_" . strtoupper(substr($type, 3));
			
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'namespace' => "Gtk",
				'class' => substr($type, 3),
				
			];

		}
		else if(substr($type, 0, 3) == "Gdk") {

			$this->is_object = TRUE;
			$this->macro = "GDK_" . strtoupper(substr($type, 3));
			
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'namespace' => "Gdk",
				'class' => substr($type, 3),
				
			];

		}
		else if(substr($type, 0, 3) == "Atk") {

			$this->is_object = TRUE;
			$this->macro = "ATK_" . strtoupper(substr($type, 3));
			
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'namespace' => "Atk",
				'class' => substr($type, 3),
				
			];

		}

		else if(substr($type, 0, 1) == "G") {



			$this->is_object = TRUE;
			$this->macro = "G_" . strtoupper(substr($type, 1));
			
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'namespace' => "G",
				'class' => substr($type, 1),
				
			];

			

		}
		else if($type == "void") {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "void"
			];
			
		}
		else if($type == "gpointer") {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "gpointer"
			];
			
		}
		else if($type == "guchar") {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "unsigned char"
			];
			
		}
		else if(($type == "guint") || ($type == "gsize") || ($type == "gulong") || ($type == "guint8") || ($type == "guint16") || ($type == "guint32") || ($type == "guint64")) {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "unsigned int"
			];
			
		}
		else if(($type == "gint") || ($type == "int") || ($type == "gssize") || ($type == "gint8") || ($type == "gint16") || ($type == "gint32") || ($type == "gint64") || ($type == "goffset")) {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "int"
			];
			
		}
		else if(($type == "double") || ($type == "gdouble") || ($type == "float") || ($type == "gfloat")) {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "float"
			];
			
		}
		else if(($type == "gchar") || ($type == "char")) {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "char"
			];
			
		}
		else if($type == "gboolean") {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "bool"
			];
			
		}
		else if(($type == "gchar-const") || ($type == "gchar-const-const")) {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => "char"
			];
		}
		else if($type == "va_list") {

			$this->is_object = FALSE;
			return [
				
				'is_va_list' => TRUE,
				'name' => $type,
				'c_type' => "va_list"
			];
		}

		else if($type == "volatile-guint32") return NULL;
		else if($type == "pid_t") return NULL;
		else if($type == "uid_t") return NULL;

		else {
			var_dump($type);
			die();


$this->is_object = FALSE;
			return [
				
				'is_va_list' => FALSE,
				'name' => $type,
				'c_type' => $type
			];
		}

		die("OK\n");
	}

	/**
	 *
	 */
	private function _normalize($type, $pointers=0) {
		if(substr($type, -1) == "*") {
			$pointers++;

			$type = substr($type, 0, strlen($type)-1);
			
			$type = $this->_normalize($type, $pointers);
		}

		if(substr($type, 0, 6) == "const-") {
			$type = substr($type, 6);
			$const = TRUE;
		}
		else {
			$const = FALSE;
		}

		return [$type, $pointers, $const];
	}
}