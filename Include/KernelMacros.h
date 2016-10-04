//
// Bad_Kernel
// Include/KernelMacros.h
//
#ifndef __KERNEL_MACROS_H__
#define __KERNEL_MACROS_H__

// In the event that we're getting compiled by a C++ compiler, we need to make
//  sure that we have a way to state the functions have C linkage. That's what
//  we do here. If the '__cplusplus' macro has been defined, we'll prefix all* C
//  functions with an extern saying they should use C linkage.
//
// *In reality, this doesn't actually prefix all functions; the functions have
//  to have the 'C_FUNC' prefix for this to work properly.
#ifdef __cplusplus
# define C_FUNC extern "C"
#else
# define C_FUNC
#endif

#endif