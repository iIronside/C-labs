#include "ExpressionEvaluator.h"
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"
#include <iostream>
using namespace std;
void writeResult(double tmp)
{
	cout << endl;
	cout << "[-RESULT- " << tmp << "]" << endl;
}
void main()
{
	//Создать массив из трех указателей на класс обработки арифметических выражений.
	ExpressionEvaluator* e1 = new Summator();
	ExpressionEvaluator* e2 = new CustomExpressionEvaluator(12);
	ExpressionEvaluator* e3 = new Subtractor();

	double tmpMass[7] = {15, -3.5, 10.5, -2.1, 3.3, 4, 6.3};
	e1->setOperands(tmpMass, 7);

	double tmpMass2[7] = {15, 10, -3, 12, 6.5};
	e2->setOperands(tmpMass, 7);

	e3->setOperand(0, 1.5);
	e3->setOperand(1, 4);
	e3->setOperand(2, -2.5);

    ExpressionEvaluator* mass[3] = {e1, e2, e3};
	string filename = "D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №3\\ffff.txt";
	double tmp = 0;
	for(int i = 0; i < 3; ++i)
	{
		mass[i]->logToScreen();
		mass[i]->logToFile(filename);
		tmp = mass[i]->calculate();
		writeResult(tmp);
	}
	std::cout << std::endl;

	for(int i = 0; i < 3; ++i)
	{
		IShuffle* iss = dynamic_cast<IShuffle*>(mass[i]);
		if(iss)
		{
			iss->shuffle(0,1);
			mass[i]->logToScreen();
		    tmp = mass[i]->calculate();
			writeResult(tmp);

			iss->shuffle();
			mass[i]->logToScreen();
			tmp = mass[i]->calculate();
			writeResult(tmp);
		}
	}
	getchar();
}
