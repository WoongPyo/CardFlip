#pragma once
#include "main.h"
#include "Card.h"
#include "Choose.h"

class Print
{
public:
	void PrintNum();
	void PrintCardBack();
	
	virtual void AskingPrint();
	void EraseExplain();
	void AskingOtherNum();
	
	void FlipCard(Card* card,Choose* choose,int cardNum);
	void FlipCardAgain(Choose* choose, int cardNum);
};

