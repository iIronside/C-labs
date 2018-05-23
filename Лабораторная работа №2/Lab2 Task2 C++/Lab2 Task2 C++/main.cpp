#include "Fraction.h"
#include <iostream>

void main()
{
	const int x1 = 1;
	const int y1 = 3;

	const int x2 = 5;
	const int y2 = 20;

	Fraction f1(x1,y1);
	Fraction f2(x2,y2);

	Fraction f3 = f1 + f2;
	f3.reduce();
	f3.print();

	Fraction f4 = f1 - f2;
	f4.reduce();
	f4.print();

	Fraction f5 = f1 * f2;
	f5.print();

	Fraction f6 = f1 / f2;
	f6.print();

	int gsdf1 = f1.gcd(f1.getNumerator(), f1.getDenumerator());
	std::cout << gsdf1 << std::endl;
	//int x = Fraction::gcd();
	f1.reduce();
	f1.print();
	f1.printAsFraction(0.45);

	/*f1.printAsFraction("0.12");*/
	f1.printCounter();
}