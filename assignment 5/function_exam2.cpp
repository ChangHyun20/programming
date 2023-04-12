#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void multiply(int a[5],int b[5]) {
	for (int i = 0; i < 5; i++) { 
		a[i] = 1000 + 500 * i; 
		b[i] = a[i]*5;
	}
	
}

void power(float a[3],float b[3]) {
	for (int i = 0; i < 3; i++) {
		a[i] = 0.5 * i - 0.5;
		b[i] = a[i] * a[i];
	}
	
}

int main() {
	int value1[1];
	value1[0] = 1234;
	int value2[5], result2[5];
	multiply(value2, result2);
	float value3[3], result3[3];
	power(value3, result3);




	ofstream xx("chang.bin", ios::binary | ios::out);
	if (!xx) { return 0; }
	xx.write((char*)value1, 1 * sizeof(int));
	xx.write((char*)result2, 5 * sizeof(int));
	xx.write((char*)result3, 3 * sizeof(float));
	xx.close();


	ifstream yy("chang.bin", ios::binary | ios::in);
	if (!yy) { return 0; }
	yy.read((char*)value1, 1 * sizeof(int));
	yy.read((char*)result2, 5 * sizeof(int));
	yy.read((char*)result3, 3 * sizeof(float));
	yy.close();

	cout << value1[0];
	for (int i = 0; i < 5; i++) { cout << result2[i] << " "; }
	for (int i = 0; i < 3; i++) { cout << result3[i] << " "; }
}
