#ifndef _TABLE_H
#define _TABLE_H

#include "LinkedList.h"
#include <iostream>
#include <string>
#include "structMenu.h"

using namespace std;

class Table : public LinkedList
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
		
};

#endif