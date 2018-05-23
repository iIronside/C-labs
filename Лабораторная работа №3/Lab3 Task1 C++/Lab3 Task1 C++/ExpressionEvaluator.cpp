#include "ExpressionEvaluator.h"
#include <string>
#include <iostream>

ExpressionEvaluator::ExpressionEvaluator(void)
{
	arr1D = new double[20];//�������� ������ ��� 20 ���������
	for(int i = 0; i < 20; ++i)//���������������� �� ������
		*(arr1D + i) = 0;
	number = 20;
}

ExpressionEvaluator::ExpressionEvaluator(int N) : number(N)
{
	arr1D = new double[N];//�������� ������ ��� N ���������
	for(int i = 0; i < N; ++i)//���������������� �� ������
		*(arr1D + i) = 0;
}

ExpressionEvaluator::~ExpressionEvaluator(void)//� ����������� ������ ������������� ������, ���������� � ������������
{
	delete[] arr1D;
}

void ExpressionEvaluator::setOperand(int pos, double value)//��������� �������� value ������ �������� �� ������� pos
{
	*(arr1D + pos) = value;
}

void ExpressionEvaluator::setOperands(double ops[], int N)//��������� ����� ������ �� N ��������� �������� �������� ops
{
	for (int i = 0; i < N; ++i)
	{
		arr1D[i] = *(ops + i);
	}
}