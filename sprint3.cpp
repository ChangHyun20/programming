#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float freq(short a) {
	float ff;
	if (a == 1) ff = 261.3;
	else if (a == 2) ff = 293.66;
	else if (a == 3) ff = 329.63;
	else if (a == 4) ff = 349.23;
	else if (a == 5) ff = 392;
	else if (a == 6) ff = 440;
	else if (a == 7) ff = 493.88;
	else if (a == 8) ff = 523.25;
	else if (a == 9) ff = 587.33;
	return ff;
}

int main() {
	char header[44];
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 666;
	xx.read(header, 44 * sizeof(char));

	short* NumCannels;
	NumCannels = (short*)(header + 22);
	cout << *NumCannels << endl;
	int* SampleRate;
	SampleRate = (int*)(header + 24);
	*SampleRate = 22050;
	cout << *SampleRate << endl;
	int* ByteRate;
	ByteRate = (int*)(header + 28);
	cout << *ByteRate << endl;

	int N = SampleRate[0];
	short* data;

	data = new short[N];

	*NumCannels = 1;
	*ByteRate = NumCannels[0] * SampleRate[0] * sizeof(short);
	xx.read((char*)data, N * sizeof(short));
	xx.close();

	const float pi = 3.141592;
	float dt = 1. / SampleRate[0], a = 10000.0;
	for (int i = 0; i < SampleRate[0]; i++) {         // 440Hz�� sine ���� 1�ʺз� ���
		data[i] = (short)(a * sin(2.0 * pi * freq(6) * i * dt));

	}
	ofstream zz("My.wav", ios::binary | ios::out);  // ofstream�� �̸� yy�� ifstream�� �̸� xx�� �ٸ��� �Ѵ�.
	if (!zz) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
	zz.write(header, 44 * sizeof(char)); // ����� ����.
	zz.write((char*)data, N * sizeof(short));
	return 0;// �� ���� �ѹ� �� �����ϸ� 2�ʺз��� �ȴ�.
	zz.close();











}