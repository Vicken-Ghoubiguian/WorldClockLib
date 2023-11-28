#include <time.h>
#include "dstCalculous.h"

//
//#define NB_SECONDS_IN_DAY 86400

//
/*time_t first_sunday_in_choosen_month(time_t today, int month, int hour)
{
    //
    struct tm *date_tm;
    time_t date_timestamp;
    int i;

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
    while(1)
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

			//
            if(date_tm->tm_wday == 0 && date_tm->tm_mon == month)
            {
                i = i + 1;
            }
        }
    }

    //
    return date_timestamp;
}*/
