#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "appdevwave.h"

int main(void){
	waveHDR mywavehdr; // take the waveHDR from appdevwave.h and define mywave as varible
	short int samples[SAMPLE_PER_SEC]; //defined in appdevwave.h
	int i;
	FILE *fp;
	for(i=0;i<10;i++){
		system("arecord -r16000 -c1 -d1 -f S16_LE -q valmis.wav");  //record
		fp = fopen("valmis.wav", "rb"); //open the wav file in binary read only mode
		if(fp == NULL){
			printf("cannot open teh file\n");
			exit(1);
		}
		fread(&mywavehdr, sizeof(mywavehdr),1,fp);
		dispWaveHDR(mywavehdr);	
		fread(&samples, sizeof(short int),SAMPLE_PER_SEC,fp);
		dispSoundWave(samples);
		sendData(samples);
		fclose(fp);
	}
}
