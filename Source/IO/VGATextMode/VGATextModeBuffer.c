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

void vga_textmode_buffer_increase_row
(
    VGATextModeBuffer *pTextmodeBuffer
)
{
    if (NULL == pTextmodeBuffer)
        return;
    
    if (VGA_TEXTMODE_BUFFER_HEIGHT == ++pTextmodeBuffer->row)
    {
        // Welcome, to [simulated] scrolling. The following code, which isn't
        //  very efficient, does nothing more than shift all of the buffer's
        //  contents up by 1 row. It also disgards the topmost row.
        
        for (size_t row = 0x0; row < VGA_TEXTMODE_BUFFER_HEIGHT; ++row)
        {
            for (size_t col = 0x0; col < VGA_TEXTMODE_BUFFER_WIDTH; ++col)
            {
                // TODO (Giga): Use a better name for this variable.
                size_t i = row * VGA_TEXTMODE_BUFFER_WIDTH + col;
                
                if (VGA_TEXTMODE_BUFFER_HEIGHT > (row + 1))
                {
                    // TODO (Giga): Use a better name for this variable.
                    size_t j = (row + 1) * VGA_TEXTMODE_BUFFER_WIDTH + col;
                    
                    pTextmodeBuffer->pBuffer[i] = pTextmodeBuffer->pBuffer[j];
                }
            }
        }
        
        // We're always on the next-to-last row once this runs.
        pTextmodeBuffer->row = (VGA_TEXTMODE_BUFFER_HEIGHT - 1);
    }
    
    pTextmodeBuffer->col = 0x0;
}

void vga_textmode_buffer_increase_col
(
    VGATextModeBuffer *pTextmodeBuffer
)
{
    if (NULL == pTextmodeBuffer)
        return;
    
    if (VGA_TEXTMODE_BUFFER_WIDTH == ++pTextmodeBuffer->col)
        vga_textmode_buffer_increase_row(pTextmodeBuffer);
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
        vga_textmode_buffer_increase_row(pTextmodeBuffer);
        
        return;
    }
    
    bufferIndex = (
        pTextmodeBuffer->row * VGA_TEXTMODE_BUFFER_WIDTH + pTextmodeBuffer->col
    );
    
    pTextmodeBuffer->pBuffer[bufferIndex] = bufferEntry;
    
    vga_textmode_buffer_increase_col(pTextmodeBuffer);
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