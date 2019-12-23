/* ----------------------------------------------------
 * Memorizza RFID nella EEPROM
 * Rev 00
 -------------------------------------------------------*/

#include <EZPROM.h>


//RFID Cards codes
const uint8_t uid_cards[][7] = {
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



void setup() {
	Serial.begin(115200);
	delay(100);
	Serial.println("initializing...");

/*
 //------- Reset ----
// only do once, if this is called every setup then information will be lost between power cycles
  Serial.println("Reset Eeprom...");
  ezprom.reset();
*/



ezprom.setOverwriteIfSizeDifferent(false);

const uint8_t	uid_cards_id=0,
				uide_id=1;

Serial.println("Registra le Carte nella Eeprom");
ezprom.save(uid_cards_id, **uid_cards, 12 * 7);

   delay(1000);

  Serial.println("Carica le Carte dalla Eeprom");
uint8_t uid_e[12][7];
ezprom.load(uide_id, **uid_e);

   delay(1000);
   Serial.println("");
  Serial.println("Registrate le seguenti Carte:");
	for (int n=0; n<12; n++) {
		Serial.print("New UID Card ");
		Serial.print(n);
		Serial.print(" Value: ");
		for (uint8_t i=0; i < 7; i++) 
		{
		  Serial.print(" 0x");Serial.print(uid_e[n][i], HEX); 
		}
		Serial.println("");
   }



} //End Setup

void loop() {
	
}
