#include "Result.h"

void Result::CorrectOrNot(Choose* choose, Card* card)
{
	if (card->ReadCards(choose->ReadPlayerInput(FIRST_CARD)) != card->ReadCards(choose->ReadPlayerInput(SECOND_CARD)))
	{
		gotoxy(choose->ReadPlayerInput(FIRST_CARD)*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		std::cout << "бс";
		gotoxy(choose->ReadPlayerInput(SECOND_CARD)*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		std::cout << "бс";
	}
	else
	{
		card->SetFlag(choose->ReadPlayerInput(FIRST_CARD));
		card->SetFlag(choose->ReadPlayerInput(SECOND_CARD));
		correctCount++;
	}
}

int Result::ReadCount()
{
	return correctCount;
}