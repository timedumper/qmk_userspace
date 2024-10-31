#pragma once

#include "app_switcher.h"

#define DECL(name) void name(tap_dance_state_t *state, void *user_data);
DECL(_td_tap_or_hold_each)
DECL(_td_tap_or_hold_each_release)
DECL(_td_tap_or_hold_finished)
DECL(_td_tap_or_hold_reset)
DECL(_td_n_tap_or_hold_each_release)
DECL(_td_n_tap_or_hold_finished)
DECL(_td_full_dbl_finished)
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

typedef struct {
    uint16_t tap_code;
    uint16_t dbl_tap_code;
    uint16_t hold_code;
    uint16_t dbl_hold_code;
} td_n_tap_hold_state_t;

#define TAP_DANCE_N_TAP_HOLD(tap_kc, hold_kc) (\
    (tap_dance_action_t){ \
        .fn.on_each_release   = _td_n_tap_or_hold_each_release, \
        .fn.on_dance_finished = _td_n_tap_or_hold_finished, \
        .user_data = \
            &(td_n_tap_hold_state_t){ \
                .tap_code = tap_kc, \
                .hold_code = hold_kc, \
            }, \
    })

#define TAP_DANCE_FULL_DOUBLE(tap_kc, dbl_tap_kc, hold_kc, dbl_hold_kc) (\
    (tap_dance_action_t){ \
        .fn.on_dance_finished = _td_full_dbl_finished, \
        .user_data = \
            &(td_n_tap_hold_state_t){ \
                .tap_code = tap_kc, \
                .hold_code = hold_kc, \
                .dbl_hold_code = dbl_hold_kc, \
                .dbl_tap_code = dbl_tap_kc, \
            }, \
    })
