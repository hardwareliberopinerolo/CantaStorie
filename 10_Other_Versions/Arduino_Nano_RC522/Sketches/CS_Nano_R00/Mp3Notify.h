#ifndef MP3NOTIFY_H
#define MP3NOTIFY_H
// implement a notification class,
// its member methods will get called 
//----------------------------------------------
class Mp3Notify{
public:
  static void OnError(uint16_t errorCode){
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);

    /* NOTE
    https://github.com/Makuna/DFMiniMp3/blob/master/src/DFMiniMp3.h
    DfMp3_Error
    // from device
    DfMp3_Error_Busy = 1,
    DfMp3_Error_Sleeping,
    DfMp3_Error_SerialWrongStack,
    DfMp3_Error_CheckSumNotMatch,
    DfMp3_Error_FileIndexOut,
    DfMp3_Error_FileMismatch,
    DfMp3_Error_Advertise,
    // from library
    DfMp3_Error_PacketSize = 0x81,
    DfMp3_Error_PacketHeader,
    DfMp3_Error_PacketChecksum,
    DfMp3_Error_General = 0xff
  */
  }
  //------------------------------------------------- 
  static void OnPlayFinished(uint16_t globalTrack){
    Serial.println();
    //Serial.print("Play finished for #");
    
    Serial.println("Fine lettura brano");
    Serial.println(globalTrack);
    //digitalWrite(LED1,LOW);
  }
  //-----------------------------------------------
  static void OnCardOnline(uint16_t code){
    Serial.println();
    Serial.print("Card online ");
    Serial.println(code);     
  }
  //----------------------------------------------
  static void OnUsbOnline(uint16_t code){
    Serial.println();
    Serial.print("USB Disk online ");
    Serial.println(code);     
  }
  //---------------------------------------------
  static void OnCardInserted(uint16_t code){
    Serial.println();
    Serial.print("Card inserted ");
    Serial.println(code); 
  }
  //--------------------------------------------
  static void OnUsbInserted(uint16_t code){
    Serial.println();
    Serial.print("USB Disk inserted ");
    Serial.println(code); 
  }
  //-------------------------------------------
  static void OnCardRemoved(uint16_t code){
    Serial.println();
    Serial.print("Card removed ");
    Serial.println(code);  
  }
  //------------------------------------------
  static void OnUsbRemoved(uint16_t code){
    Serial.println();
    Serial.print("USB Disk removed ");
    Serial.println(code);  
  }
};
#endif
