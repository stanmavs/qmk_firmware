/* Copyright 2023 Stanislavs Malahvejs (https://github.com/stanmavs)
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

enum layer_names {
  _QWERTY,
  _SYMBOL,
  _NUMPAD,
  _NAVFUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ┌────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┐
 * │   Q    │   W    │   E    │   R    │   T    │           │   Y    │   U    │   I    |   O    |   P    |
 * ├────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┤
 * │ Gui(A) │ Alt(S) │ Ctrl(D)│ Shft(F)│   G    │           │   H    │ Shft(J)│ Ctrl(K)| Alt(L) | Gui(:) |
 * ├────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┤
 * │   Z    │   X    │   C    │   V    │   B    │           │   N    │   M    │  , <   |  . >   |  / ?   |
 * └────────┴────────┴────────┴────────┴────────┘           └────────┴────────┴────────┴────────┴────────┘
 *                      ┌────────┬────────┬────────┐    ┌────────┬────────┬────────┐
 *                      |Nav(Esc)|Sym(Spc)|        |    |        |Sym(Bsp)|Nav(Del)|
 *                      └────────┴────────┤Num(Tab)|    | Enter  ├────────┴────────┘
 *                                        |        |    |        |
 *                                        └────────┘    └────────┘
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,         KC_W,         KC_E,           KC_R,         KC_T,         KC_Y,    KC_U,          KC_I,         KC_O,         KC_P,
  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J),  RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  KC_Z,         KC_X,         KC_C,           KC_V,         KC_B,         KC_N,    KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,
                      LT(3,KC_ESC),   LT(1,KC_SPC), LT(2,KC_TAB),         KC_ENT,  LT(1,KC_BSPC), LT(3,KC_DEL)
),

/* SYMBOL
 *
 * ┌──────┬──────┬──────┬──────┬──────┐           ┌──────┬──────┬──────┬──────┬──────┐
 * │   !  │   @  │   #  │   $  │   %  │           │   ^  │   &  │   *  │   +  │   =  │
 * ├──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┤
 * │   ~  │   ]  │   }  │   )  │   |  │           │   _  │   (  │   {  │   [  │   -  │
 * ├──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┤
 * │  Alt │ Ctrl │ Shft │   \  │      │           │      │   /  │ Shft │ Ctrl │  Alt │
 * └──────┴──────┴──────┴──────┴──────┘           └──────┴──────┴──────┴──────┴──────┘
 *                  ┌──────┬──────┬──────┐    ┌──────┬──────┬──────┐
 *                  |      |   `  |      |    |      |  "   |  $   |
 *                  └──────┴──────┤  '   |    |  ^   ├──────┴──────┘
 *                                |      |    |      |
 *                                └──────┘    └──────┘
 */
[_SYMBOL] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQUAL,
  KC_TILD, KC_RBRC, KC_RCBR, KC_RPRN, KC_PIPE,         KC_UNDS, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINUS,
  KC_LALT, KC_LCTL, KC_LSFT, KC_BSLS, KC_NO,           KC_NO,   KC_SLSH, KC_RSFT, KC_RCTL, KC_RALT,
                    KC_NO,   KC_GRV,  KC_QUOT,         KC_CIRC, KC_DQUO, KC_DLR
),

/* NUMPAD
 *
 * ┌──────┬──────┬──────┬──────┬──────┐           ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │           │   *  │   7  │   8  │   9  │   -  │
 * ├──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┤
 * │  Gui │  Alt │ Ctrl │ Shft │      │           │  Bsp │   4  │   5  │   6  │   +  │
 * ├──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │           │   /  │   1  │   2  │   3  │ Enter│
 * └──────┴──────┴──────┴──────┴──────┘           └──────┴──────┴──────┴──────┴──────┘
 *                  ┌──────┬──────┬──────┐    ┌──────┬──────┬──────┐
 *                  |      |      |      |    |      |  0   |  .   |
 *                  └──────┴──────┤      |    |  ,   ├──────┴──────┘
 *                                |      |    |      |
 *                                └──────┘    └──────┘
 */
[_NUMPAD] = LAYOUT_split_3x5_3(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_ASTR, KC_7, KC_8,   KC_9,  KC_MINUS,
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_BSPC, KC_4, KC_5,   KC_6,  KC_PLUS,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_SLSH, KC_1, KC_2,   KC_3,  KC_ENT,
                    KC_NO,   KC_NO,   KC_NO,      KC_COMM, KC_0, KC_DOT
),

/* NAVFUN
 *
 * ┌────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┐
 * │   F1   │   F2   │   F3   │   F4   │        │           │        │        │   ↑    |        |  PgUp  |
 * ├────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┤
 * │ Gui(F5)│ Alt(F6)│Ctrl(F7)│Shft(F8)│        │           │        │ Shft(←)│ Ctrl(↓)| Alt(→) |Gui(PgD)|
 * ├────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┤
 * │   F9   │  F10   │  F11   │  F12   │        │           │        │        │        |        |        |
 * └────────┴────────┴────────┴────────┴────────┘           └────────┴────────┴────────┴────────┴────────┘
 *                      ┌────────┬────────┬────────┐    ┌────────┬────────┬────────┐
 *                      |        |PrintScr|        |    |        |        |   End  |
 *                      └────────┴────────┤        |    |  Home  ├────────┴────────┘
 *                                        |        |    |        |
 *                                        └────────┘    └────────┘
 */
[_NAVFUN] =  LAYOUT_split_3x5_3(
  KC_F1,         KC_F2,          KC_F3,          KC_F4,         KC_NO,         KC_NO,   KC_NO,           KC_UP,           KC_NO,            KC_PGUP,
  LGUI_T(KC_F5), LALT_T(KC_F6),  LCTL_T(KC_F7),  LSFT_T(KC_F8), KC_NO,         KC_NO,   RSFT_T(KC_LEFT), RCTL_T(KC_DOWN), RALT_T(KC_RIGHT), RGUI_T(KC_PGDN),
  KC_F9,         KC_F10,         KC_F11,         KC_F12,        KC_NO,         KC_NO,   KC_NO,           KC_NO,           KC_NO,            KC_NO,
                                 KC_NO,          KC_PSCR,       KC_NO,         KC_HOME, KC_NO,           KC_END
)
};