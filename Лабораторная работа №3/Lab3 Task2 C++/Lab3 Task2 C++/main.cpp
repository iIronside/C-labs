#include "Plane.h"
#include "passengerPlane.h"
#include "cargoPlane.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	char* model1 = "TU-144";
	char* compani1 = "Tupolev";
	const int year1 = 1975;
	const int size1 = 28;
	const int maxNumPassengers1 = 55;//גלוסעטלמסעü
	const int maxPayLoad1 = 10000;
	
	char* model2 = "Boing 747";
	char* compani2 = "Boing";
	const int year2 = 1985;
	const int size2 = 60;
	const int maxNumPassengers2 = 490;//גלוסעטלמסעü
	const int maxPayLoad2 = 58000;
	
	char* model3 = "Antonov";
	char* compani3 = "Ruslan";
	const int year3 = 1987;
	const int size3 = 73;
	const int maxPayLoad3 = 120000;
	
	char* model4 = "Mriya";
	char* compani4 = "AN-225";
	const int year4 = 1988;
	const int size4 = 100;
	int maxPayLoad4 = 253800;
	
	Plane* p1 = new passengerPlane(model1, compani1, year1, size1, maxNumPassengers1, maxPayLoad1);	
	passengerPlane* passPl1 = dynamic_cast<passengerPlane*>(p1);
	passPl1->setPassengers(40);
	Plane* p2 = new passengerPlane(model2, compani2, year2, size2, maxNumPassengers2, maxPayLoad2);
	passengerPlane* passPl2 = dynamic_cast<passengerPlane*>(p2);
	passPl2->setPassengers(340);
	Plane* p3 = new cargoPlane(model3, compani3, year3, size3, maxPayLoad3);
	Plane* p4 = new cargoPlane(model4, compani4, year4, size4, maxPayLoad4);

	Plane* mass[4] = {p1, p2, p3, p4}; 


	for(int i = 0; i < 4; ++i)
	{
		mass[i]->printData();
		cout << endl;
	}

	for(int i = 0; i < 4; ++i)
	{
		ILoadable* loadPlane = dynamic_cast<ILoadable*>(mass[i]);
		if(loadPlane)
		{
			loadPlane->load(100000);
		}
	}

	for(int i = 0; i < 4; ++i)
	{
		mass[i]->printData();
		cout << endl;
	}
	getchar();
}
