#pragma once
#include "Player.h"

class Dealer  : public Player
{
private:
	int rate;//ставка
public:
	Dealer(void);
	~Dealer(void);
};
