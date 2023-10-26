# WorldClockLib

## Contents

## Introduction

Below is the instruction to compile the library with the example program titled classic `main.c` :
```bash
gcc main.c ../WorldClockLib/dtFRMtz/dtFRMtz.c -o main
```

Below is an example of a minimal C program to use this library available in `tests` :
```c
#include <stdio.h>
#include <stdlib.h>
#include "../WorldClockLib/dtFRMtz/dtFRMtz.h"

int main() {

	/*time_t timestampGetDateTime = getDateTime_Epoch("Africa/Algiers");
	printf("Current UTC time is %s\n", ctime(&timestampGetDateTime));*/

	char* tz = malloc(30);
	printf("Veuillez saisir le timezone que vous voulez : ");
	scanf("%s", tz);
	printf("\n");

	printf("%s", tz);

	struct tm *tmGetDateTime = getDateTime_Tm("Pacific/Marquesas");
	printf("Current UTC time is %s\n", asctime(tmGetDateTime));

	free(tz);

	return 0;
}
```