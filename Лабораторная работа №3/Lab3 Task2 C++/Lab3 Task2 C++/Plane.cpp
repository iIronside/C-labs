#include "Plane.h"
#include <iostream>
#include <string>

using namespace std;

Plane::Plane()
{
}

Plane::Plane(string model, string compani, const int year,const int size) : model(model),
	compani(compani), year(year), size(size)
{
}

Plane::~Plane(void)
{
}