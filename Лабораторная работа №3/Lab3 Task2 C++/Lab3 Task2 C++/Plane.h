#pragma once
#include "ILoadable.h"
#include <string>
using namespace std;

class Plane : public ILoadable
{
protected:
	string  model;
	string compani;
	int year;
	int size;
public:
	Plane();
	Plane(string model, string compani, const int year, const int size);
	~Plane(void);

	virtual void printData() = 0;

	virtual void load(int kilograms) = 0;
};

