#include <fstream>
#include <cstdio>
#include <ctime>
using namespace std;

int processArray(int numbers[], int sortNumbers[],int smallNumber, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		numbers[i] = rand()%5+1;
	}
	int nums[5] = {0};
	for (int i = 0; i < size; ++i)
	{
		switch(numbers[i])
		{
		    case 1: nums[0]++;break;
		    case 2: nums[1]++;break;
			case 3: nums[2]++;break;
		    case 4: nums[3]++;break;
			case 5: nums[4]++;break;
		}
	}
	int figure = nums[0];
	for (int i = 1; i < 5; ++i)
	{
		if(figure == 0)
		{
			figure = nums[i];
			smallNumber = i+1;
			break;
		}
		 else if(figure > nums[i])
		{
			figure = nums[i];
			smallNumber = i+1;
		}
	}
	int N = 0;
	for (int i = 0; i < 5; ++i)//"сортировка"
	{
		for (int x = 0; x < nums[i]; ++x)
		{
			sortNumbers[N] = i+1;
			N++; 
		}

	}
	return smallNumber;
}
void writeArray(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}
void main()
{
	int numbers[20] = {0};
	int sortNumbers[20];
	int smallNamber = 1; 
	
	smallNamber = processArray(numbers,sortNumbers,smallNamber,20);
	printf("Input:\n");
	writeArray(numbers, 20);
	printf("\nOutput:\n");
	writeArray(sortNumbers, 20);
	printf("\nLeast_frequent_element = %d\n",smallNamber);
}

