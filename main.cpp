#include<iostream>
#include<string>
#include"circleList.h"

using namespace std;


int main(int argc, char* argv[]) {

	circleList list;
	student *st1 = new student;
	//initialize data for st1
	st1->name ="A";
	st1->next = nullptr;
	list.addFirst(st1);
	cout << "\nTest case: print when list empty" << endl;
	list.printList();
	//add student 2
	student *st2 = new student;
	st2->name = "B";
	st2->next = nullptr;
	list.addLast(st2);
	cout << "\nTest case: print when list has one element" << endl;
	list.printList();


	student *st3 = new student;
	st3->name = "C";
	st3->next = nullptr;
	//TEST FUNCTION INSERT AT POSTION
	cout << "\nTest function insertAt(0)" << endl;
	//list.addFirst(st3);
	list.insertAt(2, st3);
	list.printList();

	cout << "\nInsert student D at position 10" << endl;
	student *st4 = new student;
	st4->name = "D";
	st4->next = nullptr;
	list.insertAt(10, st4);
	cout << "\nTest function search(\"A\")" << endl;
	cout << list.search("A") << endl;

	cout << "\nRemove student C" << endl;
	list.remove("C");
	list.printList();

	cout << "\nRemove student A" << endl;
	list.remove("A");
	list.printList();

	cout << "\nRemove student D" << endl;
	list.remove("D");
	list.printList();

	cout << "\nRemove student B" << endl;
	list.remove("B");
	list.printList();

	system("pause");
	return 0;
}