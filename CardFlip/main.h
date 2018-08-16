void gotoxy(int x, int y);

void SuffleCards(int* card);

void PrintCardsNum();

void PrintCardBack();

void FlipCard(int FilpNum, int* cards);

int ChooseCardTwo(int PlayerInput2, const int* cardFlag, int PlayerInput1);

void CorrectOrNot(int* cards, int PlayerInput1, int PlayerInput2, int* cardFlag, int &correctCount);

int ChooseCardOne(int PlayerInput1, const int* cardFlag);

void DuplicateCardNumber(int* cards);
