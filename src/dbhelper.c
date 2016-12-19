#include "dbhelper.h"

void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

bool validconnection(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn); 
    }
}

