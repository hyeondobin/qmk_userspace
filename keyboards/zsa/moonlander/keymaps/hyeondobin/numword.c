#include "numword.h"
#include "keycodes.h"
#include "print.h"

static bool _num_word_enabled = false;
bool        num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    if (!_num_word_enabled) {
        _num_word_enabled = true;
    }
    layer_on(_NUM);
}

void disable_num_word(void) {
    if (_num_word_enabled) {
        printf("Disable NUMWORD\n");
    }
    _num_word_enabled = false;
    layer_off(_NUM);
}

void process_num_word_activation(const keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }

    if (num_word_enabled()) {
        printf("Enable NUM layer\n");
        _num_word_enabled = false;
    } else {
        printf("Enable NUMWORD\n");
        enable_num_word();
    }
}

bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0) return true;
            keycode = keycode & 0xFF;
    }

    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_PERC:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_MINS:
        case KC_ASTR:
        case KC_PLUS:
        case KC_COLN:
        case KC_EQL:
        case KC_UNDS:
        case KC_BSPC:
        case KC_X:
        case REPEAT:
        case KC_ENT:
        case xxxxxxx:
        case NUMWORD:
            break;
        case CLEAR:
            if (record->event.pressed) {
                disable_num_word();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}
