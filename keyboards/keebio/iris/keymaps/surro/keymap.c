// based on krusli

#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_german.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,     KC_3,     KC_4,     KC_5,                       KC_6,      KC_7,       KC_8,       KC_9,       KC_0,       DE_SS,
    KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,       DE_UE,
    KC_LCTL,  KC_A,    KC_S,     KC_D,     KC_F,     KC_G,                       KC_H,      KC_J,       KC_K,       KC_L,       DE_OE,      DE_AE,
    KC_LSFT,  KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,     KC_LALT,  KC_APP, KC_N,      KC_M,       DE_COMM,    DE_DOT,     DE_MINS,    KC_RSFT,
										KC_LGUI,    LOWER,      KC_ENT,  KC_SPC, RAISE,   KC_BSPS
  ),

  [_LOWER] = LAYOUT(
    DE_ACUT,  _______, _______,  _______,  _______,  _______,                    _______,   _______,    _______,    _______,    KC_PSLS,    DE_CIRC,
    _______,  DE_AT,   XXXXXXX,  DE_EURO,  KC_HOME,  KC_PGUP,                    XXXXXXX,   KC_4,       KC_5,       KC_6,       KC_PAST,    DE_TILD,
    _______,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_END,   KC_PGDN,                    XXXXXXX,   KC_1,       KC_2,       KC_3,       KC_PPLS,    DE_HASH,
    _______,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, _______, XXXXXXX,   KC_0,       _______,    _______,    KC_PMNS,    DE_LESS,
                                           _______,  _______,  _______, _______, _______,   KC_DEL
  ),

  [_RAISE] = LAYOUT(
    KC_F12,   KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,                    	KC_F6, 		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
    KC_CAPS,  XXXXXXX,  XXXXXXX,  KC_UP,   XXXXXXX, XXXXXXX,                    XXXXXXX,  	DE_LBRC,    DE_RBRC,    DE_BSLS,	XXXXXXX,	XXXXXXX,
    _______,  XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RGHT, XXXXXXX,                    XXXXXXX,   	DE_LPRN,    DE_RPRN,    DE_PIPE,    XXXXXXX,    KC_RCTL,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX,   	DE_LCBR,    DE_RCBR,    DE_SLSH,    XXXXXXX,    _______,
                                           _______, _______,  _______, _______, _______,   	KC_DEL
  ),

  [_ADJUST] = LAYOUT(
    RESET,   _______, _______,  _______,  _______,  _______,                    _______,  _______,    _______,    _______,    _______,    _______,
    RGB_TOG, RGB_MOD, RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,                    _______,  _______,    _______,    _______,    _______,    _______,
    _______, _______, RGB_HUD,  RGB_SAD,  RGB_SAD,  RGB_VAD,                    _______,  _______,    _______,    _______,    _______,    _______,
    BL_STEP, _______,   _______,  _______,  _______,  _______,  _______, _______, _______,  _______,    _______,    _______,    _______,    _______,
                                            _______,  _______,  _______, _______, _______,  _______
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
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
  }
  return true;
}
