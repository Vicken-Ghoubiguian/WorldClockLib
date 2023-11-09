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
    printf("Date de changement à l'heure d'hiver concernant l'Australie pour l'année %d\n", utc_date_tm->tm_year + 1900);

    //
    printf("Date de changement à l'heure d'été concernant l'Australie pour l'année %d\n", utc_date_tm->tm_year + 1900);

    //
    return 0;
}