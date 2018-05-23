#pragma once
#include "myMatrix.h"
class Vector
{
private:
	float* arr1D;
	const int size;
public:
	Vector(const int num);
	~Vector(void);

	void makeArray1D(myMatrix &m, const int N, const int M);
	void printArray1D();
	float operator[](const int index);
};

