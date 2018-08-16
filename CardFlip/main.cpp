#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "main.h"

#define NUM_OF_CARD 10
#define MAX_CARD_NUM NUM_OF_CARD/2
#define	DIGIT_LIMITER 10

#define DISPALY_TAB_BETWEEN_CARDS 5
#define NUM_LINE 0
#define CARD_LINE 1
#define INPUT_LINE 10
#define EXPLAIN_LINE 11
#define ANSWER_LINE 4
#define FLAG_LINE 6

#define TRUE 1
#define FALSE 0

using namespace std;


int main()
{
	int cards[NUM_OF_CARD];
	int cardFlag[NUM_OF_CARD] = {0};
	int correctCount = 0;
	// 숫자당 2개씩 임의의 위치에 들어감

	SuffleCards(cards);
	
	DuplicateCardNumber(cards);

	
	/*정답*/
	/*for (int i = 0; i < NUM_OF_CARD; ++i)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, ANSWER_LINE);
		cout << cards[i];
	}*/
	

	// 뒤집어진 카드가 생성됨
	PrintCardsNum();

	PrintCardBack();
	while (1)
	{
		// 플레이어가 1번째 카드를 선택함
		int PlayerInput1 = 0;
		PlayerInput1 = ChooseCardOne(PlayerInput1, cardFlag);
		// 첫번재 선택된 카드가 뒤집어짐 <-- 선택된 카드는 그대로 둠
		FlipCard(PlayerInput1, cards);


		// 플레이어가 2번재 카드를 선택함
		int PlayerInput2 = 0;
		PlayerInput2 = ChooseCardTwo(PlayerInput2, cardFlag, PlayerInput1);
		// 선택된 카드가 뒤집어짐 <-- 0.5초 보여줌
		FlipCard(PlayerInput2, cards);
		Sleep(500);


		/*	카드가 같으면 카드가 계속해서 보임 <-- 게임 끝날때까지
			카드가 다르면 카드가 다시 보이지 않음 <-- 전체가 아님
													이미 맞춘 카드는 그대로 있어야 함.	*/
		CorrectOrNot(cards, PlayerInput1, PlayerInput2, cardFlag, correctCount);

		if (correctCount == MAX_CARD_NUM)
			break;

		/*flag*/
		/*for (int i = 0; i < NUM_OF_CARD; i++) {
			gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, FLAG_LINE);
			cout << cardFlag[i];
		}*/
		

	}

	return 0;
}

void CorrectOrNot(int* cards, int PlayerInput1, int PlayerInput2, int* cardFlag, int &correctCount)
{
	if (cards[PlayerInput1] != cards[PlayerInput2])
	{
		gotoxy(PlayerInput1*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "■";
		gotoxy(PlayerInput2*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "■";
	}
	else
	{
		cardFlag[PlayerInput1] = TRUE;
		cardFlag[PlayerInput2] = TRUE;
		correctCount++;
	}
}

int ChooseCardTwo(int PlayerInput2, const int* cardFlag, int PlayerInput1)
{
	while (1)
	{
		gotoxy(0, INPUT_LINE);
		cout << "2번째 입력 : ";
		gotoxy(15, INPUT_LINE);
		cout << "           ";
		gotoxy(15, INPUT_LINE);
		cin >> PlayerInput2;
		if (cardFlag[PlayerInput2] != TRUE)
		{
			if ((!(PlayerInput2 / DIGIT_LIMITER) && !(PlayerInput2 == PlayerInput1)))
				// 하나의 숫자만을 입력받음 && 첫번재 숫자와 동일한 입력은 받지 않음
			{
				gotoxy(0, EXPLAIN_LINE);
				cout << "                                                                                        ";
				break;
			}
		}
		else
		{
			gotoxy(1, EXPLAIN_LINE);
			cout << "                                                                                        ";
			gotoxy(1, EXPLAIN_LINE);
			cout << "이미 맞춘 숫자는 입력할 수 없습니다. 다시 입력하세요.";
		}
	}
	return PlayerInput2;
}

void FlipCard(int FilpNum, int* cards)
{
	gotoxy(FilpNum*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);

	cout << cards[FilpNum];
}

int ChooseCardOne(int PlayerInput1, const int* cardFlag)
{
	while (1)
	{
		gotoxy(0, INPUT_LINE);
		cout << "1번째 입력 : ";
		gotoxy(15, INPUT_LINE);
		cout << "           ";
		gotoxy(15, INPUT_LINE);
		cin >> PlayerInput1;
		if (cardFlag[PlayerInput1] != TRUE) // 이미 맞춘 숫자는 입력되지 않음
		{
			if (!(PlayerInput1 / DIGIT_LIMITER)) // 하나의 숫자만을 입력받음
			{
				gotoxy(0, EXPLAIN_LINE);
				cout << "                                                                                        ";
				break;
			}
		}
		else
		{
			gotoxy(0, EXPLAIN_LINE);
			cout << "                                                                                        ";
			gotoxy(0, EXPLAIN_LINE);
			cout << "이미 맞춘 숫자는 입력할 수 없습니다. 다시 입력하세요.";
		}
	}
	return PlayerInput1;
}

void PrintCardBack()
{
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "■";
	}
}

void PrintCardsNum()
{
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, NUM_LINE);
		cout << " " << i;
	}
}

void DuplicateCardNumber(int* cards)
{
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		int numOfChange = i + MAX_CARD_NUM;
		for (int j = 0; j < NUM_OF_CARD; j++)
		{
			if (cards[j] == numOfChange)
				cards[j] = i;
		}
	}
}

void SuffleCards(int* card)
{
	// 삽입 방식
	int flagOfNum[NUM_OF_CARD] = { 0, };

	// 난수 생성기 시드 지정
	srand((unsigned int)time(NULL));

	int count = 0;
	do
	{
		int number = (rand() % NUM_OF_CARD);
		if (flagOfNum[number] == FALSE)
		{
			card[count] = number;
			flagOfNum[number] = TRUE;
			count++;
		}
	} while (count < NUM_OF_CARD);
}


void gotoxy(int x, int y)
{
	COORD CursorPosition = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
