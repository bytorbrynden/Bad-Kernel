//
// Bad_Kernel
// Include/IO/VGATextMode/VGATextModeBuffer.h
//
#ifndef __VGA_TEXTMODE_BUFFER_H__
#define __VGA_TEXTMODE_BUFFER_H__

#include <stddef.h>
#include <stdint.h>

#include "KernelMacros.h"
#include "VGATextModeEntry.h"

// TODO (You): Change this, and see what happens!
#define VGA_TEXTMODE_BUFFER_FG VGA_TEXTMODE_COLOR_WHITE
#define VGA_TEXTMODE_BUFFER_BG VGA_TEXTMODE_COLOR_BLACK

// The following width and height, refer to the number of characters that fit
//  on the screen.
#define VGA_TEXTMODE_BUFFER_WIDTH  0x50 // 80
#define VGA_TEXTMODE_BUFFER_HEIGHT 0x19 // 25

// The character specified here, is the character that we'll use to fill the
//  buffer up initially. We'll also use this character whenever a request is
//  made to clear out a location in the buffer.
//
// TODO (You): Change this, and see what happens!
#define VGA_TEXTMODE_BUFFER_PLACEHOLDER ' '

// This anonymous struct (which we later typedef), is used to store information
//  about the text-mode buffer.
typedef struct
{
    // The following members, are used to keep track of our location within the
    //  buffer. You'll find this information to be really invaluable when you
    //  want to write something to the buffer later on.
    size_t row;
    size_t col;
    
    // This is the color (or colors, rather) that we want to use when we
    //  initialize (and in the future, refresh?) the buffer.
    VGATextModeColor color;
    
    // This is what we'll use to reference the actual textmode buffer, which
    //  starts at 0xB8000 (a physical memory address).
    VGATextModeEntry *pBuffer;
} VGATextModeBuffer;

C_FUNC VGATextModeBuffer vga_textmode_buffer_create();

C_FUNC void vga_textmode_buffer_increase_row
(
    VGATextModeBuffer *pTextmodeBuffer // IN: The buffer to modify
);

C_FUNC void vga_textmode_buffer_increase_col
(
    VGATextModeBuffer *pTextmodeBuffer // IN: The buffer to modify
);

C_FUNC void vga_textmode_buffer_write_c
(
    VGATextModeEntryChar character,    // IN: The character to write
    int foreground,                    // IN: The foreground color
    int background,                    // IN: The background color
    VGATextModeBuffer *pTextmodeBuffer // IN: The buffer to write to
);

C_FUNC void vga_textmode_buffer_write_s
(
    const VGATextModeEntryChar *pString, // IN: The string to write
    int foreground,                      // IN: The foreground color
    int background,                      // IN: The background color
    VGATextModeBuffer *pTextmodeBuffer   // IN: The buffer to write to
);

#endif