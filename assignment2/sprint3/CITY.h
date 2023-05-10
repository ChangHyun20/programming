#pragma once
#include <iostream>
#include <fstream>
#include "FC.h"
class CITY{
public:
	
	CITY() {};
	CITY(float cc[12]) { 
		for (int i = 0; i < 12; i++) {
			CF[i] = cc[i];
		}
	};
	float CF[12];
};