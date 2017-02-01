#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <unistd.h>
#include <ctype.h>

#include "dbhelper.h"

int main(int argc, char** argv){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    valid_conn(conn);  
    
    Book* book = malloc(sizeof(Book));

    book->title = "C Programming Language";
    book->isbn = "0-13-110163-3";
    book->author = "Kernighan and Ritchie";
    
    book->checkin = malloc(sizeof(Date));
    book->checkin->day = 9;
    book->checkin->month = 1;
    book->checkin->year = 2017; 

    bool success = insertbook(conn, book);
    free(book);
    
    int numBooks = get_numrows(conn);
    if (success)
        printf("Insert succeeded!");
    printf("Current number of books checked out: %d", numBooks);
    
    do_exit(conn);
}


