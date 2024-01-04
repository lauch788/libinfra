DESTDIR   =
PREFIX    = /usr/local
INCPREFIX = $(PREFIX)/include
LIBPREFIX = $(PREFIX)/lib

ANAME = libinfra.a

CC     = gcc -std=c99 -Wall -pedantic
CFLAGS = -O2 -march=native -ftree-vectorize

AR     = ar
RANLIB = ranlib
