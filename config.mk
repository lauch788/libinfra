# Customize below to fit your system

# paths (unset $PCPREFIX to not install a pkg-config-file)
DESTDIR   =
PREFIX    = /usr/local
INCPREFIX = $(PREFIX)/include
LIBPREFIX = $(PREFIX)/lib
PCPREFIX  = $(LIBPREFIX)/pkgconfig

# names
ANAME = libinfra.a

# flags
CFLAGS = -std=c99 -Wall -pedantic -O2

# tools
CC     = cc
AR     = ar
RANLIB = ranlib
