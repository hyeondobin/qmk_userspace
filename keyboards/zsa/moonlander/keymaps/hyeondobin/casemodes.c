#include "casemodes.h"
#include "action.h"
#include "action_util.h"
#include "host.h"
#include "modifiers.h"
#include "status.h"
#include "keycodes.h"

#include "config.h"

#ifndef DEFAULT_XCASE_SEPARATOR
#    define DEFAULT_XCASE_SEPARATOR KC_UNDS
#endif /* ifndef DEFAULT_XCASE_SEPARATOR */

#define IS_OSM(keycode) (keycode >= QK_ONE_SHOT_MOD && keycode <= QK_ONE_SHOT_MOD_MAX)

enum xcase_state {
    XCASE_OFF = 0,
    XCASE_ON,
    XCASE_WAIT,
};

// bool to keep track of the caps word state
static bool caps_word_on = false;

// enum to keep track of the xcase state
static enum xcase_state xcase_state = XCASE_OFF;
// the keycode of the xcase delimiter
static uint16_t xcase_delimiter;

bool caps_word_enabled(void) {
    return caps_word_on;
}

void enable_caps_word(void) {
    caps_word_on = true;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(is_caps_swapped() ? KC_ESC : KC_CAPS);
    }
}

// Disable caps word
void disable_caps_word(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(is_caps_swapped() ? KC_ESC : KC_CAPS);
    }
}

// Toggle caps word
void toggle_caps_word(void) {
    if (caps_word_on) {
        disable_caps_word();
    } else {
        enable_caps_word();
    }
}

// Check whether xcase is on
bool xcase_enabled(void) {
    return xcase_state == XCASE_ON;
}

// Check whether xcase is waiting for a keypress
bool xcase_waiting(void) {
    return xcase_state == XCASE_WAIT;
}

// Enable xcase and pickup the next keystroke as the delimiter
void enable_xcase(void) {
    xcase_state = XCASE_WAIT;
}

void enable_xcase_with(uint16_t delimiter) {
    xcase_state     = XCASE_ON;
    xcase_delimiter = delimiter;
}

// Disable xcase
void disable_xcase(void) {
    xcase_state = XCASE_OFF;
}

// Place the current xcase delimiter
static void place_delimiter(void) {
    switch (xcase_delimiter) {
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX: {
            uint8_t mods = xcase_delimiter & 0x10 ? (xcase_delimiter & 0x0F) << 4 : xcase_delimiter & 0xFF;
            set_oneshot_mods(mods);
            break;
        }
        default:
            tap_code16(xcase_delimiter);
            break;
    }
}

// override function to determine whether the case mode should stop
__attribute__((weak)) bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

__attribute__((weak)) bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    return false;
}

bool process_case_modes(uint16_t keycode, const keyrecord_t *record) {
    if (xcase_state == XCASE_WAIT) {
        // grab the next input to be the delimiter
        if (use_default_xcase_separator(keycode, record)) {
            enable_xcase_with(DEFAULT_XCASE_SEPARATOR);
        } else if (record->event.pressed) {
            if (keycode > QK_MODS_MAX || IS_MODIFIER_KEYCODE(keycode)) {
                // let special keys and normal modifiers go through
                return true;
            } else {
                // factor in mods
                if (get_mods() & MOD_MASK_SHIFT) {
                    keycode = LSFT(keycode);
                }
                enable_xcase_with(keycode);
                return false;
            }
            return false;
        } else {
            if (IS_OSM(keycode)) {
                // this catches the OSM release if no other key was pressed
                set_oneshot_mods(0);
                enable_xcase_with(keycode);
            }
            return true;
        }
    }

    if (caps_word_on || xcase_state) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                if (record->tap.count == 0) return true;
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }
        if (record->event.pressed) {
            // handle xcase mode
            if (xcase_state == XCASE_ON) {
                // place the delimiter if needed
                if (keycode == XCASE_DELIMITER_KEY) {
                    place_delimiter();
                    return false;
                }
            } // end XCASE_ON

            // check if the case modes have been terminated
            if (terminate_case_modes(keycode, record)) {
                disable_caps_word();
                disable_xcase();
            }
        }
        return true;
    }
    return true;
}
