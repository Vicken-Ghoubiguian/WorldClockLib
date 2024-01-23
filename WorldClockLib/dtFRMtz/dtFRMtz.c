#include <string.h>
#include <time.h>
#include "dtFRMtz.h"
#include "../dstCalculous/dstCalculous.h"

#define NB_SECONDS_IN_HOURS 3600
#define NB_SECONDS_IN_MINUTES 60
#define __NULL ((void *)0)

//
int getIndexFromTzArray(char* timezone)
{
	//
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

						// KI
						"Pacific/Kanton", // 82
						"Pacific/Kiritimati", // 83

						// FM
						"Pacific/Kosrae", // 84

						// MH
						"Pacific/Kwajalein", // 85

						// PF
						"Pacific/Marquesas", // 86
						"Pacific/Tahiti", // 87

						// NR
						"Pacific/Nauru", // 88

						// NU
						"Pacific/Niue", // 89

						// NC
						"Pacific/Noumea", // 90

						// AS, UM
						"Pacific/Pago_Pago", // 91

						// PW
						"Pacific/Palau", // 92

						// PN
						"Pacific/Pitcairn", // 93

						// PG, AQ, FM
						"Pacific/Port_Moresby", // 94

						// CK
						"Pacific/Rarotonga", // 95

						// KI, MH, TV, UM, WF
						"Pacific/Tarawa", // 96

						// TO
						"Pacific/Tongatapu", // 97

						// MX
						"America/Bahia_Banderas", // 98
						"America/Cancun", // 99
						"America/Chihuahua", // 100
						"America/Hermosillo", // 101
						"America/Mazatlan", // 102
						"America/Merida", // 103
						"America/Mexico_City", // 104
						"America/Monterrey", // 105
						"America/Ojinaga", // 106
						"America/Ciudad_Juarez", // 107
						"America/Matamoros", // 108
						"America/Tijuana", // 109

						// AQ
						"Antarctica/Casey", // 110
						"Antarctica/Davis", // 111
						"Antarctica/Mawson", // 112
						"Antarctica/Palmer", // 113
						"Antarctica/Rothera", // 114
						"Antarctica/Macquarie", // 115
						"Antarctica/Troll", // 116

						// CV
						"Atlantic/Cape_Verde", // 117

						// GS
						"Atlantic/South_Georgia", // 118

						// FK
						"Atlantic/Stanley", // 119

						// AU
						"Australia/Brisbane", // 120
						"Australia/Darwin", // 121
						"Australia/Eucla", // 122
						"Australia/Lindeman", // 123
						"Australia/Perth", // 124
						"Australia/Sydney", // 125
						"Australia/Melbourne", // 126
						"Australia/Lord_Howe", // 127
						"Australia/Hobart", // 128
						"Australia/Broken_Hill", // 129
						"Australia/Adelaide", // 130

						// MM, CC
						"Asia/Yangon", // 131

						// TH, CX, KH, LA, VN
						"Asia/Bangkok", // 132

						// KG
						"Asia/Bishkek", // 133

						// MN
						"Asia/Choibalsan", // 134
						"Asia/Ulaanbaatar", // 135
						"Asia/Hovd", // 136

						// LK
						"Asia/Colombo", // 137

						// SY
						"Asia/Damascus", // 138

						// BD
						"Asia/Dhaka", // 139

						// TL
						"Asia/Dili", // 140

						// AE, OM, RE, SC, TF
						"Asia/Dubai", // 141

						// TJ
						"Asia/Dushanbe", // 142

						// CY
						"Asia/Famagusta", // 143

						// PS
						"Asia/Gaza", // 144

						// PS
						"Asia/Hebron", // 145

						// VN
						"Asia/Ho_Chi_Minh", // 146

						// HK
						"Asia/Hong_Kong", // 147

						// ID
						"Asia/Jakarta", // 148
						"Asia/Jayapura", // 149
						"Asia/Makassar", // 150
						"Asia/Pontianak", // 151

						// AF
						"Asia/Kabul", // 152

						// PK
						"Asia/Karachi", // 153

						// NP
						"Asia/Kathmandu", // 154

						// QA, BH
						"Asia/Qatar", // 155

						// KZ
						"Asia/Almaty", // 156
						"Asia/Aqtau", // 157
						"Asia/Aqtobe", // 158
						"Asia/Atyrau", // 159
						"Asia/Oral", // 160
						"Asia/Qostanay", // 161
						"Asia/Qyzylorda", // 162

						// PH
						"Asia/Manila", // 163

						// MO
						"Asia/Macau", // 164

						// SA, AQ, KW, YE
						"Asia/Riyadh", // 165

						// UZ
						"Asia/Samarkand", // 166
						"Asia/Tashkent", // 167

						// GE
						"Asia/Tbilisi", // 168

						// IR
						"Asia/Tehran", // 169

						// BT
						"Asia/Thimphu", // 170

						// JP
						"Asia/Tokyo", // 171

						// AM
						"Asia/Yerevan", // 172

						// TR
						"Europe/Istanbul", // 173

						// BY
						"Europe/Minsk", // 174

						// BZ
						"America/Belize", // 175

						// CO
						"America/Bogota", // 176

						// VE
						"America/Caracas", // 177

						// GF
						"America/Cayenne", // 178

						// CR
						"America/Costa_Rica", // 179

						// GL
						"America/Danmarkshavn", // 180
						"America/Nuuk", // 181
						"America/Scoresbysund", // 182
						"America/Thule", // 183

						// PA, CA, KY
						"America/Panama", // 184

						// SR
						"America/Paramaribo", // 185

						// DO
						"America/Santo_Domingo", // 186

						// CL
						"America/Punta_Arenas", // 187
						"America/Santiago", // 188
						"Pacific/Easter", // 189

						// EH
						"Africa/El_Aaiun", // 190

						// MA
						"Africa/Casablanca", // 191

						// EG
						"Africa/Cairo", // 192

						// BO
						"America/La_Paz", // 193

						// CA

						// US
						"Pacific/Honolulu", // 194

						// NF
						"Pacific/Norfolk", // 195

						// MV, TF
						"Indian/Maldives", // 196

						// MU
						"Indian/Mauritius", // 197

						// IO
						"Indian/Chagos", // 198

						// IN
						"Asia/Kolkata", // 199

						// MY, BN
						"Asia/Kuching", // 200

						// NZ
						"Pacific/Auckland", // 201
						"Pacific/Chatham" // 202
					};
    
	//
    int tzArrayLen = sizeof tzArray / sizeof tzArray[0];

	//
    int index = -1;
    
	//
    for (int i = 0; i < tzArrayLen; i++) {

		//
        if (tzArray[i] == timezone) {

			//
            index = i;

			//
            break;
        }
    }

	//
	return index;
}

