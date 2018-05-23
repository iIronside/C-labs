#include"CustomExpressionEvaluator.h"
double CustomExpressionEvaluator::calculate()
{
	double result;
	result = operands[0]+operands[1];
	 for(int i=2;i<size;++i)
	 {
		 result*=operands[i];
	 }
	 return result;
}
void CustomExpressionEvaluator::shuffle()
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
void CustomExpressionEvaluator::shuffle(int i, int j)
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