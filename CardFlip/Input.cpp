#include "Input.h"

void Input::ChooseCard(Card* card, int cardNum, Print* print)
{
	int input;
	while (1)
	{
		print->AskingPrint();
		std::cin >> input;
		if (card->ReadFlag(input) != TRUE) // 이미 맞춘 숫자는 입력되지 않음
			if (InputCondition(input, cardNum)) // 하나의 숫자를 만족한다면
			{
				print->EraseExplain();
				break;
			}
		else
			print->AskingOtherNum();
	}
	playerInput[cardNum] = input;
}
