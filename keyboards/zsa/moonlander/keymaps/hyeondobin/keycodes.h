#pragma once

#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
    _BAS = 0,
    _QWE,
    _TRS,
    _NUM,
    _NAV,
    _MOU,
    _SYM,
    _LED,
    _FNC,
    _GUI,
};

enum custom_keycodes {
    ARROW = QK_USER,
    TILD,

    // layer keys
    SPC_NAV,
    ESC_SYM,
    FNC_MOU,

    // Positional key refs
    LITHUMB,
    LMTHUMB,
    LOTHUMB,
    RITHUMB,
    RMTHUMB,
    ROTHUMB,

    // Multiple chars
    QU,
    ATU,
    SC,
    USRNAME,

    QWE_BAS,
    WSLFLSH,

    SUNDAY,

    // email addresses
    EGDOBIN,
    EGJAYLI,
    EGPANRU,
    ENDOBIN,

    // Vim
    SAVE_VIM,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Custom Win + Alt for window toggling on Windows
    WIN_ALT,

    // Smart caps lock and layers that turn off on certain keys
    NUMWORD,
    SYMBOL,
    SMMOUSE,

    // Layer management
    CANCEL,
    CLEAR,

    TG_KOR,

    // Instant leader key
    LEADER,

    VRSN, //= SAFE_RANGE,

    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    TAB_MOD
};

#define HR_N GUI_T(KC_N)
#define HR_R ALT_T(KC_R)
#define HR_T SFT_T(KC_T)
#define HR_S CTL_T(KC_S)
#define HR_H CTL_T(KC_H)
#define HR_A SFT_T(KC_A)
#define HR_E ALT_T(KC_E)
#define HR_I GUI_T(KC_I)

#define QW_A GUI_T(KC_A)
#define QW_S ALT_T(KC_S)
#define QW_D SFT_T(KC_D)
#define QW_F CTL_T(KC_F)

#define QW_J CTL_T(KC_J)
#define QW_K SFT_T(KC_K)
#define QW_L ALT_T(KC_L)
#define QW_UNDS GUI_T(KC_UNDS)

#define xxxxxxx KC_NO

#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_SYM LT(_SYM, KC_ESC)
// #define FNC_MOU LT(_SYM, KC_0)
#define C_TAB C(KC_TAB)
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))
#define RPSHFT SFT_T(REPEAT)
#define CAPSWORD CW_TOGG
#define REPEAT SFT_T(KC_0)
#define ALTRPT QK_AREP
#define SYMBOL OSL(_SYM)

#define LOTHUMB ALTRPT
#define LMTHUMB REPEAT
#define LITHUMB SYMBOL

#define ROTHUMB OS_LSFT
#define RMTHUMB SPC_NAV
#define RITHUMB OSL(_FNC)
