#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define __NULL ((void *)0)

time_t getDateTime_Epoch(char* timezone) {

	time_t utc_now = time(NULL);

	if(strcmp(timezone, "UTC") == 0)
	{
		return utc_now;
	}
	else if(strcmp(timezone, "Africa/Abidjan") == 0)
	{
		return utc_now;
	}
	else if(strcmp(timezone, "Africa/Algiers") == 0)
        {
		printf("%ld", utc_now + 3600);
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
	}
}

struct tm *getDateTime_Tm(char* timezone) {

	time_t utc_now = time(NULL);
	time_t tz_now;

	if(strcmp(timezone, "UTC") == 0)
        {
                return gmtime(&utc_now);
        }
	else if(strcmp(timezone, "Africa/Abidjan") == 0)
        {
                return gmtime(&utc_now);
        }
        else if(strcmp(timezone, "Africa/Algiers") == 0)
        {
                tz_now = utc_now + 3600;
		return gmtime(&tz_now);
        }
        else if(strcmp(timezone, "Africa/Bissau") == 0)
        {
                tz_now = utc_now + 3600;
		return gmtime(&tz_now);
        }
	else if(strcmp(timezone, "Asia/Seoul") == 0)
        {
                tz_now = utc_now + 32400;
		return gmtime(&tz_now);
        }
        else if(strcmp(timezone, "Asia/Pyongyang") == 0)
        {
                tz_now = utc_now + 32400;
		return gmtime(&tz_now);
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
