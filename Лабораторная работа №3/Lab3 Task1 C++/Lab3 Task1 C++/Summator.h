#pragma once
#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator
{
public:
	Summator(void);
	Summator(int N);
	~Summator(void);

	void logToScreen();
	void logToFile(std::string filename);
	double calculate();

	void shuffle(){};
	void shuffle(int i, int j){};
};

