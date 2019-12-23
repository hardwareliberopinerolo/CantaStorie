void loop(){
  if(Serial.available()){
    char inizializza=Serial.read();
    if(inizializza=='R'){ // Reset Eeprom
      initEEPROM();
      inizializza=' ';
    }
	else if(inizializza=='L'){ //Load cards from Eeprom
      read_eeprom();
      inizializza=' ';
    }
	else if(inizializza=='M'){ //Update Master card
      update_master();
      inizializza=' ';
    }
  }
  
	legge_rfid();
	delay(100); //1000
	mp3.loop(); //controlla il lettore per messaggi
	delay(10);
}
