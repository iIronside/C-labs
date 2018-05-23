#pragma once
#include "Hand.h"

class Player
{
private:
	int balance;

protected:
	int score;
	Hand* hand;

public:
	Player(void);
	virtual ~Player(void);

	void setPoints(int points);
	void addPoints(int points);
	void takePoints(int points);

	int getBalance();

	void writeBalance();
	void setCart(Card card);
	int getScore();

	void writeHand();
};

