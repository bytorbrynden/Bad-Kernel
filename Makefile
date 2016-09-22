ROOT := ${CURDIR}
TOOL := ${HOME}/osdev/utils/cross_compiler/bin
_SRC := ${ROOT}/Source
_INC := ${ROOT}/Include
_OUT := ${ROOT}/Build
_OBJ := ${_OUT}/objs
_ISO := ${_OUT}/isos

C_SRCS := $(shell find ${_SRC} -type f -name "*.c")
C_OBJS := $(patsubst ${_SRC}/%.c, ${_OBJ}/c/%.o, ${C_SRCS})

MD := mkdir
CP := cp
AS := ${TOOL}/i686-elf-as
CC := ${TOOL}/i686-elf-gcc

LD_FLAGS := -ffreestanding -O2 -nostdlib -lgcc
CC_FLAGS := -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I${_INC}

.PHONY: all
all: prepare clean objects assemble link check image

prepare:
	if [ ! -d ${_OUT} ]; then ${MD} -p ${_OUT}; fi
	if [ ! -d ${_OBJ} ]; then ${MD} -p ${_OBJ}; fi
	if [ ! -d ${_ISO} ]; then ${MD} -p ${_ISO}; fi
	
	# TODO: Clean this up
	if [ ! -d ${_OBJ}/c ]; then ${MD} -p ${_OBJ}/c; fi
	if [ ! -d ${_OBJ}/asm ]; then ${MD} -p ${_OBJ}/asm; fi

clean:
	rm -rf ${_ISO}/*
	
	# TODO: Clean this up
	rm -rf ${_OBJ}/c/*
	rm -rf ${_OBJ}/asm/*

objects: ${C_OBJS}

assemble:
	${AS} ${ROOT}/Kernel.S -o ${_OBJ}/asm/Kernel.o

link:
	${CC} -T ${ROOT}/Kernel.ld -o ${_OBJ}/bad.bin ${LD_FLAGS} $(shell find ${_OBJ} -type f -name "*.o")

check:
	grub-file --is-x86-multiboot ${_OBJ}/bad.bin

image:
	${MD} ${_ISO}/boot
	${CP} ${_OBJ}/bad.bin ${_ISO}/boot/
	${MD} ${_ISO}/boot/grub
	${CP} ${ROOT}/grub.cfg ${_ISO}/boot/grub
	grub-mkrescue -o bad.iso ${_ISO}

${_OBJ}/c/%.o: ${_SRC}/%.c
	${CC} ${CC_FLAGS} $^ -o $@