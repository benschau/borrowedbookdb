#include <stdio.h>
#include <stdlib.h>

#include "date.h"

char* getdate(Date* date){
    char* datestr = malloc(MAX_DATE_LEN + sizeof(char));
    
    snprintf(datestr, MAX_DATE_LEN, "%d-%d-%d", date->month, date->day, date->year); 
    return(datestr);
}

char* valid_day(int day){
}

char* valid_month(int month){
}

char* valid_year(int year){
}
