#include"ExpressionEvaluator.h"
#include"IShuffle.h"
#pragma once
class CustomExpressionEvaluator:public ExpressionEvaluator,public IShuffle
{
public:
	double calculate();
	void shuffle();
	void shuffle(int i, int j);

};