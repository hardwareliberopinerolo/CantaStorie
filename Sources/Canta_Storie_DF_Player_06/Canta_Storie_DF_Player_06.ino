/* ----------------------------------------------------
 * CantaStorie 
 * Rev 06
 * 
 -------------------------------------------------------*/
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
 // #include <NfcAdapter.h>
  
PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);

/*
const uint8_t uid_ok1[] = { 0x4, 0xB1, 0x63, 0xDA, 0x31, 0x5B, 0x80 };  //UID SPT Subway 1
const uint8_t uid_ok2[] = { 0x4, 0x42, 0x55, 0x72, 0x62, 0x57, 0x80 };  //UID ciondolo viola 
const uint8_t uid_ok3[] = { 0xF6, 0x99, 0xBD, 0xAC,0,0,0 };  //UID ciondolo rosso
const uint8_t uid_ok4[] = { 0x4, 0x4D, 0x23, 0x2A, 0x52, 0x5D, 0x85 };  //UID GTT1
const uint8_t uid_ok5[] = { 0x4, 0x4B, 0x23, 0x2A, 0x52, 0x5D, 0x85 };  //UID GTT2
const uint8_t uid_ok6[] = { 0x4, 0x47, 0x3D, 0xDA, 0x64, 0x5D, 0x81 };  //UID GTT3
const uint8_t uid_ok7[] = { 0x5, 0x77, 0x7C, 0x6A, 0x99, 0x54, 0xE9 };  //UID GTT4
const uint8_t uid_ok8[] = { 0x5, 0x7D, 0x8C, 0xB9, 0x59, 0x54, 0xE9 };  //UID GTT5
const uint8_t uid_ok9[] = { 0x5, 0x76, 0x23, 0x1A, 0xE9, 0x54, 0xE9 };  //UID SPT Subway 2
const uint8_t uid_ok10[] = { 0x5, 0x7D, 0x62, 0x7B, 0x5A, 0x54, 0xE9 };  //UID SPT Subway 3
const uint8_t uid_ok11[] = { 0x5, 0x72, 0x8E, 0x19, 0x7A, 0x54, 0xE9 };  //UID SPT Subway 4
const uint8_t uid_ok12[] = { 0x5, 0x73, 0x7B, 0x9B, 0xE9, 0x54, 0xE9 };  //UID SPT Subway 5
*/

//RFID Cards codes
const uint8_t uid_ok[][7] = {
{ 0x4, 0xB1, 0x63, 0xDA, 0x31, 0x5B, 0x80 },	//RFID 1
{ 0x4, 0x42, 0x55, 0x72, 0x62, 0x57, 0x80 },	//RFID 2
{ 0xF6, 0x99, 0xBD, 0xAC,0,0,0 },  			  	//RFID 3
{ 0x4, 0x4D, 0x23, 0x2A, 0x52, 0x5D, 0x85 },	//RFID 4
{ 0x4, 0x4B, 0x23, 0x2A, 0x52, 0x5D, 0x85 },	//RFID 5
{ 0x4, 0x47, 0x3D, 0xDA, 0x64, 0x5D, 0x81 },	//RFID 6
{ 0x5, 0x77, 0x7C, 0x6A, 0x99, 0x54, 0xE9 },	//RFID 7
{ 0x5, 0x7D, 0x8C, 0xB9, 0x59, 0x54, 0xE9 },	//RFID 8
{ 0x5, 0x76, 0x23, 0x1A, 0xE9, 0x54, 0xE9 },	//RFID 9
{ 0x5, 0x7D, 0x62, 0x7B, 0x5A, 0x54, 0xE9 },	//RFID 10
{ 0x5, 0x72, 0x8E, 0x19, 0x7A, 0x54, 0xE9 },	//RFID 11
{ 0x5, 0x73, 0x7B, 0x9B, 0xE9, 0x54, 0xE9 },	//RFID 12
};

//Status associated to the RFID Cards
const int mstatus[] = { 
	1,		//RFID 1: track 1
	999,	//RFID 2: null
	900,	//RFID 3: stop
	2,		//RFID 4: track 2
	3,		//RFID 5: track 3
	6,		//RFID 6: track 6
	5,		//RFID 7: track 5
	900, 	//RFID 8: stop
	100, 	//RFID 9: track 100
	101,	//RFID 10: track 101
	901,	//RFID 11: vol+ 
	902,	//RFID 12: vol-
};	

int volume=15;
const int secondi=60;
