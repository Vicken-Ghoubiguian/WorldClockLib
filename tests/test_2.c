#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../WorldClockLib/dstCalculous/dstCalculous.h"

#define NB_SECONDS_IN_DAY 86400

time_t first_sunday_in_choosen_month(time_t today, int month, int hour)
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
    /*while(1)
    {
        //
        if(date_tm->tm_wday == 0 && date_tm->tm_mon == month)
        {
            break;
		}
		else
		{
			//
            date_timestamp = date_timestamp + NB_SECONDS_IN_DAY;
			
            //
            date_tm = gmtime(&date_timestamp);
        }
    }*/

    while(date_tm->tm_wday != 0 /*&& date_tm->tm_mon != month*/)
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
    time_t datetime_for_winter_in_australia = first_sunday_in_choosen_month(utc_today, 3, 3);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of change to summer time for Australia at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_australia = first_sunday_in_choosen_month(utc_today, 9, 2);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("\n");

    //
    return 0;
}