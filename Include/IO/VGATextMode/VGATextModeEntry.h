//
// Bad_Kernel
// Include/IO/VGATextMode/VGATextModeEntry.h
//
#ifndef __VGA_TEXTMODE_ENTRY_H__
#define __VGA_TEXTMODE_ENTRY_H__

#include <stdint.h>

#include "KernelMacros.h"
#include "VGATextModeColor.h"

typedef uint16_t VGATextModeEntry;
typedef uint16_t VGATextModeEntryChar;

C_FUNC VGATextModeEntry vga_textmode_entry_create
(
    VGATextModeEntryChar character, // IN: Character to write
    VGATextModeColor     color      // IN: Desired FG and BG color
);

#endif