#include "Print.h"

void Print::PrintNum()
{
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, NUM_LINE);
		std::cout << " " << i;
	}
}

void Print::PrintCardBack()
{
	for (int i = 0; i < NUM_OF_CARD; i++) {
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, CARD_LINE);
		std::cout << "��";
	}
}

void Print::AskingPrint()
{
}

void Print::AskingOtherNum()
{
	gotoxy(0, EXPLAIN_LINE);
	std::cout << "                                                                                        ";
	gotoxy(0, EXPLAIN_LINE);
	std::cout << "�̹� ���� ���ڴ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.";
}

void Print::EraseExplain()
{
	gotoxy(0, EXPLAIN_LINE);
	std::cout << "                                                                                        ";
}