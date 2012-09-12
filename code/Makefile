CC=clang
CFLAGS+=-g -std=c99 -Wall -pedantic

stack-bounds-gnu: stack-bounds-gnu.c
	$(CC) -o stack-bounds-gnu stack-bounds-gnu.c -lpthread

thread-local: thread-local.c
	$(CC) -o thread-local thread-local.c -lpthread
