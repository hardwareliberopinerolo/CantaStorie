/* ----------------------------------------------------
 * Memorizza RFID nella EEPROM
 * Rev 00
 -------------------------------------------------------*/

#include <EZPROM.h>

void setup() {
	Serial.begin(115200);
	delay(100);
	Serial.println("initializing...");


ezprom.setOverwriteIfSizeDifferent(false);

const uint8_t	uid_cards_id=0,
				uide_id=1;

delay(500);

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
