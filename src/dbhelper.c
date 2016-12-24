#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>

#include "dbhelper.h"

void do_exit(PGconn *conn){
    PQfinish(conn);
    exit(1);
}

bool valid_conn(PGconn *conn){
    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn); 
    }
}

/*
bool valid_res(PGconn *conn, PGresult *res){
   if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data structures in %s", PQdb(conn)); 
        PQclear(res);
        //exit 
   }
}
*/

int get_numrows(PGconn *conn){
    valid_conn(conn);
     
    PGresult *res = PQexec(conn, "SELECT * FROM gilBooks");
    int rows = PQntuples(res); 
    PQclear(res); 
    
    return rows;
}

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


