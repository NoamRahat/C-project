#pragma once
#include "Mammel.h"
class Tiger : public Mammel
{
private:
	int _numOfSouls;
public:
	Tiger();
	~Tiger();
	void print() const;
	void makeNoise() const;
};

