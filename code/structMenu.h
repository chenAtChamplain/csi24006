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

#ifndef STRUCTMENU_H
#define STRUCTMENU_H

//#include "header.h"	We'll probably have one 
#include <string>
#include <iostream>

using namespace std;

const int APP = 3, ENTREE = 6, DESS = 2, DAILY = 1;

struct Menu{

		int mNumAppetizers[APP];
		int mNumEntrees[ENTREE];
		int mNumDesserts[DESS];
		int mNumDailies[DAILY];		//Prob not necessary as it is a single, though i've left in incase needed
		
		double mAppetizersCost[APP];
		double mEntreesCost[ENTREE];
		double mDessertsCost[DESS];
		double mDailiesCost[DAILY];
		
		string mAppetizers[APP];
		string mAppetizersDesc[APP];

		string mEntrees[ENTREE];
		string mEntreesDesc[ENTREE];

		string mDesserts[DESS];
		string mDessertsDesc[DESS];

		string mDaily[DAILY];
		string mDailyDesc[DAILY];

};

#endif