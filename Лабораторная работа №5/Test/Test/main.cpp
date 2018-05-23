#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

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
void main()
{
	map <string,int> words;
	ifstream in;
	in.open("D:\\Мои документы\\Програмирование 2-й курс\\Лабораторная работа №5\\Lab5 Task2 C++\\text.txt", ios_base::app);
	string word;
	while (in >> word)
	{
		myReplace(word.begin(), word.end());
		if(word.size() > 3)
		{
			words[word]++;
		}
	}
	map <string,int>::iterator cur;
	multimap <int, string, std::greater<int>> sortWords;
	for(cur=words.begin();cur!=words.end();cur++)
		{
			sortWords.insert(std::make_pair(cur->second,cur->first));
		}
	cout<<"Words count:"<<endl;
	multimap <int, string, std::greater<int>>::iterator sortCur;
	for (sortCur = sortWords.begin(); sortCur != sortWords.end(); ++sortCur)
	{
		if((*sortCur).first > 7)
			cout<<(*sortCur).first<<": "<<(*sortCur).second << endl;
	}
	getchar();
}