#pragma once
#include <fstream>
using namespace std;
class file {
public:
	file() {};
	file(char* fn) {
		outf.open(fn);
	}
	ofstream outf;
	void write(float a) {
		outf << a << endl;
	}
	void write2(float a) {
		outf << a << " ";
	}
};
