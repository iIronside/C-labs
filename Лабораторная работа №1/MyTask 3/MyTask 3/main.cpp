#include <cstdio>
//#include <cstring>

void main()
{ 
	FILE* f; 
	errno_t err;

	err = fopen_s(&f, "d:\Новый текстовый документ.txt", "rt");
	printf("%s", err);
	fclose(f);

}