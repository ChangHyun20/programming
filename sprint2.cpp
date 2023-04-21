#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main() {
	char header[44];

	
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 666;
	xx.read(header, 44 * sizeof(char));

	short* NumCannels;
	NumCannels = (short*)(header + 22);
	cout << "NumCannels : " << * NumCannels << endl;
	int* SampleRate;
	SampleRate = (int*)(header + 24);
	*SampleRate = 22050;
	cout << "SampleRate : " << *SampleRate << endl;
	int* ByteRate;
	ByteRate = (int*)(header + 28);
	cout << "ByteRate : " << *ByteRate << endl;

	int N = SampleRate[0]*10;
	short* data;
	data = new short[N];
	
	*NumCannels = 1;
	*ByteRate = NumCannels[0] * SampleRate[0] * sizeof(short);
	cout << "변경(ByteRate) : " << *ByteRate << endl;
	xx.read((char*)data, N * sizeof(short));
	xx.close();

	ofstream zz("sprint.wav", ios::binary | ios::out);  // ofstream의 이름 yy는 ifstream의 이름 xx와 다르게 한다.
	if (!zz) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	zz.write(header, 44 * sizeof(char)); // 헤더를 쓴다.
	zz.write((char*)data, N * sizeof(short));
	zz.close();

}