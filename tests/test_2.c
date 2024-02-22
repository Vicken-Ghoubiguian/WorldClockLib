#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "../WorldClockLib/dstCalculous/dstCalculous.h"

// Definition of the global variable 'NB_SECONDS_IN_DAY' which contains the number of seconds in a day
#define NB_SECONDS_IN_DAY 86400

// Defining the enumeration named "numeral" to specify which iteration of a week day in a month is requested
enum numeral {
    FIRST, // First iteration of a week day in a month
    SECOND, // Second iteration of a week day in a month
    THIRD, // Third iteration of a week day in a month
    BEFORE_LAST, // Penultimate iteration of a week day in a month
    LAST // Last iteration of a week day in a month
};

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(time_t today, int month, int wday, int hour, int minute, int second, enum numeral num)
{
    //
    int i = 0;
    int condition = 0;

    // Definition of the 'date_tm' and the 'date_timestamp' variables
    struct tm *date_tm;
    time_t date_timestamp;

    //
    date_tm = gmtime(&today);

    // Initialization of the 'date_tm' to make all the necessary calculations
    date_tm->tm_mday = 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = minute;
    date_tm->tm_sec = second;

    //
    if(num == LAST || num == BEFORE_LAST){ date_tm->tm_mon = month + 1; }
    else{ date_tm->tm_mon = month; }

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    if((num == LAST) || (num == FIRST))
    {
        //
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
    }
    //
    else if(num == BEFORE_LAST)
    {
        //
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
    }
    //
    else if(num == SECOND)
    {
        //
        condition = date_tm->tm_wday != wday || i != 1;
    }
    //
    else if(num == THIRD)
    {
        //
        condition = date_tm->tm_wday != wday || i != 2;
    }

    //
    if((num == LAST) && (date_tm->tm_wday == 0))
    {
        //
        date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;

        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    while(condition)
    {
        //
        if(num == BEFORE_LAST)
        {
            //
            if(date_tm->tm_wday == wday && date_tm->tm_mon == month)
            {
                //
                i = i + 1;
            }
        }
        //
        else if(num == SECOND || num == THIRD)
        {
            //
            if(date_tm->tm_wday == wday)
            {
                //
                i = i + 1;
            }
        }

        //
        if(num == LAST || num == BEFORE_LAST)
        {
            //
            date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;
        }
        //
        else
        {
            //
            date_timestamp = date_timestamp + NB_SECONDS_IN_DAY;
        }

        //
        date_tm = gmtime(&date_timestamp);

        //
        if((num == LAST) || (num == FIRST))
        {
            //
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
        }
        //
        else if(num == BEFORE_LAST)
        {
            //
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
        }
        //
        else if(num == SECOND)
        {
            //
            condition = date_tm->tm_wday != wday || i != 1;
        }
        //
        else if(num == THIRD)
        {
            //
            condition = date_tm->tm_wday != wday || i != 2;
        }
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
    time_t datetime_for_winter_in_australia = wished_wday_in_choosen_month(utc_today, 3, 0, 3, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of change to summer time for Australia at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_australia = wished_wday_in_choosen_month(utc_today, 9, 0, 2, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("=================================================");

    //
    printf("\n================== New Zealand ==================\n");

    //
    printf("Date of change to winter time for New Zealand at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_new_zealand = wished_wday_in_choosen_month(utc_today, 3, 0, 3, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_new_zealand)));

    //
    printf("Date of change to summer time for New Zealand at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_new_zealand = wished_wday_in_choosen_month(utc_today, 8, 0, 2, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_new_zealand)));

    //
    printf("=================================================");

    //
    printf("\n================== Britain, Ireland, France, Spain, Italy, Germany and Portugal ==================\n");

    //
    printf("Date of change to winter time for Britain at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_britain = wished_wday_in_choosen_month(utc_today, 9, 0, 3, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_britain)));

    //
    printf("Date of change to summer time for Britain at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_britain = wished_wday_in_choosen_month(utc_today, 2, 0, 2, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_britain)));

    //
    printf("=================================================");

    //
    printf("\n================== United States of America ==================\n");

    //
    printf("Date of change to winter time for United States of America (USA) at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_usa = wished_wday_in_choosen_month(utc_today, 2, 0, 2, 0, 0, SECOND);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_usa)));

    //
    printf("Date of change to summer time for United States of America (USA) at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_usa = wished_wday_in_choosen_month(utc_today, 10, 0, 2, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_usa)));

    //
    printf("=================================================");

    //
    printf("\n================== Egypt ==================\n");

    // ====> winter

    //
    printf("Date of change to summer time for Egypt at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_egypt = wished_wday_in_choosen_month(utc_today, 3, 5, 0, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_egypt)));

    //
    printf("=================================================");

    //
    printf("\n================== Canada ==================\n");

    //
    printf("Date of change to winter time for Canada of America (USA) at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_canada = wished_wday_in_choosen_month(utc_today, 2, 0, 2, 0, 0, SECOND);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_canada)));

    //
    printf("Date of change to summer time for Canada at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_canada = wished_wday_in_choosen_month(utc_today, 10, 0, 2, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_canada)));

    //
    printf("=================================================");

    //
    printf("\n================== Paraguay ==================\n");

    // ====> winter

    //
    printf("Date of change to winter time for Paraguay at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_winter_in_paraguay = wished_wday_in_choosen_month(utc_today, 9, 0, 1, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_paraguay)));

    //
    printf("Date of change to summer time for Paraguay at the year %d : ", utc_date_tm->tm_year + 1900);
    time_t datetime_for_summer_in_paraguay = wished_wday_in_choosen_month(utc_today, 9, 0, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_paraguay)));

    //
    printf("=================================================");

    //
    printf("\n");

    //
    return 0;
}