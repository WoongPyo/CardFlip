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
	// 숫자당 2개씩 임의의 위치에 들어감

	card.SuffleCards();
	
	card.DuplicateCardNumber();

	
	/*정답 출력 디버깅용*/
	/*for (int i = 0; i < NUM_OF_CARD; ++i)
	{
		gotoxy(i*DISPALY_TAB_BETWEEN_CARDS, ANSWER_LINE);
		cout << card.cards[i];
	}*/
	

	// 뒤집어진 카드를 출력
	Print print;

	print.PrintNum();
	print.PrintCardBack();

	Result result; // while 문 안에서 선언을 하면 결과 값에 대한 선언이 계속되게 되어서 while 문 밖에서 먼저 선언하고 Result 클래스가 계속 생성되지 않게함.
	
	enum CardOrder cardOrder; // 열거형 변수 사용

	while (1)
	{
		Choose choose;

		// 플레이어가 1번째 카드를 선택함
		cardOrder = First;
		InputOne inputOne; // 1번째와 두번째 선택에서 달라지는 약간의 출력 코딩을 구별하기 위해 가상함수를 사용함.
		choose.ChooseCard(&card, &inputOne, cardOrder); // 첫번째와 두번째 선택에서 달라지는 조건문을 위해 마지막에 CARD에 대한 순서를 정의

		// 첫번재 선택된 카드가 뒤집어짐 <-- 선택된 카드는 그대로 둠
		choose.FlipCard(cardOrder, &card);
		

		// 플레이어가 2번재 카드를 선택함
		cardOrder = Second;
		InputTwo inputTwo;
		choose.ChooseCard(&card, &inputTwo, cardOrder);

		// 선택된 카드가 뒤집어짐 <-- 0.5초 보여줌
		choose.FlipCard(cardOrder, &card);
		Sleep(500);


		/*	카드가 같으면 카드가 계속해서 보임 <-- 게임 끝날때까지
			카드가 다르면 카드가 다시 보이지 않음 <-- 전체가 아님
													이미 맞춘 카드는 그대로 있어야 함.	*/
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
