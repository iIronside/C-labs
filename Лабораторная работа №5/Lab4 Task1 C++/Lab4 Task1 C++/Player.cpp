#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(void) : balance(0), score(0)
{
	hand = new Hand();
}


Player::~Player(void)
{
	delete hand;
}


void Player::setPoints(int points)
{
	balance = points;
}


void Player::addPoints(int points)
{
	balance += points;
}


void Player::takePoints(int points)
{
	balance -= points;
}


int Player::getBalance()
{
	return balance;
}


void Player::setCart(Card card)
{
	score += card.getPoint();
	hand->setCard(card);
}


void Player::writeBalance()
{
	cout << balance;
}


void Player::writeHand()
{
	hand->write();
}


int Player::getScore()
{
	return score;
}