#include "Zoo.h"

Zoo::Zoo(string name) {
	this->_zooName = name;
	this->_size = 0;
	this->_allAnimals = NULL;
}
Zoo::~Zoo() {
	if (this->_size == 0) return;
	for (int i = 0; i < this->_size; i++)
		delete this->_allAnimals[i];
	delete[] this->_allAnimals;
}
void Zoo::printAllAnimals() const {
	cout << "Zoo name : " << this->_zooName << endl;
	if (this->_size == 0) {
		cout<<"Empty zoo"<<endl;
		return;
	}
	for (int i = 0; i < this->_size; i++) {
		cout << "****************************************" << endl;
		this->_allAnimals[i]->print();
		cout << "****************************************" << endl;
	}
}
void Zoo::animalParty() const {
	cout << "Zoo name : " << this->_zooName << endl;
	if (this->_size == 0) {
		cout << "Empty zoo" << endl;
		return;
	}
	for (int i = 0; i < this->_size; i++)
		this->_allAnimals[i]->makeNoise();
}
void Zoo::insertAnAnimal() {
	Animal** temp = new Animal * [this->_size + 1];
	for (int i = 0; i < this->_size; i++)
		temp[i] = this->_allAnimals[i];
	delete[] this->_allAnimals;
	this->_allAnimals = temp;
	this->_size++;
	cout << "Sub Menu:" << endl;
	cout << "*********" << endl;
	cout << "1) Regular animal" << endl;
	cout << "2) Mammel" << endl;
	cout << "3) Insect" << endl;
	cout << "4) Tiger" << endl;
	cout << "5) Lion" << endl;
	cout << "6) Horse" << endl;
	cout << "7) Butterfly" << endl;
	cout << "Your choice : ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:this->_allAnimals[this->_size - 1] = new Animal;
		break;
	case 2:this->_allAnimals[this->_size - 1] = new Mammel;
		break;
	case 3:this->_allAnimals[this->_size - 1] = new Insect;
		break;
	case 4:this->_allAnimals[this->_size - 1] = new Tiger;
		break;
	case 5:this->_allAnimals[this->_size - 1] = new Lion;
		break;
	case 6:this->_allAnimals[this->_size - 1] = new Horse;
		break;
	case 7:this->_allAnimals[this->_size - 1] = new Butterfly;
		break;
	default:this->_allAnimals[this->_size - 1] = new Animal;
	}
	cout << "Animal added..." << endl;
}
void Zoo::removeAnAnimal() {
	int index = this->findAnimalByName();
	if (index == -1) {
		cout << "no such animal" << endl;
		return;
	}
	delete this->_allAnimals[index];
	this->_allAnimals[index] = this->_allAnimals[this->_size - 1];
	Animal** temp = new Animal * [this->_size - 1];
	for (int i = 0; i < this->_size - 1; i++)
		temp[i] = this->_allAnimals[i];
	delete[] this->_allAnimals;
	this->_allAnimals = temp;
	this->_size--;
	cout << "Animal removed..." << endl;
}
int Zoo::findAnimalByName() {
	string n;
	cout << "Enter the animal's name  you want to find or remove : ";
	cin >> n;
	for (int i = 0; i < this->_size; i++)
		if (this->_allAnimals[i]->getName() == n)
			return i;
	return -1;
}
void Zoo::sortAllAnimalsByName() {
	int i, j;
	Animal* temp = NULL;
	for (i = 0; i < this->_size; i++) {
		for(j = 0 ; j < this->_size-i-1 ; j++)
			if (this->_allAnimals[j]->getName() > this->_allAnimals[j + 1]->getName()) {
				temp = this->_allAnimals[j];
				this->_allAnimals[j] = this->_allAnimals[j + 1];
				this->_allAnimals[j + 1] = temp;
			}
	}
	cout << "Zoo sorted..." << endl;
}
void Zoo::MENU() {
	int choice;
	int index;

	while (true) {
		cout << "Menu" << endl;
		cout << "****" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Print all animals" << endl;
		cout << "2) Animal party" << endl;
		cout << "3) Find an animal" << endl;
		cout << "4) Sort all animals by name" << endl;
		cout << "5) Insert a new animal" << endl;
		cout << "6) Remove an animal" << endl;
		cout << "7) Count type of animal" << endl;
		cout<<"8) Count the number of any mammel"<<endl;
		cout << "Your choice : ";
		cin >> choice;
		switch (choice) {
		case 0: cout << "Bye bye, see you again soon..." << endl;
			return;
		case 1:this->printAllAnimals();
			break;
		case 2:this->animalParty();
			break;
		case 3:
			index = this->findAnimalByName();
			if (index == -1)
				cout << "No such animal" << endl;
			else {
				cout << "Found at " << index << endl;
				this->_allAnimals[index]->print();
			}
			break;
		case 4:
			this->sortAllAnimalsByName();
			break;
		case 5:
			this->insertAnAnimal();
			break;
		case 6:
			this->removeAnAnimal();
			break;
		case 7:
			this->getNumberOfKind();
			break;
		case 8:
			this->printNumberOfAnyMammel();
			break;
		default:cout << "wrong choice... please try again" << endl;
			break;
		}
	}
}
void Zoo::getNumberOfKind() const {
	int choice;
	int counter = 0;
	cout << "which type of animal you want to count ?" << endl;
	cout << "1) Regular animal" << endl;
	cout << "2) Mammel" << endl;
	cout << "3) Insect" << endl;
	cout << "4) Tiger" << endl;
	cout << "5) Lion" << endl;
	cout << "6) Horse" << endl;
	cout << "7) Butterfly" << endl;
	cout << "Your choice : ";
	cin >> choice;
	switch (choice) {
	case 1:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Animal))
				counter++;
		break;
	case 2:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Mammel))
				counter++;
		break;
	case 3:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Insect))
				counter++;
		break;
	case 4:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Tiger))
				counter++;
		break;
	case 5:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Lion))
				counter++;
		break;
	case 6:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Horse))
				counter++;
		break;
	case 7:
		for (int i = 0; i < this->_size; i++)
			if (typeid(*(this->_allAnimals[i])) == typeid(Butterfly))
				counter++;
		break;
	
		
	}
	cout << "The number of this type is : " << counter << endl;
}
void Zoo::printNumberOfAnyMammel() const {
	int counter = 0;
	for (int i = 0; i < this->_size; i++)
		if (dynamic_cast<Mammel*>(this->_allAnimals[i]))
				counter++;
	cout << "The number of mammels is : " << counter;
}
