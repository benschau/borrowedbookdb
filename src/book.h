#ifndef BOOK_H_
#define BOOK_H_

#include "date.h"

#define NUM_BOOK_PARAMS 4

typedef struct Books {
    char* title;
    char* isbn;
    char* author; 
    Date* checkin;
} Book;

//int peekid();

#endif
