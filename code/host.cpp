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

#include "host.h"

Host::Host()
{
	mId = 0;
	mName = "";
	mWages = 0;
	mAddress = "";
	mPhone = "";
	mWaitStaffWorking = 0;
}

Host::Host(int Id, string name, double wages, string address, string phone, int waitStaffWorking)
{
	mId = Id;
	mName = name;
	mWages = wages;
	mAddress = address;
	mPhone = phone;
	mWaitStaffWorking = waitStaffWorking;
}

Host::~Host()
{

}

/*
****************************************************************************
Author:    	Danielle Barry
Function:	assignTable(int ID, Table table[])
Pre:		int ID, Table table[]
Post:		bool assign -- returns true if table assigned, false if not
Purpose:	assigns a table (with id of int ID) to a customer(s),
returns a bool value of whether or not it was successful
****************************************************************************
*/
bool Host::assignTable(int ID, Table table[])
{
	bool assign = false;

	for (int i = 0; i < MAX_TABLE; i++)
	{
		if (table[i].id == ID)
		{
			if (table[i].isAvailable)
			{
				table[i].isAvailable = false;
				assign = true;
				break;
			}
		}
	}

	return assign;
}

/*
author: Alex Twombly
function: freeTable(int id Table table[])
pre: int id Table table[]
post: returns true if table is freed false if not
purpose: it frees the table
************************************************/
bool Host::freeTable(int id, Table table[])
{
	for (int i = 0; i < MAX_TABLE; i++)
	{
		if (table[i].id == id)
		{
			if (table[i].isAvailable == false)
			{
				table[i].isAvailable = true;

				return true;
			}

			else
			{
				cout << "Table " << i << " Is already avalible\n";

				return false;
			}
		}
	}

	cout << "Table not found\n";
	return false;
}

/*
*       Pre: Information in table class
*      Post: Displays the available tables
*   Purpose: To search for available tables and display them
*	 Author: Brian Zhang
********************************************************/
void Host::searchTableAvailable(Table table[])
{
	for (int i = 0; i < MAX_TABLE; i++)
	{
		if (table[i].isAvailable)
		{
			cout << "Table: " << i << "is available\n";
		}
	}
}

/*
*       Pre: Information in table class
*      Post: Displays the available seats
*   Purpose: To search for available tables with the needed amount of seats
and display them
*	 Author: Brian Zhang
********************************************************/
void Host::searchTableSeat(Table table[])
{
	int seats;

	cout << "Enter the amount of needed seats: ";
	cin >> seats;

	for (int i = 0; i < MAX_TABLE; i++)
	{
		if (table[i].maxPeople == seats)
		{
			cout << "Table: " << i << " can fit " << seats << " people\n";

			if (table[i].maxPeople > seats)
			{
				cout << "Table: " << i << " can fit more then " << seats << " people\n";
			}
		}
	}
}

/*
Pre: A filled table array
Post: Nothing output
Purpose: Allow user to access host functions
Author: Stephen Brkiatis
*/
void Host::hostUserMenu(Table table[])
{
    int choice = 0, id;

	while(choice != 5)
	{
		cout << "Choose your option: "<< endl
			<< "1. Check all tables" << endl
			<< "2. Check avaliable tables" << endl
			<< "3. Assign a table" << endl
			<< "4. Free table" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			searchTableSeat(table);
			break;
		case 2:
			searchTableAvailable(table);
			break;
		case 3:
			cout << "Enter an id: ";
			cin >> id;
			assignTable(id, table);
			break;
		case 4:
			cout << "Enter an id: ";
			cin >> id;
			freeTable(id, table);
			break;
		case 5:
			continue;
			break;
		default:
			cout << "That is not an option, enter a new item.";
		}
	}
}