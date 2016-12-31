#ifndef BOOK_H_
#define BOOK_H_

#include "date.h"

typedef struct Books {
    char* title;
    char* isbn;
    char* author; 
    Date* checkin;
} Book;

#endif
