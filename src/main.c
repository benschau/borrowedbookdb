#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <unistd.h>
#include <ctype.h>

#include "pqhelper.h"

int main(int argc, char** argv){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    validconnection(conn);  
     
    PGresult *res = PQexec(conn, "SELECT * FROM gilBooks");    
    
    
    int numBooks; 
    printf("Current number of books checked out: %d", numBooks);
    //print book titles here
}
