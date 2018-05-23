#include "Hand.h"


Hand::Hand(void)
{
	numberCards = 0;
	cardsInHand = new Card[11];
}


Hand::~Hand(void)
{
	delete []cardsInHand;
}


void Hand::setCard(Card card)
{
	cardsInHand[numberCards] = card;
	++numberCards;
}


void Hand::clearHand()
{
	/*for(int i = 0; i < 11; ++i)
	{
		*(cardsInHand + i) = 0;
	}*/
}


void Hand::write()
{
	for(int i = 0; i < numberCards; ++i)
	{
		std::cout << cardsInHand[i];//.pritCard();
	}
}