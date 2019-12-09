#include <iostream>
#include <lab4Task4.h>
#include <stdlib.h>
#include <string>
using namespace std;

Card::Card(string cardSuit, int cardValue) {
	suit = cardSuit;
	value = cardValue;
}

Card::Card() {
	suit = "";
	value = 0;
};

void Card::cardPrint() {
	
	if (value == 1)
	{
		cout << suit << " Ace" << endl;
	}

	if (value == 11)
	{
		cout << suit << " Jack" << endl;
	}

	if (value == 12)
	{
		cout << suit << " Queen" << endl;
	}
	
	if (value == 13)
	{
		cout << suit << " King" << endl;
	}
	
	if (value != 1 && value != 11 && value != 12 && value != 13)
	{
		cout << suit << " " << value << endl;
	}
}


CardDeck::CardDeck(){
	cardArr = new Card[52]; 
	int i = 0;
	do // couldn't get a for loop to do this for me and didn't have time to fix it so the solution is not optimal
	{
		cardArr[i].suit = "Spade";
		cardArr[i].value = i + 1;
		i++;
	} while ( i >= 0 && i < 13);
	
	do
	{
		cardArr[i].suit = "Clubs";
		cardArr[i].value = i-12;
		i++;
	} while (i > 13 && i < 26);
	
	do
	{
		cardArr[i].suit = "Diamonds";
		cardArr[i].value = i - 25;
		i++;
	} while (i > 26 && i < 39);

	do
	{
		cardArr[i].suit = "Heart";
		cardArr[i].value = i - 38;
		i++;
	} while (i > 39 && i < 52);
}

CardDeck::~CardDeck(){
	delete[] cardArr;
}

int main() {
	CardDeck cat;

	for (int i = 0; i < 52; i++)
	{
		cat.cardArr[i].cardPrint();
	}

}