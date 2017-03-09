/* main.c
 * 
 * borrowedbookdb program entry point.
 * Should be a fully interactive wrapper to the created database.
 *     Notify user if books are overdue/close to overdue. 
 *     Allow adding books.
 *     Allow extending book borrow time.
 *     Allow removing books.
 *     Allow printing bookdb.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <unistd.h>
#include <ctype.h>

#include "dbhelper.h"

int main(int argc, char** argv){
    // Replace with a setup script later; e.g on a new system,
    //  1. Check if the database has already been created.
    //  2. If not, create the database, make necessary modifications via user input.
    //  3. Setup environmental variables if need be.
    //  4. Run the program. 
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    valid_conn(conn);  

    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    char date[MAX_DATE_LEN];

    printf("----bookdb add----\n"); 
    printf("TITLE: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    
    printf("AUTHOR: ");
    fgets(author, MAX_AUTHOR_LEN, stdin);
    
    printf("ISBN: ");
    fgets(isbn, MAX_ISBN_LEN, stdin);
   
    printf("CHECK-IN DATE (mm-dd-yyyy): ");
    int month, day, year;          
    fgets(date, MAX_DATE_LEN, stdin);
    sscanf(date, "%d-%d-%d", &month, &day, &year);

    printf("TITLE: %s\n", title);
    printf("AUTHOR: %s\n", author);
    printf("ISBN: %s\n", isbn);
    printf("CHECK-IN DATE: %s\n", date);
    printf("Is this ok? (y/n)");

    Date *checkin = initdate(month, day, year);
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


