#pragma once
static int counter;
class Fraction
{
private:
	 int numerator;
	 int denumerator;
public:
	Fraction(void);
	Fraction(const int numerator, const int denumerator);
	~Fraction(void);

	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);
	void printCounter();
	int getNumerator();
	int getDenumerator();
	static int gcd(int n, int m);
	void reduce();
	static void printAsFraction(double dec_fraction); 
	static void printAsFraction(char* dec_fraction);

	void print();
};

