#include "Summator.h"
#include <iostream>
#include <fstream>

using namespace std;

Summator::Summator(void)
{
}

Summator::Summator(int N) : ExpressionEvaluator(N)
{
}

Summator::~Summator(void)
{
}

void Summator::logToScreen()
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
		cout << " plus ";
	}
}

void Summator::logToFile(std::string filename)
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
		fout << " plus ";
	}
	fout << endl;
	fout.close();
}

double Summator::calculate()
{
	double tmp = 0;
	for (int i = 0; i < number; ++i)
	{
		tmp += arr1D[i]; 
	}
	return tmp;
}
