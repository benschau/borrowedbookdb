TGT = gilbookdb

CC     = gcc
CFLAGS = -o $(TGT) -lpq -Wall

SRCDIR = src/

default: main

main:
	$(CC) $(CFLAGS) $(SRCDIR)main.c $(SRCDIR)dbhelper.c $(SRCDIR)date.c $(SRCDIR)book.c


