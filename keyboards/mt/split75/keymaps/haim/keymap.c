// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    BASE = 0,
    MO_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base          ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Del |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspace | Home|
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | PgUp|
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgDn|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | End |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |   Space   |Fn   |     | Space         |  Alt  |     | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [BASE] = LAYOUT(
    //--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
                      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(1),   KC_INS,  KC_DEL,
    KC_MUTE, KC_TRNS, KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_EQUAL,KC_BSPC,          KC_HOME,
    KC_F14,  KC_F15,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    KC_F16,  KC_F17,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENTER,                  KC_PGDN,
    KC_F18,  KC_F19,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,
    KC_F20,  KC_F21,  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  _______,                       KC_SPC,  KC_RGUI, KC_RALT, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [MO_1] = LAYOUT(
                      QK_BOOT, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______, _______
    )
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    { // Key Matrix to LED Index
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
     { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
    },
    { // LED Index to Physical Position
     { 0,  0 }, { 112,  0 }, { 224, 0 }, { 224,  64 }, {  112,  64 }, {  0,  64 }, { 112, 32 }
    },
    { // LED Index to Flag
     0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a
    }
};
#endif
