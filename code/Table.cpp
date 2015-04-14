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

#include "Table.h"

Table::Table()
{
	id = 0;
	maxPeople = 0;
	isAvailable = true;
	waitStaff = "";
}

Table::~Table()
{

}

void Table::changeOrder()
{
	string holdOrder, orderChange, holdString, tempHold;
	int count;
	bool found = false;
	LinkedList temp;

	cout << "Which item do you want to change:" << endl;
	//displayOrder();

	cin >> holdOrder;
	cout << "What do you want to change it to:";
	cin >> orderChange;

	if(found == false)
	{
		holdString = order.pop();
		temp.push(holdString);
		count++;

		if(holdString == holdOrder)
		{
			found = true;
			temp.pop(); //Pops the order we want to change
		}
	}

	for(int i = 0; i < count; i++) //this pushes the other orders back onto the main LinkedList
	{
		tempHold = temp.pop();
		order.push(tempHold);
	}

	order.push(orderChange);
}

void Table::takeOrder(Menu &todayMenu)
{
	int items, num;
	string itemOrdered;
	bool found = false;

	cout << "How many items were ordered? ";
	cin >> items;

	for(int i = 0; i < items; i++)
	{
		found = false;
		cout << "Enter the item's name: ";
		cin >> itemOrdered;
		//since our foods are put in several differnt arrays this checks all of them for the item
		found = searchForItem(itemOrdered, APP, todayMenu.mAppetizers, num);
		if(todayMenu.mNumAppetizers[num] <= 0) //checking if the item is in stock
		{
			found = false;
		}
		if(found == true)
		{
			//removes one item from stock
			todayMenu.mNumAppetizers[num] = todayMenu.mNumAppetizers[num] - 1;
		}

		if(found == false)
		{
			found = searchForItem(itemOrdered, ENTREE, todayMenu.mEntrees, num);
			if(todayMenu.mNumEntrees[num] <= 0)
			{
				found = false;
			}
			if(found == true)
			{
				todayMenu.mNumEntrees[num] = todayMenu.mNumEntrees[num] - 1;
			}
		}

		if(found == false)
		{
			found = searchForItem(itemOrdered, DESS, todayMenu.mDesserts, num);
			if(todayMenu.mNumDesserts[num] <= 0)
			{
				found = false;
			}
			if(found == true)
			{
				todayMenu.mNumDesserts[num] = todayMenu.mNumDesserts[num] - 1;
			}
		}

		if(found == false)
		{
			found = searchForItem(itemOrdered, DAILY, todayMenu.mDaily, num);
			if(todayMenu.mNumDailies[num] <= 0)
			{
				found = false;
			}
			if(found == true)
			{
				todayMenu.mNumDailies[num] = todayMenu.mNumDailies[num] - 1;
			}
		}

		if(found == false)
		{
			//should we do i-- here? On the one hand helps if they mistyped, on the other if
			//something is out of stock then it would just create a loop
			cout << "Item is not on the menu.";
		}
		else
		{
			order.push(itemOrdered);
		}
	}
	
}

bool Table::searchForItem(string itemsName, int arraySize, string arrayOfNames[], int &num)
{
	string itemCompare;
	bool found = false;

	for(int j = 0; j < arraySize; j++)
	{
		itemCompare = arrayOfNames[j];

		if(itemsName == itemCompare)
		{
			found = true;
			num = j;
			return found;
		}
	}

	found = false;
	return false;
}

double Table::generateBill(Menu todayMenu)
{
	double totalBill, holderDouble;
	string current;
	int num = 0;;
	bool found = false;

	current = order.pop();

	while (current != "")
	{
		found = searchForItem(current, APP, todayMenu.mAppetizers, num);
		holderDouble = todayMenu.mAppetizersCost[num]; //No matter what the function pulls out a price

		if(found == false)
		{
			found = searchForItem(current, ENTREE, todayMenu.mEntrees, num);
			holderDouble = todayMenu.mEntreesCost[num]; //if the first price wasn't correct then it gets overwriten and so on
		}

		if(found == false)
		{
			found = searchForItem(current, DESS, todayMenu.mDesserts, num);
			holderDouble = todayMenu.mDessertsCost[num];
		}

		if(found == false)
		{
			found = searchForItem(current, DAILY, todayMenu.mDaily, num);
			holderDouble = todayMenu.mDessertsCost[num];
		}

		cout << current << ": $" << holderDouble << endl;

		totalBill = totalBill + holderDouble;

		found = false;
		current = order.pop();
	}

	cout << "Total: " << totalBill;

	return totalBill;
}

/*
*       Pre: Orders stored in a linked list
*      Post: Delete an order
*   Purpose: To prompt for an order to delete and delete that order from the list 
*	 Author: Brian Zhang
********************************************************/
void Table::deleteOrder()
{
	string item;
	int count;
	Node *nodePtr, *previousNodePtr; //Not sure how I can get this to work with what we have right now. One way that can fix this is to change private to protected in
	//LinkedList.h and have table be a children of LinkedList.h. Not sure if this will mess anyone else up, so I didn't change anything yet. 
	//Does anyone know another fix? - Brian.
	

	cout << "What item do you want to delete?\n";
	getline(cin, item);

	if (!mHead)
	{
		return;
	}

	if (mHead->itemName == item)
	{
		nodePtr = mHead;
		mHead = mHead->mNext;
		delete nodePtr;
	}
	else
	{
		nodePtr = mHead;

		while (nodePtr != NULL && nodePtr->itemName != item)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->mNext;
		}
		if (nodePtr)
		{
			previousNodePtr->mNext = nodePtr->mNext;
			delete nodePtr;
		}
	}
}