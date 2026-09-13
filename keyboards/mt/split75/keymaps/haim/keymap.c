// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    BASE = 0,
    MO_1
};

enum custom_keycodes {
    MAC_SIRI = SAFE_RANGE,
    MAC_DND
};

// macOS fn: F21, remapped to fn by hidutil at login (see macos/me.g8n.split75-fn.plist). macOS ignores F21 otherwise.
// Real fn/Globe needs Apple's VID/PID. Globe (consumer 0x29D) arrives on the second USB interface, so fn would not
// apply to keys on the keyboard interface.
#define KC_MAC_FN KC_F21

// Webex App meeting shortcuts. Mute and video are ticked "Global" in Webex settings, so they work in the background.
#define WBX_MUTE S(G(KC_M))
#define WBX_VID  C(S(KC_V))

// Rectangle. ⌃⌥⌘←/→ are rebound on both Macs to "Display 2/3" (left/right Dell; the open laptop is Display 1):
// the stock previous/next display cycle through all screens and wrap around.
#define RCT_DSPL C(A(G(KC_LEFT)))
#define RCT_DSPR C(A(G(KC_RIGHT)))
#define RCT_2_3  C(A(KC_E))   // left 2/3; again for right 2/3
#define RCT_1_3  C(A(KC_G))   // right 1/3; again cycles centre and left
#define RCT_MAX  C(A(KC_ENT))

#define SCR_CLIP C(S(G(KC_4))) // screenshot of an area to the clipboard

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base          ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 | L1  | Ins | Del |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |WMute|WVid |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspace | Home|
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |Siri | DND |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | PgUp|
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |<Dspl|Dspl>|  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgDn|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * | 2/3 | 1/3 |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | End |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * | Max |Shot |  | Ctrl  |  Opt |  Cmd |   Space   | fn  |     | Space         |  Cmd  | Opt | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [BASE] = LAYOUT(
    //--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
                      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(1),   KC_INS,  KC_DEL,
    WBX_MUTE,WBX_VID, KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_EQUAL,KC_BSPC,          KC_HOME,
    MAC_SIRI,MAC_DND, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    RCT_DSPL,RCT_DSPR,KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENTER,                  KC_PGDN,
    RCT_2_3, RCT_1_3, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,
    RCT_MAX, SCR_CLIP,KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_MAC_FN,                     KC_SPC,  KC_RGUI, KC_RALT, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [MO_1] = LAYOUT(
                      QK_BOOT, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,
    UG_TOGG, UG_NEXT, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_SIRI:
            // Siri's keyboard shortcut is set to 🌐S on both Macs. Held while the key is held: tap types to Siri, hold talks.
            if (record->event.pressed) {
                register_code(KC_MAC_FN);
                register_code(KC_S);
            } else {
                unregister_code(KC_S);
                unregister_code(KC_MAC_FN);
            }
            return false;
        case MAC_DND:
            // Generic Desktop 0x9B "System Do Not Disturb", Apple's Focus key. config.h widens the System Control range for it.
            host_system_send(record->event.pressed ? 0x9B : 0);
            return false;
    }
    return true;
}

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
