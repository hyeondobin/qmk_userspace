#include "layermodes.h"
#include "keycodes.h"

static uint16_t num_word_timer;
static bool _num_word_enabled = false;
bool num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(_NUMBER);
}
void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUMBER);
}
void process_num_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_NUMBER);
        num_word_timer = timer_read();
    } else {
        if (timer_elapsed(num_word_timer) < TAPPING_TERM) {
            _num_word_enabled = true;
        } else {
            layer_off(_NUMBER);
        }
    }
}
bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MODE_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
    }
    // switch (keycode) {
    //     return true;
    // }
}
