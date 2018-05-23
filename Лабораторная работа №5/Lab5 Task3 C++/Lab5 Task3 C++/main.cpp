#include "Book.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<Book*>& books)
{
	vector<Book*>::iterator bookIter;
	for(bookIter = books.begin(); bookIter < books.end(); ++bookIter)
	{
		cout << (*bookIter)->getAuthor() <<" \"" << (*bookIter)->getBookName() << "\"" << std::endl;
	}
}

class BookSorter
{
public:
	bool operator()(Book* book1, Book* book2)
	{
		if((*book1).getAuthor() == (*book2).getAuthor())
		{
			if((*book1).getBookName() > (*book2).getBookName())
				return false;
			else
				return true;
		}
		else
		{
			if((*book1).getAuthor() > (*book2).getAuthor())
				return false;
			else
				return true;
		}
	};
};

class BookFinder
{
private:
	int fromYear;
	int toYear;

public:
	BookFinder(int year1, int year2) : fromYear(year1), toYear(year2)
	{
	};

	bool operator()(Book *book)
	{
		if((*book).getYear() >= fromYear && (*book).getYear() <= toYear)
			return true;
		else
			return false;
	};
};
void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	vector<Book*> books;
	books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011)); 
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009)); 
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001)); 
	books.push_back(new Book("Фауст", "Гёте И.В.", 2010)); 
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));

	print(books);
	//////////////////////////////////////////////////////////
	std::cout << std::endl << "Книги в алфавитном порядке: ";
	std::cout << std::endl << std::endl;

	BookSorter bookSorter;
	std::sort(books.begin(), books.end(), bookSorter);

	print(books);
	/////////////////////////////////////////////
	std::cout << std::endl << "Книги в диапазоне года издания 2005 - 2014: "; std::cout << std::endl << std::endl;

	BookFinder bookFinder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if( books.begin(), books.end(), bookFinder);

	while (finder != books.end())
	{
		std::cout << (*finder)->getAuthor() << " \"" << (*finder)->getBookName() << "\"" << std::endl; finder = std::find_if(++finder, books.end(), bookFinder);
	}
	
	getchar();
}