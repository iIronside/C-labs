#include"ExpressionEvaluator.h"
#include<iostream>
ExpressionEvaluator::ExpressionEvaluator()
{
	int size=20;
	operands = new double[20];
	for(int i=0; i<size;++i)
	{
		operands[i]=0;
	}
	std::cout<<"OK";
}
ExpressionEvaluator::ExpressionEvaluator(int N):size(N)
{
	operands = new double[size];
	for(int i=0; i<size;++i)
	{
		operands[i]=0;
	}
}
void ExpressionEvaluator::setOperand(int pos, double value)
{
	operands[pos]=value;
}
void ExpressionEvaluator::setOperands(double ops[], int N)
{
	for(int i=0;i<N;++i)
	{
		operands[i]=ops[i];
	}
}
ExpressionEvaluator::~ExpressionEvaluator()
{
	delete operands;
}
void ExpressionEvaluator::logToScreen(){}
void ExpressionEvaluator::logToFile(std::string filename){}
void ExpressionEvaluator::Printi()
{
	for(int i=0; i<size;++i)
	std::cout<<operands[i];
}