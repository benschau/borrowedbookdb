TGT = gilbookdb

CC     = gcc
CFLAGS = -g -o $(TGT) -lpq -Wall

SRCDIR = src/

default: main

main:
	$(CC) $(CFLAGS) $(SRCDIR)main.c $(SRCDIR)dbhelper.c $(SRCDIR)date.c $(SRCDIR)book.c

test:
        

clean:
    
