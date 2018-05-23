#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(void)
{
}


Card::~Card(void)
{
}


void Card::makeCard(int suit1, int type1, int point1)
{
	suit = suit1;
	type = type1;
	point = point1;
}


int Card::getPoint()
{
	return point;
}


void Card::pritCard()
{
	//cout << this;
	switch(suit)
	{
	    case 0: cout << static_cast<char>(3); break;
		case 1: cout << static_cast<char>(4); break;
		case 2: cout << static_cast<char>(5); break;
		case 3: cout << static_cast<char>(6); break;
	}
	switch(type)
	{
		case 0: cout << point << " "; break;
	    case 1: cout << point << " "; break;
		case 2: cout << point << " "; break;
		case 3: cout << point << " "; break;
		case 4: cout << point << " "; break;
		case 5: cout << point << " "; break;
		case 6: cout << point << " "; break;
		case 7: cout << point << " "; break;
		case 8: cout << point << " "; break;
		case 9: cout << "V" << " "; break;
		case 10: cout << "D" << " "; break;
		case 11: cout << "K" << " "; break;
		case 12: cout << "T" << " "; break;
	}
}


int Card::getSuit()
{
	return suit;
}


ostream& operator<<(ostream& os, const Card& card)
{

	os << static_cast<char>(card.suit + 3);
	if(card.suit <9)
	{
		cout << card.point << " ";
	}
	else
	{
		switch(card.type)
		{

			case 9: cout << "V" << " "; break;
			case 10: cout << "D" << " "; break;
			case 11: cout << "K" << " "; break;
			case 12: cout << "T" << " "; break;
		}
	}
	return os;
}