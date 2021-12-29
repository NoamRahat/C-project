#include "List.h"

void main() {
	List myList;
	List otherList;

	myList.printList();
	
	Student st1("123", "Moshe");
	Student st2("456", "Roy");
	Student st3("678", "Esti");
	Student st4("987", "Renana");
	myList.insertFirst(st1);
	myList.insertFirst(st2);
	myList.insertLast(st3);
	myList.insertLast(st4);
	myList.printList();
	myList.remove("678");
	myList.remove("888");
	myList.printList();
	myList.insertLast(st3);
	myList.insertLast(st3);
	myList.insertLast(st3);
	myList.insertLast(st3);
	myList.printList();


	List anotherList;
	anotherList = otherList = myList;

	otherList.printList();
	myList.printList();
	if (myList == otherList)
		cout << "These lists are equals" << endl;
	else
		cout << "These lists are not equals" << endl;


	myList.insertFirst(st3);
	if (myList == otherList)
		cout << "These lists are equals" << endl;
	else
		cout << "These lists are not equals" << endl;

	if (st1 != st2)
		cout << "These students are not equals" << endl;
	else
		cout << "These students are equals" << endl;

	myList.printList();
	((myList += st3)+=st2).printList();

	List newList= myList + otherList;
	myList.printList();
	otherList.printList();
	newList.printList();





	//otherList.printList();






}