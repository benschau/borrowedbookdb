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

void validresult(PGconn *conn, PGresult *res){
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved.");
        PQclear(res);
        do_exit(conn); 
    }
}

int main(int argc, char **argv){
    const int LEN = 10;
    const char *paramvalues[1];

    if (argc != 2){
        fprintf(stderr, "Usage: prepared_statement rowId\n");
        exit(1); 
    }

    int rowId;
    int ret = sscanf(*(argv + 1), "%d", &rowId);

    if (ret != 1){
        fprintf(stderr, "The argument must be an integer.");
        exit(1);  
    }

    if (rowId < 0){
        fprintf(stderr, "Error passing a negative rowId\n"); 
        exit(1); 
    }

    char str[LEN];
    snprintf(str, LEN, "%d", rowId);
    paramvalues[0] = str;

    PGconn *conn = PQconnectdb("user=barchie dbname=bookdb");
    validconnection(conn);

    char *stm = "SELECT * FROM gilBooks WHERE Id=$1";
    PGresult *res = PQexecParams(conn, stm, 1, NULL, paramvalues, NULL, NULL, 0);
    validresult(conn, res);

    printf("%s %s %s\n", PQgetvalue(res, 0, 0), 
        PQgetvalue(res, 0, 1), PQgetvalue(res, 0, 2));

    PQclear(res);
    PQfinish(conn);

    return 0;
}
