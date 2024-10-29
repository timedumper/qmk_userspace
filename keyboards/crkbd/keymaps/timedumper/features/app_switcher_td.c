#include "app_switcher_td.h"

void _debug_td_state(tap_dance_state_t *state, const char *what);

void _td_tap_or_hold_each(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, "PRESS");
    td_tap_or_hold_state_t *td_state = user_data;

    if (!td_state->app_switcher->is_active && state->count == 1 && !state->interrupted) {
        // because we'll never activate the switcher from a hold we can safely
        // do it right instead of release to expedite things
        td_state->activated_on_first_press = true;
        app_switcher_next(td_state->app_switcher);
    }
}

void _td_tap_or_hold_each_release(tap_dance_state_t *state, void *user_data) {
    _debug_td_state(state, "RELEASE");
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
    _debug_td_state(state, "FINISH");
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
    _debug_td_state(state, "RESET");
    td_tap_or_hold_state_t *td_state   = user_data;
    td_state->activated_on_first_press = false;
}

void _debug_td_state(tap_dance_state_t *state, const char *what) {
    uprintf("     %05u [%s] %s cnt=%d%s%s\n", timer_read(), what, state->pressed ? "PRESS" : "REL", state->count, state->finished ? " finished" : "", state->interrupted ? " interrupted" : "");
}
