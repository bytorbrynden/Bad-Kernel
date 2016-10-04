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

#define VGA_TEXTMODE_BUFFER_FG VGA_TEXTMODE_COLOR_WHITE
#define VGA_TEXTMODE_BUFFER_BG VGA_TEXTMODE_COLOR_BLACK

#define VGA_TEXTMODE_BUFFER_WIDTH  0x50 // 80
#define VGA_TEXTMODE_BUFFER_HEIGHT 0x19 // 25

#define VGA_TEXTMODE_BUFFER_PLACEHOLDER ' '

typedef struct
{
    size_t row;
    size_t col;
    
    VGATextModeColor color;
    
    VGATextModeEntry *pBuffer;
} VGATextModeBuffer;

C_FUNC VGATextModeBuffer vga_textmode_buffer_create();

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