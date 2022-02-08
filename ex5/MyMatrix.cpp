#include "MyMatrix.h"
#define ERROR -1

// Setters

void MyMatrix::setRows(int m)
{
	try
	{
		if (m <= 0)
			throw ERROR;
		this->_m = m;
	}
	catch (const int e)
	{
		cout << "cannot create matrix with rows less or equal to zero" << endl;
	}
}

void MyMatrix::setColums(int n)
{
	try
	{
		if (n <= 0)
			throw ERROR;
		this->_n = n;
	}
	catch (const int e)
	{
		cout << "cannot create matrix with cols less or equal to zero" << endl;
	}
}

void MyMatrix::AllocMatrix(int m, int n)
{
	this->setRows(m);
	this->setColums(n);
	this->_matrix = new double* [this->getRows()];
	for (int i = 0; i < this->getRows(); i++)
	{
		_matrix[i] = new double[this->getColums()];
	}
	this->reSetMatrix();
}

void MyMatrix::reSetMatrix()
{
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColums(); j++) {
			_matrix[i][j] = 0;
		}
	}
}

void MyMatrix::setElement(int m, int n, double element)
{
	this->_matrix[m][n] = element;
}

void MyMatrix::setMatrix()
{
	this->setRows(3);
	this->setColums(3);
	AllocMatrix(this->getRows(), this->getColums());
}


// Constructors & Destructors

MyMatrix::MyMatrix()
{
	setRows(3);
	setColums(3);
	this->AllocMatrix(this->getRows(), this->getColums());
}

MyMatrix::MyMatrix(int m, int n)
{
	this->setRows(m);
	this->setColums(n);
	this->AllocMatrix(this->getRows(), this->getColums());
}

MyMatrix::MyMatrix(const MyMatrix& other)
{
	*this = other;
}

MyMatrix::~MyMatrix()
{
	for (int i = 0; i < this->getRows(); i++)
	{
		delete[] this->_matrix[i];
	}
	delete[] this->_matrix;
}


// Opperators

MyMatrix& MyMatrix::operator=(const MyMatrix& other)
{
	// "="
	this->AllocMatrix(other.getRows(), other.getColums());
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColums(); j++) {
			this->setElement(i, j, other.getElement(i, j));
		}
	}
	return *this;
}

const MyMatrix MyMatrix::operator+(const MyMatrix& other) const
{
	try
	{
		if (this->getRows() != other.getRows() || this->getColums() != other.getColums())
			throw string("the 2 matrixs must have equel number of rows an cols");

		MyMatrix sum(this->getRows(), this->getColums());
		for (int i = 0; i < this->getRows(); i++) {
			for (int j = 0; j < this->getColums(); j++)
			{
				sum.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
			}
		}
		return sum;
	}
	catch (string e)
	{
		cout << e << endl;
		throw e;
	}
}

const MyMatrix MyMatrix::operator-(const MyMatrix& other) const
{
	try
	{
		if (this->getRows() != other.getRows() || this->getColums() != other.getColums())
			throw ERROR;

		MyMatrix sub(this->getRows(), this->getColums());
		for (int i = 0; i < this->getRows(); i++) {
			for (int j = 0; j < this->getColums(); j++)
			{
				sub.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
			}
		}
		return sub;
	}
	catch (const int e)
	{
		cout << "the 2 matrixs must have equel number of rows an cols";
	}
}

const MyMatrix MyMatrix::operator*(const int scalar) const
{
	MyMatrix mult;
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getColums(); j++)
		{
			mult.setElement(i, j, scalar * this->getElement(i, j));
		}
	}
	return mult;
}

const MyMatrix operator*(const int scalar, const MyMatrix& other)
{
	MyMatrix mult = other * scalar;
	return mult;
}

const MyMatrix MyMatrix::operator*(const MyMatrix& other) const
{
	try {
		if (this->getColums() != other.getRows())
			throw ERROR;
		MyMatrix mult(this->getRows(), other.getColums());
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < other.getColums(); j++)
			{
				double element = 0;
				for (int k = 0; k < other.getRows(); k++)
				{
					element += (this->getElement(i, k) * other.getElement(k, j));
					mult.setElement(i, j, element);
				}
			}
		}
		return mult;
	}
	catch (int e) {
		cout << "The Second Matrices number of rows has to be equal to the First Matrices number of cols" << endl;
	}
}

bool MyMatrix::operator==(const MyMatrix& other) const
{
	if (!(this->getRows() == other.getRows() && this->getColums() == other.getColums())){
		cout << "The tow Matrices are different";
		return false;
	}
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColums(); j++)
		{
			if (!(this->getElement(i,j)==other.getElement(i,j)))
			{
				cout << "The tow Matrices are different" << endl;
				return false;
			}
		}
	}
	cout << "The tow Matrices are equel" << endl;;
	return true;
}

const double* MyMatrix::operator[](int k)
{
	try {
		if (k < this->getRows())
			throw ERROR;

		return this->_matrix[k];
	}

	catch (const int e) {
		cout << "This Idnex dousn't exsist" << endl;
	}
}

MyMatrix::operator double() const
{
	int sum = 0;
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getColums(); j++)
		{
			sum += this->getElement(i, j);
		}
	}
	return sum;
}

const ostream& operator<<(ostream& out, const MyMatrix& other)
{
	// TODO: insert return statement here
	other.print();
	return out;
}

const istream& operator>>(istream& in, MyMatrix& other)
{
	cout << "enter matrix:" << endl;
	for (int i = 0; i < other.getRows(); i++) {
		for (int j = 0; j < other.getColums(); j++) {
			double element;
			cin >> element;
			other.setElement(i, j, element);
		}
	}
	return in;
}


// Other Mothosd

void MyMatrix::print() const
{
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColums(); j++)
		{
			cout << this->getElement(i, j) << "\t";
		}
		cout << endl;
	}
}

