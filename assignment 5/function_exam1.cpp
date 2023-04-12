#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int multiply(int a) {
	a *= 5;
	return a;
}

float power(float b) {
	b = b * b;
	return b;
}

int main() {
	int value1[1];
	value1[0] = 1234;
	int value2[5];
	float value3[3];

	for (int i = 0; i < 5; i ++) {
		value2[i] = multiply(1000+500*i);
	}
	for (int j = 0; j < 3; j ++){
		value3[j] = power((0.5*j)-0.5);
	}

	

	ofstream xx("chang.bin", ios::binary | ios::out);
	if (!xx) { return 0; }
	xx.write((char*)value1, 1 * sizeof(int));
	xx.write((char*)value2, 5 * sizeof(int));
	xx.write((char*)value3, 3 * sizeof(float));
	xx.close();

	
	ifstream yy("chang.bin", ios::binary | ios::in);
	if (!yy) { return 0; }
	yy.read((char*)value1, 1 * sizeof(int));
	yy.read((char*)value2, 5 * sizeof(int));
	yy.read((char*)value3, 3 * sizeof(float));
	yy.close();

	cout << value1[0];
	for (int i = 0; i < 5; i++) { cout << value2[i] << " "; }
	for (int i = 0; i < 3; i++) { cout << value3[i] << " "; }
}
