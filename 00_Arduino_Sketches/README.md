# Sketches

La cartella contiene lo Sketch Arduino del Canta Storie

Per semplificare la lettura del codice lo sketch è suddiviso in vari file ino in base alla funzionalità che eseguono

**Librerie Utilizzate**

[MP3 DF Player Mini](https://github.com/Makuna/DFMiniMp3)

[RC522 RFID Reader](https://github.com/miguelbalboa/rfid) 

[Ezprom](https://github.com/amirchev/EZPROM) 



**Comandi eseguibili dal Serial Monitor**

- Per resettare la memoria Eeprom premere R nel serial monitor e poi fare l'acquisizione carte


## Esecuzione Brani Random
La nuova funzionalità di eseguire brani in modo random è stata aggiunta col lo Sketch [CS_Random](https://github.com/hardwareliberopinerolo/CantaStorie/tree/master/00_Arduino_Sketches/CS_Random_R03): Se si passa una RFID Card non programmata, viene eseguito un brano a caso
Con questa funzionalità è quindi possibile provare fin da subito il Canta Storie senza programmare le RFID Card



