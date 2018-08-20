#pragma once
#include "card.h"

class Choose
{
protected:
	int playerInput[2] = { 0,};
	bool InputCondition(int input, int cardNum);

public:
	int ReadPlayerInput(int index);
};

