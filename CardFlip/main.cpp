#include "main.h"
#include "Card.h"
#include "Print.h"
#include "Choose.h"
#include "InputOne.h"
#include "InputTwo.h"
#include "result.h"

using namespace std;


int main()
{
	Card card;
	// ���ڴ� 2���� ������ ��ġ�� ��

	card.SuffleCards();
	
	card.DuplicateCardNumber();

	
	/*���� ��� ������*/
	/*for (int i = 0; i < NUM_OF_CARD; ++i)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, ANSWER_LINE);
		cout << card.cards[i];
	}*/
	

	// �������� ī�带 ���
	Print print;

	print.PrintNum();
	print.PrintCardBack();

	Result result; // while �� �ȿ��� ������ �ϸ� ��� ���� ���� ������ ��ӵǰ� �Ǿ while �� �ۿ��� ���� �����ϰ� Result Ŭ������ ��� �������� �ʰ���.
	
	enum CardOrder cardOrder; // ������ ���� ���

	while (1)
	{
		Choose choose;

		// �÷��̾ 1��° ī�带 ������
		cardOrder = First;
		InputOne inputOne; // 1��°�� �ι�° ���ÿ��� �޶����� �ణ�� ��� �ڵ��� �����ϱ� ���� �����Լ��� �����.
		choose.ChooseCard(&card, &inputOne, cardOrder); // ù��°�� �ι�° ���ÿ��� �޶����� ���ǹ��� ���� �������� CARD�� ���� ������ ����

		// ù���� ���õ� ī�尡 �������� <-- ���õ� ī��� �״�� ��
		choose.FlipCard(cardOrder, &card);
		

		// �÷��̾ 2���� ī�带 ������
		cardOrder = Second;
		InputTwo inputTwo;
		choose.ChooseCard(&card, &inputTwo, cardOrder);

		// ���õ� ī�尡 �������� <-- 0.5�� ������
		choose.FlipCard(cardOrder, &card);
		Sleep(500);


		/*	ī�尡 ������ ī�尡 ����ؼ� ���� <-- ���� ����������
			ī�尡 �ٸ��� ī�尡 �ٽ� ������ ���� <-- ��ü�� �ƴ�
													�̹� ���� ī��� �״�� �־�� ��.	*/
		result.CorrectOrNot(&choose,&card);

		if (result.ReadCount() >= MAX_CARD_NUM)
			break;

		/*flag*/
		/*for (int i = 0; i < NUM_OF_CARD; i++) {
			gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, FLAG_LINE);
			cout << cardFlag[i];
		}*/
		

	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD CursorPosition = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
