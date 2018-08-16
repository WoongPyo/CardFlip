#pragma once
#include "choose.h"
#include "Card.h"

class Result
{
private:
	int correctCount ;
	

public:
	void CorrectOrNot(Choose* choose, Card* card);
	int ReadCount();
};

