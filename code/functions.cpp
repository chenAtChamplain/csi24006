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

#include "header.h"

void clearScreen()
{
   system("cls");
}

void mainMenuShow()
{
   cout << setw(5) << "A:" << "Table Menu\n"
      << setw(5) << "B:" << "Kitchen Menu\n"
      << setw(5) << "C:" << "Login\n"
      << setw(5) << "D:" << "Logout\n\n";

}

void mainMenu()
{
   char menuChoice;
   do
   {
      mainMenuShow();

      cin >> menuChoice;

      switch (menuChoice)
      {
         case 'A':
            TableObj.menu();
            break;
         case 'B':
            KitchenObj.menu();
            break;
         case 'C':
            login();
            break;
         case 'D':
            logout();
            break;
         case '>':
            ManagerObj.menu();
            break;
         default:
            clearScreen();
            cout << "Option not available!\n\n";
      }
   } while (menuChoice != 'A' && menuChoice != 'B' && menuChoice != 'C' && menuChoice != 'D' && menuChoice != '>');
}
