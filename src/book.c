#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libpq-fe.h>

#include "book.h"
//#include "date.h"
//#include "dbhelper.h"

Book* initbook(char *title, char *isbn, char *author, Date *checkin){
    int errnum; 
    Book* book = malloc(sizeof(Book));
    
    if (book != NULL) { 
        book->title = valid_title(title) ? title : NULL;
        book->isbn = valid_isbn(isbn) ? isbn : NULL;
        book->author = valid_author(author) ? author : NULL;
        book->checkin = checkin;
    } else {
        errnum = errno;
        fprintf(stderr, "Error allocating book structure: %s\n", strerror(errnum)); 
    }
        
    return book;    
}

/**
 * Compare two books.
 * Not sure if by title, by author, by?
 */
int compare(Book *book, Book *book2){
    return 0; 
}

/**
 * Check if the given title is valid (e.g it is within the size of the limit).
 */
bool valid_title(char *title){
    if (strlen(title) > MAX_TITLE_LEN){
        return false; 
    } 

    return true;
}

/** 
 * Check if the given isbn is valid (e.g right number of digits, etc).
 * ISBNs are 10 or 13 digit #s. 
 * You can convert from a 10 digit to a 13 digit by adding 978 
 * prefix and alter the last digit to indicate a 13 digit isbn.
 * How to check if a 10 digit ISBN is valid:
 *    0-7167-0344-0
 *      * Multiply each digit by its position, and find the sum.
 *          * e.g (0 * 1) + (4 * 2) + ... +
 *      * Mod the sum; if it is 0, it is a valid 10 digit isbn.
 *        if not, it is invalid.
 *    978-0-7167-0344-0
 *      * Multiply each number by an alternating 1 and 3; odd 
 *        number positions by 1, even number positions by 3. 
 *          * e.g (9 * 1) + (7 * 3) + ... + 
 *      * Mod the sum; if it is 0, it is a valid 13 digit isbn.
 *        if not, it is invalid. 
 */
bool valid_isbn(char *isbn){
     
    
    return true;
}

/** 
 * Check if the given author is valid (e.g it is within the size limit).
 */
bool valid_author(char *author){
    if (strlen(author) > MAX_AUTHOR_LEN){
        return false; 
    } 

    return true;
}
