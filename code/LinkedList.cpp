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