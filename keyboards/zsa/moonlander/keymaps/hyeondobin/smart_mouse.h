#pragma once

#include QMK_KEYBOARD_H

bool smart_mouse_enabled(void);

void enable_smart_mouse(void);
void disable_smart_mouse(void);

void process_smart_mouse_activation(const keyrecord_t *record);

bool process_smart_mouse(uint16_t keycode, const keyrecord_t *record);
