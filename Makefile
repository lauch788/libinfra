.POSIX:
.SUFFIXES:

include config.mk

CFLAGS += -I.

all: $(ANAME)

TEST =\
	test/queue\
	test/stack\
	test/string\

SRCS =\
	src/queue\
	src/stack\
	src/string\

$(ANAME): $(SRCS:=.o)
	$(AR) -rc $@ $^
	$(RANLIB) $@

src/queue.o: src/queue.c infra/queue.h
src/object.o: src/object.c infra/object.h
src/stack.o: src/stack.c infra/stack.h
src/string.o: src/string.c infra/string.h

$(SRCS:=.o):
	$(CC) -c -o $@ $(CFLAGS) $(@:.o=.c)

$(SRCS:=.o): config.mk Makefile

test: $(TEST)
	@for t in $(TEST); do echo -n "Running $$t:\t"; ./$$t && echo 'passed' || echo 'failed'; done

$(TEST): $(ANAME)
	$(CC) -o $@ $(CFLAGS) $(@:=.c) -L. -linfra -lgrapheme

test/queue: test/queue.c infra/queue.h
test/stack: test/stack.c infra/stack.h
test/string: test/string.c infra/string.h

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
	rm -rf $(ANAME) $(SRCS:=.o) $(TEST)

.PHONY: all test install uninstall clean

