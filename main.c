#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t getDateTime_Epoch() {

	time_t utc_now = time(NULL);

	return utc_now;
}

struct tm *getDateTime_Tm() {

	time_t utc_now = time(NULL);

	return gmtime(&utc_now);
}

int main() {

	printf("Current UTC time is  %ld (EPOCH)\n", getDateTime_Epoch());

	return 0;
}
