#include <stdio.h>
#include "./dtFRMtz/dtFRMtz.h"

int main() {

	/*time_t timestampGetDateTime = getDateTime_Epoch("Africa/Algiers");
	printf("Current UTC time is %s\n", ctime(&timestampGetDateTime));*/

	/*char tz[20];
	printf("Veuillez saisir le timezone que vous voulez : ");
	scanf("%s", tz);
	printf("\n");*/

	struct tm *tmGetDateTime = getDateTime_Tm("Pacific/Marquesas");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	return 0;
}