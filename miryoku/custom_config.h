// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define MIRYOKU_NAV_VI
#define MIRYOKU_CLIPBOARD_MAC
#define MIRYOKU_KLUDGE_MOUSEKEYSPR
#define MIRYOKU_KLUDGE_TAPDELAY

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(SEN,    "Sen")

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9
#define U_SEN    10

#define MIRYOKU_LAYERMAPPING_SEN MIRYOKU_MAPPING

#define AS(keycode) &as keycode
#define SC_SPACE_SHIFT &sc_mo_space_shift U_NAV 0
#define RALT_MINUS_DQT &ht_minus_dqt RALT 0

#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,  \
&kp LGUI,          &kp LALT,          &kp LCTL,         &kp LSHFT,         U_NA,              U_MS_L,            U_MS_D,            U_MS_U,            U_MS_R,            &kp ESC, \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_WH_L,            U_WH_D,            U_WH_U,            U_WH_R,            U_NU,   \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP

#define MIRYOKU_LAYER_BASE \
&kp B,             &kp L,             &kp D,             &kp W,             &kp Z,             &apos_under,             &kp F,             &kp O,             &kp U,             &kp J,     \
U_MT(LGUI, N),     U_MT(LALT, R),     U_MT(LCTL, T),    U_MT(LSHFT, S),    &kp G,             &kp Y,             U_MT(LSHFT, H),    U_MT(LCTL, A),    U_MT(LALT, E),     U_MT(LGUI, I), \
U_LT(U_BUTTON, Q), U_MT(RALT, X),     &kp M,             &kp C,             &kp V,             &kp K,             &kp P,             &sc_dot,         RALT_MINUS_DQT,   &slash_lt ,   \
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_SEN \
&trans,            &trans,            &trans,            &trans,         &trans,            &trans,            &trans,            &trans,            &trans,            &trans, \
&trans,            &trans,            &trans,            &trans,         &trans,            &trans,            &trans,            &trans,            &trans,            &trans, \
&trans,            &trans,            &trans,            &trans,         &trans,            &trans,            &trans,            &trans,            &trans,            &trans, \
U_NP,              U_NP,              U_NP,              SC_SPACE_SHIFT, &trans,            &trans,            &trans,            U_NP,              U_NP,              U_NP
