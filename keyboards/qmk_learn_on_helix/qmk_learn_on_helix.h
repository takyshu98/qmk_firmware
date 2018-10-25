/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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
#ifndef QMK_LEARN_ON_HELIX_H
#define QMK_LEARN_ON_HELIX_H

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05, \
    L10, L11, L12, L13, L14, L15, \
    L20, L21, L22, L23, L24, L25, \
    L30, L31, L32, L33, L34, L35, L36, \
    L40, L41, L42, L43, L44, L45, L46 \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L36, \
        KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##L46 \
    )


#define LAYOUT( \
  L00, L01, L02, L03, L04, L05, \
  L10, L11, L12, L13, L14, L15, \
  L20, L21, L22, L23, L24, L25, \
  L30, L31, L32, L33, L34, L35, L36, \
  L40, L41, L42, L43, L44, L45, L46 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05,   KC_NO }, \
    { L10, L11, L12, L13, L14, L15,   KC_NO }, \
    { L20, L21, L22, L23, L24, L25,   KC_NO }, \
    { L30, L31, L32, L33, L34, L35, L36 },   \
    { L40, L41, L42, L43, L44, L45, L46 }    \
  }

#endif
