#pragma once
#include<string>
#include<iostream>

using namespace std;
struct student {
	string name="";
	student *next;
};


class circleList
{

private:
	student* head;

public:
	circleList();

	void addFirst(student *newSt);
	void printList();
	void addLast(student *newSt);
	void insertAt(int pos, student *newSt);
	bool search(string stName);
	void remove(string stName);
};

