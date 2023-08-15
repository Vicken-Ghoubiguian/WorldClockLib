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
                return utc_now + 3600;
        }
	else if(strcmp(timezone, "Africa/Bissau") == 0)
        {
                return utc_now + 3600;
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
        else
        {
                return __NULL;
        }
}

int main() {

	printf("Current UTC time is  %ld (EPOCH)\n", getDateTime_Epoch("Africa/Algiers"));

	return 0;
}
