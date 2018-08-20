#pragma once
#include "choose.h"
#include "Card.h"
#include "Print.h"

class Result
{
private:
	int correctCount = 0;
	

public:
	void CorrectOrNot(Choose* choose, Card* card, Print* print);
	int ReadCount();
};

