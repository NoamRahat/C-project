#pragma once
#include<string>
#include<iostream>
using namespace std;

class Animal
{
private:
	string _animalName;
	int _age;
protected:
	int _type;
public:
	Animal();
	virtual ~Animal();
	virtual void print() const;
	virtual void makeNoise() const;
	string getName() const { return this->_animalName; }
};

