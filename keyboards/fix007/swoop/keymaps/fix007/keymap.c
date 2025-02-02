#include QMK_KEYBOARD_H
#include "keymap_german.h"

#include <stdio.h>

char wpm_str[8];

extern keymap_config_t keymap_config;


/*
 * Keycode aliases
 */

#define _v_     KC_TRNS
#define ___     KC_NO
#define x__ENT  LCTL_T(KC_ENT)     /* ctrl(hold) or enter(tap) */
#define x__Q    LCTL_T(KC_Q)       /* ctrl(hold) or q(tap) */
#define x__CBSP C(KC_BSPC)         /* Delete word */
#define x__LMB  KC_MS_BTN1         /* Left mouse button */
#define x__RMB  KC_MS_BTN2         /* Right mouse button */
#define x__MMB  KC_MS_BTN3         /* Mid mouse button */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK_DH 0
#define _QWERTZ 1
#define _SYM 2
#define _NAV 3
#define _HEX 4
#define _FUN 5
#define _ADJ 6
#define _RGB 7

enum custom_keycodes {
  COLEMAK_DH = SAFE_RANGE,
  QWERTZ,
  SYM,
  NAV,
  HEX,
  FUN,
  ADJ,
};

// macro keys
#define CALTDEL LCTL(LALT(KC_DEL)) // ctrl-alt-del
#define CALTESC LCTL(LSFT(KC_ESC)) // ctrl-alt-esc
#define CALT LCTL(KC_LALT) // ctrl-alt

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * Colemak DH ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │ q  │ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ z  │bks │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ y  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,- │ ._ │ent^│
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │cmd │SYM │ sft  │ │ spc  │NAV │opt │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

[_COLEMAK_DH] = LAYOUT_split_3x5_3( \
  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,                 DE_J,    DE_L,    DE_U,    DE_Z,    KC_BSPC, \
  DE_A,    DE_R,    DE_S,    DE_T,    DE_G,                 DE_M,    DE_N,    DE_E,    DE_I,    DE_O,  \
  DE_Y,    DE_X,    DE_C,    DE_D,    DE_V,                 DE_K,    DE_H,    DE_COMM, DE_DOT,  x__ENT,  \
              KC_LGUI, MO(_SYM), KC_LSFT,		            KC_SPC, MO(_NAV), KC_LALT \
),

  /*
   * _QWE / Qwertz ──
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │ q  │ w  │ e  │ r  │ t  │     │ z  │ u  │ i  │ o  │ p  │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ a  │ s  │ d  │ f  │ g  │     │ h  │ j  │ k  │ l  │bks │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ y  │ x  │ c  │ v  │ b  │     │ n  │ m  │ ,  │ .  │ent^│
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │cmd │SYM │ sft  │ │ spc  │NAV │opt │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

[_QWERTZ] = LAYOUT_split_3x5_3( \
  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                       DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, \
  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                       DE_H,    DE_J,    DE_K,    DE_L,    KC_BSPC,  \
  DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                       DE_N,    DE_M,    DE_COMM, DE_DOT,  x__ENT,  \
              KC_LGUI, MO(_SYM), KC_LSFT,		            KC_SPC, MO(_NAV), KC_LALT \
),


 /*
   * _SYM / Symbols ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │ '  │ "  │ ^  │ ?  │ `  │     │ [  │ <  │ =  │ >  │ ]  │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ !  │ @  │ #  │ $  │ %  │     │ {  │ (  │ :  │ )  │ }  │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ \  │ ~  │ |  │ ;  │ &  │     │ /  │ *  │ -  │ +  │ _  │
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │    │ ▓▓ │ ADJ  │ │      │FUN │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_SYM] = LAYOUT_split_3x5_3(
    DE_QUOT, DE_DQUO, DE_CIRC, DE_QUES, DE_GRV,   /**/ DE_LBRC, DE_LABK,  DE_EQL,  DE_RABK,   DE_RBRC,
    DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC,  /**/ DE_LCBR, DE_LPRN,  DE_COLN, DE_RPRN, DE_RCBR,
    DE_BSLS, DE_TILD, DE_PIPE, DE_SCLN, DE_AMPR,  /**/ DE_SLSH, DE_ASTR,  DE_MINS, DE_PLUS, DE_UNDS,
    /**/     /**/     _v_,     _v_,     MO(_ADJ), /**/ _v_,     MO(_FUN), _v_      /**/     /**/
  ),
