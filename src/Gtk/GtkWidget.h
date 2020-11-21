#ifndef _PHPGTK_GTKWIDGET_H_
#define _PHPGTK_GTKWIDGET_H_

#include <php.h>
#include <gtk/gtk.h>

#include "../../helper.h"

#include "../G/GObject.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, first_property_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_activate, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, activate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_add_accelerator, 0, 0, 5)
	ZEND_ARG_INFO(0, accel_signal)
	ZEND_ARG_INFO(0, accel_group)
	ZEND_ARG_INFO(0, accel_key)
	ZEND_ARG_INFO(0, accel_mods)
	ZEND_ARG_INFO(0, accel_flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, add_accelerator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_add_device_events, 0, 0, 2)
	ZEND_ARG_INFO(0, device)
	ZEND_ARG_INFO(0, events)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, add_device_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_add_events, 0, 0, 1)
	ZEND_ARG_INFO(0, events)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, add_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_add_mnemonic_label, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, add_mnemonic_label);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_can_activate_accel, 0, 0, 1)
	ZEND_ARG_INFO(0, signal_id)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, can_activate_accel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_child_focus, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, child_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_child_notify1, 0, 0, 1)
	ZEND_ARG_INFO(0, child_property)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, child_notify1);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_compute_expand, 0, 0, 1)
	ZEND_ARG_INFO(0, orientation)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, compute_expand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_create_pango_context, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, create_pango_context);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_create_pango_layout, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, create_pango_layout);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_destroy, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_device_is_shadowed, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, device_is_shadowed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_draw, 0, 0, 1)
	ZEND_ARG_INFO(0, cr)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, draw);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_error_bell, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, error_bell);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_event, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_freeze_child_notify, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, freeze_child_notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_accessible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_accessible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_action_group, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_action_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_allocated_baseline, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_allocated_baseline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_allocated_height, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_allocated_height);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_allocated_size, 0, 0, 2)
	ZEND_ARG_INFO(0, allocation)
	ZEND_ARG_INFO(0, baseline)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_allocated_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_allocated_width, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_allocated_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_allocation, 0, 0, 1)
	ZEND_ARG_INFO(0, allocation)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_allocation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_ancestor, 0, 0, 1)
	ZEND_ARG_INFO(0, widget_type)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_ancestor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_app_paintable, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_app_paintable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_can_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_can_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_can_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_can_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_child_requisition, 0, 0, 1)
	ZEND_ARG_INFO(0, requisition)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_child_requisition);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_child_visible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_child_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_clip, 0, 0, 1)
	ZEND_ARG_INFO(0, clip)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_clip);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_clipboard, 0, 0, 1)
	ZEND_ARG_INFO(0, selection)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_clipboard);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_composite_name, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_composite_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_device_enabled, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_device_enabled);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_device_events, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_device_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_direction, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_direction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_display, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_display);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_double_buffered, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_double_buffered);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_events, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_focus_on_click, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_focus_on_click);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_font_map, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_font_map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_font_options, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_font_options);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_frame_clock, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_frame_clock);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_halign, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_halign);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_has_tooltip, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_has_tooltip);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_has_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_has_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_hexpand, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_hexpand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_hexpand_set, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_hexpand_set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_mapped, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_mapped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_bottom, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_bottom);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_end, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_end);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_left, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_left);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_right, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_right);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_start, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_start);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_margin_top, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_margin_top);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_modifier_mask, 0, 0, 1)
	ZEND_ARG_INFO(0, intent)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_modifier_mask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_name, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_no_show_all, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_no_show_all);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_opacity, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_opacity);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_pango_context, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_pango_context);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_parent, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_parent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_parent_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_parent_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_path, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_pointer, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_pointer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_height, 0, 0, 2)
	ZEND_ARG_INFO(0, minimum_height)
	ZEND_ARG_INFO(0, natural_height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_height);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_height_and_baseline_for_width, 0, 0, 5)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, minimum_height)
	ZEND_ARG_INFO(0, natural_height)
	ZEND_ARG_INFO(0, minimum_baseline)
	ZEND_ARG_INFO(0, natural_baseline)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_height_and_baseline_for_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_height_for_width, 0, 0, 3)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, minimum_height)
	ZEND_ARG_INFO(0, natural_height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_height_for_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_size, 0, 0, 2)
	ZEND_ARG_INFO(0, minimum_size)
	ZEND_ARG_INFO(0, natural_size)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_width, 0, 0, 2)
	ZEND_ARG_INFO(0, minimum_width)
	ZEND_ARG_INFO(0, natural_width)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_width);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_preferred_width_for_height, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, minimum_width)
	ZEND_ARG_INFO(0, natural_width)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_preferred_width_for_height);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_realized, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_realized);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_receives_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_receives_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_request_mode, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_request_mode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_requisition, 0, 0, 1)
	ZEND_ARG_INFO(0, requisition)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_requisition);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_root_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_root_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_scale_factor, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_scale_factor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_screen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_sensitive, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_sensitive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_settings, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_settings);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_size_request, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_size_request);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_state, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_state_flags, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_state_flags);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_style_context, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_style_context);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_support_multidevice, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_support_multidevice);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_template_child, 0, 0, 2)
	ZEND_ARG_INFO(0, widget_type)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_template_child);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_tooltip_markup, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_tooltip_markup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_tooltip_text, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_tooltip_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_tooltip_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_tooltip_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_toplevel, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_toplevel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_valign, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_valign);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_valign_with_baseline, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_valign_with_baseline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_vexpand, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_vexpand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_vexpand_set, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_vexpand_set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_visible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_visual, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_visual);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_get_window, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, get_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_grab_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, grab_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_grab_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, grab_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_has_default, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, has_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_has_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, has_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_has_grab, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, has_grab);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_has_screen, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, has_screen);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_has_visible_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, has_visible_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_hide, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, hide);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_hide_on_delete, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, hide_on_delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_in_destruction, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, in_destruction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_init_template, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, init_template);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_input_shape_combine_region, 0, 0, 1)
	ZEND_ARG_INFO(0, region)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, input_shape_combine_region);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_insert_action_group, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, insert_action_group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_intersect, 0, 0, 2)
	ZEND_ARG_INFO(0, area)
	ZEND_ARG_INFO(0, intersection)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, intersect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_ancestor, 0, 0, 1)
	ZEND_ARG_INFO(0, ancestor)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_ancestor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_composited, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_composited);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_drawable, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_drawable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_focus, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_sensitive, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_sensitive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_toplevel, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_toplevel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_is_visible, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, is_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_keynav_failed, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, keynav_failed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_list_accel_closures, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, list_accel_closures);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_list_action_prefixes, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, list_action_prefixes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_list_mnemonic_labels, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, list_mnemonic_labels);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_map, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_mnemonic_activate1, 0, 0, 1)
	ZEND_ARG_INFO(0, group_cycling)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, mnemonic_activate1);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_override_background_color, 0, 0, 2)
	ZEND_ARG_INFO(0, state)
	ZEND_ARG_INFO(0, color)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, override_background_color);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_override_color, 0, 0, 2)
	ZEND_ARG_INFO(0, state)
	ZEND_ARG_INFO(0, color)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, override_color);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_override_cursor, 0, 0, 2)
	ZEND_ARG_INFO(0, cursor)
	ZEND_ARG_INFO(0, secondary_cursor)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, override_cursor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_override_font, 0, 0, 1)
	ZEND_ARG_INFO(0, font_desc)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, override_font);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_override_symbolic_color, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, color)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, override_symbolic_color);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_allocate, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_allocate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_compute_expand, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_compute_expand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_draw, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_draw);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_draw_area, 0, 0, 4)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_draw_area);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_draw_region, 0, 0, 1)
	ZEND_ARG_INFO(0, region)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_draw_region);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_resize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_resize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_queue_resize_no_redraw, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, queue_resize_no_redraw);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_realize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, realize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_region_intersect, 0, 0, 1)
	ZEND_ARG_INFO(0, region)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, region_intersect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_register_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, register_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_remove_accelerator, 0, 0, 3)
	ZEND_ARG_INFO(0, accel_group)
	ZEND_ARG_INFO(0, accel_key)
	ZEND_ARG_INFO(0, accel_mods)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, remove_accelerator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_remove_mnemonic_label, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, remove_mnemonic_label);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_remove_tick_callback, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, remove_tick_callback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_render_icon_pixbuf, 0, 0, 2)
	ZEND_ARG_INFO(0, stock_id)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, render_icon_pixbuf);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_reparent, 0, 0, 1)
	ZEND_ARG_INFO(0, new_parent)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, reparent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_reset_style, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, reset_style);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_send_expose, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, send_expose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_send_focus_change, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, send_focus_change);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_accel_path, 0, 0, 2)
	ZEND_ARG_INFO(0, accel_path)
	ZEND_ARG_INFO(0, accel_group)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_accel_path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_allocation, 0, 0, 1)
	ZEND_ARG_INFO(0, allocation)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_allocation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_app_paintable, 0, 0, 1)
	ZEND_ARG_INFO(0, app_paintable)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_app_paintable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_can_default, 0, 0, 1)
	ZEND_ARG_INFO(0, can_default)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_can_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_can_focus, 0, 0, 1)
	ZEND_ARG_INFO(0, can_focus)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_can_focus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_child_visible, 0, 0, 1)
	ZEND_ARG_INFO(0, is_visible)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_child_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_clip, 0, 0, 1)
	ZEND_ARG_INFO(0, clip)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_clip);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_composite_name, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_composite_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_device_enabled, 0, 0, 2)
	ZEND_ARG_INFO(0, device)
	ZEND_ARG_INFO(0, enabled)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_device_enabled);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_device_events, 0, 0, 2)
	ZEND_ARG_INFO(0, device)
	ZEND_ARG_INFO(0, events)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_device_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_direction, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_direction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_double_buffered, 0, 0, 1)
	ZEND_ARG_INFO(0, double_buffered)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_double_buffered);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_events, 0, 0, 1)
	ZEND_ARG_INFO(0, events)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_events);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_focus_on_click, 0, 0, 1)
	ZEND_ARG_INFO(0, focus_on_click)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_focus_on_click);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_font_map, 0, 0, 1)
	ZEND_ARG_INFO(0, font_map)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_font_map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_font_options, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_font_options);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_halign, 0, 0, 1)
	ZEND_ARG_INFO(0, align)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_halign);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_has_tooltip, 0, 0, 1)
	ZEND_ARG_INFO(0, has_tooltip)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_has_tooltip);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_has_window, 0, 0, 1)
	ZEND_ARG_INFO(0, has_window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_has_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_hexpand, 0, 0, 1)
	ZEND_ARG_INFO(0, expand)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_hexpand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_hexpand_set, 0, 0, 1)
	ZEND_ARG_INFO(0, set)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_hexpand_set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_mapped, 0, 0, 1)
	ZEND_ARG_INFO(0, mapped)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_mapped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_bottom, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_bottom);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_end, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_end);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_left, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_left);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_right, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_right);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_start, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_start);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_margin_top, 0, 0, 1)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_margin_top);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_name, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_no_show_all, 0, 0, 1)
	ZEND_ARG_INFO(0, no_show_all)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_no_show_all);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_opacity, 0, 0, 1)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_opacity);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_parent, 0, 0, 1)
	ZEND_ARG_INFO(0, parent)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_parent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_parent_window, 0, 0, 1)
	ZEND_ARG_INFO(0, parent_window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_parent_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_realized, 0, 0, 1)
	ZEND_ARG_INFO(0, realized)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_realized);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_receives_default, 0, 0, 1)
	ZEND_ARG_INFO(0, receives_default)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_receives_default);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_redraw_on_allocate, 0, 0, 1)
	ZEND_ARG_INFO(0, redraw_on_allocate)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_redraw_on_allocate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_sensitive, 0, 0, 1)
	ZEND_ARG_INFO(0, sensitive)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_sensitive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_size_request, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_size_request);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_state_flags, 0, 0, 2)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, clear)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_state_flags);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_support_multidevice, 0, 0, 1)
	ZEND_ARG_INFO(0, support_multidevice)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_support_multidevice);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_tooltip_markup, 0, 0, 1)
	ZEND_ARG_INFO(0, markup)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_tooltip_markup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_tooltip_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_tooltip_text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_tooltip_window, 0, 0, 1)
	ZEND_ARG_INFO(0, custom_window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_tooltip_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_valign, 0, 0, 1)
	ZEND_ARG_INFO(0, align)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_valign);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_vexpand, 0, 0, 1)
	ZEND_ARG_INFO(0, expand)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_vexpand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_vexpand_set, 0, 0, 1)
	ZEND_ARG_INFO(0, set)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_vexpand_set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_visible, 0, 0, 1)
	ZEND_ARG_INFO(0, visible)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_visible);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_visual, 0, 0, 1)
	ZEND_ARG_INFO(0, visual)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_visual);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_set_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, set_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_shape_combine_region, 0, 0, 1)
	ZEND_ARG_INFO(0, region)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, shape_combine_region);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_show, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, show);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_show_all, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, show_all);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_show_now, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, show_now);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_size_allocate, 0, 0, 1)
	ZEND_ARG_INFO(0, allocation)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, size_allocate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_size_allocate_with_baseline, 0, 0, 2)
	ZEND_ARG_INFO(0, allocation)
	ZEND_ARG_INFO(0, baseline)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, size_allocate_with_baseline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_size_request, 0, 0, 1)
	ZEND_ARG_INFO(0, requisition)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, size_request);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_style_get, 0, 0, 1)
	ZEND_ARG_INFO(0, first_property_name)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, style_get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_style_get_property, 0, 0, 2)
	ZEND_ARG_INFO(0, property_name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, style_get_property);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_style_get_valist, 0, 0, 2)
	ZEND_ARG_INFO(0, first_property_name)
	ZEND_ARG_INFO(0, var_args)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, style_get_valist);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_thaw_child_notify, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, thaw_child_notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_translate_coordinates, 0, 0, 5)
	ZEND_ARG_INFO(0, dest_widget)
	ZEND_ARG_INFO(0, src_x)
	ZEND_ARG_INFO(0, src_y)
	ZEND_ARG_INFO(0, dest_x)
	ZEND_ARG_INFO(0, dest_y)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, translate_coordinates);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_trigger_tooltip_query, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, trigger_tooltip_query);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_unmap, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, unmap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_unparent, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, unparent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_unrealize, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, unrealize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_unregister_window, 0, 0, 1)
	ZEND_ARG_INFO(0, window)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, unregister_window);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtkwidget_unset_state_flags, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

