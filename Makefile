CC=gcc
CFLAGS=-Wall -Wextra `sdl2-config --cflags --libs`

sdl: main.c
	$(CC) main.c $(CFLAGS) -o sdl
