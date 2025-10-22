#include "smart_mouse.h"
#include "keycodes.h"

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
        printf("Disable Smart Mouse");
    }
    _smart_mouse_enabled = false;
    layer_off(_SYM);
}
void process_smart_mouse_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        return;
    }
}
