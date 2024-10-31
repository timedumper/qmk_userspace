#include "quantum.h"
#include "definitions.h"
#include "utils.h"

void oled_render_logo(void);
static void oled_render_layer_state(void);

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        oled_clear();
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }

    return false;
}

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("L: "), false);

    switch (get_highest_layer(layer_state)) {
        case IDE_SYM:
            oled_write_P(PSTR("IDE_SYM"), false);
            break;
        case SYM_IDE:
            oled_write_P(PSTR("SYM_IDE"), false);
            break;
        case DIGIT_CHARS:
            oled_write_P(PSTR("DIGIT_CHARS"), false);
            break;
        case NAV:
            oled_write_P(PSTR("NAV"), false);
            break;
        case LEFT_MODS:
            oled_write_P(PSTR("LEFT_MODS"), false);
            break;
        case RIGHT_MODS:
            oled_write_P(PSTR("RIGHT_MODS"), false);
            break;
        case 0:
            oled_write_P(PSTR("DEFAULT"), false);
            break;
        default:
            oled_write_P(PSTR("???"), false);
            break;
    }

    if (num_active_layers(layer_state) > 1) {
        oled_write_ln_P(PSTR(" + more"), false);
    } else {
        oled_advance_page(true);
    }
}
