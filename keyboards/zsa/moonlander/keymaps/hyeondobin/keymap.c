/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdint.h>
#include "action.h"
#include "action_layer.h"
#include "action_util.h"
#include "modifiers.h"
#include "process_key_override.h"
#include "process_repeat_key.h"
#include "quantum.h"
#include "repeat_key.h"

#include "keycodes.h"
#include "numword.h"
#include "smart_mouse.h"
#include "dobih.h"

#include "g/keymap_combo.h"

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L',        'L',        'L',        'L',        'L',        'L',        'L',            'R',        'R',        'R',        'R',        'R',        'R',        'R',
        'L',        'L',        'L',        'L',        'L',        'L',        'L',            'R',        'R',        'R',        'R',        'R',        'R',        'R',
        'L',        'L',        'L',        'L',        'L',        'L',        'L',            'R',        'R',        'R',        'R',        'R',        'R',        'R',
        'L',        'L',        'L',        'L',        'L',        'L',                                    'R',        'R',        'R',        'R',        'R',        'R',
        'L',        'L',        'L',        'L',        'L',                    '*',            '*',                    'R',        'R',        'R',        'R',        'R',
                                                        '*',        '*',        '*',            '*',        '*',        '*');

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT(
        KC_EQL,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       XXXXXXX,        XXXXXXX,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        MO(_MOU),   KC_B,       KC_L,       KC_D,       KC_C,       KC_V,       MS_WHLU,        XXXXXXX,    KC_J,       KC_Y,       KC_O,       KC_U,       KC_UNDS,    XXXXXXX,
        KC_MEH,     HR_N,       HR_R,       HR_T,       HR_S,       KC_G,       MS_WHLD,        XXXXXXX,    KC_P,       HR_H,       HR_A,       HR_E,       HR_I,       KC_MEH,
        XXXXXXX,    KC_X,       KC_Q,       KC_M,       KC_W,       KC_Z,                                   KC_K,       KC_F,       KC_COMM,    KC_DOT,     KC_QUES,    XXXXXXX,
        MO(_SYM),   XXXXXXX,    XXXXXXX,    XXXXXXX,    LITHUMB,                KC_LNG1,        TG(_QWE),               RITHUMB,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        LMTHUMB,    LOTHUMB,    MO(_MOU),       XXXXXXX,    ROTHUMB,    RMTHUMB
    ),


    [_QWE] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,        _______,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
        _______,    QW_A,       QW_S,       QW_D,       QW_F,       KC_G,       _______,        KC_B,       KC_H,       QW_J,       QW_K,       QW_L,       QW_UNDS,    _______,
        _______,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     _______,    _______,
        _______,    _______,    _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_MOU] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   EGDOBIN,     EGJAYLI,    EGPANRU,    ENDOBIN,    _______,    _______,        _______,    MS_BTN4,    MS_WHLL,    MS_UP,      MS_WHLR,    MS_WHLU,    _______,
        _______,   USRNAME,     MS_BTN3,    MS_BTN2,    MS_BTN1,    _______,    _______,        _______,    MS_BTN5,    MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLD,    _______,
        _______,   KC_LGUI,     KC_LALT,    KC_LSFT,    KC_LCTL,    _______,                                _______,    KC_LCTL,    KC_LSFT,    KC_LALT,    KC_LGUI,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    CLEAR,      MS_ACL0
    ),

    [_NAV] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    KC_LPRN,    KC_RPRN,    _______,    _______,        _______,    _______,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    _______,
        _______,   KC_LGUI,     KC_LALT,    KC_LSFT,    KC_LCTL,    _______,    _______,        _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    _______,
        _______,   _______,     _______,    KC_LCBR,    KC_RCBR,    _______,                                _______,    KC_LBRC,    KC_RBRC,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_SYM] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   KC_GRV,      KC_LABK,    KC_RABK,    KC_MINS,    KC_PIPE,    _______,        _______,    KC_CIRC,    KC_LCBR,    KC_RCBR,    KC_DLR,     ARROW,      _______,
        _______,   KC_BSLS,     KC_ASTR,    KC_SLSH,    KC_EQL,     KC_AMPR,    _______,        _______,    KC_HASH,    KC_LPRN,    KC_RPRN,    KC_SCLN,    KC_DQUO,    _______,
        _______,   KC_TILD,     KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_PERC,                                KC_AT,      KC_COLN,    KC_COMM,    KC_DOT,     KC_QUOT,    _______,
        EE_CLR,    AU_TOGG,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    TG(_LED),   _______
    ),

    [_NUM] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   KC_B,        KC_W,       KC_E,       _______,    _______,    _______,        _______,    KC_J,       KC_H,       KC_L,       ATU,        _______,    _______,
        _______,   KC_6,        KC_4,       KC_0,       KC_2,       _______,    _______,        _______,    _______,    KC_3,       KC_1,       KC_5,       KC_7,       _______,
        _______,   KC_COMM,     _______,    NUM_G,      KC_8,       _______,                                KC_K,       KC_9,       _______,    _______,    KC_UNDS,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    CLEAR,      _______
    ),
    [_LED] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   RM_HUEU,     RM_SATU,    RM_VALU,    RM_SPDU,    RM_NEXT,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   RM_HUED,     RM_SATD,    RM_VALD,    RM_SPDD,    RM_PREV,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    RM_OFF,     RM_ON,      _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    CLEAR,      _______
                    ),
    [_FNC] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   KC_F6,       KC_F4,      KC_F10,     KC_F2,      KC_F12,     _______,        _______,    KC_F11,     KC_F3,      KC_F1,      KC_F5,      KC_F7,      _______,
        _______,   _______,     _______,    _______,    KC_F8,      _______,                                _______,    KC_F9,      _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    CLEAR,      _______
    ),
    [_GUI] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   G(KC_B),     G(KC_L),    G(KC_D),    G(KC_C),    G(KC_V),    _______,        _______,    G(KC_J),    G(KC_Y),    G(KC_O),    G(KC_U),    G(KC_UNDS), _______,
        KC_BSPC,   HR_N,        HR_R,       HR_T,       HR_S,       KC_G,       _______,        _______,    KC_P,       HR_H,       HR_A,       HR_E,       HR_I,       _______,
        _______,   KC_X,        KC_Q,       KC_M,       KC_W,       KC_Z,                                   KC_K,       KC_F,       KC_COMM,    KC_DOT,     KC_QUES,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_TRS] = LAYOUT( // for creating new layout
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),
};

