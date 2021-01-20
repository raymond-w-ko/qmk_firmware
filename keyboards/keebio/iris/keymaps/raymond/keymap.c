#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define  _BASE 0
#define _GAME0 1
#define _GAME1 2
#define   _SYM 3
#define   _NAV 4
#define   _NUM 5
#define   _FNC 6
#define   _MOU 7
#define   _SYS 8

#define df_BASE DF(_BASE)
#define df_GAM0 DF(_GAME0)
#define df_GAM1 DF(_GAME1)
#define lt_FNC LT(_FNC, KC_F13)

#define osl_SYM OSL(_SYM)
#define osl_NAV OSL(_NAV)
#define osl_NUM OSL(_NUM)
#define osl_FNC OSL(_FNC)
#define osl_MOU OSL(_MOU)
#define osl_SYS OSL(_SYS)

#define osm_CTL OSM(MOD_LCTL)
#define osm_ALT OSM(MOD_LALT)
#define osm_SFT OSM(MOD_LSFT)
#define osm_GUI OSM(MOD_LGUI)
#define osm_HYP OSM(MOD_HYPR)
#define osm_CS OSM(MOD_LCTL | MOD_LSFT)
#define osm_CA OSM(MOD_LCTL | MOD_LALT)

#define sTAB LSFT(KC_TAB)
#define sINS LSFT(KC_INS)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  tmux_L,
  tmux_R,
  gui_L,
  gui_R,
};

///////////////////////////////////////////////////////////////////////////////

#define KC_ KC_NO
#define _ KC_NO

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

#define KC_xx00 X(0)
#define KC_xx01 X(1)
#define KC_xx02 X(2)
#define KC_xx03 X(3)
#define KC_xx04 X(4)
#define KC_xx05 X(5)
#define KC_xx06 X(6)
#define KC_xx07 X(7)
#define KC_xx08 X(8)
#define KC_xx09 X(9)
#define KC_xx10 X(10)
#define KC_xx11 X(11)
#define KC_xx12 X(12)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LEFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  KC_RGHT,
  KC_Z,    KC_LSFT, KC_X,    KC_C,    KC_V,    KC_B,     lt_FNC,          KC_LCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_SLSH,
                                      KC_LALT, osl_NUM, osl_NAV,          KC_SPC,  osl_SYM, KC_LGUI
),
[_GAME0] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  KC_RGHT,
  KC_Z,    KC_LSFT, KC_X,    KC_C,    KC_V,    KC_B,     lt_FNC,          KC_LCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_SLSH,
                                      KC_LALT, osl_NUM, KC_SPC,           KC_SPC,  osl_SYM, KC_LALT
),
[_GAME1] = LAYOUT(
  KC_ESC,  KC_5,    KC_1,    KC_2,    KC_3,    KC_4,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_G,    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  KC_QUOT,
  KC_B,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    lt_FNC,          KC_RCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_SLSH,
                                      KC_LALT, osl_NUM, KC_SPC,           KC_SPC,  osl_SYM, KC_LALT
),
[_SYM] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       KC_LABK, KC_MINS, KC_DQUO, KC_PLUS, KC_SCLN,                            KC_GRV,  KC_RBRC, KC_RPRN, KC_RCBR, KC_PIPE, _,
  _,       KC_RABK, KC_UNDS, KC_QUOT, KC_EQL,  KC_COLN,                            KC_BSPC, KC_LBRC, KC_LPRN, KC_LCBR, KC_AMPR, _,
  _,       KC_EXLM, KC_ASTR, KC_AT,   KC_SLSH, KC_QUES, osm_GUI,          osm_CA,  KC_TILD, KC_DLR,  KC_HASH, KC_BSLS, KC_PERC, _,
                                      _,       osm_HYP, osl_NAV,          osm_CS,  osl_NAV, _
),
[_NAV] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       KC_ENT,  sTAB,    KC_ESC,  KC_TAB,  KC_DEL,                             sTAB,    KC_PGUP, KC_UP,   KC_PGDN, KC_APP,  _,
  _,       osm_GUI, osm_CTL, osm_SFT, osm_ALT, KC_BSPC,                            KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _,
  _,       C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _,       osl_FNC,          KC_F13,  KC_TAB,  KC_HOME, KC_DEL,  KC_END,  KC_INS,  _,
                                      _,       KC_T,    osl_NAV,          KC_SPC,  osl_SYM, _
),
[_NUM] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       KC_PCMM, tmux_L,  KC_UP,   tmux_R,  KC_CIRC,                            KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _,
  _,       _,       KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT,                            KC_BSPC, KC_P4,   KC_P5,   KC_P6,   KC_PENT, _,
  _,       _,       gui_L,   sINS,    gui_R,   _,       osl_SYM,          KC_PEQL, KC_PPLS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _,
                                      _,       _,       osl_NAV,          KC_P0,   KC_PDOT, _
),

[_FNC] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                               osm_ALT, KC_F7,   KC_F8,   KC_F9,   KC_F11,  _,
  _,       KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                               osm_SFT, KC_F4,   KC_F5,   KC_F6,   KC_F10,  _,
  _,       KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    osl_MOU,          _,       osm_CTL, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _,
                                      _,       osl_SYS, osl_NAV,          KC_CAPS, KC_LGUI, _
),

[_MOU] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       _,       _,       _,       _,       _,       _,                _,       _,       _,       _,       _,       _,       _,
                                      _,       _,       _,                _,       _,       _
),

[_SYS] = LAYOUT(
  _,       _,       _,       _,       _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       KC_PSCR, _,       KC_VOLU, KC_MUTE, _,                                  _,       _,       _,       _,       _,       _,
  _,       _,       _,       KC_VOLD, _,       _,                                  _,       _,       _,       _,       _,       _,
  _,       _,       _,       _,       _,       _,       _,                _,       _,       _,       _,       _,       _,       _,
                                      _,       _,       _,                _,       _,       _
),

};
// clang-format on

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

static bool process_my_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // tmux keys
    case tmux_L:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_P);
      }
      return true; // maintain one shot layer behavior
    case tmux_R:
      if (record->event.pressed) {
        press_two_keys(KC_LCTL, KC_SPC);
        press_key(KC_N);
      }
      return true; // maintain one shot layer behavior
    // window manager keys
    case gui_L:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_LEFT);
      }
      return true; // maintain one shot layer behavior
    case gui_R:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_RGHT);
      }
      return true; // maintain one shot layer behavior
  }

  return true;
}

////////////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool continue_processing = true;

  continue_processing = process_my_keys(keycode, record);
  if (!continue_processing) return continue_processing;

  return true;
}

////////////////////////////////////////

static void process_host_input(uint8_t* data, uint8_t length) {
  if (length == 0) return;

  switch (data[0]) {
    case 0x01: // reserved by system
      break;
    case 0x02:
      default_layer_set(1UL << _BASE);
      break;
    case 0x03:
      default_layer_set(1UL << _GAME0);
      break;
    case 0x04:
      default_layer_set(1UL << _GAME1);
      break;
    case 0xFE: // reserved by system
      break;
  }
}

void process_console_data_user(uint8_t* data, uint8_t length) {
  process_host_input(data, length);
}

void raw_hid_receive(uint8_t* data, uint8_t length) {
  process_host_input(data, length);
}
