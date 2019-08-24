/**************************************************************************/
/*! 
 Verifica che UID sia quello della scheda
    
*/
/**************************************************************************/

  #include <Wire.h>
  #include <PN532_I2C.h>
  #include <PN532.h>
  #include <NfcAdapter.h>
  
  PN532_I2C pn532i2c(Wire);
  PN532 nfc(pn532i2c);

const uint8_t uid_ok1[] = { 0x4, 0xB1, 0x63, 0xDA, 0x31, 0x5B, 0x80 };  //UID SPT Subway
const uint8_t uid_ok2[] = { 0x4, 0x42, 0x55, 0x72, 0x62, 0x57, 0x80 };  //UID ciondolo viola 
const uint8_t uid_ok3[] = { 0xF6, 0x99, 0xBD, 0xAC,0,0,0 };  //UID ciondolo rosso
const uint8_t uid_ok4[] = { 0x4, 0x4D, 0x23, 0x2A, 0x52, 0x5D, 0x85 };  //UID GTT1
const uint8_t uid_ok5[] = { 0x4, 0x4B, 0x23, 0x2A, 0x52, 0x5D, 0x85 };  //UID GTT2




  
void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

/*  
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
*/  
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
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if (success) {
    Serial.println("Found a card!");
    //Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(" 0x");Serial.print(uid[i], HEX); 
    }
    Serial.println("");
    // Wait 1 second before continuing
   // delay(1000);
    if(uidLength==7){
      test=memcmp(uid,uid_ok1,sizeof(uid));
        if (test==0) {
          Serial.println("Carta SPT Subway");
          
        } 
      test=memcmp(uid,uid_ok2,sizeof(uid));
        if (test==0) {
          Serial.println("Ciondolo Viola");
         
        } 
    }
    if(uidLength==4){
      test=memcmp(uid,uid_ok3,sizeof(uid));
        if (test==0) {
          Serial.println("Ciondolo Rosso");
         } 
    
     }
   Serial.println("");
  }
  else
  {
    // PN532 probably timed out waiting for a card
   // Serial.println("Timed out waiting for a card");
  }
  delay(1000);
}
