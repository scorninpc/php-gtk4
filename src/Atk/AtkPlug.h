#ifndef _PHPGTK_atkplug_H_
#define _PHPGTK_atkplug_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../G/GObject.h"

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_atkplug___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(AtkPlug, __construct);

// -------------------
ZEND_BEGIN_ARG_INFO_EX(arginfo_atkplug_get_id, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(AtkPlug, get_id);

// -------------------
static zend_class_entry *gtk4_atkplug_ce = NULL;
static const zend_function_entry atkplug_functions[] = {
	PHP_FE_END
};

#endif