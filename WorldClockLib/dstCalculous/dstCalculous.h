#ifndef DSTCALCULOUS
#define DSTCALCULOUS

#include <time.h>

// Definition of the global variable 'NB_SECONDS_IN_DAY' which contains the number of seconds in a day
#define NB_SECONDS_IN_DAY 86400

// Defining the enumeration named "numeral" to specify which iteration of a week day in a month is requested
enum numeral {
    FIRST, // First iteration of a week day in a month
    SECOND, // Second iteration of a week day in a month
    THIRD, // Third iteration of a week day in a month
    BEFORE_LAST, // Penultimate iteration of a week day in a month
    LAST // Last iteration of a week day in a month
};

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num);

#endif