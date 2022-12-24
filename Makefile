CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
PUBDIR = $(HOME)/cmpt433/public/myApps/

all: execute
	cp hello $(PUBDIR)

hello.o: 
	$(CC) $(CFLAGS) -c -g hello.c

LED.o:
	$(CC) $(CFLAGS) -c -g LED.c

button.o:
	$(CC) $(CFLAGS) -c -g button.c

execute: hello.o LED.o button.o
	$(CC) $(CFLAGS) -o hello hello.o LED.o button.o -lm


clean:
	rm -rf *.o hello *~
