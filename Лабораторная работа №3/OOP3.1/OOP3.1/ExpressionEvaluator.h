#include"ILogabble.h"
#pragma once
class ExpressionEvaluator:public ILogabble
{
public:
	int size;
	double* operands;
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int N);
	virtual ~ExpressionEvaluator();
	void logToScreen();
	void logToFile(std::string filename);
	virtual double  calculate()=0;
	void setOperand(int pos, double value);
	void setOperands(double ops[], int N);
	void Printi();
};