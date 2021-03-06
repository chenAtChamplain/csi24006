#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string password)
{
    mPassword = password;
}

Manager::~Manager()
{
}


string Manager::getPassword()
{
	return mPassword;
}

double Manager::getTotalSale()
{
	return mTotalSale;
}

int Manager::getNumOfOrders()
{
	return mNumOfOrders;
}

void Manager::setPassword(string password)
{
	mPassword = password;
}

void Manager::setTotalSale(double sale)
{
	mTotalSale = sale;
}

void Manager::setNumOfOrders(int orders)
{
	mNumOfOrders = orders;
}


/* Function:  dailyAveragePerOrder
*   Purpose:  To generate the average
*       Pre:  None
*      Post:  Average is returned to caller
*    Author:  Tony Taylor
*****************************************************************/
double Manager::dailyAveragePerOrder()
{
	return (mTotalSale / mNumOfOrders);
}

/* Function:  Fire Employee
*   Purpose:  To remove an employee from the system data
*       Pre:  populated employee ("employees[]")array must exist
*      Post:  Employee data is removed from the array
*    Author:  Justin Fernandez
*****************************************************************/
void Manager::fireEmployee(Employee employees[])
{
	int id;
	int employeeLocation;

	cout << "Enter employee ID\n";
	cin >> id;

	employeeLocation = searchEmployee(id, employees);

	if (employeeLocation != -1)
	{
		for (int i = employeeLocation; i < (MAX_EMPLOYEES - 2); i++)
		{
			employees[i] = employees[i + 1];
		}

		Employee newEmployee;
		employees[MAX_EMPLOYEES - 1] = newEmployee;
	}
}

/* Function:  Generate Report
*   Purpose:  To generate a sales report
*       Pre:  None
*      Post:  Sales report is appended to sales file
*    Author:  Justin Fernandez
*****************************************************************/
void Manager::generateReport()
{
	ofstream fout;
	fout.open("sales.txt", ios::app);

		fout << "Sales Report for " << __TIMESTAMP__ << ":\n"
		<< "Total Sales: " << mTotalSale << endl
		<< "Total Orders: " << mNumOfOrders << endl
		<< "Average $ per Order: " << dailyAveragePerOrder()
		<< endl << endl;

	fout.close();

	cout << "Sales Report for " << __TIMESTAMP__ << ":\n"
		<< "Total Sales: " << mTotalSale << endl
		<< "Total Orders: " << mNumOfOrders << endl
		<< "Average $ per Order: " << dailyAveragePerOrder()
		<< endl;
}

/* Function:  Hire Employee
*   Purpose:  To hire an employee
*       Pre:  Employee array ("employees[]") must be declared
*      Post:  Employee data is added to the array
*    Author:  Duncan Carroll
*****************************************************************/
void Manager::hireEmployee(Employee employees[])
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (employees[i].getId() == ' ')
		{
			Employee newEmployee;
			cin >> newEmployee;
			employees[i] = newEmployee;
			return;
		}
	}

	cout << "Cannot hire any more employees\n";
	pause();
}

/* Function:  Main Menu
*   Purpose:  Main Menu for Manager Operations
*       Pre:  None
*      Post:  carrys out selected menu option
*    Author:  Tony Taylor
*****************************************************************/
bool Manager::menu(Kitchen kitchen[], Host host[])
{
	char choice;

	do
	{
		clearScreen();

		cout << setw(8) << left << "Choice" << left << "Option\n"
			<< setw(8) << left << "U" << left << "Update Employee\n"
			<< setw(8) << left << "H" << left << "Hire Employee\n"
			<< setw(8) << left << "F" << left << "Fire Employee\n"
			<< setw(8) << left << "R" << left << "Return\n"
			<< setw(8) << left << "S" << left << "Shut Down\n";

		cout << "Choice:  ";
		cin >> choice;

		choice = toupper(choice);

		switch (choice)
		{
		case 'U': updateEmployee(employees);
			break;

		case 'H': hireEmployee(employees);
			break;

		case 'F': fireEmployee(employees);
			break;

		case 'R': return false;
			break;

		case 'S': return shutDown();
			break;

		default: cout << "Invalid Entry";
			break;
		}
	} while (choice != 'S');

   return false;
}

/* Function:  Search Employees
*   Purpose:  To Search for an Employee
*       Pre:  None
*      Post:  Returns true if employee is found
*    Author:  Justin Fernandez
*****************************************************************/
int Manager::searchEmployee(int searchKey, Employee employees[])
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (employees[i].getId() == searchKey)
			return i;
	}

	cout << "Employee not found\n";
	return -1;
}

/* Function:  Shut Down
*   Purpose:  To Shut down the system
*       Pre:  None
*      Post:  generateeport() is called and the system shuts down
*    Author:  Justin Fernandez
*****************************************************************/
bool Manager::shutDown()
{
	char option;

	cout << "Do you wish to shut down? Y/N \n";
	cin >> option;

	if (option == 'Y' || option == 'y')
	{
		cout << "Generating Sales Report:\n";
		generateReport();
		pause();
		return true;
	}
	else
		return false;
}

/* Function:  Update Employee
*   Purpose:  To update employee information
*       Pre:  A populated employee array("employees[]")
*      Post:  Employee data in the array is replaced
*    Author:  Tony Taylor
*****************************************************************/
void Manager::updateEmployee(Employee employees[])
{
	int id;
	int employeeLocation;

	cout << "Enter employee ID\n";
	cin >> id;

	employeeLocation = searchEmployee(id, employees);

	if (employeeLocation != -1)
	{
		Employee updatedEmployee;
		cin >> updatedEmployee;
		employees[employeeLocation] = updatedEmployee;
	}
}
