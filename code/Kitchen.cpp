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

#include "kitchen.h"

//Constructor
Kitchen::Kitchen()
{
}

//deconstructor
Kitchen::~Kitchen()
{
	
}

//Accessor
bool Kitchen::getStatus()
{
	return mStatus;
}

/* Function:  addDailyItems
*   Purpose:  Add daily items to the menu
*       Pre:  none
*      Post: Menu items are added 
*    Author:  Danielle Barry
*****************************************************************/
void Kitchen::addDailyItems(Menu menu)
{
	string name, desc;
	int quantity;
	double price;

	for (int i = 0; i < 1; i++)
	{
		//get dish info
		cout << "Add daily menu item(s):" << endl << endl;
		cout << "Name of dish: " << endl;
		getline(cin, name);
		cout << "Price of dish: " << endl;
		cin >> price;
		cin.ignore();
		cout << "Quantity of dish: " << endl;
		cin >> quantity;
		cin.ignore();
		cout << "Description of dish (<= 80 characters): " << endl;
		getline(cin, desc);

		//add dish to menu
		menu.mDaily[i] = name;
		menu.mDailiesCost[i] = price;
		menu.mNumDailies[i] = quantity;
		menu.mDailyDesc[i] = desc;

	}
}

/* Function: changeStatus()
*   Purpose: Kitchen staff flags order as ready
*       Pre: Order is finished
*      Post: mstatus changed to true
*    Author: Alex Taxiera
****************************************************************/
bool Kitchen::changeStatus()
{
	bool status = false;
	char affirm;

	cout << "Change status of this order?(Y/N)\n";
	cin >> affirm;

	while (affirm != 'Y' && affirm != 'N')
	{
		cout << "(Y/N)\n";
		cin >> affirm;
	}

	if (affirm == 'Y')
	{
		mStatus = true;
	}
	return mStatus;

}

/* Function: createMenu()
*   Purpose: a Menu is created and all arrays are filled from txt file
*       Pre: Text files are populated
*      Post: Menu created
*    Author: Damon Devani
****************************************************************/
Menu Kitchen::createMenu()
{
	string stringInput, junk;
	int intInput;
	double doubleInput;

	ifstream fin;
	fin.open("menu.txt");	//can switch to constant if included in header.h

	Menu menu;

	for (int i = 0; i <= 5; i++){		//Entrees

		getline(fin, stringInput);
		menu.mEntrees[i] = stringInput;

		fin >> doubleInput;
		menu.mEntreesCost[i] = doubleInput;

		fin >> intInput;
		menu.mNumEntrees[i] = intInput;
		getline(fin, junk);

		getline(fin, stringInput);
		menu.mEntreesDesc[i] = stringInput;

	}

	for (int i = 0; i <= 2; i++){		//Appetizers

		getline(fin, stringInput);
		menu.mAppetizers[i] = stringInput;

		fin >> doubleInput;
		menu.mAppetizersCost[i] = doubleInput;

		fin >> intInput;
		menu.mNumAppetizers[i] = intInput;
		getline(fin, junk);

		getline(fin, stringInput);
		menu.mAppetizersDesc[i] = stringInput;
	}

	for (int i = 0; i <= 1; i++){		//Desserts

		getline(fin, stringInput);
		menu.mDesserts[i] = stringInput;

		fin >> doubleInput;
		menu.mDessertsCost[i] = doubleInput;

		fin >> intInput;
		menu.mNumDesserts[i] = intInput;
		getline(fin, junk);

		getline(fin, stringInput);
		menu.mDessertsDesc[i] = stringInput;
	}

	fin.close();
	
	addDailyItems(menu);

	return menu;

}

/* Function:  viewOrder
*   Purpose:  To output the order to the screen
*       Pre:  none
*      Post:  Order is outputted
*    Author:  Stephen Brikiatis
*****************************************************************/
void Kitchen::viewOrder(Table mainArray[], int MAX_TABLES)
{
	int id;

	cout << "Enter the id of the table you want to check: ";
	cin >> id;

	for (int i = 0; i < MAX_TABLES; i++)
	{
		if (mainArray[i].id == id)
		{
			mainArray[i].displayOrder();
			break;
		}
	}
}

/* Function:  Operator Overloading
*   Purpose:  Overload the output operator
*       Pre:  None 
*      Post:  The output operator is overloaded
*    Author:  Duncan Carroll
*****************************************************************/
ofstream operator<<(ofstream fout, Menu menu)
{
//add entress to the text file in the same format as the menu.txt
	for (int i = 0; i < 6; i++)
	{
		fout << menu.mEntrees[i] << endl
			<< menu.mEntreesCost[i] << endl
			<< menu.mNumEntrees[i] << endl
			<< menu.mEntreesDesc[i] << endl;
	}
	//adds appetizers
	for (int i = 0; i < 3; i++)
	{
		fout << menu.mAppetizers[i] << endl
			<< menu.mAppetizersCost[i] << endl
			<< menu.mNumAppetizers[i] << endl
			<< menu.mAppetizersDesc[i] << endl;
	}
	//adds desserts
	for (int i = 0; i < 2; i++)
	{
		fout << menu.mDesserts[i] << endl
			<< menu.mDessertsCost[i] << endl
			<< menu.mNumDesserts[i] << endl
			<< menu.mDessertsDesc[i] << endl;
	}

	return fout;
}
