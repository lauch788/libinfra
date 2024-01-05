.POSIX:
.SUFFIXES:

include config.mk

CFLAGS += -I.

all: $(ANAME)

SRCS =\
	src/object\
	src/stack\
	src/string\

$(ANAME): $(SRCS:=.o)
	$(AR) -rc $@ $^
	$(RANLIB) $@

src/object.o: src/object.c infra/object.h
src/stack.o: src/stack.c infra/stack.h
src/string.o: src/string.c infra/string.h

$(SRCS:=.o):
	$(CC) -c -o $@ $(CFLAGS) $(@:.o=.c)

$(SRCS:=.o): config.mk Makefile

install: all
	mkdir -p "$(DESTDIR)$(LIBPREFIX)"
	mkdir -p "$(DESTDIR)$(INCPREFIX)/infra"
	cp -f $(ANAME) "$(DESTDIR)$(LIBPREFIX)"
	cp -r infra "$(DESTDIR)$(INCPREFIX)"
	if ! [ -z "$(PCPREFIX)" ]; then mkdir -p "$(DESTDIR)$(PCPREFIX)"; printf "Name: libinfra\nDescription: C99 Utility Library\nURL: https://github.com/rshadr/libinfra\nVersion: 0.1\nCflags: -I$(INCPREFIX)\nLibs: -L$(LIBPREFIX) -linfra -lgrapheme\n" > "$(DESTDIR)$(PCPREFIX)/libinfra.pc"; fi

uninstall:
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(ANAME)"
	rm -rdf "$(DESTDIR)$(INCPREFIX)/infra"

clean:
	rm -rf $(ANAME) $(SRCS:=.o)

.PHONY: clean
