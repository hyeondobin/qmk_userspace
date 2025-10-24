COMBO_ENABLE = yes

# key logging
CONSOLLE_ENABLE = yes

CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
REPEAT_KEY_ENABLE = yes

RGBLIGHT_ENABLE = no # there's no keyboard RGB underglow in moonlander
RGB_MATRIX_DRIVER = is31fl3731

RGB_MATRIX_CUSTOM_KB = no

# Easy definition of combos
VPATH += keyboards/gboards/

# Enable mouse
MOUSEKEY_ENABLE = yes

# Extra features that are nice but take space
WPM_ENABLE = no
#EXTRAKEY_ENABLE = no # For volume keys and similar

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
AUDIO_ENABLE = no

UNICODE_ENABLE = yes

SRC +=numword.c
SRC +=smart_mouse.c
