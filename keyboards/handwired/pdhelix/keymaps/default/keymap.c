/* Copyright 2018 'mtei'
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
#include QMK_KEYBOARD_H

#define KC_RBSCP LT(_RAISE,KC_BSPC)
#define KC_RENT LT(_RAISE,KC_ENT)
#define KC_LOWER MO(_LOWER)

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  BS  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | Ctrl |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   `  |   '  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Lower | Lower| Caps |  Alt |  GUI | Space|  BS  | Enter| Space| GUI  | Alt  | Menu |Lower |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_kc( /* Base */
      ESC,    1,    2,    3,    4,    5,                6,    7,    8,    9,    0,    BSPC, \
      TAB,    Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P,    BSLS, \
      LCTL,   A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN,    RCTL, \
      LSFT,   Z,    X,    C,    V,    B,   GRV,  QUOT,  N,    M,  COMM, DOT, SLSH,    RSFT, \
      LOWER,LOWER,CAPS,LALT, LGUI,  SPC, RBSCP,  RENT, SPC, RGUI, RALT, APP, LOWER,  LOWER \
  ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |Pause | ScrLk| Ins  |      |             |      | Ins  | ScrLk|Pause |      | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | PgUp |      | Up   |Delete| Home |             | Home |Delete| Up   |      | PgUp |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | PgDn | Left | Down | Right| End  |      |      | End  | Left | Down | Right| PgDn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | PrtSc|      |      |      |Adjust|Adjust|      |      |      | PrtSc|      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(                                                    \
      XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
      XXXXXXX, XXXXXXX, KC_PAUS, KC_SLCK, KC_INS,  XXXXXXX,                   XXXXXXX, KC_INS,  KC_SLCK, KC_PAUS, XXXXXXX, KC_F12, \
      _______, KC_HOME, XXXXXXX, KC_UP,   KC_DEL,  KC_PGUP,                   KC_PGUP, KC_DEL,  KC_UP,   XXXXXXX, KC_HOME, _______, \
      _______, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  XXXXXXX, XXXXXXX,KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, \
      _______, _______, KC_PSCR, _______, _______, _______, MO(_ADJUST),
                                                                 MO(_ADJUST), _______, _______, _______, KC_PSCR, _______, _______ \
      ),
  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |  _   |  -   |             |  =   |  +   |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |  {   |  [   |             |  ]   |  }   |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      | EISU | EISU | KANA | KANA | Next | Vol- | Vol+ | Play |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_MINS), KC_MINS,         KC_EQL, LSFT(KC_EQL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_LBRC), KC_LBRC,       KC_RBRC, LSFT(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    EISU,    EISU,    KANA,    KANA, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, \
      MO(_ADJUST),MO(_ADJUST),XXXXXXX, _______, _______, XXXXXXX, _______,
                                                                _______, XXXXXXX, _______, _______, XXXXXXX,MO(_ADJUST),MO(_ADJUST) \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|RGB ON|Aud on| Win  |             | Win  |Aud on|RGB ON|RGBRST|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | HUE+ | SAT+ | VAL+ |RGB md|Audoff| Mac  |             | Mac  |Audoff|RGB md| VAL+ | SAT+ | HUE+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | HUE- | SAT- | VAL- |      |      |      |      |      |      |      |      | VAL- | SAT- | HUE- |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, RESET,   RGBRST,  RGB_TOG,   AU_ON, AG_SWAP,                   AG_SWAP,   AU_ON, RGB_TOG,  RGBRST, XXXXXXX, XXXXXXX, \
      RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  AU_OFF, AG_NORM,                   AG_NORM,  AU_OFF, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, \
      RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, \
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______ \
   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