//
time_t getDateTime_Epoch(char* timezone) {

	time_t tmz_now;
	time_t utc_now = time(NULL);
	int tzIndex = getIndexFromTzArray(timezone);
	int hours;
	int offset;

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
		// America/Bahia
		case 21:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Belem
		case 22:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Boa_Vista
		case 23:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Campo_Grande
		case 24:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cuiaba
		case 25:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Eirunepe
		case 26:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Fortaleza
		case 27:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Maceio
		case 28:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Manaus
		case 29:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Noronha
		case 30:
			tmz_now = utc_now + (-2 * NB_SECONDS_IN_HOURS);
			break;
		// America/Porto_Velho
		case 31:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Recife
		case 32:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Rio_Branco
		case 33:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Santarem
		case 34:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Sao_Paulo
		case 35:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
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
		// Pacific/Kanton
		case 82:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kiritimati
		case 83:
			tmz_now = utc_now + (14 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kosrae
		case 84:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Kwajalein
		case 85:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Marquesas
		case 86:
			tmz_now = utc_now - (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Pacific/Tahiti
		case 87:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Nauru
		case 88:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Niue
		case 89:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Noumea
		case 90:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pago_Pago
		case 91:
			tmz_now = utc_now + (-11 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Palau
		case 92:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Pitcairn
		case 93:
			tmz_now = utc_now + (-8 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Port_Moresby
		case 94:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Rarotonga
		case 95:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tarawa
		case 96:
			tmz_now = utc_now + (12 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Tongatapu
		case 97:
			tmz_now = utc_now + (13 * NB_SECONDS_IN_HOURS);
			break;
		// America/Bahia_Banderas
		case 98:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cancun
		case 99:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Chihuahua
		case 100:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Hermosillo
		case 101:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mazatlan
		case 102:
			tmz_now = utc_now + (-7 * NB_SECONDS_IN_HOURS);
			break;
		// America/Merida
		case 103:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Mexico_City
		case 104:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Monterrey
		case 105:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Antarctica/Casey
		case 110:
			tmz_now = utc_now + (11 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Davis
		case 111:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Mawson
		case 112:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Palmer
		case 113:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Antarctica/Rothera
		case 114:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Atlantic/Cape_Verde
		case 117:
			tmz_now = utc_now + (-1 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/South_Georgia
		case 118:
			tmz_now = utc_now + (-2 * NB_SECONDS_IN_HOURS);
			break;
		// Atlantic/Stanley
		case 119:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Brisbane
		case 120:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Darwin
		case 121:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Eucla
		case 122:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Australia/Lindeman
		case 123:
			tmz_now = utc_now + (10 * NB_SECONDS_IN_HOURS);
			break;
		// Australia/Perth
		case 124:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Yangon
		case 131:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Bangkok
		case 132:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Bishkek
		case 133:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Choibalsan
		case 134:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Ulaanbaatar
		case 135:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hovd
		case 136:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Colombo
		case 137:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Damascus
		case 138:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dhaka
		case 139:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dili
		case 140:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dubai
		case 141:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Dushanbe
		case 142:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;

		//

		// Asia/Ho_Chi_Minh
		case 146:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Hong_Kong
		case 147:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jakarta
		case 148:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Jayapura
		case 149:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Makassar
		case 150:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Pontianak
		case 151:
			tmz_now = utc_now + (7 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kabul
		case 152:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Karachi
		case 153:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kathmandu
		case 154:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 45 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Qatar
		case 155:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Almaty
		case 156:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtau
		case 157:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Aqtobe
		case 158:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Atyrau
		case 159:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Oral
		case 160:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qostanay
		case 161:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Qyzylorda
		case 162:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Manila
		case 163:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Macau
		case 164:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Riyadh
		case 165:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Samarkand
		case 166:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tashkent
		case 167:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tbilisi
		case 168:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tehran
		case 169:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Thimphu
		case 170:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Tokyo
		case 171:
			tmz_now = utc_now + (9 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Yerevan
		case 172:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Istanbul
		case 173:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// Europe/Minsk
		case 174:
			tmz_now = utc_now + (3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Belize
		case 175:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		// America/Bogota
		case 176:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Caracas
		case 177:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Cayenne
		case 178:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Costa_Rica
		case 179:
			tmz_now = utc_now + (-6 * NB_SECONDS_IN_HOURS);
			break;
		
		//

		// America/Panama
		case 184:
			tmz_now = utc_now + (-5 * NB_SECONDS_IN_HOURS);
			break;
		// America/Paramaribo
		case 185:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;
		// America/Santo_Domingo
		case 186:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// America/Punta_Arenas
		case 187:
			tmz_now = utc_now + (-3 * NB_SECONDS_IN_HOURS);
			break;

		//

		// America/La_Paz
		case 193:
			tmz_now = utc_now + (-4 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Honolulu
		case 194:
			tmz_now = utc_now + (-10 * NB_SECONDS_IN_HOURS);
			break;
		// Pacific/Norfolk
		case 195:
			tmz_now = first_sunday_in_april(utc_now, 2);
			/*
				if(utc_now + 12 >= first_sunday_in_april(utc_now, 2) &&  <= utc_now)
				{
					offset = 0;
				}
				else
				{
					offset = 1;
				}
			*/
			/*offset = 1;
			hours = 11 + offset;
			tmz_now = utc_now + (hours * NB_SECONDS_IN_HOURS);*/
			break;
		// Indian/Maldives
		case 196:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS);
			break;
		// Indian/Mauritius
		case 197:
			tmz_now = utc_now + (4 * NB_SECONDS_IN_HOURS);
			break;
		// Indian/Chagos
		case 198:
			tmz_now = utc_now + (6 * NB_SECONDS_IN_HOURS);
			break;
		// Asia/Kolkata
		case 199:
			tmz_now = utc_now + (5 * NB_SECONDS_IN_HOURS + 30 * NB_SECONDS_IN_MINUTES);
			break;
		// Asia/Kuching
		case 200:
			tmz_now = utc_now + (8 * NB_SECONDS_IN_HOURS);
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