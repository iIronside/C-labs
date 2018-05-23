#include "Game.h"
#include "Shuz.h"
#include "Player.h"
#include "Dealer.h"
#include "Hand.h"
#include <iostream>

void main()
{
	Shuz shuz;
	shuz.makeShuz();
	shuz.writeDeck();



	/*Player player;
	Dealer dealer;
	Game game(shuz, player, dealer);
	try
	{
		game.gameInit();
	}
	catch(ExceptionBJ& ex)
	{
		std::cout << ex.getMessage() << std::endl;
	}*/
	
}