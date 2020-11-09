/* gtk4 extension for PHP (c) 2020 Bruno P. Gonçalves */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>
#include "ext/standard/info.h"
#include "php_gtk4.h"
#include "gtk4_arginfo.h"

/**
 * Php Gtk Classes
 */
#include "gtk4.h"

// ----------------
// static zend_class_entry *gtk4_exception_ce = NULL;
// static const zend_function_entry gtk4_exception_functions[] = {
// 	PHP_FE_END
// };	

/**
 * Old php versions
 */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/**
 * MINIT
 */
static PHP_MINIT_FUNCTION(gtk4)
{
	// Exception class
	zend_class_entry tmp_gtk4_exception_ce;
	INIT_CLASS_ENTRY(tmp_gtk4_exception_ce, "Gtk\\Exception", NULL);
	// gtk4_exception_ce = zend_register_internal_class_ex(&tmp_gtk4_exception_ce, zend_ce_exception);
	zend_register_internal_class_ex(&tmp_gtk4_exception_ce, zend_ce_exception);

	// Create class
	zend_class_entry tmp_gobject_ce;
	INIT_CLASS_ENTRY(tmp_gobject_ce, "G\\Object", gobject_functions);
	gtk4_gobject_ce = zend_register_internal_class(&tmp_gobject_ce);
	gtk4_gobject_ce->create_object = g_object_create_object;

	zend_class_entry tmp_gtk_ce;
	INIT_CLASS_ENTRY(tmp_gtk_ce, "Gtk", gtk_functions);
	gtk4_gtk_ce = zend_register_internal_class(&tmp_gtk_ce);

	zend_class_entry tmp_gapplication_ce;
	INIT_CLASS_ENTRY(tmp_gapplication_ce, "G\\Application", gapplication_functions);
	gtk4_gapplication_ce = zend_register_internal_class_ex(&tmp_gapplication_ce, gtk4_gobject_ce);

	zend_class_entry tmp_gtkapplication_ce;
	INIT_CLASS_ENTRY(tmp_gtkapplication_ce, "Gtk\\Application", gtkapplication_functions);
	gtk4_gtkapplication_ce = zend_register_internal_class_ex(&tmp_gtkapplication_ce, gtk4_gapplication_ce);

	zend_class_entry tmp_gtkwidget_ce;
	INIT_CLASS_ENTRY(tmp_gtkwidget_ce, "Gtk\\Widget", gtkwidget_functions);
	gtk4_gtkwidget_ce = zend_register_internal_class_ex(&tmp_gtkwidget_ce, gtk4_gobject_ce);

	zend_class_entry tmp_gtkwindow_ce;
	INIT_CLASS_ENTRY(tmp_gtkwindow_ce, "Gtk\\Window", gtkwindow_functions);
	gtk4_gtkwindow_ce = zend_register_internal_class_ex(&tmp_gtkwindow_ce, gtk4_gtkwidget_ce);

	zend_class_entry tmp_gtkapplicationwindow_ce;
	INIT_CLASS_ENTRY(tmp_gtkapplicationwindow_ce, "Gtk\\Application\\Window", gtkapplicationwindow_functions);
	gtk4_gtkapplicationwindow_ce = zend_register_internal_class_ex(&tmp_gtkapplicationwindow_ce, gtk4_gtkwindow_ce);



		zend_class_entry tmp_atkcoordtype_ce;
	INIT_CLASS_ENTRY(tmp_atkcoordtype_ce, "Atk\\Coord\\Type", NULL);
	zend_class_entry *atkcoordtype_ce = zend_register_internal_class(&tmp_atkcoordtype_ce);
	atkcoordtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkcoordtype_ce, "SCREEN", sizeof("SCREEN") - 1, ATK_XY_SCREEN);
	zend_declare_class_constant_long(atkcoordtype_ce, "WINDOW", sizeof("WINDOW") - 1, ATK_XY_WINDOW);
	zend_declare_class_constant_long(atkcoordtype_ce, "PARENT", sizeof("PARENT") - 1, ATK_XY_PARENT);

	zend_class_entry tmp_atkkeyeventtype_ce;
	INIT_CLASS_ENTRY(tmp_atkkeyeventtype_ce, "Atk\\Key\\Event\\Type", NULL);
	zend_class_entry *atkkeyeventtype_ce = zend_register_internal_class(&tmp_atkkeyeventtype_ce);
	atkkeyeventtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkkeyeventtype_ce, "PRESS", sizeof("PRESS") - 1, ATK_KEY_EVENT_PRESS);
	zend_declare_class_constant_long(atkkeyeventtype_ce, "RELEASE", sizeof("RELEASE") - 1, ATK_KEY_EVENT_RELEASE);
	zend_declare_class_constant_long(atkkeyeventtype_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_KEY_EVENT_LAST_DEFINED);

	zend_class_entry tmp_atklayer_ce;
	INIT_CLASS_ENTRY(tmp_atklayer_ce, "Atk\\Layer", NULL);
	zend_class_entry *atklayer_ce = zend_register_internal_class(&tmp_atklayer_ce);
	atklayer_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atklayer_ce, "INVALID", sizeof("INVALID") - 1, ATK_LAYER_INVALID);
	zend_declare_class_constant_long(atklayer_ce, "BACKGROUND", sizeof("BACKGROUND") - 1, ATK_LAYER_BACKGROUND);
	zend_declare_class_constant_long(atklayer_ce, "CANVAS", sizeof("CANVAS") - 1, ATK_LAYER_CANVAS);
	zend_declare_class_constant_long(atklayer_ce, "WIDGET", sizeof("WIDGET") - 1, ATK_LAYER_WIDGET);
	zend_declare_class_constant_long(atklayer_ce, "MDI", sizeof("MDI") - 1, ATK_LAYER_MDI);
	zend_declare_class_constant_long(atklayer_ce, "POPUP", sizeof("POPUP") - 1, ATK_LAYER_POPUP);
	zend_declare_class_constant_long(atklayer_ce, "OVERLAY", sizeof("OVERLAY") - 1, ATK_LAYER_OVERLAY);
	zend_declare_class_constant_long(atklayer_ce, "WINDOW", sizeof("WINDOW") - 1, ATK_LAYER_WINDOW);

	zend_class_entry tmp_atkrelationtype_ce;
	INIT_CLASS_ENTRY(tmp_atkrelationtype_ce, "Atk\\Relation\\Type", NULL);
	zend_class_entry *atkrelationtype_ce = zend_register_internal_class(&tmp_atkrelationtype_ce);
	atkrelationtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkrelationtype_ce, "NULL", sizeof("NULL") - 1, ATK_RELATION_NULL);
	zend_declare_class_constant_long(atkrelationtype_ce, "CONTROLLED_BY", sizeof("CONTROLLED_BY") - 1, ATK_RELATION_CONTROLLED_BY);
	zend_declare_class_constant_long(atkrelationtype_ce, "CONTROLLER_FOR", sizeof("CONTROLLER_FOR") - 1, ATK_RELATION_CONTROLLER_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "LABEL_FOR", sizeof("LABEL_FOR") - 1, ATK_RELATION_LABEL_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "LABELLED_BY", sizeof("LABELLED_BY") - 1, ATK_RELATION_LABELLED_BY);
	zend_declare_class_constant_long(atkrelationtype_ce, "MEMBER_OF", sizeof("MEMBER_OF") - 1, ATK_RELATION_MEMBER_OF);
	zend_declare_class_constant_long(atkrelationtype_ce, "NODE_CHILD_OF", sizeof("NODE_CHILD_OF") - 1, ATK_RELATION_NODE_CHILD_OF);
	zend_declare_class_constant_long(atkrelationtype_ce, "FLOWS_TO", sizeof("FLOWS_TO") - 1, ATK_RELATION_FLOWS_TO);
	zend_declare_class_constant_long(atkrelationtype_ce, "FLOWS_FROM", sizeof("FLOWS_FROM") - 1, ATK_RELATION_FLOWS_FROM);
	zend_declare_class_constant_long(atkrelationtype_ce, "SUBWINDOW_OF", sizeof("SUBWINDOW_OF") - 1, ATK_RELATION_SUBWINDOW_OF);
	zend_declare_class_constant_long(atkrelationtype_ce, "EMBEDS", sizeof("EMBEDS") - 1, ATK_RELATION_EMBEDS);
	zend_declare_class_constant_long(atkrelationtype_ce, "EMBEDDED_BY", sizeof("EMBEDDED_BY") - 1, ATK_RELATION_EMBEDDED_BY);
	zend_declare_class_constant_long(atkrelationtype_ce, "POPUP_FOR", sizeof("POPUP_FOR") - 1, ATK_RELATION_POPUP_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "PARENT_WINDOW_OF", sizeof("PARENT_WINDOW_OF") - 1, ATK_RELATION_PARENT_WINDOW_OF);
	zend_declare_class_constant_long(atkrelationtype_ce, "DESCRIBED_BY", sizeof("DESCRIBED_BY") - 1, ATK_RELATION_DESCRIBED_BY);
	zend_declare_class_constant_long(atkrelationtype_ce, "DESCRIPTION_FOR", sizeof("DESCRIPTION_FOR") - 1, ATK_RELATION_DESCRIPTION_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "NODE_PARENT_OF", sizeof("NODE_PARENT_OF") - 1, ATK_RELATION_NODE_PARENT_OF);
	zend_declare_class_constant_long(atkrelationtype_ce, "DETAILS", sizeof("DETAILS") - 1, ATK_RELATION_DETAILS);
	zend_declare_class_constant_long(atkrelationtype_ce, "DETAILS_FOR", sizeof("DETAILS_FOR") - 1, ATK_RELATION_DETAILS_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "ERROR_MESSAGE", sizeof("ERROR_MESSAGE") - 1, ATK_RELATION_ERROR_MESSAGE);
	zend_declare_class_constant_long(atkrelationtype_ce, "ERROR_FOR", sizeof("ERROR_FOR") - 1, ATK_RELATION_ERROR_FOR);
	zend_declare_class_constant_long(atkrelationtype_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_RELATION_LAST_DEFINED);

	zend_class_entry tmp_atkrole_ce;
	INIT_CLASS_ENTRY(tmp_atkrole_ce, "Atk\\Role", NULL);
	zend_class_entry *atkrole_ce = zend_register_internal_class(&tmp_atkrole_ce);
	atkrole_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkrole_ce, "INVALID", sizeof("INVALID") - 1, ATK_ROLE_INVALID);
	zend_declare_class_constant_long(atkrole_ce, "ACCEL_LABEL", sizeof("ACCEL_LABEL") - 1, ATK_ROLE_ACCEL_LABEL);
	zend_declare_class_constant_long(atkrole_ce, "ALERT", sizeof("ALERT") - 1, ATK_ROLE_ALERT);
	zend_declare_class_constant_long(atkrole_ce, "ANIMATION", sizeof("ANIMATION") - 1, ATK_ROLE_ANIMATION);
	zend_declare_class_constant_long(atkrole_ce, "ARROW", sizeof("ARROW") - 1, ATK_ROLE_ARROW);
	zend_declare_class_constant_long(atkrole_ce, "CALENDAR", sizeof("CALENDAR") - 1, ATK_ROLE_CALENDAR);
	zend_declare_class_constant_long(atkrole_ce, "CANVAS", sizeof("CANVAS") - 1, ATK_ROLE_CANVAS);
	zend_declare_class_constant_long(atkrole_ce, "CHECK_BOX", sizeof("CHECK_BOX") - 1, ATK_ROLE_CHECK_BOX);
	zend_declare_class_constant_long(atkrole_ce, "CHECK_MENU_ITEM", sizeof("CHECK_MENU_ITEM") - 1, ATK_ROLE_CHECK_MENU_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "COLOR_CHOOSER", sizeof("COLOR_CHOOSER") - 1, ATK_ROLE_COLOR_CHOOSER);
	zend_declare_class_constant_long(atkrole_ce, "COLUMN_HEADER", sizeof("COLUMN_HEADER") - 1, ATK_ROLE_COLUMN_HEADER);
	zend_declare_class_constant_long(atkrole_ce, "COMBO_BOX", sizeof("COMBO_BOX") - 1, ATK_ROLE_COMBO_BOX);
	zend_declare_class_constant_long(atkrole_ce, "DATE_EDITOR", sizeof("DATE_EDITOR") - 1, ATK_ROLE_DATE_EDITOR);
	zend_declare_class_constant_long(atkrole_ce, "DESKTOP_ICON", sizeof("DESKTOP_ICON") - 1, ATK_ROLE_DESKTOP_ICON);
	zend_declare_class_constant_long(atkrole_ce, "DESKTOP_FRAME", sizeof("DESKTOP_FRAME") - 1, ATK_ROLE_DESKTOP_FRAME);
	zend_declare_class_constant_long(atkrole_ce, "DIAL", sizeof("DIAL") - 1, ATK_ROLE_DIAL);
	zend_declare_class_constant_long(atkrole_ce, "DIALOG", sizeof("DIALOG") - 1, ATK_ROLE_DIALOG);
	zend_declare_class_constant_long(atkrole_ce, "DIRECTORY_PANE", sizeof("DIRECTORY_PANE") - 1, ATK_ROLE_DIRECTORY_PANE);
	zend_declare_class_constant_long(atkrole_ce, "DRAWING_AREA", sizeof("DRAWING_AREA") - 1, ATK_ROLE_DRAWING_AREA);
	zend_declare_class_constant_long(atkrole_ce, "FILE_CHOOSER", sizeof("FILE_CHOOSER") - 1, ATK_ROLE_FILE_CHOOSER);
	zend_declare_class_constant_long(atkrole_ce, "FILLER", sizeof("FILLER") - 1, ATK_ROLE_FILLER);
	zend_declare_class_constant_long(atkrole_ce, "FONT_CHOOSER", sizeof("FONT_CHOOSER") - 1, ATK_ROLE_FONT_CHOOSER);
	zend_declare_class_constant_long(atkrole_ce, "FRAME", sizeof("FRAME") - 1, ATK_ROLE_FRAME);
	zend_declare_class_constant_long(atkrole_ce, "GLASS_PANE", sizeof("GLASS_PANE") - 1, ATK_ROLE_GLASS_PANE);
	zend_declare_class_constant_long(atkrole_ce, "HTML_CONTAINER", sizeof("HTML_CONTAINER") - 1, ATK_ROLE_HTML_CONTAINER);
	zend_declare_class_constant_long(atkrole_ce, "ICON", sizeof("ICON") - 1, ATK_ROLE_ICON);
	zend_declare_class_constant_long(atkrole_ce, "IMAGE", sizeof("IMAGE") - 1, ATK_ROLE_IMAGE);
	zend_declare_class_constant_long(atkrole_ce, "INTERNAL_FRAME", sizeof("INTERNAL_FRAME") - 1, ATK_ROLE_INTERNAL_FRAME);
	zend_declare_class_constant_long(atkrole_ce, "LABEL", sizeof("LABEL") - 1, ATK_ROLE_LABEL);
	zend_declare_class_constant_long(atkrole_ce, "LAYERED_PANE", sizeof("LAYERED_PANE") - 1, ATK_ROLE_LAYERED_PANE);
	zend_declare_class_constant_long(atkrole_ce, "LIST", sizeof("LIST") - 1, ATK_ROLE_LIST);
	zend_declare_class_constant_long(atkrole_ce, "LIST_ITEM", sizeof("LIST_ITEM") - 1, ATK_ROLE_LIST_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "MENU", sizeof("MENU") - 1, ATK_ROLE_MENU);
	zend_declare_class_constant_long(atkrole_ce, "MENU_BAR", sizeof("MENU_BAR") - 1, ATK_ROLE_MENU_BAR);
	zend_declare_class_constant_long(atkrole_ce, "MENU_ITEM", sizeof("MENU_ITEM") - 1, ATK_ROLE_MENU_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "OPTION_PANE", sizeof("OPTION_PANE") - 1, ATK_ROLE_OPTION_PANE);
	zend_declare_class_constant_long(atkrole_ce, "PAGE_TAB", sizeof("PAGE_TAB") - 1, ATK_ROLE_PAGE_TAB);
	zend_declare_class_constant_long(atkrole_ce, "PAGE_TAB_LIST", sizeof("PAGE_TAB_LIST") - 1, ATK_ROLE_PAGE_TAB_LIST);
	zend_declare_class_constant_long(atkrole_ce, "PANEL", sizeof("PANEL") - 1, ATK_ROLE_PANEL);
	zend_declare_class_constant_long(atkrole_ce, "PASSWORD_TEXT", sizeof("PASSWORD_TEXT") - 1, ATK_ROLE_PASSWORD_TEXT);
	zend_declare_class_constant_long(atkrole_ce, "POPUP_MENU", sizeof("POPUP_MENU") - 1, ATK_ROLE_POPUP_MENU);
	zend_declare_class_constant_long(atkrole_ce, "PROGRESS_BAR", sizeof("PROGRESS_BAR") - 1, ATK_ROLE_PROGRESS_BAR);
	zend_declare_class_constant_long(atkrole_ce, "PUSH_BUTTON", sizeof("PUSH_BUTTON") - 1, ATK_ROLE_PUSH_BUTTON);
	zend_declare_class_constant_long(atkrole_ce, "RADIO_BUTTON", sizeof("RADIO_BUTTON") - 1, ATK_ROLE_RADIO_BUTTON);
	zend_declare_class_constant_long(atkrole_ce, "RADIO_MENU_ITEM", sizeof("RADIO_MENU_ITEM") - 1, ATK_ROLE_RADIO_MENU_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "ROOT_PANE", sizeof("ROOT_PANE") - 1, ATK_ROLE_ROOT_PANE);
	zend_declare_class_constant_long(atkrole_ce, "ROW_HEADER", sizeof("ROW_HEADER") - 1, ATK_ROLE_ROW_HEADER);
	zend_declare_class_constant_long(atkrole_ce, "SCROLL_BAR", sizeof("SCROLL_BAR") - 1, ATK_ROLE_SCROLL_BAR);
	zend_declare_class_constant_long(atkrole_ce, "SCROLL_PANE", sizeof("SCROLL_PANE") - 1, ATK_ROLE_SCROLL_PANE);
	zend_declare_class_constant_long(atkrole_ce, "SEPARATOR", sizeof("SEPARATOR") - 1, ATK_ROLE_SEPARATOR);
	zend_declare_class_constant_long(atkrole_ce, "SLIDER", sizeof("SLIDER") - 1, ATK_ROLE_SLIDER);
	zend_declare_class_constant_long(atkrole_ce, "SPLIT_PANE", sizeof("SPLIT_PANE") - 1, ATK_ROLE_SPLIT_PANE);
	zend_declare_class_constant_long(atkrole_ce, "SPIN_BUTTON", sizeof("SPIN_BUTTON") - 1, ATK_ROLE_SPIN_BUTTON);
	zend_declare_class_constant_long(atkrole_ce, "STATUSBAR", sizeof("STATUSBAR") - 1, ATK_ROLE_STATUSBAR);
	zend_declare_class_constant_long(atkrole_ce, "TABLE", sizeof("TABLE") - 1, ATK_ROLE_TABLE);
	zend_declare_class_constant_long(atkrole_ce, "TABLE_CELL", sizeof("TABLE_CELL") - 1, ATK_ROLE_TABLE_CELL);
	zend_declare_class_constant_long(atkrole_ce, "TABLE_COLUMN_HEADER", sizeof("TABLE_COLUMN_HEADER") - 1, ATK_ROLE_TABLE_COLUMN_HEADER);
	zend_declare_class_constant_long(atkrole_ce, "TABLE_ROW_HEADER", sizeof("TABLE_ROW_HEADER") - 1, ATK_ROLE_TABLE_ROW_HEADER);
	zend_declare_class_constant_long(atkrole_ce, "TEAR_OFF_MENU_ITEM", sizeof("TEAR_OFF_MENU_ITEM") - 1, ATK_ROLE_TEAR_OFF_MENU_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "TERMINAL", sizeof("TERMINAL") - 1, ATK_ROLE_TERMINAL);
	zend_declare_class_constant_long(atkrole_ce, "TEXT", sizeof("TEXT") - 1, ATK_ROLE_TEXT);
	zend_declare_class_constant_long(atkrole_ce, "TOGGLE_BUTTON", sizeof("TOGGLE_BUTTON") - 1, ATK_ROLE_TOGGLE_BUTTON);
	zend_declare_class_constant_long(atkrole_ce, "TOOL_BAR", sizeof("TOOL_BAR") - 1, ATK_ROLE_TOOL_BAR);
	zend_declare_class_constant_long(atkrole_ce, "TOOL_TIP", sizeof("TOOL_TIP") - 1, ATK_ROLE_TOOL_TIP);
	zend_declare_class_constant_long(atkrole_ce, "TREE", sizeof("TREE") - 1, ATK_ROLE_TREE);
	zend_declare_class_constant_long(atkrole_ce, "TREE_TABLE", sizeof("TREE_TABLE") - 1, ATK_ROLE_TREE_TABLE);
	zend_declare_class_constant_long(atkrole_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, ATK_ROLE_UNKNOWN);
	zend_declare_class_constant_long(atkrole_ce, "VIEWPORT", sizeof("VIEWPORT") - 1, ATK_ROLE_VIEWPORT);
	zend_declare_class_constant_long(atkrole_ce, "WINDOW", sizeof("WINDOW") - 1, ATK_ROLE_WINDOW);
	zend_declare_class_constant_long(atkrole_ce, "HEADER", sizeof("HEADER") - 1, ATK_ROLE_HEADER);
	zend_declare_class_constant_long(atkrole_ce, "FOOTER", sizeof("FOOTER") - 1, ATK_ROLE_FOOTER);
	zend_declare_class_constant_long(atkrole_ce, "PARAGRAPH", sizeof("PARAGRAPH") - 1, ATK_ROLE_PARAGRAPH);
	zend_declare_class_constant_long(atkrole_ce, "RULER", sizeof("RULER") - 1, ATK_ROLE_RULER);
	zend_declare_class_constant_long(atkrole_ce, "APPLICATION", sizeof("APPLICATION") - 1, ATK_ROLE_APPLICATION);
	zend_declare_class_constant_long(atkrole_ce, "AUTOCOMPLETE", sizeof("AUTOCOMPLETE") - 1, ATK_ROLE_AUTOCOMPLETE);
	zend_declare_class_constant_long(atkrole_ce, "EDITBAR", sizeof("EDITBAR") - 1, ATK_ROLE_EDITBAR);
	zend_declare_class_constant_long(atkrole_ce, "EMBEDDED", sizeof("EMBEDDED") - 1, ATK_ROLE_EMBEDDED);
	zend_declare_class_constant_long(atkrole_ce, "ENTRY", sizeof("ENTRY") - 1, ATK_ROLE_ENTRY);
	zend_declare_class_constant_long(atkrole_ce, "CHART", sizeof("CHART") - 1, ATK_ROLE_CHART);
	zend_declare_class_constant_long(atkrole_ce, "CAPTION", sizeof("CAPTION") - 1, ATK_ROLE_CAPTION);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_FRAME", sizeof("DOCUMENT_FRAME") - 1, ATK_ROLE_DOCUMENT_FRAME);
	zend_declare_class_constant_long(atkrole_ce, "HEADING", sizeof("HEADING") - 1, ATK_ROLE_HEADING);
	zend_declare_class_constant_long(atkrole_ce, "PAGE", sizeof("PAGE") - 1, ATK_ROLE_PAGE);
	zend_declare_class_constant_long(atkrole_ce, "SECTION", sizeof("SECTION") - 1, ATK_ROLE_SECTION);
	zend_declare_class_constant_long(atkrole_ce, "REDUNDANT_OBJECT", sizeof("REDUNDANT_OBJECT") - 1, ATK_ROLE_REDUNDANT_OBJECT);
	zend_declare_class_constant_long(atkrole_ce, "FORM", sizeof("FORM") - 1, ATK_ROLE_FORM);
	zend_declare_class_constant_long(atkrole_ce, "LINK", sizeof("LINK") - 1, ATK_ROLE_LINK);
	zend_declare_class_constant_long(atkrole_ce, "INPUT_METHOD_WINDOW", sizeof("INPUT_METHOD_WINDOW") - 1, ATK_ROLE_INPUT_METHOD_WINDOW);
	zend_declare_class_constant_long(atkrole_ce, "TABLE_ROW", sizeof("TABLE_ROW") - 1, ATK_ROLE_TABLE_ROW);
	zend_declare_class_constant_long(atkrole_ce, "TREE_ITEM", sizeof("TREE_ITEM") - 1, ATK_ROLE_TREE_ITEM);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_SPREADSHEET", sizeof("DOCUMENT_SPREADSHEET") - 1, ATK_ROLE_DOCUMENT_SPREADSHEET);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_PRESENTATION", sizeof("DOCUMENT_PRESENTATION") - 1, ATK_ROLE_DOCUMENT_PRESENTATION);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_TEXT", sizeof("DOCUMENT_TEXT") - 1, ATK_ROLE_DOCUMENT_TEXT);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_WEB", sizeof("DOCUMENT_WEB") - 1, ATK_ROLE_DOCUMENT_WEB);
	zend_declare_class_constant_long(atkrole_ce, "DOCUMENT_EMAIL", sizeof("DOCUMENT_EMAIL") - 1, ATK_ROLE_DOCUMENT_EMAIL);
	zend_declare_class_constant_long(atkrole_ce, "COMMENT", sizeof("COMMENT") - 1, ATK_ROLE_COMMENT);
	zend_declare_class_constant_long(atkrole_ce, "LIST_BOX", sizeof("LIST_BOX") - 1, ATK_ROLE_LIST_BOX);
	zend_declare_class_constant_long(atkrole_ce, "GROUPING", sizeof("GROUPING") - 1, ATK_ROLE_GROUPING);
	zend_declare_class_constant_long(atkrole_ce, "IMAGE_MAP", sizeof("IMAGE_MAP") - 1, ATK_ROLE_IMAGE_MAP);
	zend_declare_class_constant_long(atkrole_ce, "NOTIFICATION", sizeof("NOTIFICATION") - 1, ATK_ROLE_NOTIFICATION);
	zend_declare_class_constant_long(atkrole_ce, "INFO_BAR", sizeof("INFO_BAR") - 1, ATK_ROLE_INFO_BAR);
	zend_declare_class_constant_long(atkrole_ce, "LEVEL_BAR", sizeof("LEVEL_BAR") - 1, ATK_ROLE_LEVEL_BAR);
	zend_declare_class_constant_long(atkrole_ce, "TITLE_BAR", sizeof("TITLE_BAR") - 1, ATK_ROLE_TITLE_BAR);
	zend_declare_class_constant_long(atkrole_ce, "BLOCK_QUOTE", sizeof("BLOCK_QUOTE") - 1, ATK_ROLE_BLOCK_QUOTE);
	zend_declare_class_constant_long(atkrole_ce, "AUDIO", sizeof("AUDIO") - 1, ATK_ROLE_AUDIO);
	zend_declare_class_constant_long(atkrole_ce, "VIDEO", sizeof("VIDEO") - 1, ATK_ROLE_VIDEO);
	zend_declare_class_constant_long(atkrole_ce, "DEFINITION", sizeof("DEFINITION") - 1, ATK_ROLE_DEFINITION);
	zend_declare_class_constant_long(atkrole_ce, "ARTICLE", sizeof("ARTICLE") - 1, ATK_ROLE_ARTICLE);
	zend_declare_class_constant_long(atkrole_ce, "LANDMARK", sizeof("LANDMARK") - 1, ATK_ROLE_LANDMARK);
	zend_declare_class_constant_long(atkrole_ce, "LOG", sizeof("LOG") - 1, ATK_ROLE_LOG);
	zend_declare_class_constant_long(atkrole_ce, "MARQUEE", sizeof("MARQUEE") - 1, ATK_ROLE_MARQUEE);
	zend_declare_class_constant_long(atkrole_ce, "MATH", sizeof("MATH") - 1, ATK_ROLE_MATH);
	zend_declare_class_constant_long(atkrole_ce, "RATING", sizeof("RATING") - 1, ATK_ROLE_RATING);
	zend_declare_class_constant_long(atkrole_ce, "TIMER", sizeof("TIMER") - 1, ATK_ROLE_TIMER);
	zend_declare_class_constant_long(atkrole_ce, "DESCRIPTION_LIST", sizeof("DESCRIPTION_LIST") - 1, ATK_ROLE_DESCRIPTION_LIST);
	zend_declare_class_constant_long(atkrole_ce, "DESCRIPTION_TERM", sizeof("DESCRIPTION_TERM") - 1, ATK_ROLE_DESCRIPTION_TERM);
	zend_declare_class_constant_long(atkrole_ce, "DESCRIPTION_VALUE", sizeof("DESCRIPTION_VALUE") - 1, ATK_ROLE_DESCRIPTION_VALUE);
	zend_declare_class_constant_long(atkrole_ce, "STATIC", sizeof("STATIC") - 1, ATK_ROLE_STATIC);
	zend_declare_class_constant_long(atkrole_ce, "MATH_FRACTION", sizeof("MATH_FRACTION") - 1, ATK_ROLE_MATH_FRACTION);
	zend_declare_class_constant_long(atkrole_ce, "MATH_ROOT", sizeof("MATH_ROOT") - 1, ATK_ROLE_MATH_ROOT);
	zend_declare_class_constant_long(atkrole_ce, "SUBSCRIPT", sizeof("SUBSCRIPT") - 1, ATK_ROLE_SUBSCRIPT);
	zend_declare_class_constant_long(atkrole_ce, "SUPERSCRIPT", sizeof("SUPERSCRIPT") - 1, ATK_ROLE_SUPERSCRIPT);
	zend_declare_class_constant_long(atkrole_ce, "FOOTNOTE", sizeof("FOOTNOTE") - 1, ATK_ROLE_FOOTNOTE);
	zend_declare_class_constant_long(atkrole_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_ROLE_LAST_DEFINED);

	zend_class_entry tmp_atkscrolltype_ce;
	INIT_CLASS_ENTRY(tmp_atkscrolltype_ce, "Atk\\Scroll\\Type", NULL);
	zend_class_entry *atkscrolltype_ce = zend_register_internal_class(&tmp_atkscrolltype_ce);
	atkscrolltype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkscrolltype_ce, "TOP_LEFT", sizeof("TOP_LEFT") - 1, ATK_SCROLL_TOP_LEFT);
	zend_declare_class_constant_long(atkscrolltype_ce, "BOTTOM_RIGHT", sizeof("BOTTOM_RIGHT") - 1, ATK_SCROLL_BOTTOM_RIGHT);
	zend_declare_class_constant_long(atkscrolltype_ce, "TOP_EDGE", sizeof("TOP_EDGE") - 1, ATK_SCROLL_TOP_EDGE);
	zend_declare_class_constant_long(atkscrolltype_ce, "BOTTOM_EDGE", sizeof("BOTTOM_EDGE") - 1, ATK_SCROLL_BOTTOM_EDGE);
	zend_declare_class_constant_long(atkscrolltype_ce, "LEFT_EDGE", sizeof("LEFT_EDGE") - 1, ATK_SCROLL_LEFT_EDGE);
	zend_declare_class_constant_long(atkscrolltype_ce, "RIGHT_EDGE", sizeof("RIGHT_EDGE") - 1, ATK_SCROLL_RIGHT_EDGE);
	zend_declare_class_constant_long(atkscrolltype_ce, "ANYWHERE", sizeof("ANYWHERE") - 1, ATK_SCROLL_ANYWHERE);

	zend_class_entry tmp_atkstatetype_ce;
	INIT_CLASS_ENTRY(tmp_atkstatetype_ce, "Atk\\State\\Type", NULL);
	zend_class_entry *atkstatetype_ce = zend_register_internal_class(&tmp_atkstatetype_ce);
	atkstatetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkstatetype_ce, "INVALID", sizeof("INVALID") - 1, ATK_STATE_INVALID);
	zend_declare_class_constant_long(atkstatetype_ce, "ACTIVE", sizeof("ACTIVE") - 1, ATK_STATE_ACTIVE);
	zend_declare_class_constant_long(atkstatetype_ce, "ARMED", sizeof("ARMED") - 1, ATK_STATE_ARMED);
	zend_declare_class_constant_long(atkstatetype_ce, "BUSY", sizeof("BUSY") - 1, ATK_STATE_BUSY);
	zend_declare_class_constant_long(atkstatetype_ce, "CHECKED", sizeof("CHECKED") - 1, ATK_STATE_CHECKED);
	zend_declare_class_constant_long(atkstatetype_ce, "DEFUNCT", sizeof("DEFUNCT") - 1, ATK_STATE_DEFUNCT);
	zend_declare_class_constant_long(atkstatetype_ce, "EDITABLE", sizeof("EDITABLE") - 1, ATK_STATE_EDITABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "ENABLED", sizeof("ENABLED") - 1, ATK_STATE_ENABLED);
	zend_declare_class_constant_long(atkstatetype_ce, "EXPANDABLE", sizeof("EXPANDABLE") - 1, ATK_STATE_EXPANDABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "EXPANDED", sizeof("EXPANDED") - 1, ATK_STATE_EXPANDED);
	zend_declare_class_constant_long(atkstatetype_ce, "FOCUSABLE", sizeof("FOCUSABLE") - 1, ATK_STATE_FOCUSABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "FOCUSED", sizeof("FOCUSED") - 1, ATK_STATE_FOCUSED);
	zend_declare_class_constant_long(atkstatetype_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, ATK_STATE_HORIZONTAL);
	zend_declare_class_constant_long(atkstatetype_ce, "ICONIFIED", sizeof("ICONIFIED") - 1, ATK_STATE_ICONIFIED);
	zend_declare_class_constant_long(atkstatetype_ce, "MODAL", sizeof("MODAL") - 1, ATK_STATE_MODAL);
	zend_declare_class_constant_long(atkstatetype_ce, "MULTI_LINE", sizeof("MULTI_LINE") - 1, ATK_STATE_MULTI_LINE);
	zend_declare_class_constant_long(atkstatetype_ce, "MULTISELECTABLE", sizeof("MULTISELECTABLE") - 1, ATK_STATE_MULTISELECTABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "OPAQUE", sizeof("OPAQUE") - 1, ATK_STATE_OPAQUE);
	zend_declare_class_constant_long(atkstatetype_ce, "PRESSED", sizeof("PRESSED") - 1, ATK_STATE_PRESSED);
	zend_declare_class_constant_long(atkstatetype_ce, "RESIZABLE", sizeof("RESIZABLE") - 1, ATK_STATE_RESIZABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "SELECTABLE", sizeof("SELECTABLE") - 1, ATK_STATE_SELECTABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "SELECTED", sizeof("SELECTED") - 1, ATK_STATE_SELECTED);
	zend_declare_class_constant_long(atkstatetype_ce, "SENSITIVE", sizeof("SENSITIVE") - 1, ATK_STATE_SENSITIVE);
	zend_declare_class_constant_long(atkstatetype_ce, "SHOWING", sizeof("SHOWING") - 1, ATK_STATE_SHOWING);
	zend_declare_class_constant_long(atkstatetype_ce, "SINGLE_LINE", sizeof("SINGLE_LINE") - 1, ATK_STATE_SINGLE_LINE);
	zend_declare_class_constant_long(atkstatetype_ce, "STALE", sizeof("STALE") - 1, ATK_STATE_STALE);
	zend_declare_class_constant_long(atkstatetype_ce, "TRANSIENT", sizeof("TRANSIENT") - 1, ATK_STATE_TRANSIENT);
	zend_declare_class_constant_long(atkstatetype_ce, "VERTICAL", sizeof("VERTICAL") - 1, ATK_STATE_VERTICAL);
	zend_declare_class_constant_long(atkstatetype_ce, "VISIBLE", sizeof("VISIBLE") - 1, ATK_STATE_VISIBLE);
	zend_declare_class_constant_long(atkstatetype_ce, "MANAGES_DESCENDANTS", sizeof("MANAGES_DESCENDANTS") - 1, ATK_STATE_MANAGES_DESCENDANTS);
	zend_declare_class_constant_long(atkstatetype_ce, "INDETERMINATE", sizeof("INDETERMINATE") - 1, ATK_STATE_INDETERMINATE);
	zend_declare_class_constant_long(atkstatetype_ce, "TRUNCATED", sizeof("TRUNCATED") - 1, ATK_STATE_TRUNCATED);
	zend_declare_class_constant_long(atkstatetype_ce, "REQUIRED", sizeof("REQUIRED") - 1, ATK_STATE_REQUIRED);
	zend_declare_class_constant_long(atkstatetype_ce, "INVALID_ENTRY", sizeof("INVALID_ENTRY") - 1, ATK_STATE_INVALID_ENTRY);
	zend_declare_class_constant_long(atkstatetype_ce, "SUPPORTS_AUTOCOMPLETION", sizeof("SUPPORTS_AUTOCOMPLETION") - 1, ATK_STATE_SUPPORTS_AUTOCOMPLETION);
	zend_declare_class_constant_long(atkstatetype_ce, "SELECTABLE_TEXT", sizeof("SELECTABLE_TEXT") - 1, ATK_STATE_SELECTABLE_TEXT);
	zend_declare_class_constant_long(atkstatetype_ce, "DEFAULT", sizeof("DEFAULT") - 1, ATK_STATE_DEFAULT);
	zend_declare_class_constant_long(atkstatetype_ce, "ANIMATED", sizeof("ANIMATED") - 1, ATK_STATE_ANIMATED);
	zend_declare_class_constant_long(atkstatetype_ce, "VISITED", sizeof("VISITED") - 1, ATK_STATE_VISITED);
	zend_declare_class_constant_long(atkstatetype_ce, "CHECKABLE", sizeof("CHECKABLE") - 1, ATK_STATE_CHECKABLE);
	zend_declare_class_constant_long(atkstatetype_ce, "HAS_POPUP", sizeof("HAS_POPUP") - 1, ATK_STATE_HAS_POPUP);
	zend_declare_class_constant_long(atkstatetype_ce, "HAS_TOOLTIP", sizeof("HAS_TOOLTIP") - 1, ATK_STATE_HAS_TOOLTIP);
	zend_declare_class_constant_long(atkstatetype_ce, "READ_ONLY", sizeof("READ_ONLY") - 1, ATK_STATE_READ_ONLY);
	zend_declare_class_constant_long(atkstatetype_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_STATE_LAST_DEFINED);

	zend_class_entry tmp_atktextattribute_ce;
	INIT_CLASS_ENTRY(tmp_atktextattribute_ce, "Atk\\Text\\Attribute", NULL);
	zend_class_entry *atktextattribute_ce = zend_register_internal_class(&tmp_atktextattribute_ce);
	atktextattribute_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atktextattribute_ce, "INVALID", sizeof("INVALID") - 1, ATK_TEXT_ATTR_INVALID);
	zend_declare_class_constant_long(atktextattribute_ce, "LEFT_MARGIN", sizeof("LEFT_MARGIN") - 1, ATK_TEXT_ATTR_LEFT_MARGIN);
	zend_declare_class_constant_long(atktextattribute_ce, "RIGHT_MARGIN", sizeof("RIGHT_MARGIN") - 1, ATK_TEXT_ATTR_RIGHT_MARGIN);
	zend_declare_class_constant_long(atktextattribute_ce, "INDENT", sizeof("INDENT") - 1, ATK_TEXT_ATTR_INDENT);
	zend_declare_class_constant_long(atktextattribute_ce, "INVISIBLE", sizeof("INVISIBLE") - 1, ATK_TEXT_ATTR_INVISIBLE);
	zend_declare_class_constant_long(atktextattribute_ce, "EDITABLE", sizeof("EDITABLE") - 1, ATK_TEXT_ATTR_EDITABLE);
	zend_declare_class_constant_long(atktextattribute_ce, "PIXELS_ABOVE_LINES", sizeof("PIXELS_ABOVE_LINES") - 1, ATK_TEXT_ATTR_PIXELS_ABOVE_LINES);
	zend_declare_class_constant_long(atktextattribute_ce, "PIXELS_BELOW_LINES", sizeof("PIXELS_BELOW_LINES") - 1, ATK_TEXT_ATTR_PIXELS_BELOW_LINES);
	zend_declare_class_constant_long(atktextattribute_ce, "PIXELS_INSIDE_WRAP", sizeof("PIXELS_INSIDE_WRAP") - 1, ATK_TEXT_ATTR_PIXELS_INSIDE_WRAP);
	zend_declare_class_constant_long(atktextattribute_ce, "BG_FULL_HEIGHT", sizeof("BG_FULL_HEIGHT") - 1, ATK_TEXT_ATTR_BG_FULL_HEIGHT);
	zend_declare_class_constant_long(atktextattribute_ce, "RISE", sizeof("RISE") - 1, ATK_TEXT_ATTR_RISE);
	zend_declare_class_constant_long(atktextattribute_ce, "UNDERLINE", sizeof("UNDERLINE") - 1, ATK_TEXT_ATTR_UNDERLINE);
	zend_declare_class_constant_long(atktextattribute_ce, "STRIKETHROUGH", sizeof("STRIKETHROUGH") - 1, ATK_TEXT_ATTR_STRIKETHROUGH);
	zend_declare_class_constant_long(atktextattribute_ce, "SIZE", sizeof("SIZE") - 1, ATK_TEXT_ATTR_SIZE);
	zend_declare_class_constant_long(atktextattribute_ce, "SCALE", sizeof("SCALE") - 1, ATK_TEXT_ATTR_SCALE);
	zend_declare_class_constant_long(atktextattribute_ce, "WEIGHT", sizeof("WEIGHT") - 1, ATK_TEXT_ATTR_WEIGHT);
	zend_declare_class_constant_long(atktextattribute_ce, "LANGUAGE", sizeof("LANGUAGE") - 1, ATK_TEXT_ATTR_LANGUAGE);
	zend_declare_class_constant_long(atktextattribute_ce, "FAMILY_NAME", sizeof("FAMILY_NAME") - 1, ATK_TEXT_ATTR_FAMILY_NAME);
	zend_declare_class_constant_long(atktextattribute_ce, "BG_COLOR", sizeof("BG_COLOR") - 1, ATK_TEXT_ATTR_BG_COLOR);
	zend_declare_class_constant_long(atktextattribute_ce, "FG_COLOR", sizeof("FG_COLOR") - 1, ATK_TEXT_ATTR_FG_COLOR);
	zend_declare_class_constant_long(atktextattribute_ce, "BG_STIPPLE", sizeof("BG_STIPPLE") - 1, ATK_TEXT_ATTR_BG_STIPPLE);
	zend_declare_class_constant_long(atktextattribute_ce, "FG_STIPPLE", sizeof("FG_STIPPLE") - 1, ATK_TEXT_ATTR_FG_STIPPLE);
	zend_declare_class_constant_long(atktextattribute_ce, "WRAP_MODE", sizeof("WRAP_MODE") - 1, ATK_TEXT_ATTR_WRAP_MODE);
	zend_declare_class_constant_long(atktextattribute_ce, "DIRECTION", sizeof("DIRECTION") - 1, ATK_TEXT_ATTR_DIRECTION);
	zend_declare_class_constant_long(atktextattribute_ce, "JUSTIFICATION", sizeof("JUSTIFICATION") - 1, ATK_TEXT_ATTR_JUSTIFICATION);
	zend_declare_class_constant_long(atktextattribute_ce, "STRETCH", sizeof("STRETCH") - 1, ATK_TEXT_ATTR_STRETCH);
	zend_declare_class_constant_long(atktextattribute_ce, "VARIANT", sizeof("VARIANT") - 1, ATK_TEXT_ATTR_VARIANT);
	zend_declare_class_constant_long(atktextattribute_ce, "STYLE", sizeof("STYLE") - 1, ATK_TEXT_ATTR_STYLE);
	zend_declare_class_constant_long(atktextattribute_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_TEXT_ATTR_LAST_DEFINED);

	zend_class_entry tmp_atktextboundary_ce;
	INIT_CLASS_ENTRY(tmp_atktextboundary_ce, "Atk\\Text\\Boundary", NULL);
	zend_class_entry *atktextboundary_ce = zend_register_internal_class(&tmp_atktextboundary_ce);
	atktextboundary_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atktextboundary_ce, "CHAR", sizeof("CHAR") - 1, ATK_TEXT_BOUNDARY_CHAR);
	zend_declare_class_constant_long(atktextboundary_ce, "WORD_START", sizeof("WORD_START") - 1, ATK_TEXT_BOUNDARY_WORD_START);
	zend_declare_class_constant_long(atktextboundary_ce, "WORD_END", sizeof("WORD_END") - 1, ATK_TEXT_BOUNDARY_WORD_END);
	zend_declare_class_constant_long(atktextboundary_ce, "SENTENCE_START", sizeof("SENTENCE_START") - 1, ATK_TEXT_BOUNDARY_SENTENCE_START);
	zend_declare_class_constant_long(atktextboundary_ce, "SENTENCE_END", sizeof("SENTENCE_END") - 1, ATK_TEXT_BOUNDARY_SENTENCE_END);
	zend_declare_class_constant_long(atktextboundary_ce, "LINE_START", sizeof("LINE_START") - 1, ATK_TEXT_BOUNDARY_LINE_START);
	zend_declare_class_constant_long(atktextboundary_ce, "LINE_END", sizeof("LINE_END") - 1, ATK_TEXT_BOUNDARY_LINE_END);

	zend_class_entry tmp_atktextcliptype_ce;
	INIT_CLASS_ENTRY(tmp_atktextcliptype_ce, "Atk\\Text\\Clip\\Type", NULL);
	zend_class_entry *atktextcliptype_ce = zend_register_internal_class(&tmp_atktextcliptype_ce);
	atktextcliptype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atktextcliptype_ce, "NONE", sizeof("NONE") - 1, ATK_TEXT_CLIP_NONE);
	zend_declare_class_constant_long(atktextcliptype_ce, "MIN", sizeof("MIN") - 1, ATK_TEXT_CLIP_MIN);
	zend_declare_class_constant_long(atktextcliptype_ce, "MAX", sizeof("MAX") - 1, ATK_TEXT_CLIP_MAX);
	zend_declare_class_constant_long(atktextcliptype_ce, "BOTH", sizeof("BOTH") - 1, ATK_TEXT_CLIP_BOTH);

	zend_class_entry tmp_atktextgranularity_ce;
	INIT_CLASS_ENTRY(tmp_atktextgranularity_ce, "Atk\\Text\\Granularity", NULL);
	zend_class_entry *atktextgranularity_ce = zend_register_internal_class(&tmp_atktextgranularity_ce);
	atktextgranularity_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atktextgranularity_ce, "CHAR", sizeof("CHAR") - 1, ATK_TEXT_GRANULARITY_CHAR);
	zend_declare_class_constant_long(atktextgranularity_ce, "WORD", sizeof("WORD") - 1, ATK_TEXT_GRANULARITY_WORD);
	zend_declare_class_constant_long(atktextgranularity_ce, "SENTENCE", sizeof("SENTENCE") - 1, ATK_TEXT_GRANULARITY_SENTENCE);
	zend_declare_class_constant_long(atktextgranularity_ce, "LINE", sizeof("LINE") - 1, ATK_TEXT_GRANULARITY_LINE);
	zend_declare_class_constant_long(atktextgranularity_ce, "PARAGRAPH", sizeof("PARAGRAPH") - 1, ATK_TEXT_GRANULARITY_PARAGRAPH);

	zend_class_entry tmp_atkvaluetype_ce;
	INIT_CLASS_ENTRY(tmp_atkvaluetype_ce, "Atk\\Value\\Type", NULL);
	zend_class_entry *atkvaluetype_ce = zend_register_internal_class(&tmp_atkvaluetype_ce);
	atkvaluetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_WEAK", sizeof("VERY_WEAK") - 1, ATK_VALUE_VERY_WEAK);
	zend_declare_class_constant_long(atkvaluetype_ce, "WEAK", sizeof("WEAK") - 1, ATK_VALUE_WEAK);
	zend_declare_class_constant_long(atkvaluetype_ce, "ACCEPTABLE", sizeof("ACCEPTABLE") - 1, ATK_VALUE_ACCEPTABLE);
	zend_declare_class_constant_long(atkvaluetype_ce, "STRONG", sizeof("STRONG") - 1, ATK_VALUE_STRONG);
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_STRONG", sizeof("VERY_STRONG") - 1, ATK_VALUE_VERY_STRONG);
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_LOW", sizeof("VERY_LOW") - 1, ATK_VALUE_VERY_LOW);
	zend_declare_class_constant_long(atkvaluetype_ce, "LOW", sizeof("LOW") - 1, ATK_VALUE_LOW);
	zend_declare_class_constant_long(atkvaluetype_ce, "MEDIUM", sizeof("MEDIUM") - 1, ATK_VALUE_MEDIUM);
	zend_declare_class_constant_long(atkvaluetype_ce, "HIGH", sizeof("HIGH") - 1, ATK_VALUE_HIGH);
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_HIGH", sizeof("VERY_HIGH") - 1, ATK_VALUE_VERY_HIGH);
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_BAD", sizeof("VERY_BAD") - 1, ATK_VALUE_VERY_BAD);
	zend_declare_class_constant_long(atkvaluetype_ce, "BAD", sizeof("BAD") - 1, ATK_VALUE_BAD);
	zend_declare_class_constant_long(atkvaluetype_ce, "GOOD", sizeof("GOOD") - 1, ATK_VALUE_GOOD);
	zend_declare_class_constant_long(atkvaluetype_ce, "VERY_GOOD", sizeof("VERY_GOOD") - 1, ATK_VALUE_VERY_GOOD);
	zend_declare_class_constant_long(atkvaluetype_ce, "BEST", sizeof("BEST") - 1, ATK_VALUE_BEST);
	zend_declare_class_constant_long(atkvaluetype_ce, "LAST_DEFINED", sizeof("LAST_DEFINED") - 1, ATK_VALUE_LAST_DEFINED);

	zend_class_entry tmp_atkhyperlinkstateflags_ce;
	INIT_CLASS_ENTRY(tmp_atkhyperlinkstateflags_ce, "Atk\\Hyperlink\\State\\Flags", NULL);
	zend_class_entry *atkhyperlinkstateflags_ce = zend_register_internal_class(&tmp_atkhyperlinkstateflags_ce);
	atkhyperlinkstateflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(atkhyperlinkstateflags_ce, "INLINE", sizeof("INLINE") - 1, ATK_HYPERLINK_IS_INLINE);

	zend_class_entry tmp_gbustype_ce;
	INIT_CLASS_ENTRY(tmp_gbustype_ce, "G\\Bus\\Type", NULL);
	zend_class_entry *gbustype_ce = zend_register_internal_class(&tmp_gbustype_ce);
	gbustype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gbustype_ce, "STARTER", sizeof("STARTER") - 1, G_BUS_TYPE_STARTER);
	zend_declare_class_constant_long(gbustype_ce, "NONE", sizeof("NONE") - 1, G_BUS_TYPE_NONE);
	zend_declare_class_constant_long(gbustype_ce, "SYSTEM", sizeof("SYSTEM") - 1, G_BUS_TYPE_SYSTEM);
	zend_declare_class_constant_long(gbustype_ce, "SESSION", sizeof("SESSION") - 1, G_BUS_TYPE_SESSION);

	zend_class_entry tmp_gconverterresult_ce;
	INIT_CLASS_ENTRY(tmp_gconverterresult_ce, "G\\Converter\\Result", NULL);
	zend_class_entry *gconverterresult_ce = zend_register_internal_class(&tmp_gconverterresult_ce);
	gconverterresult_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gconverterresult_ce, "ERROR", sizeof("ERROR") - 1, G_CONVERTER_ERROR);
	zend_declare_class_constant_long(gconverterresult_ce, "CONVERTED", sizeof("CONVERTED") - 1, G_CONVERTER_CONVERTED);
	zend_declare_class_constant_long(gconverterresult_ce, "FINISHED", sizeof("FINISHED") - 1, G_CONVERTER_FINISHED);
	zend_declare_class_constant_long(gconverterresult_ce, "FLUSHED", sizeof("FLUSHED") - 1, G_CONVERTER_FLUSHED);

	zend_class_entry tmp_gcredentialstype_ce;
	INIT_CLASS_ENTRY(tmp_gcredentialstype_ce, "G\\Credentials\\Type", NULL);
	zend_class_entry *gcredentialstype_ce = zend_register_internal_class(&tmp_gcredentialstype_ce);
	gcredentialstype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gcredentialstype_ce, "INVALID", sizeof("INVALID") - 1, G_CREDENTIALS_TYPE_INVALID);
	zend_declare_class_constant_long(gcredentialstype_ce, "LINUX_UCRED", sizeof("LINUX_UCRED") - 1, G_CREDENTIALS_TYPE_LINUX_UCRED);
	zend_declare_class_constant_long(gcredentialstype_ce, "FREEBSD_CMSGCRED", sizeof("FREEBSD_CMSGCRED") - 1, G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED);
	zend_declare_class_constant_long(gcredentialstype_ce, "OPENBSD_SOCKPEERCRED", sizeof("OPENBSD_SOCKPEERCRED") - 1, G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED);
	zend_declare_class_constant_long(gcredentialstype_ce, "SOLARIS_UCRED", sizeof("SOLARIS_UCRED") - 1, G_CREDENTIALS_TYPE_SOLARIS_UCRED);
	zend_declare_class_constant_long(gcredentialstype_ce, "NETBSD_UNPCBID", sizeof("NETBSD_UNPCBID") - 1, G_CREDENTIALS_TYPE_NETBSD_UNPCBID);

	zend_class_entry tmp_gdatastreambyteorder_ce;
	INIT_CLASS_ENTRY(tmp_gdatastreambyteorder_ce, "G\\Data\\Stream\\Byte\\Order", NULL);
	zend_class_entry *gdatastreambyteorder_ce = zend_register_internal_class(&tmp_gdatastreambyteorder_ce);
	gdatastreambyteorder_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdatastreambyteorder_ce, "BIG_ENDIAN", sizeof("BIG_ENDIAN") - 1, G_DATA_STREAM_BYTE_ORDER_BIG_ENDIAN);
	zend_declare_class_constant_long(gdatastreambyteorder_ce, "LITTLE_ENDIAN", sizeof("LITTLE_ENDIAN") - 1, G_DATA_STREAM_BYTE_ORDER_LITTLE_ENDIAN);
	zend_declare_class_constant_long(gdatastreambyteorder_ce, "HOST_ENDIAN", sizeof("HOST_ENDIAN") - 1, G_DATA_STREAM_BYTE_ORDER_HOST_ENDIAN);

	zend_class_entry tmp_gdatastreamnewlinetype_ce;
	INIT_CLASS_ENTRY(tmp_gdatastreamnewlinetype_ce, "G\\Data\\Stream\\Newline\\Type", NULL);
	zend_class_entry *gdatastreamnewlinetype_ce = zend_register_internal_class(&tmp_gdatastreamnewlinetype_ce);
	gdatastreamnewlinetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdatastreamnewlinetype_ce, "LF", sizeof("LF") - 1, G_DATA_STREAM_NEWLINE_TYPE_LF);
	zend_declare_class_constant_long(gdatastreamnewlinetype_ce, "CR", sizeof("CR") - 1, G_DATA_STREAM_NEWLINE_TYPE_CR);
	zend_declare_class_constant_long(gdatastreamnewlinetype_ce, "CR_LF", sizeof("CR_LF") - 1, G_DATA_STREAM_NEWLINE_TYPE_CR_LF);
	zend_declare_class_constant_long(gdatastreamnewlinetype_ce, "ANY", sizeof("ANY") - 1, G_DATA_STREAM_NEWLINE_TYPE_ANY);

	zend_class_entry tmp_gdbuserror_ce;
	INIT_CLASS_ENTRY(tmp_gdbuserror_ce, "G\\D\\Bus\\Error", NULL);
	zend_class_entry *gdbuserror_ce = zend_register_internal_class(&tmp_gdbuserror_ce);
	gdbuserror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbuserror_ce, "FAILED", sizeof("FAILED") - 1, G_DBUS_ERROR_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "NO_MEMORY", sizeof("NO_MEMORY") - 1, G_DBUS_ERROR_NO_MEMORY);
	zend_declare_class_constant_long(gdbuserror_ce, "SERVICE_UNKNOWN", sizeof("SERVICE_UNKNOWN") - 1, G_DBUS_ERROR_SERVICE_UNKNOWN);
	zend_declare_class_constant_long(gdbuserror_ce, "NAME_HAS_NO_OWNER", sizeof("NAME_HAS_NO_OWNER") - 1, G_DBUS_ERROR_NAME_HAS_NO_OWNER);
	zend_declare_class_constant_long(gdbuserror_ce, "NO_REPLY", sizeof("NO_REPLY") - 1, G_DBUS_ERROR_NO_REPLY);
	zend_declare_class_constant_long(gdbuserror_ce, "IO_ERROR", sizeof("IO_ERROR") - 1, G_DBUS_ERROR_IO_ERROR);
	zend_declare_class_constant_long(gdbuserror_ce, "BAD_ADDRESS", sizeof("BAD_ADDRESS") - 1, G_DBUS_ERROR_BAD_ADDRESS);
	zend_declare_class_constant_long(gdbuserror_ce, "NOT_SUPPORTED", sizeof("NOT_SUPPORTED") - 1, G_DBUS_ERROR_NOT_SUPPORTED);
	zend_declare_class_constant_long(gdbuserror_ce, "LIMITS_EXCEEDED", sizeof("LIMITS_EXCEEDED") - 1, G_DBUS_ERROR_LIMITS_EXCEEDED);
	zend_declare_class_constant_long(gdbuserror_ce, "ACCESS_DENIED", sizeof("ACCESS_DENIED") - 1, G_DBUS_ERROR_ACCESS_DENIED);
	zend_declare_class_constant_long(gdbuserror_ce, "AUTH_FAILED", sizeof("AUTH_FAILED") - 1, G_DBUS_ERROR_AUTH_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "NO_SERVER", sizeof("NO_SERVER") - 1, G_DBUS_ERROR_NO_SERVER);
	zend_declare_class_constant_long(gdbuserror_ce, "TIMEOUT", sizeof("TIMEOUT") - 1, G_DBUS_ERROR_TIMEOUT);
	zend_declare_class_constant_long(gdbuserror_ce, "NO_NETWORK", sizeof("NO_NETWORK") - 1, G_DBUS_ERROR_NO_NETWORK);
	zend_declare_class_constant_long(gdbuserror_ce, "ADDRESS_IN_USE", sizeof("ADDRESS_IN_USE") - 1, G_DBUS_ERROR_ADDRESS_IN_USE);
	zend_declare_class_constant_long(gdbuserror_ce, "DISCONNECTED", sizeof("DISCONNECTED") - 1, G_DBUS_ERROR_DISCONNECTED);
	zend_declare_class_constant_long(gdbuserror_ce, "INVALID_ARGS", sizeof("INVALID_ARGS") - 1, G_DBUS_ERROR_INVALID_ARGS);
	zend_declare_class_constant_long(gdbuserror_ce, "FILE_NOT_FOUND", sizeof("FILE_NOT_FOUND") - 1, G_DBUS_ERROR_FILE_NOT_FOUND);
	zend_declare_class_constant_long(gdbuserror_ce, "FILE_EXISTS", sizeof("FILE_EXISTS") - 1, G_DBUS_ERROR_FILE_EXISTS);
	zend_declare_class_constant_long(gdbuserror_ce, "UNKNOWN_METHOD", sizeof("UNKNOWN_METHOD") - 1, G_DBUS_ERROR_UNKNOWN_METHOD);
	zend_declare_class_constant_long(gdbuserror_ce, "TIMED_OUT", sizeof("TIMED_OUT") - 1, G_DBUS_ERROR_TIMED_OUT);
	zend_declare_class_constant_long(gdbuserror_ce, "MATCH_RULE_NOT_FOUND", sizeof("MATCH_RULE_NOT_FOUND") - 1, G_DBUS_ERROR_MATCH_RULE_NOT_FOUND);
	zend_declare_class_constant_long(gdbuserror_ce, "MATCH_RULE_INVALID", sizeof("MATCH_RULE_INVALID") - 1, G_DBUS_ERROR_MATCH_RULE_INVALID);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_EXEC_FAILED", sizeof("SPAWN_EXEC_FAILED") - 1, G_DBUS_ERROR_SPAWN_EXEC_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_FORK_FAILED", sizeof("SPAWN_FORK_FAILED") - 1, G_DBUS_ERROR_SPAWN_FORK_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_CHILD_EXITED", sizeof("SPAWN_CHILD_EXITED") - 1, G_DBUS_ERROR_SPAWN_CHILD_EXITED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_CHILD_SIGNALED", sizeof("SPAWN_CHILD_SIGNALED") - 1, G_DBUS_ERROR_SPAWN_CHILD_SIGNALED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_FAILED", sizeof("SPAWN_FAILED") - 1, G_DBUS_ERROR_SPAWN_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_SETUP_FAILED", sizeof("SPAWN_SETUP_FAILED") - 1, G_DBUS_ERROR_SPAWN_SETUP_FAILED);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_CONFIG_INVALID", sizeof("SPAWN_CONFIG_INVALID") - 1, G_DBUS_ERROR_SPAWN_CONFIG_INVALID);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_SERVICE_INVALID", sizeof("SPAWN_SERVICE_INVALID") - 1, G_DBUS_ERROR_SPAWN_SERVICE_INVALID);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_SERVICE_NOT_FOUND", sizeof("SPAWN_SERVICE_NOT_FOUND") - 1, G_DBUS_ERROR_SPAWN_SERVICE_NOT_FOUND);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_PERMISSIONS_INVALID", sizeof("SPAWN_PERMISSIONS_INVALID") - 1, G_DBUS_ERROR_SPAWN_PERMISSIONS_INVALID);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_FILE_INVALID", sizeof("SPAWN_FILE_INVALID") - 1, G_DBUS_ERROR_SPAWN_FILE_INVALID);
	zend_declare_class_constant_long(gdbuserror_ce, "SPAWN_NO_MEMORY", sizeof("SPAWN_NO_MEMORY") - 1, G_DBUS_ERROR_SPAWN_NO_MEMORY);
	zend_declare_class_constant_long(gdbuserror_ce, "UNIX_PROCESS_ID_UNKNOWN", sizeof("UNIX_PROCESS_ID_UNKNOWN") - 1, G_DBUS_ERROR_UNIX_PROCESS_ID_UNKNOWN);
	zend_declare_class_constant_long(gdbuserror_ce, "INVALID_SIGNATURE", sizeof("INVALID_SIGNATURE") - 1, G_DBUS_ERROR_INVALID_SIGNATURE);
	zend_declare_class_constant_long(gdbuserror_ce, "INVALID_FILE_CONTENT", sizeof("INVALID_FILE_CONTENT") - 1, G_DBUS_ERROR_INVALID_FILE_CONTENT);
	zend_declare_class_constant_long(gdbuserror_ce, "SELINUX_SECURITY_CONTEXT_UNKNOWN", sizeof("SELINUX_SECURITY_CONTEXT_UNKNOWN") - 1, G_DBUS_ERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN);
	zend_declare_class_constant_long(gdbuserror_ce, "ADT_AUDIT_DATA_UNKNOWN", sizeof("ADT_AUDIT_DATA_UNKNOWN") - 1, G_DBUS_ERROR_ADT_AUDIT_DATA_UNKNOWN);
	zend_declare_class_constant_long(gdbuserror_ce, "OBJECT_PATH_IN_USE", sizeof("OBJECT_PATH_IN_USE") - 1, G_DBUS_ERROR_OBJECT_PATH_IN_USE);
	zend_declare_class_constant_long(gdbuserror_ce, "UNKNOWN_OBJECT", sizeof("UNKNOWN_OBJECT") - 1, G_DBUS_ERROR_UNKNOWN_OBJECT);
	zend_declare_class_constant_long(gdbuserror_ce, "UNKNOWN_INTERFACE", sizeof("UNKNOWN_INTERFACE") - 1, G_DBUS_ERROR_UNKNOWN_INTERFACE);
	zend_declare_class_constant_long(gdbuserror_ce, "UNKNOWN_PROPERTY", sizeof("UNKNOWN_PROPERTY") - 1, G_DBUS_ERROR_UNKNOWN_PROPERTY);
	zend_declare_class_constant_long(gdbuserror_ce, "PROPERTY_READ_ONLY", sizeof("PROPERTY_READ_ONLY") - 1, G_DBUS_ERROR_PROPERTY_READ_ONLY);

	zend_class_entry tmp_gdbusmessagebyteorder_ce;
	INIT_CLASS_ENTRY(tmp_gdbusmessagebyteorder_ce, "G\\D\\Bus\\Message\\Byte\\Order", NULL);
	zend_class_entry *gdbusmessagebyteorder_ce = zend_register_internal_class(&tmp_gdbusmessagebyteorder_ce);
	gdbusmessagebyteorder_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusmessagebyteorder_ce, "BIG_ENDIAN", sizeof("BIG_ENDIAN") - 1, G_DBUS_MESSAGE_BYTE_ORDER_BIG_ENDIAN);
	zend_declare_class_constant_long(gdbusmessagebyteorder_ce, "LITTLE_ENDIAN", sizeof("LITTLE_ENDIAN") - 1, G_DBUS_MESSAGE_BYTE_ORDER_LITTLE_ENDIAN);

	zend_class_entry tmp_gdbusmessageheaderfield_ce;
	INIT_CLASS_ENTRY(tmp_gdbusmessageheaderfield_ce, "G\\D\\Bus\\Message\\Header\\Field", NULL);
	zend_class_entry *gdbusmessageheaderfield_ce = zend_register_internal_class(&tmp_gdbusmessageheaderfield_ce);
	gdbusmessageheaderfield_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "INVALID", sizeof("INVALID") - 1, G_DBUS_MESSAGE_HEADER_FIELD_INVALID);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "PATH", sizeof("PATH") - 1, G_DBUS_MESSAGE_HEADER_FIELD_PATH);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "INTERFACE", sizeof("INTERFACE") - 1, G_DBUS_MESSAGE_HEADER_FIELD_INTERFACE);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "MEMBER", sizeof("MEMBER") - 1, G_DBUS_MESSAGE_HEADER_FIELD_MEMBER);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "ERROR_NAME", sizeof("ERROR_NAME") - 1, G_DBUS_MESSAGE_HEADER_FIELD_ERROR_NAME);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "REPLY_SERIAL", sizeof("REPLY_SERIAL") - 1, G_DBUS_MESSAGE_HEADER_FIELD_REPLY_SERIAL);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "DESTINATION", sizeof("DESTINATION") - 1, G_DBUS_MESSAGE_HEADER_FIELD_DESTINATION);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "SENDER", sizeof("SENDER") - 1, G_DBUS_MESSAGE_HEADER_FIELD_SENDER);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "SIGNATURE", sizeof("SIGNATURE") - 1, G_DBUS_MESSAGE_HEADER_FIELD_SIGNATURE);
	zend_declare_class_constant_long(gdbusmessageheaderfield_ce, "NUM_UNIX_FDS", sizeof("NUM_UNIX_FDS") - 1, G_DBUS_MESSAGE_HEADER_FIELD_NUM_UNIX_FDS);

	zend_class_entry tmp_gdbusmessagetype_ce;
	INIT_CLASS_ENTRY(tmp_gdbusmessagetype_ce, "G\\D\\Bus\\Message\\Type", NULL);
	zend_class_entry *gdbusmessagetype_ce = zend_register_internal_class(&tmp_gdbusmessagetype_ce);
	gdbusmessagetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusmessagetype_ce, "INVALID", sizeof("INVALID") - 1, G_DBUS_MESSAGE_TYPE_INVALID);
	zend_declare_class_constant_long(gdbusmessagetype_ce, "METHOD_CALL", sizeof("METHOD_CALL") - 1, G_DBUS_MESSAGE_TYPE_METHOD_CALL);
	zend_declare_class_constant_long(gdbusmessagetype_ce, "METHOD_RETURN", sizeof("METHOD_RETURN") - 1, G_DBUS_MESSAGE_TYPE_METHOD_RETURN);
	zend_declare_class_constant_long(gdbusmessagetype_ce, "ERROR", sizeof("ERROR") - 1, G_DBUS_MESSAGE_TYPE_ERROR);
	zend_declare_class_constant_long(gdbusmessagetype_ce, "SIGNAL", sizeof("SIGNAL") - 1, G_DBUS_MESSAGE_TYPE_SIGNAL);

	zend_class_entry tmp_gdrivestartflags_ce;
	INIT_CLASS_ENTRY(tmp_gdrivestartflags_ce, "G\\Drive\\Start\\Flags", NULL);
	zend_class_entry *gdrivestartflags_ce = zend_register_internal_class(&tmp_gdrivestartflags_ce);
	gdrivestartflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdrivestartflags_ce, "NONE", sizeof("NONE") - 1, G_DRIVE_START_NONE);

	zend_class_entry tmp_gdrivestartstoptype_ce;
	INIT_CLASS_ENTRY(tmp_gdrivestartstoptype_ce, "G\\Drive\\Start\\Stop\\Type", NULL);
	zend_class_entry *gdrivestartstoptype_ce = zend_register_internal_class(&tmp_gdrivestartstoptype_ce);
	gdrivestartstoptype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdrivestartstoptype_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, G_DRIVE_START_STOP_TYPE_UNKNOWN);
	zend_declare_class_constant_long(gdrivestartstoptype_ce, "SHUTDOWN", sizeof("SHUTDOWN") - 1, G_DRIVE_START_STOP_TYPE_SHUTDOWN);
	zend_declare_class_constant_long(gdrivestartstoptype_ce, "NETWORK", sizeof("NETWORK") - 1, G_DRIVE_START_STOP_TYPE_NETWORK);
	zend_declare_class_constant_long(gdrivestartstoptype_ce, "MULTIDISK", sizeof("MULTIDISK") - 1, G_DRIVE_START_STOP_TYPE_MULTIDISK);
	zend_declare_class_constant_long(gdrivestartstoptype_ce, "PASSWORD", sizeof("PASSWORD") - 1, G_DRIVE_START_STOP_TYPE_PASSWORD);

	zend_class_entry tmp_gemblemorigin_ce;
	INIT_CLASS_ENTRY(tmp_gemblemorigin_ce, "G\\Emblem\\Origin", NULL);
	zend_class_entry *gemblemorigin_ce = zend_register_internal_class(&tmp_gemblemorigin_ce);
	gemblemorigin_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gemblemorigin_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, G_EMBLEM_ORIGIN_UNKNOWN);
	zend_declare_class_constant_long(gemblemorigin_ce, "DEVICE", sizeof("DEVICE") - 1, G_EMBLEM_ORIGIN_DEVICE);
	zend_declare_class_constant_long(gemblemorigin_ce, "LIVEMETADATA", sizeof("LIVEMETADATA") - 1, G_EMBLEM_ORIGIN_LIVEMETADATA);
	zend_declare_class_constant_long(gemblemorigin_ce, "TAG", sizeof("TAG") - 1, G_EMBLEM_ORIGIN_TAG);

	zend_class_entry tmp_gfileattributestatus_ce;
	INIT_CLASS_ENTRY(tmp_gfileattributestatus_ce, "G\\File\\Attribute\\Status", NULL);
	zend_class_entry *gfileattributestatus_ce = zend_register_internal_class(&tmp_gfileattributestatus_ce);
	gfileattributestatus_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfileattributestatus_ce, "UNSET", sizeof("UNSET") - 1, G_FILE_ATTRIBUTE_STATUS_UNSET);
	zend_declare_class_constant_long(gfileattributestatus_ce, "SET", sizeof("SET") - 1, G_FILE_ATTRIBUTE_STATUS_SET);
	zend_declare_class_constant_long(gfileattributestatus_ce, "ERROR_SETTING", sizeof("ERROR_SETTING") - 1, G_FILE_ATTRIBUTE_STATUS_ERROR_SETTING);

	zend_class_entry tmp_gfileattributetype_ce;
	INIT_CLASS_ENTRY(tmp_gfileattributetype_ce, "G\\File\\Attribute\\Type", NULL);
	zend_class_entry *gfileattributetype_ce = zend_register_internal_class(&tmp_gfileattributetype_ce);
	gfileattributetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfileattributetype_ce, "INVALID", sizeof("INVALID") - 1, G_FILE_ATTRIBUTE_TYPE_INVALID);
	zend_declare_class_constant_long(gfileattributetype_ce, "STRING", sizeof("STRING") - 1, G_FILE_ATTRIBUTE_TYPE_STRING);
	zend_declare_class_constant_long(gfileattributetype_ce, "BYTE_STRING", sizeof("BYTE_STRING") - 1, G_FILE_ATTRIBUTE_TYPE_BYTE_STRING);
	zend_declare_class_constant_long(gfileattributetype_ce, "BOOLEAN", sizeof("BOOLEAN") - 1, G_FILE_ATTRIBUTE_TYPE_BOOLEAN);
	zend_declare_class_constant_long(gfileattributetype_ce, "UINT32", sizeof("UINT32") - 1, G_FILE_ATTRIBUTE_TYPE_UINT32);
	zend_declare_class_constant_long(gfileattributetype_ce, "INT32", sizeof("INT32") - 1, G_FILE_ATTRIBUTE_TYPE_INT32);
	zend_declare_class_constant_long(gfileattributetype_ce, "UINT64", sizeof("UINT64") - 1, G_FILE_ATTRIBUTE_TYPE_UINT64);
	zend_declare_class_constant_long(gfileattributetype_ce, "INT64", sizeof("INT64") - 1, G_FILE_ATTRIBUTE_TYPE_INT64);
	zend_declare_class_constant_long(gfileattributetype_ce, "OBJECT", sizeof("OBJECT") - 1, G_FILE_ATTRIBUTE_TYPE_OBJECT);
	zend_declare_class_constant_long(gfileattributetype_ce, "STRINGV", sizeof("STRINGV") - 1, G_FILE_ATTRIBUTE_TYPE_STRINGV);

	zend_class_entry tmp_gfilemonitorevent_ce;
	INIT_CLASS_ENTRY(tmp_gfilemonitorevent_ce, "G\\File\\Monitor\\Event", NULL);
	zend_class_entry *gfilemonitorevent_ce = zend_register_internal_class(&tmp_gfilemonitorevent_ce);
	gfilemonitorevent_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilemonitorevent_ce, "CHANGED", sizeof("CHANGED") - 1, G_FILE_MONITOR_EVENT_CHANGED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "CHANGES_DONE_HINT", sizeof("CHANGES_DONE_HINT") - 1, G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "DELETED", sizeof("DELETED") - 1, G_FILE_MONITOR_EVENT_DELETED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "CREATED", sizeof("CREATED") - 1, G_FILE_MONITOR_EVENT_CREATED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "ATTRIBUTE_CHANGED", sizeof("ATTRIBUTE_CHANGED") - 1, G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "PRE_UNMOUNT", sizeof("PRE_UNMOUNT") - 1, G_FILE_MONITOR_EVENT_PRE_UNMOUNT);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "UNMOUNTED", sizeof("UNMOUNTED") - 1, G_FILE_MONITOR_EVENT_UNMOUNTED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "MOVED", sizeof("MOVED") - 1, G_FILE_MONITOR_EVENT_MOVED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "RENAMED", sizeof("RENAMED") - 1, G_FILE_MONITOR_EVENT_RENAMED);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "MOVED_IN", sizeof("MOVED_IN") - 1, G_FILE_MONITOR_EVENT_MOVED_IN);
	zend_declare_class_constant_long(gfilemonitorevent_ce, "MOVED_OUT", sizeof("MOVED_OUT") - 1, G_FILE_MONITOR_EVENT_MOVED_OUT);

	zend_class_entry tmp_gfilesystempreviewtype_ce;
	INIT_CLASS_ENTRY(tmp_gfilesystempreviewtype_ce, "G\\Filesystem\\Preview\\Type", NULL);
	zend_class_entry *gfilesystempreviewtype_ce = zend_register_internal_class(&tmp_gfilesystempreviewtype_ce);
	gfilesystempreviewtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilesystempreviewtype_ce, "IF_ALWAYS", sizeof("IF_ALWAYS") - 1, G_FILESYSTEM_PREVIEW_TYPE_IF_ALWAYS);
	zend_declare_class_constant_long(gfilesystempreviewtype_ce, "IF_LOCAL", sizeof("IF_LOCAL") - 1, G_FILESYSTEM_PREVIEW_TYPE_IF_LOCAL);
	zend_declare_class_constant_long(gfilesystempreviewtype_ce, "NEVER", sizeof("NEVER") - 1, G_FILESYSTEM_PREVIEW_TYPE_NEVER);

	zend_class_entry tmp_gfiletype_ce;
	INIT_CLASS_ENTRY(tmp_gfiletype_ce, "G\\File\\Type", NULL);
	zend_class_entry *gfiletype_ce = zend_register_internal_class(&tmp_gfiletype_ce);
	gfiletype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfiletype_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, G_FILE_TYPE_UNKNOWN);
	zend_declare_class_constant_long(gfiletype_ce, "REGULAR", sizeof("REGULAR") - 1, G_FILE_TYPE_REGULAR);
	zend_declare_class_constant_long(gfiletype_ce, "DIRECTORY", sizeof("DIRECTORY") - 1, G_FILE_TYPE_DIRECTORY);
	zend_declare_class_constant_long(gfiletype_ce, "SYMBOLIC_LINK", sizeof("SYMBOLIC_LINK") - 1, G_FILE_TYPE_SYMBOLIC_LINK);
	zend_declare_class_constant_long(gfiletype_ce, "SPECIAL", sizeof("SPECIAL") - 1, G_FILE_TYPE_SPECIAL);
	zend_declare_class_constant_long(gfiletype_ce, "SHORTCUT", sizeof("SHORTCUT") - 1, G_FILE_TYPE_SHORTCUT);
	zend_declare_class_constant_long(gfiletype_ce, "MOUNTABLE", sizeof("MOUNTABLE") - 1, G_FILE_TYPE_MOUNTABLE);

	zend_class_entry tmp_gioerrorenum_ce;
	INIT_CLASS_ENTRY(tmp_gioerrorenum_ce, "G\\I\\O\\Error\\Enum", NULL);
	zend_class_entry *gioerrorenum_ce = zend_register_internal_class(&tmp_gioerrorenum_ce);
	gioerrorenum_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gioerrorenum_ce, "FAILED", sizeof("FAILED") - 1, G_IO_ERROR_FAILED);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, G_IO_ERROR_NOT_FOUND);
	zend_declare_class_constant_long(gioerrorenum_ce, "EXISTS", sizeof("EXISTS") - 1, G_IO_ERROR_EXISTS);
	zend_declare_class_constant_long(gioerrorenum_ce, "IS_DIRECTORY", sizeof("IS_DIRECTORY") - 1, G_IO_ERROR_IS_DIRECTORY);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_DIRECTORY", sizeof("NOT_DIRECTORY") - 1, G_IO_ERROR_NOT_DIRECTORY);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_EMPTY", sizeof("NOT_EMPTY") - 1, G_IO_ERROR_NOT_EMPTY);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_REGULAR_FILE", sizeof("NOT_REGULAR_FILE") - 1, G_IO_ERROR_NOT_REGULAR_FILE);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_SYMBOLIC_LINK", sizeof("NOT_SYMBOLIC_LINK") - 1, G_IO_ERROR_NOT_SYMBOLIC_LINK);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_MOUNTABLE_FILE", sizeof("NOT_MOUNTABLE_FILE") - 1, G_IO_ERROR_NOT_MOUNTABLE_FILE);
	zend_declare_class_constant_long(gioerrorenum_ce, "FILENAME_TOO_LONG", sizeof("FILENAME_TOO_LONG") - 1, G_IO_ERROR_FILENAME_TOO_LONG);
	zend_declare_class_constant_long(gioerrorenum_ce, "INVALID_FILENAME", sizeof("INVALID_FILENAME") - 1, G_IO_ERROR_INVALID_FILENAME);
	zend_declare_class_constant_long(gioerrorenum_ce, "TOO_MANY_LINKS", sizeof("TOO_MANY_LINKS") - 1, G_IO_ERROR_TOO_MANY_LINKS);
	zend_declare_class_constant_long(gioerrorenum_ce, "NO_SPACE", sizeof("NO_SPACE") - 1, G_IO_ERROR_NO_SPACE);
	zend_declare_class_constant_long(gioerrorenum_ce, "INVALID_ARGUMENT", sizeof("INVALID_ARGUMENT") - 1, G_IO_ERROR_INVALID_ARGUMENT);
	zend_declare_class_constant_long(gioerrorenum_ce, "PERMISSION_DENIED", sizeof("PERMISSION_DENIED") - 1, G_IO_ERROR_PERMISSION_DENIED);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_SUPPORTED", sizeof("NOT_SUPPORTED") - 1, G_IO_ERROR_NOT_SUPPORTED);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_MOUNTED", sizeof("NOT_MOUNTED") - 1, G_IO_ERROR_NOT_MOUNTED);
	zend_declare_class_constant_long(gioerrorenum_ce, "ALREADY_MOUNTED", sizeof("ALREADY_MOUNTED") - 1, G_IO_ERROR_ALREADY_MOUNTED);
	zend_declare_class_constant_long(gioerrorenum_ce, "CLOSED", sizeof("CLOSED") - 1, G_IO_ERROR_CLOSED);
	zend_declare_class_constant_long(gioerrorenum_ce, "CANCELLED", sizeof("CANCELLED") - 1, G_IO_ERROR_CANCELLED);
	zend_declare_class_constant_long(gioerrorenum_ce, "PENDING", sizeof("PENDING") - 1, G_IO_ERROR_PENDING);
	zend_declare_class_constant_long(gioerrorenum_ce, "READ_ONLY", sizeof("READ_ONLY") - 1, G_IO_ERROR_READ_ONLY);
	zend_declare_class_constant_long(gioerrorenum_ce, "CANT_CREATE_BACKUP", sizeof("CANT_CREATE_BACKUP") - 1, G_IO_ERROR_CANT_CREATE_BACKUP);
	zend_declare_class_constant_long(gioerrorenum_ce, "WRONG_ETAG", sizeof("WRONG_ETAG") - 1, G_IO_ERROR_WRONG_ETAG);
	zend_declare_class_constant_long(gioerrorenum_ce, "TIMED_OUT", sizeof("TIMED_OUT") - 1, G_IO_ERROR_TIMED_OUT);
	zend_declare_class_constant_long(gioerrorenum_ce, "WOULD_RECURSE", sizeof("WOULD_RECURSE") - 1, G_IO_ERROR_WOULD_RECURSE);
	zend_declare_class_constant_long(gioerrorenum_ce, "BUSY", sizeof("BUSY") - 1, G_IO_ERROR_BUSY);
	zend_declare_class_constant_long(gioerrorenum_ce, "WOULD_BLOCK", sizeof("WOULD_BLOCK") - 1, G_IO_ERROR_WOULD_BLOCK);
	zend_declare_class_constant_long(gioerrorenum_ce, "HOST_NOT_FOUND", sizeof("HOST_NOT_FOUND") - 1, G_IO_ERROR_HOST_NOT_FOUND);
	zend_declare_class_constant_long(gioerrorenum_ce, "WOULD_MERGE", sizeof("WOULD_MERGE") - 1, G_IO_ERROR_WOULD_MERGE);
	zend_declare_class_constant_long(gioerrorenum_ce, "FAILED_HANDLED", sizeof("FAILED_HANDLED") - 1, G_IO_ERROR_FAILED_HANDLED);
	zend_declare_class_constant_long(gioerrorenum_ce, "TOO_MANY_OPEN_FILES", sizeof("TOO_MANY_OPEN_FILES") - 1, G_IO_ERROR_TOO_MANY_OPEN_FILES);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_INITIALIZED", sizeof("NOT_INITIALIZED") - 1, G_IO_ERROR_NOT_INITIALIZED);
	zend_declare_class_constant_long(gioerrorenum_ce, "ADDRESS_IN_USE", sizeof("ADDRESS_IN_USE") - 1, G_IO_ERROR_ADDRESS_IN_USE);
	zend_declare_class_constant_long(gioerrorenum_ce, "PARTIAL_INPUT", sizeof("PARTIAL_INPUT") - 1, G_IO_ERROR_PARTIAL_INPUT);
	zend_declare_class_constant_long(gioerrorenum_ce, "INVALID_DATA", sizeof("INVALID_DATA") - 1, G_IO_ERROR_INVALID_DATA);
	zend_declare_class_constant_long(gioerrorenum_ce, "DBUS_ERROR", sizeof("DBUS_ERROR") - 1, G_IO_ERROR_DBUS_ERROR);
	zend_declare_class_constant_long(gioerrorenum_ce, "HOST_UNREACHABLE", sizeof("HOST_UNREACHABLE") - 1, G_IO_ERROR_HOST_UNREACHABLE);
	zend_declare_class_constant_long(gioerrorenum_ce, "NETWORK_UNREACHABLE", sizeof("NETWORK_UNREACHABLE") - 1, G_IO_ERROR_NETWORK_UNREACHABLE);
	zend_declare_class_constant_long(gioerrorenum_ce, "CONNECTION_REFUSED", sizeof("CONNECTION_REFUSED") - 1, G_IO_ERROR_CONNECTION_REFUSED);
	zend_declare_class_constant_long(gioerrorenum_ce, "PROXY_FAILED", sizeof("PROXY_FAILED") - 1, G_IO_ERROR_PROXY_FAILED);
	zend_declare_class_constant_long(gioerrorenum_ce, "PROXY_AUTH_FAILED", sizeof("PROXY_AUTH_FAILED") - 1, G_IO_ERROR_PROXY_AUTH_FAILED);
	zend_declare_class_constant_long(gioerrorenum_ce, "PROXY_NEED_AUTH", sizeof("PROXY_NEED_AUTH") - 1, G_IO_ERROR_PROXY_NEED_AUTH);
	zend_declare_class_constant_long(gioerrorenum_ce, "PROXY_NOT_ALLOWED", sizeof("PROXY_NOT_ALLOWED") - 1, G_IO_ERROR_PROXY_NOT_ALLOWED);
	zend_declare_class_constant_long(gioerrorenum_ce, "BROKEN_PIPE", sizeof("BROKEN_PIPE") - 1, G_IO_ERROR_BROKEN_PIPE);
	zend_declare_class_constant_long(gioerrorenum_ce, "CONNECTION_CLOSED", sizeof("CONNECTION_CLOSED") - 1, G_IO_ERROR_CONNECTION_CLOSED);
	zend_declare_class_constant_long(gioerrorenum_ce, "NOT_CONNECTED", sizeof("NOT_CONNECTED") - 1, G_IO_ERROR_NOT_CONNECTED);
	zend_declare_class_constant_long(gioerrorenum_ce, "MESSAGE_TOO_LARGE", sizeof("MESSAGE_TOO_LARGE") - 1, G_IO_ERROR_MESSAGE_TOO_LARGE);

	zend_class_entry tmp_giomodulescopeflags_ce;
	INIT_CLASS_ENTRY(tmp_giomodulescopeflags_ce, "G\\I\\O\\Module\\Scope\\Flags", NULL);
	zend_class_entry *giomodulescopeflags_ce = zend_register_internal_class(&tmp_giomodulescopeflags_ce);
	giomodulescopeflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(giomodulescopeflags_ce, "NONE", sizeof("NONE") - 1, G_IO_MODULE_SCOPE_NONE);
	zend_declare_class_constant_long(giomodulescopeflags_ce, "BLOCK_DUPLICATES", sizeof("BLOCK_DUPLICATES") - 1, G_IO_MODULE_SCOPE_BLOCK_DUPLICATES);

	zend_class_entry tmp_gmountmountflags_ce;
	INIT_CLASS_ENTRY(tmp_gmountmountflags_ce, "G\\Mount\\Mount\\Flags", NULL);
	zend_class_entry *gmountmountflags_ce = zend_register_internal_class(&tmp_gmountmountflags_ce);
	gmountmountflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gmountmountflags_ce, "NONE", sizeof("NONE") - 1, G_MOUNT_MOUNT_NONE);

	zend_class_entry tmp_gmountoperationresult_ce;
	INIT_CLASS_ENTRY(tmp_gmountoperationresult_ce, "G\\Mount\\Operation\\Result", NULL);
	zend_class_entry *gmountoperationresult_ce = zend_register_internal_class(&tmp_gmountoperationresult_ce);
	gmountoperationresult_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gmountoperationresult_ce, "HANDLED", sizeof("HANDLED") - 1, G_MOUNT_OPERATION_HANDLED);
	zend_declare_class_constant_long(gmountoperationresult_ce, "ABORTED", sizeof("ABORTED") - 1, G_MOUNT_OPERATION_ABORTED);
	zend_declare_class_constant_long(gmountoperationresult_ce, "UNHANDLED", sizeof("UNHANDLED") - 1, G_MOUNT_OPERATION_UNHANDLED);

	zend_class_entry tmp_gnetworkconnectivity_ce;
	INIT_CLASS_ENTRY(tmp_gnetworkconnectivity_ce, "G\\Network\\Connectivity", NULL);
	zend_class_entry *gnetworkconnectivity_ce = zend_register_internal_class(&tmp_gnetworkconnectivity_ce);
	gnetworkconnectivity_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gnetworkconnectivity_ce, "LOCAL", sizeof("LOCAL") - 1, G_NETWORK_CONNECTIVITY_LOCAL);
	zend_declare_class_constant_long(gnetworkconnectivity_ce, "LIMITED", sizeof("LIMITED") - 1, G_NETWORK_CONNECTIVITY_LIMITED);
	zend_declare_class_constant_long(gnetworkconnectivity_ce, "PORTAL", sizeof("PORTAL") - 1, G_NETWORK_CONNECTIVITY_PORTAL);
	zend_declare_class_constant_long(gnetworkconnectivity_ce, "FULL", sizeof("FULL") - 1, G_NETWORK_CONNECTIVITY_FULL);

	zend_class_entry tmp_gnotificationpriority_ce;
	INIT_CLASS_ENTRY(tmp_gnotificationpriority_ce, "G\\Notification\\Priority", NULL);
	zend_class_entry *gnotificationpriority_ce = zend_register_internal_class(&tmp_gnotificationpriority_ce);
	gnotificationpriority_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gnotificationpriority_ce, "NORMAL", sizeof("NORMAL") - 1, G_NOTIFICATION_PRIORITY_NORMAL);
	zend_declare_class_constant_long(gnotificationpriority_ce, "LOW", sizeof("LOW") - 1, G_NOTIFICATION_PRIORITY_LOW);
	zend_declare_class_constant_long(gnotificationpriority_ce, "HIGH", sizeof("HIGH") - 1, G_NOTIFICATION_PRIORITY_HIGH);
	zend_declare_class_constant_long(gnotificationpriority_ce, "URGENT", sizeof("URGENT") - 1, G_NOTIFICATION_PRIORITY_URGENT);

	zend_class_entry tmp_gpasswordsave_ce;
	INIT_CLASS_ENTRY(tmp_gpasswordsave_ce, "G\\Password\\Save", NULL);
	zend_class_entry *gpasswordsave_ce = zend_register_internal_class(&tmp_gpasswordsave_ce);
	gpasswordsave_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gpasswordsave_ce, "NEVER", sizeof("NEVER") - 1, G_PASSWORD_SAVE_NEVER);
	zend_declare_class_constant_long(gpasswordsave_ce, "FOR_SESSION", sizeof("FOR_SESSION") - 1, G_PASSWORD_SAVE_FOR_SESSION);
	zend_declare_class_constant_long(gpasswordsave_ce, "PERMANENTLY", sizeof("PERMANENTLY") - 1, G_PASSWORD_SAVE_PERMANENTLY);

	zend_class_entry tmp_gresolvererror_ce;
	INIT_CLASS_ENTRY(tmp_gresolvererror_ce, "G\\Resolver\\Error", NULL);
	zend_class_entry *gresolvererror_ce = zend_register_internal_class(&tmp_gresolvererror_ce);
	gresolvererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gresolvererror_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, G_RESOLVER_ERROR_NOT_FOUND);
	zend_declare_class_constant_long(gresolvererror_ce, "TEMPORARY_FAILURE", sizeof("TEMPORARY_FAILURE") - 1, G_RESOLVER_ERROR_TEMPORARY_FAILURE);
	zend_declare_class_constant_long(gresolvererror_ce, "INTERNAL", sizeof("INTERNAL") - 1, G_RESOLVER_ERROR_INTERNAL);

	zend_class_entry tmp_gresolverrecordtype_ce;
	INIT_CLASS_ENTRY(tmp_gresolverrecordtype_ce, "G\\Resolver\\Record\\Type", NULL);
	zend_class_entry *gresolverrecordtype_ce = zend_register_internal_class(&tmp_gresolverrecordtype_ce);
	gresolverrecordtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gresolverrecordtype_ce, "SRV", sizeof("SRV") - 1, G_RESOLVER_RECORD_SRV);
	zend_declare_class_constant_long(gresolverrecordtype_ce, "MX", sizeof("MX") - 1, G_RESOLVER_RECORD_MX);
	zend_declare_class_constant_long(gresolverrecordtype_ce, "TXT", sizeof("TXT") - 1, G_RESOLVER_RECORD_TXT);
	zend_declare_class_constant_long(gresolverrecordtype_ce, "SOA", sizeof("SOA") - 1, G_RESOLVER_RECORD_SOA);
	zend_declare_class_constant_long(gresolverrecordtype_ce, "NS", sizeof("NS") - 1, G_RESOLVER_RECORD_NS);

	zend_class_entry tmp_gresourceerror_ce;
	INIT_CLASS_ENTRY(tmp_gresourceerror_ce, "G\\Resource\\Error", NULL);
	zend_class_entry *gresourceerror_ce = zend_register_internal_class(&tmp_gresourceerror_ce);
	gresourceerror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gresourceerror_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, G_RESOURCE_ERROR_NOT_FOUND);
	zend_declare_class_constant_long(gresourceerror_ce, "INTERNAL", sizeof("INTERNAL") - 1, G_RESOURCE_ERROR_INTERNAL);

	zend_class_entry tmp_gresourcelookupflags_ce;
	INIT_CLASS_ENTRY(tmp_gresourcelookupflags_ce, "G\\Resource\\Lookup\\Flags", NULL);
	zend_class_entry *gresourcelookupflags_ce = zend_register_internal_class(&tmp_gresourcelookupflags_ce);
	gresourcelookupflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gresourcelookupflags_ce, "NONE", sizeof("NONE") - 1, G_RESOURCE_LOOKUP_FLAGS_NONE);

	zend_class_entry tmp_gsocketclientevent_ce;
	INIT_CLASS_ENTRY(tmp_gsocketclientevent_ce, "G\\Socket\\Client\\Event", NULL);
	zend_class_entry *gsocketclientevent_ce = zend_register_internal_class(&tmp_gsocketclientevent_ce);
	gsocketclientevent_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsocketclientevent_ce, "RESOLVING", sizeof("RESOLVING") - 1, G_SOCKET_CLIENT_RESOLVING);
	zend_declare_class_constant_long(gsocketclientevent_ce, "RESOLVED", sizeof("RESOLVED") - 1, G_SOCKET_CLIENT_RESOLVED);
	zend_declare_class_constant_long(gsocketclientevent_ce, "CONNECTING", sizeof("CONNECTING") - 1, G_SOCKET_CLIENT_CONNECTING);
	zend_declare_class_constant_long(gsocketclientevent_ce, "CONNECTED", sizeof("CONNECTED") - 1, G_SOCKET_CLIENT_CONNECTED);
	zend_declare_class_constant_long(gsocketclientevent_ce, "PROXY_NEGOTIATING", sizeof("PROXY_NEGOTIATING") - 1, G_SOCKET_CLIENT_PROXY_NEGOTIATING);
	zend_declare_class_constant_long(gsocketclientevent_ce, "PROXY_NEGOTIATED", sizeof("PROXY_NEGOTIATED") - 1, G_SOCKET_CLIENT_PROXY_NEGOTIATED);
	zend_declare_class_constant_long(gsocketclientevent_ce, "TLS_HANDSHAKING", sizeof("TLS_HANDSHAKING") - 1, G_SOCKET_CLIENT_TLS_HANDSHAKING);
	zend_declare_class_constant_long(gsocketclientevent_ce, "TLS_HANDSHAKED", sizeof("TLS_HANDSHAKED") - 1, G_SOCKET_CLIENT_TLS_HANDSHAKED);
	zend_declare_class_constant_long(gsocketclientevent_ce, "COMPLETE", sizeof("COMPLETE") - 1, G_SOCKET_CLIENT_COMPLETE);

	zend_class_entry tmp_gsocketfamily_ce;
	INIT_CLASS_ENTRY(tmp_gsocketfamily_ce, "G\\Socket\\Family", NULL);
	zend_class_entry *gsocketfamily_ce = zend_register_internal_class(&tmp_gsocketfamily_ce);
	gsocketfamily_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsocketfamily_ce, "INVALID", sizeof("INVALID") - 1, G_SOCKET_FAMILY_INVALID);
	zend_declare_class_constant_long(gsocketfamily_ce, "UNIX", sizeof("UNIX") - 1, G_SOCKET_FAMILY_UNIX);
	zend_declare_class_constant_long(gsocketfamily_ce, "IPV4", sizeof("IPV4") - 1, G_SOCKET_FAMILY_IPV4);
	zend_declare_class_constant_long(gsocketfamily_ce, "IPV6", sizeof("IPV6") - 1, G_SOCKET_FAMILY_IPV6);

	zend_class_entry tmp_gsocketlistenerevent_ce;
	INIT_CLASS_ENTRY(tmp_gsocketlistenerevent_ce, "G\\Socket\\Listener\\Event", NULL);
	zend_class_entry *gsocketlistenerevent_ce = zend_register_internal_class(&tmp_gsocketlistenerevent_ce);
	gsocketlistenerevent_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsocketlistenerevent_ce, "BINDING", sizeof("BINDING") - 1, G_SOCKET_LISTENER_BINDING);
	zend_declare_class_constant_long(gsocketlistenerevent_ce, "BOUND", sizeof("BOUND") - 1, G_SOCKET_LISTENER_BOUND);
	zend_declare_class_constant_long(gsocketlistenerevent_ce, "LISTENING", sizeof("LISTENING") - 1, G_SOCKET_LISTENER_LISTENING);
	zend_declare_class_constant_long(gsocketlistenerevent_ce, "LISTENED", sizeof("LISTENED") - 1, G_SOCKET_LISTENER_LISTENED);

	zend_class_entry tmp_gsocketmsgflags_ce;
	INIT_CLASS_ENTRY(tmp_gsocketmsgflags_ce, "G\\Socket\\Msg\\Flags", NULL);
	zend_class_entry *gsocketmsgflags_ce = zend_register_internal_class(&tmp_gsocketmsgflags_ce);
	gsocketmsgflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsocketmsgflags_ce, "NONE", sizeof("NONE") - 1, G_SOCKET_MSG_NONE);
	zend_declare_class_constant_long(gsocketmsgflags_ce, "OOB", sizeof("OOB") - 1, G_SOCKET_MSG_OOB);
	zend_declare_class_constant_long(gsocketmsgflags_ce, "PEEK", sizeof("PEEK") - 1, G_SOCKET_MSG_PEEK);
	zend_declare_class_constant_long(gsocketmsgflags_ce, "DONTROUTE", sizeof("DONTROUTE") - 1, G_SOCKET_MSG_DONTROUTE);

	zend_class_entry tmp_gsocketprotocol_ce;
	INIT_CLASS_ENTRY(tmp_gsocketprotocol_ce, "G\\Socket\\Protocol", NULL);
	zend_class_entry *gsocketprotocol_ce = zend_register_internal_class(&tmp_gsocketprotocol_ce);
	gsocketprotocol_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsocketprotocol_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, G_SOCKET_PROTOCOL_UNKNOWN);
	zend_declare_class_constant_long(gsocketprotocol_ce, "DEFAULT", sizeof("DEFAULT") - 1, G_SOCKET_PROTOCOL_DEFAULT);
	zend_declare_class_constant_long(gsocketprotocol_ce, "TCP", sizeof("TCP") - 1, G_SOCKET_PROTOCOL_TCP);
	zend_declare_class_constant_long(gsocketprotocol_ce, "UDP", sizeof("UDP") - 1, G_SOCKET_PROTOCOL_UDP);
	zend_declare_class_constant_long(gsocketprotocol_ce, "SCTP", sizeof("SCTP") - 1, G_SOCKET_PROTOCOL_SCTP);

	zend_class_entry tmp_gsockettype_ce;
	INIT_CLASS_ENTRY(tmp_gsockettype_ce, "G\\Socket\\Type", NULL);
	zend_class_entry *gsockettype_ce = zend_register_internal_class(&tmp_gsockettype_ce);
	gsockettype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsockettype_ce, "INVALID", sizeof("INVALID") - 1, G_SOCKET_TYPE_INVALID);
	zend_declare_class_constant_long(gsockettype_ce, "STREAM", sizeof("STREAM") - 1, G_SOCKET_TYPE_STREAM);
	zend_declare_class_constant_long(gsockettype_ce, "DATAGRAM", sizeof("DATAGRAM") - 1, G_SOCKET_TYPE_DATAGRAM);
	zend_declare_class_constant_long(gsockettype_ce, "SEQPACKET", sizeof("SEQPACKET") - 1, G_SOCKET_TYPE_SEQPACKET);

	zend_class_entry tmp_gtestdbusflags_ce;
	INIT_CLASS_ENTRY(tmp_gtestdbusflags_ce, "G\\Test\\D\\Bus\\Flags", NULL);
	zend_class_entry *gtestdbusflags_ce = zend_register_internal_class(&tmp_gtestdbusflags_ce);
	gtestdbusflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtestdbusflags_ce, "NONE", sizeof("NONE") - 1, G_TEST_DBUS_NONE);

	zend_class_entry tmp_gtlsauthenticationmode_ce;
	INIT_CLASS_ENTRY(tmp_gtlsauthenticationmode_ce, "G\\Tls\\Authentication\\Mode", NULL);
	zend_class_entry *gtlsauthenticationmode_ce = zend_register_internal_class(&tmp_gtlsauthenticationmode_ce);
	gtlsauthenticationmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlsauthenticationmode_ce, "NONE", sizeof("NONE") - 1, G_TLS_AUTHENTICATION_NONE);
	zend_declare_class_constant_long(gtlsauthenticationmode_ce, "REQUESTED", sizeof("REQUESTED") - 1, G_TLS_AUTHENTICATION_REQUESTED);
	zend_declare_class_constant_long(gtlsauthenticationmode_ce, "REQUIRED", sizeof("REQUIRED") - 1, G_TLS_AUTHENTICATION_REQUIRED);

	zend_class_entry tmp_gtlscertificaterequestflags_ce;
	INIT_CLASS_ENTRY(tmp_gtlscertificaterequestflags_ce, "G\\Tls\\Certificate\\Request\\Flags", NULL);
	zend_class_entry *gtlscertificaterequestflags_ce = zend_register_internal_class(&tmp_gtlscertificaterequestflags_ce);
	gtlscertificaterequestflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlscertificaterequestflags_ce, "NONE", sizeof("NONE") - 1, G_TLS_CERTIFICATE_REQUEST_NONE);

	zend_class_entry tmp_gtlsdatabaselookupflags_ce;
	INIT_CLASS_ENTRY(tmp_gtlsdatabaselookupflags_ce, "G\\Tls\\Database\\Lookup\\Flags", NULL);
	zend_class_entry *gtlsdatabaselookupflags_ce = zend_register_internal_class(&tmp_gtlsdatabaselookupflags_ce);
	gtlsdatabaselookupflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlsdatabaselookupflags_ce, "NONE", sizeof("NONE") - 1, G_TLS_DATABASE_LOOKUP_NONE);
	zend_declare_class_constant_long(gtlsdatabaselookupflags_ce, "KEYPAIR", sizeof("KEYPAIR") - 1, G_TLS_DATABASE_LOOKUP_KEYPAIR);

	zend_class_entry tmp_gtlsdatabaseverifyflags_ce;
	INIT_CLASS_ENTRY(tmp_gtlsdatabaseverifyflags_ce, "G\\Tls\\Database\\Verify\\Flags", NULL);
	zend_class_entry *gtlsdatabaseverifyflags_ce = zend_register_internal_class(&tmp_gtlsdatabaseverifyflags_ce);
	gtlsdatabaseverifyflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlsdatabaseverifyflags_ce, "NONE", sizeof("NONE") - 1, G_TLS_DATABASE_VERIFY_NONE);

	zend_class_entry tmp_gtlserror_ce;
	INIT_CLASS_ENTRY(tmp_gtlserror_ce, "G\\Tls\\Error", NULL);
	zend_class_entry *gtlserror_ce = zend_register_internal_class(&tmp_gtlserror_ce);
	gtlserror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlserror_ce, "UNAVAILABLE", sizeof("UNAVAILABLE") - 1, G_TLS_ERROR_UNAVAILABLE);
	zend_declare_class_constant_long(gtlserror_ce, "MISC", sizeof("MISC") - 1, G_TLS_ERROR_MISC);
	zend_declare_class_constant_long(gtlserror_ce, "BAD_CERTIFICATE", sizeof("BAD_CERTIFICATE") - 1, G_TLS_ERROR_BAD_CERTIFICATE);
	zend_declare_class_constant_long(gtlserror_ce, "NOT_TLS", sizeof("NOT_TLS") - 1, G_TLS_ERROR_NOT_TLS);
	zend_declare_class_constant_long(gtlserror_ce, "HANDSHAKE", sizeof("HANDSHAKE") - 1, G_TLS_ERROR_HANDSHAKE);
	zend_declare_class_constant_long(gtlserror_ce, "CERTIFICATE_REQUIRED", sizeof("CERTIFICATE_REQUIRED") - 1, G_TLS_ERROR_CERTIFICATE_REQUIRED);
	zend_declare_class_constant_long(gtlserror_ce, "EOF", sizeof("EOF") - 1, G_TLS_ERROR_EOF);

	zend_class_entry tmp_gtlsinteractionresult_ce;
	INIT_CLASS_ENTRY(tmp_gtlsinteractionresult_ce, "G\\Tls\\Interaction\\Result", NULL);
	zend_class_entry *gtlsinteractionresult_ce = zend_register_internal_class(&tmp_gtlsinteractionresult_ce);
	gtlsinteractionresult_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlsinteractionresult_ce, "UNHANDLED", sizeof("UNHANDLED") - 1, G_TLS_INTERACTION_UNHANDLED);
	zend_declare_class_constant_long(gtlsinteractionresult_ce, "HANDLED", sizeof("HANDLED") - 1, G_TLS_INTERACTION_HANDLED);
	zend_declare_class_constant_long(gtlsinteractionresult_ce, "FAILED", sizeof("FAILED") - 1, G_TLS_INTERACTION_FAILED);

	zend_class_entry tmp_gtlsrehandshakemode_ce;
	INIT_CLASS_ENTRY(tmp_gtlsrehandshakemode_ce, "G\\Tls\\Rehandshake\\Mode", NULL);
	zend_class_entry *gtlsrehandshakemode_ce = zend_register_internal_class(&tmp_gtlsrehandshakemode_ce);
	gtlsrehandshakemode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlsrehandshakemode_ce, "NEVER", sizeof("NEVER") - 1, G_TLS_REHANDSHAKE_NEVER);
	zend_declare_class_constant_long(gtlsrehandshakemode_ce, "SAFELY", sizeof("SAFELY") - 1, G_TLS_REHANDSHAKE_SAFELY);
	zend_declare_class_constant_long(gtlsrehandshakemode_ce, "UNSAFELY", sizeof("UNSAFELY") - 1, G_TLS_REHANDSHAKE_UNSAFELY);

	zend_class_entry tmp_gunixsocketaddresstype_ce;
	INIT_CLASS_ENTRY(tmp_gunixsocketaddresstype_ce, "G\\Unix\\Socket\\Address\\Type", NULL);
	zend_class_entry *gunixsocketaddresstype_ce = zend_register_internal_class(&tmp_gunixsocketaddresstype_ce);
	gunixsocketaddresstype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gunixsocketaddresstype_ce, "INVALID", sizeof("INVALID") - 1, G_UNIX_SOCKET_ADDRESS_INVALID);
	zend_declare_class_constant_long(gunixsocketaddresstype_ce, "ANONYMOUS", sizeof("ANONYMOUS") - 1, G_UNIX_SOCKET_ADDRESS_ANONYMOUS);
	zend_declare_class_constant_long(gunixsocketaddresstype_ce, "PATH", sizeof("PATH") - 1, G_UNIX_SOCKET_ADDRESS_PATH);
	zend_declare_class_constant_long(gunixsocketaddresstype_ce, "ABSTRACT", sizeof("ABSTRACT") - 1, G_UNIX_SOCKET_ADDRESS_ABSTRACT);
	zend_declare_class_constant_long(gunixsocketaddresstype_ce, "ABSTRACT_PADDED", sizeof("ABSTRACT_PADDED") - 1, G_UNIX_SOCKET_ADDRESS_ABSTRACT_PADDED);

	zend_class_entry tmp_gzlibcompressorformat_ce;
	INIT_CLASS_ENTRY(tmp_gzlibcompressorformat_ce, "G\\Zlib\\Compressor\\Format", NULL);
	zend_class_entry *gzlibcompressorformat_ce = zend_register_internal_class(&tmp_gzlibcompressorformat_ce);
	gzlibcompressorformat_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gzlibcompressorformat_ce, "ZLIB", sizeof("ZLIB") - 1, G_ZLIB_COMPRESSOR_FORMAT_ZLIB);
	zend_declare_class_constant_long(gzlibcompressorformat_ce, "GZIP", sizeof("GZIP") - 1, G_ZLIB_COMPRESSOR_FORMAT_GZIP);
	zend_declare_class_constant_long(gzlibcompressorformat_ce, "RAW", sizeof("RAW") - 1, G_ZLIB_COMPRESSOR_FORMAT_RAW);

	zend_class_entry tmp_gappinfocreateflags_ce;
	INIT_CLASS_ENTRY(tmp_gappinfocreateflags_ce, "G\\App\\Info\\Create\\Flags", NULL);
	zend_class_entry *gappinfocreateflags_ce = zend_register_internal_class(&tmp_gappinfocreateflags_ce);
	gappinfocreateflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gappinfocreateflags_ce, "NONE", sizeof("NONE") - 1, G_APP_INFO_CREATE_NONE);
	zend_declare_class_constant_long(gappinfocreateflags_ce, "NEEDS_TERMINAL", sizeof("NEEDS_TERMINAL") - 1, G_APP_INFO_CREATE_NEEDS_TERMINAL);
	zend_declare_class_constant_long(gappinfocreateflags_ce, "SUPPORTS_URIS", sizeof("SUPPORTS_URIS") - 1, G_APP_INFO_CREATE_SUPPORTS_URIS);
	zend_declare_class_constant_long(gappinfocreateflags_ce, "SUPPORTS_STARTUP_NOTIFICATION", sizeof("SUPPORTS_STARTUP_NOTIFICATION") - 1, G_APP_INFO_CREATE_SUPPORTS_STARTUP_NOTIFICATION);

	zend_class_entry tmp_gapplicationflags_ce;
	INIT_CLASS_ENTRY(tmp_gapplicationflags_ce, "G\\Application\\Flags", NULL);
	zend_class_entry *gapplicationflags_ce = zend_register_internal_class(&tmp_gapplicationflags_ce);
	gapplicationflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gapplicationflags_ce, "NONE", sizeof("NONE") - 1, G_APPLICATION_FLAGS_NONE);
	zend_declare_class_constant_long(gapplicationflags_ce, "IS_SERVICE", sizeof("IS_SERVICE") - 1, G_APPLICATION_IS_SERVICE);
	zend_declare_class_constant_long(gapplicationflags_ce, "IS_LAUNCHER", sizeof("IS_LAUNCHER") - 1, G_APPLICATION_IS_LAUNCHER);
	zend_declare_class_constant_long(gapplicationflags_ce, "HANDLES_OPEN", sizeof("HANDLES_OPEN") - 1, G_APPLICATION_HANDLES_OPEN);
	zend_declare_class_constant_long(gapplicationflags_ce, "HANDLES_COMMAND_LINE", sizeof("HANDLES_COMMAND_LINE") - 1, G_APPLICATION_HANDLES_COMMAND_LINE);
	zend_declare_class_constant_long(gapplicationflags_ce, "SEND_ENVIRONMENT", sizeof("SEND_ENVIRONMENT") - 1, G_APPLICATION_SEND_ENVIRONMENT);
	zend_declare_class_constant_long(gapplicationflags_ce, "NON_UNIQUE", sizeof("NON_UNIQUE") - 1, G_APPLICATION_NON_UNIQUE);
	zend_declare_class_constant_long(gapplicationflags_ce, "CAN_OVERRIDE_APP_ID", sizeof("CAN_OVERRIDE_APP_ID") - 1, G_APPLICATION_CAN_OVERRIDE_APP_ID);

	zend_class_entry tmp_gaskpasswordflags_ce;
	INIT_CLASS_ENTRY(tmp_gaskpasswordflags_ce, "G\\Ask\\Password\\Flags", NULL);
	zend_class_entry *gaskpasswordflags_ce = zend_register_internal_class(&tmp_gaskpasswordflags_ce);
	gaskpasswordflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gaskpasswordflags_ce, "NEED_PASSWORD", sizeof("NEED_PASSWORD") - 1, G_ASK_PASSWORD_NEED_PASSWORD);
	zend_declare_class_constant_long(gaskpasswordflags_ce, "NEED_USERNAME", sizeof("NEED_USERNAME") - 1, G_ASK_PASSWORD_NEED_USERNAME);
	zend_declare_class_constant_long(gaskpasswordflags_ce, "NEED_DOMAIN", sizeof("NEED_DOMAIN") - 1, G_ASK_PASSWORD_NEED_DOMAIN);
	zend_declare_class_constant_long(gaskpasswordflags_ce, "SAVING_SUPPORTED", sizeof("SAVING_SUPPORTED") - 1, G_ASK_PASSWORD_SAVING_SUPPORTED);
	zend_declare_class_constant_long(gaskpasswordflags_ce, "ANONYMOUS_SUPPORTED", sizeof("ANONYMOUS_SUPPORTED") - 1, G_ASK_PASSWORD_ANONYMOUS_SUPPORTED);
	zend_declare_class_constant_long(gaskpasswordflags_ce, "TCRYPT", sizeof("TCRYPT") - 1, G_ASK_PASSWORD_TCRYPT);

	zend_class_entry tmp_gbusnameownerflags_ce;
	INIT_CLASS_ENTRY(tmp_gbusnameownerflags_ce, "G\\Bus\\Name\\Owner\\Flags", NULL);
	zend_class_entry *gbusnameownerflags_ce = zend_register_internal_class(&tmp_gbusnameownerflags_ce);
	gbusnameownerflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gbusnameownerflags_ce, "NONE", sizeof("NONE") - 1, G_BUS_NAME_OWNER_FLAGS_NONE);
	zend_declare_class_constant_long(gbusnameownerflags_ce, "ALLOW_REPLACEMENT", sizeof("ALLOW_REPLACEMENT") - 1, G_BUS_NAME_OWNER_FLAGS_ALLOW_REPLACEMENT);
	zend_declare_class_constant_long(gbusnameownerflags_ce, "REPLACE", sizeof("REPLACE") - 1, G_BUS_NAME_OWNER_FLAGS_REPLACE);
	zend_declare_class_constant_long(gbusnameownerflags_ce, "DO_NOT_QUEUE", sizeof("DO_NOT_QUEUE") - 1, G_BUS_NAME_OWNER_FLAGS_DO_NOT_QUEUE);

	zend_class_entry tmp_gbusnamewatcherflags_ce;
	INIT_CLASS_ENTRY(tmp_gbusnamewatcherflags_ce, "G\\Bus\\Name\\Watcher\\Flags", NULL);
	zend_class_entry *gbusnamewatcherflags_ce = zend_register_internal_class(&tmp_gbusnamewatcherflags_ce);
	gbusnamewatcherflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gbusnamewatcherflags_ce, "NONE", sizeof("NONE") - 1, G_BUS_NAME_WATCHER_FLAGS_NONE);
	zend_declare_class_constant_long(gbusnamewatcherflags_ce, "AUTO_START", sizeof("AUTO_START") - 1, G_BUS_NAME_WATCHER_FLAGS_AUTO_START);

	zend_class_entry tmp_gconverterflags_ce;
	INIT_CLASS_ENTRY(tmp_gconverterflags_ce, "G\\Converter\\Flags", NULL);
	zend_class_entry *gconverterflags_ce = zend_register_internal_class(&tmp_gconverterflags_ce);
	gconverterflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gconverterflags_ce, "NO_FLAGS", sizeof("NO_FLAGS") - 1, G_CONVERTER_NO_FLAGS);
	zend_declare_class_constant_long(gconverterflags_ce, "INPUT_AT_END", sizeof("INPUT_AT_END") - 1, G_CONVERTER_INPUT_AT_END);
	zend_declare_class_constant_long(gconverterflags_ce, "FLUSH", sizeof("FLUSH") - 1, G_CONVERTER_FLUSH);

	zend_class_entry tmp_gdbuscallflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbuscallflags_ce, "G\\D\\Bus\\Call\\Flags", NULL);
	zend_class_entry *gdbuscallflags_ce = zend_register_internal_class(&tmp_gdbuscallflags_ce);
	gdbuscallflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbuscallflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_CALL_FLAGS_NONE);
	zend_declare_class_constant_long(gdbuscallflags_ce, "NO_AUTO_START", sizeof("NO_AUTO_START") - 1, G_DBUS_CALL_FLAGS_NO_AUTO_START);
	zend_declare_class_constant_long(gdbuscallflags_ce, "ALLOW_INTERACTIVE_AUTHORIZATION", sizeof("ALLOW_INTERACTIVE_AUTHORIZATION") - 1, G_DBUS_CALL_FLAGS_ALLOW_INTERACTIVE_AUTHORIZATION);

	zend_class_entry tmp_gdbuscapabilityflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbuscapabilityflags_ce, "G\\D\\Bus\\Capability\\Flags", NULL);
	zend_class_entry *gdbuscapabilityflags_ce = zend_register_internal_class(&tmp_gdbuscapabilityflags_ce);
	gdbuscapabilityflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbuscapabilityflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_CAPABILITY_FLAGS_NONE);
	zend_declare_class_constant_long(gdbuscapabilityflags_ce, "UNIX_FD_PASSING", sizeof("UNIX_FD_PASSING") - 1, G_DBUS_CAPABILITY_FLAGS_UNIX_FD_PASSING);

	zend_class_entry tmp_gdbusconnectionflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusconnectionflags_ce, "G\\D\\Bus\\Connection\\Flags", NULL);
	zend_class_entry *gdbusconnectionflags_ce = zend_register_internal_class(&tmp_gdbusconnectionflags_ce);
	gdbusconnectionflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_CONNECTION_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "AUTHENTICATION_CLIENT", sizeof("AUTHENTICATION_CLIENT") - 1, G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT);
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "AUTHENTICATION_SERVER", sizeof("AUTHENTICATION_SERVER") - 1, G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_SERVER);
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "AUTHENTICATION_ALLOW_ANONYMOUS", sizeof("AUTHENTICATION_ALLOW_ANONYMOUS") - 1, G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS);
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "MESSAGE_BUS_CONNECTION", sizeof("MESSAGE_BUS_CONNECTION") - 1, G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION);
	zend_declare_class_constant_long(gdbusconnectionflags_ce, "DELAY_MESSAGE_PROCESSING", sizeof("DELAY_MESSAGE_PROCESSING") - 1, G_DBUS_CONNECTION_FLAGS_DELAY_MESSAGE_PROCESSING);

	zend_class_entry tmp_gdbusinterfaceskeletonflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusinterfaceskeletonflags_ce, "G\\D\\Bus\\Interface\\Skeleton\\Flags", NULL);
	zend_class_entry *gdbusinterfaceskeletonflags_ce = zend_register_internal_class(&tmp_gdbusinterfaceskeletonflags_ce);
	gdbusinterfaceskeletonflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusinterfaceskeletonflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_INTERFACE_SKELETON_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusinterfaceskeletonflags_ce, "HANDLE_METHOD_INVOCATIONS_IN_THREAD", sizeof("HANDLE_METHOD_INVOCATIONS_IN_THREAD") - 1, G_DBUS_INTERFACE_SKELETON_FLAGS_HANDLE_METHOD_INVOCATIONS_IN_THREAD);

	zend_class_entry tmp_gdbusmessageflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusmessageflags_ce, "G\\D\\Bus\\Message\\Flags", NULL);
	zend_class_entry *gdbusmessageflags_ce = zend_register_internal_class(&tmp_gdbusmessageflags_ce);
	gdbusmessageflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusmessageflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_MESSAGE_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusmessageflags_ce, "NO_REPLY_EXPECTED", sizeof("NO_REPLY_EXPECTED") - 1, G_DBUS_MESSAGE_FLAGS_NO_REPLY_EXPECTED);
	zend_declare_class_constant_long(gdbusmessageflags_ce, "NO_AUTO_START", sizeof("NO_AUTO_START") - 1, G_DBUS_MESSAGE_FLAGS_NO_AUTO_START);
	zend_declare_class_constant_long(gdbusmessageflags_ce, "ALLOW_INTERACTIVE_AUTHORIZATION", sizeof("ALLOW_INTERACTIVE_AUTHORIZATION") - 1, G_DBUS_MESSAGE_FLAGS_ALLOW_INTERACTIVE_AUTHORIZATION);

	zend_class_entry tmp_gdbusobjectmanagerclientflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusobjectmanagerclientflags_ce, "G\\D\\Bus\\Object\\Manager\\Client\\Flags", NULL);
	zend_class_entry *gdbusobjectmanagerclientflags_ce = zend_register_internal_class(&tmp_gdbusobjectmanagerclientflags_ce);
	gdbusobjectmanagerclientflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusobjectmanagerclientflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusobjectmanagerclientflags_ce, "DO_NOT_AUTO_START", sizeof("DO_NOT_AUTO_START") - 1, G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_DO_NOT_AUTO_START);

	zend_class_entry tmp_gdbuspropertyinfoflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbuspropertyinfoflags_ce, "G\\D\\Bus\\Property\\Info\\Flags", NULL);
	zend_class_entry *gdbuspropertyinfoflags_ce = zend_register_internal_class(&tmp_gdbuspropertyinfoflags_ce);
	gdbuspropertyinfoflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbuspropertyinfoflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_PROPERTY_INFO_FLAGS_NONE);
	zend_declare_class_constant_long(gdbuspropertyinfoflags_ce, "READABLE", sizeof("READABLE") - 1, G_DBUS_PROPERTY_INFO_FLAGS_READABLE);
	zend_declare_class_constant_long(gdbuspropertyinfoflags_ce, "WRITABLE", sizeof("WRITABLE") - 1, G_DBUS_PROPERTY_INFO_FLAGS_WRITABLE);

	zend_class_entry tmp_gdbusproxyflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusproxyflags_ce, "G\\D\\Bus\\Proxy\\Flags", NULL);
	zend_class_entry *gdbusproxyflags_ce = zend_register_internal_class(&tmp_gdbusproxyflags_ce);
	gdbusproxyflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusproxyflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_PROXY_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusproxyflags_ce, "DO_NOT_LOAD_PROPERTIES", sizeof("DO_NOT_LOAD_PROPERTIES") - 1, G_DBUS_PROXY_FLAGS_DO_NOT_LOAD_PROPERTIES);
	zend_declare_class_constant_long(gdbusproxyflags_ce, "DO_NOT_CONNECT_SIGNALS", sizeof("DO_NOT_CONNECT_SIGNALS") - 1, G_DBUS_PROXY_FLAGS_DO_NOT_CONNECT_SIGNALS);
	zend_declare_class_constant_long(gdbusproxyflags_ce, "DO_NOT_AUTO_START", sizeof("DO_NOT_AUTO_START") - 1, G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START);
	zend_declare_class_constant_long(gdbusproxyflags_ce, "GET_INVALIDATED_PROPERTIES", sizeof("GET_INVALIDATED_PROPERTIES") - 1, G_DBUS_PROXY_FLAGS_GET_INVALIDATED_PROPERTIES);
	zend_declare_class_constant_long(gdbusproxyflags_ce, "DO_NOT_AUTO_START_AT_CONSTRUCTION", sizeof("DO_NOT_AUTO_START_AT_CONSTRUCTION") - 1, G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START_AT_CONSTRUCTION);

	zend_class_entry tmp_gdbussendmessageflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbussendmessageflags_ce, "G\\D\\Bus\\Send\\Message\\Flags", NULL);
	zend_class_entry *gdbussendmessageflags_ce = zend_register_internal_class(&tmp_gdbussendmessageflags_ce);
	gdbussendmessageflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbussendmessageflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_SEND_MESSAGE_FLAGS_NONE);
	zend_declare_class_constant_long(gdbussendmessageflags_ce, "PRESERVE_SERIAL", sizeof("PRESERVE_SERIAL") - 1, G_DBUS_SEND_MESSAGE_FLAGS_PRESERVE_SERIAL);

	zend_class_entry tmp_gdbusserverflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbusserverflags_ce, "G\\D\\Bus\\Server\\Flags", NULL);
	zend_class_entry *gdbusserverflags_ce = zend_register_internal_class(&tmp_gdbusserverflags_ce);
	gdbusserverflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbusserverflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_SERVER_FLAGS_NONE);
	zend_declare_class_constant_long(gdbusserverflags_ce, "RUN_IN_THREAD", sizeof("RUN_IN_THREAD") - 1, G_DBUS_SERVER_FLAGS_RUN_IN_THREAD);
	zend_declare_class_constant_long(gdbusserverflags_ce, "AUTHENTICATION_ALLOW_ANONYMOUS", sizeof("AUTHENTICATION_ALLOW_ANONYMOUS") - 1, G_DBUS_SERVER_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS);

	zend_class_entry tmp_gdbussignalflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbussignalflags_ce, "G\\D\\Bus\\Signal\\Flags", NULL);
	zend_class_entry *gdbussignalflags_ce = zend_register_internal_class(&tmp_gdbussignalflags_ce);
	gdbussignalflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbussignalflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_SIGNAL_FLAGS_NONE);
	zend_declare_class_constant_long(gdbussignalflags_ce, "NO_MATCH_RULE", sizeof("NO_MATCH_RULE") - 1, G_DBUS_SIGNAL_FLAGS_NO_MATCH_RULE);
	zend_declare_class_constant_long(gdbussignalflags_ce, "MATCH_ARG0_NAMESPACE", sizeof("MATCH_ARG0_NAMESPACE") - 1, G_DBUS_SIGNAL_FLAGS_MATCH_ARG0_NAMESPACE);
	zend_declare_class_constant_long(gdbussignalflags_ce, "MATCH_ARG0_PATH", sizeof("MATCH_ARG0_PATH") - 1, G_DBUS_SIGNAL_FLAGS_MATCH_ARG0_PATH);

	zend_class_entry tmp_gdbussubtreeflags_ce;
	INIT_CLASS_ENTRY(tmp_gdbussubtreeflags_ce, "G\\D\\Bus\\Subtree\\Flags", NULL);
	zend_class_entry *gdbussubtreeflags_ce = zend_register_internal_class(&tmp_gdbussubtreeflags_ce);
	gdbussubtreeflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gdbussubtreeflags_ce, "NONE", sizeof("NONE") - 1, G_DBUS_SUBTREE_FLAGS_NONE);
	zend_declare_class_constant_long(gdbussubtreeflags_ce, "DISPATCH_TO_UNENUMERATED_NODES", sizeof("DISPATCH_TO_UNENUMERATED_NODES") - 1, G_DBUS_SUBTREE_FLAGS_DISPATCH_TO_UNENUMERATED_NODES);

	zend_class_entry tmp_gfileattributeinfoflags_ce;
	INIT_CLASS_ENTRY(tmp_gfileattributeinfoflags_ce, "G\\File\\Attribute\\Info\\Flags", NULL);
	zend_class_entry *gfileattributeinfoflags_ce = zend_register_internal_class(&tmp_gfileattributeinfoflags_ce);
	gfileattributeinfoflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfileattributeinfoflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_ATTRIBUTE_INFO_NONE);
	zend_declare_class_constant_long(gfileattributeinfoflags_ce, "COPY_WITH_FILE", sizeof("COPY_WITH_FILE") - 1, G_FILE_ATTRIBUTE_INFO_COPY_WITH_FILE);
	zend_declare_class_constant_long(gfileattributeinfoflags_ce, "COPY_WHEN_MOVED", sizeof("COPY_WHEN_MOVED") - 1, G_FILE_ATTRIBUTE_INFO_COPY_WHEN_MOVED);

	zend_class_entry tmp_gfilecopyflags_ce;
	INIT_CLASS_ENTRY(tmp_gfilecopyflags_ce, "G\\File\\Copy\\Flags", NULL);
	zend_class_entry *gfilecopyflags_ce = zend_register_internal_class(&tmp_gfilecopyflags_ce);
	gfilecopyflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilecopyflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_COPY_NONE);
	zend_declare_class_constant_long(gfilecopyflags_ce, "OVERWRITE", sizeof("OVERWRITE") - 1, G_FILE_COPY_OVERWRITE);
	zend_declare_class_constant_long(gfilecopyflags_ce, "BACKUP", sizeof("BACKUP") - 1, G_FILE_COPY_BACKUP);
	zend_declare_class_constant_long(gfilecopyflags_ce, "NOFOLLOW_SYMLINKS", sizeof("NOFOLLOW_SYMLINKS") - 1, G_FILE_COPY_NOFOLLOW_SYMLINKS);
	zend_declare_class_constant_long(gfilecopyflags_ce, "ALL_METADATA", sizeof("ALL_METADATA") - 1, G_FILE_COPY_ALL_METADATA);
	zend_declare_class_constant_long(gfilecopyflags_ce, "NO_FALLBACK_FOR_MOVE", sizeof("NO_FALLBACK_FOR_MOVE") - 1, G_FILE_COPY_NO_FALLBACK_FOR_MOVE);
	zend_declare_class_constant_long(gfilecopyflags_ce, "TARGET_DEFAULT_PERMS", sizeof("TARGET_DEFAULT_PERMS") - 1, G_FILE_COPY_TARGET_DEFAULT_PERMS);

	zend_class_entry tmp_gfilecreateflags_ce;
	INIT_CLASS_ENTRY(tmp_gfilecreateflags_ce, "G\\File\\Create\\Flags", NULL);
	zend_class_entry *gfilecreateflags_ce = zend_register_internal_class(&tmp_gfilecreateflags_ce);
	gfilecreateflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilecreateflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_CREATE_NONE);
	zend_declare_class_constant_long(gfilecreateflags_ce, "PRIVATE", sizeof("PRIVATE") - 1, G_FILE_CREATE_PRIVATE);
	zend_declare_class_constant_long(gfilecreateflags_ce, "REPLACE_DESTINATION", sizeof("REPLACE_DESTINATION") - 1, G_FILE_CREATE_REPLACE_DESTINATION);

	zend_class_entry tmp_gfilemeasureflags_ce;
	INIT_CLASS_ENTRY(tmp_gfilemeasureflags_ce, "G\\File\\Measure\\Flags", NULL);
	zend_class_entry *gfilemeasureflags_ce = zend_register_internal_class(&tmp_gfilemeasureflags_ce);
	gfilemeasureflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilemeasureflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_MEASURE_NONE);
	zend_declare_class_constant_long(gfilemeasureflags_ce, "REPORT_ANY_ERROR", sizeof("REPORT_ANY_ERROR") - 1, G_FILE_MEASURE_REPORT_ANY_ERROR);
	zend_declare_class_constant_long(gfilemeasureflags_ce, "APPARENT_SIZE", sizeof("APPARENT_SIZE") - 1, G_FILE_MEASURE_APPARENT_SIZE);
	zend_declare_class_constant_long(gfilemeasureflags_ce, "NO_XDEV", sizeof("NO_XDEV") - 1, G_FILE_MEASURE_NO_XDEV);

	zend_class_entry tmp_gfilemonitorflags_ce;
	INIT_CLASS_ENTRY(tmp_gfilemonitorflags_ce, "G\\File\\Monitor\\Flags", NULL);
	zend_class_entry *gfilemonitorflags_ce = zend_register_internal_class(&tmp_gfilemonitorflags_ce);
	gfilemonitorflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilemonitorflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_MONITOR_NONE);
	zend_declare_class_constant_long(gfilemonitorflags_ce, "WATCH_MOUNTS", sizeof("WATCH_MOUNTS") - 1, G_FILE_MONITOR_WATCH_MOUNTS);
	zend_declare_class_constant_long(gfilemonitorflags_ce, "SEND_MOVED", sizeof("SEND_MOVED") - 1, G_FILE_MONITOR_SEND_MOVED);
	zend_declare_class_constant_long(gfilemonitorflags_ce, "WATCH_HARD_LINKS", sizeof("WATCH_HARD_LINKS") - 1, G_FILE_MONITOR_WATCH_HARD_LINKS);
	zend_declare_class_constant_long(gfilemonitorflags_ce, "WATCH_MOVES", sizeof("WATCH_MOVES") - 1, G_FILE_MONITOR_WATCH_MOVES);

	zend_class_entry tmp_gfilequeryinfoflags_ce;
	INIT_CLASS_ENTRY(tmp_gfilequeryinfoflags_ce, "G\\File\\Query\\Info\\Flags", NULL);
	zend_class_entry *gfilequeryinfoflags_ce = zend_register_internal_class(&tmp_gfilequeryinfoflags_ce);
	gfilequeryinfoflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gfilequeryinfoflags_ce, "NONE", sizeof("NONE") - 1, G_FILE_QUERY_INFO_NONE);
	zend_declare_class_constant_long(gfilequeryinfoflags_ce, "NOFOLLOW_SYMLINKS", sizeof("NOFOLLOW_SYMLINKS") - 1, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS);

	zend_class_entry tmp_giostreamspliceflags_ce;
	INIT_CLASS_ENTRY(tmp_giostreamspliceflags_ce, "G\\I\\O\\Stream\\Splice\\Flags", NULL);
	zend_class_entry *giostreamspliceflags_ce = zend_register_internal_class(&tmp_giostreamspliceflags_ce);
	giostreamspliceflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(giostreamspliceflags_ce, "NONE", sizeof("NONE") - 1, G_IO_STREAM_SPLICE_NONE);
	zend_declare_class_constant_long(giostreamspliceflags_ce, "CLOSE_STREAM1", sizeof("CLOSE_STREAM1") - 1, G_IO_STREAM_SPLICE_CLOSE_STREAM1);
	zend_declare_class_constant_long(giostreamspliceflags_ce, "CLOSE_STREAM2", sizeof("CLOSE_STREAM2") - 1, G_IO_STREAM_SPLICE_CLOSE_STREAM2);
	zend_declare_class_constant_long(giostreamspliceflags_ce, "WAIT_FOR_BOTH", sizeof("WAIT_FOR_BOTH") - 1, G_IO_STREAM_SPLICE_WAIT_FOR_BOTH);

	zend_class_entry tmp_gmountunmountflags_ce;
	INIT_CLASS_ENTRY(tmp_gmountunmountflags_ce, "G\\Mount\\Unmount\\Flags", NULL);
	zend_class_entry *gmountunmountflags_ce = zend_register_internal_class(&tmp_gmountunmountflags_ce);
	gmountunmountflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gmountunmountflags_ce, "NONE", sizeof("NONE") - 1, G_MOUNT_UNMOUNT_NONE);
	zend_declare_class_constant_long(gmountunmountflags_ce, "FORCE", sizeof("FORCE") - 1, G_MOUNT_UNMOUNT_FORCE);

	zend_class_entry tmp_goutputstreamspliceflags_ce;
	INIT_CLASS_ENTRY(tmp_goutputstreamspliceflags_ce, "G\\Output\\Stream\\Splice\\Flags", NULL);
	zend_class_entry *goutputstreamspliceflags_ce = zend_register_internal_class(&tmp_goutputstreamspliceflags_ce);
	goutputstreamspliceflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(goutputstreamspliceflags_ce, "NONE", sizeof("NONE") - 1, G_OUTPUT_STREAM_SPLICE_NONE);
	zend_declare_class_constant_long(goutputstreamspliceflags_ce, "CLOSE_SOURCE", sizeof("CLOSE_SOURCE") - 1, G_OUTPUT_STREAM_SPLICE_CLOSE_SOURCE);
	zend_declare_class_constant_long(goutputstreamspliceflags_ce, "CLOSE_TARGET", sizeof("CLOSE_TARGET") - 1, G_OUTPUT_STREAM_SPLICE_CLOSE_TARGET);

	zend_class_entry tmp_gresourceflags_ce;
	INIT_CLASS_ENTRY(tmp_gresourceflags_ce, "G\\Resource\\Flags", NULL);
	zend_class_entry *gresourceflags_ce = zend_register_internal_class(&tmp_gresourceflags_ce);
	gresourceflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gresourceflags_ce, "NONE", sizeof("NONE") - 1, G_RESOURCE_FLAGS_NONE);
	zend_declare_class_constant_long(gresourceflags_ce, "COMPRESSED", sizeof("COMPRESSED") - 1, G_RESOURCE_FLAGS_COMPRESSED);

	zend_class_entry tmp_gsettingsbindflags_ce;
	INIT_CLASS_ENTRY(tmp_gsettingsbindflags_ce, "G\\Settings\\Bind\\Flags", NULL);
	zend_class_entry *gsettingsbindflags_ce = zend_register_internal_class(&tmp_gsettingsbindflags_ce);
	gsettingsbindflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsettingsbindflags_ce, "DEFAULT", sizeof("DEFAULT") - 1, G_SETTINGS_BIND_DEFAULT);
	zend_declare_class_constant_long(gsettingsbindflags_ce, "GET", sizeof("GET") - 1, G_SETTINGS_BIND_GET);
	zend_declare_class_constant_long(gsettingsbindflags_ce, "SET", sizeof("SET") - 1, G_SETTINGS_BIND_SET);
	zend_declare_class_constant_long(gsettingsbindflags_ce, "NO_SENSITIVITY", sizeof("NO_SENSITIVITY") - 1, G_SETTINGS_BIND_NO_SENSITIVITY);
	zend_declare_class_constant_long(gsettingsbindflags_ce, "GET_NO_CHANGES", sizeof("GET_NO_CHANGES") - 1, G_SETTINGS_BIND_GET_NO_CHANGES);
	zend_declare_class_constant_long(gsettingsbindflags_ce, "INVERT_BOOLEAN", sizeof("INVERT_BOOLEAN") - 1, G_SETTINGS_BIND_INVERT_BOOLEAN);

	zend_class_entry tmp_gsubprocessflags_ce;
	INIT_CLASS_ENTRY(tmp_gsubprocessflags_ce, "G\\Subprocess\\Flags", NULL);
	zend_class_entry *gsubprocessflags_ce = zend_register_internal_class(&tmp_gsubprocessflags_ce);
	gsubprocessflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gsubprocessflags_ce, "NONE", sizeof("NONE") - 1, G_SUBPROCESS_FLAGS_NONE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDIN_PIPE", sizeof("STDIN_PIPE") - 1, G_SUBPROCESS_FLAGS_STDIN_PIPE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDIN_INHERIT", sizeof("STDIN_INHERIT") - 1, G_SUBPROCESS_FLAGS_STDIN_INHERIT);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDOUT_PIPE", sizeof("STDOUT_PIPE") - 1, G_SUBPROCESS_FLAGS_STDOUT_PIPE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDOUT_SILENCE", sizeof("STDOUT_SILENCE") - 1, G_SUBPROCESS_FLAGS_STDOUT_SILENCE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDERR_PIPE", sizeof("STDERR_PIPE") - 1, G_SUBPROCESS_FLAGS_STDERR_PIPE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDERR_SILENCE", sizeof("STDERR_SILENCE") - 1, G_SUBPROCESS_FLAGS_STDERR_SILENCE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "STDERR_MERGE", sizeof("STDERR_MERGE") - 1, G_SUBPROCESS_FLAGS_STDERR_MERGE);
	zend_declare_class_constant_long(gsubprocessflags_ce, "INHERIT_FDS", sizeof("INHERIT_FDS") - 1, G_SUBPROCESS_FLAGS_INHERIT_FDS);

	zend_class_entry tmp_gtlscertificateflags_ce;
	INIT_CLASS_ENTRY(tmp_gtlscertificateflags_ce, "G\\Tls\\Certificate\\Flags", NULL);
	zend_class_entry *gtlscertificateflags_ce = zend_register_internal_class(&tmp_gtlscertificateflags_ce);
	gtlscertificateflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtlscertificateflags_ce, "UNKNOWN_CA", sizeof("UNKNOWN_CA") - 1, G_TLS_CERTIFICATE_UNKNOWN_CA);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "BAD_IDENTITY", sizeof("BAD_IDENTITY") - 1, G_TLS_CERTIFICATE_BAD_IDENTITY);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "NOT_ACTIVATED", sizeof("NOT_ACTIVATED") - 1, G_TLS_CERTIFICATE_NOT_ACTIVATED);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "EXPIRED", sizeof("EXPIRED") - 1, G_TLS_CERTIFICATE_EXPIRED);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "REVOKED", sizeof("REVOKED") - 1, G_TLS_CERTIFICATE_REVOKED);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "INSECURE", sizeof("INSECURE") - 1, G_TLS_CERTIFICATE_INSECURE);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "GENERIC_ERROR", sizeof("GENERIC_ERROR") - 1, G_TLS_CERTIFICATE_GENERIC_ERROR);
	zend_declare_class_constant_long(gtlscertificateflags_ce, "VALIDATE_ALL", sizeof("VALIDATE_ALL") - 1, G_TLS_CERTIFICATE_VALIDATE_ALL);

	zend_class_entry tmp_gtkalign_ce;
	INIT_CLASS_ENTRY(tmp_gtkalign_ce, "Gtk\\Align", NULL);
	zend_class_entry *gtkalign_ce = zend_register_internal_class(&tmp_gtkalign_ce);
	gtkalign_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkalign_ce, "FILL", sizeof("FILL") - 1, GTK_ALIGN_FILL);
	zend_declare_class_constant_long(gtkalign_ce, "START", sizeof("START") - 1, GTK_ALIGN_START);
	zend_declare_class_constant_long(gtkalign_ce, "END", sizeof("END") - 1, GTK_ALIGN_END);
	zend_declare_class_constant_long(gtkalign_ce, "CENTER", sizeof("CENTER") - 1, GTK_ALIGN_CENTER);
	zend_declare_class_constant_long(gtkalign_ce, "BASELINE", sizeof("BASELINE") - 1, GTK_ALIGN_BASELINE);

	zend_class_entry tmp_gtkarrowplacement_ce;
	INIT_CLASS_ENTRY(tmp_gtkarrowplacement_ce, "Gtk\\Arrow\\Placement", NULL);
	zend_class_entry *gtkarrowplacement_ce = zend_register_internal_class(&tmp_gtkarrowplacement_ce);
	gtkarrowplacement_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkarrowplacement_ce, "BOTH", sizeof("BOTH") - 1, GTK_ARROWS_BOTH);
	zend_declare_class_constant_long(gtkarrowplacement_ce, "START", sizeof("START") - 1, GTK_ARROWS_START);
	zend_declare_class_constant_long(gtkarrowplacement_ce, "END", sizeof("END") - 1, GTK_ARROWS_END);

	zend_class_entry tmp_gtkarrowtype_ce;
	INIT_CLASS_ENTRY(tmp_gtkarrowtype_ce, "Gtk\\Arrow\\Type", NULL);
	zend_class_entry *gtkarrowtype_ce = zend_register_internal_class(&tmp_gtkarrowtype_ce);
	gtkarrowtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkarrowtype_ce, "UP", sizeof("UP") - 1, GTK_ARROW_UP);
	zend_declare_class_constant_long(gtkarrowtype_ce, "DOWN", sizeof("DOWN") - 1, GTK_ARROW_DOWN);
	zend_declare_class_constant_long(gtkarrowtype_ce, "LEFT", sizeof("LEFT") - 1, GTK_ARROW_LEFT);
	zend_declare_class_constant_long(gtkarrowtype_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_ARROW_RIGHT);
	zend_declare_class_constant_long(gtkarrowtype_ce, "NONE", sizeof("NONE") - 1, GTK_ARROW_NONE);

	zend_class_entry tmp_gtkassistantpagetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkassistantpagetype_ce, "Gtk\\Assistant\\Page\\Type", NULL);
	zend_class_entry *gtkassistantpagetype_ce = zend_register_internal_class(&tmp_gtkassistantpagetype_ce);
	gtkassistantpagetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "CONTENT", sizeof("CONTENT") - 1, GTK_ASSISTANT_PAGE_CONTENT);
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "INTRO", sizeof("INTRO") - 1, GTK_ASSISTANT_PAGE_INTRO);
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "CONFIRM", sizeof("CONFIRM") - 1, GTK_ASSISTANT_PAGE_CONFIRM);
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "SUMMARY", sizeof("SUMMARY") - 1, GTK_ASSISTANT_PAGE_SUMMARY);
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "PROGRESS", sizeof("PROGRESS") - 1, GTK_ASSISTANT_PAGE_PROGRESS);
	zend_declare_class_constant_long(gtkassistantpagetype_ce, "CUSTOM", sizeof("CUSTOM") - 1, GTK_ASSISTANT_PAGE_CUSTOM);

	zend_class_entry tmp_gtkbaselineposition_ce;
	INIT_CLASS_ENTRY(tmp_gtkbaselineposition_ce, "Gtk\\Baseline\\Position", NULL);
	zend_class_entry *gtkbaselineposition_ce = zend_register_internal_class(&tmp_gtkbaselineposition_ce);
	gtkbaselineposition_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkbaselineposition_ce, "TOP", sizeof("TOP") - 1, GTK_BASELINE_POSITION_TOP);
	zend_declare_class_constant_long(gtkbaselineposition_ce, "CENTER", sizeof("CENTER") - 1, GTK_BASELINE_POSITION_CENTER);
	zend_declare_class_constant_long(gtkbaselineposition_ce, "BOTTOM", sizeof("BOTTOM") - 1, GTK_BASELINE_POSITION_BOTTOM);

	zend_class_entry tmp_gtkborderstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtkborderstyle_ce, "Gtk\\Border\\Style", NULL);
	zend_class_entry *gtkborderstyle_ce = zend_register_internal_class(&tmp_gtkborderstyle_ce);
	gtkborderstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkborderstyle_ce, "NONE", sizeof("NONE") - 1, GTK_BORDER_STYLE_NONE);
	zend_declare_class_constant_long(gtkborderstyle_ce, "SOLID", sizeof("SOLID") - 1, GTK_BORDER_STYLE_SOLID);
	zend_declare_class_constant_long(gtkborderstyle_ce, "INSET", sizeof("INSET") - 1, GTK_BORDER_STYLE_INSET);
	zend_declare_class_constant_long(gtkborderstyle_ce, "OUTSET", sizeof("OUTSET") - 1, GTK_BORDER_STYLE_OUTSET);
	zend_declare_class_constant_long(gtkborderstyle_ce, "HIDDEN", sizeof("HIDDEN") - 1, GTK_BORDER_STYLE_HIDDEN);
	zend_declare_class_constant_long(gtkborderstyle_ce, "DOTTED", sizeof("DOTTED") - 1, GTK_BORDER_STYLE_DOTTED);
	zend_declare_class_constant_long(gtkborderstyle_ce, "DASHED", sizeof("DASHED") - 1, GTK_BORDER_STYLE_DASHED);
	zend_declare_class_constant_long(gtkborderstyle_ce, "DOUBLE", sizeof("DOUBLE") - 1, GTK_BORDER_STYLE_DOUBLE);
	zend_declare_class_constant_long(gtkborderstyle_ce, "GROOVE", sizeof("GROOVE") - 1, GTK_BORDER_STYLE_GROOVE);
	zend_declare_class_constant_long(gtkborderstyle_ce, "RIDGE", sizeof("RIDGE") - 1, GTK_BORDER_STYLE_RIDGE);

	zend_class_entry tmp_gtkbuildererror_ce;
	INIT_CLASS_ENTRY(tmp_gtkbuildererror_ce, "Gtk\\Builder\\Error", NULL);
	zend_class_entry *gtkbuildererror_ce = zend_register_internal_class(&tmp_gtkbuildererror_ce);
	gtkbuildererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_TYPE_FUNCTION", sizeof("INVALID_TYPE_FUNCTION") - 1, GTK_BUILDER_ERROR_INVALID_TYPE_FUNCTION);
	zend_declare_class_constant_long(gtkbuildererror_ce, "UNHANDLED_TAG", sizeof("UNHANDLED_TAG") - 1, GTK_BUILDER_ERROR_UNHANDLED_TAG);
	zend_declare_class_constant_long(gtkbuildererror_ce, "MISSING_ATTRIBUTE", sizeof("MISSING_ATTRIBUTE") - 1, GTK_BUILDER_ERROR_MISSING_ATTRIBUTE);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_ATTRIBUTE", sizeof("INVALID_ATTRIBUTE") - 1, GTK_BUILDER_ERROR_INVALID_ATTRIBUTE);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_TAG", sizeof("INVALID_TAG") - 1, GTK_BUILDER_ERROR_INVALID_TAG);
	zend_declare_class_constant_long(gtkbuildererror_ce, "MISSING_PROPERTY_VALUE", sizeof("MISSING_PROPERTY_VALUE") - 1, GTK_BUILDER_ERROR_MISSING_PROPERTY_VALUE);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_VALUE", sizeof("INVALID_VALUE") - 1, GTK_BUILDER_ERROR_INVALID_VALUE);
	zend_declare_class_constant_long(gtkbuildererror_ce, "VERSION_MISMATCH", sizeof("VERSION_MISMATCH") - 1, GTK_BUILDER_ERROR_VERSION_MISMATCH);
	zend_declare_class_constant_long(gtkbuildererror_ce, "DUPLICATE_ID", sizeof("DUPLICATE_ID") - 1, GTK_BUILDER_ERROR_DUPLICATE_ID);
	zend_declare_class_constant_long(gtkbuildererror_ce, "OBJECT_TYPE_REFUSED", sizeof("OBJECT_TYPE_REFUSED") - 1, GTK_BUILDER_ERROR_OBJECT_TYPE_REFUSED);
	zend_declare_class_constant_long(gtkbuildererror_ce, "TEMPLATE_MISMATCH", sizeof("TEMPLATE_MISMATCH") - 1, GTK_BUILDER_ERROR_TEMPLATE_MISMATCH);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_PROPERTY", sizeof("INVALID_PROPERTY") - 1, GTK_BUILDER_ERROR_INVALID_PROPERTY);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_SIGNAL", sizeof("INVALID_SIGNAL") - 1, GTK_BUILDER_ERROR_INVALID_SIGNAL);
	zend_declare_class_constant_long(gtkbuildererror_ce, "INVALID_ID", sizeof("INVALID_ID") - 1, GTK_BUILDER_ERROR_INVALID_ID);

	zend_class_entry tmp_gtkbuttonboxstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtkbuttonboxstyle_ce, "Gtk\\Button\\Box\\Style", NULL);
	zend_class_entry *gtkbuttonboxstyle_ce = zend_register_internal_class(&tmp_gtkbuttonboxstyle_ce);
	gtkbuttonboxstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "SPREAD", sizeof("SPREAD") - 1, GTK_BUTTONBOX_SPREAD);
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "EDGE", sizeof("EDGE") - 1, GTK_BUTTONBOX_EDGE);
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "START", sizeof("START") - 1, GTK_BUTTONBOX_START);
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "END", sizeof("END") - 1, GTK_BUTTONBOX_END);
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "CENTER", sizeof("CENTER") - 1, GTK_BUTTONBOX_CENTER);
	zend_declare_class_constant_long(gtkbuttonboxstyle_ce, "EXPAND", sizeof("EXPAND") - 1, GTK_BUTTONBOX_EXPAND);

	zend_class_entry tmp_gtkbuttonrole_ce;
	INIT_CLASS_ENTRY(tmp_gtkbuttonrole_ce, "Gtk\\Button\\Role", NULL);
	zend_class_entry *gtkbuttonrole_ce = zend_register_internal_class(&tmp_gtkbuttonrole_ce);
	gtkbuttonrole_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkbuttonrole_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_BUTTON_ROLE_NORMAL);
	zend_declare_class_constant_long(gtkbuttonrole_ce, "CHECK", sizeof("CHECK") - 1, GTK_BUTTON_ROLE_CHECK);
	zend_declare_class_constant_long(gtkbuttonrole_ce, "RADIO", sizeof("RADIO") - 1, GTK_BUTTON_ROLE_RADIO);

	zend_class_entry tmp_gtkbuttonstype_ce;
	INIT_CLASS_ENTRY(tmp_gtkbuttonstype_ce, "Gtk\\Buttons\\Type", NULL);
	zend_class_entry *gtkbuttonstype_ce = zend_register_internal_class(&tmp_gtkbuttonstype_ce);
	gtkbuttonstype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkbuttonstype_ce, "NONE", sizeof("NONE") - 1, GTK_BUTTONS_NONE);
	zend_declare_class_constant_long(gtkbuttonstype_ce, "OK", sizeof("OK") - 1, GTK_BUTTONS_OK);
	zend_declare_class_constant_long(gtkbuttonstype_ce, "CLOSE", sizeof("CLOSE") - 1, GTK_BUTTONS_CLOSE);
	zend_declare_class_constant_long(gtkbuttonstype_ce, "CANCEL", sizeof("CANCEL") - 1, GTK_BUTTONS_CANCEL);
	zend_declare_class_constant_long(gtkbuttonstype_ce, "YES_NO", sizeof("YES_NO") - 1, GTK_BUTTONS_YES_NO);
	zend_declare_class_constant_long(gtkbuttonstype_ce, "OK_CANCEL", sizeof("OK_CANCEL") - 1, GTK_BUTTONS_OK_CANCEL);

	zend_class_entry tmp_gtkcellrendereraccelmode_ce;
	INIT_CLASS_ENTRY(tmp_gtkcellrendereraccelmode_ce, "Gtk\\Cell\\Renderer\\Accel\\Mode", NULL);
	zend_class_entry *gtkcellrendereraccelmode_ce = zend_register_internal_class(&tmp_gtkcellrendereraccelmode_ce);
	gtkcellrendereraccelmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcellrendereraccelmode_ce, "GTK", sizeof("GTK") - 1, GTK_CELL_RENDERER_ACCEL_MODE_GTK);
	zend_declare_class_constant_long(gtkcellrendereraccelmode_ce, "OTHER", sizeof("OTHER") - 1, GTK_CELL_RENDERER_ACCEL_MODE_OTHER);

	zend_class_entry tmp_gtkcellrenderermode_ce;
	INIT_CLASS_ENTRY(tmp_gtkcellrenderermode_ce, "Gtk\\Cell\\Renderer\\Mode", NULL);
	zend_class_entry *gtkcellrenderermode_ce = zend_register_internal_class(&tmp_gtkcellrenderermode_ce);
	gtkcellrenderermode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcellrenderermode_ce, "INERT", sizeof("INERT") - 1, GTK_CELL_RENDERER_MODE_INERT);
	zend_declare_class_constant_long(gtkcellrenderermode_ce, "ACTIVATABLE", sizeof("ACTIVATABLE") - 1, GTK_CELL_RENDERER_MODE_ACTIVATABLE);
	zend_declare_class_constant_long(gtkcellrenderermode_ce, "EDITABLE", sizeof("EDITABLE") - 1, GTK_CELL_RENDERER_MODE_EDITABLE);

	zend_class_entry tmp_gtkcornertype_ce;
	INIT_CLASS_ENTRY(tmp_gtkcornertype_ce, "Gtk\\Corner\\Type", NULL);
	zend_class_entry *gtkcornertype_ce = zend_register_internal_class(&tmp_gtkcornertype_ce);
	gtkcornertype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcornertype_ce, "TOP_LEFT", sizeof("TOP_LEFT") - 1, GTK_CORNER_TOP_LEFT);
	zend_declare_class_constant_long(gtkcornertype_ce, "BOTTOM_LEFT", sizeof("BOTTOM_LEFT") - 1, GTK_CORNER_BOTTOM_LEFT);
	zend_declare_class_constant_long(gtkcornertype_ce, "TOP_RIGHT", sizeof("TOP_RIGHT") - 1, GTK_CORNER_TOP_RIGHT);
	zend_declare_class_constant_long(gtkcornertype_ce, "BOTTOM_RIGHT", sizeof("BOTTOM_RIGHT") - 1, GTK_CORNER_BOTTOM_RIGHT);

	zend_class_entry tmp_gtkcssprovidererror_ce;
	INIT_CLASS_ENTRY(tmp_gtkcssprovidererror_ce, "Gtk\\Css\\Provider\\Error", NULL);
	zend_class_entry *gtkcssprovidererror_ce = zend_register_internal_class(&tmp_gtkcssprovidererror_ce);
	gtkcssprovidererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "FAILED", sizeof("FAILED") - 1, GTK_CSS_PROVIDER_ERROR_FAILED);
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "SYNTAX", sizeof("SYNTAX") - 1, GTK_CSS_PROVIDER_ERROR_SYNTAX);
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "IMPORT", sizeof("IMPORT") - 1, GTK_CSS_PROVIDER_ERROR_IMPORT);
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "NAME", sizeof("NAME") - 1, GTK_CSS_PROVIDER_ERROR_NAME);
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "DEPRECATED", sizeof("DEPRECATED") - 1, GTK_CSS_PROVIDER_ERROR_DEPRECATED);
	zend_declare_class_constant_long(gtkcssprovidererror_ce, "UNKNOWN_VALUE", sizeof("UNKNOWN_VALUE") - 1, GTK_CSS_PROVIDER_ERROR_UNKNOWN_VALUE);

	zend_class_entry tmp_gtkcsssectiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkcsssectiontype_ce, "Gtk\\Css\\Section\\Type", NULL);
	zend_class_entry *gtkcsssectiontype_ce = zend_register_internal_class(&tmp_gtkcsssectiontype_ce);
	gtkcsssectiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "DOCUMENT", sizeof("DOCUMENT") - 1, GTK_CSS_SECTION_DOCUMENT);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "IMPORT", sizeof("IMPORT") - 1, GTK_CSS_SECTION_IMPORT);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "COLOR_DEFINITION", sizeof("COLOR_DEFINITION") - 1, GTK_CSS_SECTION_COLOR_DEFINITION);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "BINDING_SET", sizeof("BINDING_SET") - 1, GTK_CSS_SECTION_BINDING_SET);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "RULESET", sizeof("RULESET") - 1, GTK_CSS_SECTION_RULESET);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "SELECTOR", sizeof("SELECTOR") - 1, GTK_CSS_SECTION_SELECTOR);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "DECLARATION", sizeof("DECLARATION") - 1, GTK_CSS_SECTION_DECLARATION);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "VALUE", sizeof("VALUE") - 1, GTK_CSS_SECTION_VALUE);
	zend_declare_class_constant_long(gtkcsssectiontype_ce, "KEYFRAMES", sizeof("KEYFRAMES") - 1, GTK_CSS_SECTION_KEYFRAMES);

	zend_class_entry tmp_gtkdeletetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkdeletetype_ce, "Gtk\\Delete\\Type", NULL);
	zend_class_entry *gtkdeletetype_ce = zend_register_internal_class(&tmp_gtkdeletetype_ce);
	gtkdeletetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdeletetype_ce, "CHARS", sizeof("CHARS") - 1, GTK_DELETE_CHARS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "WORD_ENDS", sizeof("WORD_ENDS") - 1, GTK_DELETE_WORD_ENDS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "WORDS", sizeof("WORDS") - 1, GTK_DELETE_WORDS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "DISPLAY_LINES", sizeof("DISPLAY_LINES") - 1, GTK_DELETE_DISPLAY_LINES);
	zend_declare_class_constant_long(gtkdeletetype_ce, "DISPLAY_LINE_ENDS", sizeof("DISPLAY_LINE_ENDS") - 1, GTK_DELETE_DISPLAY_LINE_ENDS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "PARAGRAPH_ENDS", sizeof("PARAGRAPH_ENDS") - 1, GTK_DELETE_PARAGRAPH_ENDS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "PARAGRAPHS", sizeof("PARAGRAPHS") - 1, GTK_DELETE_PARAGRAPHS);
	zend_declare_class_constant_long(gtkdeletetype_ce, "WHITESPACE", sizeof("WHITESPACE") - 1, GTK_DELETE_WHITESPACE);

	zend_class_entry tmp_gtkdirectiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkdirectiontype_ce, "Gtk\\Direction\\Type", NULL);
	zend_class_entry *gtkdirectiontype_ce = zend_register_internal_class(&tmp_gtkdirectiontype_ce);
	gtkdirectiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdirectiontype_ce, "TAB_FORWARD", sizeof("TAB_FORWARD") - 1, GTK_DIR_TAB_FORWARD);
	zend_declare_class_constant_long(gtkdirectiontype_ce, "TAB_BACKWARD", sizeof("TAB_BACKWARD") - 1, GTK_DIR_TAB_BACKWARD);
	zend_declare_class_constant_long(gtkdirectiontype_ce, "UP", sizeof("UP") - 1, GTK_DIR_UP);
	zend_declare_class_constant_long(gtkdirectiontype_ce, "DOWN", sizeof("DOWN") - 1, GTK_DIR_DOWN);
	zend_declare_class_constant_long(gtkdirectiontype_ce, "LEFT", sizeof("LEFT") - 1, GTK_DIR_LEFT);
	zend_declare_class_constant_long(gtkdirectiontype_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_DIR_RIGHT);

	zend_class_entry tmp_gtkdragresult_ce;
	INIT_CLASS_ENTRY(tmp_gtkdragresult_ce, "Gtk\\Drag\\Result", NULL);
	zend_class_entry *gtkdragresult_ce = zend_register_internal_class(&tmp_gtkdragresult_ce);
	gtkdragresult_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdragresult_ce, "SUCCESS", sizeof("SUCCESS") - 1, GTK_DRAG_RESULT_SUCCESS);
	zend_declare_class_constant_long(gtkdragresult_ce, "NO_TARGET", sizeof("NO_TARGET") - 1, GTK_DRAG_RESULT_NO_TARGET);
	zend_declare_class_constant_long(gtkdragresult_ce, "USER_CANCELLED", sizeof("USER_CANCELLED") - 1, GTK_DRAG_RESULT_USER_CANCELLED);
	zend_declare_class_constant_long(gtkdragresult_ce, "TIMEOUT_EXPIRED", sizeof("TIMEOUT_EXPIRED") - 1, GTK_DRAG_RESULT_TIMEOUT_EXPIRED);
	zend_declare_class_constant_long(gtkdragresult_ce, "GRAB_BROKEN", sizeof("GRAB_BROKEN") - 1, GTK_DRAG_RESULT_GRAB_BROKEN);
	zend_declare_class_constant_long(gtkdragresult_ce, "ERROR", sizeof("ERROR") - 1, GTK_DRAG_RESULT_ERROR);

	zend_class_entry tmp_gtkentryiconposition_ce;
	INIT_CLASS_ENTRY(tmp_gtkentryiconposition_ce, "Gtk\\Entry\\Icon\\Position", NULL);
	zend_class_entry *gtkentryiconposition_ce = zend_register_internal_class(&tmp_gtkentryiconposition_ce);
	gtkentryiconposition_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkentryiconposition_ce, "PRIMARY", sizeof("PRIMARY") - 1, GTK_ENTRY_ICON_PRIMARY);
	zend_declare_class_constant_long(gtkentryiconposition_ce, "SECONDARY", sizeof("SECONDARY") - 1, GTK_ENTRY_ICON_SECONDARY);

	zend_class_entry tmp_gtkeventsequencestate_ce;
	INIT_CLASS_ENTRY(tmp_gtkeventsequencestate_ce, "Gtk\\Event\\Sequence\\State", NULL);
	zend_class_entry *gtkeventsequencestate_ce = zend_register_internal_class(&tmp_gtkeventsequencestate_ce);
	gtkeventsequencestate_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkeventsequencestate_ce, "NONE", sizeof("NONE") - 1, GTK_EVENT_SEQUENCE_NONE);
	zend_declare_class_constant_long(gtkeventsequencestate_ce, "CLAIMED", sizeof("CLAIMED") - 1, GTK_EVENT_SEQUENCE_CLAIMED);
	zend_declare_class_constant_long(gtkeventsequencestate_ce, "DENIED", sizeof("DENIED") - 1, GTK_EVENT_SEQUENCE_DENIED);

	zend_class_entry tmp_gtkfilechooseraction_ce;
	INIT_CLASS_ENTRY(tmp_gtkfilechooseraction_ce, "Gtk\\File\\Chooser\\Action", NULL);
	zend_class_entry *gtkfilechooseraction_ce = zend_register_internal_class(&tmp_gtkfilechooseraction_ce);
	gtkfilechooseraction_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkfilechooseraction_ce, "OPEN", sizeof("OPEN") - 1, GTK_FILE_CHOOSER_ACTION_OPEN);
	zend_declare_class_constant_long(gtkfilechooseraction_ce, "SAVE", sizeof("SAVE") - 1, GTK_FILE_CHOOSER_ACTION_SAVE);
	zend_declare_class_constant_long(gtkfilechooseraction_ce, "SELECT_FOLDER", sizeof("SELECT_FOLDER") - 1, GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	zend_declare_class_constant_long(gtkfilechooseraction_ce, "CREATE_FOLDER", sizeof("CREATE_FOLDER") - 1, GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER);

	zend_class_entry tmp_gtkfilechooserconfirmation_ce;
	INIT_CLASS_ENTRY(tmp_gtkfilechooserconfirmation_ce, "Gtk\\File\\Chooser\\Confirmation", NULL);
	zend_class_entry *gtkfilechooserconfirmation_ce = zend_register_internal_class(&tmp_gtkfilechooserconfirmation_ce);
	gtkfilechooserconfirmation_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkfilechooserconfirmation_ce, "CONFIRM", sizeof("CONFIRM") - 1, GTK_FILE_CHOOSER_CONFIRMATION_CONFIRM);
	zend_declare_class_constant_long(gtkfilechooserconfirmation_ce, "ACCEPT_FILENAME", sizeof("ACCEPT_FILENAME") - 1, GTK_FILE_CHOOSER_CONFIRMATION_ACCEPT_FILENAME);
	zend_declare_class_constant_long(gtkfilechooserconfirmation_ce, "SELECT_AGAIN", sizeof("SELECT_AGAIN") - 1, GTK_FILE_CHOOSER_CONFIRMATION_SELECT_AGAIN);

	zend_class_entry tmp_gtkfilechoosererror_ce;
	INIT_CLASS_ENTRY(tmp_gtkfilechoosererror_ce, "Gtk\\File\\Chooser\\Error", NULL);
	zend_class_entry *gtkfilechoosererror_ce = zend_register_internal_class(&tmp_gtkfilechoosererror_ce);
	gtkfilechoosererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkfilechoosererror_ce, "NONEXISTENT", sizeof("NONEXISTENT") - 1, GTK_FILE_CHOOSER_ERROR_NONEXISTENT);
	zend_declare_class_constant_long(gtkfilechoosererror_ce, "BAD_FILENAME", sizeof("BAD_FILENAME") - 1, GTK_FILE_CHOOSER_ERROR_BAD_FILENAME);
	zend_declare_class_constant_long(gtkfilechoosererror_ce, "ALREADY_EXISTS", sizeof("ALREADY_EXISTS") - 1, GTK_FILE_CHOOSER_ERROR_ALREADY_EXISTS);
	zend_declare_class_constant_long(gtkfilechoosererror_ce, "INCOMPLETE_HOSTNAME", sizeof("INCOMPLETE_HOSTNAME") - 1, GTK_FILE_CHOOSER_ERROR_INCOMPLETE_HOSTNAME);

	zend_class_entry tmp_gtkiconsize_ce;
	INIT_CLASS_ENTRY(tmp_gtkiconsize_ce, "Gtk\\Icon\\Size", NULL);
	zend_class_entry *gtkiconsize_ce = zend_register_internal_class(&tmp_gtkiconsize_ce);
	gtkiconsize_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkiconsize_ce, "INVALID", sizeof("INVALID") - 1, GTK_ICON_SIZE_INVALID);
	zend_declare_class_constant_long(gtkiconsize_ce, "MENU", sizeof("MENU") - 1, GTK_ICON_SIZE_MENU);
	zend_declare_class_constant_long(gtkiconsize_ce, "SMALL_TOOLBAR", sizeof("SMALL_TOOLBAR") - 1, GTK_ICON_SIZE_SMALL_TOOLBAR);
	zend_declare_class_constant_long(gtkiconsize_ce, "LARGE_TOOLBAR", sizeof("LARGE_TOOLBAR") - 1, GTK_ICON_SIZE_LARGE_TOOLBAR);
	zend_declare_class_constant_long(gtkiconsize_ce, "BUTTON", sizeof("BUTTON") - 1, GTK_ICON_SIZE_BUTTON);
	zend_declare_class_constant_long(gtkiconsize_ce, "DND", sizeof("DND") - 1, GTK_ICON_SIZE_DND);
	zend_declare_class_constant_long(gtkiconsize_ce, "DIALOG", sizeof("DIALOG") - 1, GTK_ICON_SIZE_DIALOG);

	zend_class_entry tmp_gtkiconthemeerror_ce;
	INIT_CLASS_ENTRY(tmp_gtkiconthemeerror_ce, "Gtk\\Icon\\Theme\\Error", NULL);
	zend_class_entry *gtkiconthemeerror_ce = zend_register_internal_class(&tmp_gtkiconthemeerror_ce);
	gtkiconthemeerror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkiconthemeerror_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, GTK_ICON_THEME_NOT_FOUND);
	zend_declare_class_constant_long(gtkiconthemeerror_ce, "FAILED", sizeof("FAILED") - 1, GTK_ICON_THEME_FAILED);

	zend_class_entry tmp_gtkiconviewdropposition_ce;
	INIT_CLASS_ENTRY(tmp_gtkiconviewdropposition_ce, "Gtk\\Icon\\View\\Drop\\Position", NULL);
	zend_class_entry *gtkiconviewdropposition_ce = zend_register_internal_class(&tmp_gtkiconviewdropposition_ce);
	gtkiconviewdropposition_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "NO_DROP", sizeof("NO_DROP") - 1, GTK_ICON_VIEW_NO_DROP);
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "DROP_INTO", sizeof("DROP_INTO") - 1, GTK_ICON_VIEW_DROP_INTO);
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "DROP_LEFT", sizeof("DROP_LEFT") - 1, GTK_ICON_VIEW_DROP_LEFT);
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "DROP_RIGHT", sizeof("DROP_RIGHT") - 1, GTK_ICON_VIEW_DROP_RIGHT);
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "DROP_ABOVE", sizeof("DROP_ABOVE") - 1, GTK_ICON_VIEW_DROP_ABOVE);
	zend_declare_class_constant_long(gtkiconviewdropposition_ce, "DROP_BELOW", sizeof("DROP_BELOW") - 1, GTK_ICON_VIEW_DROP_BELOW);

	zend_class_entry tmp_gtkimagetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkimagetype_ce, "Gtk\\Image\\Type", NULL);
	zend_class_entry *gtkimagetype_ce = zend_register_internal_class(&tmp_gtkimagetype_ce);
	gtkimagetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkimagetype_ce, "EMPTY", sizeof("EMPTY") - 1, GTK_IMAGE_EMPTY);
	zend_declare_class_constant_long(gtkimagetype_ce, "PIXBUF", sizeof("PIXBUF") - 1, GTK_IMAGE_PIXBUF);
	zend_declare_class_constant_long(gtkimagetype_ce, "STOCK", sizeof("STOCK") - 1, GTK_IMAGE_STOCK);
	zend_declare_class_constant_long(gtkimagetype_ce, "ICON_SET", sizeof("ICON_SET") - 1, GTK_IMAGE_ICON_SET);
	zend_declare_class_constant_long(gtkimagetype_ce, "ANIMATION", sizeof("ANIMATION") - 1, GTK_IMAGE_ANIMATION);
	zend_declare_class_constant_long(gtkimagetype_ce, "ICON_NAME", sizeof("ICON_NAME") - 1, GTK_IMAGE_ICON_NAME);
	zend_declare_class_constant_long(gtkimagetype_ce, "GICON", sizeof("GICON") - 1, GTK_IMAGE_GICON);
	zend_declare_class_constant_long(gtkimagetype_ce, "SURFACE", sizeof("SURFACE") - 1, GTK_IMAGE_SURFACE);

	zend_class_entry tmp_gtkimpreeditstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtkimpreeditstyle_ce, "Gtk\\I\\M\\Preedit\\Style", NULL);
	zend_class_entry *gtkimpreeditstyle_ce = zend_register_internal_class(&tmp_gtkimpreeditstyle_ce);
	gtkimpreeditstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkimpreeditstyle_ce, "NOTHING", sizeof("NOTHING") - 1, GTK_IM_PREEDIT_NOTHING);
	zend_declare_class_constant_long(gtkimpreeditstyle_ce, "CALLBACK", sizeof("CALLBACK") - 1, GTK_IM_PREEDIT_CALLBACK);
	zend_declare_class_constant_long(gtkimpreeditstyle_ce, "NONE", sizeof("NONE") - 1, GTK_IM_PREEDIT_NONE);

	zend_class_entry tmp_gtkimstatusstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtkimstatusstyle_ce, "Gtk\\I\\M\\Status\\Style", NULL);
	zend_class_entry *gtkimstatusstyle_ce = zend_register_internal_class(&tmp_gtkimstatusstyle_ce);
	gtkimstatusstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkimstatusstyle_ce, "NOTHING", sizeof("NOTHING") - 1, GTK_IM_STATUS_NOTHING);
	zend_declare_class_constant_long(gtkimstatusstyle_ce, "CALLBACK", sizeof("CALLBACK") - 1, GTK_IM_STATUS_CALLBACK);
	zend_declare_class_constant_long(gtkimstatusstyle_ce, "NONE", sizeof("NONE") - 1, GTK_IM_STATUS_NONE);

	zend_class_entry tmp_gtkinputpurpose_ce;
	INIT_CLASS_ENTRY(tmp_gtkinputpurpose_ce, "Gtk\\Input\\Purpose", NULL);
	zend_class_entry *gtkinputpurpose_ce = zend_register_internal_class(&tmp_gtkinputpurpose_ce);
	gtkinputpurpose_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkinputpurpose_ce, "FREE_FORM", sizeof("FREE_FORM") - 1, GTK_INPUT_PURPOSE_FREE_FORM);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "ALPHA", sizeof("ALPHA") - 1, GTK_INPUT_PURPOSE_ALPHA);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "DIGITS", sizeof("DIGITS") - 1, GTK_INPUT_PURPOSE_DIGITS);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "NUMBER", sizeof("NUMBER") - 1, GTK_INPUT_PURPOSE_NUMBER);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "PHONE", sizeof("PHONE") - 1, GTK_INPUT_PURPOSE_PHONE);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "URL", sizeof("URL") - 1, GTK_INPUT_PURPOSE_URL);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "EMAIL", sizeof("EMAIL") - 1, GTK_INPUT_PURPOSE_EMAIL);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "NAME", sizeof("NAME") - 1, GTK_INPUT_PURPOSE_NAME);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "PASSWORD", sizeof("PASSWORD") - 1, GTK_INPUT_PURPOSE_PASSWORD);
	zend_declare_class_constant_long(gtkinputpurpose_ce, "PIN", sizeof("PIN") - 1, GTK_INPUT_PURPOSE_PIN);

	zend_class_entry tmp_gtkjustification_ce;
	INIT_CLASS_ENTRY(tmp_gtkjustification_ce, "Gtk\\Justification", NULL);
	zend_class_entry *gtkjustification_ce = zend_register_internal_class(&tmp_gtkjustification_ce);
	gtkjustification_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkjustification_ce, "LEFT", sizeof("LEFT") - 1, GTK_JUSTIFY_LEFT);
	zend_declare_class_constant_long(gtkjustification_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_JUSTIFY_RIGHT);
	zend_declare_class_constant_long(gtkjustification_ce, "CENTER", sizeof("CENTER") - 1, GTK_JUSTIFY_CENTER);
	zend_declare_class_constant_long(gtkjustification_ce, "FILL", sizeof("FILL") - 1, GTK_JUSTIFY_FILL);

	zend_class_entry tmp_gtklevelbarmode_ce;
	INIT_CLASS_ENTRY(tmp_gtklevelbarmode_ce, "Gtk\\Level\\Bar\\Mode", NULL);
	zend_class_entry *gtklevelbarmode_ce = zend_register_internal_class(&tmp_gtklevelbarmode_ce);
	gtklevelbarmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtklevelbarmode_ce, "CONTINUOUS", sizeof("CONTINUOUS") - 1, GTK_LEVEL_BAR_MODE_CONTINUOUS);
	zend_declare_class_constant_long(gtklevelbarmode_ce, "DISCRETE", sizeof("DISCRETE") - 1, GTK_LEVEL_BAR_MODE_DISCRETE);

	zend_class_entry tmp_gtklicense_ce;
	INIT_CLASS_ENTRY(tmp_gtklicense_ce, "Gtk\\License", NULL);
	zend_class_entry *gtklicense_ce = zend_register_internal_class(&tmp_gtklicense_ce);
	gtklicense_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtklicense_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, GTK_LICENSE_UNKNOWN);
	zend_declare_class_constant_long(gtklicense_ce, "CUSTOM", sizeof("CUSTOM") - 1, GTK_LICENSE_CUSTOM);
	zend_declare_class_constant_long(gtklicense_ce, "GPL_2_0", sizeof("GPL_2_0") - 1, GTK_LICENSE_GPL_2_0);
	zend_declare_class_constant_long(gtklicense_ce, "GPL_3_0", sizeof("GPL_3_0") - 1, GTK_LICENSE_GPL_3_0);
	zend_declare_class_constant_long(gtklicense_ce, "LGPL_2_1", sizeof("LGPL_2_1") - 1, GTK_LICENSE_LGPL_2_1);
	zend_declare_class_constant_long(gtklicense_ce, "LGPL_3_0", sizeof("LGPL_3_0") - 1, GTK_LICENSE_LGPL_3_0);
	zend_declare_class_constant_long(gtklicense_ce, "BSD", sizeof("BSD") - 1, GTK_LICENSE_BSD);
	zend_declare_class_constant_long(gtklicense_ce, "MIT_X11", sizeof("MIT_X11") - 1, GTK_LICENSE_MIT_X11);
	zend_declare_class_constant_long(gtklicense_ce, "ARTISTIC", sizeof("ARTISTIC") - 1, GTK_LICENSE_ARTISTIC);
	zend_declare_class_constant_long(gtklicense_ce, "GPL_2_0_ONLY", sizeof("GPL_2_0_ONLY") - 1, GTK_LICENSE_GPL_2_0_ONLY);
	zend_declare_class_constant_long(gtklicense_ce, "GPL_3_0_ONLY", sizeof("GPL_3_0_ONLY") - 1, GTK_LICENSE_GPL_3_0_ONLY);
	zend_declare_class_constant_long(gtklicense_ce, "LGPL_2_1_ONLY", sizeof("LGPL_2_1_ONLY") - 1, GTK_LICENSE_LGPL_2_1_ONLY);
	zend_declare_class_constant_long(gtklicense_ce, "LGPL_3_0_ONLY", sizeof("LGPL_3_0_ONLY") - 1, GTK_LICENSE_LGPL_3_0_ONLY);
	zend_declare_class_constant_long(gtklicense_ce, "AGPL_3_0", sizeof("AGPL_3_0") - 1, GTK_LICENSE_AGPL_3_0);
	zend_declare_class_constant_long(gtklicense_ce, "AGPL_3_0_ONLY", sizeof("AGPL_3_0_ONLY") - 1, GTK_LICENSE_AGPL_3_0_ONLY);

	zend_class_entry tmp_gtkmenudirectiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkmenudirectiontype_ce, "Gtk\\Menu\\Direction\\Type", NULL);
	zend_class_entry *gtkmenudirectiontype_ce = zend_register_internal_class(&tmp_gtkmenudirectiontype_ce);
	gtkmenudirectiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkmenudirectiontype_ce, "PARENT", sizeof("PARENT") - 1, GTK_MENU_DIR_PARENT);
	zend_declare_class_constant_long(gtkmenudirectiontype_ce, "CHILD", sizeof("CHILD") - 1, GTK_MENU_DIR_CHILD);
	zend_declare_class_constant_long(gtkmenudirectiontype_ce, "NEXT", sizeof("NEXT") - 1, GTK_MENU_DIR_NEXT);
	zend_declare_class_constant_long(gtkmenudirectiontype_ce, "PREV", sizeof("PREV") - 1, GTK_MENU_DIR_PREV);

	zend_class_entry tmp_gtkmessagetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkmessagetype_ce, "Gtk\\Message\\Type", NULL);
	zend_class_entry *gtkmessagetype_ce = zend_register_internal_class(&tmp_gtkmessagetype_ce);
	gtkmessagetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkmessagetype_ce, "INFO", sizeof("INFO") - 1, GTK_MESSAGE_INFO);
	zend_declare_class_constant_long(gtkmessagetype_ce, "WARNING", sizeof("WARNING") - 1, GTK_MESSAGE_WARNING);
	zend_declare_class_constant_long(gtkmessagetype_ce, "QUESTION", sizeof("QUESTION") - 1, GTK_MESSAGE_QUESTION);
	zend_declare_class_constant_long(gtkmessagetype_ce, "ERROR", sizeof("ERROR") - 1, GTK_MESSAGE_ERROR);
	zend_declare_class_constant_long(gtkmessagetype_ce, "OTHER", sizeof("OTHER") - 1, GTK_MESSAGE_OTHER);

	zend_class_entry tmp_gtkmovementstep_ce;
	INIT_CLASS_ENTRY(tmp_gtkmovementstep_ce, "Gtk\\Movement\\Step", NULL);
	zend_class_entry *gtkmovementstep_ce = zend_register_internal_class(&tmp_gtkmovementstep_ce);
	gtkmovementstep_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkmovementstep_ce, "LOGICAL_POSITIONS", sizeof("LOGICAL_POSITIONS") - 1, GTK_MOVEMENT_LOGICAL_POSITIONS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "VISUAL_POSITIONS", sizeof("VISUAL_POSITIONS") - 1, GTK_MOVEMENT_VISUAL_POSITIONS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "WORDS", sizeof("WORDS") - 1, GTK_MOVEMENT_WORDS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "DISPLAY_LINES", sizeof("DISPLAY_LINES") - 1, GTK_MOVEMENT_DISPLAY_LINES);
	zend_declare_class_constant_long(gtkmovementstep_ce, "DISPLAY_LINE_ENDS", sizeof("DISPLAY_LINE_ENDS") - 1, GTK_MOVEMENT_DISPLAY_LINE_ENDS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "PARAGRAPHS", sizeof("PARAGRAPHS") - 1, GTK_MOVEMENT_PARAGRAPHS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "PARAGRAPH_ENDS", sizeof("PARAGRAPH_ENDS") - 1, GTK_MOVEMENT_PARAGRAPH_ENDS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "PAGES", sizeof("PAGES") - 1, GTK_MOVEMENT_PAGES);
	zend_declare_class_constant_long(gtkmovementstep_ce, "BUFFER_ENDS", sizeof("BUFFER_ENDS") - 1, GTK_MOVEMENT_BUFFER_ENDS);
	zend_declare_class_constant_long(gtkmovementstep_ce, "HORIZONTAL_PAGES", sizeof("HORIZONTAL_PAGES") - 1, GTK_MOVEMENT_HORIZONTAL_PAGES);

	zend_class_entry tmp_gtknotebooktab_ce;
	INIT_CLASS_ENTRY(tmp_gtknotebooktab_ce, "Gtk\\Notebook\\Tab", NULL);
	zend_class_entry *gtknotebooktab_ce = zend_register_internal_class(&tmp_gtknotebooktab_ce);
	gtknotebooktab_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtknotebooktab_ce, "FIRST", sizeof("FIRST") - 1, GTK_NOTEBOOK_TAB_FIRST);
	zend_declare_class_constant_long(gtknotebooktab_ce, "LAST", sizeof("LAST") - 1, GTK_NOTEBOOK_TAB_LAST);

	zend_class_entry tmp_gtknumberuplayout_ce;
	INIT_CLASS_ENTRY(tmp_gtknumberuplayout_ce, "Gtk\\Number\\Up\\Layout", NULL);
	zend_class_entry *gtknumberuplayout_ce = zend_register_internal_class(&tmp_gtknumberuplayout_ce);
	gtknumberuplayout_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtknumberuplayout_ce, "LEFT_TO_RIGHT_TOP_TO_BOTTOM", sizeof("LEFT_TO_RIGHT_TOP_TO_BOTTOM") - 1, GTK_NUMBER_UP_LAYOUT_LEFT_TO_RIGHT_TOP_TO_BOTTOM);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "LEFT_TO_RIGHT_BOTTOM_TO_TOP", sizeof("LEFT_TO_RIGHT_BOTTOM_TO_TOP") - 1, GTK_NUMBER_UP_LAYOUT_LEFT_TO_RIGHT_BOTTOM_TO_TOP);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "RIGHT_TO_LEFT_TOP_TO_BOTTOM", sizeof("RIGHT_TO_LEFT_TOP_TO_BOTTOM") - 1, GTK_NUMBER_UP_LAYOUT_RIGHT_TO_LEFT_TOP_TO_BOTTOM);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "RIGHT_TO_LEFT_BOTTOM_TO_TOP", sizeof("RIGHT_TO_LEFT_BOTTOM_TO_TOP") - 1, GTK_NUMBER_UP_LAYOUT_RIGHT_TO_LEFT_BOTTOM_TO_TOP);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "TOP_TO_BOTTOM_LEFT_TO_RIGHT", sizeof("TOP_TO_BOTTOM_LEFT_TO_RIGHT") - 1, GTK_NUMBER_UP_LAYOUT_TOP_TO_BOTTOM_LEFT_TO_RIGHT);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "TOP_TO_BOTTOM_RIGHT_TO_LEFT", sizeof("TOP_TO_BOTTOM_RIGHT_TO_LEFT") - 1, GTK_NUMBER_UP_LAYOUT_TOP_TO_BOTTOM_RIGHT_TO_LEFT);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "BOTTOM_TO_TOP_LEFT_TO_RIGHT", sizeof("BOTTOM_TO_TOP_LEFT_TO_RIGHT") - 1, GTK_NUMBER_UP_LAYOUT_BOTTOM_TO_TOP_LEFT_TO_RIGHT);
	zend_declare_class_constant_long(gtknumberuplayout_ce, "BOTTOM_TO_TOP_RIGHT_TO_LEFT", sizeof("BOTTOM_TO_TOP_RIGHT_TO_LEFT") - 1, GTK_NUMBER_UP_LAYOUT_BOTTOM_TO_TOP_RIGHT_TO_LEFT);

	zend_class_entry tmp_gtkorientation_ce;
	INIT_CLASS_ENTRY(tmp_gtkorientation_ce, "Gtk\\Orientation", NULL);
	zend_class_entry *gtkorientation_ce = zend_register_internal_class(&tmp_gtkorientation_ce);
	gtkorientation_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkorientation_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, GTK_ORIENTATION_HORIZONTAL);
	zend_declare_class_constant_long(gtkorientation_ce, "VERTICAL", sizeof("VERTICAL") - 1, GTK_ORIENTATION_VERTICAL);

	zend_class_entry tmp_gtkpackdirection_ce;
	INIT_CLASS_ENTRY(tmp_gtkpackdirection_ce, "Gtk\\Pack\\Direction", NULL);
	zend_class_entry *gtkpackdirection_ce = zend_register_internal_class(&tmp_gtkpackdirection_ce);
	gtkpackdirection_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpackdirection_ce, "LTR", sizeof("LTR") - 1, GTK_PACK_DIRECTION_LTR);
	zend_declare_class_constant_long(gtkpackdirection_ce, "RTL", sizeof("RTL") - 1, GTK_PACK_DIRECTION_RTL);
	zend_declare_class_constant_long(gtkpackdirection_ce, "TTB", sizeof("TTB") - 1, GTK_PACK_DIRECTION_TTB);
	zend_declare_class_constant_long(gtkpackdirection_ce, "BTT", sizeof("BTT") - 1, GTK_PACK_DIRECTION_BTT);

	zend_class_entry tmp_gtkpacktype_ce;
	INIT_CLASS_ENTRY(tmp_gtkpacktype_ce, "Gtk\\Pack\\Type", NULL);
	zend_class_entry *gtkpacktype_ce = zend_register_internal_class(&tmp_gtkpacktype_ce);
	gtkpacktype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpacktype_ce, "START", sizeof("START") - 1, GTK_PACK_START);
	zend_declare_class_constant_long(gtkpacktype_ce, "END", sizeof("END") - 1, GTK_PACK_END);

	zend_class_entry tmp_gtkpadactiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkpadactiontype_ce, "Gtk\\Pad\\Action\\Type", NULL);
	zend_class_entry *gtkpadactiontype_ce = zend_register_internal_class(&tmp_gtkpadactiontype_ce);
	gtkpadactiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpadactiontype_ce, "BUTTON", sizeof("BUTTON") - 1, GTK_PAD_ACTION_BUTTON);
	zend_declare_class_constant_long(gtkpadactiontype_ce, "RING", sizeof("RING") - 1, GTK_PAD_ACTION_RING);
	zend_declare_class_constant_long(gtkpadactiontype_ce, "STRIP", sizeof("STRIP") - 1, GTK_PAD_ACTION_STRIP);

	zend_class_entry tmp_gtkpageorientation_ce;
	INIT_CLASS_ENTRY(tmp_gtkpageorientation_ce, "Gtk\\Page\\Orientation", NULL);
	zend_class_entry *gtkpageorientation_ce = zend_register_internal_class(&tmp_gtkpageorientation_ce);
	gtkpageorientation_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpageorientation_ce, "PORTRAIT", sizeof("PORTRAIT") - 1, GTK_PAGE_ORIENTATION_PORTRAIT);
	zend_declare_class_constant_long(gtkpageorientation_ce, "LANDSCAPE", sizeof("LANDSCAPE") - 1, GTK_PAGE_ORIENTATION_LANDSCAPE);
	zend_declare_class_constant_long(gtkpageorientation_ce, "REVERSE_PORTRAIT", sizeof("REVERSE_PORTRAIT") - 1, GTK_PAGE_ORIENTATION_REVERSE_PORTRAIT);
	zend_declare_class_constant_long(gtkpageorientation_ce, "REVERSE_LANDSCAPE", sizeof("REVERSE_LANDSCAPE") - 1, GTK_PAGE_ORIENTATION_REVERSE_LANDSCAPE);

	zend_class_entry tmp_gtkpageset_ce;
	INIT_CLASS_ENTRY(tmp_gtkpageset_ce, "Gtk\\Page\\Set", NULL);
	zend_class_entry *gtkpageset_ce = zend_register_internal_class(&tmp_gtkpageset_ce);
	gtkpageset_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpageset_ce, "ALL", sizeof("ALL") - 1, GTK_PAGE_SET_ALL);
	zend_declare_class_constant_long(gtkpageset_ce, "EVEN", sizeof("EVEN") - 1, GTK_PAGE_SET_EVEN);
	zend_declare_class_constant_long(gtkpageset_ce, "ODD", sizeof("ODD") - 1, GTK_PAGE_SET_ODD);

	zend_class_entry tmp_gtkpandirection_ce;
	INIT_CLASS_ENTRY(tmp_gtkpandirection_ce, "Gtk\\Pan\\Direction", NULL);
	zend_class_entry *gtkpandirection_ce = zend_register_internal_class(&tmp_gtkpandirection_ce);
	gtkpandirection_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpandirection_ce, "LEFT", sizeof("LEFT") - 1, GTK_PAN_DIRECTION_LEFT);
	zend_declare_class_constant_long(gtkpandirection_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_PAN_DIRECTION_RIGHT);
	zend_declare_class_constant_long(gtkpandirection_ce, "UP", sizeof("UP") - 1, GTK_PAN_DIRECTION_UP);
	zend_declare_class_constant_long(gtkpandirection_ce, "DOWN", sizeof("DOWN") - 1, GTK_PAN_DIRECTION_DOWN);

	zend_class_entry tmp_gtkpolicytype_ce;
	INIT_CLASS_ENTRY(tmp_gtkpolicytype_ce, "Gtk\\Policy\\Type", NULL);
	zend_class_entry *gtkpolicytype_ce = zend_register_internal_class(&tmp_gtkpolicytype_ce);
	gtkpolicytype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpolicytype_ce, "ALWAYS", sizeof("ALWAYS") - 1, GTK_POLICY_ALWAYS);
	zend_declare_class_constant_long(gtkpolicytype_ce, "AUTOMATIC", sizeof("AUTOMATIC") - 1, GTK_POLICY_AUTOMATIC);
	zend_declare_class_constant_long(gtkpolicytype_ce, "NEVER", sizeof("NEVER") - 1, GTK_POLICY_NEVER);
	zend_declare_class_constant_long(gtkpolicytype_ce, "EXTERNAL", sizeof("EXTERNAL") - 1, GTK_POLICY_EXTERNAL);

	zend_class_entry tmp_gtkpopoverconstraint_ce;
	INIT_CLASS_ENTRY(tmp_gtkpopoverconstraint_ce, "Gtk\\Popover\\Constraint", NULL);
	zend_class_entry *gtkpopoverconstraint_ce = zend_register_internal_class(&tmp_gtkpopoverconstraint_ce);
	gtkpopoverconstraint_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpopoverconstraint_ce, "NONE", sizeof("NONE") - 1, GTK_POPOVER_CONSTRAINT_NONE);
	zend_declare_class_constant_long(gtkpopoverconstraint_ce, "WINDOW", sizeof("WINDOW") - 1, GTK_POPOVER_CONSTRAINT_WINDOW);

	zend_class_entry tmp_gtkpositiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkpositiontype_ce, "Gtk\\Position\\Type", NULL);
	zend_class_entry *gtkpositiontype_ce = zend_register_internal_class(&tmp_gtkpositiontype_ce);
	gtkpositiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpositiontype_ce, "LEFT", sizeof("LEFT") - 1, GTK_POS_LEFT);
	zend_declare_class_constant_long(gtkpositiontype_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_POS_RIGHT);
	zend_declare_class_constant_long(gtkpositiontype_ce, "TOP", sizeof("TOP") - 1, GTK_POS_TOP);
	zend_declare_class_constant_long(gtkpositiontype_ce, "BOTTOM", sizeof("BOTTOM") - 1, GTK_POS_BOTTOM);

	zend_class_entry tmp_gtkprintduplex_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintduplex_ce, "Gtk\\Print\\Duplex", NULL);
	zend_class_entry *gtkprintduplex_ce = zend_register_internal_class(&tmp_gtkprintduplex_ce);
	gtkprintduplex_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintduplex_ce, "SIMPLEX", sizeof("SIMPLEX") - 1, GTK_PRINT_DUPLEX_SIMPLEX);
	zend_declare_class_constant_long(gtkprintduplex_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, GTK_PRINT_DUPLEX_HORIZONTAL);
	zend_declare_class_constant_long(gtkprintduplex_ce, "VERTICAL", sizeof("VERTICAL") - 1, GTK_PRINT_DUPLEX_VERTICAL);

	zend_class_entry tmp_gtkprinterror_ce;
	INIT_CLASS_ENTRY(tmp_gtkprinterror_ce, "Gtk\\Print\\Error", NULL);
	zend_class_entry *gtkprinterror_ce = zend_register_internal_class(&tmp_gtkprinterror_ce);
	gtkprinterror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprinterror_ce, "GENERAL", sizeof("GENERAL") - 1, GTK_PRINT_ERROR_GENERAL);
	zend_declare_class_constant_long(gtkprinterror_ce, "INTERNAL_ERROR", sizeof("INTERNAL_ERROR") - 1, GTK_PRINT_ERROR_INTERNAL_ERROR);
	zend_declare_class_constant_long(gtkprinterror_ce, "NOMEM", sizeof("NOMEM") - 1, GTK_PRINT_ERROR_NOMEM);
	zend_declare_class_constant_long(gtkprinterror_ce, "INVALID_FILE", sizeof("INVALID_FILE") - 1, GTK_PRINT_ERROR_INVALID_FILE);

	zend_class_entry tmp_gtkprintoperationaction_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintoperationaction_ce, "Gtk\\Print\\Operation\\Action", NULL);
	zend_class_entry *gtkprintoperationaction_ce = zend_register_internal_class(&tmp_gtkprintoperationaction_ce);
	gtkprintoperationaction_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintoperationaction_ce, "PRINT_DIALOG", sizeof("PRINT_DIALOG") - 1, GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG);
	zend_declare_class_constant_long(gtkprintoperationaction_ce, "PRINT", sizeof("PRINT") - 1, GTK_PRINT_OPERATION_ACTION_PRINT);
	zend_declare_class_constant_long(gtkprintoperationaction_ce, "PREVIEW", sizeof("PREVIEW") - 1, GTK_PRINT_OPERATION_ACTION_PREVIEW);
	zend_declare_class_constant_long(gtkprintoperationaction_ce, "EXPORT", sizeof("EXPORT") - 1, GTK_PRINT_OPERATION_ACTION_EXPORT);

	zend_class_entry tmp_gtkprintoperationresult_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintoperationresult_ce, "Gtk\\Print\\Operation\\Result", NULL);
	zend_class_entry *gtkprintoperationresult_ce = zend_register_internal_class(&tmp_gtkprintoperationresult_ce);
	gtkprintoperationresult_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintoperationresult_ce, "ERROR", sizeof("ERROR") - 1, GTK_PRINT_OPERATION_RESULT_ERROR);
	zend_declare_class_constant_long(gtkprintoperationresult_ce, "APPLY", sizeof("APPLY") - 1, GTK_PRINT_OPERATION_RESULT_APPLY);
	zend_declare_class_constant_long(gtkprintoperationresult_ce, "CANCEL", sizeof("CANCEL") - 1, GTK_PRINT_OPERATION_RESULT_CANCEL);
	zend_declare_class_constant_long(gtkprintoperationresult_ce, "IN_PROGRESS", sizeof("IN_PROGRESS") - 1, GTK_PRINT_OPERATION_RESULT_IN_PROGRESS);

	zend_class_entry tmp_gtkprintpages_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintpages_ce, "Gtk\\Print\\Pages", NULL);
	zend_class_entry *gtkprintpages_ce = zend_register_internal_class(&tmp_gtkprintpages_ce);
	gtkprintpages_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintpages_ce, "ALL", sizeof("ALL") - 1, GTK_PRINT_PAGES_ALL);
	zend_declare_class_constant_long(gtkprintpages_ce, "CURRENT", sizeof("CURRENT") - 1, GTK_PRINT_PAGES_CURRENT);
	zend_declare_class_constant_long(gtkprintpages_ce, "RANGES", sizeof("RANGES") - 1, GTK_PRINT_PAGES_RANGES);
	zend_declare_class_constant_long(gtkprintpages_ce, "SELECTION", sizeof("SELECTION") - 1, GTK_PRINT_PAGES_SELECTION);

	zend_class_entry tmp_gtkprintquality_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintquality_ce, "Gtk\\Print\\Quality", NULL);
	zend_class_entry *gtkprintquality_ce = zend_register_internal_class(&tmp_gtkprintquality_ce);
	gtkprintquality_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintquality_ce, "LOW", sizeof("LOW") - 1, GTK_PRINT_QUALITY_LOW);
	zend_declare_class_constant_long(gtkprintquality_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_PRINT_QUALITY_NORMAL);
	zend_declare_class_constant_long(gtkprintquality_ce, "HIGH", sizeof("HIGH") - 1, GTK_PRINT_QUALITY_HIGH);
	zend_declare_class_constant_long(gtkprintquality_ce, "DRAFT", sizeof("DRAFT") - 1, GTK_PRINT_QUALITY_DRAFT);

	zend_class_entry tmp_gtkprintstatus_ce;
	INIT_CLASS_ENTRY(tmp_gtkprintstatus_ce, "Gtk\\Print\\Status", NULL);
	zend_class_entry *gtkprintstatus_ce = zend_register_internal_class(&tmp_gtkprintstatus_ce);
	gtkprintstatus_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkprintstatus_ce, "INITIAL", sizeof("INITIAL") - 1, GTK_PRINT_STATUS_INITIAL);
	zend_declare_class_constant_long(gtkprintstatus_ce, "PREPARING", sizeof("PREPARING") - 1, GTK_PRINT_STATUS_PREPARING);
	zend_declare_class_constant_long(gtkprintstatus_ce, "GENERATING_DATA", sizeof("GENERATING_DATA") - 1, GTK_PRINT_STATUS_GENERATING_DATA);
	zend_declare_class_constant_long(gtkprintstatus_ce, "SENDING_DATA", sizeof("SENDING_DATA") - 1, GTK_PRINT_STATUS_SENDING_DATA);
	zend_declare_class_constant_long(gtkprintstatus_ce, "PENDING", sizeof("PENDING") - 1, GTK_PRINT_STATUS_PENDING);
	zend_declare_class_constant_long(gtkprintstatus_ce, "PENDING_ISSUE", sizeof("PENDING_ISSUE") - 1, GTK_PRINT_STATUS_PENDING_ISSUE);
	zend_declare_class_constant_long(gtkprintstatus_ce, "PRINTING", sizeof("PRINTING") - 1, GTK_PRINT_STATUS_PRINTING);
	zend_declare_class_constant_long(gtkprintstatus_ce, "FINISHED", sizeof("FINISHED") - 1, GTK_PRINT_STATUS_FINISHED);
	zend_declare_class_constant_long(gtkprintstatus_ce, "FINISHED_ABORTED", sizeof("FINISHED_ABORTED") - 1, GTK_PRINT_STATUS_FINISHED_ABORTED);

	zend_class_entry tmp_gtkpropagationphase_ce;
	INIT_CLASS_ENTRY(tmp_gtkpropagationphase_ce, "Gtk\\Propagation\\Phase", NULL);
	zend_class_entry *gtkpropagationphase_ce = zend_register_internal_class(&tmp_gtkpropagationphase_ce);
	gtkpropagationphase_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkpropagationphase_ce, "NONE", sizeof("NONE") - 1, GTK_PHASE_NONE);
	zend_declare_class_constant_long(gtkpropagationphase_ce, "CAPTURE", sizeof("CAPTURE") - 1, GTK_PHASE_CAPTURE);
	zend_declare_class_constant_long(gtkpropagationphase_ce, "BUBBLE", sizeof("BUBBLE") - 1, GTK_PHASE_BUBBLE);
	zend_declare_class_constant_long(gtkpropagationphase_ce, "TARGET", sizeof("TARGET") - 1, GTK_PHASE_TARGET);

	zend_class_entry tmp_gtkrecentchoosererror_ce;
	INIT_CLASS_ENTRY(tmp_gtkrecentchoosererror_ce, "Gtk\\Recent\\Chooser\\Error", NULL);
	zend_class_entry *gtkrecentchoosererror_ce = zend_register_internal_class(&tmp_gtkrecentchoosererror_ce);
	gtkrecentchoosererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkrecentchoosererror_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, GTK_RECENT_CHOOSER_ERROR_NOT_FOUND);
	zend_declare_class_constant_long(gtkrecentchoosererror_ce, "INVALID_URI", sizeof("INVALID_URI") - 1, GTK_RECENT_CHOOSER_ERROR_INVALID_URI);

	zend_class_entry tmp_gtkrecentmanagererror_ce;
	INIT_CLASS_ENTRY(tmp_gtkrecentmanagererror_ce, "Gtk\\Recent\\Manager\\Error", NULL);
	zend_class_entry *gtkrecentmanagererror_ce = zend_register_internal_class(&tmp_gtkrecentmanagererror_ce);
	gtkrecentmanagererror_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "NOT_FOUND", sizeof("NOT_FOUND") - 1, GTK_RECENT_MANAGER_ERROR_NOT_FOUND);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "INVALID_URI", sizeof("INVALID_URI") - 1, GTK_RECENT_MANAGER_ERROR_INVALID_URI);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "INVALID_ENCODING", sizeof("INVALID_ENCODING") - 1, GTK_RECENT_MANAGER_ERROR_INVALID_ENCODING);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "NOT_REGISTERED", sizeof("NOT_REGISTERED") - 1, GTK_RECENT_MANAGER_ERROR_NOT_REGISTERED);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "READ", sizeof("READ") - 1, GTK_RECENT_MANAGER_ERROR_READ);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "WRITE", sizeof("WRITE") - 1, GTK_RECENT_MANAGER_ERROR_WRITE);
	zend_declare_class_constant_long(gtkrecentmanagererror_ce, "UNKNOWN", sizeof("UNKNOWN") - 1, GTK_RECENT_MANAGER_ERROR_UNKNOWN);

	zend_class_entry tmp_gtkrecentsorttype_ce;
	INIT_CLASS_ENTRY(tmp_gtkrecentsorttype_ce, "Gtk\\Recent\\Sort\\Type", NULL);
	zend_class_entry *gtkrecentsorttype_ce = zend_register_internal_class(&tmp_gtkrecentsorttype_ce);
	gtkrecentsorttype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkrecentsorttype_ce, "NONE", sizeof("NONE") - 1, GTK_RECENT_SORT_NONE);
	zend_declare_class_constant_long(gtkrecentsorttype_ce, "MRU", sizeof("MRU") - 1, GTK_RECENT_SORT_MRU);
	zend_declare_class_constant_long(gtkrecentsorttype_ce, "LRU", sizeof("LRU") - 1, GTK_RECENT_SORT_LRU);
	zend_declare_class_constant_long(gtkrecentsorttype_ce, "CUSTOM", sizeof("CUSTOM") - 1, GTK_RECENT_SORT_CUSTOM);

	zend_class_entry tmp_gtkreliefstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtkreliefstyle_ce, "Gtk\\Relief\\Style", NULL);
	zend_class_entry *gtkreliefstyle_ce = zend_register_internal_class(&tmp_gtkreliefstyle_ce);
	gtkreliefstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkreliefstyle_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_RELIEF_NORMAL);
	zend_declare_class_constant_long(gtkreliefstyle_ce, "HALF", sizeof("HALF") - 1, GTK_RELIEF_HALF);
	zend_declare_class_constant_long(gtkreliefstyle_ce, "NONE", sizeof("NONE") - 1, GTK_RELIEF_NONE);

	zend_class_entry tmp_gtkresizemode_ce;
	INIT_CLASS_ENTRY(tmp_gtkresizemode_ce, "Gtk\\Resize\\Mode", NULL);
	zend_class_entry *gtkresizemode_ce = zend_register_internal_class(&tmp_gtkresizemode_ce);
	gtkresizemode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkresizemode_ce, "PARENT", sizeof("PARENT") - 1, GTK_RESIZE_PARENT);
	zend_declare_class_constant_long(gtkresizemode_ce, "QUEUE", sizeof("QUEUE") - 1, GTK_RESIZE_QUEUE);
	zend_declare_class_constant_long(gtkresizemode_ce, "IMMEDIATE", sizeof("IMMEDIATE") - 1, GTK_RESIZE_IMMEDIATE);

	zend_class_entry tmp_gtkresponsetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkresponsetype_ce, "Gtk\\Response\\Type", NULL);
	zend_class_entry *gtkresponsetype_ce = zend_register_internal_class(&tmp_gtkresponsetype_ce);
	gtkresponsetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkresponsetype_ce, "NONE", sizeof("NONE") - 1, GTK_RESPONSE_NONE);
	zend_declare_class_constant_long(gtkresponsetype_ce, "REJECT", sizeof("REJECT") - 1, GTK_RESPONSE_REJECT);
	zend_declare_class_constant_long(gtkresponsetype_ce, "ACCEPT", sizeof("ACCEPT") - 1, GTK_RESPONSE_ACCEPT);
	zend_declare_class_constant_long(gtkresponsetype_ce, "DELETE_EVENT", sizeof("DELETE_EVENT") - 1, GTK_RESPONSE_DELETE_EVENT);
	zend_declare_class_constant_long(gtkresponsetype_ce, "OK", sizeof("OK") - 1, GTK_RESPONSE_OK);
	zend_declare_class_constant_long(gtkresponsetype_ce, "CANCEL", sizeof("CANCEL") - 1, GTK_RESPONSE_CANCEL);
	zend_declare_class_constant_long(gtkresponsetype_ce, "CLOSE", sizeof("CLOSE") - 1, GTK_RESPONSE_CLOSE);
	zend_declare_class_constant_long(gtkresponsetype_ce, "YES", sizeof("YES") - 1, GTK_RESPONSE_YES);
	zend_declare_class_constant_long(gtkresponsetype_ce, "NO", sizeof("NO") - 1, GTK_RESPONSE_NO);
	zend_declare_class_constant_long(gtkresponsetype_ce, "APPLY", sizeof("APPLY") - 1, GTK_RESPONSE_APPLY);
	zend_declare_class_constant_long(gtkresponsetype_ce, "HELP", sizeof("HELP") - 1, GTK_RESPONSE_HELP);

	zend_class_entry tmp_gtkrevealertransitiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkrevealertransitiontype_ce, "Gtk\\Revealer\\Transition\\Type", NULL);
	zend_class_entry *gtkrevealertransitiontype_ce = zend_register_internal_class(&tmp_gtkrevealertransitiontype_ce);
	gtkrevealertransitiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "NONE", sizeof("NONE") - 1, GTK_REVEALER_TRANSITION_TYPE_NONE);
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "CROSSFADE", sizeof("CROSSFADE") - 1, GTK_REVEALER_TRANSITION_TYPE_CROSSFADE);
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "SLIDE_RIGHT", sizeof("SLIDE_RIGHT") - 1, GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT);
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "SLIDE_LEFT", sizeof("SLIDE_LEFT") - 1, GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT);
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "SLIDE_UP", sizeof("SLIDE_UP") - 1, GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP);
	zend_declare_class_constant_long(gtkrevealertransitiontype_ce, "SLIDE_DOWN", sizeof("SLIDE_DOWN") - 1, GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN);

	zend_class_entry tmp_gtkscrollablepolicy_ce;
	INIT_CLASS_ENTRY(tmp_gtkscrollablepolicy_ce, "Gtk\\Scrollable\\Policy", NULL);
	zend_class_entry *gtkscrollablepolicy_ce = zend_register_internal_class(&tmp_gtkscrollablepolicy_ce);
	gtkscrollablepolicy_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkscrollablepolicy_ce, "MINIMUM", sizeof("MINIMUM") - 1, GTK_SCROLL_MINIMUM);
	zend_declare_class_constant_long(gtkscrollablepolicy_ce, "NATURAL", sizeof("NATURAL") - 1, GTK_SCROLL_NATURAL);

	zend_class_entry tmp_gtkscrollstep_ce;
	INIT_CLASS_ENTRY(tmp_gtkscrollstep_ce, "Gtk\\Scroll\\Step", NULL);
	zend_class_entry *gtkscrollstep_ce = zend_register_internal_class(&tmp_gtkscrollstep_ce);
	gtkscrollstep_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkscrollstep_ce, "STEPS", sizeof("STEPS") - 1, GTK_SCROLL_STEPS);
	zend_declare_class_constant_long(gtkscrollstep_ce, "PAGES", sizeof("PAGES") - 1, GTK_SCROLL_PAGES);
	zend_declare_class_constant_long(gtkscrollstep_ce, "ENDS", sizeof("ENDS") - 1, GTK_SCROLL_ENDS);
	zend_declare_class_constant_long(gtkscrollstep_ce, "HORIZONTAL_STEPS", sizeof("HORIZONTAL_STEPS") - 1, GTK_SCROLL_HORIZONTAL_STEPS);
	zend_declare_class_constant_long(gtkscrollstep_ce, "HORIZONTAL_PAGES", sizeof("HORIZONTAL_PAGES") - 1, GTK_SCROLL_HORIZONTAL_PAGES);
	zend_declare_class_constant_long(gtkscrollstep_ce, "HORIZONTAL_ENDS", sizeof("HORIZONTAL_ENDS") - 1, GTK_SCROLL_HORIZONTAL_ENDS);

	zend_class_entry tmp_gtkscrolltype_ce;
	INIT_CLASS_ENTRY(tmp_gtkscrolltype_ce, "Gtk\\Scroll\\Type", NULL);
	zend_class_entry *gtkscrolltype_ce = zend_register_internal_class(&tmp_gtkscrolltype_ce);
	gtkscrolltype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkscrolltype_ce, "NONE", sizeof("NONE") - 1, GTK_SCROLL_NONE);
	zend_declare_class_constant_long(gtkscrolltype_ce, "JUMP", sizeof("JUMP") - 1, GTK_SCROLL_JUMP);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_BACKWARD", sizeof("STEP_BACKWARD") - 1, GTK_SCROLL_STEP_BACKWARD);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_FORWARD", sizeof("STEP_FORWARD") - 1, GTK_SCROLL_STEP_FORWARD);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_BACKWARD", sizeof("PAGE_BACKWARD") - 1, GTK_SCROLL_PAGE_BACKWARD);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_FORWARD", sizeof("PAGE_FORWARD") - 1, GTK_SCROLL_PAGE_FORWARD);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_UP", sizeof("STEP_UP") - 1, GTK_SCROLL_STEP_UP);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_DOWN", sizeof("STEP_DOWN") - 1, GTK_SCROLL_STEP_DOWN);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_UP", sizeof("PAGE_UP") - 1, GTK_SCROLL_PAGE_UP);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_DOWN", sizeof("PAGE_DOWN") - 1, GTK_SCROLL_PAGE_DOWN);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_LEFT", sizeof("STEP_LEFT") - 1, GTK_SCROLL_STEP_LEFT);
	zend_declare_class_constant_long(gtkscrolltype_ce, "STEP_RIGHT", sizeof("STEP_RIGHT") - 1, GTK_SCROLL_STEP_RIGHT);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_LEFT", sizeof("PAGE_LEFT") - 1, GTK_SCROLL_PAGE_LEFT);
	zend_declare_class_constant_long(gtkscrolltype_ce, "PAGE_RIGHT", sizeof("PAGE_RIGHT") - 1, GTK_SCROLL_PAGE_RIGHT);
	zend_declare_class_constant_long(gtkscrolltype_ce, "START", sizeof("START") - 1, GTK_SCROLL_START);
	zend_declare_class_constant_long(gtkscrolltype_ce, "END", sizeof("END") - 1, GTK_SCROLL_END);

	zend_class_entry tmp_gtkselectionmode_ce;
	INIT_CLASS_ENTRY(tmp_gtkselectionmode_ce, "Gtk\\Selection\\Mode", NULL);
	zend_class_entry *gtkselectionmode_ce = zend_register_internal_class(&tmp_gtkselectionmode_ce);
	gtkselectionmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkselectionmode_ce, "NONE", sizeof("NONE") - 1, GTK_SELECTION_NONE);
	zend_declare_class_constant_long(gtkselectionmode_ce, "SINGLE", sizeof("SINGLE") - 1, GTK_SELECTION_SINGLE);
	zend_declare_class_constant_long(gtkselectionmode_ce, "BROWSE", sizeof("BROWSE") - 1, GTK_SELECTION_BROWSE);
	zend_declare_class_constant_long(gtkselectionmode_ce, "MULTIPLE", sizeof("MULTIPLE") - 1, GTK_SELECTION_MULTIPLE);

	zend_class_entry tmp_gtksensitivitytype_ce;
	INIT_CLASS_ENTRY(tmp_gtksensitivitytype_ce, "Gtk\\Sensitivity\\Type", NULL);
	zend_class_entry *gtksensitivitytype_ce = zend_register_internal_class(&tmp_gtksensitivitytype_ce);
	gtksensitivitytype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtksensitivitytype_ce, "AUTO", sizeof("AUTO") - 1, GTK_SENSITIVITY_AUTO);
	zend_declare_class_constant_long(gtksensitivitytype_ce, "ON", sizeof("ON") - 1, GTK_SENSITIVITY_ON);
	zend_declare_class_constant_long(gtksensitivitytype_ce, "OFF", sizeof("OFF") - 1, GTK_SENSITIVITY_OFF);

	zend_class_entry tmp_gtkshadowtype_ce;
	INIT_CLASS_ENTRY(tmp_gtkshadowtype_ce, "Gtk\\Shadow\\Type", NULL);
	zend_class_entry *gtkshadowtype_ce = zend_register_internal_class(&tmp_gtkshadowtype_ce);
	gtkshadowtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkshadowtype_ce, "NONE", sizeof("NONE") - 1, GTK_SHADOW_NONE);
	zend_declare_class_constant_long(gtkshadowtype_ce, "IN", sizeof("IN") - 1, GTK_SHADOW_IN);
	zend_declare_class_constant_long(gtkshadowtype_ce, "OUT", sizeof("OUT") - 1, GTK_SHADOW_OUT);
	zend_declare_class_constant_long(gtkshadowtype_ce, "ETCHED_IN", sizeof("ETCHED_IN") - 1, GTK_SHADOW_ETCHED_IN);
	zend_declare_class_constant_long(gtkshadowtype_ce, "ETCHED_OUT", sizeof("ETCHED_OUT") - 1, GTK_SHADOW_ETCHED_OUT);

	zend_class_entry tmp_gtkshortcuttype_ce;
	INIT_CLASS_ENTRY(tmp_gtkshortcuttype_ce, "Gtk\\Shortcut\\Type", NULL);
	zend_class_entry *gtkshortcuttype_ce = zend_register_internal_class(&tmp_gtkshortcuttype_ce);
	gtkshortcuttype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkshortcuttype_ce, "ACCELERATOR", sizeof("ACCELERATOR") - 1, GTK_SHORTCUT_ACCELERATOR);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_PINCH", sizeof("GESTURE_PINCH") - 1, GTK_SHORTCUT_GESTURE_PINCH);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_STRETCH", sizeof("GESTURE_STRETCH") - 1, GTK_SHORTCUT_GESTURE_STRETCH);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_ROTATE_CLOCKWISE", sizeof("GESTURE_ROTATE_CLOCKWISE") - 1, GTK_SHORTCUT_GESTURE_ROTATE_CLOCKWISE);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_ROTATE_COUNTERCLOCKWISE", sizeof("GESTURE_ROTATE_COUNTERCLOCKWISE") - 1, GTK_SHORTCUT_GESTURE_ROTATE_COUNTERCLOCKWISE);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_TWO_FINGER_SWIPE_LEFT", sizeof("GESTURE_TWO_FINGER_SWIPE_LEFT") - 1, GTK_SHORTCUT_GESTURE_TWO_FINGER_SWIPE_LEFT);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE_TWO_FINGER_SWIPE_RIGHT", sizeof("GESTURE_TWO_FINGER_SWIPE_RIGHT") - 1, GTK_SHORTCUT_GESTURE_TWO_FINGER_SWIPE_RIGHT);
	zend_declare_class_constant_long(gtkshortcuttype_ce, "GESTURE", sizeof("GESTURE") - 1, GTK_SHORTCUT_GESTURE);

	zend_class_entry tmp_gtksizegroupmode_ce;
	INIT_CLASS_ENTRY(tmp_gtksizegroupmode_ce, "Gtk\\Size\\Group\\Mode", NULL);
	zend_class_entry *gtksizegroupmode_ce = zend_register_internal_class(&tmp_gtksizegroupmode_ce);
	gtksizegroupmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtksizegroupmode_ce, "NONE", sizeof("NONE") - 1, GTK_SIZE_GROUP_NONE);
	zend_declare_class_constant_long(gtksizegroupmode_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, GTK_SIZE_GROUP_HORIZONTAL);
	zend_declare_class_constant_long(gtksizegroupmode_ce, "VERTICAL", sizeof("VERTICAL") - 1, GTK_SIZE_GROUP_VERTICAL);
	zend_declare_class_constant_long(gtksizegroupmode_ce, "BOTH", sizeof("BOTH") - 1, GTK_SIZE_GROUP_BOTH);

	zend_class_entry tmp_gtksizerequestmode_ce;
	INIT_CLASS_ENTRY(tmp_gtksizerequestmode_ce, "Gtk\\Size\\Request\\Mode", NULL);
	zend_class_entry *gtksizerequestmode_ce = zend_register_internal_class(&tmp_gtksizerequestmode_ce);
	gtksizerequestmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtksizerequestmode_ce, "HEIGHT_FOR_WIDTH", sizeof("HEIGHT_FOR_WIDTH") - 1, GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH);
	zend_declare_class_constant_long(gtksizerequestmode_ce, "WIDTH_FOR_HEIGHT", sizeof("WIDTH_FOR_HEIGHT") - 1, GTK_SIZE_REQUEST_WIDTH_FOR_HEIGHT);
	zend_declare_class_constant_long(gtksizerequestmode_ce, "CONSTANT_SIZE", sizeof("CONSTANT_SIZE") - 1, GTK_SIZE_REQUEST_CONSTANT_SIZE);

	zend_class_entry tmp_gtksorttype_ce;
	INIT_CLASS_ENTRY(tmp_gtksorttype_ce, "Gtk\\Sort\\Type", NULL);
	zend_class_entry *gtksorttype_ce = zend_register_internal_class(&tmp_gtksorttype_ce);
	gtksorttype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtksorttype_ce, "ASCENDING", sizeof("ASCENDING") - 1, GTK_SORT_ASCENDING);
	zend_declare_class_constant_long(gtksorttype_ce, "DESCENDING", sizeof("DESCENDING") - 1, GTK_SORT_DESCENDING);

	zend_class_entry tmp_gtkspinbuttonupdatepolicy_ce;
	INIT_CLASS_ENTRY(tmp_gtkspinbuttonupdatepolicy_ce, "Gtk\\Spin\\Button\\Update\\Policy", NULL);
	zend_class_entry *gtkspinbuttonupdatepolicy_ce = zend_register_internal_class(&tmp_gtkspinbuttonupdatepolicy_ce);
	gtkspinbuttonupdatepolicy_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkspinbuttonupdatepolicy_ce, "ALWAYS", sizeof("ALWAYS") - 1, GTK_UPDATE_ALWAYS);
	zend_declare_class_constant_long(gtkspinbuttonupdatepolicy_ce, "IF_VALID", sizeof("IF_VALID") - 1, GTK_UPDATE_IF_VALID);

	zend_class_entry tmp_gtkspintype_ce;
	INIT_CLASS_ENTRY(tmp_gtkspintype_ce, "Gtk\\Spin\\Type", NULL);
	zend_class_entry *gtkspintype_ce = zend_register_internal_class(&tmp_gtkspintype_ce);
	gtkspintype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkspintype_ce, "STEP_FORWARD", sizeof("STEP_FORWARD") - 1, GTK_SPIN_STEP_FORWARD);
	zend_declare_class_constant_long(gtkspintype_ce, "STEP_BACKWARD", sizeof("STEP_BACKWARD") - 1, GTK_SPIN_STEP_BACKWARD);
	zend_declare_class_constant_long(gtkspintype_ce, "PAGE_FORWARD", sizeof("PAGE_FORWARD") - 1, GTK_SPIN_PAGE_FORWARD);
	zend_declare_class_constant_long(gtkspintype_ce, "PAGE_BACKWARD", sizeof("PAGE_BACKWARD") - 1, GTK_SPIN_PAGE_BACKWARD);
	zend_declare_class_constant_long(gtkspintype_ce, "HOME", sizeof("HOME") - 1, GTK_SPIN_HOME);
	zend_declare_class_constant_long(gtkspintype_ce, "END", sizeof("END") - 1, GTK_SPIN_END);
	zend_declare_class_constant_long(gtkspintype_ce, "USER_DEFINED", sizeof("USER_DEFINED") - 1, GTK_SPIN_USER_DEFINED);

	zend_class_entry tmp_gtkstacktransitiontype_ce;
	INIT_CLASS_ENTRY(tmp_gtkstacktransitiontype_ce, "Gtk\\Stack\\Transition\\Type", NULL);
	zend_class_entry *gtkstacktransitiontype_ce = zend_register_internal_class(&tmp_gtkstacktransitiontype_ce);
	gtkstacktransitiontype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "NONE", sizeof("NONE") - 1, GTK_STACK_TRANSITION_TYPE_NONE);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "CROSSFADE", sizeof("CROSSFADE") - 1, GTK_STACK_TRANSITION_TYPE_CROSSFADE);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_RIGHT", sizeof("SLIDE_RIGHT") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_LEFT", sizeof("SLIDE_LEFT") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_UP", sizeof("SLIDE_UP") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_UP);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_DOWN", sizeof("SLIDE_DOWN") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_LEFT_RIGHT", sizeof("SLIDE_LEFT_RIGHT") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "SLIDE_UP_DOWN", sizeof("SLIDE_UP_DOWN") - 1, GTK_STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_UP", sizeof("OVER_UP") - 1, GTK_STACK_TRANSITION_TYPE_OVER_UP);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_DOWN", sizeof("OVER_DOWN") - 1, GTK_STACK_TRANSITION_TYPE_OVER_DOWN);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_LEFT", sizeof("OVER_LEFT") - 1, GTK_STACK_TRANSITION_TYPE_OVER_LEFT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_RIGHT", sizeof("OVER_RIGHT") - 1, GTK_STACK_TRANSITION_TYPE_OVER_RIGHT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "UNDER_UP", sizeof("UNDER_UP") - 1, GTK_STACK_TRANSITION_TYPE_UNDER_UP);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "UNDER_DOWN", sizeof("UNDER_DOWN") - 1, GTK_STACK_TRANSITION_TYPE_UNDER_DOWN);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "UNDER_LEFT", sizeof("UNDER_LEFT") - 1, GTK_STACK_TRANSITION_TYPE_UNDER_LEFT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "UNDER_RIGHT", sizeof("UNDER_RIGHT") - 1, GTK_STACK_TRANSITION_TYPE_UNDER_RIGHT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_UP_DOWN", sizeof("OVER_UP_DOWN") - 1, GTK_STACK_TRANSITION_TYPE_OVER_UP_DOWN);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_DOWN_UP", sizeof("OVER_DOWN_UP") - 1, GTK_STACK_TRANSITION_TYPE_OVER_DOWN_UP);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_LEFT_RIGHT", sizeof("OVER_LEFT_RIGHT") - 1, GTK_STACK_TRANSITION_TYPE_OVER_LEFT_RIGHT);
	zend_declare_class_constant_long(gtkstacktransitiontype_ce, "OVER_RIGHT_LEFT", sizeof("OVER_RIGHT_LEFT") - 1, GTK_STACK_TRANSITION_TYPE_OVER_RIGHT_LEFT);

	zend_class_entry tmp_gtkstatetype_ce;
	INIT_CLASS_ENTRY(tmp_gtkstatetype_ce, "Gtk\\State\\Type", NULL);
	zend_class_entry *gtkstatetype_ce = zend_register_internal_class(&tmp_gtkstatetype_ce);
	gtkstatetype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkstatetype_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_STATE_NORMAL);
	zend_declare_class_constant_long(gtkstatetype_ce, "ACTIVE", sizeof("ACTIVE") - 1, GTK_STATE_ACTIVE);
	zend_declare_class_constant_long(gtkstatetype_ce, "PRELIGHT", sizeof("PRELIGHT") - 1, GTK_STATE_PRELIGHT);
	zend_declare_class_constant_long(gtkstatetype_ce, "SELECTED", sizeof("SELECTED") - 1, GTK_STATE_SELECTED);
	zend_declare_class_constant_long(gtkstatetype_ce, "INSENSITIVE", sizeof("INSENSITIVE") - 1, GTK_STATE_INSENSITIVE);
	zend_declare_class_constant_long(gtkstatetype_ce, "INCONSISTENT", sizeof("INCONSISTENT") - 1, GTK_STATE_INCONSISTENT);
	zend_declare_class_constant_long(gtkstatetype_ce, "FOCUSED", sizeof("FOCUSED") - 1, GTK_STATE_FOCUSED);

	zend_class_entry tmp_gtktextbuffertargetinfo_ce;
	INIT_CLASS_ENTRY(tmp_gtktextbuffertargetinfo_ce, "Gtk\\Text\\Buffer\\Target\\Info", NULL);
	zend_class_entry *gtktextbuffertargetinfo_ce = zend_register_internal_class(&tmp_gtktextbuffertargetinfo_ce);
	gtktextbuffertargetinfo_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextbuffertargetinfo_ce, "BUFFER_CONTENTS", sizeof("BUFFER_CONTENTS") - 1, GTK_TEXT_BUFFER_TARGET_INFO_BUFFER_CONTENTS);
	zend_declare_class_constant_long(gtktextbuffertargetinfo_ce, "RICH_TEXT", sizeof("RICH_TEXT") - 1, GTK_TEXT_BUFFER_TARGET_INFO_RICH_TEXT);
	zend_declare_class_constant_long(gtktextbuffertargetinfo_ce, "TEXT", sizeof("TEXT") - 1, GTK_TEXT_BUFFER_TARGET_INFO_TEXT);

	zend_class_entry tmp_gtktextdirection_ce;
	INIT_CLASS_ENTRY(tmp_gtktextdirection_ce, "Gtk\\Text\\Direction", NULL);
	zend_class_entry *gtktextdirection_ce = zend_register_internal_class(&tmp_gtktextdirection_ce);
	gtktextdirection_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextdirection_ce, "NONE", sizeof("NONE") - 1, GTK_TEXT_DIR_NONE);
	zend_declare_class_constant_long(gtktextdirection_ce, "LTR", sizeof("LTR") - 1, GTK_TEXT_DIR_LTR);
	zend_declare_class_constant_long(gtktextdirection_ce, "RTL", sizeof("RTL") - 1, GTK_TEXT_DIR_RTL);

	zend_class_entry tmp_gtktextextendselection_ce;
	INIT_CLASS_ENTRY(tmp_gtktextextendselection_ce, "Gtk\\Text\\Extend\\Selection", NULL);
	zend_class_entry *gtktextextendselection_ce = zend_register_internal_class(&tmp_gtktextextendselection_ce);
	gtktextextendselection_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextextendselection_ce, "WORD", sizeof("WORD") - 1, GTK_TEXT_EXTEND_SELECTION_WORD);
	zend_declare_class_constant_long(gtktextextendselection_ce, "LINE", sizeof("LINE") - 1, GTK_TEXT_EXTEND_SELECTION_LINE);

	zend_class_entry tmp_gtktextviewlayer_ce;
	INIT_CLASS_ENTRY(tmp_gtktextviewlayer_ce, "Gtk\\Text\\View\\Layer", NULL);
	zend_class_entry *gtktextviewlayer_ce = zend_register_internal_class(&tmp_gtktextviewlayer_ce);
	gtktextviewlayer_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextviewlayer_ce, "BELOW", sizeof("BELOW") - 1, GTK_TEXT_VIEW_LAYER_BELOW);
	zend_declare_class_constant_long(gtktextviewlayer_ce, "ABOVE", sizeof("ABOVE") - 1, GTK_TEXT_VIEW_LAYER_ABOVE);
	zend_declare_class_constant_long(gtktextviewlayer_ce, "BELOW_TEXT", sizeof("BELOW_TEXT") - 1, GTK_TEXT_VIEW_LAYER_BELOW_TEXT);
	zend_declare_class_constant_long(gtktextviewlayer_ce, "ABOVE_TEXT", sizeof("ABOVE_TEXT") - 1, GTK_TEXT_VIEW_LAYER_ABOVE_TEXT);

	zend_class_entry tmp_gtktextwindowtype_ce;
	INIT_CLASS_ENTRY(tmp_gtktextwindowtype_ce, "Gtk\\Text\\Window\\Type", NULL);
	zend_class_entry *gtktextwindowtype_ce = zend_register_internal_class(&tmp_gtktextwindowtype_ce);
	gtktextwindowtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextwindowtype_ce, "PRIVATE", sizeof("PRIVATE") - 1, GTK_TEXT_WINDOW_PRIVATE);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "WIDGET", sizeof("WIDGET") - 1, GTK_TEXT_WINDOW_WIDGET);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "TEXT", sizeof("TEXT") - 1, GTK_TEXT_WINDOW_TEXT);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "LEFT", sizeof("LEFT") - 1, GTK_TEXT_WINDOW_LEFT);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_TEXT_WINDOW_RIGHT);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "TOP", sizeof("TOP") - 1, GTK_TEXT_WINDOW_TOP);
	zend_declare_class_constant_long(gtktextwindowtype_ce, "BOTTOM", sizeof("BOTTOM") - 1, GTK_TEXT_WINDOW_BOTTOM);

	zend_class_entry tmp_gtktoolbarspacestyle_ce;
	INIT_CLASS_ENTRY(tmp_gtktoolbarspacestyle_ce, "Gtk\\Toolbar\\Space\\Style", NULL);
	zend_class_entry *gtktoolbarspacestyle_ce = zend_register_internal_class(&tmp_gtktoolbarspacestyle_ce);
	gtktoolbarspacestyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktoolbarspacestyle_ce, "EMPTY", sizeof("EMPTY") - 1, GTK_TOOLBAR_SPACE_EMPTY);
	zend_declare_class_constant_long(gtktoolbarspacestyle_ce, "LINE", sizeof("LINE") - 1, GTK_TOOLBAR_SPACE_LINE);

	zend_class_entry tmp_gtktoolbarstyle_ce;
	INIT_CLASS_ENTRY(tmp_gtktoolbarstyle_ce, "Gtk\\Toolbar\\Style", NULL);
	zend_class_entry *gtktoolbarstyle_ce = zend_register_internal_class(&tmp_gtktoolbarstyle_ce);
	gtktoolbarstyle_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktoolbarstyle_ce, "ICONS", sizeof("ICONS") - 1, GTK_TOOLBAR_ICONS);
	zend_declare_class_constant_long(gtktoolbarstyle_ce, "TEXT", sizeof("TEXT") - 1, GTK_TOOLBAR_TEXT);
	zend_declare_class_constant_long(gtktoolbarstyle_ce, "BOTH", sizeof("BOTH") - 1, GTK_TOOLBAR_BOTH);
	zend_declare_class_constant_long(gtktoolbarstyle_ce, "BOTH_HORIZ", sizeof("BOTH_HORIZ") - 1, GTK_TOOLBAR_BOTH_HORIZ);

	zend_class_entry tmp_gtktreeviewcolumnsizing_ce;
	INIT_CLASS_ENTRY(tmp_gtktreeviewcolumnsizing_ce, "Gtk\\Tree\\View\\Column\\Sizing", NULL);
	zend_class_entry *gtktreeviewcolumnsizing_ce = zend_register_internal_class(&tmp_gtktreeviewcolumnsizing_ce);
	gtktreeviewcolumnsizing_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktreeviewcolumnsizing_ce, "GROW_ONLY", sizeof("GROW_ONLY") - 1, GTK_TREE_VIEW_COLUMN_GROW_ONLY);
	zend_declare_class_constant_long(gtktreeviewcolumnsizing_ce, "AUTOSIZE", sizeof("AUTOSIZE") - 1, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
	zend_declare_class_constant_long(gtktreeviewcolumnsizing_ce, "FIXED", sizeof("FIXED") - 1, GTK_TREE_VIEW_COLUMN_FIXED);

	zend_class_entry tmp_gtktreeviewdropposition_ce;
	INIT_CLASS_ENTRY(tmp_gtktreeviewdropposition_ce, "Gtk\\Tree\\View\\Drop\\Position", NULL);
	zend_class_entry *gtktreeviewdropposition_ce = zend_register_internal_class(&tmp_gtktreeviewdropposition_ce);
	gtktreeviewdropposition_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktreeviewdropposition_ce, "BEFORE", sizeof("BEFORE") - 1, GTK_TREE_VIEW_DROP_BEFORE);
	zend_declare_class_constant_long(gtktreeviewdropposition_ce, "AFTER", sizeof("AFTER") - 1, GTK_TREE_VIEW_DROP_AFTER);
	zend_declare_class_constant_long(gtktreeviewdropposition_ce, "INTO_OR_BEFORE", sizeof("INTO_OR_BEFORE") - 1, GTK_TREE_VIEW_DROP_INTO_OR_BEFORE);
	zend_declare_class_constant_long(gtktreeviewdropposition_ce, "INTO_OR_AFTER", sizeof("INTO_OR_AFTER") - 1, GTK_TREE_VIEW_DROP_INTO_OR_AFTER);

	zend_class_entry tmp_gtktreeviewgridlines_ce;
	INIT_CLASS_ENTRY(tmp_gtktreeviewgridlines_ce, "Gtk\\Tree\\View\\Grid\\Lines", NULL);
	zend_class_entry *gtktreeviewgridlines_ce = zend_register_internal_class(&tmp_gtktreeviewgridlines_ce);
	gtktreeviewgridlines_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktreeviewgridlines_ce, "NONE", sizeof("NONE") - 1, GTK_TREE_VIEW_GRID_LINES_NONE);
	zend_declare_class_constant_long(gtktreeviewgridlines_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, GTK_TREE_VIEW_GRID_LINES_HORIZONTAL);
	zend_declare_class_constant_long(gtktreeviewgridlines_ce, "VERTICAL", sizeof("VERTICAL") - 1, GTK_TREE_VIEW_GRID_LINES_VERTICAL);
	zend_declare_class_constant_long(gtktreeviewgridlines_ce, "BOTH", sizeof("BOTH") - 1, GTK_TREE_VIEW_GRID_LINES_BOTH);

	zend_class_entry tmp_gtkunit_ce;
	INIT_CLASS_ENTRY(tmp_gtkunit_ce, "Gtk\\Unit", NULL);
	zend_class_entry *gtkunit_ce = zend_register_internal_class(&tmp_gtkunit_ce);
	gtkunit_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkunit_ce, "NONE", sizeof("NONE") - 1, GTK_UNIT_NONE);
	zend_declare_class_constant_long(gtkunit_ce, "POINTS", sizeof("POINTS") - 1, GTK_UNIT_POINTS);
	zend_declare_class_constant_long(gtkunit_ce, "INCH", sizeof("INCH") - 1, GTK_UNIT_INCH);
	zend_declare_class_constant_long(gtkunit_ce, "MM", sizeof("MM") - 1, GTK_UNIT_MM);

	zend_class_entry tmp_gtkwidgethelptype_ce;
	INIT_CLASS_ENTRY(tmp_gtkwidgethelptype_ce, "Gtk\\Widget\\Help\\Type", NULL);
	zend_class_entry *gtkwidgethelptype_ce = zend_register_internal_class(&tmp_gtkwidgethelptype_ce);
	gtkwidgethelptype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkwidgethelptype_ce, "TOOLTIP", sizeof("TOOLTIP") - 1, GTK_WIDGET_HELP_TOOLTIP);
	zend_declare_class_constant_long(gtkwidgethelptype_ce, "WHATS_THIS", sizeof("WHATS_THIS") - 1, GTK_WIDGET_HELP_WHATS_THIS);

	zend_class_entry tmp_gtkwindowposition_ce;
	INIT_CLASS_ENTRY(tmp_gtkwindowposition_ce, "Gtk\\Window\\Position", NULL);
	zend_class_entry *gtkwindowposition_ce = zend_register_internal_class(&tmp_gtkwindowposition_ce);
	gtkwindowposition_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkwindowposition_ce, "NONE", sizeof("NONE") - 1, GTK_WIN_POS_NONE);
	zend_declare_class_constant_long(gtkwindowposition_ce, "CENTER", sizeof("CENTER") - 1, GTK_WIN_POS_CENTER);
	zend_declare_class_constant_long(gtkwindowposition_ce, "MOUSE", sizeof("MOUSE") - 1, GTK_WIN_POS_MOUSE);
	zend_declare_class_constant_long(gtkwindowposition_ce, "CENTER_ALWAYS", sizeof("CENTER_ALWAYS") - 1, GTK_WIN_POS_CENTER_ALWAYS);
	zend_declare_class_constant_long(gtkwindowposition_ce, "CENTER_ON_PARENT", sizeof("CENTER_ON_PARENT") - 1, GTK_WIN_POS_CENTER_ON_PARENT);

	zend_class_entry tmp_gtkwindowtype_ce;
	INIT_CLASS_ENTRY(tmp_gtkwindowtype_ce, "Gtk\\Window\\Type", NULL);
	zend_class_entry *gtkwindowtype_ce = zend_register_internal_class(&tmp_gtkwindowtype_ce);
	gtkwindowtype_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkwindowtype_ce, "TOPLEVEL", sizeof("TOPLEVEL") - 1, GTK_WINDOW_TOPLEVEL);
	zend_declare_class_constant_long(gtkwindowtype_ce, "POPUP", sizeof("POPUP") - 1, GTK_WINDOW_POPUP);

	zend_class_entry tmp_gtkwrapmode_ce;
	INIT_CLASS_ENTRY(tmp_gtkwrapmode_ce, "Gtk\\Wrap\\Mode", NULL);
	zend_class_entry *gtkwrapmode_ce = zend_register_internal_class(&tmp_gtkwrapmode_ce);
	gtkwrapmode_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkwrapmode_ce, "NONE", sizeof("NONE") - 1, GTK_WRAP_NONE);
	zend_declare_class_constant_long(gtkwrapmode_ce, "CHAR", sizeof("CHAR") - 1, GTK_WRAP_CHAR);
	zend_declare_class_constant_long(gtkwrapmode_ce, "WORD", sizeof("WORD") - 1, GTK_WRAP_WORD);
	zend_declare_class_constant_long(gtkwrapmode_ce, "WORD_CHAR", sizeof("WORD_CHAR") - 1, GTK_WRAP_WORD_CHAR);

	zend_class_entry tmp_gtkaccelflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkaccelflags_ce, "Gtk\\Accel\\Flags", NULL);
	zend_class_entry *gtkaccelflags_ce = zend_register_internal_class(&tmp_gtkaccelflags_ce);
	gtkaccelflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkaccelflags_ce, "VISIBLE", sizeof("VISIBLE") - 1, GTK_ACCEL_VISIBLE);
	zend_declare_class_constant_long(gtkaccelflags_ce, "LOCKED", sizeof("LOCKED") - 1, GTK_ACCEL_LOCKED);
	zend_declare_class_constant_long(gtkaccelflags_ce, "MASK", sizeof("MASK") - 1, GTK_ACCEL_MASK);

	zend_class_entry tmp_gtkapplicationinhibitflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkapplicationinhibitflags_ce, "Gtk\\Application\\Inhibit\\Flags", NULL);
	zend_class_entry *gtkapplicationinhibitflags_ce = zend_register_internal_class(&tmp_gtkapplicationinhibitflags_ce);
	gtkapplicationinhibitflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkapplicationinhibitflags_ce, "LOGOUT", sizeof("LOGOUT") - 1, GTK_APPLICATION_INHIBIT_LOGOUT);
	zend_declare_class_constant_long(gtkapplicationinhibitflags_ce, "SWITCH", sizeof("SWITCH") - 1, GTK_APPLICATION_INHIBIT_SWITCH);
	zend_declare_class_constant_long(gtkapplicationinhibitflags_ce, "SUSPEND", sizeof("SUSPEND") - 1, GTK_APPLICATION_INHIBIT_SUSPEND);
	zend_declare_class_constant_long(gtkapplicationinhibitflags_ce, "IDLE", sizeof("IDLE") - 1, GTK_APPLICATION_INHIBIT_IDLE);

	zend_class_entry tmp_gtkcalendardisplayoptions_ce;
	INIT_CLASS_ENTRY(tmp_gtkcalendardisplayoptions_ce, "Gtk\\Calendar\\Display\\Options", NULL);
	zend_class_entry *gtkcalendardisplayoptions_ce = zend_register_internal_class(&tmp_gtkcalendardisplayoptions_ce);
	gtkcalendardisplayoptions_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcalendardisplayoptions_ce, "SHOW_HEADING", sizeof("SHOW_HEADING") - 1, GTK_CALENDAR_SHOW_HEADING);
	zend_declare_class_constant_long(gtkcalendardisplayoptions_ce, "SHOW_DAY_NAMES", sizeof("SHOW_DAY_NAMES") - 1, GTK_CALENDAR_SHOW_DAY_NAMES);
	zend_declare_class_constant_long(gtkcalendardisplayoptions_ce, "NO_MONTH_CHANGE", sizeof("NO_MONTH_CHANGE") - 1, GTK_CALENDAR_NO_MONTH_CHANGE);
	zend_declare_class_constant_long(gtkcalendardisplayoptions_ce, "SHOW_WEEK_NUMBERS", sizeof("SHOW_WEEK_NUMBERS") - 1, GTK_CALENDAR_SHOW_WEEK_NUMBERS);
	zend_declare_class_constant_long(gtkcalendardisplayoptions_ce, "SHOW_DETAILS", sizeof("SHOW_DETAILS") - 1, GTK_CALENDAR_SHOW_DETAILS);

	zend_class_entry tmp_gtkcellrendererstate_ce;
	INIT_CLASS_ENTRY(tmp_gtkcellrendererstate_ce, "Gtk\\Cell\\Renderer\\State", NULL);
	zend_class_entry *gtkcellrendererstate_ce = zend_register_internal_class(&tmp_gtkcellrendererstate_ce);
	gtkcellrendererstate_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "SELECTED", sizeof("SELECTED") - 1, GTK_CELL_RENDERER_SELECTED);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "PRELIT", sizeof("PRELIT") - 1, GTK_CELL_RENDERER_PRELIT);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "INSENSITIVE", sizeof("INSENSITIVE") - 1, GTK_CELL_RENDERER_INSENSITIVE);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "SORTED", sizeof("SORTED") - 1, GTK_CELL_RENDERER_SORTED);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "FOCUSED", sizeof("FOCUSED") - 1, GTK_CELL_RENDERER_FOCUSED);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "EXPANDABLE", sizeof("EXPANDABLE") - 1, GTK_CELL_RENDERER_EXPANDABLE);
	zend_declare_class_constant_long(gtkcellrendererstate_ce, "EXPANDED", sizeof("EXPANDED") - 1, GTK_CELL_RENDERER_EXPANDED);

	zend_class_entry tmp_gtkdebugflag_ce;
	INIT_CLASS_ENTRY(tmp_gtkdebugflag_ce, "Gtk\\Debug\\Flag", NULL);
	zend_class_entry *gtkdebugflag_ce = zend_register_internal_class(&tmp_gtkdebugflag_ce);
	gtkdebugflag_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdebugflag_ce, "MISC", sizeof("MISC") - 1, GTK_DEBUG_MISC);
	zend_declare_class_constant_long(gtkdebugflag_ce, "PLUGSOCKET", sizeof("PLUGSOCKET") - 1, GTK_DEBUG_PLUGSOCKET);
	zend_declare_class_constant_long(gtkdebugflag_ce, "TEXT", sizeof("TEXT") - 1, GTK_DEBUG_TEXT);
	zend_declare_class_constant_long(gtkdebugflag_ce, "TREE", sizeof("TREE") - 1, GTK_DEBUG_TREE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "UPDATES", sizeof("UPDATES") - 1, GTK_DEBUG_UPDATES);
	zend_declare_class_constant_long(gtkdebugflag_ce, "KEYBINDINGS", sizeof("KEYBINDINGS") - 1, GTK_DEBUG_KEYBINDINGS);
	zend_declare_class_constant_long(gtkdebugflag_ce, "MULTIHEAD", sizeof("MULTIHEAD") - 1, GTK_DEBUG_MULTIHEAD);
	zend_declare_class_constant_long(gtkdebugflag_ce, "MODULES", sizeof("MODULES") - 1, GTK_DEBUG_MODULES);
	zend_declare_class_constant_long(gtkdebugflag_ce, "GEOMETRY", sizeof("GEOMETRY") - 1, GTK_DEBUG_GEOMETRY);
	zend_declare_class_constant_long(gtkdebugflag_ce, "ICONTHEME", sizeof("ICONTHEME") - 1, GTK_DEBUG_ICONTHEME);
	zend_declare_class_constant_long(gtkdebugflag_ce, "PRINTING", sizeof("PRINTING") - 1, GTK_DEBUG_PRINTING);
	zend_declare_class_constant_long(gtkdebugflag_ce, "BUILDER", sizeof("BUILDER") - 1, GTK_DEBUG_BUILDER);
	zend_declare_class_constant_long(gtkdebugflag_ce, "SIZE_REQUEST", sizeof("SIZE_REQUEST") - 1, GTK_DEBUG_SIZE_REQUEST);
	zend_declare_class_constant_long(gtkdebugflag_ce, "NO_CSS_CACHE", sizeof("NO_CSS_CACHE") - 1, GTK_DEBUG_NO_CSS_CACHE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "BASELINES", sizeof("BASELINES") - 1, GTK_DEBUG_BASELINES);
	zend_declare_class_constant_long(gtkdebugflag_ce, "PIXEL_CACHE", sizeof("PIXEL_CACHE") - 1, GTK_DEBUG_PIXEL_CACHE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "NO_PIXEL_CACHE", sizeof("NO_PIXEL_CACHE") - 1, GTK_DEBUG_NO_PIXEL_CACHE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "INTERACTIVE", sizeof("INTERACTIVE") - 1, GTK_DEBUG_INTERACTIVE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "TOUCHSCREEN", sizeof("TOUCHSCREEN") - 1, GTK_DEBUG_TOUCHSCREEN);
	zend_declare_class_constant_long(gtkdebugflag_ce, "ACTIONS", sizeof("ACTIONS") - 1, GTK_DEBUG_ACTIONS);
	zend_declare_class_constant_long(gtkdebugflag_ce, "RESIZE", sizeof("RESIZE") - 1, GTK_DEBUG_RESIZE);
	zend_declare_class_constant_long(gtkdebugflag_ce, "LAYOUT", sizeof("LAYOUT") - 1, GTK_DEBUG_LAYOUT);

	zend_class_entry tmp_gtkdestdefaults_ce;
	INIT_CLASS_ENTRY(tmp_gtkdestdefaults_ce, "Gtk\\Dest\\Defaults", NULL);
	zend_class_entry *gtkdestdefaults_ce = zend_register_internal_class(&tmp_gtkdestdefaults_ce);
	gtkdestdefaults_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdestdefaults_ce, "MOTION", sizeof("MOTION") - 1, GTK_DEST_DEFAULT_MOTION);
	zend_declare_class_constant_long(gtkdestdefaults_ce, "HIGHLIGHT", sizeof("HIGHLIGHT") - 1, GTK_DEST_DEFAULT_HIGHLIGHT);
	zend_declare_class_constant_long(gtkdestdefaults_ce, "DROP", sizeof("DROP") - 1, GTK_DEST_DEFAULT_DROP);
	zend_declare_class_constant_long(gtkdestdefaults_ce, "ALL", sizeof("ALL") - 1, GTK_DEST_DEFAULT_ALL);

	zend_class_entry tmp_gtkdialogflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkdialogflags_ce, "Gtk\\Dialog\\Flags", NULL);
	zend_class_entry *gtkdialogflags_ce = zend_register_internal_class(&tmp_gtkdialogflags_ce);
	gtkdialogflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkdialogflags_ce, "MODAL", sizeof("MODAL") - 1, GTK_DIALOG_MODAL);
	zend_declare_class_constant_long(gtkdialogflags_ce, "DESTROY_WITH_PARENT", sizeof("DESTROY_WITH_PARENT") - 1, GTK_DIALOG_DESTROY_WITH_PARENT);
	zend_declare_class_constant_long(gtkdialogflags_ce, "USE_HEADER_BAR", sizeof("USE_HEADER_BAR") - 1, GTK_DIALOG_USE_HEADER_BAR);

	zend_class_entry tmp_gtkeventcontrollerscrollflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkeventcontrollerscrollflags_ce, "Gtk\\Event\\Controller\\Scroll\\Flags", NULL);
	zend_class_entry *gtkeventcontrollerscrollflags_ce = zend_register_internal_class(&tmp_gtkeventcontrollerscrollflags_ce);
	gtkeventcontrollerscrollflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "NONE", sizeof("NONE") - 1, GTK_EVENT_CONTROLLER_SCROLL_NONE);
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "VERTICAL", sizeof("VERTICAL") - 1, GTK_EVENT_CONTROLLER_SCROLL_VERTICAL);
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "HORIZONTAL", sizeof("HORIZONTAL") - 1, GTK_EVENT_CONTROLLER_SCROLL_HORIZONTAL);
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "DISCRETE", sizeof("DISCRETE") - 1, GTK_EVENT_CONTROLLER_SCROLL_DISCRETE);
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "KINETIC", sizeof("KINETIC") - 1, GTK_EVENT_CONTROLLER_SCROLL_KINETIC);
	zend_declare_class_constant_long(gtkeventcontrollerscrollflags_ce, "BOTH_AXES", sizeof("BOTH_AXES") - 1, GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES);

	zend_class_entry tmp_gtkfilefilterflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkfilefilterflags_ce, "Gtk\\File\\Filter\\Flags", NULL);
	zend_class_entry *gtkfilefilterflags_ce = zend_register_internal_class(&tmp_gtkfilefilterflags_ce);
	gtkfilefilterflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkfilefilterflags_ce, "FILENAME", sizeof("FILENAME") - 1, GTK_FILE_FILTER_FILENAME);
	zend_declare_class_constant_long(gtkfilefilterflags_ce, "URI", sizeof("URI") - 1, GTK_FILE_FILTER_URI);
	zend_declare_class_constant_long(gtkfilefilterflags_ce, "DISPLAY_NAME", sizeof("DISPLAY_NAME") - 1, GTK_FILE_FILTER_DISPLAY_NAME);
	zend_declare_class_constant_long(gtkfilefilterflags_ce, "MIME_TYPE", sizeof("MIME_TYPE") - 1, GTK_FILE_FILTER_MIME_TYPE);

	zend_class_entry tmp_gtkfontchooserlevel_ce;
	INIT_CLASS_ENTRY(tmp_gtkfontchooserlevel_ce, "Gtk\\Font\\Chooser\\Level", NULL);
	zend_class_entry *gtkfontchooserlevel_ce = zend_register_internal_class(&tmp_gtkfontchooserlevel_ce);
	gtkfontchooserlevel_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkfontchooserlevel_ce, "FAMILY", sizeof("FAMILY") - 1, GTK_FONT_CHOOSER_LEVEL_FAMILY);
	zend_declare_class_constant_long(gtkfontchooserlevel_ce, "STYLE", sizeof("STYLE") - 1, GTK_FONT_CHOOSER_LEVEL_STYLE);
	zend_declare_class_constant_long(gtkfontchooserlevel_ce, "SIZE", sizeof("SIZE") - 1, GTK_FONT_CHOOSER_LEVEL_SIZE);
	zend_declare_class_constant_long(gtkfontchooserlevel_ce, "VARIATIONS", sizeof("VARIATIONS") - 1, GTK_FONT_CHOOSER_LEVEL_VARIATIONS);
	zend_declare_class_constant_long(gtkfontchooserlevel_ce, "FEATURES", sizeof("FEATURES") - 1, GTK_FONT_CHOOSER_LEVEL_FEATURES);

	zend_class_entry tmp_gtkiconlookupflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkiconlookupflags_ce, "Gtk\\Icon\\Lookup\\Flags", NULL);
	zend_class_entry *gtkiconlookupflags_ce = zend_register_internal_class(&tmp_gtkiconlookupflags_ce);
	gtkiconlookupflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "NO_SVG", sizeof("NO_SVG") - 1, GTK_ICON_LOOKUP_NO_SVG);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "FORCE_SVG", sizeof("FORCE_SVG") - 1, GTK_ICON_LOOKUP_FORCE_SVG);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "USE_BUILTIN", sizeof("USE_BUILTIN") - 1, GTK_ICON_LOOKUP_USE_BUILTIN);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "GENERIC_FALLBACK", sizeof("GENERIC_FALLBACK") - 1, GTK_ICON_LOOKUP_GENERIC_FALLBACK);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "FORCE_SIZE", sizeof("FORCE_SIZE") - 1, GTK_ICON_LOOKUP_FORCE_SIZE);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "FORCE_REGULAR", sizeof("FORCE_REGULAR") - 1, GTK_ICON_LOOKUP_FORCE_REGULAR);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "FORCE_SYMBOLIC", sizeof("FORCE_SYMBOLIC") - 1, GTK_ICON_LOOKUP_FORCE_SYMBOLIC);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "DIR_LTR", sizeof("DIR_LTR") - 1, GTK_ICON_LOOKUP_DIR_LTR);
	zend_declare_class_constant_long(gtkiconlookupflags_ce, "DIR_RTL", sizeof("DIR_RTL") - 1, GTK_ICON_LOOKUP_DIR_RTL);

	zend_class_entry tmp_gtkinputhints_ce;
	INIT_CLASS_ENTRY(tmp_gtkinputhints_ce, "Gtk\\Input\\Hints", NULL);
	zend_class_entry *gtkinputhints_ce = zend_register_internal_class(&tmp_gtkinputhints_ce);
	gtkinputhints_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkinputhints_ce, "NONE", sizeof("NONE") - 1, GTK_INPUT_HINT_NONE);
	zend_declare_class_constant_long(gtkinputhints_ce, "SPELLCHECK", sizeof("SPELLCHECK") - 1, GTK_INPUT_HINT_SPELLCHECK);
	zend_declare_class_constant_long(gtkinputhints_ce, "NO_SPELLCHECK", sizeof("NO_SPELLCHECK") - 1, GTK_INPUT_HINT_NO_SPELLCHECK);
	zend_declare_class_constant_long(gtkinputhints_ce, "WORD_COMPLETION", sizeof("WORD_COMPLETION") - 1, GTK_INPUT_HINT_WORD_COMPLETION);
	zend_declare_class_constant_long(gtkinputhints_ce, "LOWERCASE", sizeof("LOWERCASE") - 1, GTK_INPUT_HINT_LOWERCASE);
	zend_declare_class_constant_long(gtkinputhints_ce, "UPPERCASE_CHARS", sizeof("UPPERCASE_CHARS") - 1, GTK_INPUT_HINT_UPPERCASE_CHARS);
	zend_declare_class_constant_long(gtkinputhints_ce, "UPPERCASE_WORDS", sizeof("UPPERCASE_WORDS") - 1, GTK_INPUT_HINT_UPPERCASE_WORDS);
	zend_declare_class_constant_long(gtkinputhints_ce, "UPPERCASE_SENTENCES", sizeof("UPPERCASE_SENTENCES") - 1, GTK_INPUT_HINT_UPPERCASE_SENTENCES);
	zend_declare_class_constant_long(gtkinputhints_ce, "INHIBIT_OSK", sizeof("INHIBIT_OSK") - 1, GTK_INPUT_HINT_INHIBIT_OSK);
	zend_declare_class_constant_long(gtkinputhints_ce, "VERTICAL_WRITING", sizeof("VERTICAL_WRITING") - 1, GTK_INPUT_HINT_VERTICAL_WRITING);
	zend_declare_class_constant_long(gtkinputhints_ce, "EMOJI", sizeof("EMOJI") - 1, GTK_INPUT_HINT_EMOJI);
	zend_declare_class_constant_long(gtkinputhints_ce, "NO_EMOJI", sizeof("NO_EMOJI") - 1, GTK_INPUT_HINT_NO_EMOJI);

	zend_class_entry tmp_gtkjunctionsides_ce;
	INIT_CLASS_ENTRY(tmp_gtkjunctionsides_ce, "Gtk\\Junction\\Sides", NULL);
	zend_class_entry *gtkjunctionsides_ce = zend_register_internal_class(&tmp_gtkjunctionsides_ce);
	gtkjunctionsides_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkjunctionsides_ce, "NONE", sizeof("NONE") - 1, GTK_JUNCTION_NONE);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "CORNER_TOPLEFT", sizeof("CORNER_TOPLEFT") - 1, GTK_JUNCTION_CORNER_TOPLEFT);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "CORNER_TOPRIGHT", sizeof("CORNER_TOPRIGHT") - 1, GTK_JUNCTION_CORNER_TOPRIGHT);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "CORNER_BOTTOMLEFT", sizeof("CORNER_BOTTOMLEFT") - 1, GTK_JUNCTION_CORNER_BOTTOMLEFT);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "CORNER_BOTTOMRIGHT", sizeof("CORNER_BOTTOMRIGHT") - 1, GTK_JUNCTION_CORNER_BOTTOMRIGHT);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "TOP", sizeof("TOP") - 1, GTK_JUNCTION_TOP);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "BOTTOM", sizeof("BOTTOM") - 1, GTK_JUNCTION_BOTTOM);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "LEFT", sizeof("LEFT") - 1, GTK_JUNCTION_LEFT);
	zend_declare_class_constant_long(gtkjunctionsides_ce, "RIGHT", sizeof("RIGHT") - 1, GTK_JUNCTION_RIGHT);

	zend_class_entry tmp_gtkplacesopenflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkplacesopenflags_ce, "Gtk\\Places\\Open\\Flags", NULL);
	zend_class_entry *gtkplacesopenflags_ce = zend_register_internal_class(&tmp_gtkplacesopenflags_ce);
	gtkplacesopenflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkplacesopenflags_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_PLACES_OPEN_NORMAL);
	zend_declare_class_constant_long(gtkplacesopenflags_ce, "NEW_TAB", sizeof("NEW_TAB") - 1, GTK_PLACES_OPEN_NEW_TAB);
	zend_declare_class_constant_long(gtkplacesopenflags_ce, "NEW_WINDOW", sizeof("NEW_WINDOW") - 1, GTK_PLACES_OPEN_NEW_WINDOW);

	zend_class_entry tmp_gtkrecentfilterflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkrecentfilterflags_ce, "Gtk\\Recent\\Filter\\Flags", NULL);
	zend_class_entry *gtkrecentfilterflags_ce = zend_register_internal_class(&tmp_gtkrecentfilterflags_ce);
	gtkrecentfilterflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "URI", sizeof("URI") - 1, GTK_RECENT_FILTER_URI);
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "DISPLAY_NAME", sizeof("DISPLAY_NAME") - 1, GTK_RECENT_FILTER_DISPLAY_NAME);
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "MIME_TYPE", sizeof("MIME_TYPE") - 1, GTK_RECENT_FILTER_MIME_TYPE);
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "APPLICATION", sizeof("APPLICATION") - 1, GTK_RECENT_FILTER_APPLICATION);
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "GROUP", sizeof("GROUP") - 1, GTK_RECENT_FILTER_GROUP);
	zend_declare_class_constant_long(gtkrecentfilterflags_ce, "AGE", sizeof("AGE") - 1, GTK_RECENT_FILTER_AGE);

	zend_class_entry tmp_gtkregionflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkregionflags_ce, "Gtk\\Region\\Flags", NULL);
	zend_class_entry *gtkregionflags_ce = zend_register_internal_class(&tmp_gtkregionflags_ce);
	gtkregionflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkregionflags_ce, "EVEN", sizeof("EVEN") - 1, GTK_REGION_EVEN);
	zend_declare_class_constant_long(gtkregionflags_ce, "ODD", sizeof("ODD") - 1, GTK_REGION_ODD);
	zend_declare_class_constant_long(gtkregionflags_ce, "FIRST", sizeof("FIRST") - 1, GTK_REGION_FIRST);
	zend_declare_class_constant_long(gtkregionflags_ce, "LAST", sizeof("LAST") - 1, GTK_REGION_LAST);
	zend_declare_class_constant_long(gtkregionflags_ce, "ONLY", sizeof("ONLY") - 1, GTK_REGION_ONLY);
	zend_declare_class_constant_long(gtkregionflags_ce, "SORTED", sizeof("SORTED") - 1, GTK_REGION_SORTED);

	zend_class_entry tmp_gtkstateflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkstateflags_ce, "Gtk\\State\\Flags", NULL);
	zend_class_entry *gtkstateflags_ce = zend_register_internal_class(&tmp_gtkstateflags_ce);
	gtkstateflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkstateflags_ce, "NORMAL", sizeof("NORMAL") - 1, GTK_STATE_FLAG_NORMAL);
	zend_declare_class_constant_long(gtkstateflags_ce, "ACTIVE", sizeof("ACTIVE") - 1, GTK_STATE_FLAG_ACTIVE);
	zend_declare_class_constant_long(gtkstateflags_ce, "PRELIGHT", sizeof("PRELIGHT") - 1, GTK_STATE_FLAG_PRELIGHT);
	zend_declare_class_constant_long(gtkstateflags_ce, "SELECTED", sizeof("SELECTED") - 1, GTK_STATE_FLAG_SELECTED);
	zend_declare_class_constant_long(gtkstateflags_ce, "INSENSITIVE", sizeof("INSENSITIVE") - 1, GTK_STATE_FLAG_INSENSITIVE);
	zend_declare_class_constant_long(gtkstateflags_ce, "INCONSISTENT", sizeof("INCONSISTENT") - 1, GTK_STATE_FLAG_INCONSISTENT);
	zend_declare_class_constant_long(gtkstateflags_ce, "FOCUSED", sizeof("FOCUSED") - 1, GTK_STATE_FLAG_FOCUSED);
	zend_declare_class_constant_long(gtkstateflags_ce, "BACKDROP", sizeof("BACKDROP") - 1, GTK_STATE_FLAG_BACKDROP);
	zend_declare_class_constant_long(gtkstateflags_ce, "DIR_LTR", sizeof("DIR_LTR") - 1, GTK_STATE_FLAG_DIR_LTR);
	zend_declare_class_constant_long(gtkstateflags_ce, "DIR_RTL", sizeof("DIR_RTL") - 1, GTK_STATE_FLAG_DIR_RTL);
	zend_declare_class_constant_long(gtkstateflags_ce, "LINK", sizeof("LINK") - 1, GTK_STATE_FLAG_LINK);
	zend_declare_class_constant_long(gtkstateflags_ce, "VISITED", sizeof("VISITED") - 1, GTK_STATE_FLAG_VISITED);
	zend_declare_class_constant_long(gtkstateflags_ce, "CHECKED", sizeof("CHECKED") - 1, GTK_STATE_FLAG_CHECKED);
	zend_declare_class_constant_long(gtkstateflags_ce, "DROP_ACTIVE", sizeof("DROP_ACTIVE") - 1, GTK_STATE_FLAG_DROP_ACTIVE);

	zend_class_entry tmp_gtkstylecontextprintflags_ce;
	INIT_CLASS_ENTRY(tmp_gtkstylecontextprintflags_ce, "Gtk\\Style\\Context\\Print\\Flags", NULL);
	zend_class_entry *gtkstylecontextprintflags_ce = zend_register_internal_class(&tmp_gtkstylecontextprintflags_ce);
	gtkstylecontextprintflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtkstylecontextprintflags_ce, "NONE", sizeof("NONE") - 1, GTK_STYLE_CONTEXT_PRINT_NONE);
	zend_declare_class_constant_long(gtkstylecontextprintflags_ce, "RECURSE", sizeof("RECURSE") - 1, GTK_STYLE_CONTEXT_PRINT_RECURSE);
	zend_declare_class_constant_long(gtkstylecontextprintflags_ce, "SHOW_STYLE", sizeof("SHOW_STYLE") - 1, GTK_STYLE_CONTEXT_PRINT_SHOW_STYLE);

	zend_class_entry tmp_gtktargetflags_ce;
	INIT_CLASS_ENTRY(tmp_gtktargetflags_ce, "Gtk\\Target\\Flags", NULL);
	zend_class_entry *gtktargetflags_ce = zend_register_internal_class(&tmp_gtktargetflags_ce);
	gtktargetflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktargetflags_ce, "SAME_APP", sizeof("SAME_APP") - 1, GTK_TARGET_SAME_APP);
	zend_declare_class_constant_long(gtktargetflags_ce, "SAME_WIDGET", sizeof("SAME_WIDGET") - 1, GTK_TARGET_SAME_WIDGET);
	zend_declare_class_constant_long(gtktargetflags_ce, "OTHER_APP", sizeof("OTHER_APP") - 1, GTK_TARGET_OTHER_APP);
	zend_declare_class_constant_long(gtktargetflags_ce, "OTHER_WIDGET", sizeof("OTHER_WIDGET") - 1, GTK_TARGET_OTHER_WIDGET);

	zend_class_entry tmp_gtktextsearchflags_ce;
	INIT_CLASS_ENTRY(tmp_gtktextsearchflags_ce, "Gtk\\Text\\Search\\Flags", NULL);
	zend_class_entry *gtktextsearchflags_ce = zend_register_internal_class(&tmp_gtktextsearchflags_ce);
	gtktextsearchflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktextsearchflags_ce, "VISIBLE_ONLY", sizeof("VISIBLE_ONLY") - 1, GTK_TEXT_SEARCH_VISIBLE_ONLY);
	zend_declare_class_constant_long(gtktextsearchflags_ce, "TEXT_ONLY", sizeof("TEXT_ONLY") - 1, GTK_TEXT_SEARCH_TEXT_ONLY);
	zend_declare_class_constant_long(gtktextsearchflags_ce, "CASE_INSENSITIVE", sizeof("CASE_INSENSITIVE") - 1, GTK_TEXT_SEARCH_CASE_INSENSITIVE);

	zend_class_entry tmp_gtktoolpalettedragtargets_ce;
	INIT_CLASS_ENTRY(tmp_gtktoolpalettedragtargets_ce, "Gtk\\Tool\\Palette\\Drag\\Targets", NULL);
	zend_class_entry *gtktoolpalettedragtargets_ce = zend_register_internal_class(&tmp_gtktoolpalettedragtargets_ce);
	gtktoolpalettedragtargets_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktoolpalettedragtargets_ce, "ITEMS", sizeof("ITEMS") - 1, GTK_TOOL_PALETTE_DRAG_ITEMS);
	zend_declare_class_constant_long(gtktoolpalettedragtargets_ce, "GROUPS", sizeof("GROUPS") - 1, GTK_TOOL_PALETTE_DRAG_GROUPS);

	zend_class_entry tmp_gtktreemodelflags_ce;
	INIT_CLASS_ENTRY(tmp_gtktreemodelflags_ce, "Gtk\\Tree\\Model\\Flags", NULL);
	zend_class_entry *gtktreemodelflags_ce = zend_register_internal_class(&tmp_gtktreemodelflags_ce);
	gtktreemodelflags_ce->ce_flags |= ZEND_ACC_FINAL;
	zend_declare_class_constant_long(gtktreemodelflags_ce, "ITERS_PERSIST", sizeof("ITERS_PERSIST") - 1, GTK_TREE_MODEL_ITERS_PERSIST);
	zend_declare_class_constant_long(gtktreemodelflags_ce, "LIST_ONLY", sizeof("LIST_ONLY") - 1, GTK_TREE_MODEL_LIST_ONLY);



	
	return SUCCESS;
}

/**
 * RINIT
 */
PHP_RINIT_FUNCTION(gtk4)
{
	#if defined(ZTS) && defined(COMPILE_DL_GTK4)
		ZEND_TSRMLS_CACHE_UPDATE();
	#endif

	return SUCCESS;
}

/**
 * MINFO
 */
PHP_MINFO_FUNCTION(gtk4)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gtk4 support", "enabled");
	php_info_print_table_end();
}

/**
 * Module entry
 */
zend_module_entry gtk4_module_entry = {
	STANDARD_MODULE_HEADER,
	"gtk4",							/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(gtk4),				/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(gtk4),				/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(gtk4),				/* PHP_MINFO - Module info */
	"0.1",							/* Version */
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_GTK4
	# ifdef ZTS
		ZEND_TSRMLS_CACHE_DEFINE()
	# endif
	ZEND_GET_MODULE(gtk4)
#endif
