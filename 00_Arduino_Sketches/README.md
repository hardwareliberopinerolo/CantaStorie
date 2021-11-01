# Sketches

La cartella contiene lo [Sketch per Arduino Mini Pro a 3.3V](https://github.com/hardwareliberopinerolo/CantaStorie/tree/master/00_Arduino_Sketches/CantaStorie) del Canta Storie

Per semplificare la lettura del codice lo sketch è suddiviso in vari file ino in base alla funzionalità che eseguono

Ricordati di selezionare nel ArduinoIDE come Board: Arduino Mini Pro a 3.3V 


**Librerie Utilizzate**

[MP3 DF Player Mini](https://github.com/Makuna/DFMiniMp3)

[RC522 RFID Reader](https://github.com/miguelbalboa/rfid) 

[Ezprom](https://github.com/amirchev/EZPROM) 



**Comandi eseguibili dal Serial Monitor**

Premere nel serial monitor:

- R: Per resettare la memoria Eeprom e poi fare l'acquisizione carte
- L: per mostrare i codici RFID delle carte registrate
- M: per settare o Resettare la Master RFID card
- "+ / -" : Per aumentare o diminuire il volume
- D: per settare quanti brani random eseguire


## Esecuzione Brani Random
La nuova funzionalità di eseguire brani in modo random è stata aggiunta col lo Sketch [CS_Random](https://github.com/hardwareliberopinerolo/CantaStorie/tree/master/00_Arduino_Sketches/CS_Random_R03): Se si passa una RFID Card non programmata, viene eseguito un brano a caso
Con questa funzionalità è quindi possibile provare fin da subito il Canta Storie senza programmare le RFID Card



