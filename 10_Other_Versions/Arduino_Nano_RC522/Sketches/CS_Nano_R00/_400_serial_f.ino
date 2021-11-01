void legge_serial(){
  if(Serial.available()){
    char inizializza=Serial.read();

// Reset Eeprom
      if(inizializza=='R'){ // Reset Eeprom
        initEEPROM();
        inizializza=' ';
      }

//Load cards from Eeprom    
      else if(inizializza=='L'){ //Load cards from Eeprom
          read_eeprom();
          inizializza=' ';
        }

//Update Master card
      else if(inizializza=='M'){ //Update Master card
          update_master();
          inizializza=' ';
        }
        else if(inizializza=='+'){ //Volume su
          if (volume<30){
            mp3.setVolume(++volume);
            delay(300);
            Serial.print(F("Volume: "));
            Serial.println(volume);
            mp3.playMp3FolderTrack(910);
            ezprom.save(volume_id, volume, sizeof(volume));
            delay(100);
          }
          inizializza=' ';
        }

//Volume giù
        else if(inizializza=='-'){ //Volume giù
          if (volume>5){
            mp3.setVolume(--volume);
            delay(300);
            Serial.print(F("Volume: "));
            Serial.println(volume);
            mp3.playMp3FolderTrack(910);
            ezprom.save(volume_id, volume, sizeof(volume));
            delay(100);
          }
          inizializza=' ';
        }

// Max MP3 Random
      if(inizializza=='D'){
			Serial.println(F("Numero Brani da eseguire?")); 
			MP3_file_registrati=Serial.parseInt(SKIP_ALL);
			if (MP3_file_registrati >0 && MP3_file_registrati <11 ){
				Serial.println(MP3_file_registrati);
				Serial.println(F("Registra massimo numero di brani random"));
				ezprom.save(MP3_file_registrati_id, MP3_file_registrati, sizeof(MP3_file_registrati)); 
			}
			else{
				Serial.println(F("Tempo scaduto o numero maggiore di 10 => Premi di nuovo D"));
			}
        inizializza=' ';
      }
       
  }
}
