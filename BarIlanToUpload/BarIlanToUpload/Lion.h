#pragma once
#include "Mammel.h"
class Lion : public Mammel
{
private:
	int _volume;
public:
	Lion();
	~Lion();
	void print() const;
	void makeNoise() const;
};

