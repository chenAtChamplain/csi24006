#ifndef HOST_H
#define HOST_H

#include <iostream>
#include "employee.h"
#include "table.h"
#include <string>

using namespace std;

const int MAX_TABLE = 15;

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
		void menu(Table table[]);
		void searchTableAvailable(Table table[]);
		void searchTableSeat(Table table[]);
};

#endif