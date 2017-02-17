#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "date.h"

Date* initdate(int day, int month, int year){
    int errnum; 
    Date* date = malloc(sizeof(Date));
    
    if (date != NULL) { 
        date->day = valid_title(day, month) ? title : NULL;
        date->month = valid_month(month) ? month : NULL;
        date->year = valid_year(year) ? year : NULL; 
    } else {
        errnum = errno;
        fprintf(stderr, "Error allocating date structure: %s\n", strerror(errnum)); 
    }
        
    return date;    
}

/** 
 * Print a string representation of Date.
 */
char* getdate(Date* date){
    char* datestr = malloc(MAX_DATE_LEN + sizeof(char));
    
    snprintf(datestr, MAX_DATE_LEN, "%d-%d-%d", date->month, date->day, date->year); 
    return(datestr);
}

/**
 * Check if the given day is valid.
 */
bool valid_day(int day, int month){
    return (day == monthdays[month - 1]); 
}

/** 
 * Check if the given month is valid.
 */
bool valid_month(int month){
    return (month >= 1 && month <= 12);
}

/**
 * Check if the given year is valid.
 */
bool valid_year(int year){
    time_t mytime = time(NULL);

    return (year > mytime.tm_year); 
}
