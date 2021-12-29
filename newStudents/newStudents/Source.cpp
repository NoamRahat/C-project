#include "Student.h"
#include "Classroom.h"

void main() {
	Student st1;

	st1.printStudent();

	st1.setStudent();

	st1.printStudent();

	st1.setStudent(123123123, "Moshe", 95);

	st1.printStudent();

	st1.setStudent(444, "Mosh%e", -50);

	st1.printStudent();

	Student* ptr1 = new Student(123123123);

	delete ptr1;

	Student st2(234234234, "Ronit", 100);

	st2.printStudent();

	Student st3(567567567);
	Student st4("Ronna");
	st3.printStudent();
	st4.printStudent();
	Student st5(st4);
	st4.printStudent();
	st5.printStudent();
	Student st6 = st5;
	st6.printStudent();

	cout << "*************************************************" << endl;
	Classroom c("eng_class");
	c.printClassroom();
	c.setName("e_class");
	c.printClassroom();
	c.insertToClassroom(3, &st3);
	c.insertToClassroom(8, &st4);
	c.insertToClassroom(9, &st5);
	c.printClassroom();
	Classroom c1(c);
	cout << "*************************************************" << endl;
	c.printClassroom();
	cout << "*************************************************" << endl;
	c1.printClassroom();


}