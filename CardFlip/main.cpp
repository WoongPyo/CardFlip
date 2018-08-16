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
	// ���ڴ� 2���� ������ ��ġ�� ��

	SuffleCards(cards);
	
	DuplicateCardNumber(cards);

	
	/*����*/
	/*for (int i = 0; i < NUM_OF_CARD; ++i)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, ANSWER_LINE);
		cout << cards[i];
	}*/
	

	// �������� ī�尡 ������
	PrintCardsNum();

	PrintCardBack();
	while (1)
	{
		// �÷��̾ 1��° ī�带 ������
		int PlayerInput1 = 0;
		PlayerInput1 = ChooseCardOne(PlayerInput1, cardFlag);
		// ù���� ���õ� ī�尡 �������� <-- ���õ� ī��� �״�� ��
		FlipCard(PlayerInput1, cards);


		// �÷��̾ 2���� ī�带 ������
		int PlayerInput2 = 0;
		PlayerInput2 = ChooseCardTwo(PlayerInput2, cardFlag, PlayerInput1);
		// ���õ� ī�尡 �������� <-- 0.5�� ������
		FlipCard(PlayerInput2, cards);
		Sleep(500);


		/*	ī�尡 ������ ī�尡 ����ؼ� ���� <-- ���� ����������
			ī�尡 �ٸ��� ī�尡 �ٽ� ������ ���� <-- ��ü�� �ƴ�
													�̹� ���� ī��� �״�� �־�� ��.	*/
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
		cout << "��";
		gotoxy(PlayerInput2*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "��";
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
		cout << "2��° �Է� : ";
		gotoxy(15, INPUT_LINE);
		cout << "           ";
		gotoxy(15, INPUT_LINE);
		cin >> PlayerInput2;
		if (cardFlag[PlayerInput2] != TRUE)
		{
			if ((!(PlayerInput2 / DIGIT_LIMITER) && !(PlayerInput2 == PlayerInput1)))
				// �ϳ��� ���ڸ��� �Է¹��� && ù���� ���ڿ� ������ �Է��� ���� ����
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
			cout << "�̹� ���� ���ڴ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.";
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
		cout << "1��° �Է� : ";
		gotoxy(15, INPUT_LINE);
		cout << "           ";
		gotoxy(15, INPUT_LINE);
		cin >> PlayerInput1;
		if (cardFlag[PlayerInput1] != TRUE) // �̹� ���� ���ڴ� �Էµ��� ����
		{
			if (!(PlayerInput1 / DIGIT_LIMITER)) // �ϳ��� ���ڸ��� �Է¹���
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
			cout << "�̹� ���� ���ڴ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.";
		}
	}
	return PlayerInput1;
}

void PrintCardBack()
{
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "��";
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
	// ���� ���
	int flagOfNum[NUM_OF_CARD] = { 0, };

	// ���� ������ �õ� ����
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
