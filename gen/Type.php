<?php

class Type
{
	public $type;
	public $pointers;
	public $const;

	public $macro;
	
	public $is_object;

	static private $instance;
	static private $types;
	static private $enums;


	public function getInstance()
	{
		if(!self::$instance) {
			self::$instance = new self;
		}

		return self::$instance;
	}

	public function parseEnums($parser)
	{

		foreach($parser->enums as $enum) {
			$name = $enum->c_name;

			self::$enums[$name]	 = [
				'module' => $enum->in_module,
				'namespace' => $this->createNamespace($name),
			];
		}
	}

	public function getTypes()
	{
		return self::$types;
	}

	public function getEnums()
	{
		return self::$enums;
	}

	public function getType($type)
	{

		$this->type = NULL;
		$this->pointers = NULL;
		$this->const = NULL;
		$this->macro = NULL;
		$this->is_enum = NULL;
		$this->php_type = NULL;
		$this->c_type = NULL;


		if($type == NULL) {
			return $this;
		}

		// Verify if type are parsed yet
		if(isset(self::$types[$type])) {

			return [
				'type' => $type,
				'pointers' => self::$types[$type]['pointers'],
				'const' => self::$types[$type]['const'],
				'macro' => self::$types[$type]['macro'],
				'is_enum' => self::$types[$type]['is_enum'],
				'php_type' => self::$types[$type]['php_type'],
				'c_type' => self::$types[$type]['c_type'],
			];

			// $this->type = $type;
			// $this->pointers = self::$types[$type]['pointers'];
			// $this->const = self::$types[$type]['const'];
			// $this->macro = self::$types[$type]['macro'];
			// $this->is_enum = self::$types[$type]['is_enum'];
			// $this->php_type = self::$types[$type]['php_type'];
			// $this->c_type = self::$types[$type]['c_type'];

			return $this;
		}


		// Normalize the string to get pointers, if constant and clean type
		$a = $type;
		list($type, $this->pointers, $this->const) = $this->_normalize($type);

		// default values
		self::$types[$type]['name'] = $type;
		self::$types[$type]['pointers'] = $this->pointers;
		self::$types[$type]['const'] = $this->const;
		self::$types[$type]['is_enum'] = FALSE;
		self::$types[$type]['macro'] = NULL;
		self::$types[$type]['c_type'] = NULL;

		// None
		if($type == "none") {
			self::$types[$type]['name'] = NULL;
			self::$types[$type]['pointers'] = NULL;
			self::$types[$type]['const'] = NULL;
			self::$types[$type]['php_type'] = "NULL";
			
		}

		// Verify if is enum
		else if(isset(self::$enums[$type])) {
			self::$types[$type]['is_enum'] = TRUE;
			self::$types[$type]['macro'] = NULL;
			self::$types[$type]['php_type'] = "LONG";
			self::$types[$type]['c_type'] = "zend_long";
			
		}

		// Gtk objects
		else if(substr($type, 0, 3) == "Gtk") {

			self::$types[$type]['is_object'] = TRUE;
			self::$types[$type]['macro'] = $this->_createMacro($type);
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = "Gtk";
			self::$types[$type]['class'] = substr($type, 3);
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "OBJ";

		}

		// Gdk objects
		else if(substr($type, 0, 3) == "Gdk") {

			self::$types[$type]['is_object'] = TRUE;
			self::$types[$type]['macro'] = "(" . $type . "*)";
			// self::$types[$type]['macro'] = $this->_createMacro($type);
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = "Gdk";
			self::$types[$type]['class'] = substr($type, 3);
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "OBJ";
			
		}

		// Atk objects
		else if(substr($type, 0, 3) == "Atk") {

			self::$types[$type]['is_object'] = TRUE;
			self::$types[$type]['macro'] = $this->_createMacro($type);
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = "Gtk";
			self::$types[$type]['class'] = substr($type, 3);
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "OBJ";

		}

		// GList type
		else if($type == "GList") {

			self::$types[$type]['is_object'] = FALSE;
			self::$types[$type]['macro'] = NULL;
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = NULL;
			self::$types[$type]['class'] = NULL;
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "GList";

		}

		// GError
		else if($type == "GError") {

			self::$types[$type]['is_object'] = FALSE;
			self::$types[$type]['macro'] = NULL;
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = NULL;
			self::$types[$type]['class'] = NULL;
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "GError";

		}

		// G objects
		else if(substr($type, 0, 1) == "G") {

			self::$types[$type]['is_object'] = TRUE;
			self::$types[$type]['macro'] = $this->_createMacro($type);
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['namespace'] = "G";
			self::$types[$type]['class'] = substr($type, 1);
			self::$types[$type]['c_type'] = NULL;
			self::$types[$type]['php_type'] = "OBJ";

		}

		// C types
		else {

			self::$types[$type]['is_object'] = FALSE;
			self::$types[$type]['is_va_list'] = FALSE;
			self::$types[$type]['macro'] = NULL;
			self::$types[$type]['namespace'] = NULL;
			self::$types[$type]['class'] = NULL;
			
			// 
			if($type == "void") {
				self::$types[$type]['c_type'] = "void";
				self::$types[$type]['php_type'] = "NULL";
			}
			else if($type == "gpointer") {
				self::$types[$type]['c_type'] = "gpointer";
				self::$types[$type]['php_type'] = "OBJ";
			}
			else if($type == "guchar") {
				self::$types[$type]['c_type'] = "unsigned char";
				self::$types[$type]['php_type'] = "STRING";
			}
			else if(($type == "guint") || ($type == "gsize") || ($type == "gulong") || ($type == "guint8") || ($type == "guint16") || ($type == "guint32") || ($type == "guint64")) {
				self::$types[$type]['c_type'] = "long";
				self::$types[$type]['php_type'] = "LONG";
			}
			else if(($type == "gint") || ($type == "int") || ($type == "gssize") || ($type == "gint8") || ($type == "gint16") || ($type == "gint32") || ($type == "gint64") || ($type == "goffset")) {
				self::$types[$type]['c_type'] = "long";
				self::$types[$type]['php_type'] = "LONG";				
			}
			else if(($type == "double") || ($type == "gdouble") || ($type == "float") || ($type == "gfloat")) {
				self::$types[$type]['c_type'] = "float";
				self::$types[$type]['php_type'] = "DOUBLE";
			}
			else if(($type == "gchar") || ($type == "char")) {
				self::$types[$type]['c_type'] = "char";
				self::$types[$type]['php_type'] = "STRING";			
			}
			else if($type == "gboolean") {
				self::$types[$type]['c_type'] = "bool";
				self::$types[$type]['php_type'] = "BOOL";			
			}
			else if(($type == "gchar-const") || ($type == "gchar-const-const") || ($type == "gchar*-const")) {
				self::$types[$type]['c_type'] = "char";
				self::$types[$type]['php_type'] = "STRING";
			}
			else if($type == "va_list") {
				self::$types[$type]['is_va_list'] = TRUE;
				self::$types[$type]['c_type'] = "va_list";
				self::$types[$type]['php_type'] = "ARR";
			}

			else if($type == "volatile-guint32") return NULL;
			else if($type == "pid_t") return NULL;
			else if($type == "uid_t") return NULL;

			// Die for debug
			else { die("Type $type not found [Types.php line " . __line__ . "]"); }
		}

		// Call the same
		return $this->getType($type);
	}

	/**
	 *
	 */
	private function _normalize($type, $pointers=0, $const=FALSE) 
	{
		// Remove const
		if(strpos("const", $type) !== 0) {

			$const = TRUE;

			$type = str_replace("const", "", str_replace("const-", "", str_replace("-const", "", $type)));
		}

		if(substr($type, -1) == "*") {
			$pointers++;

			$type = substr($type, 0, strlen($type)-1);
			
			list($type, $pointers, $const) = $this->_normalize($type, $pointers, $const);
		}

		return [$type, $pointers, $const];
	}

	/**
	 *
	 */
	private function _createMacro($class_name)
	{

		// if($class_name == "GdkEventKey") {

		// 	$macro = "(GdkEventKey *)";

		// }
		// else {
			$pieces = preg_split('/(?=[A-Z])/', trim($class_name));
			unset($pieces[0]);

			$macro = strtoupper(implode("_", $pieces));
		// }

		return $macro;
	}

	/**
	 *
	 */
	public function createNamespace($class_name)
	{
		$pieces = preg_split('/(?=[A-Z])/', trim($class_name));
		unset($pieces[0]);

		$namespace = implode("\\", $pieces);

		return $namespace;
	}
}