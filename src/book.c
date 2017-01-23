#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "book.h"
#include "date.h"
#include "dbhelper.h"

/*
int peekid(){
     
}
*/

Book* initbook(char *title, char *isbn, char *author, Date *checkin){
    Book* book = malloc(sizeof(Book));
    
    book->title = valid_title(title) ? title : NULL;
    book->isbn = valid_isbn(isbn) ? isbn : NULL;
    book->author = valid_author(author) ? author : NULL;
    book->checkin = checkin;
        
    return book;    
}

/**
 * Compare two books by their titles, authors?
 */
bool compare(Book *book){
}

/**
 * Check if the given title is valid (e.g it is within the size of the limit).
 */
bool valid_title(char *title){
}

/** 
 * Check if the given isbn is valid (e.g right number of digits, etc).
 */
bool valid_isbn(char *isbn){
}

/** 
 * Check if the given author is valid (e.g it is within the size limit).
 */
bool valid_author(char *author){
}
