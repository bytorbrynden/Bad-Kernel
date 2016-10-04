//
// Bad_Kernel
// Source/Kernel.c
//
#include "Kernel.h"

void kernel_entry()
{
    VGATextModeBuffer buffer = vga_textmode_buffer_create();
    
    vga_textmode_buffer_write_s("Hello, world!\n", VGA_TEXTMODE_COLOR_WHITE,
        VGA_TEXTMODE_COLOR_BLACK, &buffer);
}