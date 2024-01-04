.POSIX:
.SUFFIXES:

include config.mk

CFLAGS += -I.

all: $(ANAME)

INCLUDES =\
	stack.h\
	string.h\

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
	for h in $(INCLUDES); do cp -f infra/$h "$(DESTDIR)$(INCPREFIX)/infra/$h"; done

uninstall:
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(ANAME)"
	rm -rdf "$(DESTDIR)$(INCPREFIX)/infra"

clean:
	rm -rf $(ANAME) $(SRCS:=.o)

.PHONY: clean
