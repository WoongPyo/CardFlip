#include "Card.h"

void Card::SuffleCards()
{
	// 삽입 방식
	int flagOfNum[NUM_OF_CARD] = { 0, };

	// 난수 생성기 시드 지정
	srand((unsigned int)time(NULL));

	int filledSpaceCount = 0;
	do
	{
		int number = (rand() % NUM_OF_CARD);
		if (flagOfNum[number] == FALSE)
		{
			cards[filledSpaceCount] = number;
			flagOfNum[number] = TRUE;
			filledSpaceCount++;
		}
	} while (filledSpaceCount < NUM_OF_CARD);
}


void Card::DuplicateCardNumber()
{
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		int needForDuplicate = i + MAX_CARD_NUM;
		for (int j = 0; j < NUM_OF_CARD; j++)
		{
			if (cards[j] == needForDuplicate)
				cards[j] = i;
		}
	}
}

int Card::ReadCards(int index)
{
	if (index < 0 || index >= NUM_OF_CARD)
		return -1;

	return cards[index];
}

int Card::ReadFlag(int index)
{
	if (index < 0 || index >= NUM_OF_CARD)
		return -1;

	return cardFlag[index];
}

void Card::SetFlag(int index)
{
	cardFlag[index] = TRUE;
}