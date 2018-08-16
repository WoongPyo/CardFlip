#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "main.h"

#define NUM_OF_CARD 10
#define DISPALY_TAB_BETWEEN_CARDS 5
#define MAX_CARD_NUM NUM_OF_CARD/2
#define NUM_LINE 0
#define CARD_LINE 1

using namespace std;


int main()
{
	int cards[NUM_OF_CARD];
	int cardFlag[NUM_OF_CARD] = {0};
	int correctCount=0;
	// ���ڴ� 2���� ������ ��ġ�� ��

	SuffleCards(cards);
	
	DuplicateCardNumber(cards);
	/*
	for (int i = 0; i < NUM_OF_CARD; ++i)
		printf("%d ", cards[i]);

	printf("\n");
	*/

	// �������� ī�尡 ������
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, NUM_LINE);
		cout << " " << i;
	}

	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		cout << "��";
	}
	while (1)
	{
		// �÷��̾ 1��° ī�带 ������
		int oneDigitPlayerInput1;
		while (1)
		{
			gotoxy(1, 10);
			cout << "1��° �Է� : ";
			gotoxy(15, 10);
			cout << "           ";
			gotoxy(15, 10);
			cin >> oneDigitPlayerInput1;
			if (cardFlag[oneDigitPlayerInput1] != 1) // �̹� ���� ���ڴ� �Էµ��� ����
			{
				if (!(oneDigitPlayerInput1 / 10)) // �ϳ��� ���ڸ��� �Է¹���
				{
					gotoxy(1, 11);
					cout << "                                                                                        ";
					break;
				}
			}
			else
			{
				gotoxy(1, 11);
				cout << "                                                                                        ";
				gotoxy(1, 11);
				cout << "�̹� ���� ���ڴ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.";
			}
		}
		// ù���� ���õ� ī�尡 �������� <-- ���õ� ī��� �״�� ��
		gotoxy(oneDigitPlayerInput1*DISPALY_TAB_BETWEEN_CARDS, 1);

		cout << cards[oneDigitPlayerInput1];


		// �÷��̾ 2���� ī�带 ������
		int oneDigitPlayerInput2;
		while (1)
		{
			gotoxy(1, 10);
			cout << "2��° �Է� : ";
			gotoxy(15, 10);
			cout << "           ";
			gotoxy(15, 10);
			cin >> oneDigitPlayerInput2;
			if (cardFlag[oneDigitPlayerInput2] != 1)
			{
				if ((!(oneDigitPlayerInput2 / 10) && !(oneDigitPlayerInput2 == oneDigitPlayerInput1))) 
					// �ϳ��� ���ڸ��� �Է¹��� && ù���� ���ڿ� ������ �Է��� ���� ����
				{
					gotoxy(1, 11);
					cout << "                                                                                        ";
					break;
				}
			}
			else
			{
				gotoxy(1, 11);
				cout << "                                                                                        ";
				gotoxy(1, 11);
				cout << "�̹� ���� ���ڴ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.";
			}
		}
		// ���õ� ī�尡 �������� <-- 0.5�� ������
		gotoxy(oneDigitPlayerInput2*DISPALY_TAB_BETWEEN_CARDS, 1);

		cout << cards[oneDigitPlayerInput2];
		Sleep(500);


		/*	ī�尡 ������ ī�尡 ����ؼ� ���� <-- ���� ����������
			ī�尡 �ٸ��� ī�尡 �ٽ� ������ ���� <-- ��ü�� �ƴ�
													�̹� ���� ī��� �״�� �־�� ��.	*/
		if (cards[oneDigitPlayerInput1] != cards[oneDigitPlayerInput2])
		{
			gotoxy(oneDigitPlayerInput1*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
			cout << "��";
			gotoxy(oneDigitPlayerInput2*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
			cout << "��";
		}
		else
		{
			cardFlag[oneDigitPlayerInput1] = 1;
			cardFlag[oneDigitPlayerInput2] = 1;
			correctCount++;
		}
		if (correctCount == NUM_OF_CARD / 2)
		{
			gotoxy(1, 11);
			cout << "��"<< endl;
			system("pause");
			break;
		}
		/*
		for (int i = 0; i < NUM_OF_CARD; i++) {
			gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, 4);
			cout << cardFlag[i];
		}
		*/

	}

	return 0;
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
