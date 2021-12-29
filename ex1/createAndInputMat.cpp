#include"Header.h"
int** createAndInput(int& rows, int& cols) {
	
	cout << "Please Enter a Number of Rows:" << endl;
	cin >> rows;
	cout << "Please Enter a Number of Colums:" << endl;
	cin >> cols;

	int** arr = new int* [cols];
	for (int i = 0; i < cols; i++) {
		arr[i] = new int[rows];
	}

	cout << "Please enter " << rows*cols << " numbers" << endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cin >> arr[i][j];
		}
	}
	return (arr);
	
}