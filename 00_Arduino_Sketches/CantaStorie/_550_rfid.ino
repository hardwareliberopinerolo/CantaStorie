//-------------------------------------------------
void legge_rfid(void){
	int status_=0;
	int test=1;
  if ( ! rfid.PICC_IsNewCardPresent())
    //Serial.println("Nessuna card presente");
    return;
  if ( ! rfid.PICC_ReadCardSerial()) //Legge la card e verifica se questo uid 
    //digitalWrite(LED1,LOW);
    return;                          //è stato registrato. 
  Serial.println("Found a card!");   //uidByte contiene uid della scheda..
  //Serial.print("volume =: ");
  //Serial.println(volume); 
  Serial.print("UID Value: ");
  for (uint8_t i=0; i < rfid.uid.size; i++){ //Vis. il codice della carta.
    Serial.print(" 0x");                     //
    Serial.print(rfid.uid.uidByte[i], HEX);  //uidByte[] array 10 elem.
  }                           //nella libreria MFRC522.h in struct Uid
  Serial.println();
 
  Serial.println("");
  rfid.PICC_HaltA(); //Halt PICC (evita la continua lettura della scheda)
  for (uint8_t s=0; s < MP3_files; s++){ //Scan RFID UID per associazione 
    test=memcmp(rfid.uid.uidByte,uid_ok[s],rfid.uid.size); //uid file    
    Serial.print("Risultato Test: ");
    Serial.println(test);
    if (test==0) {
		  status_=mstatus[s];        //Posizione del brano da riprodurre.
      Serial.print("Status: ");
      Serial.println(status_);
		  break;
    } 
  } //end for
  switch (status_) {           //Do the action related to the status 
		case 1 ... 200:            //using a State Machine
			Serial.print("track: "); 
			Serial.println(status_); 
      //mp3.setVolume(volume);
      delay(100);
			mp3.playMp3FolderTrack(910); //Bing sound
			delay(500);
			mp3.playMp3FolderTrack(status_); 
      delay(100);
      digitalWrite(LED1,HIGH);
		  break;
		case 900:
			Serial.println("Stop"); 
			mp3.playMp3FolderTrack(910); 
			delay(300);
      digitalWrite(LED1,LOW);
			mp3.stop(); // stop
		  delay(100);
		  break;
		case 901:
			if (volume<21){
        digitalWrite(LED2,HIGH);
				Serial.println("901 - incrementa volume"); 
				mp3.setVolume(++volume);
        delay(300);
        digitalWrite(LED2,LOW);
        Serial.print("Volume: ");
        Serial.println(volume);
			}
		break;
		case 902:
			if (volume>5){
        digitalWrite(LED2,HIGH);
				Serial.println("902 - decrementa volume"); 
				mp3.setVolume(--volume);
        delay(300);
        digitalWrite(LED2,LOW);
        Serial.print("Volume: ");
        Serial.println(volume);
			}
		  break;
		case 903:
			load_rfid();
  		break;
		default:
  		break;
	} //end switch case
} // end 
  
