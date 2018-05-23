#include "myMatrix.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

myMatrix::myMatrix(const int N, const int M) : line(N), colum(M)
{
	arr2D = new float* [line];
}

myMatrix::~myMatrix()
{
	for(int i = 0; i < line; ++i)
	{
		delete[] *(arr2D + i);
	}
	delete []arr2D;
}

void myMatrix::initializeArray()
{
	
	for(int i = 0; i < line; ++i)
	{
		*(arr2D + i) = new float[colum];
	}
	for(int i = 0; i < line; ++i)
	{
		for(int j = 0; j < colum; ++j)
		{
			*(*(arr2D + i) + j) = sin((float)i-j) + cos((float)i+j);
		}
	}
}

void myMatrix::printMatrix()
{
	for(int i = 0; i < line; ++i)
	{
		for(int j = 0; j < colum; ++j)
		{
			cout << setw(10) << right;
			cout << *(*(arr2D + i) + j) << setprecision(4);
		}
		cout << endl;
	}
}

float myMatrix::getItem(int i, int j)
{
	return *(*(arr2D + (i - 1)) + (j - 1));
}

void myMatrix::setItem(const int i, const int j, const float number)
{
	*(*(arr2D + (i - 1)) + (j - 1)) = number;
}

myMatrix& myMatrix::operator++()
{
	for(int i = 0; i < line; ++i)
	{
		for(int j = 0; j < colum; ++j)
			arr2D[i][j]++;
	}
	return *this;
} 
myMatrix myMatrix::operator++(int)
{
	myMatrix tmp(*this);
	++(*this);
	return tmp;
}

myMatrix& myMatrix::operator--()
{
	for(int i = 0; i < line; ++i)
	{
		for(int j = 0; j < colum; ++j)
			arr2D[i][j]--;
	}
	return *this;
} 

myMatrix myMatrix::operator--(int)
{
	myMatrix tmp(*this);
	--(*this);
	return tmp;
} 