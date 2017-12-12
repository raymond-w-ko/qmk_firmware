/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "action_layer.h"
#include "planck.h"

#define TAP_DELAY 256

extern keymap_config_t keymap_config;

enum planck_layers {
  ALPH,
  LOWER,
  RAISE,
  ADJUST,
  NUMS,
  FKEY,
  CURS,
  SEMILAYER,
};

enum planck_keycodes {
  SEMIKEY = SAFE_RANGE,
  LOWERKEY,
  RAISEKEY,

  WINUNI,
  WINCUNI,
  OSXUNI,
  LNXUNI,

  MY_BELW,
  MY_TERM,
  MY_DEQL,  // /=
  MY_MEQL,  // *=
  MY_SEQL,  // -=
  MY_PEQL,  // +=
  MY_NEQL,  // !=
  MY_LTGT,  // <>
  MY_DPIP,  // ||
  MY_DAMP,  // &&

  ALT_TAB,
  TMUX_L,
  TMUX_R,
  I3_L,
  I3_R,
};

float winc_song[][2] = SONG(ROCK_A_BYE_BABY);
float osx_song[][2] = SONG(ODE_TO_JOY);
float lnx_song[][2] = SONG(ZELDA_PUZZLE);

const uint32_t PROGMEM unicode_map[] = {
    0x03b8,  // θ
    0x03c1,  // ρ
    0x03c6,  // φ
    0x03c7,  // χ
    0x03c3,  // σ
    0x03b2,  // β
    0x03c5,  // υ
    0x03c8,  // ψ
    0x03c0,  // π
    0x03b7,  // η
    0x03ba,  // κ
    0x03bd,  // ν
    0x03bc,  // μ
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = {
{KC_Q,          KC_W,     KC_E,     KC_R,     KC_T,          KC_LBRC, KC_RBRC, KC_Y,   KC_U,     KC_I,     KC_O,     KC_P},
{KC_A,          KC_S,     KC_D,     KC_F,     KC_G,          KC_LPRN, KC_RPRN, KC_H,   KC_J,     KC_K,     KC_L,     SEMIKEY},
{SFT_T(KC_Z),   KC_X,     KC_C,     KC_V,     KC_B,          KC_LCBR, KC_RCBR, KC_N,   KC_M,     KC_COMM,  KC_DOT,   SFT_T(KC_SLSH)},
{GUI_T(KC_TAB), MO(FKEY), MO(NUMS), LOWERKEY, CTL_T(KC_ESC), KC_BSPC, KC_ENT,  KC_SPC, RAISEKEY, MO(CURS), TG(CURS), KC_LALT}
},

  
[SEMILAYER] = {
{X(0),    KC_BSLS, KC_EQL,  X(1),    KC_TILD, _______, _______, X(6),    X(7),    KC_TAB,  KC_BSPC, X(8)   },
{KC_MINS, KC_UNDS, KC_COLN, X(2),    KC_GT,   _______, _______, X(9),    KC_SCLN, X(10),   KC_LT,   _______},
{KC_PLUS, X(3),    X(4),    KC_ENT,  X(5),    _______, _______, X(11),   X(12),   _______, _______, _______},
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______}
},

[LOWER] = {
{KC_PSCR, TMUX_L,  KC_UP,   TMUX_R,  XXXXXXX, XXXXXXX, XXXXXXX, MY_LTGT, KC_LABK, KC_RABK, KC_COLN, KC_DLR},
{ALT_TAB, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_PIPE, MY_DPIP, KC_GRV,  KC_DQUO, KC_QUOT, KC_HASH},
{XXXXXXX, I3_L,    MY_TERM, I3_R,    XXXXXXX, XXXXXXX, KC_AMPR, MY_DAMP, KC_TILD, KC_AT,   KC_EXLM, KC_QUES},
{XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______}
},

[RAISE] = {
{MY_DEQL, MY_MEQL, MY_SEQL, MY_PEQL, MY_NEQL, XXXXXXX, XXXXXXX, MY_LTGT, KC_LABK, KC_RABK, KC_COLN, KC_DLR},
{KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  XXXXXXX, KC_PIPE, MY_DPIP, KC_GRV,  KC_DQUO, KC_QUOT, KC_HASH},
{KC_BSLS, KC_CIRC, KC_PERC, KC_UNDS, XXXXXXX, XXXXXXX, KC_AMPR, MY_DAMP, KC_TILD, KC_AT,   KC_EXLM, KC_QUES},
{XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX}
},

