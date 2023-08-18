#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
						"Africa/Windhoek"
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
			tmz_now = utc_now;
			break;
		// Africa/Abidjan
		case 1:
			tmz_now = utc_now;
			break;
		// Africa/Algiers
		case 2:
			tmz_now = utc_now + 3600;
			break;
		// Africa/Bissau
		case 3:
			tmz_now = utc_now + 3600;
			break;
		// Asia/Seoul
		case 4:
			tmz_now = utc_now + 32400;
			break;
		// Asia/Pyongyang
		case 5:
			tmz_now = utc_now + 32400;
			break;
		// Asia/Shanghai
		case 6:
			tmz_now = utc_now + 28800;
			break;
		// Asia/Urumqi
		case 7:
			tmz_now = utc_now + 21600;
			break;
		// Africa/Johannesburg
		case 8:
			tmz_now = utc_now + 7200;
			break;
		// Africa/Juba
		case 9:
			tmz_now = utc_now + 7200;
			break;
		// Africa/Khartoum
		case 10:
			tmz_now = utc_now + 7200;
			break;
		// Africa/Lagos
		case 11:
			tmz_now = utc_now + 3600;
			break;
		// Africa/Maputo
		case 12:
			tmz_now = utc_now + 7200;
			break;
		// Africa/Monrovia
		case 13:
			tmz_now = utc_now;
			break;
		// Africa/Nairobi
		case 14:
			tmz_now = utc_now + 10800;
			break;
		// Africa/Ndjamena
		case 15:
			tmz_now = utc_now + 3600;
			break;
		// Africa/Sao_Tome
		case 16:
			tmz_now = utc_now;
			break;
		// Africa/Tripoli
		case 17:
			tmz_now = utc_now + 7200;
			break;
		// Africa/Tunis
		case 18:
			tmz_now = utc_now + 3600;
			break;
		// Africa/Windhoek
		case 19:
			tmz_now = utc_now + 7200;
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

int main() {

	/*time_t timestampGetDateTime = getDateTime_Epoch("Africa/Algiers");
	printf("Current UTC time is %s\n", ctime(&timestampGetDateTime));*/

	struct tm *tmGetDateTime = getDateTime_Tm("Africa/Windhoek");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	return 0;
}
