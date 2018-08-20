#pragma once
#include "Choose.h"
#include "Print.h"

class Input : public Choose
{
public:
	void ChooseCard(Card* card, int cardNum, Print* print);
};

