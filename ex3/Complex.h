#pragma once
#include<iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
	int _re;
	int _im;
	void setRe(int re = 0) { this->_re = re; }//inline
	void setIm(int im = 0) { this->_im = im; }//inline
public:
	int getRe() const { return this->_re; }//inline
	int getIm() const { return this->_im; }//inline
	void setComplex(int x = 0, int y = 0) { this->setRe(x); this->setIm(y); }//inline
	double getComplexAbs() const;
	double getComlexArg()const;
	Complex add(const Complex& other);
	//Complex add(const Complex C1, const Complex C2);
	Complex sub(const Complex& other);
	void printComlex() const;

	Complex();
	Complex(const int re, const int im);
	Complex(const int re);
	Complex(const Complex& other);


};

