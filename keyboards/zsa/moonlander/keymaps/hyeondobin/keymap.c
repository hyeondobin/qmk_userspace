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
#include <stdint.h>
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "status.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"

#include "g/keymap_combo.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

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
        KC_DEL,     KC_B,       KC_L,       KC_D,       KC_C,       KC_V,       XXXXXXX,        XXXXXXX,    KC_J,       KC_Y,       KC_O,       KC_U,       KC_QUOT,    XXXXXXX,
        KC_BSPC,    HR_N,       HR_R,       HR_T,       HR_S,       KC_G,       XXXXXXX,        XXXXXXX,    KC_P,       HR_H,       HR_A,       HR_E,       HR_I,       XXXXXXX,
        XXXXXXX,    KC_X,       KC_Q,       KC_M,       KC_W,       KC_Z,                                   KC_K,       KC_F,       KC_COMM,    KC_DOT,     KC_QUES,    XXXXXXX,
        MO(_SYM),   XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ESC,                 KC_LNG1,        TG(_QWE),               MO(_NUM),   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        RPSHFT,    MO(_MOU),     MO(_MOU),       XXXXXXX,    KC_BSPC,    SPC_NAV
    ),

    [_QWE] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,        _______,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
        _______,    QW_A,       QW_S,       QW_D,       QW_F,       KC_G,       _______,        KC_B,       KC_H,       QW_J,       QW_K,       QW_L,       QW_SCLN,    _______,
        _______,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     _______,    _______,
        _______,    _______,    _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_MOU] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   EGDOBIN,     EGJAYLI,    EGPANRU,    ENDOBIN,    _______,    _______,        _______,    MS_BTN4,    MS_WHLL,    MS_UP,      MS_WHLR,    MS_WHLU,    _______,
        _______,   _______,     MS_BTN3,    MS_BTN2,    MS_BTN1,    _______,    _______,        _______,    MS_BTN5,   MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLD,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    MS_ACL0
    ),

    [_NAV] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    KC_LPRN,    KC_RPRN,    _______,    _______,        _______,    _______,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    _______,
        _______,   _______,     _______,    KC_LBRC,    KC_RBRC,    _______,    _______,        _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    _______,
        _______,   _______,     _______,    KC_LCBR,    KC_RCBR,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,                _______,        _______,                _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_SYM] = LAYOUT(
        VRSN,      KC_F1,       KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,        _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,   KC_EXLM,     KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    _______,        _______,    KC_UP,      KC_7,       KC_8,       KC_9,       KC_ASTR,    KC_F12,
        _______,   KC_HASH,     KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,     _______,        _______,    KC_DOWN,    KC_4,       KC_5,       KC_6,       KC_PLUS,    _______,
        _______,   KC_PERC,     KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,                                KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLS,    _______,
        EE_CLR,    AU_TOGG,     _______,    _______,    _______,                RM_VALU,        RM_TOGG,                _______,    KC_DOT,     KC_0,       KC_EQL,     _______,
                                                        RM_HUED,    RM_VALD,    RM_HUEU,        XXXXXXX,    _______,    _______
    ),

    [_NUM] = LAYOUT(
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,   _______,     _______,    _______,    _______,    _______,    _______,        _______,    KC_J,       _______,    _______,    _______,    _______,    _______,
        _______,   KC_6,        KC_4,       KC_0,       KC_2,       _______,    _______,        _______,    _______,    KC_3,       KC_1,       KC_5,       KC_7,       _______,
        _______,   KC_COMM,     _______,    NUM_G,      KC_8,       _______,                                KC_K,       KC_9,       KC_LPRN,    KC_RPRN,    KC_UNDS,    _______,
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

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up = KC_NO;

static bool swap_caps_escape = false;
bool is_caps_swapped(void) {
    return swap_caps_escape;
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

void swap_caps_esc(void) {
    swap_caps_escape = !swap_caps_escape;
    #ifdef OLED_DRIVER_ENABLE
    oled_on();
#endif
}

bool process_caps(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
    }
    return true;
}

bool process_escape(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_CAPS);
        } else {
            unregister_code(KC_CAPS);
        }
        return false;
    }
    return true;
}

void tap_escape(void) {
    tap_code(swap_caps_escape ? KC_CAPS : KC_ESC);
}

void tap_caps_lock(void) {
    tap_code(swap_caps_escape ? KC_ESC : KC_CAPS);
}

void tap_space_shift(uint16_t key, bool key_down) {
    if (key_down) {
        tap_code16(key);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code(KC_SPC);
    double_tap(keycode);
    tap_code(KC_SPC);
}

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case L_BRACKET:
        case R_BRACKET:
        default:
            return COMBO_TERM;
    }
}

//Case modes

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case REPEAT:
            return false;
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
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

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
        case TAB_MOD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

// Tap hold

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case QU:
        case SC:
            return true;
            default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case QU:
        send_string("qu");
        return;
        case SC:
        send_string("sc");
        return;
        case CLOSE_WIN:
        tap_code16(C(KC_W));
        tap_code(KC_Q);
        return;
        default:
        tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
            double_tap(keycode);
        return;
        case KC_DQUO:
        case KC_DOT:
        case KC_0:
        triple_tap(keycode);
        return;
        case KC_PERC:
        send_string("%{}");
        return;
            case KC_AT:
        tap_code16(KC_AT);
        tap16_repeatable(KC_U);
        return;
    }
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

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!pcrocess_leader(keycode, record)) {
    //     return false;
    // }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_tap_hold(keycode, record)) {
        if (record->event.pressed) {
            register_key_to_repeat(keycode);
        }
        return false;
    }

    switch (keycode) {
        case ESC_SYM:
            if (record->tap.count && record->event.pressed) {
                tap_escape();
                return false;
            }
            break;
        case KC_CAPS:
            return process_caps(record->event.pressed);
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            // stop_leading();
            layer_off(_NUM);
            layer_off(_SYM);
            layer_move(_BAS);
            // stop_leading();
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_escape();
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case TG_KOR:
            if (record->event.pressed) {
                layer_invert(_QWE);
                tap_code(KC_LNG1);
            }
            return false;
        case REPEAT:
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case KC_ENT:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_NUM)) {
                    tap16_repeatable(KC_PENT);
                } else {
                    tap16_repeatable(KC_ENT);
                }
                disable_num_word();
            }
            return false;
        case SUNDAY:
            if (record->event.pressed) {
                SEND_STRING("1251");
                tap_code(KC_ENT);
            }
        return false;
    case EGDOBIN:
            if (record->event.pressed) {
                SEND_STRING("dobinhyeon@gmail.com");
            }
        return false;
    case EGJAYLI:
            if (record->event.pressed) {
                SEND_STRING("jayli2558@gmail.com");
            }
        return false;
    case EGPANRU:
            if (record->event.pressed) {
                SEND_STRING("panruyal@gmail.com");
            }
        return false;
    case ENDOBIN:
            if (record->event.pressed) {
                SEND_STRING("hyeondobin@naver.com");
            }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register keyrepeat here by default.
    bool res = _process_record_user(keycode, record);

    // Space needs some special handling to not interfere with NAV toggling.
    // Maybe there's a more general way to do this, but I don't know.
    if (keycode == SPC_NAV) {
        if (!record->event.pressed && last_key_down == SPC_NAV) {
            register_key_to_repeat(KC_SPC);
        }
    } else if (res && record->event.pressed) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    if (record->event.pressed) {
        last_key_down = keycode;
    } else {
        last_key_up = keycode;
    }
    return res;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}
