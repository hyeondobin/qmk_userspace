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

#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include "process_key_override.h"
#include QMK_KEYBOARD_H
#include "version.h"

#include "g/keymap_combo.h"

#define HR_N GUI_T(KC_N)
#define HR_R ALT_T(KC_R)
#define HR_T SFT_T(KC_T)
#define HR_S CTL_T(KC_S)
#define HR_H CTL_T(KC_H)
#define HR_A SFT_T(KC_A)
#define HR_E ALT_T(KC_E)
#define HR_I GUI_T(KC_I)

// #ifdef CONSOLE_ENABLE
// #   include "print.h"
// #endif

// enum layers {
//     _BASE,  // default layer
//     _QWERTY,
//     // _NAVI,
//     _TRANS, // for easy layering
//     _MOUSE,
//     _NUMBER,
//     _SYMBOL,  // symbols always on top
// };

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L',         'L',         'L',          'L',         'L',         'L',     'L',               'R',        'R',     'R',         'R',            'R',            'R',         'R',
        'L',         'L',         'L',          'L',         'L',         'L',     'L',               'R',        'R',     'R',         'R',            'R',            'R',         'R',
        'L',         'L',         'L',          'L',         'L',         'L',     'L',               'R',        'R',     'R',         'R',            'R',            'R',         'R',
        'L',         'L',         'L',          'L',         'L',         'L',                                    'R',     'R',         'R',            'R',            'R',         'R',
        'L',         'L',         'L',          'L',         'L',                  '*',               '*',                 'R',         'R',            'R',            'R',         'R',
                                                             '*',         '*',     '*',               '*',        '*',     '*');

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_EQL,      KC_1,        KC_2,         KC_3,        KC_4,        KC_5,    XXXXXXX,           XXXXXXX,    KC_6,    KC_7,        KC_8,           KC_9,           KC_0,        KC_MINS,
        KC_DEL,      KC_B,        KC_L,         KC_D,        KC_C,        KC_V,    XXXXXXX,           XXXXXXX,    KC_J,    KC_Y,        KC_O,           KC_U,           KC_QUOT,     XXXXXXX,
        KC_BSPC,     HR_N,        HR_R,         HR_T,        HR_S,        KC_G,    XXXXXXX,           XXXXXXX,    KC_P,    HR_H,        HR_A,           HR_E,           HR_I,        XXXXXXX,
        XXXXXXX,     KC_X,        KC_Q,         KC_M,        KC_W,        KC_Z,                                   KC_K,    KC_F,        KC_COMM,        KC_DOT,         KC_QUES,     XXXXXXX,
        MO(_SYMBOL), XXXXXXX,     XXXXXXX,      XXXXXXX,     KC_ESC,               KC_LNG1,           TG(_QWERTY),         MO(_NUMBER), XXXXXXX,        XXXXXXX,        XXXXXXX,     XXXXXXX,
                                                             KC_LSFT,     KC_ENT,  MO(_MOUSE),        XXXXXXX,    KC_BSPC, KC_SPC
    ),
    [_QWERTY] = LAYOUT(
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   KC_Q,    KC_W,         KC_E,        KC_R,        KC_T,    _______,           _______,    KC_Y,    KC_U,        KC_I,           KC_O,           KC_P,        _______,
        _______,   KC_A,    KC_S,         KC_D,        KC_F,        KC_G,    _______,           KC_B,       KC_H,    KC_J,        KC_K,           KC_L,           KC_SCLN,     _______,
        _______,   KC_Z,    GUI_T(KC_X),  ALT_T(KC_C), CTL_T(KC_V), KC_B,                                   KC_N,    CTL_T(KC_M), ALT_T(KC_COMM), GUI_T(KC_DOT),  _______,     _______,
        _______,   _______, _______,      _______,     _______,              _______,           _______,             _______,     _______,        _______,        _______,     _______,
                                                       _______,     _______, _______,           _______,    _______, _______
    ),

    [_TRANS] = LAYOUT(
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,     _______,                                _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,              _______,           _______,             _______,     _______,        _______,        _______,     _______,
                                                       _______,     _______, _______,           _______,    _______, _______
    ),

    [_SYMBOL] = LAYOUT(
        VRSN,      KC_F1,   KC_F2,        KC_F3,       KC_F4,       KC_F5,   _______,           _______,    KC_F6,   KC_F7,       KC_F8,          KC_F9,          KC_F10,      KC_F11,
        _______,   KC_EXLM, KC_AT,        KC_LCBR,     KC_RCBR,     KC_PIPE, _______,           _______,    KC_UP,   KC_7,        KC_8,           KC_9,           KC_ASTR,     KC_F12,
        _______,   KC_HASH, KC_DLR,       KC_LPRN,     KC_RPRN,     KC_GRV,  _______,           _______,    KC_DOWN, KC_4,        KC_5,           KC_6,           KC_PLUS,     _______,
        _______,   KC_PERC, KC_CIRC,      KC_LBRC,     KC_RBRC,     KC_TILD,                                KC_AMPR, KC_1,        KC_2,           KC_3,           KC_BSLS,     _______,
        EE_CLR,    AU_TOGG, _______,      _______,     _______,              RM_VALU,           RM_TOGG,             _______,     KC_DOT,         KC_0,           KC_EQL,      _______,
                                                       RM_HUED,     RM_VALD, RM_HUEU,           XXXXXXX,    _______, _______
    ),

    [_MOUSE] = LAYOUT(
        LED_LEVEL, _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     QK_BOOT,
        _______,   _______, _______,      MS_UP,       _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, MS_LEFT,      MS_DOWN,     MS_RGHT,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     KC_MPLY,
        _______,   _______, _______,      _______,     _______,     _______,                                _______, _______,     KC_MPRV,        KC_MNXT,        _______,     _______,
        _______,   _______, _______,      MS_BTN1,     MS_BTN2,              _______,           _______,             KC_VOLU,     KC_VOLD,        KC_MUTE,        _______,     _______,
                                                       _______,     _______, _______,           _______,    _______, _______
    ),
    [_NUMBER] = LAYOUT(
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    _______, _______,     _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,     _______, _______,           _______,    KC_J,    _______,     _______,        _______,        _______,     _______,
        _______,   KC_6,    KC_4,         KC_0,        KC_2,        _______, _______,           _______,    _______, KC_3,        KC_1,           KC_5,           KC_7,        _______,
        _______,   _______, _______,      _______,     KC_8,        _______,                                KC_K,    KC_9,        _______,        _______,        _______,     _______,
        _______,   _______, _______,      _______,     _______,              _______,           _______,             _______,     _______,        _______,        _______,     _______,
                                                       _______,     _______, _______,           _______,    _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

const key_override_t ques_expm_override = ko_make_basic(
    MOD_MASK_SHIFT, KC_QUES, KC_EXLM
);
const key_override_t comma_smcolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t comma_A_bracket_override = ko_make_basic(MOD_MASK_CS, KC_COMM, KC_LABK);
const key_override_t dot_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t dot_A_bracket_override = ko_make_basic(MOD_MASK_CS, KC_DOT, KC_RABK);

const key_override_t *key_overrides[] = {
    &ques_expm_override,
    &comma_A_bracket_override,
    &comma_smcolon_override,
    &dot_A_bracket_override,
    &dot_colon_override
};
