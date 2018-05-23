#include"ExpressionEvaluator.h"
#include"IShuffle.h"
#pragma once
class Substractor:public ExpressionEvaluator,public IShuffle
{
public:
	double calculate();
	void shuffle();
	void shuffle(int i, int j);
};