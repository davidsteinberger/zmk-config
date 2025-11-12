// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define ZMK_POINTING_DEFAULT_MOVE_VAL 1000  // default: 600
#define ZMK_POINTING_DEFAULT_SCRL_VAL 20    // default: 10

#define MIRYOKU_NAV_VI
#define MIRYOKU_CLIPBOARD_MAC
#define MIRYOKU_KLUDGE_MOUSEKEYSPR
#define MIRYOKU_KLUDGE_DOUBLETAPBOOT
//#define MIRYOKU_KLUDGE_TAPDELAY

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(ALT,    "Alt") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define U_BASE   0
#define U_ALT    1
#define U_EXTRA  2
#define U_TAP    3
#define U_BUTTON 4
#define U_NAV    5
#define U_MOUSE  6
#define U_MEDIA  7
#define U_NUM    8
#define U_SYM    9
#define U_FUN    10

#define MIRYOKU_LAYERMAPPING_ALT MIRYOKU_MAPPING

#define AS(keycode) &as keycode
#define RALT_MINUS_DQT &ht_minus_dqt RALT 0
#define U_MTL(mod, keycode) &hml mod keycode
#define U_MTR(mod, keycode) &hmr mod keycode

#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,  \
&kp LGUI,          &kp LALT,          &kp LCTL,         &kp LSHFT,         U_NA,              U_MS_L,            U_MS_D,            U_MS_U,            U_MS_R,            &kp ESC, \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_WH_L,            U_WH_D,            U_WH_U,            U_WH_R,            U_NU,   \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_ALT,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           &kp INS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

#define MIRYOKU_LAYER_BASE \
&kp B,             &kp L,             &kp D,             &kp W,             &kp Z,             &apos_under,             &kp F,             &kp O,             &kp U,             &kp J,     \
U_MTL(LGUI, N),     U_MTL(LALT, R),     U_MTL(LCTL, T),    U_MTL(LSHFT,S),    &kp G,             &kp Y,             &hmr LSHFT H,    U_MTR(LCTL, A),    U_MTR(LALT, E),     U_MTR(LGUI, I), \
U_LT(U_BUTTON, Q), U_MTL(RALT, X),     &kp M,             &kp C,             &kp V,             &kp K,             &kp P,             &dot_gt,         RALT_MINUS_DQT,   &slash_lt ,   \
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_ALT \
&kp B,             &kp L,             &kp D,             &kp W,             &kp Z,             &apos_under,             &kp F,             &kp O,             &kp U,             &kp J,     \
U_MTL(LGUI, N),     U_MTL(LALT, R),     U_MTL(LCTL, T),    U_MTL(LSHFT, S),    &kp G,             &kp Y,             U_MTR(LSHFT, H),    U_MTR(LCTL, A),    U_MTR(LALT, E),     U_MTR(LGUI, I), \
U_LT(U_BUTTON, Q), U_MTL(RALT, X),     &kp M,             &kp C,             &kp V,             &kp K,             &kp P,             &dot_gt,         RALT_MINUS_DQT,   &slash_lt ,   \
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),&ak_sc,&ak_tab,U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
&kp LBKT,          &kp N7,            &kp N8,            &kp N9,            &kp RBKT,          U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp SEMI,          &kp N4,            &kp N5,            &kp N6,            &kp EQUAL,         U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp GRAVE,         &kp N1,            &kp N2,            &kp N3,            &kp BSLH,          &kp COMMA,         &u_to_U_NUM,       &u_to_U_NAV,       &kp RALT,          &kp DOT,              \
U_NP,              U_NP,              &kp DOT,           &kp N0,            &kp MINUS,         U_NA,              U_NA,              U_NA,              U_NP,              U_NP
