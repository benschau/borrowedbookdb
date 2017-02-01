LIBS = -lpq
CC     = gcc
CFLAGS = -g -Wall

TGT = bookdb

SRC_DIR = src/
SRCS = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRCS:.c=.o)

all: $(TGT)

$(TGT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm $(SRC_DIR)*.o    
 
