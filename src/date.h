#ifndef DATE_H_
#define DATE_H_

#define MAX_DATE_LEN 10

#include <stdbool.h>

typedef struct Dates {
    int day;
    int month;
    int year;
} Date;

char* getdate(Date* date);

bool valid_day(int day);

bool valid_month(int month);

bool valid_year(int year);

Date* initdate(int day, int month, int year);

#endif
