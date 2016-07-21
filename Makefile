ROOT := ${CURDIR}
TOOL := ${HOME}/osdev/utils/cross_compiler/bin
_SRC := ${ROOT}/Source
_INC := ${ROOT}/Include
_OUT := ${ROOT}/Build
_OBJ := ${_OUT}/objs
_ISO := ${_OUT}/isos

C_SRCS := $(shell find ${_SRC} -type f -name "*.c")
C_OBJS := $(patsubst ${_SRC}/%.c, ${_OBJ}/%.o, ${C_SRCS})

MD := mkdir
AS := ${TOOL}/i686-elf-as

.PHONY: all
all: prepare assemble

prepare:
	if [ ! -d ${_OUT} ]; then ${MD} -p ${_OUT}; fi
	if [ ! -d ${_OBJ} ]; then ${MD} -p ${_OBJ}; fi
	if [ ! -d ${_ISO} ]; then ${MD} -p ${_ISO}; fi

assemble:
	${AS} ${ROOT}/Kernel.S -o ${_OBJ}/Kernel.o