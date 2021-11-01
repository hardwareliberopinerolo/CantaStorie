//---Abbina le schede RFID ai brani in SD-CARD-------------------
void load_rfid(){
	int test=1;
  Serial.println(F("Carica Schede..."));
	for (uint8_t s=1; s < MP3_files; s++){ //Not read the Master Card
	  mp3.playMp3FolderTrack(mstatus[s]); 
    delay(500);
    while (!scan_rfid()){}
	//Verifica che non sia la scheda master	
	test=memcmp(rfid.uid.uidByte,uid_ok[0],rfid.uid.size); //uid file    
   Serial.print(F("Risultato Test: "));
   Serial.println(test);
    if (test != 0) {
 	
		memcpy (&uid_ok[s], &rfid.uid.uidByte, rfid.uid.size);
    //mp3.playMp3FolderTrack(10); //Bing sound
    //delay(500);
		Serial.print(F("Scheda Caricata: "));
		Serial.println(s);
    MP3_file_registrati=s;
    //break;
	}	
	else {
		Serial.println(F("Caricamento brani interrotto"));

		break;

	}
}

	Serial.println(F("Schede Caricate!"));
	Serial.println(F("Registra le Carte nella Eeprom"));
	ezprom.save(uide_id, **uid_ok, MP3_files * 7);
	delay(100);
	// Salva max MP3 file registrati
	MP3_file_registrati=MP3_file_registrati-3;
			if (MP3_file_registrati >0 && MP3_file_registrati <11 ){
				Serial.println(MP3_file_registrati);
				Serial.println(F("Registra massimo numero di brani random in eeprom"));
				ezprom.save(MP3_file_registrati_id, MP3_file_registrati, sizeof(MP3_file_registrati)); 
			}
	
	delay(100);
	
	read_eeprom(); // Check the new UIDs has been correctly written
  delay(1000);
}
//------------------------------------------- 
bool scan_rfid(){
  //Wait for an ISO14443A type cards (Mifare, etc.).  
  //Reset the loop if no new card present on the sensor/reader. 
  //This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return 0;
  // Verify if the UID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return 0;
  // Halt PICC (evita la continua lettura della scheda)
  rfid.PICC_HaltA();
  //else a card has been found
	mp3.playMp3FolderTrack(910); //Bing sound
	delay(500);
  Serial.println(F("Found a card!"));
  Serial.print(F("UID Value: "));
  for (uint8_t i=0; i < rfid.uid.size; i++){
    Serial.print(F(" 0x"));
	Serial.print(rfid.uid.uidByte[i], HEX); 
  }
  Serial.println(F("")); 
  return 1;
}

//------------------------------------------------------------------------
void update_master(){
	Serial.println(F("Aggiorna Scheda Master..."));
   while (!scan_rfid()){}
	memcpy (&uid_ok[0], &rfid.uid.uidByte, rfid.uid.size);
 	Serial.print(F("Scheda Master Caricata"));
	Serial.println(F("Registra le Carte nella Eeprom"));
	ezprom.save(uide_id, **uid_ok, MP3_files * 7);
	delay(100);
	read_eeprom(); // Check the new UIDs has been correctly written
  	delay(100);
}
