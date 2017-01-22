#ifndef BOOK_H_
#define BOOK_H_

#include "date.h"
#include <stdbool.h>

#define NUM_BOOK_PARAMS 4
#define RENEW_TIME 1

typedef struct Books {
    char *title;
    char *isbn;
    char *author; 
    Date *checkin;
} Book;

//int peekid();

bool compare(Book *book);

bool valid_title(char *title);

bool valid_isbn(char *isbn);

bool valid_author(char *author);

#endif
