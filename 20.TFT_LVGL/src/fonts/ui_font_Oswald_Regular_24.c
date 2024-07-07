/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --font C:\Users\VIETNGU\Desktop\LVGL_Watchface-main\SquareLine_240\assets\Oswald-Regular.ttf -o C:\Users\VIETNGU\Desktop\LVGL_Watchface-main\SquareLine_240\assets\ui_font_Oswald_Regular_24.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_OSWALD_REGULAR_24
#define UI_FONT_OSWALD_REGULAR_24 1
#endif

#if UI_FONT_OSWALD_REGULAR_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xdb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb0, 0x1f, 0x80,

    /* U+0022 "\"" */
    0xdf, 0x7d, 0xb6, 0xdb, 0x60,

    /* U+0023 "#" */
    0x19, 0xc6, 0x73, 0x9c, 0xe6, 0x39, 0x8c, 0x6f,
    0xff, 0xff, 0x33, 0x9c, 0xef, 0xff, 0xff, 0x63,
    0x19, 0xc6, 0x71, 0x9c, 0xe7, 0x39, 0x8e, 0x60,

    /* U+0024 "$" */
    0x8, 0x2, 0x0, 0x80, 0xf8, 0x7f, 0xb8, 0xee,
    0x1b, 0x87, 0xe0, 0x3c, 0x7, 0x80, 0xf0, 0x1f,
    0x3, 0xc0, 0x78, 0xf, 0xe1, 0xf8, 0x7e, 0x1d,
    0xcf, 0x7f, 0x8f, 0xc0, 0x40, 0x10,

    /* U+0025 "%" */
    0x3c, 0x1c, 0x7, 0xe1, 0xc0, 0xe7, 0x18, 0xe,
    0x73, 0x80, 0xe7, 0x38, 0xe, 0x73, 0x0, 0xe7,
    0x30, 0xe, 0x77, 0x0, 0x7e, 0x70, 0x3, 0xc6,
    0x3c, 0x0, 0xe7, 0xe0, 0xe, 0xe7, 0x0, 0xce,
    0x70, 0xc, 0xe7, 0x1, 0xce, 0x70, 0x1c, 0xe7,
    0x1, 0x8e, 0x70, 0x18, 0x7e, 0x3, 0x83, 0xc0,

    /* U+0026 "&" */
    0x3e, 0x7, 0xf0, 0xf3, 0x8e, 0x38, 0xe3, 0x8e,
    0x38, 0x67, 0x7, 0x60, 0x3c, 0x1, 0x80, 0x38,
    0x7, 0xc7, 0x6e, 0x7e, 0x76, 0xe7, 0xee, 0x3c,
    0xe3, 0xe7, 0xf7, 0x3e, 0x30,

    /* U+0027 "'" */
    0xff, 0xe0,

    /* U+0028 "(" */
    0x19, 0xdc, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xce, 0x31, 0xc7, 0x18,

    /* U+0029 ")" */
    0xc7, 0x1c, 0xe3, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x39, 0xce, 0x73, 0xb9, 0xdc, 0xc0,

    /* U+002A "*" */
    0x18, 0x18, 0xdb, 0xff, 0x18, 0x3c, 0x26, 0x66,

    /* U+002B "+" */
    0x18, 0xc, 0x6, 0x1f, 0xff, 0xf8, 0xc0, 0x60,
    0x30, 0x18, 0x0,

    /* U+002C "," */
    0xff, 0xb7, 0x80,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x6, 0x1c, 0x30, 0x60, 0xc3, 0x86, 0xc, 0x18,
    0x70, 0xc1, 0x87, 0xc, 0x18, 0x30, 0xe1, 0x83,
    0x0,

    /* U+0030 "0" */
    0x3f, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe1, 0xe0,

    /* U+0031 "1" */
    0xe, 0x7f, 0xff, 0x70, 0xe1, 0xc3, 0x87, 0xe,
    0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe, 0x1c,
    0x38,

    /* U+0032 "2" */
    0x3f, 0x1f, 0xe7, 0x3f, 0x87, 0xe1, 0xf8, 0x70,
    0x1c, 0xf, 0x3, 0x81, 0xc0, 0xf0, 0x38, 0x1c,
    0xf, 0x3, 0x81, 0xc0, 0x70, 0x3f, 0xef, 0xf8,

    /* U+0033 "3" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xc0, 0x70,
    0x38, 0x3c, 0xf, 0x0, 0xe0, 0x1c, 0x7, 0x1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe1, 0xf0,

    /* U+0034 "4" */
    0x7, 0x80, 0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x37,
    0x6, 0xe1, 0x9c, 0x33, 0x8e, 0x71, 0x8e, 0x31,
    0xcf, 0xff, 0xff, 0xc0, 0xe0, 0x1c, 0x3, 0x80,
    0x70, 0xe, 0x0,

    /* U+0035 "5" */
    0x7f, 0x9f, 0xe6, 0x1, 0x80, 0x60, 0x18, 0x6,
    0xf1, 0xfe, 0x73, 0xd8, 0x70, 0x1c, 0x7, 0x1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe3, 0xe0,

    /* U+0036 "6" */
    0x1f, 0x1f, 0xe7, 0x3f, 0x87, 0xe1, 0xf8, 0xe,
    0x3, 0xbc, 0xff, 0xbc, 0xfe, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe1, 0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0x7, 0x7, 0x6, 0x6, 0xe, 0xe,
    0xc, 0xc, 0xc, 0x1c, 0x1c, 0x18, 0x18, 0x38,
    0x38, 0x38, 0x30,

    /* U+0038 "8" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1d, 0xce, 0x3f, 0xf, 0xc7, 0x3b, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe3, 0xf0,

    /* U+0039 "9" */
    0x1e, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xf3, 0xdf, 0xf3, 0xdc, 0x7, 0x1,
    0xc0, 0x7e, 0x1f, 0x87, 0xf3, 0x9f, 0xe3, 0xe0,

    /* U+003A ":" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003B ";" */
    0xff, 0x80, 0x0, 0x3, 0xf6, 0xf0,

    /* U+003C "<" */
    0x2, 0x1c, 0xff, 0xce, 0x1c, 0x3e, 0x1f, 0xe,
    0x4,

    /* U+003D "=" */
    0xff, 0xfc, 0x0, 0xf, 0xff, 0xc0,

    /* U+003E ">" */
    0x81, 0xc3, 0xe1, 0xf0, 0xe1, 0xcf, 0xfc, 0xe1,
    0x0,

    /* U+003F "?" */
    0x3e, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xe0, 0x70,
    0x1c, 0xe, 0x3, 0x81, 0xc0, 0xe0, 0x70, 0x18,
    0x6, 0x1, 0x80, 0x0, 0x0, 0x6, 0x1, 0x80,

    /* U+0040 "@" */
    0x1, 0xfc, 0x0, 0xff, 0xe0, 0x3c, 0x1e, 0xe,
    0x0, 0xc3, 0x80, 0xc, 0xf0, 0xf9, 0x9c, 0x7f,
    0x1b, 0x8e, 0x63, 0xf3, 0x8c, 0x7c, 0x71, 0x8f,
    0x9c, 0x71, 0xf3, 0x8c, 0x3e, 0x71, 0x8f, 0xce,
    0x31, 0xb9, 0xce, 0x77, 0x1f, 0xfc, 0xf1, 0xce,
    0xe, 0x0, 0x1, 0xe0, 0x0, 0x1e, 0x0, 0x1,
    0xe0, 0x40, 0x1f, 0xf8, 0x0, 0xff, 0x0,

    /* U+0041 "A" */
    0xe, 0x1, 0xe0, 0x3c, 0x7, 0x80, 0xf0, 0x3e,
    0x6, 0xe0, 0xcc, 0x19, 0x83, 0x30, 0xe7, 0x18,
    0xe3, 0xfc, 0x7f, 0x9c, 0x33, 0x87, 0x60, 0xec,
    0xd, 0x81, 0x80,

    /* U+0042 "B" */
    0xff, 0x3f, 0xee, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x8e, 0xff, 0x3f, 0xce, 0x3b, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0xe3, 0xbf, 0xef, 0xf0,

    /* U+0043 "C" */
    0x3f, 0x1f, 0xe7, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x80, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0x9f, 0xe1, 0xf0,

    /* U+0044 "D" */
    0xfe, 0x3f, 0xee, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0xe3, 0xbf, 0xef, 0xe0,

    /* U+0045 "E" */
    0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xfe, 0xfe, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xff, 0xff,

    /* U+0046 "F" */
    0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xfe, 0xfe, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe0, 0xe0,

    /* U+0047 "G" */
    0x3f, 0x1f, 0xe7, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x3, 0x80, 0xe0, 0x39, 0xfe, 0x7f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0xdf, 0xb3, 0xcc,

    /* U+0048 "H" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xff, 0xff, 0xff, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0xe0, 0xfc,
    0x1f, 0x83, 0x80,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+004A "J" */
    0x1c, 0x71, 0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0xc7, 0x3f, 0xef, 0x0,

    /* U+004B "K" */
    0xe1, 0xdc, 0x33, 0x8e, 0x71, 0x8e, 0x71, 0xcc,
    0x3b, 0x87, 0x70, 0xfc, 0x1f, 0xc3, 0xf8, 0x73,
    0xe, 0x71, 0xc6, 0x38, 0xe7, 0xc, 0xe1, 0xdc,
    0x3b, 0x83, 0x0,

    /* U+004C "L" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xff, 0xff,

    /* U+004D "M" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xe0, 0xff, 0x7,
    0xf8, 0x3f, 0xc1, 0xfb, 0x1b, 0xd8, 0xde, 0xc6,
    0xf6, 0x37, 0x9b, 0x3c, 0xd9, 0xe6, 0xcf, 0x36,
    0x78, 0xe3, 0xc7, 0x1e, 0x38, 0xf0, 0x86,

    /* U+004E "N" */
    0xe1, 0xf8, 0x7e, 0x1f, 0xc7, 0xf1, 0xfc, 0x7f,
    0x9f, 0xa7, 0xed, 0xfb, 0x7e, 0x5f, 0x9f, 0xe7,
    0xf8, 0xfe, 0x3f, 0x8f, 0xe1, 0xf8, 0x7e, 0xc,

    /* U+004F "O" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0x71, 0xcf,
    0xf8, 0x7c, 0x0,

    /* U+0050 "P" */
    0xff, 0x3f, 0xee, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x8f, 0xff, 0xbf, 0xce, 0x3, 0x80, 0xe0,
    0x38, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xe, 0x0,

    /* U+0051 "Q" */
    0x1f, 0xf, 0xf9, 0xc7, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0x71, 0xcf,
    0xf8, 0x7c, 0x1, 0xc0, 0x1c, 0x1, 0x80, 0x10,

    /* U+0052 "R" */
    0xfe, 0x3f, 0xee, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x8f, 0xff, 0xbf, 0x8e, 0x73, 0x9c, 0xe3,
    0x38, 0xee, 0x3b, 0x8e, 0xe1, 0xf8, 0x7e, 0x1c,

    /* U+0053 "S" */
    0x3e, 0x1f, 0xcf, 0x3b, 0x86, 0xe1, 0xf8, 0xf,
    0x1, 0xe0, 0x3c, 0x7, 0xc0, 0xf0, 0x1e, 0x3,
    0xf8, 0x7e, 0x1f, 0x87, 0x73, 0xdf, 0xe1, 0xf0,

    /* U+0054 "T" */
    0xff, 0xff, 0xc7, 0x3, 0x81, 0xc0, 0xe0, 0x70,
    0x38, 0x1c, 0xe, 0x7, 0x3, 0x81, 0xc0, 0xe0,
    0x70, 0x38, 0x1c, 0xe, 0x7, 0x0,

    /* U+0055 "U" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x3f, 0x7, 0x71, 0xcf,
    0xf8, 0x7c, 0x0,

    /* U+0056 "V" */
    0xc0, 0xd8, 0x1b, 0x83, 0x70, 0xe6, 0x1c, 0xc3,
    0x1c, 0x63, 0x8c, 0x73, 0x86, 0x60, 0xcc, 0x1d,
    0x83, 0xf0, 0x3e, 0x7, 0x80, 0xf0, 0x1e, 0x1,
    0xc0, 0x30, 0x0,

    /* U+0057 "W" */
    0xc1, 0x87, 0xc1, 0x86, 0xe3, 0x86, 0xe3, 0x86,
    0x63, 0xc6, 0x63, 0xc6, 0x63, 0xce, 0x66, 0xcc,
    0x66, 0x4c, 0x76, 0x6c, 0x36, 0x6c, 0x36, 0x6c,
    0x3c, 0x6c, 0x3c, 0x78, 0x3c, 0x38, 0x3c, 0x38,
    0x1c, 0x38, 0x18, 0x38, 0x18, 0x38,

    /* U+0058 "X" */
    0x60, 0xee, 0x19, 0xc3, 0x18, 0xe3, 0x98, 0x37,
    0x7, 0xc0, 0x78, 0xe, 0x1, 0xc0, 0x3c, 0xf,
    0x81, 0xb0, 0x37, 0xe, 0x61, 0x8e, 0x70, 0xcc,
    0x1d, 0x81, 0x80,

    /* U+0059 "Y" */
    0xe0, 0xfc, 0x1d, 0x83, 0x38, 0xe7, 0x1c, 0x63,
    0xe, 0xe1, 0xdc, 0x1b, 0x3, 0xe0, 0x7c, 0x7,
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x38, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0x7, 0x6, 0xe, 0xc, 0xc, 0x1c,
    0x18, 0x18, 0x38, 0x30, 0x30, 0x60, 0x60, 0x60,
    0xc0, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xfe, 0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0x38, 0xe3,
    0xff, 0xc0,

    /* U+005C "\\" */
    0xc1, 0x83, 0x83, 0x6, 0xc, 0x1c, 0x18, 0x30,
    0x70, 0x60, 0xc1, 0x83, 0x83, 0x6, 0xc, 0xc,
    0x18,

    /* U+005D "]" */
    0xff, 0xf1, 0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71, 0xc7, 0x1f,
    0xff, 0xc0,

    /* U+005E "^" */
    0x1c, 0xe, 0xf, 0x6, 0xc7, 0x63, 0x3b, 0x8d,
    0x87,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0xe6, 0x33, 0x10,

    /* U+0061 "a" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0x7, 0x1f, 0x77,
    0x67, 0xe7, 0xe7, 0xe7, 0xff, 0x77,

    /* U+0062 "b" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x73, 0xfd,
    0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f,
    0x8f, 0xc7, 0xe3, 0xff, 0xbb, 0x80,

    /* U+0063 "c" */
    0x3e, 0x7e, 0xe7, 0xe7, 0xe7, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0064 "d" */
    0x7, 0x7, 0x7, 0x7, 0x7, 0x77, 0x7f, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0x7f, 0x77,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xff, 0xff, 0xe0,
    0xe0, 0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0066 "f" */
    0x3d, 0xf7, 0x1c, 0x73, 0xff, 0xdc, 0x71, 0xc7,
    0x1c, 0x71, 0xc7, 0x1c, 0x71, 0xc7, 0x0,

    /* U+0067 "g" */
    0x1e, 0xcf, 0xf7, 0x39, 0xce, 0x73, 0x9c, 0xe7,
    0x39, 0xce, 0x3f, 0xf, 0x86, 0x1, 0xf0, 0x7f,
    0x1c, 0xec, 0x1b, 0x6, 0xff, 0x9f, 0x80,

    /* U+0068 "h" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xee, 0xff, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7,

    /* U+0069 "i" */
    0xfc, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+006A "j" */
    0x39, 0xc0, 0x0, 0x1c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x39, 0xce, 0x7f, 0xf8,

    /* U+006B "k" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x1f, 0x8f,
    0xce, 0xe6, 0x77, 0x3f, 0x1f, 0xcf, 0xe7, 0x33,
    0x9d, 0xc6, 0xe3, 0x71, 0xf8, 0x60,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+006D "m" */
    0xee, 0x77, 0xff, 0xf9, 0xcf, 0xce, 0x7e, 0x73,
    0xf3, 0x9f, 0x9c, 0xfc, 0xe7, 0xe7, 0x3f, 0x39,
    0xf9, 0xcf, 0xce, 0x7e, 0x73, 0xf3, 0x9c,

    /* U+006E "n" */
    0xee, 0xff, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,

    /* U+006F "o" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0070 "p" */
    0xee, 0x7f, 0xb8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0x7f, 0xf7, 0x73,
    0x81, 0xc0, 0xe0, 0x70, 0x0,

    /* U+0071 "q" */
    0x77, 0x7f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0x7f, 0x77, 0x7, 0x7,
    0x7, 0x7,

    /* U+0072 "r" */
    0xef, 0xff, 0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x38, 0xe3, 0x80,

    /* U+0073 "s" */
    0x79, 0xfb, 0x9f, 0x3e, 0xe, 0xe, 0xe, 0xe,
    0xf, 0x9f, 0x3f, 0xef, 0x0,

    /* U+0074 "t" */
    0x71, 0xc7, 0x1c, 0xff, 0xf7, 0x1c, 0x71, 0xc7,
    0x1c, 0x71, 0xc7, 0x1c, 0x7c, 0xf0,

    /* U+0075 "u" */
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xff, 0x77,

    /* U+0076 "v" */
    0xe3, 0xb1, 0xd8, 0xcc, 0x67, 0x33, 0x98, 0xdc,
    0x6c, 0x36, 0x1b, 0xf, 0x83, 0xc1, 0xe0, 0xe0,

    /* U+0077 "w" */
    0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0xf3, 0xcf, 0x36,
    0xf3, 0x6d, 0x66, 0x96, 0x69, 0xe7, 0x9e, 0x79,
    0xe3, 0x9e, 0x30, 0xc3, 0xc,

    /* U+0078 "x" */
    0x63, 0xb1, 0x9c, 0xc6, 0xe3, 0xe0, 0xf0, 0x70,
    0x38, 0x1e, 0x1b, 0xd, 0xce, 0x66, 0x37, 0x1c,

    /* U+0079 "y" */
    0xe3, 0xb1, 0xd8, 0xcc, 0x67, 0x31, 0xb8, 0xdc,
    0x6c, 0x36, 0xf, 0x7, 0x83, 0x81, 0xc0, 0xe0,
    0x70, 0xf0, 0x70, 0x0,

    /* U+007A "z" */
    0xff, 0xfc, 0x38, 0xe1, 0xc3, 0xe, 0x18, 0x70,
    0xe1, 0x87, 0xf, 0xff, 0xc0,

    /* U+007B "{" */
    0x1e, 0x7c, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38,
    0x70, 0xe7, 0x8f, 0x7, 0xe, 0x1c, 0x38, 0x70,
    0xe1, 0xc3, 0x87, 0xf, 0x8f,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8,

    /* U+007D "}" */
    0xf3, 0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0x38, 0xe3,
    0x87, 0x1c, 0xe3, 0x8e, 0x38, 0xe3, 0x8e, 0x38,
    0xef, 0xbc,

    /* U+007E "~" */
    0x78, 0x7f, 0xc3, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 88, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 80, .box_w = 3, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 102, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 13},
    {.bitmap_index = 14, .adv_w = 187, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 189, .box_w = 10, .box_h = 24, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 68, .adv_w = 342, .box_w = 20, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 233, .box_w = 12, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 49, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = 13},
    {.bitmap_index = 147, .adv_w = 114, .box_w = 5, .box_h = 25, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 163, .adv_w = 100, .box_w = 5, .box_h = 25, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 179, .adv_w = 153, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 187, .adv_w = 159, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 198, .adv_w = 72, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 201, .adv_w = 116, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 203, .adv_w = 72, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 142, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 199, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 145, .box_w = 7, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 184, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 183, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 185, .box_w = 11, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 183, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 193, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 148, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 192, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 193, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 76, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 457, .adv_w = 83, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 463, .adv_w = 143, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 472, .adv_w = 159, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 478, .adv_w = 143, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 487, .adv_w = 185, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 347, .box_w = 19, .box_h = 23, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 566, .adv_w = 189, .box_w = 11, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 201, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 198, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 202, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 156, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 150, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 205, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 215, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 754, .adv_w = 95, .box_w = 3, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 116, .box_w = 6, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 190, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 804, .adv_w = 152, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 823, .adv_w = 253, .box_w = 13, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 203, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 207, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 184, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 208, .box_w = 11, .box_h = 23, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 961, .adv_w = 199, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 985, .adv_w = 182, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 159, .box_w = 9, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 209, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1058, .adv_w = 194, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1085, .adv_w = 280, .box_w = 16, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1123, .adv_w = 185, .box_w = 11, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1150, .adv_w = 185, .box_w = 11, .box_h = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1177, .adv_w = 160, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1196, .adv_w = 131, .box_w = 6, .box_h = 23, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1214, .adv_w = 142, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1231, .adv_w = 119, .box_w = 6, .box_h = 23, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1249, .adv_w = 170, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 12},
    {.bitmap_index = 1258, .adv_w = 132, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1260, .adv_w = 107, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 15},
    {.bitmap_index = 1263, .adv_w = 157, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1277, .adv_w = 172, .box_w = 9, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1299, .adv_w = 158, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1313, .adv_w = 170, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1332, .adv_w = 162, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1346, .adv_w = 110, .box_w = 6, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1361, .adv_w = 169, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1384, .adv_w = 171, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1403, .adv_w = 88, .box_w = 3, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1411, .adv_w = 88, .box_w = 5, .box_h = 22, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1425, .adv_w = 165, .box_w = 9, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1447, .adv_w = 88, .box_w = 3, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1455, .adv_w = 261, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1478, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1492, .adv_w = 163, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1506, .adv_w = 171, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1527, .adv_w = 170, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1545, .adv_w = 123, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1556, .adv_w = 144, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1569, .adv_w = 118, .box_w = 6, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1583, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1597, .adv_w = 148, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1613, .adv_w = 226, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1634, .adv_w = 149, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1650, .adv_w = 151, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1670, .adv_w = 133, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1683, .adv_w = 115, .box_w = 7, .box_h = 24, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1704, .adv_w = 92, .box_w = 3, .box_h = 23, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1713, .adv_w = 123, .box_w = 6, .box_h = 24, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1731, .adv_w = 172, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 8}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 34,
    3, 36,
    3, 40,
    3, 43,
    3, 48,
    3, 50,
    3, 66,
    3, 68,
    3, 69,
    3, 70,
    3, 72,
    3, 80,
    3, 82,
    3, 84,
    7, 53,
    8, 34,
    8, 36,
    8, 40,
    8, 43,
    8, 48,
    8, 50,
    8, 66,
    8, 68,
    8, 69,
    8, 70,
    8, 72,
    8, 80,
    8, 82,
    8, 84,
    11, 43,
    11, 57,
    13, 35,
    13, 36,
    13, 37,
    13, 38,
    13, 39,
    13, 40,
    13, 41,
    13, 42,
    13, 44,
    13, 45,
    13, 47,
    13, 48,
    13, 49,
    13, 50,
    13, 51,
    13, 53,
    13, 54,
    13, 55,
    13, 56,
    13, 58,
    13, 68,
    13, 69,
    13, 70,
    13, 80,
    13, 82,
    13, 85,
    13, 87,
    13, 88,
    13, 90,
    14, 53,
    14, 55,
    14, 56,
    14, 57,
    14, 58,
    15, 35,
    15, 36,
    15, 37,
    15, 38,
    15, 39,
    15, 40,
    15, 41,
    15, 42,
    15, 44,
    15, 45,
    15, 47,
    15, 48,
    15, 49,
    15, 50,
    15, 51,
    15, 53,
    15, 54,
    15, 55,
    15, 56,
    15, 58,
    15, 68,
    15, 69,
    15, 70,
    15, 80,
    15, 82,
    15, 85,
    15, 87,
    15, 88,
    15, 90,
    16, 36,
    16, 40,
    16, 48,
    16, 50,
    16, 52,
    16, 68,
    16, 69,
    16, 70,
    16, 80,
    16, 82,
    17, 24,
    17, 57,
    17, 58,
    18, 24,
    19, 21,
    21, 18,
    21, 24,
    22, 24,
    23, 18,
    23, 19,
    23, 24,
    23, 26,
    23, 58,
    24, 21,
    25, 24,
    25, 58,
    26, 24,
    27, 53,
    27, 55,
    27, 56,
    27, 58,
    28, 53,
    28, 55,
    28, 56,
    28, 58,
    34, 3,
    34, 8,
    34, 36,
    34, 40,
    34, 48,
    34, 52,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    34, 71,
    34, 85,
    34, 87,
    34, 88,
    34, 90,
    35, 3,
    35, 8,
    35, 13,
    35, 15,
    35, 34,
    35, 53,
    35, 55,
    35, 56,
    35, 57,
    35, 58,
    36, 3,
    36, 8,
    36, 13,
    36, 15,
    36, 57,
    36, 58,
    37, 3,
    37, 8,
    37, 13,
    37, 15,
    37, 24,
    37, 34,
    37, 43,
    37, 53,
    37, 55,
    37, 57,
    37, 58,
    37, 59,
    37, 61,
    38, 68,
    38, 69,
    38, 70,
    38, 72,
    38, 80,
    38, 82,
    38, 84,
    39, 3,
    39, 8,
    39, 13,
    39, 15,
    39, 27,
    39, 28,
    39, 34,
    39, 43,
    39, 52,
    39, 66,
    39, 68,
    39, 69,
    39, 70,
    39, 72,
    39, 80,
    39, 82,
    39, 84,
    39, 89,
    39, 90,
    39, 91,
    40, 3,
    40, 8,
    40, 53,
    40, 55,
    40, 56,
    40, 58,
    43, 13,
    43, 15,
    44, 14,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    44, 52,
    44, 54,
    44, 66,
    44, 68,
    44, 69,
    44, 70,
    44, 72,
    44, 80,
    44, 82,
    44, 84,
    44, 85,
    44, 86,
    44, 87,
    44, 88,
    44, 90,
    45, 3,
    45, 8,
    45, 11,
    45, 14,
    45, 18,
    45, 24,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 52,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 61,
    45, 68,
    45, 69,
    45, 70,
    45, 71,
    45, 72,
    45, 80,
    45, 82,
    45, 84,
    45, 85,
    45, 88,
    45, 90,
    46, 52,
    46, 53,
    46, 55,
    46, 58,
    48, 3,
    48, 8,
    48, 13,
    48, 15,
    48, 24,
    48, 34,
    48, 43,
    48, 53,
    48, 55,
    48, 57,
    48, 58,
    48, 59,
    48, 61,
    49, 13,
    49, 14,
    49, 15,
    49, 16,
    49, 21,
    49, 24,
    49, 34,
    49, 43,
    49, 52,
    49, 57,
    49, 59,
    49, 61,
    49, 66,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 78,
    49, 79,
    49, 80,
    49, 82,
    49, 83,
    49, 84,
    49, 91,
    50, 3,
    50, 8,
    50, 13,
    50, 15,
    50, 24,
    50, 34,
    50, 43,
    50, 53,
    50, 55,
    50, 57,
    50, 58,
    50, 59,
    50, 61,
    51, 36,
    51, 40,
    51, 48,
    51, 50,
    51, 52,
    51, 53,
    51, 54,
    51, 55,
    51, 56,
    51, 58,
    51, 61,
    51, 66,
    51, 68,
    51, 69,
    51, 70,
    51, 80,
    51, 82,
    51, 88,
    51, 90,
    51, 91,
    52, 16,
    52, 34,
    52, 46,
    52, 52,
    52, 55,
    52, 57,
    52, 58,
    52, 61,
    53, 7,
    53, 13,
    53, 14,
    53, 15,
    53, 16,
    53, 27,
    53, 28,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 46,
    53, 48,
    53, 50,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 71,
    53, 72,
    53, 75,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 85,
    53, 86,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    54, 13,
    54, 15,
    54, 16,
    54, 34,
    55, 13,
    55, 14,
    55, 15,
    55, 16,
    55, 27,
    55, 28,
    55, 34,
    55, 36,
    55, 40,
    55, 43,
    55, 46,
    55, 48,
    55, 50,
    55, 52,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 78,
    55, 79,
    55, 80,
    55, 81,
    55, 82,
    55, 83,
    55, 84,
    55, 85,
    55, 86,
    55, 87,
    55, 88,
    55, 89,
    55, 90,
    55, 91,
    56, 13,
    56, 14,
    56, 15,
    56, 16,
    56, 27,
    56, 28,
    56, 34,
    56, 36,
    56, 40,
    56, 48,
    56, 50,
    56, 52,
    56, 61,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 71,
    56, 72,
    56, 78,
    56, 79,
    56, 80,
    56, 81,
    56, 82,
    56, 83,
    56, 84,
    56, 87,
    56, 88,
    56, 89,
    56, 91,
    57, 11,
    57, 14,
    57, 17,
    57, 36,
    57, 40,
    57, 48,
    57, 50,
    57, 52,
    57, 61,
    57, 66,
    57, 68,
    57, 69,
    57, 70,
    57, 71,
    57, 72,
    57, 80,
    57, 82,
    57, 84,
    57, 85,
    57, 87,
    57, 88,
    57, 90,
    58, 13,
    58, 14,
    58, 15,
    58, 16,
    58, 17,
    58, 21,
    58, 23,
    58, 25,
    58, 27,
    58, 28,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 46,
    58, 48,
    58, 50,
    58, 52,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 86,
    58, 88,
    58, 89,
    58, 90,
    58, 91,
    59, 36,
    59, 40,
    59, 48,
    59, 50,
    59, 52,
    59, 66,
    59, 68,
    59, 69,
    59, 70,
    59, 80,
    59, 82,
    61, 36,
    61, 40,
    61, 48,
    61, 50,
    61, 52,
    61, 53,
    61, 54,
    61, 55,
    61, 56,
    61, 58,
    66, 3,
    66, 8,
    66, 53,
    66, 55,
    66, 56,
    66, 58,
    66, 85,
    66, 87,
    66, 88,
    66, 90,
    67, 3,
    67, 8,
    67, 13,
    67, 15,
    67, 53,
    67, 55,
    67, 56,
    67, 58,
    67, 72,
    67, 75,
    67, 88,
    67, 89,
    68, 3,
    68, 8,
    68, 13,
    68, 15,
    68, 53,
    68, 56,
    68, 58,
    68, 68,
    68, 69,
    68, 70,
    68, 75,
    68, 80,
    68, 82,
    69, 53,
    69, 55,
    69, 56,
    69, 58,
    70, 3,
    70, 8,
    70, 53,
    70, 55,
    70, 56,
    70, 58,
    70, 75,
    70, 88,
    70, 89,
    71, 15,
    71, 27,
    71, 28,
    71, 34,
    71, 66,
    71, 68,
    71, 69,
    71, 70,
    71, 71,
    71, 74,
    71, 75,
    71, 80,
    71, 82,
    71, 86,
    72, 53,
    72, 55,
    72, 57,
    72, 58,
    72, 59,
    72, 68,
    72, 69,
    72, 70,
    72, 72,
    72, 75,
    72, 80,
    72, 82,
    72, 85,
    72, 86,
    72, 88,
    72, 90,
    73, 3,
    73, 8,
    73, 53,
    73, 55,
    73, 56,
    73, 58,
    76, 3,
    76, 8,
    76, 53,
    76, 56,
    76, 58,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 80,
    76, 82,
    76, 84,
    78, 3,
    78, 8,
    78, 53,
    78, 55,
    78, 56,
    78, 58,
    79, 3,
    79, 8,
    79, 53,
    79, 55,
    79, 56,
    79, 58,
    80, 3,
    80, 8,
    80, 13,
    80, 15,
    80, 53,
    80, 55,
    80, 56,
    80, 58,
    80, 72,
    80, 75,
    80, 88,
    80, 89,
    81, 3,
    81, 8,
    81, 13,
    81, 15,
    81, 53,
    81, 55,
    81, 56,
    81, 58,
    81, 72,
    81, 75,
    81, 88,
    81, 89,
    82, 3,
    82, 8,
    82, 53,
    82, 55,
    82, 58,
    83, 13,
    83, 15,
    83, 34,
    83, 43,
    83, 53,
    83, 57,
    83, 58,
    83, 59,
    83, 66,
    83, 68,
    83, 69,
    83, 70,
    83, 72,
    83, 80,
    83, 82,
    84, 3,
    84, 8,
    84, 53,
    84, 55,
    84, 56,
    84, 57,
    84, 58,
    85, 3,
    85, 8,
    85, 52,
    85, 53,
    85, 55,
    85, 58,
    85, 72,
    86, 3,
    86, 8,
    86, 53,
    86, 55,
    86, 56,
    86, 58,
    87, 13,
    87, 15,
    87, 34,
    87, 43,
    87, 53,
    87, 55,
    87, 56,
    87, 57,
    87, 58,
    87, 59,
    87, 66,
    87, 72,
    88, 13,
    88, 15,
    88, 34,
    88, 43,
    88, 53,
    88, 55,
    88, 56,
    88, 57,
    88, 58,
    88, 59,
    88, 66,
    88, 72,
    89, 53,
    89, 55,
    89, 56,
    89, 58,
    89, 68,
    89, 69,
    89, 70,
    89, 80,
    89, 82,
    90, 13,
    90, 15,
    90, 34,
    90, 43,
    90, 53,
    90, 55,
    90, 56,
    90, 57,
    90, 58,
    90, 59,
    90, 66,
    90, 72,
    91, 53,
    91, 55,
    91, 56,
    91, 58,
    91, 68,
    91, 69,
    91, 70,
    91, 72,
    91, 80,
    91, 82
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -24, -3, -3, -13, -3, -3, -5, -9,
    -9, -9, -13, -9, -9, -5, -5, -24,
    -3, -3, -13, -3, -3, -5, -9, -9,
    -9, -13, -9, -9, -5, -4, -3, -1,
    -3, -1, -1, -1, -3, -1, -1, -1,
    -1, -1, -3, -1, -3, -1, -20, -3,
    -17, -14, -25, -3, -3, -3, -3, -3,
    -4, -6, -3, -4, -7, -10, -1, -3,
    -7, -1, -3, -1, -1, -1, -3, -1,
    -1, -1, -1, -1, -3, -1, -3, -1,
    -20, -3, -17, -14, -25, -3, -3, -3,
    -3, -3, -4, -6, -3, -4, -3, -3,
    -3, -3, -4, -8, -8, -8, -8, -8,
    -4, -1, -3, -5, -3, -3, -7, -3,
    -1, -1, -4, -2, -1, -13, -6, -1,
    -5, -24, -3, -4, -17, -24, -3, -4,
    -17, -24, -24, -2, -2, -2, -1, -16,
    -1, -15, -10, -15, -6, -4, -3, -6,
    -5, -6, -6, -3, -3, 0, -9, -10,
    -1, -8, -3, -3, -3, -1, -1, -1,
    -1, -4, -4, -3, -3, -1, -2, -1,
    -1, -1, -3, -3, -1, -5, -2, -2,
    -2, -2, -2, -2, -2, -1, -1, -24,
    -24, -5, -5, -14, -12, -1, -7, -5,
    -5, -5, -3, -5, -5, -6, -4, -4,
    -5, -4, -4, -5, -3, 0, -5, -10,
    -10, -4, -7, -7, -7, -4, -3, 0,
    -2, -5, -5, -5, -2, -5, -5, -2,
    -3, -1, -1, -5, -10, -11, -11, -17,
    -7, -5, -1, -2, -2, -2, -3, -1,
    -30, -3, -28, -19, -34, -13, -1, -1,
    -1, -5, -1, -1, -1, -1, -4, -13,
    -18, -2, -3, -1, -1, -4, -4, -3,
    -3, -1, -2, -1, -1, -1, -3, -3,
    -1, -5, -40, -33, -43, -20, -10, -1,
    -17, -8, -1, -4, -10, -4, -10, -8,
    -8, -8, -7, -3, -3, -8, 0, -3,
    -4, -3, -4, -4, -3, -3, -1, -2,
    -1, -1, -1, -3, -3, -1, -5, -1,
    -1, -1, -1, -1, -5, -1, -1, -2,
    -6, -4, -4, -3, -3, -3, -3, -3,
    -3, -1, -3, -3, -1, -1, -3, -1,
    -1, -1, -5, -1, -20, -7, -20, -8,
    -24, -24, -16, -1, -1, -9, -3, -1,
    -1, -25, -24, -24, -24, -13, -25, -5,
    -22, -22, -24, -22, 0, -22, -25, -7,
    -18, -24, -19, -23, -20, -3, -3, -4,
    -1, -18, -10, -18, -3, -4, -4, -15,
    -2, -2, -8, -1, -2, -2, -1, -23,
    -15, -15, -15, -19, -8, -8, -15, -12,
    -13, -8, -15, -4, -11, -8, -8, -8,
    -12, -16, -14, -1, -14, -5, -4, -4,
    -10, 0, 0, 0, 0, -1, -3, -15,
    -11, -11, -11, -1, -9, -5, -5, -11,
    -4, 0, -5, -5, -4, -4, -4, -3,
    -4, -3, -1, -3, -3, -3, -3, -2,
    -3, -4, -4, -4, -4, -8, -4, -4,
    -4, -8, -8, -8, -12, -12, -25, -7,
    -25, -7, -3, -4, -1, -1, -18, -18,
    -15, -3, -3, -8, -1, -3, -3, -1,
    -27, -23, -23, -23, -10, -22, -18, -18,
    -23, -16, -6, -18, -18, -17, -13, -15,
    -12, -10, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -3, -3, -3,
    -3, -4, -8, -4, -8, -7, -8, -10,
    -10, -22, -18, -12, -26, 0, -1, -2,
    -1, -9, -9, -3, -3, -24, -15, -10,
    -23, 0, -1, 0, -5, -7, -7, 0,
    0, -18, -1, -16, -2, -2, -2, -1,
    -2, -2, 12, 4, 4, 8, -3, -3,
    -24, -12, -3, -21, -1, 0, -3, -5,
    -1, -1, -1, -4, -8, -8, -8, -13,
    -3, -3, -8, -8, -4, -14, -4, -8,
    -4, -3, -2, -2, -2, -4, 4, -2,
    -2, 1, 0, 1, 2, -12, -12, -22,
    -11, -5, -18, -3, -3, -13, -1, -10,
    -2, -2, -2, -1, -2, -2, -1, -12,
    -12, -22, -11, -5, -18, -12, -12, -22,
    -11, -5, -18, -9, -9, -3, -3, -24,
    -15, -10, -23, 0, -1, 0, -5, -9,
    -9, -3, -3, -24, -15, -10, -23, 0,
    -1, 0, -5, -3, -3, -19, -9, -13,
    -28, -28, -11, -4, -20, -8, -7, -8,
    -3, -1, -1, -1, -2, -1, -4, -5,
    -5, -23, -15, -3, -4, -22, -5, -5,
    -1, -10, -4, -4, -1, -4, -4, -21,
    -8, -1, -17, -7, -7, -7, -4, -27,
    -8, -4, -8, -13, -8, -2, -2, -6,
    -7, -5, -12, -24, -8, -4, -12, -13,
    -3, -2, -1, -19, -8, -4, -15, -5,
    -5, -5, -5, -5, -11, -11, -7, -4,
    -27, -8, -4, -8, -13, -8, -2, -2,
    -20, -5, -3, -10, -3, -3, -3, -1,
    -3, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 746,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Oswald_Regular_24 = {
#else
lv_font_t ui_font_Oswald_Regular_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 28,          /*The maximum line height required by the font*/
    .base_line = 6,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_OSWALD_REGULAR_24*/