// clang-format on

// Utils
// static uint16_t last_key_down = KC_NO;

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case REPEAT:
        case CAPSWORD:
        case NUMWORD:
        case ALTRPT:
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case QU:
        case SC:
        case KC_MINS:
        case KC_UNDS:
        case KC_DOT:
        case KC_COMM:
        case KC_DEL:
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            } else {
                return false;
            }
        default:
            return record->event.pressed;
    }
}

// key override
const key_override_t ques_exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t comm_labk_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t dot_rabk_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t cs_labk_override   = ko_make_basic(MOD_MASK_CS, KC_COMM, KC_LABK);
const key_override_t cs_rabk_override   = ko_make_basic(MOD_MASK_CS, KC_DOT, KC_RABK);

const key_override_t *key_overrides[] = {
    &ques_exlm_override, &comm_labk_override, &dot_rabk_override, &cs_labk_override, &cs_rabk_override,
};

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    if (keycode == REPEAT) {
        return false;
    }
    return true;
}

void disable_oneshot_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_smart_mouse(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case REPEAT:
            if (record->tap.count) { // On tap.
                // For alternate repeat key, replace the next line with
                // alt_repeat_key_invoke(&record->event);
                repeat_key_invoke(&record->event); // Repeat the last key.
                return false;
            }
            return true;
        case QW_UNDS:
            if (record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            return true;
            // case SYMBOL:
            //     if (record->tap.count) {
            //         tap_code16(OSL(_SYM));
            //         return false;
            //     }
        case OS_SFT_LT_NAV:
            if (record->tap.count) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            } else if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
    }
    if (record->event.pressed) {
        switch (keycode) {
            case NUMWORD:
                process_num_word_activation(record);
                return false;
            case SMMOUSE:
                process_smart_mouse_activation(record);
                return false;
            case EGDOBIN:
                send_string("dobinhyeon@gmail.com");
                return false;
            case EGJAYLI:
                send_string("jayli2558@gmail.com");
                return false;
            case EGPANRU:
                send_string("panruyal@gmail.com");
                return false;
            case TG_KOR:
                tap_code(KC_LNG1);
                layer_invert(_QWE);
                return false;
            case SUNDAY:
                send_string("1251");
                tap_code(KC_ENT);
                return false;
            case USRNAME:
                send_string("hyeondobin");
                return false;
            case CLEAR:
                layer_off(_NUM);
                layer_off(_SYM);
                layer_off(_NAV);
                layer_off(_LED);
                layer_off(_FNC);
                // layer_move(_BAS);
                return false;
            case QWE_BAS:
                layer_off(_QWE);
                tap_code(KC_ENT);
                return false;
            case WSLFLSH:
                send_string("qfw");
                tap_code(KC_ENT);
                reset_keyboard();
                return false;
            case ATU:
                tap_code16(KC_AT);
                tap_code(KC_U);
                return false;
            case NUM_G:
                tap_code16(S(KC_G));
                return false;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //     const uint8_t mods     = get_mods();
    //     const uint8_t all_mods = (mods | get_weak_mods()
    // #ifndef NO_ACTION_ONESHOT
    //                               | get_oneshot_mods()
    // #endif
    //                               );
    //
    //     const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
    //     const bool    alt        = all_mods & MOD_BIT_LALT;

    bool res = _process_record_user(keycode, record);

    // reset_oneshot_layer();

    return res;
}
