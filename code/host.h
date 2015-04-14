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

#ifndef HOST_H
#define HOST_H

#include <iostream>
#include "employee.h"
#include "table.h"

const int MAX_TABLE = 15;

using namespace std;

class Host : public Employee
{
	private:
		int mWaitStaffWorking;

	public:
		Host();
		Host(int Id, string name, double wages, string address, string phone, int waitStaffWorking);
		~Host();

		bool assignTable(int Id, Table table[]);
		bool freeTable(int Id, Table table[]);
		void hostUserMenu();
		void searchTableAvailable(Table table[]);
		void searchTableSeat(Table table[]);
};

#endif