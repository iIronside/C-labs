#include <cstdio>
#include <cstring>

const char* getSubstring(const char* string, int size, char c)
{
	if(size > 0)
	{
	    int numC = 0;
	    for(int i = 0; i < size; ++i)//поиск номера "с"
	    {
		    if (string[i] == c)
		    {
			    numC = i;
			    break;
		    }
	    }
		if(numC > 0)
		{
	       int sizeSubstring = size - numC;
	       char* substring = new char[sizeSubstring];

	       for (int i = 0; i <= sizeSubstring; ++i, ++numC)
		       substring[i] = string[numC];

		   return substring;
		}
		return NULL;
	}
	else 
		return NULL;
}
const char* strch(const char* s, char c)
{
	const char* substring = strchr(s, c);
	return substring;
}
void main()// удалять ли массивы строк???
{
	 const char* string = "flkjgfdkhklhkhjhfjhjfk";
	 int size = strlen(string); 
	 char c = 'c';
	 /*printf("%d", size);*/
	 const char* mySubstring = getSubstring(string, size, c);
	 printf("My substring: %s\n", mySubstring);

	 const char* substring = strch(string, c);
	 printf("Substring: %s\n", substring);
}

