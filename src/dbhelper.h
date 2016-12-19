#ifndef DBHELPER_H_
#define DBHELPER_H_

void do_exit(PQconn *conn);

bool validconnection(PQconn *conn);

#endif 
