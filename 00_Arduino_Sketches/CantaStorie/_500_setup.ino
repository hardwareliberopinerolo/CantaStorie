// ---- SETUP -----------------
void setup(){
  Serial.begin(115200);
  Serial.println("initializing...");
  pinMode(MP3_busy,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  mp3.begin();
  delay(50); 
  mp3.stop(); // stop
  //mp3.setVolume(0);
  mp3.setVolume(volume);
  delay(50);
  uint16_t volume = mp3.getVolume();
  Serial.print("volume ");
  Serial.println(volume);
  uint16_t count = mp3.getTotalTrackCount();
  Serial.print("files ");
  Serial.println(count);
  Serial.println("starting...");
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  ezprom.setOverwriteIfSizeDifferent(true);
  read_eeprom();
  /*
  mp3.reset();
  mp3.setVolume(10);
  mp3.setVolume(--volume);
  delay(100);
  mp3.setVolume(++volume);
  delay(100);
  */
  Serial.println("Waiting for an ISO14443A card");
}
