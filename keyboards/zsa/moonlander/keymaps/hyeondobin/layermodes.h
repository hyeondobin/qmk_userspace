#pragma once

#include QMK_KEYBOARD_H

// Check whether numword is on
bool num_word_enabled(void);

// Enable numword
void enable_num_world(void);

// Disable numword
void disable_num_world(void);

// Process numword activation, to be placed in porcess user as a keycode
void process_num_word_activation(const keycode_t *record);

// Process numword, to be placed in process user
bool process_num_word(uint16_t keycode, const keycode_t *record);
