#include "keymap_common.h"

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |      Space             |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
    [0] = 
    KEYMAP(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSLS, \
        ESC,A,   S,   D,   FN7,   G,   H,   FN6,   K,   L,   SCLN,QUOT, ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,Q, \
        LGUI,LALT,LCTL,          FN0,                     RCTL,RALT,RGUI, Q),

    /* Overlay 1: SpaceFN
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [1] =
    KEYMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, DEL, \
        TRNS,TRNS,FN4,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP, RGHT,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,FN5, PGDN,GRV, FN5, TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),

    [2] = 
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, BSPC, \

        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   BSPC, Q, Q, \
        ESC,A,   S,   D,   TRNS,   G,   H,   TRNS,   K,   L,   SCLN,QUOT, Q,  \
        TRNS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,TRNS,Q, \
        TRNS,TRNS,TRNS,          BSPC,                     TRNS,TRNS,TRNS, Q),

    [3] = 
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, BSPC, \

        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   BSPC, Q, Q, \
        ESC,A,   S,   D,   TRNS,   G,   H,   LBRC,   RBRC,   BSLS,   MINS, EQL, Q,  \
        TRNS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,TRNS,Q, \
        TRNS,TRNS,TRNS,          BSPC,                     TRNS,TRNS,TRNS, Q),
};

enum macro_id {
    HELLO,
    VOLUP,
    MOVE_WORD_FORWARD,
    MOVE_WORD_BACKWARD,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    [2] = ACTION_MACRO(MOVE_WORD_FORWARD),                      // Application switching
    [3] = ACTION_MACRO(MOVE_WORD_BACKWARD),                      // Application switching
    [4] = ACTION_MODS_KEY(MOD_LCTL, KC_RIGHT),    // tilde
    [5] = ACTION_MODS_KEY(MOD_RCTL, KC_LEFT),    // tilde
    [6] = ACTION_LAYER_TAP_KEY(2, KC_J),
    [7] = ACTION_LAYER_TAP_KEY(3, KC_F),

};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case HELLO:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
        case MOVE_WORD_FORWARD:
            return (record->event.pressed ?
                    MACRO( D(LCTRL), D(RIGHT), END ) :
                    MACRO( U(RIGHT), END ));
        case MOVE_WORD_BACKWARD:
            return (record->event.pressed ?
                    MACRO( D(LCTRL), D(LEFT), END ) :
                    MACRO( U(LEFT), END ));
    }
    return MACRO_NONE;
}

