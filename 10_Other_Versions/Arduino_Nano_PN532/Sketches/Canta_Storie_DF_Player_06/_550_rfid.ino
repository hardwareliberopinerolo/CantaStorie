void legge_rfid(void){
	int status_=0;
	int test=1;
  boolean success=0;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
// If a RFID card has been read  
  if (success) {
    Serial.println("Found a card!");
    //Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(" 0x");Serial.print(uid[i], HEX); 
    }
    Serial.println("");

// Scan RFID UIDs to associate the status	
  for (uint8_t s=0; s < 12; s++) 
    {
      test=memcmp(uid,uid_ok[s],sizeof(uid));
      if (test==0) {
		status_=mstatus[s];
    Serial.print("Status");
    Serial.println(status_);
		break;
        } 
    } //end for
 
 
// Do the action related to the status
	switch (status_) {
		case 1 ... 200:
			Serial.print("track: "); 
			Serial.println(status_);  
			mp3.playMp3FolderTrack(10); //Bing sound
			delay(500);
			mp3.playMp3FolderTrack(status_);  
		break;

		case 900:
			Serial.println("Stop"); 
			mp3.playMp3FolderTrack(10); 
			delay(500);
			mp3.stop(); // stop
		break;

		case 901:
			if (volume<21){
				Serial.println("volume+"); 
				mp3.setVolume(++volume);
			}
		break;

		case 902:
			if (volume>9){
				Serial.println("volume-"); 
				mp3.setVolume(--volume);
			}
		break;


		default:
		// Nothing
		break;
		} //end switch case
    
  } // end 
  
  else {
// Nothing
  }
}
