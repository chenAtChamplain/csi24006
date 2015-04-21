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
	string mName, mAddress, mPhone, mPassword;
	double mWages;
	bool mWorking;
	char mType;

public:
	Employee();
	Employee(int Id, string Name, string Address, string Phone, double Wages,
		bool Working, string Password);
	~Employee();

	//accessors
	int getId();
	string getName();
	double getWages();
	string getAddress();
	string getPhone();
	bool getWorking();
	char getType();
	string getPassword();

	//mutators
	void setId(int id);
	void setName(string name);
	void setWages(double);
	void setAddress(string address);
	void setPhone(string phone);
	void setWorking(bool wook);
	void setType(char type);
	void setPassword(string password);

	void generalEmployeeLogin(int id);
	void generalEmployeeLogout(int id);
	string passwordMask();

	friend istream &operator>>(istream &input, Employee &e);
};




#endif