#ifndef _matrix_h
#define _matrix_h

#include<iostream>
using namespace std;

class Matrix{
	friend class Vector;
	
	friend ostream &operator<<(ostream &os, const Matrix& obj)
	{
		os << obj.numrow << " " << obj.numcol << "\n";
		for ( int i = 0; i < obj.numrow; ++i)
		{
			for ( int j = 0; j < obj.numcol; ++j)
				os << obj.row[i].column[j] << " ";
			os << "\n";
		}
		os << endl;
		return os;
	}
	
	friend istream &operator>>(istream &is, Matrix &obj)
	{
		is >> obj.numrow;
		is >> obj.numcol;
		obj.row = new Vector [obj.numrow];
		for ( int i = 0; i < obj.numrow; ++i)
			obj.row[i].column = new int [obj.numcol];
		for ( int i = 0; i < obj.numrow; ++i)
			for ( int j = 0; j < obj.numcol; ++j)
				is >> obj.row[i].column[j];
		return is;
	}
	
	friend Matrix operator+(const Matrix &m1, const Matrix &m2)
	{
		Matrix tmp(m1.numrow, m1.numrow);
		for ( int i = 0; i < m1.numrow; ++i)
			for ( int j = 0; j < m1.numcol; ++j)
				tmp.row[i].column[j] = m1.row[i].column[j] + m2.row[i].column[j];
		return tmp;
	}
	
	friend bool operator==(const Matrix &obj1, const Matrix &obj2)
	{
		if ( obj1.numrow != obj2.numrow || obj1.numcol != obj2.numcol )
			return false;
		for ( int i = 0; i < obj1.numrow; ++i)
			for ( int j = 0; j < obj1.numcol; ++j)
				if ( obj1.row[i].column[j] != obj2.row[i].column[j] )
					return false;
		return true;
	}
	
private:
	int numrow;
	int numcol;

	class  Vector{
	public:
		int *column;
		int num;

		int &operator[](int index)
		{
			{
			//	cout << "false";
				exit(-1);
			}
			return column[index - 1];
		}
		
		const int &operator[](int index) const
		{
			if ( index > num )
				exit(-1);
			return column[index - 1];
		}

		~Vector()
		{
			delete [] column;
		}
	};
	
	Vector *row;
	
public:	
	Matrix(int nr, int nc): numrow(nr), numcol(nc)
	{
		row = new Vector [numrow];
		for ( int i = 0; i < numrow; ++i)
			row[i].column = new int [numcol];
	}
	
	Matrix()
	{
		numrow = 0;
		numcol = 0;
		row = NULL;
	}
	
	Matrix(const Matrix &mat)
	{
		numrow = mat.numrow;
		numcol = mat.numcol;
		row = new Vector [numrow];
		for ( int i = 0; i < numrow; ++i)
			row[i].column = new int [numcol];
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				row[i].column[j] = mat.row[i].column[j];
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
		delete [] row;
		numrow = right.numrow;
		numcol = right.numcol;
		row = new Vector [numrow];
		for ( int i = 0; i < numrow; ++i)
			row[i].column = new int [numcol];
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				row[i].column[j] = right.row[i].column[j];
		return *this;
	}
	
	Matrix &operator+=(const Matrix &right)
	{
		for ( int i = 0; i < numrow; ++i)
			for ( int j = 0; j < numcol; ++j)
				row[i].column[j] = row[i].column[j] + right.row[i].column[j];
		return *this;
	}
	
	Vector &operator[](int index)
	{
		if ( index > numrow ) 
		{
			//cout << "false";
			exit(-1);
		}
		row[index - 1].num = numcol;
		return row[index - 1];
	}
	
	const Vector &operator[](int index) const
	{
		if ( index > numrow )
		{
			//cout << "false";
			exit(-1);
		}
		row[index - 1].num = numcol;
		return row[index - 1];
	}
	
	int operator() (int a, int b)
	{
		if ( a > numrow || b > numcol )
			exit(-1);
		return row[a-1].column[b-1];
	}
	
	~Matrix()
	{
		delete [] row;
	}
};

#endif
