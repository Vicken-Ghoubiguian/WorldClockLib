#include <string.h>
#include <time.h>
#include "dtFRMtz.h"

#define NB_MINUTES_IN_HOURS 3600
#define __NULL ((void *)0)

int getIndexFromTzArray(char* timezone)
{
	char* tzArray[] = {	"UTC", 
						"Africa/Abidjan", 
						"Africa/Algiers", 
						"Africa/Bissau", 
						"Asia/Seoul", 
						"Asia/Pyongyang", 
						"Asia/Shanghai", 
						"Asia/Urumqi",
						"Africa/Johannesburg",
						"Africa/Juba",
						"Africa/Khartoum",
						"Africa/Lagos",
						"Africa/Maputo",
						"Africa/Monrovia",
						"Africa/Nairobi",
						"Africa/Ndjamena",
						"Africa/Sao_Tome",
						"Africa/Tripoli",
						"Africa/Tunis",
						"Africa/Windhoek",
						"America/Araguaina",
						"America/Argentina/Buenos_Aires",
						"America/Argentina/Catamarca"
					};
     
    int tzArrayLen = sizeof tzArray / sizeof tzArray[0];
    int index = -1;
     
    for (int i = 0; i < tzArrayLen; i++) {
        if (tzArray[i] == timezone) {
            index = i;
            break;
        }
    }

	return index;
}

time_t getDateTime_Epoch(char* timezone) {

	time_t tmz_now;
	time_t utc_now = time(NULL);
	int tzIndex = getIndexFromTzArray(timezone);

	switch(tzIndex)
	{
		// UTC
		case 0:
			tmz_now = utc_now + (0 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Abidjan
		case 1:
			tmz_now = utc_now + (0 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Algiers
		case 2:
			tmz_now = utc_now + (1 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Bissau
		case 3:
			tmz_now = utc_now + (1 * NB_MINUTES_IN_HOURS);
			break;
		// Asia/Seoul
		case 4:
			tmz_now = utc_now + (9 * NB_MINUTES_IN_HOURS);
			break;
		// Asia/Pyongyang
		case 5:
			tmz_now = utc_now + (9 * NB_MINUTES_IN_HOURS);
			break;
		// Asia/Shanghai
		case 6:
			tmz_now = utc_now + (8 * NB_MINUTES_IN_HOURS);
			break;
		// Asia/Urumqi
		case 7:
			tmz_now = utc_now + (6 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Johannesburg
		case 8:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Juba
		case 9:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Khartoum
		case 10:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Lagos
		case 11:
			tmz_now = utc_now + (1 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Maputo
		case 12:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Monrovia
		case 13:
			tmz_now = utc_now + (0 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Nairobi
		case 14:
			tmz_now = utc_now + (3 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Ndjamena
		case 15:
			tmz_now = utc_now + (1 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Sao_Tome
		case 16:
			tmz_now = utc_now + (0 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Tripoli
		case 17:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Tunis
		case 18:
			tmz_now = utc_now + (1 * NB_MINUTES_IN_HOURS);
			break;
		// Africa/Windhoek
		case 19:
			tmz_now = utc_now + (2 * NB_MINUTES_IN_HOURS);
			break;
		// America/Araguaina
		case 20:
			tmz_now = utc_now + (-3 * NB_MINUTES_IN_HOURS);
			break;
		// America/Argentina/Buenos_Aires
		case 21:
			tmz_now = utc_now + (-3 * NB_MINUTES_IN_HOURS);
			break;
		// America/Argentina/Catamarca
		case 21:
			tmz_now = utc_now + (-3 * NB_MINUTES_IN_HOURS);
			break;
		// No available timezone
		default:
			tmz_now = -1;
	}

	return tmz_now;
}

struct tm *getDateTime_Tm(char* timezone) {

	time_t dtFromUTC = getDateTime_Epoch(timezone);
	if(dtFromUTC != -1)
	{
		return gmtime(&dtFromUTC);
	}
	else
	{
		return __NULL;
	}
}