#include "ExpressionEvaluator.h"
#include <string>
#include <iostream>

ExpressionEvaluator::ExpressionEvaluator(void)
{
	arr1D = new double[20];//выдел€ть пам€ть под 20 операндов
	for(int i = 0; i < 20; ++i)//инициализировать их нул€ми
		*(arr1D + i) = 0;
	number = 20;
}

ExpressionEvaluator::ExpressionEvaluator(int N) : number(N)
{
	arr1D = new double[N];//выдел€ть пам€ть под N операндов
	for(int i = 0; i < N; ++i)//инициализировать их нул€ми
		*(arr1D + i) = 0;
}

ExpressionEvaluator::~ExpressionEvaluator(void)//¬ деструкторе должна освобождатьс€ пам€ть, выделенна€ в конструкторе
{
	delete[] arr1D;
}

void ExpressionEvaluator::setOperand(int pos, double value)//ѕрисвоить значение value одному операнду на позиции pos
{
	*(arr1D + pos) = value;
}

void ExpressionEvaluator::setOperands(double ops[], int N)//«аполнить сразу группу из N операндов массивом значений ops
{
	for (int i = 0; i < N; ++i)
	{
		arr1D[i] = *(ops + i);
	}
}