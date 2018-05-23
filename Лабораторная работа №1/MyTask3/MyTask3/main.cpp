#include <cstdio>
void main()
{
	FILE* f = fopen("d:\\222.txt", "rt");
	char* x;
	fgets(f,"%s", &x);
	fclose(f);
	printf("x = %d\n", x);
}