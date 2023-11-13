#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../WorldClockLib/dtFRMtz/dtFRMtz.h"

//
int main() {

    //
    time_t utc_today = time(NULL);

    //
    struct tm *utc_date_tm = gmtime(&utc_today);

    //
    printf("Date of change to winter time for Australia at the year %d\n", utc_date_tm->tm_year + 1900);
    //first_sunday_in_april(utc_now, 2);

    //
    printf("Date of change to summer time for Australia at the year %d\n", utc_date_tm->tm_year + 1900);
    //

    //
    return 0;
}