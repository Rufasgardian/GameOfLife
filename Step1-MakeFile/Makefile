CC=gcc
CFLAGS=-c -std=gnu99
PACKAGE   = GameOfLife
VERSION   = step1
ARCHIVE   = $(PACKAGE)-$(VERSION)

all: GameOfLife

GameOfLife: main.o logic.o ansi_gui.o
	$(CC) main.o logic.o ansi_gui.o -o GameOfLife

main.o: source/main.c
	$(CC) $(CFLAGS) source/main.c

logic.o: source/logic.c source/logic.h
	$(CC) $(CFLAGS) source/logic.c

ansi_gui.o: source/ansi_gui.c source/ansi_gui.h
	$(CC) $(CFLAGS) source/ansi_gui.c

clean: 
	rm *.o GameOfLife

dist:
	tar -zcf $(ARCHIVE).tar.gz source

cleandist:
	rm $(ARCHIVE).tar.gz

doc:
	doxygen dconfig

cleandoc:
	rm -rf html latex