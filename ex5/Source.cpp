#include"MyMatrix.h"

int main() {

	try {
		MyMatrix mat1;
		mat1.print();
		cout << "************************************" << endl;

		mat1.setElement(1, 1, 4);
		mat1.print();
		cout << "************************************" << endl;

		MyMatrix mat2;
		mat2.setElement(1, 1, 2);
		mat2.print();
		cout << "************************************" << endl;

		MyMatrix mat3 = mat2 - mat1;
		mat3.print();
		cout << "************************************" << endl;
		mat3 = mat2 * 3;
		mat3.print();
		cout << "************************************" << endl;

		mat3 = 7 * mat3;
		mat3.print();
		cout << "************************************" << endl;

		MyMatrix mat4(7, 7);
		mat4.print();
		cout << "************************************" << endl;

		MyMatrix mat5(2, 2), mat6(2, 2);
		mat5.setElement(0, 0, 1);
		mat5.setElement(0, 1, 0);
		mat5.setElement(1, 0, -1);
		mat5.setElement(1, 1, 3);
		mat5.print();
		cout << "************************************" << endl;

		mat6.setElement(0, 0, 3);
		mat6.setElement(0, 1, 1);
		mat6.setElement(1, 0, 2);
		mat6.setElement(1, 1, 1);
		mat6.print();
		cout << "************************************" << endl;

		MyMatrix m7 = mat5 * mat6;
		m7.print();
		cout << "************************************" << endl;

		MyMatrix m9 = mat6 * mat5;
		m9.print();
		cout << "************************************" << endl;

		mat5.AllocMatrix(3, 2), mat6.AllocMatrix(2, 3);
		mat5.setElement(0, 0, 5);
		mat5.setElement(0, 1, 1);
		mat5.setElement(1, 0, 2);
		mat5.setElement(1, 1, 3);
		mat5.setElement(2, 0, 3);
		mat5.setElement(2, 1, 4);
		mat5.print();
		cout << "************************************" << endl;

		mat6.setElement(0, 0, 1);
		mat6.setElement(0, 1, 2);
		mat6.setElement(0, 2, 0);
		mat6.setElement(1, 0, 4);
		mat6.setElement(1, 1, 3);
		mat6.setElement(1, 2, -1);
		mat6.print();
		cout << "************************************" << endl;

		m7 = mat5 * mat6;
		m7.print();
		cout << "************************************" << endl;

		m9 = mat6 * mat5;
		m9.print();
		cout << "************************************" << endl;

		MyMatrix m8 = mat4 * mat3;
		cout << "************************************" << endl;

		/*m8 = mat4 + mat3;
		cout << "************************************" << endl;*/


		m8.AllocMatrix(0, 0);
		m8.print();
		cout << "************************************" << endl;
		int a = (mat1 == mat3);
		int b = (mat3 == mat3);
		cout << mat3;
		cout << "************************************" << endl;

		cin >> mat3;
		cout << mat3;
		cout << "************************************" << endl;

		int c = mat3[2][2];
		cout << "mat (2,2) is: " << c << endl;
		cout << "************************************" << endl;

		double d = (double)mat3;
		cout << "sum of mat is: " << d << endl;
		cout << "************************************" << endl;

		MyMatrix m10(mat3 * mat2);
		cout << m10;

		cout << m7;
		cout << "************************************" << endl;

		cout << mat3 + (m7 - mat2) + (m7 = (mat2 - mat3)) - mat1;
	}
	catch (string e) {
		cout << e;
	}
	return 0;
}