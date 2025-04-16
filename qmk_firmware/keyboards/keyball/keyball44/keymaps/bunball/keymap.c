/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer_names { 
  _BASE,
  _FIRST,
  _SECOND,
  _THRID,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [_BASE] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , LT(_THRID,KC_SCLN)  , KC_QUOT  ,
    KC_LCTL  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_BSLS  ,
              KC_LALT,KC_LGUI,     MO(_FIRST),LSFT_T(KC_SPC),LCTL(KC_SPC),                  KC_BSPC,LT(_SECOND,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  [_FIRST] = LAYOUT_universal(
    _______ ,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                                        LSFT(KC_6),LSFT(KC_7)   ,LSFT(KC_8)   ,LSFT(KC_9)   ,LSFT(KC_0),_______  ,
    _______ , KC_GRV   ,LSFT(KC_GRV), _______, _______  , KC_PPLS  ,                                         KC_EQL   , KC_MINS     ,LSFT(KC_LBRC),LSFT(KC_RBRC), KC_LBRC  , KC_RBRC ,
    _______ ,  _______ , _______   , _______ , _______  , KC_PSLS  ,                                         _______  ,LSFT(KC_MINS),LSFT(KC_COMM),LSFT(KC_DOT) , _______  , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [_SECOND] = LAYOUT_universal(
    _______  , _______  , KC_7     , KC_8    , KC_9     , KC_SLSH  ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_4     , KC_5    , KC_6     , KC_DOT   ,                                         KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______  ,
    _______  , _______  , KC_1     , KC_2    , KC_3     , KC_0     ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  [_THRID] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , KC_BTN1  , SCRL_MO  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Auto enable scroll mode when the highest layer is 3
//     keyball_set_scroll_mode(get_highest_layer(state) == 3);
//     return state;
// }

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
