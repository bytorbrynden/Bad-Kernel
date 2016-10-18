ROOT := ${CURDIR}
UTIL := ${ROOT}/Tools/cc/bin
_SRC := ${ROOT}/Source
_INC := ${ROOT}/Include
_OUT := ${ROOT}/Build
_OBJ := ${_OUT}/obj
_ISO := ${_OUT}/iso

BIN_FILE := ${_ISO}/bad.bin

ARCH := i686-elf

S_SRCS := $(shell find ${_SRC} -type f -name "*.S")
C_SRCS := $(shell find ${_SRC} -type f -name "*.c")

S_OBJS := $(patsubst ${_SRC}/%.S, ${_OBJ}/s/%.o, ${S_SRCS})
C_OBJS := $(patsubst ${_SRC}/%.c, ${_OBJ}/c/%.o, ${C_SRCS})
__OBJS := $(shell find ${_OBJ} -type f -name "*.o")

MD := mkdir
CP := cp

AS := ${UTIL}/${ARCH}-as
CC := ${UTIL}/${ARCH}-gcc
OD := ${UTIL}/${ARCH}-objdump

LD_FLAGS := -ffreestanding -O2 -nostdlib -lgcc
CC_FLAGS := -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I${_INC}
OD_FLAGS := -S

.PHONY: all
all: clean prepare objects link check image

prepare:
	if [ ! -d ${_OUT} ]; then ${MD} -p ${_OUT}; fi
	if [ ! -d ${_OBJ} ]; then ${MD} -p ${_OBJ}; fi
	if [ ! -d ${_ISO} ]; then ${MD} -p ${_ISO}; fi
	if [ ! -d ${_OBJ}/c ]; then ${MD} -p ${_OBJ}/c; fi
	if [ ! -d ${_OBJ}/s ]; then ${MD} -p ${_OBJ}/s; fi

clean:
	rm -rf ${_OUT}/*

objects: ${S_OBJS} ${C_OBJS}

link:
	${CC} -T ${ROOT}/Kernel.ld -o ${BIN_FILE} ${LD_FLAGS} ${__OBJS}
	${OD} ${OD_FLAGS} ${BIN_FILE} > ${_OBJ}/bad.objdump

check:
	grub-file --is-x86-multiboot ${BIN_FILE}

image:
	${MD} ${_ISO}/boot
	${CP} ${BIN_FILE} ${_ISO}/boot/
	${MD} ${_ISO}/boot/grub
	${CP} ${ROOT}/grub.cfg ${_ISO}/boot/grub
	grub-mkrescue -o bad.iso ${_ISO}

${_OBJ}/s/%.o: ${_SRC}/%.S
	${MD} -p $(dir $@)
	${AS} $^ -o $@

${_OBJ}/c/%.o: ${_SRC}/%.c
	${MD} -p $(dir $@)
	${CC} ${CC_FLAGS} $^ -o $@