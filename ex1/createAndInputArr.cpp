#include <iostream>
using namespace std;

int* createAndInput(int& size) {
	cout << "Please Enter Array Size:" << endl;
	cin >> size;
	cout << "Please Enter "  << size  << " Nubers" << endl;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	return (arr);
}