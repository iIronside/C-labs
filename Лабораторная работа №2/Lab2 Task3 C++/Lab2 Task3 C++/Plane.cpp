#include "Plane.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

Plane::Plane(void)
{
}

Plane::Plane(string Pmodel, string Pcompani, const int Pyear,
	const int Pcapacity) : model(Pmodel), compani(Pcompani),
	year(Pyear), capacity(Pcapacity)
{
}

Plane::~Plane(void)
{
}

void Plane::setPlane(string Pmodel, string Pcompani, 
	const int Pyear, const int Pcapacity) //: year(Pyear)
{ 
	model = Pmodel;
	compani = Pcompani;
	year = Pyear;
    capacity = Pcapacity;
}

int Plane::getCapacity()
{
	return capacity;
}

void Plane::printData()
{
	cout << model << endl;
	cout << compani << endl;
	cout << year << endl;
	cout << capacity << endl;
	cout << endl;
}

void Plane::serialize()
{
	ofstream fout("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\file.txt", ios_base::app);
	fout << model << endl;
	fout << compani << endl;
	fout << year << endl;
	fout << capacity;
	fout.close();
}

void Plane::deserialize()
{
	ifstream fin("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\read.txt"); 
	getline(fin, model);
	getline(fin, compani);
    fin >> year;
	fin >> capacity;
	fin.close();
}

void Plane::serialize(string filename)
{
	ofstream fout(filename, ios_base::app);
	fout << model << endl;
	fout << compani << endl;
	fout << year << endl;
	fout << capacity;
	fout.close();
}

void Plane::deserialize(string filename)
{
	ifstream fin(filename); 
	getline(fin, model);
	getline(fin, compani);
    fin >> year;
	fin >> capacity;
	fin.close();
}