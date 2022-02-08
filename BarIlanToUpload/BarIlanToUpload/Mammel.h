#pragma once
#include "Animal.h"
class Mammel : public Animal
{
private:
	bool _gotMilk;
public:
	Mammel();
	~Mammel();
	void print() const;
	void makeNoise() const;
};

