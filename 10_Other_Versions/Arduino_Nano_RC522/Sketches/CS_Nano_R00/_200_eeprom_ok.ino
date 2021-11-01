//---------------------------------------------
void read_eeprom(){
  //Read the RFID Cards UIDs codes from the Arduino Eeprom
//  ezprom.setOverwriteIfSizeDifferent(true);
  //delay(500);
  Serial.println(F("Carica le Carte dalla Eeprom"));
  //.....................
  ezprom.load(uide_id, **uid_ok); //uide=costante impostata a 0, locazione iniziale.
  delay(1000);                    //uid_ok, array bidimesionale con posizione e valore.
  //.....................
  Serial.println(F(""));             
  Serial.println(F("Registrate le seguenti Carte:"));
	for (int n=0; n<MP3_files; n++) {  //uid_ok[MP3_files][7]
		Serial.print(F("New UID Card "));   //MP3_files=14;
		Serial.print(n+1);
		Serial.print(F(" Value: "));
		for (uint8_t i=0; i < 7; i++){
		  Serial.print(F(" 0x"));
		  Serial.print(uid_ok[n][i], HEX); 
		}                     //n=numero carta, i=valore. Es 04:82:87:DA
		Serial.println(F(""));               //altro tipo carta 04:82:87:DA:64:5D:81
  }
 
 // Carica il volume dalla eeprom
  Serial.print(F("Carica il volume dalla Eeprom: "));
 ezprom.load(volume_id, volume); //Commentare al primo avvio perchè dato non registrato
  delay(1000);                    
  Serial.println(volume);             

 // Carica max file per Random
  Serial.print(F("Carica max file per Random: "));
 ezprom.load(MP3_file_registrati_id, MP3_file_registrati); //Commentare al primo avvio perchè dato non registrato
  delay(1000);                    
  Serial.println(MP3_file_registrati); 


} //end



//---Inizializzazione EEPROM--------------------
void initEEPROM(void){
  Serial.println(F("Formattazione Eeprom..."));
  ezprom.reset();
  delay(100);
  Serial.println(F("Eeprom formattata..."));
  //ezprom.setOverwriteIfSizeDifferent(true);
  //const uint8_t uid_cards_id=0,uide_id=1;
  Serial.println(F("Registra le Carte nella Eeprom"));
  //Carica sulla Eeprom solo il codice della card Master, 
  //tutti gli altri campi vouti.
  ezprom.save(uid_cards_id, **uid_cards, MP3_files * 7);
  delay(1000);
  Serial.println(F("Registra il volume nella Eeprom"));
  ezprom.save(volume_id, volume, sizeof(volume));
  delay(1000);
  Serial.println(F("Registra massimo numero di brani random"));
  ezprom.save(MP3_file_registrati_id, MP3_file_registrati, sizeof(MP3_file_registrati));  

  Serial.println(F("Verifica che le Carte siano state salvate nella Eeprom"));
  //uint8_t uid_e[MP3_files][7];
  //ezprom.load(uid_cards_id, **uid_e); //Carica i dati da Eeprom per verifica.
  //delay(1000);
  //Serial.println(F(""));
  read_eeprom();
  /*
  Serial.println(F("Registrate le seguenti Carte:"));
  for (int n=0; n<MP3_files; n++) { //Verifica contenuto Eeprom.
    Serial.print(F("New UID Card "));
    Serial.print(n+1);
    Serial.print(F(" Value: "));
    for (uint8_t i=0; i < 7; i++){
      Serial.print(F(" 0x"));
      Serial.print(uid_e[n][i], HEX); //Dati in Eeprom. 
    }
    Serial.println(F(""));
  }
  */
}
