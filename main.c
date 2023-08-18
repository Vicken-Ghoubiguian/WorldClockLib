#include <stdio.h>
#include "./dtFRMtz/dtFRMtz.h"

int main() {

	/*time_t timestampGetDateTime = getDateTime_Epoch("Africa/Algiers");
	printf("Current UTC time is %s\n", ctime(&timestampGetDateTime));*/

	struct tm *tmGetDateTime = getDateTime_Tm("Asia/Shanghai");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	return 0;
}