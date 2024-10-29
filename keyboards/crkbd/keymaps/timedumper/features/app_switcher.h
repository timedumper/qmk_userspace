#pragma once

#include QMK_KEYBOARD_H // IWYU pragma: keep

typedef struct {
    uint8_t trigger_layer_idx;
    bool    is_active : 1;
    bool    gui_held : 1;
} app_switcher_t;

void app_switcher_next(app_switcher_t *this);
void app_switcher_kill_app(app_switcher_t *this);
void app_switcher_finish(app_switcher_t *this);
void app_switcher_layer_state_set(app_switcher_t *this, layer_state_t state);
void app_switcher_post_process_record(app_switcher_t *this, uint16_t keycode, keyrecord_t *record);
