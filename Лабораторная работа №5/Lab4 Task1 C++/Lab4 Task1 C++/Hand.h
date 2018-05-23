#pragma once
#include "Card.h"

class Hand
{
private:
	int numberCards;
	Card* cardsInHand;

protected:
	Card* card;

public:
	Hand(void);
	~Hand(void);

	void setCard(Card card);
	void clearHand();
	void write();
};

