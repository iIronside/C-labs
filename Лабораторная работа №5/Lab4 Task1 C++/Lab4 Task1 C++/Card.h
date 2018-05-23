#pragma once
#include <iostream>

class Card
{
private:
	int suit;
	int type;
	int point;

public:
	Card(void);
	~Card(void);

	void makeCard(int suit1, int type1, int point1);
	void pritCard();

	int getPoint();

	int getSuit();
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

