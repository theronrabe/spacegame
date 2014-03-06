SHELL = /bin/sh
CC    = gcc
 
FLAGS        = -std=gnu99 -IgameMachine -I./ -w
CFLAGS       = -pedantic -Wall -Wextra -march=native -ggdb3
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O0 -D NDEBUG -combine -fwhole-program
LATEFLAGS    = -lGLU -lglut -lSOIL
 
TARGET  = ./NewtonsRevenge
SOURCES = $(shell echo gameMachine/*.c) $(shell echo ./*.c)
COMMON  = $(shell echo gameMachine/*.h)#include/definitions.h include/debug.h
HEADERS = $(shell echo gameMachine/*.h) $(shell echo ./*.h)
OBJECTS = $(SOURCES:.c=.o)
 
PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin
 
 
all: $(TARGET)
 
$(TARGET): $(OBJECTS) $(COMMON)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS) $(LATEFLAGS)

release: $(SOURCES) $(HEADERS) $(COMMON)
	$(CC) $(FLAGS) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SOURCES)

profile: CFLAGS += -pg
profile: $(TARGET)
 
 
install: release
	install -D $(TARGET) $(BINDIR)/$(TARGET)
 
install-strip: release
	install -D -s $(TARGET) $(BINDIR)/$(TARGET)
 
uninstall:
	-rm $(BINDIR)/$(TARGET)
 
 
clean:
	-rm -f $(OBJECTS)
	-rm -f gmon.out
 
distclean: clean
	-rm -f $(TARGET)
 
 
.SECONDEXPANSION:
 
$(foreach OBJ,$(OBJECTS),$(eval $(OBJ)_DEPS = $(shell gcc -MM $(OBJ:.o=.c) | sed s/.*://)))
%.o: %.c $$($$@_DEPS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -c -o $@ $<
 
# %.o: %.c $(HEADERS) $(COMMON)
#    $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -c -o $@ $<
 
 
.PHONY : all profile release \\
	install install-strip uninstall clean distclean