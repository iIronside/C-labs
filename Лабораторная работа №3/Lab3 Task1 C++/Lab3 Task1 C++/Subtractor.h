#pragma once
#include "expressionevaluator.h"
#include <iostream>

class Subtractor : public ExpressionEvaluator, public IShuffle
{
public:
	Subtractor(void);
	Subtractor(int N);
	~Subtractor(void);

	void logToScreen();
	void logToFile(std::string filename);
	double calculate();

	void shuffle();
	void shuffle(int i, int j);
};

