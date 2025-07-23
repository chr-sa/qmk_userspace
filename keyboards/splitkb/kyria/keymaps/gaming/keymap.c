#include QMK_KEYBOARD_H
#include "features/socd_cleaner.h"

socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

enum layers {
    _QWERTY = 0,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define ADJUST   MO(_ADJUST)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_ESC, KC_TAB ,  KC_W   ,  KC_X  ,   KC_E ,   KC_R ,                                      _______, _______, _______, _______, _______, _______,
     KC_H  , KC_LSFT,  KC_A   ,  KC_W  ,   KC_D ,   KC_F ,                                      _______, _______, _______, _______, _______, _______,
     KC_J  , KC_LCTL,  KC_Z   ,  KC_S  ,   KC_C ,   KC_B , KC_NO  , KC_P,     _______, _______, _______, _______, _______, _______, _______, _______,
                                ADJUST , KC_LALT, KC_SPC , KC_GRV , KC_M,     _______, _______, _______, _______, _______
    ),


    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_socd_cleaner(keycode, record, &socd_v)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_h)) { return false; }
  return true;
}
