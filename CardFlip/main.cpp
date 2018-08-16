#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define NUM_OF_CARD 10
#define DISTANCE_BETWEEN_CARD 5

using namespace std;

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

// 
void SuffleCards(int* card)
{
	// 삽입 방식
	int flagOfNum[NUM_OF_CARD + 1] = { 0, };

	// 난수 생성기 시드 지정
	srand((unsigned int)time(NULL));

	int count = 0;
	do
	{
		int number = (rand() % NUM_OF_CARD) ;
		if (flagOfNum[number] == 0)
		{
			card[count] = number;
			flagOfNum[number] = 1;
			count++;
		}
	} while (count < NUM_OF_CARD);
}

void MakeDuplicate(int* changeCard)
{
	for (int i = 0; i < NUM_OF_CARD / 2; i++)
	{
		int numOfChange = i + NUM_OF_CARD / 2;
		for (int j = 0; j < NUM_OF_CARD; j++)
		{
			if (changeCard[j] == numOfChange)
				changeCard[j] = i;
		}
	}
}

int main()
{
	int cardFlag[NUM_OF_CARD] = {0};
	int correct=0;
	// 숫자당 2개씩 임의의 위치에 들어감
	int cards[NUM_OF_CARD];
	SuffleCards(cards);
	MakeDuplicate(cards);
	/*
	for (int i = 0; i < NUM_OF_CARD; ++i)
		printf("%d ", cards[i]);

	printf("\n");
	*/

	// 뒤집어진 카드가 생성됨

	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISTANCE_BETWEEN_CARD, 1);
		cout << "■";
	}
	while (1)
	{
		// 플레이어가 1번째 카드를 선택함
		int oneDigitPlayerInput1;
		while (1)
		{
			gotoxy(1, 10);
			cout << "1번째 입력 : ";
			gotoxy(15, 10);
			cout << "           ";
			gotoxy(15, 10);
			cin >> oneDigitPlayerInput1;
			if (cardFlag[oneDigitPlayerInput1] != 1)
			{
				if (!(oneDigitPlayerInput1 / 10) && cardFlag[oneDigitPlayerInput1] != 1)
				{
					gotoxy(1, 11);
					cout << "                                                             ";
					break;
				}
			}
			else
			{
				gotoxy(1, 11);
				cout << "이미 맞춘 숫자는 입력할 수 없습니다. 다시 입력하세요.";
			}
		}
		// 첫번재 선택된 카드가 뒤집어짐 <-- 선택된 카드는 그대로 둠
		gotoxy(oneDigitPlayerInput1*DISTANCE_BETWEEN_CARD, 1);

		cout << cards[oneDigitPlayerInput1];


		// 플레이어가 2번재 카드를 선택함
		int oneDigitPlayerInput2;
		while (1)
		{
			gotoxy(1, 10);
			cout << "2번째 입력 : ";
			gotoxy(15, 10);
			cout << "           ";
			gotoxy(15, 10);
			cin >> oneDigitPlayerInput2;
			if (cardFlag[oneDigitPlayerInput2] != 1)
			{
				if ((!(oneDigitPlayerInput2 / 10) && !(oneDigitPlayerInput2 == oneDigitPlayerInput1)))
				{
					gotoxy(1, 11);
					cout << "                                                           ";
					break;
				}
			}
			else
			{
				gotoxy(1, 11);
				cout << "이미 맞춘 숫자는 입력할 수 없습니다. 다시 입력하세요.";
			}
		}
		// 선택된 카드가 뒤집어짐 <-- 0.5초 보여줌
		gotoxy(oneDigitPlayerInput2*DISTANCE_BETWEEN_CARD, 1);

		cout << cards[oneDigitPlayerInput2];
		Sleep(500);


		/*	카드가 같으면 카드가 계속해서 보임 <-- 게임 끝날때까지
			카드가 다르면 카드가 다시 보이지 않음 <-- 전체가 아님
													이미 맞춘 카드는 그대로 있어야 함.	*/
		if (cards[oneDigitPlayerInput1] != cards[oneDigitPlayerInput2])
		{
			gotoxy(oneDigitPlayerInput1*DISTANCE_BETWEEN_CARD, 1);
			cout << "■";
			gotoxy(oneDigitPlayerInput2*DISTANCE_BETWEEN_CARD, 1);
			cout << "■";
		}
		else
		{
			cardFlag[oneDigitPlayerInput1] = 1;
			cardFlag[oneDigitPlayerInput2] = 1;
			correct++;
		}
		if (correct == NUM_OF_CARD / 2)
			break;
		/*
		for (int i = 0; i < NUM_OF_CARD; i++) {
			gotoxy(i*DISTANCE_BETWEEN_CARD, 4);
			cout << cardFlag[i];
		}
		*/

	}



	return 0;
}