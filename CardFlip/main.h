#pragma once

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

void gotoxy(int x, int y);

void SuffleCards(int* card);

void PrintCardsNum();

void PrintCardBack();

void FlipCard(int FilpNum, int* cards);

int ChooseCardTwo(int PlayerInput2, const int* cardFlag, int PlayerInput1);

void CorrectOrNot(int* cards, int PlayerInput1, int PlayerInput2, int* cardFlag, int &correctCount);

int ChooseCardOne(int PlayerInput1, const int* cardFlag);

void DuplicateCardNumber(int* cards);
