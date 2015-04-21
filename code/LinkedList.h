//Linked list for order

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
protected:

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