#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

void validconnection(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn); 
    }
}

void validresult(PGconn *conn, PGresult *res){
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved");
        PQclear(res);
        do_exit(conn); 
    }
}

int main(){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    validconnection(conn);

    PGresult *res = PQexec(conn, "SELECT * FROM gilBooks WHERE Id=0");
    validresult(conn, res);

    int ncols = PQnfields(res);
    printf("There are %d columns.\n", ncols);
    printf("Column names:\n");
    for (int i = 0; i < ncols; i++){
        char *name = PQfname(res, i);
        printf("%s\n", name); 
    }

    PQclear(res);
    PQfinish(conn);
    return 0;
}
