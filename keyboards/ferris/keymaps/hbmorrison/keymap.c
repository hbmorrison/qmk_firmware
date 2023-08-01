#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  SCUT_LAYER,
  NAV_LAYER,
  FUNC_LAYER
};

enum my_keycodes {
    M_DSKN = SAFE_RANGE,
    M_DSKP,
    M_ESCQ,
    M_ESCW,
    M_EQLR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
    KC_A, LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), KC_O,
    KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, TO(SCUT_LAYER),
    OSM(MOD_LSFT), KC_SPC, KC_ENT, OSL(SYM_LAYER)
  ),
  [SYM_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM, LSFT(KC_2), LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
    KC_ESC, LSFT(KC_NUBS), KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN, LSFT(KC_QUOT), LSFT(KC_BSLS), KC_MINS, KC_EQL,
    TO(FUNC_LAYER), KC_NUBS, KC_RBRC, KC_RCBR, KC_RPRN, KC_SCLN, KC_QUOT, KC_BSLS, KC_GRV, KC_QUES,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NAV_LAYER)
  ),
  [SCUT_LAYER] = LAYOUT_split_3x5_2(
    M_ESCQ, M_ESCW, LCTL(KC_F), LSFT(LCTL(KC_SPC)), LCTL(KC_B), KC_WH_D, KC_NO, KC_NO, KC_NO, KC_DEL,
    KC_TAB, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_G), HYPR(KC_M), HYPR(KC_4), HYPR(KC_5), HYPR(KC_6), KC_NO,
    KC_CAPS, LCTL(KC_X), LCTL(KC_C), LSFT(LCTL(KC_C)), LCTL(KC_V), KC_WH_U, KC_NO, KC_NO, M_EQLR, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  ),
  [NAV_LAYER] = LAYOUT_split_3x5_2(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TAB, LCTL(KC_TAB), LALT(KC_TAB), KC_BTN1, KC_BTN2, KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    TO(FUNC_LAYER), KC_NO, M_DSKP, M_DSKN, LSFT(KC_V), KC_INS, KC_NO, KC_PGDN, KC_PGUP, KC_END,
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x5_2(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MNXT, KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MUTE, KC_NO, KC_COMM, KC_DOT, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(SYM_LAYER)
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_ESCQ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":q!"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCW:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":wq"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_EQLR:
      if (record->event.pressed) {
        SEND_STRING("=> ");
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    // Respond to next desktop macro.
    case M_DSKN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
    // Respond to previous desktop macro.
    case M_DSKP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_LEFT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Return to the base layer after a function key is pressed.
    case KC_F1 ... KC_F24:
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Return to the base later after space or enter have been pressed.
    case KC_SPC:
    case KC_ENT:
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Cancel caps lock if escape is pressed.
    case KC_ESC:
      if (host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
      break;
    // Return to the num layer if symbols in the func layer have been pressed.
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
      if (!record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
      }
      break;
    // Slash appears in multiple layers and returns to multiple layers.
    case KC_SLSH:
      if (!record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
        if (IS_LAYER_ON(SCUT_LAYER)) {
          layer_move(BASE_LAYER);
        }
      }
      break;
    // Make most of the shortcut layer shortcuts behave like a one shots.
    case KC_TAB:
    case KC_CAPS:
    case LCTL(KC_X):
    case LCTL(KC_C):
    case LCTL(KC_V):
    case LCTL(KC_F):
    case LCTL(KC_B):
    case LSFT(LCTL(KC_SPC)):
    case LSFT(LCTL(KC_C)):
    case HYPR(KC_1):
    case HYPR(KC_2):
    case HYPR(KC_3):
    case HYPR(KC_G):
    case HYPR(KC_M):
    case HYPR(KC_4):
    case HYPR(KC_5):
    case HYPR(KC_6):
      if (!record->event.pressed) {
        if (IS_LAYER_ON(SCUT_LAYER)) {
          layer_move(BASE_LAYER);
        }
      }
      break;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Set the tapping term for the homerow mods.
    case LGUI_T(KC_R):
    case LALT_T(KC_S):
    case LCTL_T(KC_T):
    case RCTL_T(KC_N):
    case RALT_T(KC_E):
    case RGUI_T(KC_I):
      return TAPPING_TERM_MODS;
    // Set the tapping term for the paste key differently.
    case LCTL(KC_V):
      return TAPPING_TERM_PASTE;
    default:
      return TAPPING_TERM;
  }
}
