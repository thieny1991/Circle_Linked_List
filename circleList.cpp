#include "circleList.h"
#include<iostream>

using namespace std;


circleList::circleList()
{
	// assinged null state for head
	head = nullptr;
}

void circleList::addFirst(student * newSt)
{
	//case 1: list is empty
	if (head == NULL)
	{
		head = newSt;
		newSt->next = head;
	}
	//case 2: List has one element
	else if (head->next==head){
		newSt->next = head;
		head->next = newSt;
		head = newSt;
	}
	else {
		student *current = head;
		newSt->next = head;
		head = newSt;
		while (current->next != head) current = current->next;
		current->next = newSt;
	}
}

void circleList::printList()
{
	//create an tracing pointer to student type
	student *current = head;
	//case1: list is emtpy
	if (head == nullptr)
		cout << "list is empty" << endl;
	//case 2: list has one element
	else if (head->next == head) {
		cout << head->name << endl;
	}
	else {
		do {
			cout << current->name << endl;
			current = current->next;
		} while (current != head);
	}

}

void circleList::addLast(student * newSt)
{
	//create tracing pointer
	
	//case1: if list is empty
	if (head == 0) {
		head = newSt;
		head->next = head;
	}
	else{
		student *current = head;
		//locate the last element which its next ==head
		while (current->next != head) {
			current = current->next;
		}
		//add new node at the end of the last element
		current->next = newSt;
		newSt->next = head;
	}
	
}

//This function assume that pos start from 0
void circleList::insertAt(int pos, student * newSt)
{
	//if pos is 0;
	if (pos == 0)
		addFirst(newSt);
	//if list has one element
	else if (head->next == head) {
		newSt->next = head;
		head->next = newSt;
		head = newSt;
	}
	else if (pos == 1) {// if list has more than 2 element, and pos =1
		student *temp;
		temp = head->next;
		newSt->next = temp;
		head->next = newSt;
	}
	else {
		student * current = head;
		if(pos>1){
			for (int i = 0;i <= pos - 2;i++) {
				current = current->next;
				// locate pointer current to the element n-1
				if (current->next == head) {	// if pos is positive and invalid
					current->next = newSt;		// or pos is located at the end
					newSt->next = head;
					break;
				}
				student *temp = current->next;

				current->next = newSt;
				newSt->next = temp;
			}
		
		}//end if

	}

}



bool circleList::search(string stName) {

	student *current = head;
	if (head == 0) {
		return false;
	}
	else if (head->next == head) {
		return(head->next->name == stName);
	}
	else {
		while (current->name != stName&&current->next != head)
			current = current->next;
		return (current->name == stName);
	}
}

void circleList::remove(string stName)
{
	if (head == 0) cout << "List is empty" << endl;
	else if (head->next == head) {
		if (head->name == stName) {
			delete head;
			head = nullptr;
		}//end if
	}//end else if
	else {
		student *pre = head;
		student *current =head;
		while (current->name != stName&&current->next!= head) {
			pre = current;
			current = current->next;
		}
		if (current->name == stName) {
			if (current == head) {
				while (current->next != head)
					current = current->next;// locate the last element
				student *temp = head;
				head = head->next;
				current->next = head;
				delete temp;//deallocate the first node
			}
			else if (current->next == head) {
				pre->next = head;
				delete current;//deallocate the last node
			}
			else {//the found node is in the middle
				pre->next = current->next;
				delete current;//dealllocate the current node
			}
		}//end if
	}//end else
}//end remove


