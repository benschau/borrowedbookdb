#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn, PGresult *result){
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    PQclear(result);
    PQfinish(conn);
    exit(1);
}

void valid_res_status(PGconn *conn, PGresult *result){
    if (PQresultStatus(result) != PGRES_COMMAND_OK){
        do_exit(conn, result); 
    }
}

int main(){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
  
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", 
            PQerrorMessage(conn));
        PQfinish(conn);
        exit(1); 
    }
    
    PGresult *res = PQexec(conn, "DROP TABLE IF EXISTS gilBooks"); 
     
    valid_res_status(conn, res);
    PQclear(res);

    res = PQexec(conn, "CREATE TABLE gilBooks(Id INTEGER PRIMARY KEY," \
        "Name VARCHAR(225), ICBN VARCHAR(225))");

    valid_res_status(conn, res);
    PQclear(res);

    res = PQexec(conn, "INSERT INTO gilBooks VALUES(1, 'Wicked Cool Shell Scripts', 'ICBNHERE')");

    valid_res_status(conn, res);
    PQclear(res);

    res = PQexec(conn, "INSERT INTO gilBooks VALUES(2, 'Code Complete', 'ICBNHERE')");

    valid_res_status(conn, res);
    PQclear(res);
    PQfinish(conn);

    return 0;
}
