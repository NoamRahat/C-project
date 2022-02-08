#pragma once
#include "Lion.h"
#include "Tiger.h"
#include "Horse.h"
#include "Butterfly.h"

class Zoo
{
private:
	string _zooName;
	Animal** _allAnimals;
	int _size;
public:
	Zoo(string name = "Safari");
	~Zoo();
	void printAllAnimals() const;
	void animalParty() const;
	void insertAnAnimal();
	void removeAnAnimal();
	int findAnimalByName();
	void sortAllAnimalsByName();
	void getNumberOfKind() const;
	void MENU();
	void printNumberOfAnyMammel() const;
};

