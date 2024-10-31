#include "app_switcher.h"

#define APP_SW_LOG_PREFIX "[app switcher] "

void app_switcher_next(app_switcher_t *this) {
    if (!this->is_active) {
        if (this->trigger_layer_idx == 255) {
            uprintf(APP_SW_LOG_PREFIX "not activating app switcher because it was triggered from default layer!\n");
            return;
        } else {
            uprintf(APP_SW_LOG_PREFIX "activated\n");
        }
        this->is_active = true;
        if (!(get_mods() & MOD_MASK_GUI)) {
            // neither GUI modifier pressed
            register_code(KC_LGUI);
            tap_code(KC_TAB);
            this->gui_held = true;
        }
    } else {
        uprintf(APP_SW_LOG_PREFIX "switch app\n");
        tap_code(KC_TAB);
    }
}

void app_switcher_kill_app(app_switcher_t *this) {
    uprintf(APP_SW_LOG_PREFIX "kill app\n");
    if (this->is_active) {
        tap_code(KC_Q);
    }
}

void app_switcher_finish(app_switcher_t *this) {
    uprintf(APP_SW_LOG_PREFIX "deactivated\n");
    if (this->is_active) {
        this->is_active = false;
        if (this->gui_held) {
            this->gui_held = false;
            unregister_code(KC_LGUI);
        }
    }
}

void app_switcher_layer_state_set(app_switcher_t *this, layer_state_t state) {
    uint8_t layer = get_highest_layer(default_layer_state | state);
    if (!this->is_active) {
        if (IS_LAYER_ON_STATE(default_layer_state, layer)) {
            this->trigger_layer_idx = 255;
        } else {
            this->trigger_layer_idx = layer;
        }
    } else {
        if (IS_LAYER_OFF_STATE(state, this->trigger_layer_idx)) {
            app_switcher_finish(this);
        }
    }
}

void app_switcher_post_process_record(app_switcher_t *this, uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed && keycode == KC_ESC) {
        // pressing ESC would hide the task switcher on Mac OS, so we need to sync
        // this with our state (and release held modifier key, i. e. Cmd)
        app_switcher_finish(this);
        return;
    }

    if (this->is_active && !is_key_pressed(KC_LGUI)) {
        uprintf(APP_SW_LOG_PREFIX "WARNING! App switcher was active, but GUI key was depressed somehow. Resetting state.\n");
        this->is_active = false;
        this->gui_held  = false;
    }
}
