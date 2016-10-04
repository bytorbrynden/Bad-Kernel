//
// Bad_Kernel
// Source/Kernel.c
//
#include "Kernel.h"

void kernel_entry()
{
    VGATextModeBuffer buffer = vga_textmode_buffer_create();
    
    vga_textmode_buffer_write_s(KERNEL_ENTRY_MESSAGE, VGA_TEXTMODE_COLOR_BLUE,
        VGA_TEXTMODE_COLOR_BLACK, &buffer);
}