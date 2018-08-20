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
	// 숫자당 2개씩 임의의 위치에 들어감
	card.SuffleCards();
	card.DuplicateCardNumber();
	
	/*정답 출력 디버깅용*/
	//PrintAnswer(card);	

	// 뒤집어진 카드를 출력
	Print print;

	print.PrintNum();
	print.PrintCardBack();

	Result result;
	InputTwo inputTwo;
	InputOne inputOne;
	Input choose;

	while (1)
	{
		// 플레이어가 1번째 카드를 선택함
		choose.ChooseCard(&card, FIRST_CARD, &inputOne);

		// 첫번재 선택된 카드가 뒤집어짐 <-- 선택된 카드는 그대로 둠
		print.FlipCard(&card, &choose ,FIRST_CARD);		

		// 플레이어가 2번재 카드를 선택함
		choose.ChooseCard(&card, SECOND_CARD, &inputTwo);

		// 선택된 카드가 뒤집어짐 <-- 0.5초 보여줌
		print.FlipCard(&card, &choose, SECOND_CARD);
		Sleep(500);

		/*	카드가 같으면 카드가 계속해서 보임 <-- 게임 끝날때까지
			카드가 다르면 카드가 다시 보이지 않음 <-- 전체가 아님
													이미 맞춘 카드는 그대로 있어야 함.	*/
		result.CorrectOrNot(&choose,&card,&print); // 선택된 카드 2개가 서로 같은 숫자를 받는지 결과를 확인하고 같으면 계속 열고 flag를 올리고 아닌경우 카드를 뒤집음


		if (result.ReadCount() >= MAX_CARD_NUM)
			break;
		/*flag 보이기 디버깅용*/
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

void gotoxy(int x, int y) //커서의 위치를 입력 받아 위치시킴
{
	COORD CursorPosition = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
