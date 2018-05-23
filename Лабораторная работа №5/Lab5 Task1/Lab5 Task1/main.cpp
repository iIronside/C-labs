#include "DataManager.h"
#include <iostream>

using namespace std;

void main()
{
	int count = 64;

	DataManager<int> numInt(count);
	numInt.push(10);
	int elInt[] = {0, 5, 8, 99, -30, 75, 6, 5, 5};
	numInt.clearSet();
	numInt.push(elInt, 9);
	//numInt.outfile();
	numInt.printAll();

	int nInt = numInt.pop();
	cout << "*" << nInt << "*" << endl; 
	numInt.printAll();
	/////////////////////////////////////

	DataManager<double> numDouble(count);
	numDouble.push(1.95);
	double elDouble[] = {0.33, 5.85, 8.88, 0.99, -30.33, 75.6, 6.6, 5.9, 5.7};
	//numDouble.clearSet();
	numDouble.push(elDouble, 9);
	//numDouble.outfile();
	numDouble.printAll();

	double nDouble = numDouble.pop();
	cout << "*" << nDouble << "*" << endl; 
	numInt.printAll();
	//////////////////////////////////////

	DataManager<char> numChar(count);
	numChar.push('c');
	char elChar[] = {'a', '.', 'b'};
	//numChar.clearSet();
	numChar.push(elChar, 3);
	//numInt.outfile();
	numChar.printAll();

	char nChar = numChar.pop();
	cout << "*" << nChar << "*" << endl; 
	numChar.printAll();

	getchar();
}