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

	void setOperand(int pos, double value);//- Присвоить значение value одному операнду на позиции pos
	void setOperands(double ops[], int N);//- Заполнить сразу группу из N операндов массивом значений ops
};
#endif

