#pragma once
#include "main.h"

class Card
{
private:
	int cards[NUM_OF_CARD];
	int cardFlag[NUM_OF_CARD] = { 0 };

public:
	void SuffleCards();
	void DuplicateCardNumber();
	int ReadCards(int index);
	int ReadFlag(int index);
	void SetFlag(int index);

};

