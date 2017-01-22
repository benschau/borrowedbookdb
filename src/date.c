#include <stdio.h>
#include <stdlib.h>

#include "date.h"

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
bool valid_day(int day){
}

/** 
 * Check if the given month is valid.
 */
bool valid_month(int month){
}

/**
 * Check if the given year is valid.
 */
bool valid_year(int year){
}
