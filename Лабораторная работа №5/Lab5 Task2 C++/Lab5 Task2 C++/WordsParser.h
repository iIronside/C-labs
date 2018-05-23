#pragma once
#include <map>
#include <string>

using namespace std;

class WordsParser
{
private:
	map<string, int> wordsList;
	
public:
	WordsParser(void);
	~WordsParser(void);

	void make();
	void findNumEntrance();
	void print();
	void writeAll(); 

};

