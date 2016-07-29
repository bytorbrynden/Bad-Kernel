/*
    ENTRY is used to specify the symbol that is to be used as the entry point
    of our output executable.
 */
ENTRY(_kernelStart)

/*
    SECTIONS is used to specify where certain symbols are placed in our output
    executable.
 */
SECTIONS
{
    /*
        . is the location counter variable. When in the root of the SECTIONS
        statement, its value is the byte offset from that of the start of the
        SECTIONS statement.
        
        When the location counter variable is used within a section definition,
        its value is the byte offset from the start of said section definition.
     */
    
    /*
        Here, we set the location counter to 1Mb into the file. This is done
        because, for one, Grub cannot load kernels below the 1Mb mark.
        
        The reason for that, is because there are apparently lots of special
        things located below the 1Mb mark, such as the VGA-buffer.
        
        References:
         http://os.phil-opp.com/multiboot-kernel.html#fn:Linker-1M
         http://wiki.osdev.org/Memory_Map_(x86)#.22Low.22_memory_.28.3C_1_MiB.29
     */
    . = 1M;
    
    /*
        Format of section definition:
        
        name : {
            contents
        }
     */
    
    /*
        The * operator is used to specify that we want to look in all input
        files, for the symbol (or symbols) specified within the parenthesis that
        follows.
        
        Example:
        
        .text : {
            *(.blah)
        }
        
        In the above example, the linker will look in all input files for the
        .blah symbol.
     */
    
    .multiboot :
    {
        *(.multiboot)
    }
    
    .text :
    {
        *(.text)
    }
    
    .rodata :
    {
        *(.rodata)
    }
    
    .data :
    {
        *(.data)
    }
    
    .bss :
    {
        *(COMMON)
        *(.bss)
    }
}