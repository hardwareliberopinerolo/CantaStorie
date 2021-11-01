# Canta Storie realizzato con Arduino Mini Pro a 3.3V

Il Canta Storie riproduce brani MP3 (come le storie per i bambini) al passagio di Tag RFID

Le storie, in formato MP3, sono salvate su una SD Card e riprodotte dal lettore MP3 DFPlayer

I Tag RFID possono essere riciclati per esempio usando i biglietti usati dei mezzi pubblici che utilizzano questa tecnoligia

Arduino Mini Pro a 3.3V si occupa di gestire la lettura dei Tag RFID ed eseguire i brani MP3

Nella cartella [Arduino Sketches](/00_Arduino_Sketches) sono presenti gli Sketches da caricare su Arduino

Il Canta Storie è in grado di associare in modo automatico i Tag RFID ai brani MP3 che si vogliono riprodurre attraverso l'uso di un Tag RFID Master

**Materiale necessario**
- Arduino Mini Pro a 3.3V
- MP3 DFPlayer
- SD Card con file MP3
- Lettore RFID RC522
- Tessere/Tag RFID

Nella cartella [PCB Kicad](/01_PCB_Kicad) sono presenti gli schemi elettrici per costruire il circuito e il PCB


**Altre Versioni**

[Versione con Arduino Nano e RC522](/10_Other_Versions/Arduino_Nano_RC522): E' una versione che permette di usare Arduino Nano, in modo simile al progetto [TonUINO](https://github.com/seisfeld/TonUINO)

[Versione con Arduino Nano e PN532](/10_Other_Versions)



