#include <iostream>
using namespace std;
#include "FC.h"
#include "CITY.h"


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

	CITY jan;
	FC fc5;
	for (int i = 0; i < 12; i++) {
		fc5.c = jan.CF[i];
		cout << fc5.getF() << endl;

	}
}