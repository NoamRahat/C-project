#include"Header.h"

int power(int a, int b) {
	int result = 1;
	if (b == 0) {
		return 1;
	}
	for (int i = 1; i <= b; i++) {
		result *= a;
	}
	return result;
}

float power(float a, int b) {
	float result = 1;
	if (b == 0) {
		return 1;
	}
	for (int i = 1; i <= b; i++) {
		result *= a;
	}
	return result;
}

double power(double a, int b) {
	double result = 1;
	if (b == 0) {
		return 1;
	}
	for (int i = 1; i <= b; i++) {
		result *= a;
	}
	return result;
}