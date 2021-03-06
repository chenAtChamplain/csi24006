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

#ifndef _KITCHEN_H
#define _KITCHEN_H

#include <iostream>
#include <fstream>
#include <string>
#include "common.h"
//#include "header.h"
#include "Employee.h"
#include "structMenu.h"
#include "table.h"

class Kitchen : protected Employee

{
private:
	bool mStatus;

public:
	Kitchen();
	~Kitchen();

	void addDailyItems(Menu menu);    //add dailies
	bool changeStatus();
	Menu createMenu();	//pull from text file?
	bool getStatus();
	void viewOrder(Table mainArray[], int MAX_TABLES);
	friend ofstream operator<<(ofstream fout, Menu menu);
};

#endif

