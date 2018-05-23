#pragma once
#include "Plane.h"
#include <iostream>
#include <string>
using namespace std;

class passengerPlane : public Plane
{
private:
	int maxNumPassengers;//גלוסעטלמסעü
	int maxPayLoad;
	int numPassengers;
	int payload;
public:
	passengerPlane(void);
	passengerPlane(string model, string compani,const int year, 
		const int size, const int PmaxNumPassengers, const int PmaxPayLoad);
	~passengerPlane(void);

	void setPassengers(int passengers);

	void load(int kilograms);
	void printData();
};

