CONSOLE_ENABLE = yes        # Console for debug

MOUSEKEY_ENABLE = no        # Mouse keys
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
SWAP_HANDS_ENABLE = no      # Enable one-hand typing

TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes # warning: this disables per-key tapping term

SRC += features/app_switcher.c
SRC += features/app_switcher_td.c

SRC += oled/oled.c
SRC += utils.c

# Space saving measures
# RGBLIGHT_ENABLE = no # saves ~3700 bytes
SPACE_CADET_ENABLE = no # ~340 bytes
GRAVE_ESC_ENABLE = no # ~80 bytes
MAGIC_ENABLE = no # ~470 bytes

