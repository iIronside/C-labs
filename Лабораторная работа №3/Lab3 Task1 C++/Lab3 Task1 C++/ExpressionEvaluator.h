#ifndef ExpressionEvaluator_H
#define ExpressionEvaluator_H

#include "ILoggable.h"
#include "IShuffle.h"

class ExpressionEvaluator : public ILoggable
{
protected:
	double* arr1D;
	int number;
public:
	ExpressionEvaluator(void);
	ExpressionEvaluator(int N);
	virtual ~ExpressionEvaluator(void);

	virtual void logToScreen() = 0;
	virtual void logToFile(std::string filename) = 0;

	virtual double calculate() = 0;

	void setOperand(int pos, double value);//- ��������� �������� value ������ �������� �� ������� pos
	void setOperands(double ops[], int N);//- ��������� ����� ������ �� N ��������� �������� �������� ops
};
#endif

