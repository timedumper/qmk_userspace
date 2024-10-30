#include "app_switcher_td.h"

void _debug_td_state(tap_dance_state_t *state, uint8_t what);

#define LOG_PRESS 0
#define LOG_RELEASE 1
#define LOG_FINISH 2
#define LOG_RESET 3

#define LOG_APP_SW (1 << 2)
#define LOG_TAP_HOLD (2 << 2)

void _td_tap_or_hold_each(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_APP_SW | LOG_PRESS);
    td_tap_or_hold_state_t *td_state = user_data;

    if (!td_state->app_switcher->is_active && state->count == 1 && !state->interrupted) {
        // because we'll never activate the switcher from a hold we can safely
        // do it right instead of release to expedite things
        td_state->activated_on_first_press = true;
        app_switcher_next(td_state->app_switcher);
    }
}

void _td_tap_or_hold_each_release(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_APP_SW | LOG_RELEASE);
    td_tap_or_hold_state_t *td_state = user_data;

    if (!state->finished && !state->interrupted) {
        // this is a tap which means normally we go to next app unless this was
        // a first tap that activated the switcher
        if (state->count > 1 || !td_state->activated_on_first_press) {
            app_switcher_next(td_state->app_switcher);
        }
    }
}

void _td_tap_or_hold_finished(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_APP_SW | LOG_FINISH);
    td_tap_or_hold_state_t *td_state = user_data;

    if (state->pressed && !state->interrupted) {
        // this is a hold which, normally, means sending a kill command
        // however, if we activated the switcher as a part of this hold
        // we should skip that
        if (state->count > 1 || !td_state->activated_on_first_press) {
            app_switcher_kill_app(td_state->app_switcher);
        }
    }
}

void _td_tap_or_hold_reset(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_APP_SW | LOG_RESET);
    td_tap_or_hold_state_t *td_state   = user_data;
    td_state->activated_on_first_press = false;
}

void _td_n_tap_or_hold_each_release(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_TAP_HOLD | LOG_RELEASE);
    td_n_tap_hold_state_t *td_state = user_data;

    if (!state->finished && !state->interrupted && td_state->tap_code != KC_NO) {
        // this is a released tap
        tap_code16(td_state->tap_code);
    }
}

void _td_n_tap_or_hold_finished(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, LOG_TAP_HOLD | LOG_FINISH);
    td_n_tap_hold_state_t *td_state = user_data;

    if (state->pressed && !state->interrupted && td_state->hold_code != KC_NO) {
        // this is a finished hold
        tap_code16(td_state->hold_code);
    }
}

#ifdef TAP_DANCE_DEBUG
void _debug_td_state(tap_dance_state_t *state, uint8_t what) {
    char *component;
    switch (what & ~3) {
        case LOG_APP_SW: component = "app sw"; break;
        case LOG_TAP_HOLD: component = "tap/hold"; break;
        default: component = "?"; break;
    };

    char *cb;
    switch (what & 3) {
        case LOG_PRESS: cb = "PRESS"; break;
        case LOG_RELEASE: cb = "RELEASE"; break;
        case LOG_FINISH: cb = "FINISH"; break;
        case LOG_RESET: cb = "RESET"; break;
        default: cb = "?"; break;
    };

    uprintf("     %05u [%s %s] %s cnt=%d%s%s\n",
            timer_read(),
            component, cb, state->pressed ? "PRESS" : "REL", state->count, state->finished ? " finished" : "", state->interrupted ? " interrupted" : "");
}
#else
void _debug_td_state(tap_dance_state_t *state, uint8_t what) {}
#endif
