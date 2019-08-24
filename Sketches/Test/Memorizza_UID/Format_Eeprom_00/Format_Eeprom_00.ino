/* ----------------------------------------------------
 * Memorizza RFID nella EEPROM
 * Rev 00
 -------------------------------------------------------*/

#include <EZPROM.h>


void setup() {
	Serial.begin(115200);
	delay(100);
	Serial.println("initializing...");

 //------- Format ----
// only do once, if this is called every setup then information will be lost between power cycles
  Serial.println("Format Eeprom...");
  ezprom.reset();
	delay(100);
Serial.println("Eeprom formatted...");

} //End Setup

void loop() {
	
}
