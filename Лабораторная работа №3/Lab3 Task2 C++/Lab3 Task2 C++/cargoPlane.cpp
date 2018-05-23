#include "cargoPlane.h"
#include <iostream>
#include <string>

using namespace std;

cargoPlane::cargoPlane(void)
{
}


cargoPlane::cargoPlane(string model, string compani, const int year,const int size, int PmaxPayLoad) : Plane(model, compani,year,size)
{
	maxPayLoad = PmaxPayLoad;
	payload = 0;
}


cargoPlane::~cargoPlane(void)
{
}

void cargoPlane::load(int kilograms)
{
	int tmpLoad = kilograms + payload;
	if(tmpLoad > maxPayLoad)
		cout << "Error: too many load" << endl;
	else
		payload = tmpLoad;
}

void cargoPlane::printData()
{
	cout << "model " << model << endl;
	cout << "compani " << compani << endl;
	cout << "year " << year << endl;
	cout << "size " << size << endl;
	cout << "maxPayLoad " << maxPayLoad << endl;
	cout << "payload " << payload << endl;
}