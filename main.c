#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define __NULL ((void *)0)

int getIndexFromTzArray(char* timezone)
{
	char* tzArray[] = {"UTC", "Africa/Abidjan", "Africa/Algiers", "Africa/Bissau", "Asia/Seoul", "Asia/Pyongyang", "Asia/Shanghai", "Asia/Urumqi"};
     
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

	struct tm *tmGetDateTime = getDateTime_Tm("Asia/Shanghai");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	return 0;
}
