#include "Shuz.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

Shuz::Shuz()
{
	numCardsDeck1 = 52;
	numCardsDeck2 = 52;
	numCardsDeck3 = 52;
	numCardsDeck4 = 52;
	
	outCards = 0;

}


Shuz::~Shuz(void)
{

}


void Shuz::makeShuz()
{

	int numPoint;
	vector<Card>::iterator i1 = ++d1->begin(); 
	//vector<Card>::iterator i2 = d2->begin();
	//vector<Card>::iterator i3 = d3->begin();
	//vector<Card>::iterator i4 = d4->begin();
	for(int i = 0; i < 4; ++i)
	{
		
		numPoint = 1;
		for(int j = 0; j < 13; ++j)
		{
			if (j < 9)
				++numPoint;
			else if (j == 12)
				numPoint = 11;
			(*i1).makeCard(i, j, numPoint);
			/*(*i2).makeCard(i, j, numPoint);
			(*i3).makeCard(i, j, numPoint);
			(*i4).makeCard(i, j, numPoint);*/
			++i1;
			/*++i2;
			++i3;
			++i4;*/

		}

	}
}

//Card Shuz::getCard()//???
//{
//	//srand(time(0));
//	//int randomDeck = rand()%4+1;//??????
//	//int randomCard = rand()%53;
//	vector<Card>::iterator iter = d1->begin(); 
//	//switch(randomDeck)
//	//{
//	//    case 1: --numCardsDeck1;
//	//		iter = d1->begin();
//	//		return iter += randomCard; break;
//	//	case 2: --numCardsDeck2; return d2[randomCard]; break;
//	//	case 3: --numCardsDeck3; return d3[randomCard]; break;
//	//	case 4: --numCardsDeck4; return d4[randomCard]; break;
//	//}
//	return (*iter);
//}


void Shuz::writeDeck()//int** deck
{
	int tmp = 0;
	vector<Card>::iterator iter; 
	for(int i = 0; i < 4; ++i)
	{
		++tmp;
		for(int j = 0; j < 13; ++j)
		{
			cout << setw(10) << right;
			cout << (*iter).getPoint() << setprecision(4);
			++tmp;
			++iter;
		}
		cout << endl;
	}
}


void Shuz::writeNumCartInDeck()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Колоды:" << setw(5) << "["<< numCardsDeck1 << "]"<< setw(2) << 
		"["<< numCardsDeck2 << "]"<< setw(2) << "["<< numCardsDeck3 << "]"<<
		setw(2) << "["<< numCardsDeck4 << "]"<< endl;
}