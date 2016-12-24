#ifndef DBHELPER_H_
#define DBHELPER_H_

#include <libpq-fe.h>
#include <stdbool.h>

void do_exit(PGconn *conn);

bool valid_conn(PGconn *conn);

int get_numrows(PGconn *conn);

void print_row(PGconn *conn, int row);

void print_table(PGconn *conn);

#endif 
