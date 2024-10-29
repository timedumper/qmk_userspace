CONSOLE_ENABLE = yes        # Console for debug

MOUSEKEY_ENABLE = no        # Mouse keys
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
SWAP_HANDS_ENABLE = no      # Enable one-hand typing

TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes # warning: this disables per-key tapping term

SRC += features/app_switcher.c
SRC += features/app_switcher_td.c

# Temp space saving measures
# RGBLIGHT_ENABLE = no # saves ~3700 bytes

