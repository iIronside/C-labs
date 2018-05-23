#pragma once
#include "plane.h"
class cargoPlane : public Plane
{
private:
	int maxPayLoad;
	int payload;
public:
	cargoPlane(void);
	cargoPlane(string model, string compani,const int year,
		const int size, int PmaxPayLoad);
	~cargoPlane(void);

	void load(int kilograms);
	void printData();
};

