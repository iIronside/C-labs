#include "Vector.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vector::Vector(const int num) : size(num)
{
	arr1D = new float[size];
}

Vector::~Vector(void)
{
	delete []arr1D;
}

void Vector::makeArray1D(myMatrix &m, const int N, const int M)
{
	int n = 0;
	for ( int i = 1; i <= M; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			*(arr1D + n) = m.getItem(j,i);
			++n;
		}
	}
}

void Vector::printArray1D()
{
	for ( int i = 0; i < size; ++i)
	{
		cout << *(arr1D + i) << " ";
	}
	cout << endl;
}

float Vector::operator[](const int index)
{
	return arr1D[index];
}