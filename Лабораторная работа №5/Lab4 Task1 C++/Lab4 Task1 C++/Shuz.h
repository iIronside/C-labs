#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Shuz
{
private:
	int numCardsDeck1;
	int numCardsDeck2;
	int numCardsDeck3;
	int numCardsDeck4;

	int outCards;//использовано карт

	/*Card** deck1;
	Card** deck2;
	Card** deck3;
	Card** deck4;*/
	vector<Card> d1[52];
	vector<Card> d2[52];
	vector<Card> d3[52];
	vector<Card> d4[52];

protected:
	Card* card;

public:
	Shuz(void);
	~Shuz(void);

	void makeShuz();
	//Card getCard();
	void writeNumCartInDeck();


	void writeDeck();	
};

