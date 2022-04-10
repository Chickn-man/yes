PROGNAME = yes

CC = gcc

INCS =
LIBS =

CFLAGS = $(INCS) $(LIBS)

WIN_CC = x86_64-w64-mingw32-gcc

WIN_INCS =
WIN_LIBS =

WIN_CFLAGS = $(WIN_INCS) $(WIN_LIBS)


SRCDIR := src
BUILDDIR := bin

PREFIX = /usr/local

DB = gdb
VG = valgrind

VALFLAGS =
DBFLAGS =

RUNFLAGS =

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)
DIRS = $(wildcard $(SRCDIR)/*)

build: nix win

nix: setup
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$(PROGNAME) $(SRC)

win: setup
	$(WIN_CC) $(WIN_CFLAGS) -o $(BUILDDIR)/$(PROGNAME).exe $(SRC)

setup:
	@ mkdir -p $(SRCDIR)
	@ mkdir -p $(BUILDDIR)
	
clean:
	-@ rm -r $(BUILDDIR)

install: build
	@ cp $(BUILDDIR)/$(PROGNAME) $(PREFIX)/bin/$(PROGNAME)
	@ chmod 6555 $(PREFIX)/bin/$(PROGNAME)

run:
	./$(BUILDDIR)/$(PROGNAME) $(RUNFLAGS)

buildDebug:
	$(CC) $(CFLAGS) -g $(SRC) -o $(BUILDDIR)/$(PROGNAME)

debug: buildDebug
	$(DB) $(DEGUBERFLAGS) ./$(BUILDDIR)/$(PROGNAME) $(RUNFLAGS)

valgrind: buildDebug
	$(VG) $(VALFLAGS) ./$(BUILDDIR)/$(PROGNAME) $(RUNFLAGS)