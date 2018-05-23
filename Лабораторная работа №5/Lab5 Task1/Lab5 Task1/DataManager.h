#pragma once

#include <set>
#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

template <class T>
class DataManager
{
private:
	T maxCount;
	multiset<T, greater<T>> collection;

public:
	//multiset<T, greater<T>>::iterator mulItr;
	DataManager(void){};
	DataManager(T count) : maxCount(count) {};
	~DataManager(void){};

	
	void push(T elem)//push():данные пишутся на свое порядковое место в наборе (данные должны упорядочиваться по убыванию);
	{
		if(maxCount == 0)
		{
			this->clearSet();
			maxCount = 64;
		}
		--maxCount;
		collection.insert(elem);
	};
	void push(T elem[], int n) 
	{
		for(int i = 0; i < n; ++i)
		{
			if(maxCount == 0)
			{
				this->clearSet();
				maxCount = 64;
			}
			--maxCount;
			collection.insert(elem[i]);
		}
	};
	
	T peek()//peek(): возвращает последний элемент;
	{
		return *(--collection.end());
	};
	
	T pop()//pop(): извлекает предпоследний элемент или последний, если элементов в наборе меньше 2.
	{
		T tmp;
		if(maxCount > 62)
		{
			tmp = *(--collection.end());
			collection.erase(tmp);
			++maxCount;
			return tmp;
		}
		else
		{
			multiset<T, greater<T>>::iterator mulItr;//????
			mulItr = --collection.end();
			--mulItr;//???????
			tmp = *(mulItr);
			collection.erase(tmp);
			
			if(maxCount == 0)
			{
				ifstream fin("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\read.txt", ios_base::in);
				T tmp;
				fin >> tmp;
				collection.insert(tmp);
				fin.close();
			}
			else
			{
				++maxCount;
			}
			return tmp;
		}
	};

	void printAll()
	{
		copy(collection.begin(), collection.end(), ostream_iterator<T>(cout, " "));
		cout << endl;
	};

	void clearSet()
	{
		ofstream fout("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №5\\dump.dat", ios_base::out); 
		multiset<T, greater<T>>::iterator mulItr1;//????
		for(mulItr1 = collection.begin(); mulItr1 != collection.end(); ++mulItr1)
		{
			fout << *mulItr1 << endl;
		}
		fout.close();
		collection.clear();
	};

	void outfile()
	{
		T tmp;
		ifstream fin("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\read.txt", ios_base::in);
		fin >> tmp;//????????????????
		collection.insert(tmp);
		fin.close();
	}
};


////////////////////////////////////////////////////
template <>
class DataManager<char>
{
private:
	char maxCount;
	multiset<char, greater<char>> collection;

public:
	//multiset<T, greater<T>>::iterator mulItr;
	DataManager(void){};
	DataManager(char count) : maxCount(count) {};
	~DataManager(void){};

	
	void push(char elem)//push():данные пишутся на свое порядковое место в наборе (данные должны упорядочиваться по убыванию);
	{
		if(maxCount == 0)
		{
			this->clearSet();
			maxCount = 64;
		}
		--maxCount;
		if(ispunct(elem))
			collection.insert('_');
		else
			collection.insert(elem);
	};
	void push(char elem[], int n) 
	{
		for(int i = 0; i < n; ++i)
		{
			if(maxCount == 0)
			{
				this->clearSet();
				maxCount = 64;
			}
			--maxCount;
			if(ispunct(elem[i]))
				collection.insert('_');
			else
				collection.insert(elem[i]);
		}
	};
	
	char peek()//peek(): возвращает последний элемент;
	{
		return *(--collection.end());
	};
	
	char pop()//pop(): извлекает предпоследний элемент или последний, если элементов в наборе меньше 2.
	{
		char tmp;
		if(maxCount > 62)
		{
			tmp = *(--collection.end());
			collection.erase(tmp);
			++maxCount;
			return tmp;
		}
		else
		{
			multiset<char, greater<char>>::iterator mulItr;//????
			mulItr = --collection.end();
			--mulItr;//???????
			tmp = *(mulItr);
			collection.erase(tmp);
			
			if(maxCount == 0)
			{
				ifstream fin("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\read.txt", ios_base::in);
				char tmp;
				fin >> tmp;
				collection.insert(tmp);
				fin.close();
			}
			else
			{
				++maxCount;
			}
			return tmp;
		}
	};

	void printAll()
	{
		copy(collection.begin(), collection.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
	};

	void clearSet()
	{
		ofstream fout("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №5\\dump.dat", ios_base::out); 
		multiset<char, greater<char>>::iterator mulItr1;//????
		for(mulItr1 = collection.begin(); mulItr1 != collection.end(); ++mulItr1)
		{
			fout << *mulItr1 << endl;
		}
		fout.close();
		collection.clear();
	};

	//void outfile()
	//{
	//	T tmp;
	//	ifstream fin("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №2\\read.txt", ios_base::in);
	//	fin >> tmp;//????????????????
	//	collection.insert(tmp);
	//	fin.close();
	//}
};