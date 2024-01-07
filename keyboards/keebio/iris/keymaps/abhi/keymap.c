#include QMK_KEYBOARD_H
enum my_layers {
    _WORK,
    _GAMING,
    _FUNCTION,
    _ADJUST
};

#define GAMING DF(_GAMING)
#define WORK DF(_WORK)
#define ADJUST DF(_ADJUST)
#define FUNCTION MO(_FUNCTION)
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD,

} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    FN_DANCE,
    SUPER_DANCE,
    CTRL_DANCE,
    ALT_DANCE
};

td_state_t cur_dance(tap_dance_state_t *state);

void fn_finished(tap_dance_state_t *state, void *user_data);
void fn_reset(tap_dance_state_t *state, void *user_data);
void super_finished(tap_dance_state_t *state, void *user_data);
void super_reset(tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WORK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    XXXXXXX,          GAMING,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT,KC_SLASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    TD(SUPER_DANCE), KC_SPC,  TD(CTRL_DANCE),    KC_RSFT,  TD(FN_DANCE), TD(ALT_DANCE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] =LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    XXXXXXX,          ADJUST,   KC_K,    KC_H,    KC_COMM, KC_DOT, KC_QUOT, KC_SLASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, KC_SPC,  TD(CTRL_DANCE),            KC_RSFT,  TD(FN_DANCE), TD(ALT_DANCE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNCTION] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,    KC_F2,    KC_F3, KC_F4,    KC_F5,                             KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LBRC, _______, KC_RBRC, _______,                            _______, KC_BSPC, KC_UP, KC_DEL,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_RSFT, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

 [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //
     _______, _______, _______, RGB_VAD, RGB_SAI, RGB_VAI,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, RGB_HUD, RGB_SAD, RGB_HUI,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          WORK, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {

        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    else return TD_DOUBLE_TAP;
}

void fn_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    layer_on(_FUNCTION);
    switch (td_state) {
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT));
            break;
        default:
            break;
    }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
   layer_off(_FUNCTION);
   unregister_mods(MOD_BIT(KC_RSFT));
}

void super_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    register_mods(MOD_BIT(KC_LGUI));
    switch (td_state) {
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_HOLD:
             register_mods(MOD_BIT(KC_RSFT));
            break;
        default:
            break;
    }
}

void super_reset(tap_dance_state_t *state, void *user_data) {
   unregister_mods(MOD_BIT(KC_LGUI));
   unregister_mods(MOD_BIT(KC_RSFT));
}

void ctrl_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    register_mods(MOD_BIT(KC_LCTL));
    switch (td_state) {
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_HOLD:
             register_mods(MOD_BIT(KC_RSFT));
            break;
        default:
            break;
    }
}

void ctrl_reset(tap_dance_state_t *state, void *user_data) {
   unregister_mods(MOD_BIT(KC_LCTL));
   unregister_mods(MOD_BIT(KC_RSFT));
}

void alt_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    register_mods(MOD_BIT(KC_RALT));
    switch (td_state) {
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_HOLD:
             register_mods(MOD_BIT(KC_RSFT));
            break;
        default:
            break;
    }
}

void alt_reset(tap_dance_state_t *state, void *user_data) {
   unregister_mods(MOD_BIT(KC_RALT));
   unregister_mods(MOD_BIT(KC_RSFT));
}

tap_dance_action_t tap_dance_actions[] = {
    [FN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [SUPER_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, super_finished, super_reset),
    [CTRL_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),
    [ALT_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _WORK, _GAMING, _ADJUST);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

        for (uint8_t i = led_min; i < led_max; i++) {
             if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            switch(get_highest_layer(layer_state|default_layer_state)) {
            case _WORK:
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0,255,0);
                break;
            case _GAMING:
                RGB_MATRIX_INDICATOR_SET_COLOR(i,0,0,255);
                break;
            case _ADJUST:
                RGB_MATRIX_INDICATOR_SET_COLOR(i,255,0,0 );
                break;
            default:
            RGB_MATRIX_INDICATOR_SET_COLOR(i,0,0,0 );
                break;
         }
            }
        }
    return false;
}
