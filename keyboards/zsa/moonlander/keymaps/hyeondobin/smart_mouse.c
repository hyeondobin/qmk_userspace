#include "smart_mouse.h"
#include "keycodes.h"
#include "print.h"

static bool _smart_mouse_enabled = true;
bool        smart_mouse_enabled(void) {
    return _smart_mouse_enabled;
}

void enable_smart_mouse(void) {
    if (!_smart_mouse_enabled) {
        _smart_mouse_enabled = true;
    }
    layer_on(_MOU);
}

void disable_smart_mouse(void) {
    if (_smart_mouse_enabled) {
        printf("Disable Smart Mouse\n");
    }
    _smart_mouse_enabled = false;
    layer_off(_MOU);
}
void process_smart_mouse_activation(const keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }

    if (smart_mouse_enabled()) {
        printf("Enable MOU layer\n");
        _smart_mouse_enabled = false;
    } else {
        printf("Enable Smart Mouse\n");
        enable_smart_mouse();
    }
}

bool process_smart_mouse(uint16_t keycode, const keyrecord_t *record) {
    if (!_smart_mouse_enabled) {
        return true;
    }

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0) {
                return true;
            }
            keycode = keycode & 0xFF;
    }

    switch (keycode) {
        case MS_UP ... MS_ACL2:
        case xxxxxxx:
        case SMMOUSE:
            break;
        case CLEAR:
            if (record->event.pressed) {
                disable_smart_mouse();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_smart_mouse();
            }
    }
    return true;
}
