#include <string.h>
#include <time.h>
#include "dtFRMtz.h"

#define NB_SECONDS_IN_HOURS 3600
#define NB_SECONDS_IN_MINUTES 60
#define __NULL ((void *)0)

int getIndexFromTzArray(char* timezone)
{
	char* tzArray[] = {	"Etc/UTC", // 0

						// CI, BF, GH, GM, GN, IS, ML, MR, SH, SL, SN, TG
						"Africa/Abidjan", // 1

						// DZ
						"Africa/Algiers", // 2

						// GW
						"Africa/Bissau", // 3

						// KR
						"Asia/Seoul", // 4

						// KP
						"Asia/Pyongyang", // 5

						// CN
						"Asia/Shanghai", // 6
						"Asia/Urumqi", // 7

						// ZA, LS, SZ
						"Africa/Johannesburg", // 8

						// SS
						"Africa/Juba", // 9

						// SD
						"Africa/Khartoum", // 10

						// NG, AO, BJ, CD, CF, CG, CM, GA, GQ, NE
						"Africa/Lagos", // 11

						// MZ, BI, BW, CD, MW, RW, ZM, ZW
						"Africa/Maputo", // 12

						// LR
						"Africa/Monrovia", // 13

						// KE, DJ, ER, ET, KM, MG, SO, TZ, UG, YT
						"Africa/Nairobi", // 14

						// TD
						"Africa/Ndjamena", // 15

						// ST
						"Africa/Sao_Tome", // 16

						// LY
						"Africa/Tripoli", // 17

						// TN
						"Africa/Tunis", // 18

						// NA
						"Africa/Windhoek", // 19

						// BR
						"America/Araguaina", // 20

						// AR
						"America/Argentina/Buenos_Aires", // 21
						"America/Argentina/Catamarca", // 22
						"America/Argentina/Cordoba", // 23
						"America/Argentina/Jujuy", // 24
						"America/Argentina/La_Rioja", // 25
						"America/Argentina/Mendoza", // 26
						"America/Argentina/Rio_Gallegos", // 27
						"America/Argentina/Salta", //28
						"America/Argentina/San_Juan", // 29
						"America/Argentina/San_Luis", // 30
						"America/Argentina/Tucuman", // 31
						"America/Argentina/Ushuaia", // 32

						// RU
						"Europe/Moscow", // 33
						"Asia/Anadyr", // 34
						"Asia/Barnaul", // 35
						"Asia/Chita", // 36
						"Asia/Irkutsk", // 37
						"Asia/Kamchatka", // 38
						"Asia/Khandyga", // 39
						"Asia/Krasnoyarsk", // 40
						"Asia/Magadan", // 41
						"Asia/Novokuznetsk", // 42
						"Asia/Novosibirsk", // 43
						"Asia/Omsk", // 44
						"Asia/Sakhalin", // 45
						"Asia/Srednekolymsk", // 46
						"Asia/Tomsk", // 47
						"Asia/Ust-Nera", // 48
						"Asia/Vladivostok", // 49
						"Asia/Yakutsk", // 50
						"Asia/Yekaterinburg", // 51
						"Europe/Kaliningrad", // 52
						"Europe/Kirov", // 53
						"Europe/Samara", // 54
						"Europe/Saratov", // 55
						"Europe/Simferopol", // 56
						"Europe/Ulyanovsk", // 57

						// WS
						"Pacific/Apia", // 58

						// PG
						"Pacific/Bougainville", // 59

						// VU
						"Pacific/Efate", // 60

						// TK
						"Pacific/Fakaofo", // 61

						// FJ
						"Pacific/Fiji", // 62

						// EC
						"Pacific/Galapagos", // 63

						// PF
						"Pacific/Gambier", // 64

						// SB, FM
						"Pacific/Guadalcanal", // 65

						// GU, MP
						"Pacific/Guam", // 66

						// US
						"Pacific/Honolulu", // 67

						// KI
						"Pacific/Kanton", // 68
						"Pacific/Kiritimati", // 69

						// FM
						"Pacific/Kosrae", // 70

						// MH
						"Pacific/Kwajalein", // 71

						// PF
						"Pacific/Marquesas", // 72
						"Pacific/Tahiti", // 73

						// NR
						"Pacific/Nauru", // 74

						// NU
						"Pacific/Niue", // 75

						// NC
						"Pacific/Noumea", // 76

						// AS, UM
						"Pacific/Pago_Pago", // 77

						// PW
						"Pacific/Palau", // 78

						// PN
						"Pacific/Pitcairn", // 79

						// PG, AQ, FM
						"Pacific/Port_Moresby", // 80

						// CK
						"Pacific/Rarotonga", // 81

						// KI, MH, TV, UM, WF
						"Pacific/Tarawa", // 82

						// TO
						"Pacific/Tongatapu", // 83

						// MX
						"America/Bahia_Banderas", // 84
						"America/Cancun", // 85
						"America/Chihuahua", // 86
						"America/Hermosillo", // 87
						"America/Mazatlan", // 88
						"America/Merida", // 89
						"America/Mexico_City", // 90
						"America/Monterrey", // 91
						"America/Ojinaga", // 92
						"America/Ciudad_Juarez", // 93
						"America/Matamoros", // 94
						"America/Tijuana", // 95

						// AQ
						"Antarctica/Casey", // 96
						"Antarctica/Davis", // 97
						"Antarctica/Mawson", // 98
						"Antarctica/Palmer", // 99
						"Antarctica/Rothera", // 100
						"Antarctica/Macquarie", // 101
						"Antarctica/Troll", // 102

						// CV
						"Atlantic/Cape_Verde", // 103

						// GS
						"Atlantic/South_Georgia", // 104

						// FK
						"Atlantic/Stanley", // 105

						// AU
						"Australia/Brisbane", // 106
						"Australia/Darwin", // 107
						"Australia/Eucla", // 108
						"Australia/Lindeman", // 109
						"Australia/Perth", // 110
						"Australia/Sydney", // 111
						"Australia/Melbourne", // 112
						"Australia/Lord_Howe", // 113
						"Australia/Hobart", // 114
						"Australia/Broken_Hill", // 115
						"Australia/Adelaide", // 116

						// MM, CC
						"Asia/Yangon", // 117

						// TH, CX, KH, LA, VN
						"Asia/Bangkok", // 118

						// KG
						"Asia/Bishkek", // 119

						// MN
						"Asia/Choibalsan", // 120
						"Asia/Ulaanbaatar", // 121
						"Asia/Hovd", // 122

						// LK
						"Asia/Colombo", // 123

						// SY
						"Asia/Damascus", // 124

						// BD
						"Asia/Dhaka", // 125

						// TL
						"Asia/Dili", // 126

						// AE, OM, RE, SC, TF
						"Asia/Dubai", // 127

						// TJ
						"Asia/Dushanbe", // 128

						// CY
						"Asia/Famagusta", // 129

						// PS
						"Asia/Gaza", // 130

						// PS
						"Asia/Hebron", // 131

						// VN
						"Asia/Ho_Chi_Minh", // 132

						// HK
						"Asia/Hong_Kong", // 133

						// ID
						"Asia/Jakarta", // 134
						"Asia/Jayapura", // 135
						"Asia/Makassar", // 136
						"Asia/Pontianak", // 137

						// AF
						"Asia/Kabul", // 138

						// PK
						"Asia/Karachi", // 139

						// NP
						"Asia/Kathmandu", // 140

						// QA, BH
						"Asia/Qatar", // 141

						// KZ
						"Asia/Almaty", // 142
						"Asia/Aqtau", // 143
						"Asia/Aqtobe", // 144
						"Asia/Atyrau", // 145
						"Asia/Oral", // 146
						"Asia/Qostanay", // 147
						"Asia/Qyzylorda", // 148

						// PH
						"Asia/Manila", // 149

						// MO
						"Asia/Macau", // 150

						// SA, AQ, KW, YE
						"Asia/Riyadh", // 151

						// UZ
						"Asia/Samarkand", // 152
						"Asia/Tashkent", // 153

						// GE
						"Asia/Tbilisi", // 154

						// IR
						"Asia/Tehran", // 155

						// BT
						"Asia/Thimphu", // 156

						// JP
						"Asia/Tokyo", // 157

						// AM
						"Asia/Yerevan", // 158

						// TR
						"Europe/Istanbul", // 159

						// BY
						"Europe/Minsk", // 160

						// BZ
						"America/Belize", // 161

						// CO
						"America/Bogota" // 162
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
		case 36:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Irkutsk
		case 37:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kamchatka
		case 38:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Khandyga
		case 39:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Krasnoyarsk
		case 40:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Magadan
		case 41:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novokuznetsk
		case 42:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novosibirsk
		case 43:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Omsk
		case 44:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Sakhalin
		case 45:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Srednekolymsk
		case 46:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tomsk
		case 47:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ust-Nera
		case 48:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Vladivostok
		case 49:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yakutsk
		case 50:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yekaterinburg
		case 51:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kaliningrad
		case 52:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kirov
		case 53:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Samara
		case 54:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Saratov
		case 55:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Simferopol
		case 56:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Ulyanovsk
		case 57:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Apia
		case 58:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Bougainville
		case 59:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Efate
		case 60:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fakaofo
		case 61:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fiji
		case 62:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Galapagos
		case 63:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Gambier
		case 64:
			tmz_now = utc_now + (-9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guadalcanal
		case 65:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guam
		case 66:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Honolulu
		case 67:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kanton
		case 68:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kiritimati
		case 69:
			tmz_now = utc_now + (14 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kosrae
		case 70:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kwajalein
		case 71:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Marquesas
		case 72:
			tmz_now = utc_now - (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Pacific/Tahiti
		case 73:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Nauru
		case 74:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Niue
		case 75:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Noumea
		case 76:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pago_Pago
		case 77:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Palau
		case 78:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pitcairn
		case 79:
			tmz_now = utc_now + (-8 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Port_Moresby
		case 80:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Rarotonga
		case 81:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tarawa
		case 82:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tongatapu
		case 83:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// America/Bahia_Banderas
		case 84:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cancun
		case 85:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Chihuahua
		case 86:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Hermosillo
		case 87:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mazatlan
		case 88:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Merida
		case 89:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mexico_City
		case 90:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Monterrey
		case 91:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Antarctica/Casey
		case 96:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Davis
		case 97:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Mawson
		case 98:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Palmer
		case 99:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Rothera
		case 100:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Atlantic/Cape_Verde
		case 103:
			tmz_now = utc_now + (-1 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/South_Georgia
		case 104:
			tmz_now = utc_now + (-2 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/Stanley
		case 105:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Brisbane
		case 106:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Darwin
		case 107:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Eucla
		case 108:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Lindeman
		case 109:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Perth
		case 110:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Yangon
		case 117:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Bangkok
		case 118:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Bishkek
		case 119:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Choibalsan
		case 120:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ulaanbaatar
		case 121:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hovd
		case 122:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Colombo
		case 123:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Damascus
		case 124:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dhaka
		case 125:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dili
		case 126:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dubai
		case 127:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dushanbe
		case 128:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Ho_Chi_Minh
		case 132:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hong_Kong
		case 133:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jakarta
		case 134:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jayapura
		case 135:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Makassar
		case 136:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Pontianak
		case 137:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kabul
		case 138:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Karachi
		case 139:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kathmandu
		case 140:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Qatar
		case 141:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Almaty
		case 142:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtau
		case 143:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtobe
		case 144:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Atyrau
		case 145:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Oral
		case 146:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qostanay
		case 147:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qyzylorda
		case 148:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Manila
		case 149:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Macau
		case 150:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Riyadh
		case 151:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Samarkand
		case 152:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tashkent
		case 153:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tbilisi
		case 154:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tehran
		case 155:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Thimphu
		case 156:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tokyo
		case 157:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yerevan
		case 158:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Istanbul
		case 159:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Minsk
		case 160:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;

		//

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