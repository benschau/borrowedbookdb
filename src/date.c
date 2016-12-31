#include <stdio.h>

#include "date.h"

char* getdate(Date* date){
    char* datestr;
    
    snprintf(datestr, MAX_DATE_LEN, "%d-%d-%d", date->month, date->day, date->year); 
    return(datestr);
}

