#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../WorldClockLib/dstCalculous/dstCalculous.h"

#define NB_SECONDS_IN_DAY 86400

enum numeral {
    FIRST,
    /*SECOND,
    THIRD,
    BEFORE_LAST,*/
    LAST
};

// ***************************************************************************************

time_t wished_wday_in_choosen_month(time_t today, int month, int wday, int hour, enum numeral num)
{
    //
    struct tm *date_tm;
    time_t date_timestamp;

    //
    date_tm = gmtime(&today);

    //
    date_tm->tm_mday = 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

    //
    if(num == LAST){ date_tm->tm_mon = month + 1; }
    else{ date_tm->tm_mon = month; }

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    if(num == LAST)
    {
        //
        if(date_tm->tm_wday == 0)
        {
            //
            date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;

            //
            date_tm = gmtime(&date_timestamp);
        }
    }

    //
    while(date_tm->tm_wday != wday)
    {
        //
        /*switch(num)
        {
            case FIRST: date_timestamp = date_timestamp + NB_SECONDS_IN_DAY; break;
            case LAST: date_timestamp = date_timestamp - NB_SECONDS_IN_DAY; break;
        }*/

        //
        if(num == LAST){ date_timestamp = date_timestamp - NB_SECONDS_IN_DAY; }
        else{ date_timestamp = date_timestamp + NB_SECONDS_IN_DAY; }
                
        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    return date_timestamp;
}

// ***************************************************************************************

time_t last_wday_in_choosen_month(time_t today, int month, int wday, int hour)
{
    //
    struct tm *date_tm;
    time_t date_timestamp;

    //
    date_tm = gmtime(&today);

    //
    date_tm->tm_mday = 1;
    date_tm->tm_mon = month + 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    if(date_tm->tm_wday == 0)
    {
        //
        date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;

        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    while(date_tm->tm_wday != wday)
    {
        //
        date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;
                
        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    return date_timestamp;
}

time_t first_wday_in_choosen_month(time_t today, int month, int wday, int hour)
{
    //
    struct tm *date_tm;
    time_t date_timestamp;

    //
    date_tm = gmtime(&today);

    //
    date_tm->tm_mday = 1;
    date_tm->tm_mon = month;
    date_tm->tm_hour = hour;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    while(date_tm->tm_wday != wday)
    {
        //
        date_timestamp = date_timestamp + NB_SECONDS_IN_DAY;
			
        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    return date_timestamp;
}

//
int main() {

    //
    time_t utc_today = time(NULL);

    //
    struct tm *utc_date_tm = gmtime(&utc_today);

    //
    printf("\n================== Australia ==================\n");

    //
    printf("Date of change to winter time for Australia at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_australia = first_wday_in_choosen_month(utc_today, 3, 0, 3);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of change to summer time for Australia at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_australia = first_wday_in_choosen_month(utc_today, 9, 0, 2);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("=================================================");

    //
    printf("\n================== New Zealand ==================\n");

    //
    printf("Date of change to winter time for New Zealand at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_new_zealand = first_wday_in_choosen_month(utc_today, 3, 0, 3);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_new_zealand)));

    //
    printf("Date of change to summer time for New Zealand at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_new_zealand = last_wday_in_choosen_month(utc_today, 8, 0, 2);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_new_zealand)));

    //
    printf("=================================================");

    //
    printf("\n");

    //
    return 0;
}