#include "InputTwo.h"

void InputTwo::AskingPrint()
{
	gotoxy(0, INPUT_LINE);
	std::cout << "2��° �Է� : ";
	gotoxy(ASKING_INPUT_X_POSITION, INPUT_LINE);
	std::cout << "           ";
	gotoxy(ASKING_INPUT_X_POSITION, INPUT_LINE);
}