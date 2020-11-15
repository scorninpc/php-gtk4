#ifndef _PHPGTK_GTKBIN_H_
#define _PHPGTK_GTKBIN_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkbin_get_child, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkBin, get_child);

static zend_class_entry *gtk4_gtkbin_ce = NULL;
static const zend_function_entry gtkbin_functions[] = {
	PHP_ME(GtkBin, get_child, arginfo_gtkbin_get_child, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
