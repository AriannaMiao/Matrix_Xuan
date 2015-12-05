#ifndef _matrix_h
#define _matrix_h

#include<iostream>
using namespace std;

class Matrix{
	friend ostream &operator<<(ostream &os, const Matrix& obj);
	friend istream &operator>>(istream &in, Matrix &obj);
	
private:
	int numrow;
	int numcol;
	int **number;

public:
	Matrix(int nr, int nc): numrow(nr), numcol(nc)
	{
		number = new int *[numrow];
		for ( int i = 0; i < numrow; ++i)
			number[i] = new int [numcol];
	}
	Matrix(const Matrix &mat); 
	~Matrix() {delete [] number; }
};

#endif
