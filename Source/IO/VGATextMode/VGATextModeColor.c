//
// Bad_Kernel
// Source/IO/VGATextMode/VGATextModeColor.c
//
#include "IO/VGATextMode/VGATextModeColor.h"

VGATextModeColor vga_textmode_color_create
(
    int foreground,
    int background
)
{
    // A character in a textmode buffer is represented by two bytes, the color
    //  of the character, is represented by 8 bits, organized as follows:
    //
    // | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
    // | B |    BG     |      FG       |
    //
    // ('B' for "Blink", "BG" for "Background", "FG" for "Foreground")
    return foreground | background << 0x4;
}