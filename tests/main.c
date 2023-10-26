#include <stdio.h>
#include <stdlib.h>
#include "./WorldClockLib/dtFRMtz/dtFRMtz.h"

int main() {

	//
	char* tz = malloc(30);
	printf("Veuillez saisir le timezone que vous voulez : ");
	scanf("%s", tz);
	printf("\n");

	//
	printf("%s", tz);

	//
	time_t timestampGetDateTime = getDateTime_Epoch("America/Sao_Paulo");
	printf("Current UTC time is %ld\n", timestampGetDateTime);

	//
	struct tm *tmGetDateTime = getDateTime_Tm("America/Sao_Paulo");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	//
	free(tz);

	//
	return 0;
}