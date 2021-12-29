#include "Complex.h"

double Complex::getComplexAbs() const
{   
    return sqrt(pow(this->getRe(), 2) + pow(this->getIm(), 2));
}

double Complex::getComlexArg() const
{
    return atan2(this->getIm(),this->getRe());
}

// Defining add() method for adding two complex numbers
Complex Complex:: add(const Complex& other)
{
    Complex sum(this->getRe() + other.getRe(), this->getIm() + other.getIm());
    return sum;
}

Complex Complex::sub(const Complex& other)
{
    Complex sub(this->getRe() - other.getRe(), this->getIm() - other.getIm());
    return sub;
}

void Complex::printComlex() const
{
    cout << "\t";
    if (this->getComplexAbs() == 0) { cout << "0"; }
    if (this->getRe() != 0) { cout << this->getRe(); }
    if (this->getIm() < -1) { cout << this->getIm() << "i"; }
    if (this->getIm() > 1) { cout << "+" << this->getIm() << "i"; }
    if (this->getIm() == -1) { cout << "-i"; }
    if (this->getIm() == 1) {
        if (this->getRe() == 0) { cout << "i"; }
        if (this->getRe() != 0) { cout << "+i"; }
    }
    
    cout << "\t (" << this->getComplexAbs() << " , " << this->getComlexArg() << ")" << endl;
}

Complex::Complex()
{
    this->setComplex();
    cout << "Complex number Default Constructor" << endl;
}

Complex::Complex(const int re, const int im)
{
    this->setComplex(re, im);
    cout << "Complex number Constructor" << endl;
}

Complex::Complex(const int re)
{
    this->setComplex(re, 0);
    cout << "Comlex Complex Real part number Constructor" << endl;
}

Complex::Complex(const Complex& other)
{
    this->setComplex(other.getRe(),other.getIm());
    cout << "Complex number Copy Constructor" << endl;
}
