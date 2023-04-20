#include <iostream>
#include <fstream>
#define PI 3.141592

using namespace std;

class waveHeader {
public:
	waveHeader() {};
	int chunkID, chunkSize, Format, subChunkID, subChunk1size;
	short	audioFormat, numChannels;
	int sampleRate, byteRate;
	short blockAlign, bitsPerSample;
	int subChunk2ID, subChunk2size;
};

float getfrequency(char a);
int getAmplitude(int b);
float getLength(int c, int d);
int sumsum(int*, int);

int main() {

	ifstream aa("Beatles.wav", ios::binary | ios::in);
	if (!aa) return 999;

	waveHeader myHeader;

	aa.read((char*)&myHeader, sizeof(waveHeader));
	myHeader.numChannels = 1;
	myHeader.byteRate = myHeader.sampleRate * sizeof(short);

	int noteNum;
	int* noteLen;
	char* note;
	int* amplitude;
	float* Len;
	float* frequency;
	int* amp;
	
	ifstream xx("OOP.txt");
	xx >> noteNum;
	noteLen = new int[noteNum];
	note =  new char[noteNum];
	amplitude = new int[noteNum];
	Len = new float[noteNum];
	frequency = new float[noteNum];
	amp = new int[noteNum];

	for (int i = 0; i < noteNum; i++)
	{
		xx >> noteLen[i] >> note[i] >> amplitude[i];
		frequency[i] = getfrequency(note[i]);
		amp[i] = getAmplitude(amplitude[i]);
	}

	int totalLen = sumsum(noteLen, noteNum);

	for (int k = 0; k < noteNum; k++)
	{
		Len[k] = getLength(noteLen[k], totalLen);
	}

	short* data;
	int n = myHeader.sampleRate * 5;
	data = new short[n * myHeader.numChannels];
	float dt = 1. / (float)(myHeader.sampleRate);
	float timestack = 0;

	for (int j = 0; j < noteNum ; j++)
	{
		timestack += Len[j];

		for (int i = 0; i < n ; i++)
		{
			if (i > myHeader.sampleRate * timestack)
			{
				float t = i * dt;
				data[i] = (short)(amp[j] * cos(2. * PI * frequency[j] * t));
			}
		}
	}

	// mywave.wav 파일로 저장
	ofstream mywave("mywave.wav", ios::binary | ios::out);
	mywave.write((char*)&myHeader, sizeof(waveHeader));
	mywave.write((char*)data, sizeof(short) * n * myHeader.numChannels);
	mywave.close();
	
}

float getfrequency(char a)
{
	switch (a)
	{
	case 'C':
		return 261.63;
		break;
	case 'D':
		return 293.66;
		break;
	case 'E':
		return 329.63;
		break;
	case 'F':
		return 349.23;
		break;
	case 'G':
		return 392;
		break;
	case 'A':
		return 440;
		break;
	case 'B':
		return 493.88;
		break;
	case 'c':
		return 523.25;
		break;
	case 'd':
		return 587.33;
		break;
	default:
		break;
	}
}

int getAmplitude(int b)
{
	return b * 1000;
}

float getLength(int c, int d)
{
	float T;
	if (c == 4) T = 20. / d;
	else if (c == 8) T = 10. / d;
	else if (c == 16) T = 5. / d;
	return T;
}

int sumsum(int* i, int j)
{
	int M = 0;
	for (int a = 0; a < j; a++)
	{
		M += 16 / i[a];
	}
	return M;
}