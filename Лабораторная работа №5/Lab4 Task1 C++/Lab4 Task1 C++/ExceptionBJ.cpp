#include "ExceptionBJ.h"


ExceptionBJ::ExceptionBJ(void)
{
}


ExceptionBJ::ExceptionBJ(string m) : message(m)
{
}


ExceptionBJ::~ExceptionBJ(void)
{
}


string ExceptionBJ::getMessage()
{
	return message;
}