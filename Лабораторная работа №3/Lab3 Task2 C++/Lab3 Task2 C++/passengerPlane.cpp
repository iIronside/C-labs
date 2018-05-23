#include "passengerPlane.h"
#include <iostream>
#include <string>

using namespace std;

passengerPlane::passengerPlane(void)
{
}


passengerPlane::passengerPlane(string model, string compani, const int year,const int size, const int PmaxNumPassengers, const int PmaxPayLoad) : Plane(model, compani,year,size)
{
	maxNumPassengers = PmaxNumPassengers;
	maxPayLoad = PmaxPayLoad;
	numPassengers = 0;
	payload = 0;
}


passengerPlane::~passengerPlane(void)
{
}

void passengerPlane::setPassengers(int passengers)
{
	if(passengers <= maxNumPassengers)
	{
		numPassengers = passengers;
		double coefficient = maxPayLoad / maxNumPassengers;
		payload = coefficient * passengers; 
	}
	else
	{
		cout << "Error: too many passengers" << endl;
	}
}

void passengerPlane::load(int kilograms)
{
	int tmpLoad = kilograms + payload;
	if(tmpLoad > maxPayLoad)
		cout << "Error: too many load" << endl;
	else
		payload = tmpLoad;
}

void passengerPlane::printData()
{
	cout << "model " << model << endl;
	cout << "compani " << compani << endl;
	cout << "year " << year << endl;
	cout << "size " << size << endl;
	cout << "maxNumPassengers " << maxNumPassengers << endl;
	cout << "maxPayLoad " << maxPayLoad << endl;
	cout << "numPassengers " << numPassengers << endl;
	cout << "payload " << payload << endl;
}