#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <unistd.h>
#include <ctype.h>

#include "dbhelper.h"

int main(int argc, char** argv){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    valid_conn(conn);  
    
    int numBooks = get_numrows(conn);
    printf("Current number of books checked out: %d", numBooks);
    
    do_exit(conn);
}


