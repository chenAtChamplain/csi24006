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