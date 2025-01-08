// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ 1 │ 2 │ 3 │ 4 | 5 |
     * ├───┼───┼───┼───┬───┬───┐
     * │CAP│ Q │ W │ E │ R | T |
     * ├───┼───┼───┼───┬───┬───┐
     * │BKS│ A │ S │ D │ F | G |
     * ├───┼───┼───┼───┬───┬───┐
     * │CTL│ Z │ X │ C │ V | B |
     * └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
        KC_CAPS,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_BSPC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
        KC_ENT,    KC_TAB,
        KC_6,   KC_7,   KC_8,  KC_9, KC_0, KC_MINS, 
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
        KC_BSPC, KC_SPC
    )
};

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Draw to OLED
bool oled_task_user() {
    // set cursor position
    oled_set_cursor(0, 1);
    
    // Write to oled
    oled_write("Manta Ray\n\n", false);

    // Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);

    return false;
}

#endif
