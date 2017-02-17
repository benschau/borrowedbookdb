#ifndef DATE_H_
#define DATE_H_

#define MAX_DATE_LEN 10

#include <stdbool.h>

static const int monthdays[] = {
    31, // Jan
    28, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun 
    31, // Jul 
    31, // Aug
    30, // Sept
    31, // Oct
    30, // Nov
    31  // Dec
};

typedef struct Dates {
    int day;
    int month;
    int year;
} Date;

char* getdate(Date* date);

bool valid_day(int day, int month);

bool valid_month(int month);

bool valid_year(int year);

Date* initdate(int day, int month, int year);

#endif
