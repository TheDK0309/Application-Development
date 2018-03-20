#include <stdio.h>
#include <math.h>
#include "appdevwave.h"
#include "screen.h"
#include <curl/curl.h>
void sendData(short int s[]){ 
	int i,j;
	double dbfast[FASTSIZE],sum;
	for(i=0;i<FASTSIZE;i++){
		for(j=0,sum=0.0;j<SAMPLE_PER_SEC/FASTSIZE;j++){
		    sum+= s[i*2000+j]*s[i*2000+j]; //taking the total of every 2000 samples 
		}
	dbfast[i]=20*log10(sqrt(sum)/2000); //taking dB value of rms average of every 2000 samples
	}
#ifdef DEBUG
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<FASTSIZE;i++) printf("%10.2f",dbfast[i]);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
#else
	CURL *curl;
	CURLcode res;
	char postStr[200];
	sprintf(postStr,"df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f",1,dbfast[0],2,dbfast[1],3,dbfast[2],4,dbfast[3],5,dbfast[4],6,dbfast[5],7,dbfast[6],8,dbfast[7]);
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){
	    curl_easy_setopt(curl,CURLOPT_URL,"http://www.cc.puv.fi/~e1400476/xxx.php");
	    curl_easy_setopt(curl,CURLOPT_POSTFIELDS,postStr);
	    res= curl_easy_perform(curl);
	    if(res !=CURLE_OK) printf("curl doesnt work\n");
	    curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
#endif
}
void dispWaveHDR(waveHDR w){
	int i;
#ifdef DEBUG
	printf("ChunkID: ");
	for(i=0;i<4;i++) printf("%c", w.chunkID[i]);
	puts("");
	printf("Chunk size: %d\n", w.chunkSize);
	printf("Format: ");
	for(i=0;i<4;i++) printf("%c", w.format[i]);
	puts("");
	printf("Subchunk1 Size: %d\n", w.subchunk1Size);
	printf("Audio format: %d\n", w.audioFormat);
	printf("No. of Channels: %d\n", w.numChannels);
	printf("Sample rate: %d\n", w.sampleRate);
	printf("Byte rate: %d\n", w.byteRate);
	printf("Block align: %d\n", w.blockAlign);
	printf("Bits per sample: %d\n", w.bitsPerSample);
#else
	clearScreen();
	setXYColor(1,1,RED,bg(BLACK));
	printf("valmis.wav");fflush(stdout);
	setXYColor(15,1,BLUE,bg(BLACK));
	printf("N.Ch. :%1d", w.numChannels);fflush(stdout);
	setXYColor(25,1,GREEN,bg(BLACK));
	printf("Bs/Sp:%2d", w.bitsPerSample);fflush(stdout);
	setXYColor(35,1,YELLOW,bg(BLACK));
	printf("FS:%5d", w.sampleRate);fflush(stdout);
	setXYColor(45,1,CYAN,bg(BLACK));
	printf("DUR:%6.2f", (double)w.subchunk2Size/((w.bitsPerSample/8)*w.numChannels*w.sampleRate));
	fflush(stdout);
	puts("");
#endif
}
void dispSoundWave(short int s[]){
	int i,j;
	double sumRMS,rms,rmsdB;
#ifdef DEBUG
	for(i=0;i<80;i++){
		for(j=0,rms=0.0,sumRMS=0.0;j<200;j++){
			sumRMS += s[i*200+j]*s[i*200+j];
		}
		rms=sqrt(sumRMS)/200;
		rmsdB=20*log10(rms);
		printf("chunk %d:%10.2f,in dB=%10.2f\n",i,rms,rmsdB);
	}
#else
	for(i=0;i<80;i++){
		for(j=0,rms=0.0,sumRMS=0.0;j<200;j++){
			sumRMS+=s[i*200+j]*s[i*200+j];
		}
		rms=sqrt(sumRMS)/200;
		rmsdB=20*log10(rms);
		//gotoxy(i+1,29-round(rmsdB/2.5));
		if(rmsdB>55) setColors(YELLOW,bg(BLACK));
	        displayBar(i+1,29-round(rmsdB/2.5),29);fflush(stdout);
		resetColors();
	}
#endif
}
