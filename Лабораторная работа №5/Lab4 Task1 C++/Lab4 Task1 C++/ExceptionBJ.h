#pragma once
#include <string>

using namespace std;

class ExceptionBJ//������������� �� ��������
{
protected:
	string message;
public:
	ExceptionBJ(void);
	ExceptionBJ(string m);
	~ExceptionBJ(void);

	string getMessage();
};

