#
# Source/CPU/GDT/GDT.S
#
# Uses AT&T Syntax
#
#.section .text
.global initializeGDT
initializeGDT:
    lgdt (gdtReference)
    call reloadSegments
    ret

gdtEntriesStart:

    gdtNullEntry:
        .word 0x0 # Limit
        .word 0x0 # Base
        .byte 0x0
        .byte 0x0
        .byte 0x0
        .byte 0x0
    
    gdtCodeEntry:
        .word 0xFFFFFFFF # Limit
        .word 0x00000000 # Base
        .byte 0x0
        .byte 0x9A
        .byte 0xCF
        .byte 0x0
    
    gdtDataEntry:
        .word 0xFFFFFFFF # Limit
        .word 0x00000000 # Base
        .byte 0x0
        .byte 0x92
        .byte 0xCF
        .byte 0x0

gdtEntriesEnd:

#.global gdtReference
gdtReference:
    .word gdtEntriesEnd - gdtEntriesStart - 1
    .int gdtEntriesStart

.set CODE_SEGMENT, gdtCodeEntry - gdtEntriesStart
.set DATA_SEGMENT, gdtDataEntry - gdtEntriesStart

#.global reloadSegments
reloadSegments:
    mov $DATA_SEGMENT, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    ljmp $CODE_SEGMENT, $gdtDummy

gdtDummy:
    ret