#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void multiply(float a[5], float b[5]) {
	for (int i = 0; i < 5; i++) {
		a[i] = 1000 + 500 * i;
		b[i] = a[i] * 5;
	}

}

void power(float a[3], float b[3]) {
	for (int i = 0; i < 3; i++) {
		a[i] = 0.5 * i - 0.5;
		b[i] = a[i] * a[i];
	}

}

int main() {
	float* r1, * r2, * r3;
	char save[36];
	float value1[1];
	float value2[5], result2[5];
	float value3[3],result3[3];

	value1[0] = 1234;
	multiply(value2, result2);
	power(value3, result3);

	r1 = value1;
	r2 = result2;
	r3 = result3;


	r1 = (float*)save;
	r2 = (float*)(save+4);
	r3 = (float*)(save+24);

	*r1 = value1[0];
	for (int j = 0; j < 5; j++) { *(r2 + j) = result2[j]; }
	for (int i = 0; i < 3; i++) { *(r3 + i) = result3[i]; }

	

	ofstream xx("chang.bin", ios::binary | ios::out);
	if (!xx) { return 0; }
	xx.write((char*)save, 36);
	xx.close();

	float i1[1], i2[5];
	float i3[3];
	ifstream yy("chang.bin", ios::binary | ios::in);
	if (!yy) { return 0; }
	yy.read((char*)i1, 4);
	yy.read((char*)i2, 20);
	yy.read((char*)i3, 12);
	yy.close();

	cout << i1[0] << endl;
	for (int i = 0; i < 5; i++) { cout << i2[i] << " "; }
	cout << endl;
	for (int i = 0; i < 3; i++) { cout << i3[i] << " "; }
	
}