// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#if !defined (MIRYOKU_LAYOUTMAPPING_GO60)

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_GO60( \
     K00, K01, K02, K03, K04,                 K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                 K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                 K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                 K35, K36, K37, N38, N39 \
) \
&kp ESC  &kp N1  &kp N2  &kp N3  &kp N4  &kp N5                                     &kp N6  &kp N7  &kp N8  &kp N9  &kp N0  &kp BSPC \
U_PST K00  K01  K02  K03  K04                  K05  K06  K07  K08  K09  &kp EQUAL \
U_CPY K10  K11  K12  K13  K14                  K15  K16  K17  K18  K19  &comma_qmark \
&kp LSHFT  K20  K21  K22  K23  K24                  K25  K26  K27  K28  K29  &kp RSHFT \
          &kp LBRC  &kp LBKT  &kp LPAR              &kp RPAR      &kp RBKT  &kp RBRC  \
          K33  K34  K32                       K37  K35  K36

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 53 54
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 55 56

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_GO60

