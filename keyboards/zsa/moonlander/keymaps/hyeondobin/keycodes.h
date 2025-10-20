#pragma once

#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"
#include "oneshot.h"
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
#define QW_SCLN GUI_T(KC_SCLN)

enum layers { _BAS = 0, _QWE, _TRS, _NUM, _NAV, _MOU, _SYM };

enum custom_keycodes {
    TILD = QK_USER,
    // Repeat keys
    REPEAT,
    REV_REP,

    // Multiple chars
    QU,
    SC,

    SUNDAY,

    // email addresses
    EGDOBIN,
    EGJAYLI,
    EGPANRU,
    ENDOBIN,

    // Vim
    SAVE_VIM,

    CLOSE_WIN,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Custom Win + Alt for window toggling on Windows
    WIN_ALT,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

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

#define xxxxxxx KC_NO

#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_SYM LT(_SYM, KC_ESC)
#define C_TAB C(KC_TAB)
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))
#define RPSHFT SFT_T(REPEAT)
