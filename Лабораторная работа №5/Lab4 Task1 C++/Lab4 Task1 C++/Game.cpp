#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(void)
{
	shuz = 0;
	player = 0;
	dealer = 0;
}

Game::Game(Shuz& shuz, Player& player, Dealer& dealer) : shuz(&shuz), player(&player), dealer(&dealer)
{
}


Game::~Game(void)
{
}


void Game::setPlayerPoints()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Введите количество ваших очков:" << endl;
	int points = 0;
	cin >> points;
	player->setPoints(points);
}

void Game::makeRate()//ставка
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Ваша ставка:" << endl;
	int rate = 0;
	cin >> rate;
	player->takePoints(rate);
}


void Game::takeWin()
{
	int points  = rate * 2;//????
	player->addPoints(points);
}


int Game::getPoints()
{
	int points = player->getBalance();
	return points;
}


void Game::writeNumCartInDeck()
{
	shuz->writeNumCartInDeck();
}

//void Game::setPlayerCart(Card card)
//{
//	player->setCart(card);
//}
//void Game::setDealerCart(Card card)
//{
//	dealer->setCart(card);
//}


void Game::gameInit()
{
		
	this->setPlayerPoints();
	this->makeRate();

	/*player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());
	player->setCart(shuz->getCard());*/

	this->writeNumCartInDeck();

	player->writeHand();
	if(player->getScore() > 21)
	{
		throw ExceptionBJ("Much!");
	}

	/*dealer->setCart(shuz->getCard());
	dealer->setCart(shuz->getCard());*/

	
}