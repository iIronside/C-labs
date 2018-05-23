#pragma once

#include <string>
using namespace std;

class Plane
{
private:
	string  model;
	string compani;
	int year;
	int capacity;
	
public:
	Plane();
	Plane(string Pmodel, string Pcompani, 
		const int Pyear, const int Pcapacity);
	~Plane(void);

	void setPlane(string Pmodel, string Pcompani, 
		const int Pyear, const int Pcapacity);
	int getCapacity();
	void printData();
	void serialize();
	void setCompani();
	void deserialize();
	void serialize(string filename);
	void deserialize(string filename);
};

