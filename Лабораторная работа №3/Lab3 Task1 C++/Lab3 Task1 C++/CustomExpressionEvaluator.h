#pragma once
#include "expressionevaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : virtual public ExpressionEvaluator, virtual public IShuffle
{
public:
	CustomExpressionEvaluator(void);
	CustomExpressionEvaluator(int N);
	~CustomExpressionEvaluator(void);

	void logToScreen();
	void logToFile(std::string filename);
	double calculate();

	void shuffle();
	void shuffle(int i, int j);
};

