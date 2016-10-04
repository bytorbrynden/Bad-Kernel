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

void vga_textmode_buffer_write_c
(
    VGATextModeEntryChar character,
    int foreground,
    int background,
    VGATextModeBuffer *pTextmodeBuffer
)
{
    VGATextModeColor entryColor = vga_textmode_color_create(foreground,
        background);
    VGATextModeEntry bufferEntry = vga_textmode_entry_create(character,
        entryColor);
    size_t bufferIndex = 0x0;
    
    if (NULL == pTextmodeBuffer)
        return;
    
    if ('\n' == character)
    {
        pTextmodeBuffer->col = 0x0;
        pTextmodeBuffer->row++;
        
        return;
    }
    
    bufferIndex = (
        pTextmodeBuffer->row * VGA_TEXTMODE_BUFFER_WIDTH + pTextmodeBuffer->col
    );
    
    pTextmodeBuffer->pBuffer[bufferIndex] = bufferEntry;
    
    if (VGA_TEXTMODE_BUFFER_WIDTH == ++pTextmodeBuffer->col)
    {
        pTextmodeBuffer->col = 0x0;
        
        if (VGA_TEXTMODE_BUFFER_HEIGHT == ++pTextmodeBuffer->row)
        {
            pTextmodeBuffer->row = 0x0;
        }
    }
}

void vga_textmode_buffer_write_s
(
    const VGATextModeEntryChar *pString,
    int foreground,
    int background,
    VGATextModeBuffer *pTextmodeBuffer
)
{
    VGATextModeEntryChar character = 0x0;
    
    if (NULL == pTextmodeBuffer)
        return;
    
    while ((character = (*pString++)))
    {
        vga_textmode_buffer_write_c(character, foreground, background,
            pTextmodeBuffer);
    }
}