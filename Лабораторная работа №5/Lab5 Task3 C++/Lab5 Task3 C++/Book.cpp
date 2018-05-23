#include "Book.h"


Book::Book(void)
{
}


Book::Book(string name, string writer, int year) : bookName(name), author(writer), yearPublication(year)
{
}


Book::~Book(void)
{
}


string Book::getAuthor()
{
	return this->author;
}


string Book::getBookName()
{
	return this->bookName;
}


int Book::getYear()
{
	return this->yearPublication;
}