#include QMK_KEYBOARD_H

#define TAP_DELAY 512

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _SEMI 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  SEMIKEY,

  KC_rShZ,
  KC_rShS,
  KC_rCtE,

  KC_rWIN,
  KC_rOSX,
  KC_rLNX,

  KC_r_DP,
  KC_r_DA,

  KC_rA_T,
  KC_tmuL,
  KC_tmuR,
  KC_I3_L,
  KC_I3_R,

  KC_rNOR,
  KC_rGAM,
  KC_rTOG,

  KC_NKRO,
};

///////////////////////////////////////////////////////////////////////////////
// Unicode
///////////////////////////////////////////////////////////////////////////////

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

#define KC_xx00 (0 | QK_UNICODE_MAP)
#define KC_xx01 (1 | QK_UNICODE_MAP)
#define KC_xx02 (2 | QK_UNICODE_MAP)
#define KC_xx03 (3 | QK_UNICODE_MAP)
#define KC_xx04 (4 | QK_UNICODE_MAP)
#define KC_xx05 (5 | QK_UNICODE_MAP)
#define KC_xx06 (6 | QK_UNICODE_MAP)
#define KC_xx07 (7 | QK_UNICODE_MAP)
#define KC_xx08 (8 | QK_UNICODE_MAP)
#define KC_xx09 (9 | QK_UNICODE_MAP)
#define KC_xx10 (10 | QK_UNICODE_MAP)
#define KC_xx11 (11 | QK_UNICODE_MAP)
#define KC_xx12 (12 | QK_UNICODE_MAP)

///////////////////////////////////////////////////////////////////////////////

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_sINS S(KC_INSERT)
#define KC_sDEL S(KC_DELETE)

///////////////////////////////////////////////////////////////////////////////

#define KC_rSMI SEMIKEY
#define KC_NKRO MAGIC_HOST_NKRO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     rTOG, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,rSMI,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      Z  ,LSFT, X  , C  , V  , B  ,LCTL,     RCTL, N  , M  ,COMM,DOT ,RSFT,SLSH,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR,ENT ,         SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 5  , 1  , 2  , 3  , 4  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      T  , TAB, Q  , W  , E  , R  ,                Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     rTOG,LCTL, A  , S  , D  , F  ,                H  , J  , K  , L  ,rSMI,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      B  ,LSFT, Z  , X  , C  , V  ,LCTL,     RCTL, N  , M  ,COMM,DOT ,RSFT,SLSH,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LOWR,SPC ,         SPC ,RASE,RALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     VOLU,PSCR,tmuL,UP  ,tmuR,    ,                   ,LABK,RABK,COLN,DLR ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     VOLD,rA_T,LEFT,DOWN,RGHT,    ,               r_DP,GRV ,DQUO,QUOT,HASH,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,    ,I3_L,sINS,I3_R,    ,    ,         ,r_DA,TILD, AT ,EXLM,QUES,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,DEL ,         DEL ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,LCBR,RCBR,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,ASTR,    ,    ,    ,                   ,LBRC,RBRC,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,CIRC,PERC,UNDS,    ,LCTL,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,LALT,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_SEMI] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,xx00,BSLS,EQL ,xx01,TILD,               xx06,xx07,TAB ,BSPC,xx08,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MINS,UNDS,COLN,xx02,GT  ,               xx09,SCLN,xx10,LT  ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,PLUS,xx03,xx04,ENT ,xx05,    ,         ,xx11,xx12,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,sDEL,rNOR,rGAM,                   ,rWIN,rOSX,rLNX,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,RST ,    ,    ,    ,    ,    ,         ,NKRO,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};
// clang-format on

void matrix_init_user() {
#if defined(RAY_KEYMAP_TARGET_LINUX)
  set_unicode_input_mode(UC_LNX);
#elif defined(RAY_KEYMAP_TARGET_WIN)
  set_unicode_input_mode(UC_WINC);
#endif
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static void press_key(uint16_t key) {
  register_code(key);
  unregister_code(key);
}

static void press_two_keys(uint16_t key1, uint16_t key2) {
  register_code(key1);
  register_code(key2);
  unregister_code(key2);
  unregister_code(key1);
}

////////////////////////////////////////

static bool process_programmer_key_combos(uint16_t keycode,
                                          keyrecord_t *record) {
  switch (keycode) {
    case KC_r_DP:  // ||
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PIPE);
        press_two_keys(KC_LSFT, KC_PIPE);
      }

      return false;

    case KC_r_DA:  // &&
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_AMPR);
        press_two_keys(KC_LSFT, KC_AMPR);
      }

      return false;
  }

  return true;
}
////////////////////////////////////////

