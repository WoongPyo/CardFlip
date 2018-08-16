#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define NUM_OF_CARD 10
#define DISTANCE_BETWEEN_CARD 5
#define CARD_LINE 1

using namespace std;

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

// 
void SuffleCards(int* card)
{
	// ���� ���
	int flagOfNum[NUM_OF_CARD + 1] = { 0, };

	// ���� ������ �õ� ����
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

int main()
{
	int cardFlag[NUM_OF_CARD] = {0};
	int correct=0;
	// ���ڴ� 2���� ������ ��ġ�� ��
	int cards[NUM_OF_CARD];
	SuffleCards(cards);

	for (int i = 0; i < NUM_OF_CARD / 2; i++)
	{
		int numOfChange = i + NUM_OF_CARD / 2;
		for (int j = 0; j < NUM_OF_CARD; j++)
		{
			if (cards[j] == numOfChange)
				cards[j] = i;
		}
	}
	/*
	for (int i = 0; i < NUM_OF_CARD; ++i)
		printf("%d ", cards[i]);

	printf("\n");
	*/

	// �������� ī�尡 ������
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISTANCE_BETWEEN_CARD, 0);
		cout << " "<<i;
	}

	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISTANCE_BETWEEN_CARD, CARD_LINE);
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
		gotoxy(oneDigitPlayerInput1*DISTANCE_BETWEEN_CARD, 1);

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
		gotoxy(oneDigitPlayerInput2*DISTANCE_BETWEEN_CARD, 1);

		cout << cards[oneDigitPlayerInput2];
		Sleep(500);


		/*	ī�尡 ������ ī�尡 ����ؼ� ���� <-- ���� ����������
			ī�尡 �ٸ��� ī�尡 �ٽ� ������ ���� <-- ��ü�� �ƴ�
													�̹� ���� ī��� �״�� �־�� ��.	*/
		if (cards[oneDigitPlayerInput1] != cards[oneDigitPlayerInput2])
		{
			gotoxy(oneDigitPlayerInput1*DISTANCE_BETWEEN_CARD, CARD_LINE);
			cout << "��";
			gotoxy(oneDigitPlayerInput2*DISTANCE_BETWEEN_CARD, CARD_LINE);
			cout << "��";
		}
		else
		{
			cardFlag[oneDigitPlayerInput1] = 1;
			cardFlag[oneDigitPlayerInput2] = 1;
			correct++;
		}
		if (correct == NUM_OF_CARD / 2)
		{
			gotoxy(1, 11);
			cout << "��"<< endl;
			system("pause");
			break;
		}
		/*
		for (int i = 0; i < NUM_OF_CARD; i++) {
			gotoxy(i*DISTANCE_BETWEEN_CARD, 4);
			cout << cardFlag[i];
		}
		*/

	}



	return 0;
}