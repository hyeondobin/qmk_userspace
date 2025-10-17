#include "repeat.h"
#include <stdint.h>
#include "action.h"
#include "keycodes.h"

uint16_t last_keycode = KC_NO;
bool     tap_undead_key(bool key_down, uint16_t code);

uint16_t last_key(void) {
    return last_keycode;
}

void register_key_to_repeat(uint16_t keycode) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = keycode & 0xFF;
            break;
    }
    uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_CTRL) keycode |= QK_LCTL;
    if (mods & MOD_MASK_SHIFT) keycode |= QK_LSFT;
    if (mods & MOD_MASK_GUI) keycode |= QK_LGUI;
    if (mods & MOD_BIT(KC_LALT)) keycode |= QK_LALT;
    last_keycode = keycode;
}

void update_key(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}

void update_repeat_key(keyrecord_t *record) {
    switch (last_keycode) {
        case GRV:
            tap_undead_key(record->event.pressed, KC_GRV);
            break;
        case TILD:
            tap_undead_key(record->event.pressed, KC_TILD);
            break;
        case CIRC:
            tap_undead_key(record->event.pressed, KC_CIRC);
            break;
        default:
            update_key(last_keycode, record);
    }
}

void update_reverse_key_pairs(uint16_t a, uint16_t b, keyrecord_t *record) {
    if (last_keycode == a) {
        update_key(b, record);
    } else if (last_keycode == b) {
        update_key(a, record);
    }
}

void update_reverse_repeat_key(keyrecord_t *record) {
    update_reverse_key_pairs(C(KC_TAB), C(S(KC_TAB)), record);
}
