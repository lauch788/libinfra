# Customize below to fit your system

# paths (unset $PCPREFIX to not install a pkg-config-file)
DESTDIR   =
PREFIX    = /usr/local
INCPREFIX = $(PREFIX)/include
LIBPREFIX = $(PREFIX)/lib
PCPREFIX  = $(PREFIX)/lib64/pkgconfig

# names
ANAME = libinfra.a

# flags
CFLAGS = -std=c99 -Wall -pedantic -O2 -ggdb3

# tools
CC     = cc
AR     = ar
RANLIB = ranlib
