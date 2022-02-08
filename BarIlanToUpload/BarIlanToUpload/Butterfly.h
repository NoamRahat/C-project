#pragma once
#include "Insect.h"
class Butterfly : public Insect
{
private:
	int _numOfColors;
public:
	Butterfly();
	~Butterfly();
	void print() const;
	void makeNoise() const;
};

