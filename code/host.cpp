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

/* Function:  assignTable
*   Purpose:  assigns a table (with id of int ID) to a customer(s),
*               returns a bool value of whether or not it was successful
*       Pre:  int ID, Table table[]
*      Post:  bool assign -- returns true if table assigned, false if not
*    Author:  Danielle Barry
*****************************************************************/
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

/* Function:  hostUserMenu
*   Purpose:  Allow acess to host functions
*       Pre:  A filled table array
*      Post:  None
*    Author:  Stephen Brikiatis
*****************************************************************/
void Host::menu(Table table[])
{
	int choice = 0, id;

	while (choice != 5)
	{
		cout << "Choose your option: " << endl
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

/* Function:  freeTable
*   Purpose:  Frees a table
*       Pre:  int id, Table table[]
*      Post:  returns true if table is freed false if not
*    Author:  Alex Twombly
*****************************************************************/
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

/* Function: searchTableAvailable
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

/* Function: searchTableSeat
*       Pre: Information in table class
*      Post: Displays the available seats
*   Purpose: To search for available tables with the needed amount of seats
*               and display them
*	 Author: Brian Zhang
********************************************************/
void Host::searchTableSeat(Table table[])
{
	int seats;
	bool found = false;

	cout << "Enter the amount of needed seats: ";
	cin >> seats;

	for (int i = 0; i < MAX_TABLE; i++)
	{
		if (table[i].maxPeople == seats)
		{
			cout << "Table: " << i << " can fit " << seats << " people\n";
			found = true;
		}
		if (table[i].maxPeople > seats)
		{
			cout << "Table: " << i << " can fit more then " << seats << " people\n";
			found = true;
		}
	}
	if (found == false)
	{
		cout << "No tables have " << seats << "seats";
	}
}

