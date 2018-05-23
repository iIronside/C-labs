#include"Substractor.h"
double Substractor::calculate()
{
	double substract=operands[0];
	for(int i=1;i<size;++i)
	{
		substract-=operands[i];
	}
	return substract;
}
void Substractor::shuffle()
{
	int possicion;
	double tmp;
	for(int i=0; i<size;++i)
	{
		int integral=operands[i];
		if(operands[i]!=integral)
			{
				tmp = operands[i];
				possicion = i;
				break;
			}
	}
	for(int i = size-1; i>=0;++i)
	{
		int integral=operands[i];
		if(operands[i]!=integral)
		{
			operands[possicion]=operands[i];
			operands[i]=tmp;
			break;
		}
	}
}
void Substractor::shuffle(int i, int j)
{
	int integral1=operands[i];
	int integral2=operands[j];
	if(operands[i]!=integral1||operands[j]!=integral2)
	{
	double tmp = operands[i];
	operands[i]=operands[j];
	operands[j]=tmp;
	}
}