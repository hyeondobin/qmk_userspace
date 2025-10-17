#pragma once

#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"
#include "oneshot.h"

enum layers { _BASE = 0, _QWERTY, _TRANS, _NUMBER, _NAVI, _MOUSE, _SYMBOL };

enum custom_keycodes {
    // ~ ` ^
    TILD = QK_USER,
    GRV,
    CIRC,

    VRSN //= SAFE_RANGE,
};
