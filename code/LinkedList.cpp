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

//LinkedList for order

#include "LinkedList.h"

LinkedList:: LinkedList()
{
	mHead = NULL;
	mTail = NULL;
}

LinkedList:: ~LinkedList()
{
	while(mHead != NULL)
	{
		pop();
	}
}

void LinkedList:: display()
{
	string holdString;
	Node *temp;

	temp = mHead;

	do
	{
		cout << temp->itemName << endl;
		temp = temp->mNext;
	}while(temp != NULL);
	delete temp;
}

string LinkedList:: pop()
{
	string holder;
	Node *temp;

	temp = mHead;

	if(temp != NULL)
	{
		holder = temp->itemName;
		mHead = temp->mNext;

		if(mHead == NULL)
		{
			mTail = NULL;
		}
		delete temp;
	}
	return holder;
}

void LinkedList:: push(string itemName)
{
	Node *temp;

	temp = new Node(itemName);

	if(mHead == NULL)
	{
		mHead = temp;
		mTail = temp;
	}
	else
	{
		temp->mNext = mHead;
		mHead = temp;
	}
}