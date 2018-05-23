#include "Subtractor.h"
#include <iostream>
#include <fstream>

using namespace std;

Subtractor::Subtractor(void)
{
}

Subtractor::Subtractor(int N) : ExpressionEvaluator(N)
{
}

Subtractor::~Subtractor(void)
{
}

void Subtractor::logToScreen()
{
	cout << "[" << "-" << number << "- operands]" << endl;
	double tmp = 0;
	for (int i = 0; i < number; ++i)
	{
		tmp = arr1D[i];
		if(tmp > 0)
			cout << tmp;
		else if(tmp != 0)
			cout << "(" << tmp << ")";
		if(arr1D[i+1] == 0 || i == number-1)
			continue;
		cout << " minus ";
	}
}

void Subtractor::logToFile(std::string filename)
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
		if(arr1D[i+1] == 0 || i == number-1)
			continue;
		fout << " minus ";
	}
	fout << endl;
	fout.close();
}

double Subtractor::calculate()
{
	double tmp = arr1D[0];
	for (int i = 1; i < number; ++i)
	{
		tmp -= arr1D[i]; 
	}
	return tmp;
}

void Subtractor::shuffle()
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

void Subtractor::shuffle(int i, int j)
{
	if(arr1D[i] > 0 && arr1D[j] < 0)
	{
		double tmp = arr1D[i];
		arr1D[i] = arr1D[j];
		arr1D[j] = tmp;
	}
}