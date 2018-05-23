#include"CustomExpressionEvaluator.h"
#include"ExpressionEvaluator.h"
#include"ILogabble.h"
#include"IShuffle.h"
#include"Multiplaer.h"
#include"Substractor.h"
void main()
{
	ExpressionEvaluator* A = new Substractor();
	//A->Printi();
	//getchar();
	ExpressionEvaluator* B = new Multiplaer();
	ExpressionEvaluator* C = new CustomExpressionEvaluator();
	
	A->setOperand(1,23.65);
	A->setOperand(2,-12.15);
	B->setOperand(1,2.5);
	B->setOperand(2,-3);
	B->setOperand(3,4);
	B->setOperand(4,-1);
	double ops[]={ 2.5, -5, -3, 2, 10};
	C->setOperands(ops,5);
	getchar();
	ExpressionEvaluator* PointerArray[3]={A,B,C};
	
}