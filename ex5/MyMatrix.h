#pragma once
#include<iostream>
#include<string>
using namespace std;


class MyMatrix
{
private:
	double** _matrix;
	int _m;
	int _n;

public:
	// Setters
	void setRows(int m);
	void setColums(int n);
	void AllocMatrix(int m, int n);
	void reSetMatrix();
	void setElement(int m, int n, double element);
	void setMatrix();
	
	// Getters
	int getRows() const { return this->_m; }
	int getColums() const { return this->_n; }
	double getElement(int i, int j) const { return this->_matrix[i][j]; }

	// Constructors
	MyMatrix();
	MyMatrix(int m, int n);
	MyMatrix(const MyMatrix& other);

	// Destructor
	~MyMatrix();

	// Operators
	MyMatrix& operator=(const MyMatrix& other);

	const MyMatrix operator+(const MyMatrix& other) const;
	const MyMatrix operator-(const MyMatrix& other) const;
	const MyMatrix operator*(const int scalar) const; //mult a matrix by a scalar (the scalar is after the * sign)
	const friend MyMatrix operator*(const int num, const MyMatrix& other); //mult a matrix by a scalar (the scalar is before the * sign)
	const MyMatrix operator*(const MyMatrix& other) const;

	bool operator==(const MyMatrix& other) const;

	const double* operator[](int);
	operator double() const;

	const friend ostream& operator<<(ostream& out, const MyMatrix& other);
	const friend istream& operator>>(istream& in, MyMatrix& other);

	// Other Mothosd
	void print() const;
};

