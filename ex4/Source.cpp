#include"MyDate.h"
#include"Calendar.h"

int main() {
	
	MyDate d1;
	d1.print();
	d1.init();
	d1.print();
	d1.inc();
	d1.print();
	d1.setDay(31);
	d1.print();
	d1.inc();
	d1.print();
	d1.setMayDate(2021, 12, 14, "Asara Be'Tavet");
	d1.print();
	cout << "***************************************" << endl;

	MyDate d2(2021, 12, 15, "Bank Meating");
	d2.print();
	d2.isBefore(d1);
	d1.isBefore(d2);
	d2.setDay(32);
	d2.print();
	cout << "***************************************" << endl;
	d2.setMayDate(2021, 12, 15, "Bank Meating");

	MyDate d3(0, 15, 54, "Check");
	d3.print();
	cout << "***************************************" << endl;

	int oldest;
	Calendar cal;
	Calendar cal2(cal);
	cal2.Insert(d1);
	cal2.Insert(d2);
	cal2.Insert(d3);
	cal2.Insert(d1);
	cal2.Insert(d2);
	oldest = cal2.oldest();

	MyDate d4(2019, 12, 21, "Today");
	cal2.setDate(7, d4);
	int first = cal2.firstFree();
	int num = cal2.datesNum();
	oldest = cal2.oldest();
	cal2.print();
	cout << "***************************************" << endl;

	cal2.erase(1);
	cal2.print();
	cout << "***************************************" << endl;

	cal2.deleteAll();
	cal2.print();

	cout << "***************************************" << endl;




	return 0;
}