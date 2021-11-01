long Random(){
	bool ok=0;
	long randNumber;
	static long old_randNumber=0;

	const int minn=10;
	const int maxn=100;

	//randomSeed(analogRead(0));

	do{
		randNumber = random(minn, maxn)/10;
		if (old_randNumber != randNumber){
      if (randNumber <= MP3_file_registrati){
			  ok=1;
      }
		}
	} while(!ok);
	Serial.println(randNumber);
	old_randNumber = randNumber;
	return randNumber;
}
