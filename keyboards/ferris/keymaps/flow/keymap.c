#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "mac_keymap.h"
#include "flow.h"

enum layers {
    _CRTN = 0,
    _CRTN_MAC,
    _NAV,
    _NAV_MAC,
    _SYM,
    _SYM_MAC,
    _NUM,
    _NUM_MAC,
    _FUNCTION,
    _ADJUST,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    SYM = SAFE_RANGE,
    NAV,
    NUM,
    NAV_MAC,
    SYM_MAC,
    NUM_MAC,
};

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)

#define SYM_MAC  MO(_SYM_MAC)
#define NAV_MAC  MO(_NAV_MAC)
#define NUM_MAC  MO(_NUM_MAC)

const uint16_t flow_config[FLOW_COUNT][2] = {
    {NAV, KC_LSFT},
    {NAV, KC_LALT},
    {NAV, KC_LGUI},
    {NAV, KC_LCTL},
    {SYM, KC_RSFT},
    {SYM, KC_RCTL},
    {SYM, KC_RGUI},
    {SYM, KC_RALT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
};

// Aliases for readability
#define CRTN     DF(_CRTN)
#define CRTN_MAC DF(_CRTN_MAC)
#define SNUG3    DF(_SNUG3)

#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define COPY     C(DE_C)
#define PASTE    C(DE_V)
#define CUT      C(DE_X)
#define UNDO     C(DE_Z)

#define COPY_MAC  C(DE_C)
#define PASTE_MAC C(DE_V)
#define CUT_MAC   C(DE_X)
#define UNDO_MAC  C(DE_Z)

#define DELBS    MT(MOD_LCTL, KC_BSPC)
#define OSS      OSM(MOD_LSFT)

// clang-format off
#define ALPHA_LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29) \
    LAYOUT( \
	    K00, K01, K02, K03, K04,   K05, K06, K07, K08, K09, \
	    K10, K11, K12, K13, K14,   K15, K16, K17, K18, K19, \
	    K20, K21, K22, K23, K24,   K25, K26, K27, K28, K29, \
                    NAV, KC_SPC,   OSS, SYM \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // f l d v q y m o u '
    // s r t n b g c e i a
    // x j k h p z w / , .
    [_CRTN] = LAYOUT(
     DE_F, DE_L, DE_D, DE_V, DE_Q,  DE_Y, DE_M, DE_O   , DE_U   , DE_QUOT,
     DE_S, DE_R, DE_T, DE_N, DE_B,  DE_G, DE_C, DE_E   , DE_I   , DE_A   ,
     DE_X, DE_J, DE_K, DE_H, DE_P,  DE_Z, DE_W, DE_SLSH, DE_COMM, DE_DOT ,
                      NAV, KC_SPC,  OSS, SYM
    ),

    [_CRTN_MAC] = LAYOUT(
     MC_G, MC_L, MC_D, MC_V, MC_Q,  MC_K, MC_F, MC_O   , MC_U   , DE_QUOT,
     MC_C, MC_R, MC_T, MC_N, MC_P,  MC_Y, MC_S, MC_E   , MC_I   , MC_A   ,
     MC_Z, MC_J, MC_M, MC_H, MC_B,  MC_X, MC_W, DE_SLSH, DE_COMM, DE_DOT ,
                  NAV_MAC, KC_SPC,  OSS, SYM_MAC
    ),

    [_NAV] = LAYOUT(
      _______, G(C(KC_LEFT)), KC_LGUI, G(C(KC_RIGHT)), _______,  KC_PGUP, KC_HOME, KC_UP  , KC_END  , CW_TOGG,
      KC_LGUI, KC_LALT      , KC_LSFT, KC_LCTL       , _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT ,
      UNDO   , CUT          , COPY   , PASTE         , _______,  KC_LGUI, KC_BSPC, KC_ESC , KC_TAB  , KC_DEL ,
                                     _______, ADJUST , KC_ENT,  _______
    ),

    [_NAV_MAC] = LAYOUT(
      _______, C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT), _______,  KC_PGUP, KC_HOME, KC_UP  , KC_END  , CW_TOGG,
      KC_LGUI, KC_LALT   , KC_LSFT   , KC_LCTL    , _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT ,
      UNDO   , CUT       , COPY      , PASTE      , _______,  KC_LGUI, KC_BSPC, KC_ESC , KC_TAB  , KC_DEL ,
                                        _______, ADJUST , KC_ENT,  _______
    ),

    [_SYM] = LAYOUT(
     DE_ASTR, DE_PLUS, DE_LCBR, DE_RCBR, DE_TILD,  DE_AMPR, DE_SS   , DE_ODIA , DE_UDIA, DE_ADIA,
     DE_BSLS, DE_EQL , DE_LPRN, DE_RPRN, DE_HASH,  DE_GRV , KC_RCTL , KC_RSFT , KC_RALT, KC_RGUI,
     DE_CIRC, DE_MINS, DE_LBRC, DE_RBRC, DE_DLR ,  DE_PIPE, DE_LABK , DE_RABK , DE_QUES, DE_EXLM,
                                _______, _______,  _______, _______
    ),

    [_SYM_MAC] = LAYOUT(
     MC_ASTR, MC_PLUS, MC_LCBR, MC_RCBR, MC_TILD,  MC_AMPR, MC_SS  , MC_ODIA, MC_UDIA, MC_ADIA,
     MC_BSLS, MC_EQL , MC_LPRN, MC_RPRN, MC_HASH,  MC_GRV , KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI,
     MC_CIRC, MC_MINS, MC_LBRC, MC_RBRC, MC_DLR ,  MC_PIPE, MC_LABK, MC_RABK, MC_QUES, MC_EXLM,
                                _______, _______,  _______, _______
    ),

    [_NUM] = LAYOUT(
	DE_SUP2, DE_EURO, DE_PERC, DE_ASTR, _______, DE_PLUS, DE_7, DE_8, DE_9, DE_DOT ,
	KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, DE_ACUT, DE_EQL , DE_1, DE_2, DE_3, DE_0   ,
	DE_SECT, DE_MICR, DE_AT  , DE_SLSH, _______, DE_MINS, DE_4, DE_5, DE_6, DE_COMM,
                          _______, _______, _______, _______
    ),

    [_NUM_MAC] = LAYOUT(
	_______, MC_EURO, MC_PERC, MC_ASTR, _______, MC_PLUS, MC_7, MC_8, MC_9, MC_DOT ,
	KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, MC_ACUT, MC_EQL , MC_1, MC_2, MC_3, MC_0   ,
	MC_SECT, MC_MICR, MC_AT  , MC_SLSH, _______, MC_MINS, MC_4, MC_5, MC_6, MC_COMM,
                          _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,  _______, _______, _______, _______, _______,
      KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,  _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI ,
      KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,  _______, _______, _______, _______, _______,
                                _______, _______,  _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______,  _______, _______, _______ , _______,  _______,
      _______, _______, _______, _______, _______,  _______, CRTN   , CRTN_MAC, _______,  _______,
      _______, _______, _______, _______, _______,  _______, _______, _______ , _______,  _______,
                                 _______, _______,  _______, _______
    ),
};


void keyboard_pre_init_user(void) {
  setPinOutput(24);
  writePinHigh(24);
}

const key_override_t quote_override = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);
const key_override_t spc_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, DE_UNDS);
const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_MINS);

const key_override_t *key_overrides[] = {
    &quote_override,
    &spc_override,
    &slsh_override,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _SYM);
}
