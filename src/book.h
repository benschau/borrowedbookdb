#ifndef BOOK_H_
#define BOOK_H_

typedef struct Books {
    char* title;
    char* isbn;
    Date* checkout;
    Date* checkin;
} Book;

#endif
