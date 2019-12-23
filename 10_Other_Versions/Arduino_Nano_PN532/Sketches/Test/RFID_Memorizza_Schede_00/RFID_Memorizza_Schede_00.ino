/**************************************************************************/
/*
	Memorizza Schede   
*/
/**************************************************************************/

  #include <Wire.h>
  #include <PN532_I2C.h>
  #include <PN532.h>
//  #include <NfcAdapter.h>
  
  PN532_I2C pn532i2c(Wire);
  PN532 nfc(pn532i2c);

const uint8_t uid_master[] = { 0x4, 0xB1, 0x63, 0xDA, 0x31, 0x5B, 0x80 };  //UID SPT Subway
uint8_t uid[2][7]; 

  
void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
 Serial.println("PN532 Found!!!");
  
  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  nfc.setPassiveActivationRetries(0xFF);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
    
  Serial.println("Waiting for an ISO14443A card");
}

void loop(void) {
  int test=1;
  boolean success;
  uint8_t uid_temp[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid_temp[0], &uidLength);
  
  if (success) {
    Serial.println("Found a card!");
    //Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(" 0x");Serial.print(uid_temp[i], HEX); 
    }
    Serial.println("");
 
    test=memcmp(uid_temp,uid_master,sizeof(uid_temp));
    Serial.println(test);
        if (test==0) {
          Serial.println("Carta Master");
          Record_Cards();
                  Serial.println("Carte Registrate....");
        } 

   Serial.println("");
  }
  delay(1000);
}

//--------- Registra le card RFID -------------------------------------------------------------

void Record_Cards(void) {
	boolean suc=0;
  boolean okcarta=0;
	uint8_t uid_temp[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
	uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
	Serial.println("Registra Carte");
	for (int n=0; n<2; n++) {
		Serial.print("Passa la carta: ");
   Serial.println(n);
        delay(1000);
    okcarta=0;
		while (!okcarta){	
			suc = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid_temp[0], &uidLength);
			Serial.println(suc);
      
			if (suc) {
				Serial.println("Found a card!");
				Serial.print("UID Length: ");
				Serial.print(uidLength, DEC);
				Serial.println(" bytes");
				
				Serial.print("UID Value: ");
				for (uint8_t i=0; i < uidLength; i++) 
					{
					  Serial.print(" 0x");Serial.print(uid_temp[i], HEX); 
					}
				Serial.println("");
				memcpy(&uid[n],&uid_temp,sizeof(uid));
				okcarta=1;
        Serial.println("Carta Registrata....");
			}
			delay(1000);
		}
	}
      delay(1000);
   Serial.println("");
  Serial.println("Registrate le seguenti Carte:");
	for (int n=0; n<2; n++) {
		Serial.print("New UID Card ");
		Serial.print(n);
		Serial.print(" Value: ");
		for (uint8_t i=0; i < uidLength; i++) 
		{
		  Serial.print(" 0x");Serial.print(uid[n][i], HEX); 
		}
		Serial.println("");
   
	}
Serial.println("Carte Registrate....");
}
//---end--------- Registra le card RFID -------------------------------------------------------------
