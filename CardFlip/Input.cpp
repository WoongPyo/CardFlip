#include "Input.h"

void Input::ChooseCard(Card* card, int cardNum, Print* print)
{
	int input;
	while (1)
	{
		print->AskingPrint();
		std::cin >> input;
		if (card->ReadFlag(input) != TRUE) // �̹� ���� ���ڴ� �Էµ��� ����
			if (InputCondition(input, cardNum)) // �ϳ��� ���ڸ� �����Ѵٸ�
			{
				print->EraseExplain();
				break;
			}
		else
			print->AskingOtherNum();
	}
	playerInput[cardNum] = input;
}
