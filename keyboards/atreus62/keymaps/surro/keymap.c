// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _SYM 1
#define _NUM 2
#define _NAV 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwertz */
    KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,     KC_5,                  KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    DE_SS ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,                  DE_Z,      KC_U,    KC_I,    KC_O,    KC_P,    DE_UE ,
    KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,     KC_G,         	 KC_H,      KC_J,    KC_K,    KC_L,    DE_OE,   DE_AE ,
    KC_LSFT,  DE_Y,    KC_X,    KC_C,   KC_V,     KC_B,		         KC_N,      KC_M,    KC_COMM, KC_DOT,  DE_MINS, KC_RSFT ,
    KC_LCTL,  KC_LGUI, KC_LALT, MO(_NUM),MO(_SYM),KC_BSPC,KC_ENT, KC_DEL, KC_SPC, MO(_SYM),   KC_NO  , KC_RALT, KC_APP, MO(_NAV)
  ),

  [_SYM] = LAYOUT(
    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_TRNS,  DE_EURO, DE_AT,   DE_LBRC, DE_RBRC, DE_CIRC,                     DE_EXLM, DE_LESS, DE_MORE, DE_EQL,  DE_ASTR, DE_PLUS ,
    KC_TRNS,  DE_GRV,  DE_ACUT, DE_LCBR, DE_RCBR, DE_DLR,                      DE_QST,  DE_LPRN, DE_RPRN, DE_DQOT, DE_QUOT, DE_HASH ,
    KC_TRNS,  KC_TRNS, KC_TRNS, DE_PIPE, DE_TILD, DE_BSLS,                     DE_SLSH, DE_PERC, DE_AMPR, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
  ),

  [_NUM] = LAYOUT(
    RESET,   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_NO  , KC_NO  ,  KC_NO , KC_NO  , KC_NO, KC_NO,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_NO,   KC_7  ,  KC_8  ,   KC_9  , KC_NO , KC_NO, 
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      DE_SLSH, KC_4  ,  KC_5  ,   KC_6  , DE_ASTR , KC_NO,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      DE_MINS, KC_1  ,  KC_2  ,   KC_3  , DE_PLUS  , KC_NO,
    KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS  , KC_TRNS  ,  KC_TRNS  ,  KC_NO, KC_0, KC_COMM , KC_DOT  , KC_NO  , KC_NO
  ),

  
  [_NAV] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS,                     KC_PGUP, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_PGDN, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
  
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
