#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

void validconnection(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to the database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn); 
    }
}

/*
void validresult(PGconn *conn, PGres *res, char *command){
    
}
*/

int main(){
    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    validconnection(conn);

    PGresult *res = PQexec(conn, "BEGIN");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        printf("BEGIN command failed...\n");
        PQclear(res);
        do_exit(conn); 
    }

    PQclear(res);

    res = PQexec(conn, "UPDATE gilBooks SET ICBN='978-1-59327-012-4' WHERE Id=1");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        printf("UPDATE command failed...\n");
        PQclear(res);
        do_exit(conn); 
    }

    res = PQexec(conn, "INSERT INTO gilBooks VALUES(3, 'Linux Programming By Example', 'ICBN HERE')");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        printf("INSERT command failed...\n");
        PQclear(res);
        do_exit(conn); 
    }

    res = PQexec(conn, "COMMIT");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        printf("COMMIT command failed...\n");
        PQclear(res);
        do_exit(conn); 
    }
   
    PQclear(res);
    PQfinish(conn);
    return 0; 
}

