//
// Bad_Kernel
// Source/IO/VGATextMode/VGATextModeBuffer.c
//
#include "IO/VGATextMode/VGATextModeBuffer.h"

VGATextModeBuffer vga_textmode_buffer_create()
{
    VGATextModeBuffer buffer;
    
    buffer.row = 0x0;
    buffer.col = 0x0;
    
    buffer.color = vga_textmode_color_create(
        VGA_TEXTMODE_BUFFER_FG,
        VGA_TEXTMODE_BUFFER_BG
    );
    
    buffer.pBuffer = (VGATextModeEntry *) 0xB8000; // Physical Memory Address
    
    for (size_t row = 0x0; row < VGA_TEXTMODE_BUFFER_HEIGHT; ++row)
    {
        for (size_t col = 0x0; col < VGA_TEXTMODE_BUFFER_WIDTH; ++col)
        {
            buffer.pBuffer[row * VGA_TEXTMODE_BUFFER_WIDTH + col] = (
                vga_textmode_entry_create(VGA_TEXTMODE_BUFFER_PLACEHOLDER,
                    buffer.color
                )
            );
        }
    }
    
    return buffer;
}