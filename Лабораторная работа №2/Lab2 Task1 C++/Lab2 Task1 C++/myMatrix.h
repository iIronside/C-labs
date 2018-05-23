#pragma once
class myMatrix
{
private:
	float** arr2D;
	const int line;
	const int colum;
public:
	myMatrix(const int N, const int M);
	~myMatrix(void);
	

	void initializeArray();
	void printMatrix();
	float getItem(int i, int j);
	void setItem(const int i, const int j, const float number);

	myMatrix& operator++();
	myMatrix operator++(int);
	myMatrix& operator--();
	myMatrix operator--(int);
};

