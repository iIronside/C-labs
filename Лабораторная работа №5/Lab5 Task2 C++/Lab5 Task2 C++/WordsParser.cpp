#include "WordsParser.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

WordsParser::WordsParser(void)
{
}


WordsParser::~WordsParser(void)
{
}


bool is_del(const char& ch)
{
    return ispunct(ch) || isspace(ch);
}


template<class T> inline
void myReplace(T first, T end)
{
	for( ; first != end; ++first)
	{
		switch(*first)
		{
			case '.': *first = ' '; break;
			case ',': *first = ' '; break;
			case '-': *first = ' '; break;
			case ':': *first = ' '; break;
			case '!': *first = ' '; break;
			case ';': *first = ' '; break;
		}
	}
}


void WordsParser::make()
{
	//setlocale( LC_ALL,"Russian" );
	ifstream ifStr("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №5\\Lab5 Task2 C++\\text.txt", ios_base::app);
	string tmpStr, word;// = "These, days people! cannot, imagine! their lives, without modern, technologies in particular without a computer.";
	//stringstream ss(tmpStr);
	//map<string, int>::iterator mI;
	while(ifStr.good())
	{
		getline(ifStr, tmpStr);
		myReplace(tmpStr.begin(), tmpStr.end());		
		/*while(ss >> word)
		{
			wordsList.f
		}*/
		
		cout << tmpStr <<endl;
	}
	getchar();
	ifStr.close();
}


void WordsParser::findNumEntrance()
{

}


void WordsParser::print()
{
	map<string, int>::iterator itMap;
	for(itMap = wordsList.begin(); itMap != wordsList.end(); ++itMap)
	{
		if(itMap->second > 6)
			cout << itMap->first << " " << itMap->second << " ";
	}
}


void WordsParser::writeAll()
{
	map<string, int>::iterator itMap;
	for(itMap = wordsList.begin(); itMap != wordsList.end(); ++itMap)
	{
		if(itMap->second > 6)
			cout << itMap->first << " " << itMap->second << " ";
	}
}