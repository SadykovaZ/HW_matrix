#pragma once
#include <iostream>
using namespace std;
class Matrix
{
	int i, j;
	int** Matr;
public:
	Matrix();
	Matrix(int i, int j, int num =0);
	void print() const;
	int getI() const { return i; };
	int getJ() const { return j; };
	
	void transp();
	void operator*= (int num);
	void operator+= (int num);
	void operator/= (int num);
	void operator-= (int num);

	int* operator[](int i) const;
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& m);
	Matrix(Matrix&& m);
	Matrix& operator=(Matrix&& m);
	~Matrix();
};

bool operator==( const Matrix& m1, const Matrix& m2);
ostream& operator<< (ostream& os, const Matrix& m);