// Copyright 2022 zvecr <git@zvecr.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <print.h>

// void keyboard_post_init_kb(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
// //   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
// print("keyboard pressed")
//     //   uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif 
//   return true;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, \
        KC_LCTL, MO(1),   KC_LALT,                   KC_SPC,                             KC_RALT, KC_RIGHT_GUI, MO(2),          KC_RCTL  \
    ),
        [1] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
        RGB_TOG, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, XXXXXXX, XXXXXXX,   XXXXXXX,   KC_UP,   XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
        RGB_MOD, RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,   XXXXXXX,          XXXXXXX, \
        KC_LSFT, RGB_M_B, RGB_M_R, RGB_M_SW,_______, RESET,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                   XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                              XXXXXXX , XXXXXXX, XXXXXXX,         XXXXXXX  \
    ),
    [2] = LAYOUT_60_ansi(
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX, \
        XXXXXXX,   RGB_TOG,   RGB_MOD,  RGB_HUI,   RGB_SAI,   RGB_VAI,   RGB_SPI,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX, \
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX, \
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                         XXXXXXX, \
        XXXXXXX,   XXXXXXX,   XXXXXXX,                         RGB_TOG,                                    XXXXXXX,   XXXXXXX,     XXXXXXX,              XXXXXXX \
    )

};
