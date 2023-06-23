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
    SUPER_DANCE
};

td_state_t cur_dance(tap_dance_state_t *state);

void fn_finished(tap_dance_state_t *state, void *user_data);
void fn_reset(tap_dance_state_t *state, void *user_data);
void super_finished(tap_dance_state_t *state, void *user_data);
void super_reset(tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WORK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    XXXXXXX,          GAMING,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH,KC_QUOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    TD(SUPER_DANCE), KC_SPC,  KC_LCTL,                  KC_RSFT,  TD(FN_DANCE), KC_RALT
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
     KC_BSLS, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    XXXXXXX,          ADJUST,   KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLASH,KC_QUOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, KC_SPC,  KC_LCTL,                  KC_RSFT,  TD(FN_DANCE), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNCTION] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LBRC, _______, KC_RBRC, _______,                            _______, KC_BSPC, KC_UP	, KC_DEL, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_RSFT, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

 [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
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
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    else return TD_DOUBLE_TAP;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.

void fn_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    layer_on(_FUNCTION);
    switch (td_state) {
        case TD_SINGLE_HOLD:
            // layer_on(_FUNCTION); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
            register_mods(MOD_BIT(KC_RSFT));
            // layer_on(_FUNCTION);
            
            break;
        default:
            break;
    }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
//    td_state_t td_state = cur_dance(state);
   layer_off(_FUNCTION);
   unregister_mods(MOD_BIT(KC_RSFT));
    // switch (td_state) {
    //     case TD_SINGLE_HOLD:
    //         // layer_off(_FUNCTION); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
    //         break;
    //     case TD_DOUBLE_HOLD:
    //     // unregister_mods(MOD_BIT(KC_RSFT));
    //         // layer_off(_FUNCTION);
            
    //         break;
    //     default:
    //         break;
    // }
}

void super_finished(tap_dance_state_t *state, void *user_data) {
    td_state_t td_state = cur_dance(state);
    register_mods(MOD_BIT(KC_LGUI));
    switch (td_state) {
        case TD_SINGLE_HOLD:
            // layer_on(_FUNCTION); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
             register_mods(MOD_BIT(KC_RSFT));
            // layer_on(_FUNCTION);
            
            break;
        default:
            break;
    }
}

void super_reset(tap_dance_state_t *state, void *user_data) {
//    td_state_t td_state = cur_dance(state);
   unregister_mods(MOD_BIT(KC_LGUI));
   unregister_mods(MOD_BIT(KC_RSFT));
    // switch (td_state) {
    //     case TD_SINGLE_HOLD:
    //         // layer_off(_FUNCTION); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
    //         break;
    //     case TD_DOUBLE_HOLD:
    //     // unregister_mods(MOD_BIT(KC_RSFT));
    //         // layer_off(_FUNCTION);
            
    //         break;
    //     default:
    //         break;
    // }
}

tap_dance_action_t tap_dance_actions[] = {
    [FN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [SUPER_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, super_finished, super_reset)          
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _WORK, _GAMING, _ADJUST);
}
