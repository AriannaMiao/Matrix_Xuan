#include<iostream>
#include"matrix.h"
using namespace std;

Matrix::Matrix(const Matrix &mat)
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

ostream &operator<<(ostream &os, const Matrix &obj)
{
	os << obj.numrow << " " << obj.numcol << "\n";
	for ( int i = 0; i < obj.numrow; ++i)
	{
		for ( int j = 0; j < obj.numcol; ++j)
			os << obj.number[i][j];
		os << "\n";
	}
	os << endl;
	return os;
}

istream &operator>>(istream &is, Matrix &obj)
{
	is >> obj.numrow;
	is >> obj.numcol;
	for ( int i = 0; i < obj.numrow; ++i)
		for ( int j = 0; j < obj.numcol; ++j)
			is >> obj.number[i][j];
	return is;
}
