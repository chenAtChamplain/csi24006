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

#ifndef _TABLE_H
#define _TABLE_H

#include "LinkedList.h"
#include <iostream>
#include <string>
#include "structMenu.h"

using namespace std;

class Table
{
	public:
		Table();
		~Table();
		
		int id, maxPeople;
		bool isAvailable;
		string waitStaff;
		
		void takeOrder(Menu &todayMenu);
		void changeOrder();
		void deleteOrder();
		void displayOrder();
		double generateBill(Menu todayMenu);
		bool searchForItem(string itemsName, int arraySize, string arrayOfNames[], int &num);
		
	private:
		LinkedList order;
		
}

#endif