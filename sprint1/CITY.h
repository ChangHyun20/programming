#pragma once
#include <iostream>
#include "FC.h"
class CITY{
public:
	
	CITY() {
		CF[0] = 0;
		CF[1] = 5;
		CF[2] = 10;
		CF[3] = 15;
		CF[4] = 15;
		CF[5] = 18;
		CF[6] = 21;
		CF[7] = 18;
		CF[8] = 14;
		CF[9] = 9;
		CF[10] = 4;
		CF[11] = 0;
	};
	CITY(float cc[12]) { 
		for (int i = 0; i < 12; i++) {
			CF[i] = cc[i];
		}
	};
	float CF[12];
};