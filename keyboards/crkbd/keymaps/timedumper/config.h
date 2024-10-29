/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define NO_DEBUG // space saving

#define RETRO_TAPPING
#define TAPPING_TERM 200
#define DYNAMIC_TAPPING_TERM_INCREMENT 200
#define QUICK_TAP_TERM_PER_KEY
#define TAPPING_TERM_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
#define LEADER_NO_TIMEOUT

#define COMBO_STRICT_TIMER
#define COMBO_ONLY_FROM_LAYER 0 // for simplicity we'll define them in qwerty terms (base layer)
#define COMBO_SHOULD_TRIGGER // we're gonna only enable combos on certain layers

// #define LEADER_DEBUG // adds ~500 bytes
#define NO_ACTION_ONESHOT // removes ~600 bytes

// clang-format off

#define LAYOUT_left_right(\
    k0A, k0B, k0C, k0D, k0E, k0F,\
    k1A, k1B, k1C, k1D, k1E, k1F, \
    k2A, k2B, k2C, k2D, k2E, k2F, \
    k3D, k3E, k3F, \
    \
    k4F, k4E, k4D, k4C, k4B, k4A, \
    k5F, k5E, k5D, k5C, k5B, k5A, \
    k6F, k6E, k6D, k6C, k6B, k6A, \
    k7F, k7E, k7D\
) { \
	 {k0A, k0B, k0C, k0D, k0E, k0F}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F}, \
	 {KC_NO, KC_NO, KC_NO, k3D, k3E, k3F}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F}, \
	 {KC_NO, KC_NO, KC_NO, k7D, k7E, k7F} \
}

// clang-format on
