#ifndef _matrix_h
#define _matrix_h

#include<iostream>
using namespace std;

class Matrix{
	friend ostream &operator<<(ostream &os, const Matrix& obj)
	{
		os << obj.numrow << " " << obj.numcol << "\n";
		for ( int i = 0; i < obj.numrow; ++i)
		{
			for ( int j = 0; j < obj.numcol; ++j)
				os << obj.number[i][j] << " ";
			os << "\n";
		}
		os << endl;
		return os;
	}
	
	friend istream &operator>>(istream &is, Matrix &obj)
	{
		is >> obj.numrow;
		is >> obj.numcol;
		obj.number = new int *[obj.numrow];
		for ( int i = 0; i < obj.numrow; ++i)
			obj.number[i] = new int [obj.numcol];
		for ( int i = 0; i < obj.numrow; ++i)
			for ( int j = 0; j < obj.numcol; ++j)
				is >> obj.number[i][j];
		return is;
	}
	
	friend Matrix operator+(const Matrix &m1, const Matrix &m2)
	{
		Matrix tmp(m1.numrow, m1.numrow);
		for ( int i = 0; i < m1.numrow; ++i)
			for ( int j = 0; j < m1.numcol; ++j)
				tmp.number[i][j] = m1.number[i][j] + m2.number[i][j];
		return tmp;
	}
	
	friend bool operator==(const Matrix &obj1, const Matrix &obj2)
	{
		if ( obj1.numrow != obj2.numrow || obj1.numcol != obj2.numcol )
			return false;
		for ( int i = 0; i < obj1.numrow; ++i)
			for ( int j = 0; j < obj1.numcol; ++j)
				if ( obj1.number[i][j] != obj2.number[i][j] )
					return false;
		return true;
	}
	
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
	
	Matrix()
	{
		numrow = 0;
		numcol = 0;
		number = NULL;
	}
	
	Matrix(const Matrix &mat)
	{
		numrow = mat.numrow;
		numcol = mat.numcol;
		number = new int *[numrow];
		for ( int i = 0; i < numrow; ++i)
			number[i] = new int [numcol];
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				number[i][j] = mat.number[i][j];
	}
	
	int nRow()
	{
		return numrow;
	}
	
	int nCol()
	{
		return numcol;
	}
	
	Matrix &operator=(const Matrix &right)
	{
		if ( this == &right )
			return *this;
		delete [] number;
		numrow = right.numrow;
		numcol = right.numcol;
		number = new int *[numrow];
		for ( int i = 0; i < numrow; ++i)
			number[i] = new int [numcol];
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				number[i][j] = right.number[i][j];
		return *this;
	}
	
	Matrix &operator+=(const Matrix &right)
	{
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				number[i][j] = number[i][j] + right.number[i][j];
		return *this;
	}
	
	~Matrix()
	{
		delete [] number;
	}
};

#endif
