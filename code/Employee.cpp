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

#include "Employee.h"

Employee:: Employee()
{
	mId = 0;
	mName = "";
	mWages = 0.0;
	mAddress = "";
	mPhone = "";
	mWorking = false;
}

Employee::Employee(int Id, string Name, string Address, string Phone, double Wages,
		bool Working)
{
	mId = Id;
	mName = Name;
	mAddress = Address;
	mPhone = Phone;
	mWages = Wages;
	mWorking = Working;
}

Employee:: ~Employee()
{

}

//accessors
int Employee::getId()
{
	return mId;
}

string Employee::getName()
{
	return mName;
}

double Employee::getWages()
{
	return mWages;
}

string Employee::getAddress()
{
	return mAddress;
}

string Employee::getPhone()
{
	return mPhone;
}

string Employee::getType
{
	return mType;
}

bool Employee::getWorking()
{
	return mWorking;
}

void Employee::setId(int id)
{
	mId = id;
}

void Employee::setName(string name)
{
	mName = name;
}

void Employee::setWages(double wages)
{
	mWages = wages;
}

void Employee::setAddress(string address)
{
	mAddress = address;
}

void Employee::setPhone(string phone)
{
	mPhone = phone;
}

void setType(string type)
{
	mType = type;
}


void Employee::setWorking(bool work)
{
	mWorking = work;
}

void generalEmployeeLogin(int id)
{
	
}

void generalEmployeeLogout(int id)
{
	
}

/* Function:  Password Masking
*   Purpose:  Masks password as it is entered
*       Pre:  None
*      Post:  Password is returned
*    Author:  Tony Taylor
*****************************************************************/
string passwordMask()
{
	bool show_asterisk = true;
	const char BACKSPACE = 8;
	const char RETURN = 13;

	string password;
	unsigned char ch = 0;

	while ((ch = _getch()) != RETURN)
	{
		
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}

		else if (ch == 0 || ch == 224) 
		{
			_getch(); 
			continue;
		}

		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}

	}

	cout << endl;

	return password;
	}
}

friend istream &operator>>(istream &input, Employee &e)
{
    string str;
    
    cout << "Enter new ID:  ";
    getline(cin, e.mId);
    
    cout << "Enter new name:  ";
    getline(cin, e.mName);
    
    cout << "Enter new address:  ";
    getline(cin, e.mAddress);
    
    cout << "Enter new phone number:  ";
    getline(cin, e.mPhone);
    
    cout << "Enter new wages:  ";
    getline(cin, str);
    m.mWages = stod(str);
    
    cout << "Enter new position:  ";
    getline(cin, e.mType);
    
    return cin;
}