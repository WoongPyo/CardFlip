#include "Result.h"

void Result::CorrectOrNot(Choose* choose, Card* card, Print* print)
{
	if (card->ReadCards(choose->ReadPlayerInput(FIRST_CARD)) == card->ReadCards(choose->ReadPlayerInput(SECOND_CARD)))
	{
		card->SetFlag(choose->ReadPlayerInput(FIRST_CARD));
		card->SetFlag(choose->ReadPlayerInput(SECOND_CARD));
		correctCount++;
	}
	else
	{
		print->FlipCardAgain(choose, FIRST_CARD);
		print->FlipCardAgain(choose, SECOND_CARD);
	}
}

int Result::ReadCount()
{
	return correctCount;
}