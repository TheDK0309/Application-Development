#define DEBUG
#define SAMPLE_PER_SEC 16000
#define FASTSIZE 8 

typedef struct{
	char chunkID[4];
	unsigned int chunkSize;
	char format[4];
	char subchunkID[4];
	unsigned int subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	unsigned char subchunk2ID[4];
	unsigned int subchunk2Size;
}waveHDR;

void dispWaveHDR(waveHDR w);
void dispSoundWave(short int []);
void sendData(short int []);
