/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H // IWYU pragma: keep

#include "features/app_switcher.h"
#include "features/app_switcher_td.h"

// MARK: layer and TD constants

enum Layers {
    BASE,
    LEFT_MODS,
    RIGHT_MODS,
    IDE_SYM,
    SYM_IDE,
    DIGIT_CHARS,
    NAV,
};

enum tap_dances { TD_APP_SWITCH };

// layer-tap aliases
#define SYM_IDE_T(code) LT(SYM_IDE, code)
#define R_MODS_T(code) LT(RIGHT_MODS, code)
#define DGTS_CHRS_T(code) LT(DIGIT_CHARS, code)
// MARK: keycode aliases

// layer-taps
#define LT_SYMIDE_SPACE LT(SYM_IDE, KC_SPACE)
#define LT_RMODS_ENTER LT(RIGHT_MODS, KC_ENTER)
#define LT_DIGITS_F LT(DIGIT_CHARS, KC_F)

// mod-taps
#define MT_LALT_LEFT MT(KC_LALT, KC_LEFT)
#define MT_LSFT_DOWN MT(KC_LSFT, KC_DOWN)
#define MT_LCTL_RIGHT MT(KC_LCTL, KC_RIGHT)

// custom behaviors
#define CK_APP_SWITCHER TD(TD_APP_SWITCH)

// QMK keycodes
#define TAP_TERM_PRN QK_DYNAMIC_TAPPING_TERM_PRINT
#define TAP_TERM_INCR QK_DYNAMIC_TAPPING_TERM_UP
#define TAP_TERM_DECR QK_DYNAMIC_TAPPING_TERM_DOWN

// MARK: layer definitions

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
                                             _
                                            | |
                                            | |__   __ _ ___  ___
                                            | '_ \ / _` / __|/ _ \
                                            | |_) | (_| \__ \  __/
                                            |_.__/ \__,_|___/\___|
*/

  [BASE] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    KC_TAB            , KC_Q              , KC_W              , KC_E              , KC_R              , KC_T              ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_ESC            , KC_A              , KC_S              , KC_D              , LT_DIGITS_F       , KC_G              ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_LSFT           , KC_Z              , KC_X              , KC_C              , KC_V              , KC_B              ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                MO(LEFT_MODS)     , MO(NAV)           , MO(IDE_SYM)       ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    KC_Y              , KC_U              , KC_I              , KC_O              , KC_P              , XXXXXXX /* ??? */ ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_H              , KC_J              , KC_K              , KC_L              , KC_SCLN           , KC_QUOT           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_N              , KC_M              , KC_COMM           , KC_DOT            , KC_SLSH           , KC_LSFT           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    LT_SYMIDE_SPACE   , KC_BSPC           , LT_RMODS_ENTER
 //'----------------------------------------------------------'
  ),

/*
                                    _____ ______  _____
                                   |_   _||  _  \|  ___|    _
                                     | |  | | | || |__    _| |_   ___  _   _  _ __ ___
                                     | |  | | | ||  __|  |_   _| / __|| | | || '_ ` _ \
                                    _| |_ | |/ / | |___    |_|   \__ \| |_| || | | | | |
                                    \___/ |___/  \____/          |___/ \__, ||_| |_| |_|
                                                                        __/ |
                                                                        |___/
*/

  [IDE_SYM] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , KC_LGUI           , KC_LALT           , KC_LSFT           , KC_LCTL           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    KC_LEFT_PAREN     , KC_RIGHT_PAREN    , KC_LEFT_BRACKET   , KC_RIGHT_BRACKET  , KC_PIPE           , KC_AMPERSAND      ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_UNDERSCORE     , KC_EQUAL          , KC_PLUS           , KC_MINUS          , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_EXCLAIM        , KC_ASTERISK       , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    KC_SPACE          , KC_BACKSPACE      , KC_ENTER
 //'----------------------------------------------------------'
  ),

/*
                                                                 _____ ______  _____
                                                           _    |_   _||  _  \|  ___|
                                 ___  _   _  _ __ ___    _| |_    | |  | | | || |__
                                / __|| | | || '_ ` _ \  |_   _|   | |  | | | ||  __|
                                \__ \| |_| || | | | | |   |_|    _| |_ | |/ / | |___
                                |___/ \__, ||_| |_| |_|          \___/ |___/  \____/
                                    __/ |
                                    |___/
*/

  [SYM_IDE] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , KC_PERCENT        , KC_HASH           , KC_TILDE          ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , KC_DOLLAR         , KC_LCBR           , KC_RCBR           , KC_GRAVE          ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , KC_CIRCUMFLEX     , KC_BACKSLASH      ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , KC_RCTL           , KC_RSFT           , KC_RALT           , KC_RGUI           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    XXXXXXX           , XXXXXXX           , XXXXXXX
 //'----------------------------------------------------------'
),

