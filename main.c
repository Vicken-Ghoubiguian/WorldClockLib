#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	time_t utc_now = time(NULL);

	printf("Current UTC time is  %ld (EPOCH)\n", utc_now);

	return 0;
}
