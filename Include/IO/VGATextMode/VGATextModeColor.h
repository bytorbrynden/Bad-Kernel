//
// Bad_Kernel
// Include/IO/VGATextMode/VGATextModeColor.h
//
#ifndef __VGA_TEXTMODE_COLOR_H__
#define __VGA_TEXTMODE_COLOR_H__

#include <stdint.h>

#include "KernelMacros.h"

typedef uint8_t VGATextModeColor;

#define VGA_TEXTMODE_COLOR_BLACK         0x00
#define VGA_TEXTMODE_COLOR_BLUE          0x01
#define VGA_TEXTMODE_COLOR_GREEN         0x02
#define VGA_TEXTMODE_COLOR_CYAN          0x03
#define VGA_TEXTMODE_COLOR_RED           0x04
#define VGA_TEXTMODE_COLOR_MAGENTA       0x05
#define VGA_TEXTMODE_COLOR_BROWN         0x06
#define VGA_TEXTMODE_COLOR_LIGHT_GREY    0x07
#define VGA_TEXTMODE_COLOR_DARK_GREY     0x08
#define VGA_TEXTMODE_COLOR_LIGHT_BLUE    0x09
#define VGA_TEXTMODE_COLOR_LIGHT_GREEN   0x0A
#define VGA_TEXTMODE_COLOR_LIGHT_CYAN    0x0B
#define VGA_TEXTMODE_COLOR_LIGHT_RED     0x0C
#define VGA_TEXTMODE_COLOR_LIGHT_MAGENTA 0x0D
#define VGA_TEXTMODE_COLOR_LIGHT_BROWN   0x0E
#define VGA_TEXTMODE_COLOR_WHITE         0x0F

C_FUNC VGATextModeColor vga_textmode_color_create
(
    int foreground, // IN: Foreground Color
    int background  // IN: Background Color
);

#endif