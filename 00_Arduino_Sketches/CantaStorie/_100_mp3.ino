/* Inizialize MP3 player
 *  
 */
#include <SoftwareSerial.h>
#include "Mp3Notify.h"
#include <DFMiniMp3.h>
// instance a DFMiniMp3 object, 
// defined with the above notification class and the hardware serial class
//DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial1);
SoftwareSerial secondarySerial(4, 3);

DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);
/* NOTES Library MP3
DF Player Library
https://github.com/Makuna/DFMiniMp3/blob/master/src/DFMiniMp3.h
it expects the sd card to contain these three mp3 files but 
doesn't care whats in them
 sd:/mp3/0001.mp3
 sd:/mp3/0002.mp3
 sd:/mp3/0003.mp3

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
