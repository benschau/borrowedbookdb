#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <unistd.h>
#include <ctype.h>

#include "dbhelper.h"

int main(int argc, char** argv){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    valid_conn(conn);  

    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    char date[MAX_DATE_LEN];

    printf("----bookdb add----"); 
    printf("TITLE: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    printf("AUTHOR: ");
    fgets(author, MAX_AUTHOR_LEN, stdin);
    printf("ISBN: ");
    fgets(isbn, MAX_ISBN_LEN, stdin);
    printf("CHECK OUT DATE: ");
    fgets(date, MAX_DATE_LEN, stdin);

    // need to convert month, date, year for date struct.
    // use atoi() and pointer arithmetic? 

    Date *checkin = initdate(9, 1, 2017);
    Book *book = initbook(title, isbn, author, checkin);

    bool success = insertbook(conn, book);
    free(book->checkin); 
    free(book);
    
    int numBooks = get_numrows(conn);
    if (success)
        printf("Insert succeeded!\n");
    printf("Current number of books checked out: %d", numBooks);
    
    do_exit(conn);
    exit(0);
}


