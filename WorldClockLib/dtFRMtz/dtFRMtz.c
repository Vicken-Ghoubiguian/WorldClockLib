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
						"America/Bahia", // 21
						"America/Belem", // 22
						"America/Boa_Vista", // 23
						"America/Campo_Grande", // 24
						"America/Cuiaba", // 25
						"America/Eirunepe", // 26
						"America/Fortaleza", // 27
						"America/Maceio", // 28
						"America/Manaus", // 29
						"America/Noronha", // 30
						"America/Porto_Velho", // 31
						"America/Recife", // 32
						"America/Rio_Branco", // 33
						"America/Santarem", // 34
						"America/Sao_Paulo", // 35

						// AR
						"America/Argentina/Buenos_Aires", // 36
						"America/Argentina/Catamarca", // 37
						"America/Argentina/Cordoba", // 38
						"America/Argentina/Jujuy", // 39
						"America/Argentina/La_Rioja", // 40
						"America/Argentina/Mendoza", // 41
						"America/Argentina/Rio_Gallegos", // 42
						"America/Argentina/Salta", // 43
						"America/Argentina/San_Juan", // 44
						"America/Argentina/San_Luis", // 45
						"America/Argentina/Tucuman", // 46
						"America/Argentina/Ushuaia", // 47

						// RU
						"Europe/Moscow", // 48
						"Asia/Anadyr", // 49
						"Asia/Barnaul", // 50
						"Asia/Chita", // 51
						"Asia/Irkutsk", // 52
						"Asia/Kamchatka", // 53
						"Asia/Khandyga", // 54
						"Asia/Krasnoyarsk", // 55
						"Asia/Magadan", // 56
						"Asia/Novokuznetsk", // 57
						"Asia/Novosibirsk", // 58
						"Asia/Omsk", // 59
						"Asia/Sakhalin", // 60
						"Asia/Srednekolymsk", // 61
						"Asia/Tomsk", // 62
						"Asia/Ust-Nera", // 63
						"Asia/Vladivostok", // 64
						"Asia/Yakutsk", // 65
						"Asia/Yekaterinburg", // 66
						"Europe/Kaliningrad", // 67
						"Europe/Kirov", // 68
						"Europe/Samara", // 69
						"Europe/Saratov", // 70
						"Europe/Simferopol", // 71
						"Europe/Ulyanovsk", // 72

						// WS
						"Pacific/Apia", // 73

						// PG
						"Pacific/Bougainville", // 74

						// VU
						"Pacific/Efate", // 75

						// TK
						"Pacific/Fakaofo", // 76

						// FJ
						"Pacific/Fiji", // 77

						// EC
						"Pacific/Galapagos", // 78

						// PF
						"Pacific/Gambier", // 79

						// SB, FM
						"Pacific/Guadalcanal", // 80

						// GU, MP
						"Pacific/Guam", // 81

						// US
						"Pacific/Honolulu", // 82

						// KI
						"Pacific/Kanton", // 83
						"Pacific/Kiritimati", // 84

						// FM
						"Pacific/Kosrae", // 85

						// MH
						"Pacific/Kwajalein", // 86

						// PF
						"Pacific/Marquesas", // 87
						"Pacific/Tahiti", // 88

						// NR
						"Pacific/Nauru", // 89

						// NU
						"Pacific/Niue", // 90

						// NC
						"Pacific/Noumea", // 91

						// AS, UM
						"Pacific/Pago_Pago", // 92

						// PW
						"Pacific/Palau", // 93

						// PN
						"Pacific/Pitcairn", // 94

						// PG, AQ, FM
						"Pacific/Port_Moresby", // 95

						// CK
						"Pacific/Rarotonga", // 96

						// KI, MH, TV, UM, WF
						"Pacific/Tarawa", // 97

						// TO
						"Pacific/Tongatapu", // 98

						// MX
						"America/Bahia_Banderas", // 99
						"America/Cancun", // 100
						"America/Chihuahua", // 101
						"America/Hermosillo", // 102
						"America/Mazatlan", // 103
						"America/Merida", // 104
						"America/Mexico_City", // 105
						"America/Monterrey", // 106
						"America/Ojinaga", // 107
						"America/Ciudad_Juarez", // 108
						"America/Matamoros", // 109
						"America/Tijuana", // 110

						// AQ
						"Antarctica/Casey", // 111
						"Antarctica/Davis", // 112
						"Antarctica/Mawson", // 113
						"Antarctica/Palmer", // 114
						"Antarctica/Rothera", // 115
						"Antarctica/Macquarie", // 116
						"Antarctica/Troll", // 117

						// CV
						"Atlantic/Cape_Verde", // 118

						// GS
						"Atlantic/South_Georgia", // 119

						// FK
						"Atlantic/Stanley", // 120

						// AU
						"Australia/Brisbane", // 121
						"Australia/Darwin", // 122
						"Australia/Eucla", // 123
						"Australia/Lindeman", // 124
						"Australia/Perth", // 125
						"Australia/Sydney", // 126
						"Australia/Melbourne", // 127
						"Australia/Lord_Howe", // 128
						"Australia/Hobart", // 129
						"Australia/Broken_Hill", // 130
						"Australia/Adelaide", // 131

						// MM, CC
						"Asia/Yangon", // 132

						// TH, CX, KH, LA, VN
						"Asia/Bangkok", // 133

						// KG
						"Asia/Bishkek", // 134

						// MN
						"Asia/Choibalsan", // 135
						"Asia/Ulaanbaatar", // 136
						"Asia/Hovd", // 137

						// LK
						"Asia/Colombo", // 138

						// SY
						"Asia/Damascus", // 139

						// BD
						"Asia/Dhaka", // 140

						// TL
						"Asia/Dili", // 141

						// AE, OM, RE, SC, TF
						"Asia/Dubai", // 142

						// TJ
						"Asia/Dushanbe", // 143

						// CY
						"Asia/Famagusta", // 144

						// PS
						"Asia/Gaza", // 145

						// PS
						"Asia/Hebron", // 146

						// VN
						"Asia/Ho_Chi_Minh", // 147

						// HK
						"Asia/Hong_Kong", // 148

						// ID
						"Asia/Jakarta", // 149
						"Asia/Jayapura", // 150
						"Asia/Makassar", // 151
						"Asia/Pontianak", // 152

						// AF
						"Asia/Kabul", // 153

						// PK
						"Asia/Karachi", // 154

						// NP
						"Asia/Kathmandu", // 155

						// QA, BH
						"Asia/Qatar", // 156

						// KZ
						"Asia/Almaty", // 157
						"Asia/Aqtau", // 158
						"Asia/Aqtobe", // 159
						"Asia/Atyrau", // 160
						"Asia/Oral", // 161
						"Asia/Qostanay", // 162
						"Asia/Qyzylorda", // 163

						// PH
						"Asia/Manila", // 164

						// MO
						"Asia/Macau", // 165

						// SA, AQ, KW, YE
						"Asia/Riyadh", // 166

						// UZ
						"Asia/Samarkand", // 167
						"Asia/Tashkent", // 168

						// GE
						"Asia/Tbilisi", // 169

						// IR
						"Asia/Tehran", // 170

						// BT
						"Asia/Thimphu", // 171

						// JP
						"Asia/Tokyo", // 172

						// AM
						"Asia/Yerevan", // 173

						// TR
						"Europe/Istanbul", // 174

						// BY
						"Europe/Minsk", // 175

						// BZ
						"America/Belize", // 176

						// CO
						"America/Bogota", // 177

						// VE
						"America/Caracas", // 178

						// GF
						"America/Cayenne", // 179

						// CR
						"America/Costa_Rica", // 180

						// GL
						"America/Danmarkshavn", // 181
						"America/Nuuk", // 182
						"America/Scoresbysund", // 183
						"America/Thule", // 184

						// PA, CA, KY
						"America/Panama", // 185

						// SR
						"America/Paramaribo", // 186

						// DO
						"America/Santo_Domingo", // 187

						// CL
						"America/Punta_Arenas", // 188
						"America/Santiago", // 189
						"Pacific/Easter" // 190
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

		//
		/*
		
		
		
		*/

		// America/Argentina/Buenos_Aires
		case 36:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Catamarca
		case 37:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Cordoba
		case 38:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Jujuy
		case 39:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/La_Rioja
		case 40:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Mendoza
		case 41:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Rio_Gallegos
		case 42:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Salta
		case 43:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/San_Juan
		case 44:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/San_Luis
		case 45:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Tucuman
		case 46:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Argentina/Ushuaia
		case 47:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Moscow
		case 48:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Anadyr
		case 49:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Barnaul
		case 50:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Chita
		case 51:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Irkutsk
		case 52:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kamchatka
		case 53:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Khandyga
		case 54:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Krasnoyarsk
		case 55:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Magadan
		case 56:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novokuznetsk
		case 57:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Novosibirsk
		case 58:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Omsk
		case 59:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Sakhalin
		case 60:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Srednekolymsk
		case 61:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tomsk
		case 62:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ust-Nera
		case 63:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Vladivostok
		case 64:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yakutsk
		case 65:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yekaterinburg
		case 66:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kaliningrad
		case 67:
			tmz_now = utc_now + (2 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Kirov
		case 68:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Samara
		case 69:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Saratov
		case 70:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Simferopol
		case 71:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Ulyanovsk
		case 72:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Apia
		case 73:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Bougainville
		case 74:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Efate
		case 75:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fakaofo
		case 76:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Fiji
		case 77:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Galapagos
		case 78:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Gambier
		case 79:
			tmz_now = utc_now + (-9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guadalcanal
		case 80:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Guam
		case 81:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Honolulu
		case 82:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kanton
		case 83:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kiritimati
		case 84:
			tmz_now = utc_now + (14 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kosrae
		case 85:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kwajalein
		case 86:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Marquesas
		case 87:
			tmz_now = utc_now - (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Pacific/Tahiti
		case 88:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Nauru
		case 89:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Niue
		case 90:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Noumea
		case 91:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pago_Pago
		case 92:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Palau
		case 93:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pitcairn
		case 94:
			tmz_now = utc_now + (-8 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Port_Moresby
		case 95:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Rarotonga
		case 96:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tarawa
		case 97:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tongatapu
		case 98:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// America/Bahia_Banderas
		case 99:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cancun
		case 100:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Chihuahua
		case 101:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Hermosillo
		case 102:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mazatlan
		case 103:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Merida
		case 104:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mexico_City
		case 105:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Monterrey
		case 106:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Antarctica/Casey
		case 111:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Davis
		case 112:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Mawson
		case 113:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Palmer
		case 114:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Rothera
		case 115:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Atlantic/Cape_Verde
		case 118:
			tmz_now = utc_now + (-1 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/South_Georgia
		case 119:
			tmz_now = utc_now + (-2 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/Stanley
		case 120:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Brisbane
		case 121:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Darwin
		case 122:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Eucla
		case 123:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Lindeman
		case 124:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Perth
		case 125:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Yangon
		case 132:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Bangkok
		case 133:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Bishkek
		case 134:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Choibalsan
		case 135:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ulaanbaatar
		case 136:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hovd
		case 137:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Colombo
		case 138:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Damascus
		case 139:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dhaka
		case 140:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dili
		case 141:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dubai
		case 142:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dushanbe
		case 143:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Ho_Chi_Minh
		case 147:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hong_Kong
		case 148:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jakarta
		case 149:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jayapura
		case 150:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Makassar
		case 151:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Pontianak
		case 152:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kabul
		case 153:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Karachi
		case 154:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kathmandu
		case 155:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Qatar
		case 156:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Almaty
		case 157:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtau
		case 158:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtobe
		case 159:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Atyrau
		case 160:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Oral
		case 161:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qostanay
		case 162:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qyzylorda
		case 163:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Manila
		case 164:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Macau
		case 165:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Riyadh
		case 166:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Samarkand
		case 167:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tashkent
		case 168:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tbilisi
		case 169:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tehran
		case 170:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Thimphu
		case 171:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tokyo
		case 172:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yerevan
		case 173:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Istanbul
		case 174:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Minsk
		case 175:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Belize
		case 176:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Bogota
		case 177:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Caracas
		case 178:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cayenne
		case 179:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Costa_Rica
		case 180:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
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