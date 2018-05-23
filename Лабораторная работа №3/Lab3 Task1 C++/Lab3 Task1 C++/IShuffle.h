#pragma once

class IShuffle
{
public:
	~IShuffle(void){};

	virtual void shuffle() = 0;
	virtual void shuffle(int i, int j) = 0;
};