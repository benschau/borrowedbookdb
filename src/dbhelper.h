#ifndef DBHELPER_H_
#define DBHELPER_H_

#include <libpq-fe.h>
#include <stdbool.h>
#include "book.h"

#define MAX_COMMAND_LEN 1024

/* PGconn* initBookDB(); */

void do_exit(PGconn *conn);

void valid_conn(PGconn *conn);

int get_numrows(PGconn *conn);

void print_row(PGconn *conn, int row);

void print_table(PGconn *conn);

bool cleartable(PGconn *conn);

bool insertbook(PGconn *conn, Book* book);

bool removebook(PGconn *conn, const char *const *isbn);

bool renewbook(PGconn *conn, const char *const *isbn);

#endif 