/*
   * _NAV / Navigate ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────╭────┬────┬────╮┄───╮
   * │ctl │cmd │ ⇧↹ │ ↹  │opt │    │ ,  │home│ ▲  │end │del │
   * ├────┼────┼────┼────┼────┤     ├────├────┼────┼────┤┄───┤
   * │ 1  │ 2  │ 3  │ 4  │ 5  │     │ .  │ ◀  │ ▼  │ ▶  │ent │
   * ├────┼────┼────┼────┼────┤     ├────╰────┴────┴────╯┄───┤
   * │ 6  │ 7  │ 8  │ 9  │ 0  │     │esc │ p↑ │ p↓ │esc │ctl │
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │cmd │HEX │ sft  │ │      │ ▓▓ │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_NAV] = LAYOUT_split_3x5_3(
    KC_LCTL, KC_RGUI, S(KC_TAB), KC_TAB,   KC_RALT, /**/ DE_COMM, KC_HOME, KC_UP,   KC_END,  KC_DEL,
    DE_1,    DE_2,    DE_3,      DE_4,     DE_5,    /**/ DE_DOT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    DE_6,    DE_7,    DE_8,      DE_9,     DE_0,    /**/ KC_ESC,  KC_PGUP, KC_PGDN, KC_ESC,  KC_LCTL,
    /**/     /**/     _v_,       MO(_HEX), _v_,     /**/ _v_,     KC_ENT,  _v_      /**/     /**/
  ),
  // }}}

  /*
   * _HEX / Hex input ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │ #  │ ,  │ .  │ :  │bks │     │ ,  │ A  │ B  │ C  │bks │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ 1  │ 2  │ 3  │ 4  │ 5  │     │ .  │ D  │ E  │ F  │ent │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │ 6  │ 7  │ 8  │ 9  │ 0  │     │ /  │ *  │ -  │ +  │ :  │
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │    │ ▓▓ │ spc  │ │ spc  │    │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_HEX] = LAYOUT_split_3x5_3(
  DE_HASH, DE_COMM, DE_DOT,  DE_COLN, KC_BSPC, /**/ DE_COMM, DE_A,    DE_B,    DE_C,    KC_BSPC,
  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    /**/ DE_DOT,  DE_D,    DE_E,    DE_F,    KC_ENT,
  DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    /**/ DE_SLSH, DE_ASTR, DE_MINS, DE_PLUS, DE_COLN,
  /**/     /**/     ___,      ___,  KC_SPC,    /**/ KC_SPC,  ___,     ___      /**/     /**/
  ),
  // }}}

  /*
   * _FUN / Function ── {{{
   * ╭────┬────┬────┐┄───┬────╮     ╭───┄┌────┬────┬────┐┄───╮
   * │f11 │f12 │prnt│play│next│     │ w↑ │ L  │ ▲  │ R  │ b+ │
   * ├────┼────┼────┼────┼────┐     ├───┄├────┼────┼────┤┄───┤
   * │ f1 │ f2 │ f3 │ f4 │ f5 │     │ w↓ │ ◀  │ ▼  │ ▶  │ b- │
   * ├────┼────┼────┼────┼────┤     ├───┄└────┴────┴────┘┄───┤
   * │ f6 │ f7 │ f8 │ f9 │f10 │     │    │ v- │ v+ │    │    │
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │    │ L  │      │ │      │ ▓▓ │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_FUN] = LAYOUT_split_3x5_3(
    KC_F11, KC_F12, KC_PSCR, KC_MPLY, KC_MNXT, /**/ KC_WH_U, x__LMB,  KC_MS_U, x__RMB,  KC_BRIU,
    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   /**/ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,
    KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  /**/ ___,     KC_VOLD, KC_VOLU, ___,     _v_,
    /**/    /**/    _v_,     x__LMB,  _v_,     /**/ _v_,     _v_,     ___      /**/     /**/
  ),
  // }}}

  /*
   * _ADJ / Adjust ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │    │ M  │ R  │ L  │caps│     │ p↑ │ ⇤  │ ▲  │ ⇥  │    │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │GAME│    │ w↓ │ w↑ │    │     │ p↓ │ ◀  │ ▼  │ ▶  │ctl │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │QWE │COLE│ p↓ │ p↑ │RGB │     │    │    │    │    │rset│
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │    │    │   ▓▓ │ │      │    │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_ADJ] = LAYOUT_split_3x5_3(
    ___,      x__MMB, x__RMB,  x__LMB,  KC_CAPS, /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  ___,
    /*GAM_ON*/ ___,   ___,    KC_WH_D, KC_WH_U, ___,     /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL,
    DF(_QWERTZ), DF(_COLEMAK_DH),    KC_PGDN, KC_PGUP, RGB_TOG, /**/ ___,     ___,     ___,     ___,     QK_BOOTLOADER,
    /**/      /**/    _v_,     ___,   _v_,     /**/ MO(_RGB),   _v_,     _v_      /**/     /**/
  ),

  /*
   * _ADJ / Adjust ── {{{
   * ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
   * │    │    │    │    │    │     │    │    │    │    │    │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │    │    │    │    │    │     │    │    │    │    │    │
   * ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * │    │    │    │    │    │     │    │    │    │    │    │
   * ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
   *           │    │    │      │ │      │    │    │
   *           ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_RGB] = LAYOUT_split_3x5_3(
    RGB_MODE_FORWARD,   RGB_MODE_REVERSE, ___,      ___,      ___, /**/ RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW,  RGB_MODE_SWIRL,  RGB_MODE_SNAKE,
    RGB_HUI,            RGB_SAI,          RGB_VAI,  RGB_SPI,  ___, /**/ RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT,  RGB_MODE_RGBTEST,  RGB_MODE_TWINKLE,
    RGB_HUD,            RGB_SAD,          RGB_VAD,  RGB_SPD,  ___, /**/ ___, ___, ___,  ___,  ___,
    /**/   /**/  _v_,  ___,   _v_,  /**/ ___,   _v_,     _v_      /**/     /**/
  ),
};

void matrix_init_user(void) {
  set_single_persistent_default_layer(_COLEMAK_DH);
};

// #ifdef OLED_DRIVER_ENABLE

/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}
*/

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_ln_P(PSTR("MAC"), false);
    // } else {
    //     oled_write_ln_P(PSTR("WIN"), false);
    // }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTZ:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
        case _QWERTZ:
            oled_write_P(PSTR("Base\n"), false);
            break;
        // case _MOUSE:
            // oled_write_P(PSTR("Mouse\n"), false);
            // break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _HEX:
            oled_write_P(PSTR("Hex\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/* Animation bit by j-inc https://github.com/qmk/qmk_firmware/tree/master/keyboards/kyria/keymaps/j-inc */
// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 320 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Implementation credit j-inc(/James Incandenza), pixelbenny, and obosob.
// Bongo cat images changed and adapted for sofle keyboard oled size.
// Original gif can be found here: https://www.pixilart.com/art/bongo-cat-bd2a8e9323aa705
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40,
        0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            /*
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            */
            oled_write_raw_P(idle[0], ANIM_SIZE);
         }
         /*
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }*/
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_anim();
        oled_set_cursor(0,12);
        sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
        oled_write(wpm_str, false);
    }
    return false;
}

// #endif
