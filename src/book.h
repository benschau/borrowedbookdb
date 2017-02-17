#ifndef BOOK_H_
#define BOOK_H_

#include "date.h"
#include <stdbool.h>

#define MAX_AUTHOR_LEN 1024
#define MAX_TITLE_LEN 1024
#define NUM_BOOK_PARAMS 4
#define RENEW_TIME 1

typedef struct Books {
    char *title;
    char *isbn;
    char *author; 
    Date *checkin;
} Book;

int compare(Book *book, Book *book2);

bool valid_title(char *title);

bool valid_isbn(char *isbn);

bool valid_author(char *author);

Book* initbook(char *title, char *isbn, char *author, Date *checkin);

#endif
