// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#if !defined (MIRYOKU_LAYOUTMAPPING_GLOVE80)

#define XXX &none

#define AS(keycode) &as keycode
#define SK_SHIFT &kp_sticky LSHFT LSHFT

#define MIRYOKU_LAYOUTMAPPING_GLOVE80( \
     K00, K01, K02, K03, K04,                                    K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                                    K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                                    K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                                    K35, K36, K37, N38, N39 \
) \
&kp F1  &kp F2  &kp F3  &kp F4  &kp F5                                               &kp F6  &kp F7  &kp F8  &kp F9  &kp F10 \
&kp GRAVE  &kp N1  &kp N2  &kp N3  &kp N4  &kp N5                                     &kp N6  &kp N7  &kp N8  &kp N9  &kp N0  &kp BSPC \
AS(LBKT)  K00  K01  K02  K03  K04                                     K05  K06  K07  K08  K09  AS(RBKT)\
&s_par_esc  K10  K11  K12  K13  K14                                     K15  K16  K17  K18  K19  &comma_qmark \
&kp LSHFT K20  K21  K22  K23  K24  &ctrl_alt  &kp LGUI  &kp LALT   &kp RALT  &kp RGUI  &kp RCTRL  K25  K26  K27  K28  K29  &kp RSHFT \
U_CPY U_PST &kp LBRC  &kp LBKT  &kp LPAR       K33  K34  K32       K37  K35  K36       &kp RPAR      &kp RBKT  &kp RBRC  &kp LEFT  &kp RIGHT

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_GLOVE80
