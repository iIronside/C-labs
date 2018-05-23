 #pragma once
class Shuz
{
private:
	int** deck1;
	int** deck2;
	int** deck3;
	int** deck4;
public:
	Shuz();
	~Shuz();

	void makeShuz();//передовать по ссылке
	//void getCard();
	void writeDeck();//int** deck
};

