#include QMK_KEYBOARD_H 
#include "keymap_german.h"

enum layers {
	_QWERTY,
	_PUQ,
	_SYM,
	_NAV,
	_ADJUST
};

enum keycodes {
	QWERTY = SAFE_RANGE,
	PUQ
};

enum tapdance {
	DOT_COMM = 0,
	H_TAB
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[DOT_COMM] 	= ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
	[H_TAB] 	= ACTION_TAP_DANCE_DOUBLE(KC_H, KC_TAB)

};

#define BSPSYM 	LT(_SYM, KC_BSPC)
#define SPCNAV 	LT(_NAV, KC_SPC)
#define Z_SFT	LSFT_T(KC_Z)
#define X_CTL	LCTL_T(KC_X)
#define M_CTL	LCTL_T(KC_M)
#define C_ALT 	LALT_T(KC_C)
#define N_ALT	LALT_T(KC_N)
#define SFT_0	LSFT_T(KC_0)
#define CTL_3	LCTL_T(KC_3)

#define DOTCOM	TD(DOT_COMM)
#define K_SFT 	LSFT_T(KC_K)
#define Y_CTL	LCTL_T(KC_Y)
#define B_CTL	LCTL_T(KC_B)
#define W_ALT	LALT_T(KC_W)
#define X_ALT	LALT_T(KC_X)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_ortho_3x10(
		KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
		KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_ENT,
		Z_SFT, 	X_CTL,	C_ALT,	KC_V,	BSPSYM,	SPCNAV, KC_B,	N_ALT,	M_CTL,	KC_RSFT // ideal: hold = shift, tap = comma, doubletap = point
	),

	[_PUQ] = LAYOUT_ortho_3x10(
		KC_P,	KC_U,	KC_LEAD,DOTCOM, KC_Q,	KC_G,	KC_C,	KC_L,	KC_M,	KC_F,
		KC_H,	KC_I,	KC_E,	KC_A,	KC_O,	KC_D,	KC_T,	KC_R,	KC_N,	KC_S,
		K_SFT, 	Y_CTL,	X_ALT,	KC_J,	BSPSYM, SPCNAV, KC_V,	W_ALT,	B_CTL,	Z_SFT
	),

	[_SYM] = LAYOUT_ortho_3x10(
		KC_ESC,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LESS, DE_MORE, DE_EQL,  DE_AMPR,
		DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QST,  DE_LPRN, DE_RPRN, DE_COLN, DE_AT,
		DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, _______, _______, DE_DQOT, DE_QUOT, DE_SCLN, KC_PERC
	),

	[_NAV] = LAYOUT_ortho_3x10(
		KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_PPLS, KC_7,    KC_8,    KC_9, 	KC_DOT,
		KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PMNS, KC_4,    KC_5,    KC_6, 	KC_COMM,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_1,    KC_2,    CTL_3, 	SFT_0
	),

	[_ADJUST] = LAYOUT_ortho_3x10(
		XXXXXXX,QWERTY, PUQ,	XXXXXXX,BL_INC,	BL_TOGG,DE_GRV, XXXXXXX,XXXXXXX,XXXXXXX,
		KC_TAB,	XXXXXXX,XXXXXXX,XXXXXXX,BL_DEC,	BL_BRTG,XXXXXXX,XXXXXXX,XXXXXXX,KC_ENT,
		XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,_______,RESET,	XXXXXXX,XXXXXXX,KC_RSFT
	)
};

uint32_t layer_state_set_user(uint32_t state) {
  state =  update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
  return state;
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_A) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_2)SS_UP(X_LALT));
		}
		SEQ_ONE_KEY(KC_O) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_8)SS_UP(X_LALT));
		}
		SEQ_ONE_KEY(KC_U) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_9)SS_UP(X_LALT));
		}
		SEQ_ONE_KEY(KC_S) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_UP(X_LALT));
		}
		SEQ_TWO_KEYS(KC_A, KC_A) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_2)SS_UP(X_LALT));
		}
		SEQ_TWO_KEYS(KC_O, KC_O) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)SS_UP(X_LALT));
		}
		SEQ_TWO_KEYS(KC_U, KC_U) {
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_8)SS_UP(X_LALT));
		}
	}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PUQ:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PUQ);
      }
      return false;
      break;
  }
  return true;
};
