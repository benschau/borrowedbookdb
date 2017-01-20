#ifndef DATE_H_
#define DATE_H_

#define MAX_DATE_LEN 10

typedef struct Dates {
    int day;
    int month;
    int year;
} Date;

char* getdate(Date* date);

char* valid_day(int day);

char* valid_month(int month);

char* valid_year(int year);

#endif
