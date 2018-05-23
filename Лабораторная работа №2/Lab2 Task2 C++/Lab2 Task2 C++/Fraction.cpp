#include "Fraction.h"

#include <iostream>
Fraction::Fraction(void)//const инициализация базового члена класса
{
	counter++;
}

Fraction::Fraction(const int x, const int y) : numerator(x), denumerator(y)
{
	counter++;
}

Fraction::~Fraction(void)
{
}

Fraction Fraction::operator+(const Fraction& f)
{
	int num = numerator * f.denumerator + f.numerator * denumerator;
	int den = f.denumerator * denumerator;
	Fraction tmp(num, den);
	return tmp;
}

Fraction Fraction::operator-(const Fraction& f)
{
	int num = numerator * f.denumerator - f.numerator * denumerator;
	int den = f.denumerator * denumerator;
	Fraction tmp(num, den);
	return tmp;
}

Fraction Fraction::operator*(const Fraction& f)
{
	Fraction tmp(numerator * f.numerator, denumerator * f.denumerator);
	return tmp;
}

Fraction Fraction::operator/(const Fraction& f)
{
	Fraction tmp(numerator * f.denumerator, denumerator * f.numerator);
	return tmp;
}

void Fraction::print()
{
	std::cout << numerator << "/" << denumerator << std::endl;
}

void Fraction::printCounter()
{
	std::cout << counter << std::endl;
}

int Fraction::getDenumerator()
{
	return denumerator;
}
int Fraction::getNumerator()
{
	return numerator;
}

int Fraction::gcd(int n, int m)
{
	if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

void Fraction::reduce()
{
	int gsd = gcd(numerator, denumerator);
	numerator /= gsd;
	denumerator /= gsd;
}

static void printAsFraction(double dec_fraction)
{
	dec_fraction*=100;
	int dsc = Fraction::gcd(dec_fraction,100);
	std::cout<<dec_fraction/dsc<<"/"<<100/dsc<<std::endl;
}

static void printAsFraction(char* dec_fraction)
{
	int a = sizeof(dec_fraction);
	for(int i=0;i<a;++i)
	{
		std::cout<<*(dec_fraction+2+i);
	}
	std::cout<<"/"<<"100"<<std::endl;
}