#pragma once
#include <string>
#include "Pokemon.h"
class Pokemon;
class Movement
{
public:
	Movement(std::string name, int power, int accuracy);
	//virtual ~Movement();
	virtual void performMove(Pokemon* user, Pokemon* target) = 0;
	std::string name;
	int power;
	int accuracy;
};

