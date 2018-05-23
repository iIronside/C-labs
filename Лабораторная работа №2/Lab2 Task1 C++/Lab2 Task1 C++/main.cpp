#include "myMatrix.h"
#include "Vector.h"

#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	const  int N = 5;
	const  int M = 3;
	
	myMatrix m1(N, M);

	m1.initializeArray();
	m1.printMatrix();
	
	
	
	const int num = N * M;
	Vector v1(num);

	v1.makeArray1D(m1, N, M);
	v1.printArray1D();
	
	setlocale(LC_ALL, "Russian");
	const int index = 5;
	std::cout << "Запрашиваемый элемент одномерного массива: " << v1[index] << endl;
	
	int i = 5;
	int j = 3;
	float item = m1.getItem(i, j);
	std::cout << "Запрашиваемый элемент двумерного массива: " << item << endl;//подключи библиотеку
	
	const float number = 0.33;//изменение элемента массива
	m1.setItem(i, j, number);
	m1.printMatrix();

	cout << endl;
	++m1;
	m1.printMatrix();

	cout << endl;
	--m1;
	m1.printMatrix();
}
