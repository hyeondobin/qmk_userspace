COMBO_ENABLE = yes

# key logging
CONSOLLE_ENABLE = yes

CAPS_WORD_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
REPEAT_KEY_ENABLE = no
#RGBLIGHT_ENABLE = no # keyboard RGB underglow

# Easy definition of combos
VPATH += keyboards/gboards/


# Extra features that are nice but take space
WPM_ENABLE = no
#EXTRAKEY_ENABLE = no # For volume keys and similar

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
AUDIO_ENABLE = yes

SRC +=repeat.c
SRC +=oneshot.c
SRC +=layermodes.c
SRC +=casemodes.c
# SRC +=.c

