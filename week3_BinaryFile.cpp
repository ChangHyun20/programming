#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	char header[12];
	int* n;
	n = (int*)header;
	*n = 100;
	float* f;
	f = (float*)(header + 4);
	*f = 500;
	short* a;
	a = (short*)(header + 8);
	*a = 100;
	short* p;
	p = (short*)(header + 10);
	*p = 0;
	const float pi = 3.141592;
	float dt = 1. / f[0] / 20.0;
	
	ofstream xx("a.dat.bin", ios::binary | ios::out);
	if (!xx) {
		cout << "a.dat.bin 실패" << endl;
	}
	xx.write((char*)header, 12 * sizeof(char));
	xx.close();
	////// a.dat.bin 쓰기

	ifstream yy("a.dat.bin", ios::binary | ios::in);
	if (!yy) {
		cout << "File not found : " << "b.dat.bin\n";
		cout << "";
	}
	yy.read(header, 12 * sizeof(char));
	yy.close();

	/// a.dat.bin 읽기

	*f = 900;
	ofstream ab("b.dat.bin", ios::binary | ios::out);
	if (!ab) return 666;
	ab.write((char*)header, 12 * sizeof(char));
	ab.close();

	
	//// b.dat

	float* fffff;
	int* nn;
	short* aa;
	ifstream yyyy("b.dat.bin", ios::binary | ios::in);
	if (!yyyy) {
		cout << "File not found : " << "b.dat.bin\n";
		return 666;
	}
	yyyy.read(header, 12 * sizeof(char));
	yyyy.close();

	
	fffff = (float*)(header + 4);
	nn = (int*)(header);
	aa = (short*)(header + 8);
	cout << "f= " << *fffff << endl;
	cout << "n= " << *nn << endl;
	cout << "a= " << *aa << endl;




	short* data;
	data = new short[*n];
	
	for (int i = 0; i < n[0]; i++) {
		data[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));
	}
	ofstream zz("a.dat.bin", ios::binary | ios::out);
	if (!zz) return 666;
	zz.write(header, 12 * sizeof(char));
	zz.write((char*)data, n[0] * sizeof(short));
	zz.close();



	short* data1;
	short* data2;
	data1 = new short[*n];
	data2 = new short[*n];
	
	ifstream data11("a.dat.bin", ios::binary | ios::in);
	if (!data11) {
		cout << "File not found : " << "a.dat.bin\n";
		return 666;
	}
	data11.read((char*)data1, n[0] * sizeof(short));
	data11.close();


	short* data3;
	data3 = new short[*n];

	for (int i = 0; i < n[0]; i++) {
		data3[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));
	}
	ofstream zzz("b.dat.bin", ios::binary | ios::out);
	if (!zzz) return 666;
	zzz.write(header, 12 * sizeof(char));
	zzz.write((char*)data3, n[0] * sizeof(short));
	zzz.close();

	ifstream data22("b.dat.bin", ios::binary | ios::in);
	if (!data22) {
		cout << "File not found : " << "b.dat.bin\n";
		return 666;
	}
	data22.read((char*)data2, n[0] * sizeof(short));
	data22.close();

	ofstream xxx("final.txt");
	if (!xxx) return 666;
	for (int i = 0; i < n[0]; i++) {
		xxx << i * dt << " " << data1[i] << " " << data2[i] << endl;
	}
	xxx.close();



	
}