#pragma once
#ifndef lab4Task4
#define lab4Task4

using namespace std;
class Card{
	public:
	string suit;
	int value;
	Card(string cardSuit, int cardValue );
	Card();
	void cardPrint();
};

class CardDeck {
public:
	Card* cardArr;
	CardDeck();
	~CardDeck();
};

#endif // !lab4Task4
