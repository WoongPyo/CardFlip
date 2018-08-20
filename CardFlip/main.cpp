#include "main.h"
#include "Card.h"
#include "Print.h"
#include "Choose.h"
#include "InputOne.h"
#include "InputTwo.h"
#include "result.h"
#include "Input.h"

using namespace std;


int main()
{
	Card card;
	// ���ڴ� 2���� ������ ��ġ�� ��
	card.SuffleCards();
	card.DuplicateCardNumber();
	
	/*���� ��� ������*/
	//PrintAnswer(card);	

	// �������� ī�带 ���
	Print print;

	print.PrintNum();
	print.PrintCardBack();

	Result result;
	InputTwo inputTwo;
	InputOne inputOne;
	Input choose;

	while (1)
	{
		// �÷��̾ 1��° ī�带 ������
		choose.ChooseCard(&card, FIRST_CARD, &inputOne);

		// ù���� ���õ� ī�尡 �������� <-- ���õ� ī��� �״�� ��
		print.FlipCard(&card, &choose ,FIRST_CARD);		

		// �÷��̾ 2���� ī�带 ������
		choose.ChooseCard(&card, SECOND_CARD, &inputTwo);

		// ���õ� ī�尡 �������� <-- 0.5�� ������
		print.FlipCard(&card, &choose, SECOND_CARD);
		Sleep(500);

		/*	ī�尡 ������ ī�尡 ����ؼ� ���� <-- ���� ����������
			ī�尡 �ٸ��� ī�尡 �ٽ� ������ ���� <-- ��ü�� �ƴ�
													�̹� ���� ī��� �״�� �־�� ��.	*/
		result.CorrectOrNot(&choose,&card,&print); // ���õ� ī�� 2���� ���� ���� ���ڸ� �޴��� ����� Ȯ���ϰ� ������ ��� ���� flag�� �ø��� �ƴѰ�� ī�带 ������


		if (result.ReadCount() >= MAX_CARD_NUM)
			break;
		/*flag ���̱� ������*/
		//PrintFlag(card);
	}
	return 0;
}

void PrintFlag(Card &card)
{
	for (int i = 0; i < NUM_OF_CARD; i++)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, FLAG_LINE);
		cout << card.ReadFlag(i);
	}
}

void PrintAnswer(Card &card)
{
	for (int i = 0; i < NUM_OF_CARD; ++i)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, ANSWER_LINE);
		cout << card.ReadCards(i);
	}
}

void gotoxy(int x, int y) //Ŀ���� ��ġ�� �Է� �޾� ��ġ��Ŵ
{
	COORD CursorPosition = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