static bool sending_alt = false;
static bool process_my_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // alt+tab emulation
    case KC_rA_T: {
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

    // unicode mode switching keys
    case KC_rWIN:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_WINC);
      }
      return false;
    case KC_rOSX:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_OSX);
      }
      return false;
    case KC_rLNX:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_LNX);
      }
      return false;

    // tmux + i3 navigation keys
    case KC_tmuL:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_P);
      }
      return false;
    case KC_tmuR:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_N);
      }
      return false;
    case KC_I3_L:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_LEFT);
      }
      return false;
    case KC_I3_R:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_RGHT);
      }
      return false;
  }

  return true;
}

////////////////////////////////////////

static bool process_mod_tap_keys(uint16_t keycode, keyrecord_t *record) {
  static bool lshift_pressed = false;
  static bool rshift_pressed = false;

  static bool lshift_allow_transform = false;
  static bool rshift_allow_transform = false;
  static bool ctrl_allow_transform = false;
  if (record->event.pressed) {
    if (keycode != KC_rShZ) lshift_allow_transform = false;
    if (keycode != KC_rShS) rshift_allow_transform = false;
    if (keycode != KC_rCtE) ctrl_allow_transform = false;
  }

  switch (keycode) {
    case KC_rShZ:
      if (rshift_pressed) {
        if (record->event.pressed) {
          register_code(KC_Z);
          unregister_code(KC_Z);
        }
      } else {
        if (record->event.pressed) {
          lshift_allow_transform = true;
          if (!rshift_pressed) {
            register_code(KC_LSFT);
            lshift_pressed = true;
          }
        } else {
          if (lshift_pressed) {
            unregister_code(KC_LSFT);
            lshift_pressed = false;
          }
          if (lshift_allow_transform) {
            lshift_allow_transform = false;
            register_code(KC_Z);
            unregister_code(KC_Z);
          }
        }
      }

      return false;
    case KC_rShS:
      if (lshift_pressed) {
        if (record->event.pressed) {
          register_code(KC_SLSH);
          unregister_code(KC_SLSH);
        }
      } else {
        if (record->event.pressed) {
          rshift_allow_transform = true;
          if (!lshift_pressed) {
            register_code(KC_RSFT);
            rshift_pressed = true;
          }
        } else {
          if (rshift_pressed) {
            unregister_code(KC_RSFT);
            rshift_pressed = false;
          }
          if (rshift_allow_transform) {
            rshift_allow_transform = false;
            register_code(KC_SLSH);
            unregister_code(KC_SLSH);
          }
        }
      }

      return false;
    case KC_rCtE:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        ctrl_allow_transform = true;
      } else {
        unregister_code(KC_LCTL);
        if (ctrl_allow_transform) {
          rshift_allow_transform = false;
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
      }
      return false;
    default:
      return true;
  }
}

////////////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool allow_tap = false;
  static uint16_t semi_timer = 0;
  static bool is_in_game_layer = false;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        if (sending_alt) {
          sending_alt = false;
          unregister_code(KC_LALT);
        }
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case SEMIKEY:
      if (record->event.pressed) {
        semi_timer = timer_read();
        allow_tap = true;
        layer_on(_SEMI);
      } else {
        layer_off(_SEMI);
        if (allow_tap && timer_elapsed(semi_timer) < TAP_DELAY) {
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      return false;
      break;
    case KC_rNOR:
      if (record->event.pressed) {
        default_layer_set(1UL << _QWERTY);
        is_in_game_layer = false;
      }
      return false;
      break;
    case KC_rGAM:
      if (record->event.pressed) {
        default_layer_set(1UL << _GAME);
        is_in_game_layer = true;
      }
      return false;
      break;
    case KC_rTOG:
      if (record->event.pressed) {
        if (is_in_game_layer) {
          is_in_game_layer = false;
          default_layer_set(1UL << _QWERTY);
        } else {
          is_in_game_layer = true;
          default_layer_set(1UL << _GAME);
        }
      }
      return false;
      break;
    default:
      allow_tap = false;
      break;
  }

  bool unintercepted = false;

  unintercepted = process_mod_tap_keys(keycode, record);
  if (!unintercepted) return unintercepted;

  unintercepted = process_my_keys(keycode, record);
  if (!unintercepted) return unintercepted;

  unintercepted = process_programmer_key_combos(keycode, record);
  if (!unintercepted) return unintercepted;

  return true;
}
