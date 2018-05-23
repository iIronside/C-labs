#include "Shuz.h"
#include <iostream>
using namespace std;
#include <iomanip>

Shuz::Shuz()
{
	deck1 = new int* [4];
	deck2 = new int* [4];
	deck3 = new int* [4];
	deck4 = new int* [4];
}


Shuz::~Shuz(void)
{
	for(int i = 0; i < 4; ++i)//4 - количество строк(мастей)
	{
		delete[] *(deck1 + i);
		delete[] *(deck2 + i);
		delete[] *(deck3 + i);
		delete[] *(deck4 + i);
	}
	delete []deck1;
	delete []deck2;
	delete []deck3;
	delete []deck4;
}


void Shuz::makeShuz()//передовать по ссылке
{
	for(int i = 0; i < 4; ++i)
	{
		*(deck1 + i) = new int[13];
		*(deck2 + i) = new int[13];
		*(deck3 + i) = new int[13];
		*(deck4 + i) = new int[13];
	}
	int numPoint;
	for(int i = 0; i < 4; ++i)
	{
		numPoint = 1;
		for(int j = 0; j < 13; ++j)
		{
			if (j < 9)
				++numPoint;
			else if (j == 12)
				numPoint = 11;
			*(*(deck1 + i) + j) = numPoint;
			*(*(deck2 + i) + j) = numPoint;
			*(*(deck3 + i) + j) = numPoint;
			*(*(deck4 + i) + j) = numPoint;
		}
	}
}

//void Shuz::getCard(){}


void Shuz::writeDeck()//int** deck
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 13; ++j)
		{
			cout << setw(10) << right;
			cout << *(*(deck1 + i) + j) << setprecision(4);
		}
		cout << endl;
	}
}