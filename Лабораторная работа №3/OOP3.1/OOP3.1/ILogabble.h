#include<string>
#pragma once
class ILogabble
{
public:
	virtual ~ILogabble(){};
	virtual void logToScreen()=0;
	virtual void logToFile(std::string filename)=0;
};