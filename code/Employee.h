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

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

class Employee
{
protected:
	int mId;
	string mName, mAddress, mPhone;
	double mWages;
	bool mWorking;

public:
	Employee();
	Employee(int mId, string mName, string mAddress, string mPhone, double mWages,
		bool mWorking);
	~Employee();

	//accessors
	int getId();
	string getName();
	double getWages();
	string getAddress();
	string getPhone();
	bool getWorking();

	//mutators
	void setId(int id);
	void setName(string name);
	void setWages(double);
	void setAddress(string address);
	void setPhone(string phone);
	void setWorking(bool wook);

	void generalEmployeeLogin(int id);
	void generalEmployeeLogout(int id);
	string passwordMask();

	friend istream &operator>>(istream &input, Employee &e);
};




#endif