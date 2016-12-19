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

    PGresult *res = PQexec(conn, "SELECT version()");

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
        do_exit(conn); 
    }

    printf("%s\n", PQgetvalue(res, 0, 0));
    PQclear(res);
    PQfinish(conn);
    return 0;
}
