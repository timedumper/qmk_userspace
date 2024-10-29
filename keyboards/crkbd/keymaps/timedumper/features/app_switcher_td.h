#pragma once

#include "app_switcher.h"

#define DECL(name) void name(tap_dance_state_t *state, void *user_data);
DECL(_td_tap_or_hold_each)
DECL(_td_tap_or_hold_each_release)
DECL(_td_tap_or_hold_finished)
DECL(_td_tap_or_hold_reset)
#undef DECL

typedef struct {
    app_switcher_t *app_switcher;
    bool            activated_on_first_press : 1;
} td_tap_or_hold_state_t;

#define APP_SWITCHER_TAP_DANCE_ACTION(switcher_ptr) (\
    (tap_dance_action_t){ \
        .fn.on_each_tap       = _td_tap_or_hold_each, \
        .fn.on_each_release   = _td_tap_or_hold_each_release, \
        .fn.on_dance_finished = _td_tap_or_hold_finished, \
        .fn.on_reset          = _td_tap_or_hold_reset, \
        .user_data = \
            &(td_tap_or_hold_state_t){ \
                .activated_on_first_press = false, \
                .app_switcher             = switcher_ptr, \
            }, \
    })
