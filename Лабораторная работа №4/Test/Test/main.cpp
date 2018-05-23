#include "Shuz.h"
#include <iostream>
#include <ctime>
void main()
{
	Shuz s1;
	s1.makeShuz();
	s1.writeDeck();
	
	srand(time(0));
	
	for(int i = 0; i < 500; ++i)
	{
		int x = rand()%4;
		std::cout << x << std::endl;
		
	}
	getchar();
}