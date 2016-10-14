ROOT := ${CURDIR}

ARCH := i686-elf

CC_DIR := ${ROOT}/cc

BINUTILS_VER := 2.26
BINUTILS_DIR := ${CC_DIR}/binutils-${BINUTILS_VER}
BINUTILS_TAR := ${CC_DIR}/binutils-${BINUTILS_VER}.tar.bz2
BINUTILS_URL := https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VER}.tar.bz2
BINUTILS_BLD := --target=${ARCH} --prefix="${CC_DIR}" --with-sysroot --disable-nls --disable-werror

GCC_VER := 6.1.0
GCC_DIR := ${CC_DIR}/gcc-${GCC_VER}
GCC_TAR := ${CC_DIR}/gcc-${GCC_VER}.tar.bz2
GCC_URL := https://ftp.gnu.org/gnu/gcc/gcc-6.1.0/gcc-${GCC_VER}.tar.bz2
GCC_BLD := --target=${ARCH} --prefix="${CC_DIR}" --disable-nls --enable-languages=c,c++ --without-headers

TAR := tar
TAR_FLAGS := -zxf

CURL := curl
CURL_FLAGS := -O

export PATH := ${CC_DIR}/bin:${PATH}

build_cc: cc_prepare cc_download cc_extract cc_build cc_bin_print

cc_prepare:
	if [ ! -d ${CC_DIR} ]; then mkdir ${CC_DIR}; fi

cc_download:
	if [ ! -f ${BINUTILS_TAR} ]; then cd ${CC_DIR} && ${CURL} ${CURL_FLAGS} ${BINUTILS_URL}; fi
	if [ ! -f ${GCC_TAR} ]; then cd ${CC_DIR} && ${CURL} ${CURL_FLAGS} ${GCC_URL}; fi

cc_extract:
	if [ ! -d ${BINUTILS_DIR} ]; then cd ${CC_DIR} && ${TAR} ${TAR_FLAGS} ${BINUTILS_TAR}; fi
	if [ ! -d ${GCC_DIR} ]; then  cd ${CC_DIR} && ${TAR} ${TAR_FLAGS} ${GCC_TAR}; fi

cc_build: build_binutils build_gcc

build_binutils:
	if [ ! -d ${BINUTILS_DIR}/build ]; then mkdir ${BINUTILS_DIR}/build; fi
	cd ${BINUTILS_DIR}/build && ../configure ${BINUTILS_BLD}
	${MAKE} -C ${BINUTILS_DIR}/build
	${MAKE} -C ${BINUTILS_DIR}/build install

build_gcc:
	if [ ! -d ${GCC_DIR}/build ]; then mkdir ${GCC_DIR}/build; fi
	cd ${GCC_DIR} && ./contrib/download_prerequisites
	cd ${GCC_DIR}/build && ../configure ${GCC_BLD}
	${MAKE} -C ${GCC_DIR}/build all-gcc
	${MAKE} -C ${GCC_DIR}/build all-target-libgcc
	${MAKE} -C ${GCC_DIR}/build install-gcc
	${MAKE} -C ${GCC_DIR}/build install-target-libgcc

cc_bin_print:
	ls -o1 ${CC_DIR}/bin