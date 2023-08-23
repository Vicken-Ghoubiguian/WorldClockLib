#include <string.h>
#include <time.h>
#include "dtFRMtz.h"

#define NB_SECONDS_IN_HOURS 3600
#define NB_SECONDS_IN_MINUTES 60
#define __NULL ((void *)0)

int getIndexFromTzArray(char* timezone)
{
	char* tzArray[] = {	"UTC",

						// CI, BF, GH, GM, GN, IS, ML, MR, SH, SL, SN, TG
						"Africa/Abidjan",

						// DZ
						"Africa/Algiers",

						// GW
						"Africa/Bissau",

						// KR
						"Asia/Seoul",

						// KP
						"Asia/Pyongyang",

						// CN
						"Asia/Shanghai", 
						"Asia/Urumqi",

						// ZA, LS, SZ
						"Africa/Johannesburg",

						// SS
						"Africa/Juba",

						// SD
						"Africa/Khartoum",

						// NG, AO, BJ, CD, CF, CG, CM, GA, GQ, NE
						"Africa/Lagos",

						// MZ, BI, BW, CD, MW, RW, ZM, ZW
						"Africa/Maputo",

						// LR
						"Africa/Monrovia",

						// KE, DJ, ER, ET, KM, MG, SO, TZ, UG, YT
						"Africa/Nairobi",

						// TD
						"Africa/Ndjamena",

						// ST
						"Africa/Sao_Tome",

						// LY
						"Africa/Tripoli",

						// TN
						"Africa/Tunis",

						// NA
						"Africa/Windhoek",

						// BR
						"America/Araguaina",

						// AR
						"America/Argentina/Buenos_Aires",
						"America/Argentina/Catamarca",
						"America/Argentina/Cordoba",
						"America/Argentina/Jujuy",
						"America/Argentina/La_Rioja",
						"America/Argentina/Mendoza",
						"America/Argentina/Rio_Gallegos",
						"America/Argentina/San_Juan",
						"America/Argentina/San_Luis",
						"America/Argentina/Tucuman",
						"America/Argentina/Ushuaia",

						// RU
						"Europe/Moscow",
						"Asia/Anadyr",
						"Asia/Barnaul",
						"Asia/Chita",
						"Asia/Irkutsk",
						"Asia/Kamchatka",
						"Asia/Khandyga",
						"Asia/Krasnoyarsk",
						"Asia/Magadan",
						"Asia/Novokuznetsk",
						"Asia/Novosibirsk",
						"Asia/Omsk",
						"Asia/Sakhalin",
						"Asia/Srednekolymsk",
						"Asia/Tomsk",
						"Asia/Ust-Nera",
						"Asia/Vladivostok",
						"Asia/Yakutsk",
						"Asia/Yekaterinburg",
						"Europe/Kaliningrad",
						"Europe/Kirov",
						"Europe/Samara",
						"Europe/Saratov",
						"Europe/Simferopol",
						"Europe/Ulyanovsk",

						// WS
						"Pacific/Apia",

						// PG
						"Pacific/Bougainville",

						// VU
						"Pacific/Efate",

						// TK
						"Pacific/Fakaofo",

						// FJ
						"Pacific/Fiji",

						// EC
						"Pacific/Galapagos",

						// PF
						"Pacific/Gambier",

						// SB, FM
						"Pacific/Guadalcanal",

						// GU, MP
						"Pacific/Guam",

						// US
						"Pacific/Honolulu",

						// KI
						"Pacific/Kanton",
						"Pacific/Kiritimati",

						// FM
						"Pacific/Kosrae",

						// MH
						"Pacific/Kwajalein",

						// PF
						"Pacific/Marquesas",
						"Pacific/Tahiti",

						// NR
						"Pacific/Nauru",

						// NU
						"Pacific/Niue",

						// NC
						"Pacific/Noumea",

						// AS, UM
						"Pacific/Pago_Pago",

						// PW
						"Pacific/Palau",

						// PN
						"Pacific/Pitcairn",

						// PG, AQ, FM
						"Pacific/Port_Moresby",

						// CK
						"Pacific/Rarotonga",

						// KI, MH, TV, UM, WF
						"Pacific/Tarawa",

						// TO
						"Pacific/Tongatapu"
					};
     
    int tzArrayLen = sizeof tzArray / sizeof tzArray[0];
    int index = -1;
     
    for (int i = 0; i < tzArrayLen; i++) {
        if (tzArray[i] == timezone) {
            index = i;
            break;
        }
    }

	return index;
}

