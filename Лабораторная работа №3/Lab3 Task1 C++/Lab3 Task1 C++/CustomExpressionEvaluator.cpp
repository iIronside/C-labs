#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator(void)
{
}

CustomExpressionEvaluator::CustomExpressionEvaluator(int N) : ExpressionEvaluator(N)
{
}

CustomExpressionEvaluator::~CustomExpressionEvaluator(void)
{
}

void CustomExpressionEvaluator::logToScreen()
{
	std::cout << "[" << "-" << number << "- operands]" << std::endl;
	double tmp = 0;
	for (int i = 0; i < number; ++i)
	{
		tmp = arr1D[i];
		if(tmp > 0)
			std::cout << tmp;
		else if(tmp != 0)
			std::cout << "(" << tmp << ")";
		if (i == 0)
		{
			std::cout << " divide  ";
			continue;
		}
		if(arr1D[i+1] == 0 || i == number-1)
			continue;
		std::cout << " plus ";
	}
}

void CustomExpressionEvaluator::logToFile(std::string filename)
{
	ofstream fout(filename, ios_base::app);
	fout << "[" << "-" << number << "- operands]" << endl;
	double tmp = 0;
	for (int i = 0; i < number; ++i)
	{
		tmp = arr1D[i];
		if(tmp > 0)
			fout << tmp;
		else if(tmp != 0)
			fout << "(" << tmp << ")";
		if (i == 0)
		{
			fout << " divide  ";
			continue;
		}
		if(arr1D[i+1] == 0 || i == number-1)
			continue;
		fout << " plus ";
	}
	fout << endl;
	fout.close();
}

double CustomExpressionEvaluator::calculate()
{
	double tmp = 0;
	tmp = arr1D[0] / arr1D[1];
	for (int i = 2; i < number; ++i)
	{
		tmp += arr1D[i]; 
	}
	return tmp;
}

void CustomExpressionEvaluator::shuffle()
{
	double tmp = 0;
	for (int i = 0; i < number-1; i++)
	{
		for (int j = number-1; j > i; j--)
		{

		 	 if (arr1D[j - 1] > arr1D[j])
			 {
				 tmp = arr1D[j - 1];
				 arr1D[j - 1] = arr1D[j];
				 arr1D[j] = tmp;
			 }
		 }
	}
}

void CustomExpressionEvaluator::shuffle(int i, int j)
{
	if(arr1D[i] > 0 && arr1D[j] < 0)
	{
		double tmp = arr1D[i];
		arr1D[i] = arr1D[j];
		arr1D[j] = tmp;
	}
}