[NUMS] = {
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_7, KC_8,   KC_9,   KC_SLSH},
{KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_4, KC_5,   KC_6,   KC_ASTR},
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_1, KC_2,   KC_3,   KC_MINS},
{XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0, KC_DOT, KC_EQL, KC_PLUS}
},

[FKEY] = {
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12},
{KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8},
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4},
{XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[CURS] = {
{KC_MPLY, TMUX_L,  KC_UP,   TMUX_R,  KC_PGUP, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
{KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT},
{KC_VOLD, I3_L,    MY_TERM, I3_R,    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT},
{KC_MUTE, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX}
},

[ADJUST] = {
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX},
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           WINCUNI,         OSXUNI,  LNXUNI,  WINUNI},
{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_UNHOST_NKRO, MAGIC_HOST_NKRO, XXXXXXX, XXXXXXX, XXXXXXX},
{XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           _______,         XXXXXXX, XXXXXXX, XXXXXXX}
},

};  // clang-format on

void matrix_init_user() {
  set_single_persistent_default_layer(ALPH);
  set_unicode_input_mode(UC_LNX);
}

void press_key(uint16_t key) {
  register_code(key);
  unregister_code(key);
}

void press_two_keys(uint16_t key1, uint16_t key2) {
  register_code(key1);
  register_code(key2);
  unregister_code(key2);
  unregister_code(key1);
}

void press_three_keys(uint16_t key1, uint16_t key2, uint16_t key3) {
  register_code(key1);
  register_code(key2);
  register_code(key3);
  unregister_code(key3);
  unregister_code(key2);
  unregister_code(key1);
}

bool process_programmer_key_combos(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_DEQL:  // /=
      if (record->event.pressed) {
        press_key(KC_SLSH);
        press_key(KC_EQL);
      }

      return false;

    case MY_MEQL:  // *=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_ASTR);
        press_key(KC_EQL);
      }

      return false;

    case MY_SEQL:  // -=
      if (record->event.pressed) {
        press_key(KC_MINS);
        press_key(KC_EQL);
      }

      return false;

    case MY_PEQL:  // +=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PLUS);
        press_key(KC_EQL);
      }

      return false;

    case MY_NEQL:  // !=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_EXLM);
        press_key(KC_EQL);
      }

      return false;

    case MY_LTGT:  // <>
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_LABK);
        press_two_keys(KC_LSFT, KC_RABK);
      }

      return false;

    case MY_DPIP:  // ||
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PIPE);
        press_two_keys(KC_LSFT, KC_PIPE);
      }

      return false;

    case MY_DAMP:  // &&
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_AMPR);
        press_two_keys(KC_LSFT, KC_AMPR);
      }

      return false;
  }

  return true;
}

static bool sending_alt = 0;

bool process_my_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB: {
      if (!sending_alt) {
        sending_alt = true;
        register_code(KC_LALT);
      }
      if (record->event.pressed) {
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    }

    case WINUNI:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_WIN);
      }
      return false;
    case WINCUNI:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_WINC);
        PLAY_SONG(winc_song);
      }
      return false;
    case OSXUNI:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_OSX);
        PLAY_SONG(osx_song);
      }
      return false;
    case LNXUNI:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_LNX);
        PLAY_SONG(lnx_song);
      }
      return false;

    case TMUX_L:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_P);
      }
      return false;
    case TMUX_R:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_N);
      }
      return false;

    case MY_TERM:
      if (record->event.pressed) {
        press_three_keys(KC_LGUI, KC_LSFT, KC_ENTER);
      }
      return false;
    case I3_L:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_LEFT);
      }
      return false;
    case I3_R:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_RGHT);
      }
      return false;
  }

  return true;
}

static bool allow_tap = 0;
static uint16_t semi_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEMIKEY:
      if (record->event.pressed) {
        semi_timer = timer_read();
        allow_tap = true;
        layer_on(SEMILAYER);
      } else {
        layer_off(SEMILAYER);
        if (allow_tap && timer_elapsed(semi_timer) < TAP_DELAY) {
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      return false;
      break;
    case LOWERKEY:
      if (record->event.pressed) {
        layer_on(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        if (sending_alt) {
          sending_alt = false;
          unregister_code(KC_LALT);
        }
        layer_off(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
      break;
    case RAISEKEY:
      if (record->event.pressed) {
        layer_on(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        layer_off(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
      break;
    default:
      allow_tap = false;
      break;
  }

  bool unintercepted = 0;

  unintercepted = process_my_keys(keycode, record);
  if (!unintercepted) return unintercepted;

  unintercepted = process_programmer_key_combos(keycode, record);
  if (!unintercepted) return unintercepted;

  return true;
}
