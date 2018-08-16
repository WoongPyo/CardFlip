#include "Choose.h"


void Choose::ChooseCard(Card* card, Print* print,int cardNum)
{
	int input;
	while (1)
	{
		print->AskingPrint();
		std::cin >> input;
		if (card->ReadFlag(input) != TRUE) // 이미 맞춘 숫자는 입력되지 않음
		{
			if (InputCondition(input, cardNum)) // 하나의 숫자를 만족한다면
			{
				print->EraseExplain();
				break;
			}
		}
		else
		{
			print->AskingOtherNum();
		}
	}
	playerInput[cardNum] = input;
}

bool Choose::InputCondition(int input, int cardNum)
{
	if (cardNum == FIRST_CARD)
		return (!(input / DIGIT_LIMITER));
	else if (cardNum == SECOND_CARD)
		return (!(input / DIGIT_LIMITER) && !(input == playerInput[0]));
}



void Choose::FlipCard(int cardNum, Card* card)
{
	gotoxy(playerInput[cardNum]*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);

	std:: cout << card->ReadCards(playerInput[cardNum]);
}

int Choose::ReadPlayerInput(int index)
{
	if (index < 0 || index >= MAXIMUM_SELECT)
		return -1;
	else
		return playerInput[index];
}