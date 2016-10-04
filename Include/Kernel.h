//
// Bad_Kernel
// Include/Kernel.h
//
#ifndef __BAD_KERNEL_H__
#define __BAD_KERNEL_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "KernelMacros.h"
#include "IO/VGATextMode/VGATextModeBuffer.h"

#define KERNEL_ENTRY_MESSAGE ( \
    "******       **     *******  \n" \
    "*    **     ****    **    ** \n" \
    "*    **    **  **   **     **\n" \
    "******    **    **  **     **\n" \
    "*     ** ********** **     **\n" \
    "*     ** **      ** **    ** \n" \
    "*******  **      ** *******  kernel\n" \
)

// The 'kernel_entry' function serves as the entry point for the (C-side) of
//  the kernel.
//
// We declare this function and state that it should have C linkage.
C_FUNC void kernel_entry();

#endif