/*
                                    _  _         _  _             _
                                   | |(_)       (_)| |           | |
                                 __| | _   __ _  _ | |_      ___ | |__    __ _  _ __  ___
                                / _` || | / _` || || __|    / __|| '_ \  / _` || '__|/ __|
                               | (_| || || (_| || || |_    | (__ | | | || (_| || |   \__ \
                                \__,_||_| \__, ||_| \__|    \___||_| |_| \__,_||_|   |___/
                                           __/ |
                                          |___/
*/
[DIGIT_CHARS] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    KC_8              , KC_4              , KC_5              , KC_6              , KC_9              , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_7              , KC_1              , KC_2              , KC_3              , KC_0              , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    KC_SPACE          , KC_BACKSPACE      , XXXXXXX
 //'----------------------------------------------------------'
),

/*
                                                 _   _   ___   _   _
                                                | \ | | / _ \ | | | |
                                                |  \| |/ /_\ \| | | |
                                                | . ` ||  _  || | | |
                                                | |\  || | | |\ \_/ /
                                                \_| \_/\_| |_/ \___/
*/

  [NAV] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , CK_APP_SWITCHER   , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_ESCAPE         , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_LSFT           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    A(KC_LEFT)        , A(KC_RIGHT)       , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    KC_LEFT           , KC_DOWN           , KC_UP             , KC_RIGHT          , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    G(KC_LEFT)        , G(KC_RIGHT)       , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    XXXXXXX           , XXXXXXX           , XXXXXXX
 //'----------------------------------------------------------'
  ),

 /*
                                 _         __  _                             _
                                | |       / _|| |                           | |
                                | |  ___ | |_ | |_     _ __ ___    ___    __| | ___
                                | | / _ \|  _|| __|   | '_ ` _ \  / _ \  / _` |/ __|
                                | ||  __/| |  | |_    | | | | | || (_) || (_| |\__ \
                                |_| \___||_|   \__|   |_| |_| |_| \___/  \__,_||___/
 */

  [LEFT_MODS] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , QK_BOOTLOADER     , QK_DEBUG_TOGGLE   , TAP_TERM_DECR     , TAP_TERM_INCR     , TAP_TERM_PRN      ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , KC_LGUI           , KC_LALT           , KC_LSFT           , KC_LCTL           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    _______           , _______           , _______           , _______           , _______           , _______           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    _______           , _______           , _______           , _______           , _______           , _______           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    _______           , _______           , _______           , _______           , _______           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    KC_SPACE          , KC_BACKSPACE      , KC_ENTER
 //'----------------------------------------------------------'
  ),

 /*
                                       _         _      _                             _
                                      (_)       | |    | |                           | |
                                 _ __  _   __ _ | |__  | |_     _ __ ___    ___    __| | ___
                                | '__|| | / _` || '_ \ | __|   | '_ ` _ \  / _ \  / _` |/ __|
                                | |   | || (_| || | | || |_    | | | | | || (_) || (_| |\__ \
                                |_|   |_| \__, ||_| |_| \__|   |_| |_| |_| \___/  \__,_||___/
                                        __/ |
                                        |___/
 */

  [RIGHT_MODS] = LAYOUT_left_right(
 //.----------------------------------------------------------------------------------------------------------------------.
    _______           , _______           , _______           , _______           , _______           , _______           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    _______           , _______           , _______           , _______           , _______           , _______           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , _______           , _______           , _______           , _______           , _______           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , KC_RCTL           , KC_RSFT           , KC_RALT           , KC_RGUI           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    XXXXXXX           , XXXXXXX           , XXXXXXX
 //'----------------------------------------------------------'
  )

/*
   Layer with no keys:
 //.----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //'------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //                                                           `-----------------------------------------------------------'

 //,----------------------------------------------------------------------------------------------------------------------.
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
    XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           , XXXXXXX           ,
 //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------'
    XXXXXXX           , XXXXXXX           , XXXXXXX
 //'----------------------------------------------------------'
*/


};
// clang-format on

// MARK: app switcher

app_switcher_t g_app_switcher = {.is_active = false, .gui_held = false};

// MARK: tap dance definitions

tap_dance_action_t tap_dance_actions[] = {
    [TD_APP_SWITCH] = APP_SWITCHER_TAP_DANCE_ACTION(&g_app_switcher)
};

// MARK: callbacks

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_DIGITS_F:
            return 30;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_APP_SWITCHER:
            return 600;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    app_switcher_layer_state_set(&g_app_switcher, state);
    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    app_switcher_post_process_record(&g_app_switcher, keycode, record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("%s 0x%04X, ts: %5u, i: %u, cnt: %u, type: %u\n", record->event.pressed ? "PRESS" : "RELEASE", keycode, record->event.time, record->tap.interrupted, record->tap.count, record->event.type);
    return true;
}
