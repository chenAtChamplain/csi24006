#include "Employee.h"

Employee::Employee()
{
	mId = ' ';
	mName = "";
	mWages = 0.0;
	mAddress = "";
	mPhone = "";
	mWorking = false;
}

Employee::Employee(int Id, string Name, string Address, string Phone, double Wages,
	bool Working, string Password)
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

char Employee::getType()
{
	return mType;
}

bool Employee::getWorking()
{
	return mWorking;
}

string Employee::getPassword()
{
	return mPassword;
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

void Employee::setType(char type)
{
	mType = type;
}

void Employee::setWorking(bool work)
{
	mWorking = work;
}

void Employee::setPassword(string password)
{
	mPassword = password;
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

/* Function:  Operator Overloading
*   Purpose:  Overload the input operator
*       Pre:  None
*      Post:  The input operator is overloaded and an employee object is edited
*    Author:  Lucas Spiker + Duncan Carroll
*****************************************************************/
istream &operator>>(istream &input, Employee &e)
{
	bool valid = false;
	string tmp;

	while (!valid)
	{
		valid = true;
		cout << "Enter new ID:  ";
		getline(cin, tmp);
		//Make sure only numbers were entered.
		for (int i = 0; i < static_cast<int>(tmp.length()); i++)
		{
			if (!isdigit(tmp[i]))
			{
				valid = false;
			}
		}
	}
	e.mId = stoi(tmp);
	valid = false;

	while (!valid)
	{
		cout << "Enter new name:  ";
		getline(cin, tmp);
		//Make sure there were at least two names entered.
      for (int i = 0; i < static_cast<int>(tmp.length()); i++)
		{
			if (tmp[i] == ' ')
			{
				e.mName = tmp;
				valid = true;
			}
		}
	}
	valid = false;

	cout << "Enter new address:  ";
	getline(cin, e.mAddress);

	while (!valid)
	{
		cout << "Enter new phone number:  ";
		getline(cin, tmp);
		//Make sure that the number is formatted properly. "(###) ###-####"
		if (tmp[0] == '(' &&
			tmp[4] == ')' &&
			tmp[5] == ' ' &&
			tmp[9] == '-')
		{
			e.mPhone = tmp;
			valid = true;
		}

	}
	valid = false;

	while (!valid)
	{
		valid = true;
		cout << "Enter new wages:  ";
		getline(cin, tmp);
      for (int i = 0; i < static_cast<int>(tmp.length()); i++)
		{
			if (!isdigit(tmp[i]) && tmp[i] != '.')
			{
				valid = false;
			}
		}
	}
	e.mWages = stod(tmp);
	valid = false;

	return cin;
}