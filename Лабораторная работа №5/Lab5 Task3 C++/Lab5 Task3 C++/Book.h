#pragma once
#include <string>

using namespace std;

class Book
{
private:
	string author;
	string bookName;
	int yearPublication;

public:
	Book(void);
	Book(string name, string writer, int year);
	~Book(void);

	string getAuthor();
	string getBookName();
	int getYear();
};

