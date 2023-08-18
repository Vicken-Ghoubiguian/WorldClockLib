#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define __NULL ((void *)0)

int getIndexFromTzArray(char* timezone)
{
	char* tzArray[] = {"UTC", "Africa/Abidjan", "Africa/Algiers", "Africa/Bissau", "Asia/Seoul", "Asia/Pyongyang"};
     
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
		case 0:
			tmz_now = utc_now;
			break;
		case 1:
			tmz_now = utc_now;
			break;
		case 2:
			tmz_now = utc_now + 3600;
			break;
		case 3:
			tmz_now = utc_now + 3600;
			break;
		case 4:
			tmz_now = utc_now + 32400;
			break;
		case 5:
			tmz_now = utc_now + 32400;
			break;
		default:
			tmz_now = -1;
	}

	return tmz_now;

	/*if(strcmp(timezone, "UTC") == 0)
	{
		return utc_now;
	}
	else if(strcmp(timezone, "Africa/Abidjan") == 0)
	{
		return utc_now;
	}
	else if(strcmp(timezone, "Africa/Algiers") == 0)
        {
                return utc_now + 3600;
        }
	else if(strcmp(timezone, "Africa/Bissau") == 0)
        {
                return utc_now + 3600;
        }
	else if(strcmp(timezone, "Asia/Seoul") == 0)
	{
		return utc_now + 32400;
	}
	else if(strcmp(timezone, "Asia/Pyongyang") == 0)
	{
		return utc_now + 32400;
	}
	else
	{
		return -1;
	}*/
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

	struct tm *tmGetDateTime = getDateTime_Tm("Africa/Algiers");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	return 0;
}
