#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

void validconnection(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", 
            PQerrorMessage(conn));
        do_exit(conn); 
    }
}

int main(){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    validconnection(conn);

    char *params[4] = { 'C Programming', '1-10-190-10', 'Kernighan & Ritchie', '1-10-1998' };

}
