#include"Multiplaer.h"
double Multiplaer::calculate()
{
	double multipl=operands[0];
	for(int i=1;i<size;++i)
	{
		multipl*=operands[i];
	}
	return multipl;
}