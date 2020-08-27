//-------------------------------------------------
void legge_rfid(void){
	int status_=0;
	int test=1;
	bool test_random=0;
	
  if ( ! rfid.PICC_IsNewCardPresent())
    //Serial.println(F("Nessuna card presente"));
    return;
  if ( ! rfid.PICC_ReadCardSerial()) //Legge la card e verifica se questo uid 
    //digitalWrite(LED1,LOW);
    return;                          //è stato registrato. 
  Serial.println(F("Found a card!"));   //uidByte contiene uid della scheda..
  //Serial.print(F("volume =: "));
  //Serial.println(volume); 
  Serial.print(F("UID Value: "));
  for (uint8_t i=0; i < rfid.uid.size; i++){ //Vis. il codice della carta.
    Serial.print(F(" 0x"));                     //
    Serial.print(rfid.uid.uidByte[i], HEX);  //uidByte[] array 10 elem.
  }                           //nella libreria MFRC522.h in struct Uid
  Serial.println();
 
  Serial.println(F(""));
  rfid.PICC_HaltA(); //Halt PICC (evita la continua lettura della scheda)
  for (uint8_t s=0; s < MP3_files; s++){ //Scan RFID UID per associazione 
    test=memcmp(rfid.uid.uidByte,uid_ok[s],rfid.uid.size); //uid file    
    Serial.print(F("Risultato Test: "));
    Serial.println(test);
    if (test==0) {
		  status_=mstatus[s];        //Posizione del brano da riprodurre.
      Serial.print(F("Status: "));
      Serial.println(status_);
      bool test_random=1;
		  break;
	}
	if(!test_random){
		status_=300; //Status per brano random
	}
  } //end for
  
  switch (status_) {           //Do the action related to the status 
	  
//Case Brani MP3
		case 1 ... 200:            //using a State Machine
			Serial.print(F("track: ")); 
			Serial.println(status_); 
      //mp3.setVolume(volume);
      delay(100);
			mp3.playMp3FolderTrack(910); //Bing sound
			delay(500);
			mp3.playMp3FolderTrack(status_); 
      delay(100);
      digitalWrite(LED1,HIGH);
		  break;

//Case Random
		case 300:
			Serial.println(F("Random")); 
      delay(100);
			mp3.playMp3FolderTrack(910); //Bing sound
			delay(500);
			mp3.playMp3FolderTrack(Random());
			
		break;


//Case 900 - Stop
		case 900:
			Serial.println(F("Stop")); 
			mp3.playMp3FolderTrack(910); 
			delay(300);
      digitalWrite(LED1,LOW);
			mp3.stop(); // stop
		  delay(100);
		  break;
		
//Case 901 - Volume+
		case 901:
			if (volume<21){
        digitalWrite(LED2,HIGH);
				Serial.println(F("901 - incrementa volume")); 
				mp3.setVolume(++volume);
        delay(300);
        digitalWrite(LED2,LOW);
        Serial.print(F("Volume: "));
        Serial.println(volume);
			}
		break;
		
//Case 902 - Volume-		
		case 902:
			if (volume>5){
        digitalWrite(LED2,HIGH);
				Serial.println(F("902 - decrementa volume")); 
				mp3.setVolume(--volume);
        delay(300);
        digitalWrite(LED2,LOW);
        Serial.print(F("Volume: "));
        Serial.println(volume);
			}
		  break;

//Case 903 - Master		
		case 903:
			load_rfid();
  		break;
		default:
  		break;
	} //end switch case
} // end 
  
