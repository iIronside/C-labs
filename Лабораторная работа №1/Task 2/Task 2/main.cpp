#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printArray2D(float** arr2Dg)
{
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cout << setw(10) << right;
			cout << *(*(arr2Dg + i) +j) << setprecision(4);
		}
		cout << endl;
	}
}

void initializeArray(float** arr2D, int N, int M)
{
	
	for(int i = 0; i < N; ++i)
	{
		*(arr2D + i) = new float[3];
	}
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			*(*(arr2D + i) + j) = sin((float)i-j) + cos((float)i+j);
		}
	}
}

float* makeArray1D(float** arr2D, int N, int M, int num)
{
	int n = 0;
	float* arr1D = new float[num];
	for ( int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			*(arr1D + n) = *(*(arr2D + j) + i);
			++n;
		}
	}
	return arr1D;
}

void printArray1D(float* arr1D, int num)
{
	for ( int i = 0; i < num; ++i)
	{
		cout << *(arr1D + i) << " ";
	}
	cout << endl;
}

void freeArray1D(float* arr1D)
{
	delete []arr1D;
}

void freeArray2D(float** arr2D, int N)
{
	for(int i = 0; i < N; ++i)
	{
		cout << i << endl;
		cout << N << endl;
		delete[] *(arr2D + i);
	}
	delete []arr2D;
}

void main()//память динамически, доступ через указатели, вывод: iostream и iomanip
{
	const unsigned int N = 5;
	const unsigned int M = 3;


	float** arr2D = new float* [N];

	initializeArray(arr2D, N, M);
	printArray2D(arr2D);
	
	int num = N*M;
	float* arr1D = makeArray1D(arr2D, N, M, num);

	printArray1D(arr1D, num);

    freeArray1D(arr1D);

    freeArray2D(arr2D, N);
}