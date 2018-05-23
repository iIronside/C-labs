#include "Plane.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	const int number = 3;

	char* model1 = "TU-144";
	char* compani1 = "tupolev";
	const int year1 = 1982;
	const int capacity1 = 45;
	
	char* model2 = "Boing 747";
	char* compani2 = "Boing";
	const int year2 = 1985;
	const int capacity2 = 125;
	
	char* model3 = "Antonov";
	char* compani3 = "AN-12";
	const int year3 = 1968;
	const int capacity3 = 35;
	
	char* model4 = "Sukhoi";
	char* compani4 = "SU-35";
	const int year4 = 2008;
	const int capacity4 = 1;
	
	Plane p1;
	Plane p2;
	Plane p3;
	
	p1.setPlane(model1, compani1, year1, capacity1);
	p2.setPlane(model2, compani2, year2, capacity2);
	p3.setPlane(model3, compani3, year3, capacity3);

	Plane massP[number];
	*(massP + 0) = p1;
	*(massP + 1) = p2;
	*(massP + 2) = p3;
	
	Plane* p4 = new Plane(model4, compani4, year4, capacity4);

	double percentP[number] = {0};
	srand(time(NULL));
	double numPassenger = 0;
	double capacity = 0;
	for (int j = 1; j <= number; ++j)
	{
		for (int i = 0; i < number; ++i)
		{
			numPassenger = rand()%126;
			capacity = massP[i].getCapacity();
		if (numPassenger >= capacity)
		{
			percentP[i] += 100;
		}
		else
		{
			percentP[i] += 100/capacity* numPassenger;
		}
		//cout << numPassenger << "p " << capacity<< "c "<< percentP[i]<<"% "<<setprecision(4)  << endl;
		}
	}

	for (int i = 0; i < number; ++i)
	{
		percentP[i]/=3;
		cout << percentP[i]<<"% "<<setprecision(4)  << endl;
	}
	cout << endl;

	if (percentP[0] > percentP[1] && percentP[0] > percentP[2])
	{
		massP[0].printData();
		if (percentP[1] > percentP[2])
		{
			massP[1].printData();
			massP[2].printData();
		}
		else
		{
			massP[2].printData();
			massP[1].printData();
		}
	}
	else if(percentP[1] > percentP[0] && percentP[1] > percentP[2])
	{
		massP[1].printData();
		if (percentP[0] > percentP[2])
		{
			massP[0].printData();
			massP[2].printData();
		}
		else
		{
			massP[2].printData();
			massP[0].printData();
		}
	}
	else
	{
		massP[2].printData();
		if (percentP[0] > percentP[1])
		{
			massP[0].printData();
			massP[1].printData();
		}
		else
		{
			massP[1].printData();
			massP[0].printData();
		}
	}

	for (int i = 0; i < number; ++i)
	{
		massP[i].serialize();
	}
	massP[2].deserialize();
	massP[2].printData();

	string filename1 = "D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\ffff.txt";
	string filename2 = "D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\rrrr.txt";

	massP[2].serialize(filename1);
	massP[2].deserialize(filename2);
	massP[2].printData();
	getchar();
}
