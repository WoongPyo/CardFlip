#include "InputOne.h"


void InputOne::AskingPrint()
{
	gotoxy(0, INPUT_LINE);
	std::cout << "1��° �Է� : ";
	gotoxy(ASKING_INPUT_X_POSITION, INPUT_LINE);
	std::cout << "           ";
	gotoxy(ASKING_INPUT_X_POSITION, INPUT_LINE);
}