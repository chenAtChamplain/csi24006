#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "Employee.h"
#include "Manager.h"
#include "Host.h"
#include "Table.h"
#include "Kitchen.h"
#include "common.h"

using namespace std;



const string EMPLOYEE_FILE = "employee.txt";
const string TABLE_FILE = "Table.txt";

int loadEmployee(Employee employeeList[]);

void loadTable(Table theList[]);

void lodin();

void logout();

void mainManuShow();

void mainMenu(Table table[], Kitchen kitchen[], Manager manager, Host host[]);


#endif