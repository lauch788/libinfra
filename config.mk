# Customize below to fit your system

# paths (unset $PCPREFIX to not install a pkg-config-file)
DESTDIR   =
PREFIX    = /usr/local
INCPREFIX = $(PREFIX)/include
LIBPREFIX = $(PREFIX)/lib64
PCPREFIX  = $(PREFIX)/lib64/pkgconfig

# names
ANAME = libinfra.a

# flags
CFLAGS =
CFLAGS += -std=c11
CFLAGS += -pedantic -Wall -Wextra -O2
CFLAGS += -ggdb3
# CFLAGS += --coverage

# tools
CC     = gcc
AR     = ar
RANLIB = ranlib

