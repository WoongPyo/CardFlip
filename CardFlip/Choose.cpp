#include "Choose.h"

bool Choose::InputCondition(int input, int cardNum)
{
	if (cardNum == FIRST_CARD)
		return (!(input / DIGIT_LIMITER));
	else if (cardNum == SECOND_CARD)
		return (!(input / DIGIT_LIMITER) && !(input == playerInput[0]));
}

int Choose::ReadPlayerInput(int index)
{
	if (index < 0 || index >= MAXIMUM_SELECT)
		return -1;
	else
		return playerInput[index];
}