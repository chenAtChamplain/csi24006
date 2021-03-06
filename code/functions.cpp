#include "header.h"


/* Function:  LoadEmployee
*   Purpose:  To fill the list with employees from text file.
*       Pre:  inizalized employeeList array
*      Post:  List filled with Id, Name, Password, Wage ect.
*    Author:  Stephen Brikiatis
*****************************************************************/
int loadEmployee(Employee employeeList[])
{
    ifstream file;
    int intHolder, i =0;
	string stringHolder, junk;
	char charHolder;

	file.open("employee.txt");

	if(file.good())
	{
		while(!file.eof())
		{
			file >> intHolder;
			employeeList[i].setId(intHolder);
			getline(file, junk);
			getline(file, stringHolder);
			employeeList[i].setPassword(stringHolder);
			getline(file, stringHolder);
			employeeList[i].setName(stringHolder);
			getline(file, stringHolder);
			employeeList[i].setAddress(stringHolder);
			getline(file, stringHolder);
			employeeList[i].setPhone(stringHolder);
			file >> intHolder;
			employeeList[i].setWages(intHolder);
			file >> charHolder;
			employeeList[i].setType(charHolder);
			getline(file, junk);
			i++;
		}
		file.close();
		return i;
	}
	else
	{
		cout << "File not found.";
		pause();
		file.close();
		return 0;
	}
}

/* Function:  LoadTable
*   Purpose:  Create table array
*       Pre:  "Table.txt"
*      Post:  Table array is populated
*    Author:  Stephen Brikiatis
*****************************************************************/
void loadTable(Table thelist[])
{
   ifstream file;
	int holder;

	file.open("Table.txt"); //constant

	if(file.good())
	{
		for(int i = 0; i < MAX_TABLE; i++)
		{
			file >> holder;
			thelist[i].id = holder;
			file >> holder;
			thelist[i].maxPeople = holder;
		}
	}

	file.close();
}


void login()
{
   //  this need to be built
}


void logout()
{
   //  this need to be built
}


/* Function:  Main Menu Show
*   Purpose:  Shows Main Menu for entire program
*       Pre:  None 
*      Post:  A menu with choices is displayed
*    Author:  Tony Taylor & Alex Taxiera
*****************************************************************/
void mainMenuShow()
{
        clearScreen();
        
        cout << setw(8) << left << "Choice" << left << "Option\n"
    	    << setw(8) << left << "T"  << left << "Table Menu\n"
		    << setw(8) << left << "K"  << left << "Kitchen Menu\n"
		    << setw(8) << left << "L"  << left << "Login\n"
            << setw(8) << left << "S"  << left << "Logout\n";
}

/* Function:  Main Menu
*   Purpose:  calls display and carries out selection
*       Pre:  None 
*      Post:  A menu with choices is displayed and an option is selected
*    Author:  Tony Taylor & Alex Taxiera
*****************************************************************/
void mainMenu(Table table[], Kitchen kitchen[], Manager manager, Host host[])
{
   char menuChoice;
   do
   {
    mainMenuShow();

    cout << "\nChoice:  ";
    cin >> menuChoice;
    
    menuChoice = toupper(menuChoice);

      switch (menuChoice)
      {
         case 'H':
            host.menu(table);
            break;
         case 'T':
            //table.menu();
            break;
         case 'K':
            kitchen.createMenu();
            break;
         case 'L':
            login();
            break;
         case 'S':
            logout();
            break;
         case '>':
            manager.menu(kitchen, host);
            break;
         default:
            clearScreen();
            cout << "Option not available!\n\n";
      }
   } while (menuChoice != 'H' && menuChoice != 'T' && menuChoice != 'K' && menuChoice != 'L' && menuChoice != 'S' && menuChoice != '>');
}


/* Function:  saveEmployees
*   Purpose:  Save any changes made by the manager during the day.
*       Pre:  Inizalized employee list and a number of current employees generated by loadEmployee
*      Post:  list is dumped into a text file
*    Author:  Stephen Brikiatis
*****************************************************************/
void saveEmployees(Employee employeeList[], int numEmployees)
{
    ofstream file;

	file.open(EMPLOYEE_FILE);

	if(file.good())
	{
		for(int i = 0; i < numEmployees; i++)
		{
			file << employeeList[i].getId()
				<< endl << employeeList[i].getPassword()
				<< endl <<  employeeList[i].getName()
				<< endl <<  employeeList[i].getAddress()
				<< endl <<  employeeList[i].getPhone() 
				<< endl <<  employeeList[i].getWages()
				<< endl <<  employeeList[i].getType() << endl;
		}
	}
	else
	{
		cout << "File not found, changed data not saved.";
		pause();
	}
	file.close();
}