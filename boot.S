#
# boot.S
# The official entry point for the bad kernel
#
# Uses AT&T Syntax
#

# .set directive     https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_chapter/as_7.html#SEC120
# .section directive https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_chapter/as_7.html#SEC119
# .align directive   https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_chapter/as_7.html#SEC70
# .int directive     https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_chapter/as_7.html#SEC98
# .long directive    https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_chapter/as_7.html#SEC108

# Multiboot References:
#  https://www.gnu.org/software/grub/manual/multiboot/html_node/Header-magic-fields.html
#  http://fossies.org/linux/grub/include/multiboot.h

.set MULTIBOOT_MAGIC,       0x1BADB002 # Used to allow the bootloader to find us
.set MULTIBOOT_ALIGN,       0x00000001 # Used to align all boot modules on i386 page boundaries
.set MULTIBOOT_MEMINFO,     0x00000002 # Used to pass memory information to operating system
# According to the multiboot specification, this field in the multiboot header
#  plus the above 3, should equal 0
.set MULTIBOOT_CHECKSUM, -(MULTIBOOT_MAGIC + (MULTIBOOT_ALIGN + MULTIBOOT_MEMINFO))

# The multiboot header is what marks this program as a kernel. Bootloaders look
#  in the first 8KB of a kernel file, for this header.
#
# The declaration of the multiboot header is placed within its own section, so
#  the bootloader can find it within the first 8KB of the file.
.section .multiboot
.align 4 # Align multiboot header to 32 bit boundary. (8 * 4 = 32)
multiboot_header:
    .int MULTIBOOT_MAGIC
    .int MULTIBOOT_ALIGN
    .int MULTIBOOT_MEMINFO
    .int MULTIBOOT_CHECKSUM

# Stack is placed in its own section so that we can give it the following flags:
#  The "aw" flag, which marks the section as allocatable and writeable.
#  The @nobits flag, which marks that the section doesn't contain any data.
.section .stack, "aw", @nobits
stack_start: # Bottom of stack, pointed to by esp register.
    # I don't know what to do here. I assume some memory will need to be reserved
    #  for the stack, so it can be used later on in the kernel. That being said,
    #  I've yet to figure out how one would go about doing this.

stack_end: # Top of stack, pointed to by ebx register.
    # I don't know what to put here...

# TODO...
