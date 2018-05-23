#pragma once
#include "Shuz.h"
#include "Player.h"
#include "Dealer.h"
#include "ExceptionBJ.h"
class Game
{
private:
	int rate;//ставка

protected:
	Shuz* shuz;
	Player* player;
	Dealer* dealer;
	
public:
	Game(void);
	Game(Shuz& shuz, Player& player, Dealer& dealer);
	virtual ~Game(void);

	void setPlayerPoints();
	void makeRate();
	void takeWin();

	/*void setPlayerCart(Card card);
	void setDealerCart(Card card);*/

	void writeNumCartInDeck();

	int getPoints();

	void gameInit();
};