time_t getDateTime_Epoch(char* timezone) {

	time_t tmz_now;
	time_t utc_now = time(NULL);
	int tzIndex = getIndexFromTzArray(timezone);

	switch(tzIndex)
	{
		// UTC
		case 0:
			tmz_now = utc_now + (0 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Abidjan
		case 1:
			tmz_now = utc_now + (0 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Algiers
		case 2:
			tmz_now = utc_now + (1 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Bissau
		case 3:
			tmz_now = utc_now + (1 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Seoul
		case 4:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Pyongyang
		case 5:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Shanghai
		case 6:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Urumqi
		case 7:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Johannesburg
		case 8:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Juba
		case 9:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Khartoum
		case 10:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Lagos
		case 11:
			tmz_now = utc_now + (1 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Maputo
		case 12:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Monrovia
		case 13:
			tmz_now = utc_now + (0 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Nairobi
		case 14:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Ndjamena
		case 15:
			tmz_now = utc_now + (1 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Sao_Tome
		case 16:
			tmz_now = utc_now + (0 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Tripoli
		case 17:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Tunis
		case 18:
			tmz_now = utc_now + (1 * NB_SECONDS_IN_HOURS);
			break;
		// Africa/Windhoek
		case 19:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// America/Araguaina
		case 20:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Buenos_Aires
		case 21:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Catamarca
		case 22:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Cordoba
		case 23:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Jujuy
		case 24:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/La_Rioja
		case 25:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Mendoza
		case 26:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Rio_Gallegos
		case 27:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Salta
		case 28:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/San_Juan
		case 29:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/San_Luis
		case 30:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Tucuman
		case 31:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Ushuaia
		case 32:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Moscow
		case 33:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Anadyr
		case 34:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Barnaul
		case 35:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Chita
		case 35:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Irkutsk
		case 36:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kamchatka
		case 37:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Khandyga
		case 38:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Krasnoyarsk
		case 39:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Magadan
		case 40:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novokuznetsk
		case 41:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novosibirsk
		case 42:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Omsk
		case 43:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Sakhalin
		case 44:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Srednekolymsk
		case 45:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tomsk
		case 46:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ust-Nera
		case 47:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Vladivostok
		case 48:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yakutsk
		case 49:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yekaterinburg
		case 50:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kaliningrad
		case 51:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kirov
		case 52:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Samara
		case 53:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Saratov
		case 54:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Simferopol
		case 55:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Ulyanovsk
		case 55:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Apia
		case 56:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Bougainville
		case 57:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Efate
		case 58:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fakaofo
		case 59:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fiji
		case 60:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Galapagos
		case 61:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Gambier
		case 62:
			tmz_now = utc_now + (-9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guadalcanal
		case 63:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guam
		case 63:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Honolulu
		case 64:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kanton
		case 65:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kiritimati
		case 66:
			tmz_now = utc_now + (14 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kosrae
		case 67:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kwajalein
		case 68:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Marquesas
		case 69:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Pacific/Tahiti
		case 70:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Nauru
		case 71:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Niue
		case 72:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Noumea
		case 73:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pago_Pago
		case 74:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Palau
		case 75:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pitcairn
		case 76:
			tmz_now = utc_now + (-8 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Port_Moresby
		case 77:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Rarotonga
		case 78:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tarawa
		case 79:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tongatapu
		case 80:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// No available timezone
		default:
			tmz_now = -1;
	}

	return tmz_now;
}

struct tm *getDateTime_Tm(char* timezone) {

	time_t dtFromUTC = getDateTime_Epoch(timezone);
	if(dtFromUTC != -1)
	{
		return gmtime(&dtFromUTC);
	}
	else
	{
		return __NULL;
	}
}