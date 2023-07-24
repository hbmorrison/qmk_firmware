#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NUM_LAYER,
  FUNC_LAYER
};

enum my_tap_dances {
  TD_Z_CAPS,
  TD_X_CUT,
  TD_C_COPY,
  TD_V_PASTE,
  TD_F_PGDN,
  TD_B_PGUP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, KC_W, TD(TD_F_PGDN), KC_P, TD(TD_B_PGUP),
          KC_J, KC_L, KC_U, KC_Y, KC_BSPC, KC_NO,
      KC_NO, LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G,
          KC_M, LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), KC_NO,
      KC_NO, TD(TD_Z_CAPS), TD(TD_X_CUT), TD(TD_C_COPY), KC_D, TD(TD_V_PASTE),
          KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
      KC_NO, OSM(MOD_LSFT), KC_SPC, KC_ENT, OSL(SYM_LAYER), KC_NO
  ),
  [SYM_LAYER] = LAYOUT_split_3x6_3(
      KC_NO, KC_ESC, KC_DQUO, LSFT(KC_3), KC_DLR, KC_PERC,
          KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS, KC_NO,
      KC_NO, KC_TAB, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN,
          KC_COLN, KC_AT, KC_TILD, KC_MINS, KC_EQL, KC_NO,
      KC_NO, TO(FUNC_LAYER), KC_NUBS, KC_RBRC, KC_RCBR, KC_RPRN,
          KC_SCLN, KC_QUOT, KC_HASH, KC_GRV, KC_EXLM, KC_NO,
      KC_NO, TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NUM_LAYER), KC_NO
  ),
  [NUM_LAYER] = LAYOUT_split_3x6_3(
      KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,
          KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
      KC_NO, LCTL(KC_TAB), LALT(KC_TAB), LGUI(KC_TAB), KC_BTN1, KC_BTN2,
          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL, KC_NO,
      KC_NO, TO(FUNC_LAYER), KC_NO, KC_NO, KC_NO, LSFT(KC_V),
          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO,
      KC_NO, TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x6_3(
      KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_MNXT,
          KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS, KC_NO,
      KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_MPLY,
          KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL, KC_NO,
      KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_MPRV,
          KC_MUTE, KC_NO, KC_NO, KC_DOT, KC_SLSH, KC_NO,
      KC_NO, TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NUM_LAYER), KC_NO
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Z, twice for Caps Lock
    [TD_Z_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_CAPS),
    // Tap once for X, twice for Ctrl-X
    [TD_X_CUT] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_CUT),
    // Tap once for C, twice for Ctrl-C
    [TD_C_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COPY),
    // Tap once for V, twice for Ctrl-V
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_PSTE),
    // Tap once for F, twice for Ctrl-F
    [TD_F_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F)),
    // Tap once for B, twice for Ctrl-B
    [TD_B_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_B, LCTL(KC_B)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Return to the base later after fn keys, space or enter have been pressed
    case KC_F1 ... KC_F12:
    case KC_SPC:
    case KC_ENT:
      if (record->event.pressed) {
        layer_move(BASE_LAYER);
      }
      break;
    // Return to num layer if symbol keys in the func layer have been pressed
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
    case KC_SLSH:
      if (record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NUM_LAYER);
        }
      }
      break;
  }
  return true;
}
