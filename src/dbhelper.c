#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>
#include <string.h>

#include "dbhelper.h"
#include "date.h"
#include "book.h"

/** 
 * Close the connection to the database.
 */
void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

/** 
 * Check if the connection to the database is valid.
 */
void valid_conn(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn); 
    }
}

/**
 * Get the number of books in the checkout db.
 */
int get_numrows(PGconn *conn){
    valid_conn(conn);
     
    PGresult *res = PQexec(conn, "SELECT * FROM gilBooks");
    int rows = PQntuples(res); 
    PQclear(res); 
    
    return rows;
}

/**
 * Print the index of a given row in the checkout db.
 */
void print_row(PGconn *conn, int row){
   valid_conn(conn); 
   
   PGresult *res = PQexec(conn, "SELECT * FROM gilBooks");
   if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data structures in %s", PQdb(conn)); 
        PQclear(res);
        //exit 
   }

   if (row > get_numrows(conn)){
        PQclear(res); 
        //exit 
   }

   printf("%s %s %s\n", PQgetvalue(res, row, 0), PQgetvalue(res, row, 1), PQgetvalue(res, row, 2));  
   PQclear(res);
}

/**
 * Print the checkout db.
 */
void print_table(PGconn *conn){
    valid_conn(conn); 
    
    PGresult *res = PQexec(conn, "SELECT * FROM gilBooks");
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data structures in %s", PQdb(conn));
        PQclear(res);
        //exit 
    }
    
    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++){
        printf("%s %s %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), PQgetvalue(res, i, 2)); 
    }
    PQclear(res);
}

/**
 * Drop the entire checkout table.
 */
bool cleartable(PGconn *conn){
    valid_conn(conn);
    
    char* cmd = "DELETE FROM gilBooks";

    PGresult *res = PQexec(conn, cmd); 

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Command not executed: %s\n", PQerrorMessage(conn)); 
        PQclear(res);
        return false; 
    }

    return true;
}

/** 
 * Insert a book into the checkout db
 * TODO: If the same book is in the db table of books that've been checked out before.... 
 */
bool insertbook(PGconn *conn, Book *book){
    valid_conn(conn);
    
    const char *params[NUM_BOOK_PARAMS] = { book->title, book->isbn, book->author, getdate(book->checkin) }; 

    char *cmd = "INSERT INTO gilBooks VALUES($1, $2, $3, $4);";
    
    PGresult *res = PQexecParams(conn, cmd, NUM_BOOK_PARAMS, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Command not executed: %s\n", PQerrorMessage(conn)); 
        PQclear(res);
        return false; 
    }
   
    return true;
}

/** 
 * Remove a book from checkout db.
 * TODO: Add the removed book to another db table that keeps track of books you've borrowed before.
 */
bool removebook(PGconn *conn, char *isbn){
    valid_conn(conn);
   
    char *cmd = "DELETE FROM gilBooks WHERE isbn = $1;";  
  
    PGresult *res = PQexecParams(conn, cmd, 1, NULL, isbn, NULL, NULL, 0);
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Command not executed: %s\n", PQerrorMessage(conn)); 
        PQclear(res);
        return false; 
    }

    return true;    
}

// TODO: add function for valid result, valid_res()

/** 
 * Renews books in the database by RENEW_TIME, by default 1 month.
 */
bool renewbook(PGconn *conn, const char *const isbn){
    valid_conn(conn);
    
    Date* d = malloc(sizeof(Date));
    char *cmd = "SELECT * FROM gilBooks WHERE isbn=$1";
    PGresult *res = PQexecParams(conn, cmd, 1, NULL, isbn, NULL, NULL, 0); 
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Command not executed: %s\n", PQerrorMessage(conn)); 
        PQclear(res);
        return false; 
    }

    // TODO: add date validation
    d->day = (int) PQgetvalue(res, 0, 0);
    d->month = (int) PQgetvalue(res, 0, 1) + RENEW_TIME;
    d->year = (int) PQgetvalue(res, 0, 2);

    const char *params[2] = { getdate(d), isbn }; 
    
    cmd = "UPDATE gilBooks SET checkin=$1 WHERE isbn=$2;";      
     
    res = PQexecParams(conn, cmd, 2, NULL, params, NULL, NULL, 0);
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Command not executed: %s\n", PQerrorMessage(conn)); 
        PQclear(res);
        
        free(d); 
        return false; 
    }
    
    return true; 
}

