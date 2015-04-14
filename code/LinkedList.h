/*
Class: CSI-240-06
Assignment: FINAL PROJECT
Date Assigned: 3/17/15
Due Date: 4/24/15 11:00AM

Description:
A class for organizing table data for a restaurant program

Certification of Authenticity:
We certify that this is entirely our own work, except where we have given fully
documented references to the work of others. We understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
-Reproduce this assignment and provide a copy to another member of
academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/

//Linked list for order

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
private:

	struct Node
	{
		string itemName;
		Node *mNext;

		Node()
		{
			mNext = NULL;
			itemName = "";
		}
		Node(string itemName)
		{
			mNext = NULL;
			itemName = itemName;
		}
	};
	Node *mHead, *mTail;

public:
	LinkedList();
	~LinkedList();

	void display();
	string pop();
	void push(string itemName);
};



#endif