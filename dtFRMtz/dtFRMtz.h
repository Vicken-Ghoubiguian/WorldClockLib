#ifndef DTFRMTZ
#define DTFRMTZ

#include <time.h>

int getIndexFromTzArray(char* timezone);
time_t getDateTime_Epoch(char* timezone);
struct tm *getDateTime_Tm(char* timezone);

#endif