PHP_METHOD(GtkWidget, unset_state_flags);

static zend_class_entry *gtk4_gtkwidget_ce = NULL;
static const zend_function_entry gtkwidget_functions[] = {
	PHP_ME(GtkWidget, __construct, arginfo_gtkwidget___construct, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, activate, arginfo_gtkwidget_activate, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, add_accelerator, arginfo_gtkwidget_add_accelerator, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, add_device_events, arginfo_gtkwidget_add_device_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, add_events, arginfo_gtkwidget_add_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, add_mnemonic_label, arginfo_gtkwidget_add_mnemonic_label, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, can_activate_accel, arginfo_gtkwidget_can_activate_accel, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, child_focus, arginfo_gtkwidget_child_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, child_notify1, arginfo_gtkwidget_child_notify1, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, compute_expand, arginfo_gtkwidget_compute_expand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, create_pango_context, arginfo_gtkwidget_create_pango_context, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, create_pango_layout, arginfo_gtkwidget_create_pango_layout, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, destroy, arginfo_gtkwidget_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, device_is_shadowed, arginfo_gtkwidget_device_is_shadowed, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, draw, arginfo_gtkwidget_draw, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, error_bell, arginfo_gtkwidget_error_bell, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, event, arginfo_gtkwidget_event, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, freeze_child_notify, arginfo_gtkwidget_freeze_child_notify, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_accessible, arginfo_gtkwidget_get_accessible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_action_group, arginfo_gtkwidget_get_action_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_allocated_baseline, arginfo_gtkwidget_get_allocated_baseline, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_allocated_height, arginfo_gtkwidget_get_allocated_height, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_allocated_size, arginfo_gtkwidget_get_allocated_size, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_allocated_width, arginfo_gtkwidget_get_allocated_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_allocation, arginfo_gtkwidget_get_allocation, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_ancestor, arginfo_gtkwidget_get_ancestor, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_app_paintable, arginfo_gtkwidget_get_app_paintable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_can_default, arginfo_gtkwidget_get_can_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_can_focus, arginfo_gtkwidget_get_can_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_child_requisition, arginfo_gtkwidget_get_child_requisition, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_child_visible, arginfo_gtkwidget_get_child_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_clip, arginfo_gtkwidget_get_clip, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_clipboard, arginfo_gtkwidget_get_clipboard, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_composite_name, arginfo_gtkwidget_get_composite_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_device_enabled, arginfo_gtkwidget_get_device_enabled, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_device_events, arginfo_gtkwidget_get_device_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_direction, arginfo_gtkwidget_get_direction, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_display, arginfo_gtkwidget_get_display, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_double_buffered, arginfo_gtkwidget_get_double_buffered, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_events, arginfo_gtkwidget_get_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_focus_on_click, arginfo_gtkwidget_get_focus_on_click, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_font_map, arginfo_gtkwidget_get_font_map, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_font_options, arginfo_gtkwidget_get_font_options, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_frame_clock, arginfo_gtkwidget_get_frame_clock, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_halign, arginfo_gtkwidget_get_halign, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_has_tooltip, arginfo_gtkwidget_get_has_tooltip, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_has_window, arginfo_gtkwidget_get_has_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_hexpand, arginfo_gtkwidget_get_hexpand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_hexpand_set, arginfo_gtkwidget_get_hexpand_set, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_mapped, arginfo_gtkwidget_get_mapped, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_bottom, arginfo_gtkwidget_get_margin_bottom, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_end, arginfo_gtkwidget_get_margin_end, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_left, arginfo_gtkwidget_get_margin_left, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_right, arginfo_gtkwidget_get_margin_right, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_start, arginfo_gtkwidget_get_margin_start, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_margin_top, arginfo_gtkwidget_get_margin_top, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_modifier_mask, arginfo_gtkwidget_get_modifier_mask, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_name, arginfo_gtkwidget_get_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_no_show_all, arginfo_gtkwidget_get_no_show_all, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_opacity, arginfo_gtkwidget_get_opacity, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_pango_context, arginfo_gtkwidget_get_pango_context, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_parent, arginfo_gtkwidget_get_parent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_parent_window, arginfo_gtkwidget_get_parent_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_path, arginfo_gtkwidget_get_path, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_pointer, arginfo_gtkwidget_get_pointer, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_height, arginfo_gtkwidget_get_preferred_height, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_height_and_baseline_for_width, arginfo_gtkwidget_get_preferred_height_and_baseline_for_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_height_for_width, arginfo_gtkwidget_get_preferred_height_for_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_size, arginfo_gtkwidget_get_preferred_size, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_width, arginfo_gtkwidget_get_preferred_width, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_preferred_width_for_height, arginfo_gtkwidget_get_preferred_width_for_height, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_realized, arginfo_gtkwidget_get_realized, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_receives_default, arginfo_gtkwidget_get_receives_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_request_mode, arginfo_gtkwidget_get_request_mode, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_requisition, arginfo_gtkwidget_get_requisition, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_root_window, arginfo_gtkwidget_get_root_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_scale_factor, arginfo_gtkwidget_get_scale_factor, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_screen, arginfo_gtkwidget_get_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_sensitive, arginfo_gtkwidget_get_sensitive, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_settings, arginfo_gtkwidget_get_settings, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_size_request, arginfo_gtkwidget_get_size_request, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_state, arginfo_gtkwidget_get_state, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_state_flags, arginfo_gtkwidget_get_state_flags, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_style_context, arginfo_gtkwidget_get_style_context, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_support_multidevice, arginfo_gtkwidget_get_support_multidevice, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_template_child, arginfo_gtkwidget_get_template_child, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_tooltip_markup, arginfo_gtkwidget_get_tooltip_markup, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_tooltip_text, arginfo_gtkwidget_get_tooltip_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_tooltip_window, arginfo_gtkwidget_get_tooltip_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_toplevel, arginfo_gtkwidget_get_toplevel, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_valign, arginfo_gtkwidget_get_valign, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_valign_with_baseline, arginfo_gtkwidget_get_valign_with_baseline, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_vexpand, arginfo_gtkwidget_get_vexpand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_vexpand_set, arginfo_gtkwidget_get_vexpand_set, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_visible, arginfo_gtkwidget_get_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_visual, arginfo_gtkwidget_get_visual, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, get_window, arginfo_gtkwidget_get_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, grab_default, arginfo_gtkwidget_grab_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, grab_focus, arginfo_gtkwidget_grab_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, has_default, arginfo_gtkwidget_has_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, has_focus, arginfo_gtkwidget_has_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, has_grab, arginfo_gtkwidget_has_grab, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, has_screen, arginfo_gtkwidget_has_screen, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, has_visible_focus, arginfo_gtkwidget_has_visible_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, hide, arginfo_gtkwidget_hide, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, hide_on_delete, arginfo_gtkwidget_hide_on_delete, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, in_destruction, arginfo_gtkwidget_in_destruction, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, init_template, arginfo_gtkwidget_init_template, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, input_shape_combine_region, arginfo_gtkwidget_input_shape_combine_region, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, insert_action_group, arginfo_gtkwidget_insert_action_group, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, intersect, arginfo_gtkwidget_intersect, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_ancestor, arginfo_gtkwidget_is_ancestor, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_composited, arginfo_gtkwidget_is_composited, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_drawable, arginfo_gtkwidget_is_drawable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_focus, arginfo_gtkwidget_is_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_sensitive, arginfo_gtkwidget_is_sensitive, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_toplevel, arginfo_gtkwidget_is_toplevel, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, is_visible, arginfo_gtkwidget_is_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, keynav_failed, arginfo_gtkwidget_keynav_failed, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, list_accel_closures, arginfo_gtkwidget_list_accel_closures, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, list_action_prefixes, arginfo_gtkwidget_list_action_prefixes, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, list_mnemonic_labels, arginfo_gtkwidget_list_mnemonic_labels, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, map, arginfo_gtkwidget_map, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, mnemonic_activate1, arginfo_gtkwidget_mnemonic_activate1, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, override_background_color, arginfo_gtkwidget_override_background_color, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, override_color, arginfo_gtkwidget_override_color, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, override_cursor, arginfo_gtkwidget_override_cursor, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, override_font, arginfo_gtkwidget_override_font, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, override_symbolic_color, arginfo_gtkwidget_override_symbolic_color, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_allocate, arginfo_gtkwidget_queue_allocate, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_compute_expand, arginfo_gtkwidget_queue_compute_expand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_draw, arginfo_gtkwidget_queue_draw, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_draw_area, arginfo_gtkwidget_queue_draw_area, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_draw_region, arginfo_gtkwidget_queue_draw_region, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_resize, arginfo_gtkwidget_queue_resize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, queue_resize_no_redraw, arginfo_gtkwidget_queue_resize_no_redraw, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, realize, arginfo_gtkwidget_realize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, region_intersect, arginfo_gtkwidget_region_intersect, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, register_window, arginfo_gtkwidget_register_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, remove_accelerator, arginfo_gtkwidget_remove_accelerator, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, remove_mnemonic_label, arginfo_gtkwidget_remove_mnemonic_label, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, remove_tick_callback, arginfo_gtkwidget_remove_tick_callback, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, render_icon_pixbuf, arginfo_gtkwidget_render_icon_pixbuf, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, reparent, arginfo_gtkwidget_reparent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, reset_style, arginfo_gtkwidget_reset_style, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, send_expose, arginfo_gtkwidget_send_expose, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, send_focus_change, arginfo_gtkwidget_send_focus_change, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_accel_path, arginfo_gtkwidget_set_accel_path, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_allocation, arginfo_gtkwidget_set_allocation, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_app_paintable, arginfo_gtkwidget_set_app_paintable, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_can_default, arginfo_gtkwidget_set_can_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_can_focus, arginfo_gtkwidget_set_can_focus, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_child_visible, arginfo_gtkwidget_set_child_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_clip, arginfo_gtkwidget_set_clip, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_composite_name, arginfo_gtkwidget_set_composite_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_device_enabled, arginfo_gtkwidget_set_device_enabled, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_device_events, arginfo_gtkwidget_set_device_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_direction, arginfo_gtkwidget_set_direction, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_double_buffered, arginfo_gtkwidget_set_double_buffered, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_events, arginfo_gtkwidget_set_events, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_focus_on_click, arginfo_gtkwidget_set_focus_on_click, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_font_map, arginfo_gtkwidget_set_font_map, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_font_options, arginfo_gtkwidget_set_font_options, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_halign, arginfo_gtkwidget_set_halign, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_has_tooltip, arginfo_gtkwidget_set_has_tooltip, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_has_window, arginfo_gtkwidget_set_has_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_hexpand, arginfo_gtkwidget_set_hexpand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_hexpand_set, arginfo_gtkwidget_set_hexpand_set, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_mapped, arginfo_gtkwidget_set_mapped, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_bottom, arginfo_gtkwidget_set_margin_bottom, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_end, arginfo_gtkwidget_set_margin_end, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_left, arginfo_gtkwidget_set_margin_left, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_right, arginfo_gtkwidget_set_margin_right, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_start, arginfo_gtkwidget_set_margin_start, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_margin_top, arginfo_gtkwidget_set_margin_top, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_name, arginfo_gtkwidget_set_name, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_no_show_all, arginfo_gtkwidget_set_no_show_all, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_opacity, arginfo_gtkwidget_set_opacity, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_parent, arginfo_gtkwidget_set_parent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_parent_window, arginfo_gtkwidget_set_parent_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_realized, arginfo_gtkwidget_set_realized, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_receives_default, arginfo_gtkwidget_set_receives_default, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_redraw_on_allocate, arginfo_gtkwidget_set_redraw_on_allocate, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_sensitive, arginfo_gtkwidget_set_sensitive, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_size_request, arginfo_gtkwidget_set_size_request, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_state, arginfo_gtkwidget_set_state, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_state_flags, arginfo_gtkwidget_set_state_flags, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_support_multidevice, arginfo_gtkwidget_set_support_multidevice, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_tooltip_markup, arginfo_gtkwidget_set_tooltip_markup, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_tooltip_text, arginfo_gtkwidget_set_tooltip_text, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_tooltip_window, arginfo_gtkwidget_set_tooltip_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_valign, arginfo_gtkwidget_set_valign, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_vexpand, arginfo_gtkwidget_set_vexpand, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_vexpand_set, arginfo_gtkwidget_set_vexpand_set, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_visible, arginfo_gtkwidget_set_visible, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_visual, arginfo_gtkwidget_set_visual, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, set_window, arginfo_gtkwidget_set_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, shape_combine_region, arginfo_gtkwidget_shape_combine_region, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, show, arginfo_gtkwidget_show, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, show_all, arginfo_gtkwidget_show_all, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, show_now, arginfo_gtkwidget_show_now, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, size_allocate, arginfo_gtkwidget_size_allocate, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, size_allocate_with_baseline, arginfo_gtkwidget_size_allocate_with_baseline, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, size_request, arginfo_gtkwidget_size_request, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, style_get, arginfo_gtkwidget_style_get, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, style_get_property, arginfo_gtkwidget_style_get_property, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, style_get_valist, arginfo_gtkwidget_style_get_valist, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, thaw_child_notify, arginfo_gtkwidget_thaw_child_notify, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, translate_coordinates, arginfo_gtkwidget_translate_coordinates, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, trigger_tooltip_query, arginfo_gtkwidget_trigger_tooltip_query, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, unmap, arginfo_gtkwidget_unmap, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, unparent, arginfo_gtkwidget_unparent, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, unrealize, arginfo_gtkwidget_unrealize, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, unregister_window, arginfo_gtkwidget_unregister_window, ZEND_ACC_PUBLIC)
	PHP_ME(GtkWidget, unset_state_flags, arginfo_gtkwidget_unset_state_flags, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif
