#include <stdio.h>
#include <stdlib.h>
#include "./dtFRMtz/dtFRMtz.h"

int main() {

	/*time_t timestampGetDateTime = getDateTime_Epoch("Africa/Algiers");
	printf("Current UTC time is %s\n", ctime(&timestampGetDateTime));*/

	char* tz = malloc(30);
	printf("Veuillez saisir le timezone que vous voulez : ");
	scanf("%s", tz);
	printf("\n");

	printf("%s", tz);

	struct tm *tmGetDateTime = getDateTime_Tm("Asia/Colombo");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	free(tz);

	return 0;
}