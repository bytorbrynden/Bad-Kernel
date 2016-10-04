//
// Bad_Kernel
// Source/IO/VGATextMode/VGATextModeEntry.c
//
#include "IO/VGATextMode/VGATextModeEntry.h"

VGATextModeEntry vga_textmode_entry_create
(
    VGATextModeEntryChar character,
    VGATextModeColor     color
)
{
    // A character in a textmode buffer is represented by two bytes, organized
    //  as follows:
    // |               2               |               1               |
    // | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
    // | B |    BG     |      FG       |             CHAR              |
    //
    // ('B' for "Blink", "BG" for "Background", "FG" for "Foreground")
    return character | (uint16_t) color << 8;
}