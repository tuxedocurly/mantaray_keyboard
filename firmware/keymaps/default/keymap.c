// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer names for each layer
enum layer_names {
    _MAC_DEFAULT,
    _MAC_CODE,
    _MAC_MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ 1 │ 2 │ 3 │ 4 | 5 |              │ 6 │ 7 │ 8 │ 9 │ 0 | - |
     * ├───┼───┼───┼───┬───┬───┐              ├───┼───┼───┼───┬───┬───┐
     * │CAP│ Q │ W │ E │ R | T |              │ Y │ U │ I │ O │ P | \ |
     * ├───┼───┼───┼───┼───┼───┐              ├───┼───┼───┼───┼───┼───┐
     * │BKS│ A │ S │ D │ F | G |              │ H │ J │ K │ L │ ; | ' |
     * ├───┼───┼───┼───┼───┼───┐              ├───┼───┼───┼───┼───┼───┐
     * │CTL│ Z │ X │ C │ V | B |              │ N │ M │ , │ . │ / |CTL|
     * └───┴───┴───┴───┴───┼───┐              ┌───┼───┴───┴───┴───┴───┘
     *                     |ENT|              |SPC|
     *                     └───┘┌───┐    ┌───┐└───┘
     *                          |TAB|    |BSP|
     *                          └───┘    └───┘                    
     */
    [0] = LAYOUT(
        KC_ESC,    KC_1,   KC_2,    KC_3,   KC_4,    KC_5,
        KC_CAPS,   KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,
        SFT_T(KC_BSPC),KC_A,KC_S,   KC_D,   KC_F,    KC_G,
        KC_LGUI,   ALT_T(KC_Z),   KC_X,    KC_C,   KC_V,    KC_B,
        LT(1, KC_ENT),    CTL_T(KC_TAB),
        KC_6,      KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, 
        KC_Y,      KC_U,   KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_H,      KC_J,   KC_K,    KC_L,   KC_SCLN, RSFT_T(KC_QUOT),
        KC_N,      KC_M,   KC_COMMA,KC_DOT, RALT_T(KC_SLSH), KC_RCTL,
        SFT_T(KC_BSPC),   LT(2, KC_SPC)
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, 
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
        _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, 
        _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_7,    KC_8,    KC_9,    KC_MINS, KC_SLSH, KC_F12,
        KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR, KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_DOT,  KC_EQL,  KC_ENT,
        _______, KC_0
    ),
    [2] = LAYOUT(
        RM_TOGG, QK_KB,   RM_NEXT, RGB_M_P, RM_VALD, RM_VALU,         
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,         
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,         
        _______, _______, _______, _______, _______, _______,         
        _______, _______,
        _______, _______, _______, _______, _______, QK_BOOT,
        KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
        _______, _______
    ),
};

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Draw to OLED
bool oled_task_user() {
    // set cursor position
    oled_set_cursor(0, 0);

    // Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln(led_state.caps_lock ? PSTR("Caps\nLock\n  ON") : PSTR("Caps\nLock\n  OFF"), false);

    oled_set_cursor(0,5);
    oled_write_ln_P("Layer", false);
    switch(get_highest_layer(layer_state)) {
        case _MAC_DEFAULT:
        oled_write_ln(" MAIN", false);
            break;
        case _MAC_CODE:
            oled_write_ln(" CODE", false);
            break;
        case _MAC_MEDIA:
            oled_write_ln("MEDIA", false);
            break;
    }

    oled_set_cursor(0,10);
    // Get and display WPM
    uint8_t wpm = get_current_wpm();
    char wpm_str[16];
    snprintf(wpm_str, sizeof(wpm_str), "WPM:\n  %u", wpm);
    oled_write_ln(wpm_str, false);

    return false;
}

#endif
