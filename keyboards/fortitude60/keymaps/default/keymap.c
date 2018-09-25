#include QMK_KEYBOARD_H
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16
#define LOW_ES  LT(_LOWER,KC_LANG1)   // タップでかな       ホールドでLower         (Mac)
#define RIS_KN  LT(_RAISE,KC_LANG2)   // タップで英数       ホールドでRaise         (Mac)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   |                |  6   |  7   |  8   |  9   |  0   | MINS |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LSFT |  A   |  S   |  D   |  F   |  G   |                |  H   |  J   |  K   |  L   | SCLN | ENT  |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * | ESC  |  Z   |  X   |  C   |  V   |  B   | LBRC |  | RBRC |  N   |  M   | COMM | DOT  | SLSH | QUOT |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |RIS_KN| SPC  |  UP  |  | DOWN | SPC  |LOW_ES| LEFT | RGHT |
 *               `----------------------------------'  `----------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT , \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
),

/* Lower
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LCTL | F11  | F12  |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  D   |      |      |                |      | UNDS | PLUS | EQL  | PIPE |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |      |      |  C   |      |      |      |  |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |RIS_KN| SPC  |  UP  |  | DOWN | SPC  |LOW_ES| LEFT | RGHT |
 *               `----------------------------------'  `----------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, \
  KC_LCTL, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, KC_D,    _______, _______,                   _______, KC_UNDS, KC_PLUS, KC_EQL, KC_PIPE, _______, \
  _______, _______, _______, KC_C,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
),

/* Raise
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LCTL | F11  | F12  |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  D   |      |      |                |      | UNDS | PLUS | EQL  | PIPE |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |      |      |  C   |      |      |      |  |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |RIS_KN| SPC  |  UP  |  | DOWN | SPC  |LOW_ES| LEFT | RGHT |
 *               `----------------------------------'  `----------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, \
  KC_LCTL, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, KC_D,    _______, _______,                   _______, KC_UNDS, KC_PLUS, KC_EQL, KC_PIPE, _______, \
  _______, _______, _______, KC_C,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LCTL | F11  | F12  |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  D   |      |      |                |      | UNDS | PLUS | EQL  | PIPE |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |      |      |  C   |      |      |      |  |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |RIS_KN| SPC  |  UP  |  | DOWN | SPC  |LOW_ES| LEFT | RGHT |
 *               `----------------------------------'  `----------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, \
  KC_LCTL, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  \
  _______,  _______, _______, KC_D,   _______, _______,                   _______, KC_UNDS, KC_PLUS, _______, KC_PIPE, _______, \
  _______,  _______, _______, KC_C,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
),

/* Colemak
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   |                |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  F   |  P   |  G   |                |  J   |  L   |  U   |  Y   | SCLN | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | ESC  |  A   |  R   |  S   |  T   |  D   |                |  H   |  N   |  E   |  I   |  O   | QUOT |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   | LBRC |  | RBRC |  K   |  M   | COMM | DOT  | SLSH | ENT  |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |LOWER | SPC  | LCTL |  | ENT  | SPC  |RAISE | RALT | RGUI |
 *               `----------------------------------'  `----------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
),

/* Dvorak
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   |                |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  | QUOT | COMM | DOT  |  P   |  Y   |                |  F   |  G   |  C   |  R   |  L   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | ESC  |  A   |  O   |  E   |  U   |  I   |                |  D   |  H   |  T   |  N   |  S   | SLSH |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * | LSFT | SCLN |  Q   |  J   |  K   |  X   | LBRC |  | RBRC |  B   |  M   |  W   |  V   |  Z   | ENT  |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | LGUI | LALT |LOWER | SPC  | LCTL |  | ENT  | SPC  |RAISE | RALT | RGUI |
 *               `----------------------------------'  `----------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_LBRC, KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
                    KC_LGUI, KC_LALT, RIS_KN,  KC_SPC, KC_UP, KC_DOWN, KC_SPC,  LOW_ES,  KC_LEFT, KC_RGHT\
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}