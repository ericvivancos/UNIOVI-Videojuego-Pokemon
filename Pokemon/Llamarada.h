#pragma once
#include "Movement.h"
#include <iostream>
class Llamarada : public Movement
{
public:
	Llamarada();
	virtual void performMove(Pokemon* user, Pokemon* target) override;
};

