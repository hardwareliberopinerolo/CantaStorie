/* ----------------------------------------------------
 * CantaStorie con RC522 e Arduino Nano => Tonuino
 * Rev 00
 * 
 -------------------------------------------------------*/
#include <SPI.h>
#include <MFRC522.h>
#include <EZPROM.h>


#define SS_PIN 10
#define RST_PIN 9


String programma="CS_Random_Giorgio_18-08-2020";
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
#define MP3_files 14 // Numero massimo di MP3 riproducibili + 4 (Card di servizio(

int MP3_file_registrati=4; //MP3 registrati

//Per Scheda Carlo
//byte MP3_busy=2; 

//Per Arduino Nano
byte MP3_busy=4; 


byte LED1=A4;
byte LED2=A5;
//byte led1=0;
//byte led2=0;


const uint8_t uid_cards_id=0;
const uint8_t  uide_id=0;
const uint8_t  volume_id=1;
const uint8_t MP3_file_registrati_id=2;

uint8_t uid_ok[MP3_files][7];
//uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
const int mstatus[] = {   //Status associated to the RFID Cards
	903, //RFID 1: Load Card RFID
	900, //RFID 2: stop
	901, //RFID 3: vol+ 
	902, //RFID 4: vol-
	1,	 //RFID 5: track 1
	2,	 //RFID 6: track 2
	3,	 //RFID 7: track 3
	4,	 //RFID 8: track 4
	5,	 //RFID 9: track 5
	6,	 //RFID 10: track 6
	7,	 //RFID 11: track 7
	8,  //RFID 12: track 8
	9,  //RFID 13: track 9
	10, //RFID 14: track 10
};
const uint8_t uid_cards[][7] = {
//{ 0x4, 0x82, 0x87, 0xDA, 0x64, 0x5D, 0x81 },  //RFID 1 => Master
{0x4, 0x8, 0xBA, 0xFA, 0xAD, 0x56, 0x80,},
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 2  
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 3
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 4
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 5
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 6
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 7
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 8
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 9
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 10
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 11
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 12
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 13
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },  //RFID 14
};	
int volume=12;
//const int secondi=60;
