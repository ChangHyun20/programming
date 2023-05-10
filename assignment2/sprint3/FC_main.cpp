#include <iostream>
using namespace std;
#include "FC.h"
#include "CITY.h"
#include "write.h"


int main() {
	FC fc1;
	fc1.c = 36.5;
	cout << fc1.c << " = " << fc1.getF() << "\n";
	FC* fc2;
	fc2 = new FC;
	fc2->c = 36.5;
	cout << fc2->c << " = " << fc2->getF() << endl;
	FC fc3(36.5);
	cout << fc3.c << " = " << fc3.getF() << "\n";
	FC* fc4 = new FC(36.5);
	cout << fc4->c << " = " << fc4->getF() << endl;

	CITY cities[4];
	ifstream weather1("seoul.txt");
	ifstream weather2("newyork.txt");
	ifstream weather3("london.txt");
	ifstream weather4("paris.txt");
	for (int i = 0; i < 12; i++) {
		weather1 >> cities[0].CF[i];
		weather2 >> cities[1].CF[i];
		weather3 >> cities[2].CF[i];
		weather4 >> cities[3].CF[i];
	}
	weather1.close();
	weather2.close();
	weather3.close();
	weather4.close();

	FC fc5,fc6,fc7,fc8;
	file aa((char*)"total.txt");
	for (int i = 0; i < 12; i++) {
		fc5.c = cities[0].CF[i];
		fc6.c = cities[1].CF[i];
		fc7.c = cities[2].CF[i];
		fc8.c = cities[3].CF[i];
		cout << fc5.getF() << endl;
		cout << fc6.getF() << endl;
		cout << fc7.getF() << endl;
		cout << fc8.getF() << endl;
		aa.write2(fc5.getF());
		aa.write2(fc6.getF());
		aa.write2(fc7.getF());
		aa.write(fc8.getF());
	}
}