#pragma once
#include "card.h"
#include "Print.h"

class Choose
{
private:
	int playerInput[2] = { 0,};
	bool InputCondition(int input, int cardNum);

public:
	void ChooseCard(Card* card, Print* print, int cardNum);
	void FlipCard(int cardNum, Card* card);
	int ReadPlayerInput(int index);
};

