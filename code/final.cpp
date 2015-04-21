#include "header.h"


// this need to be changed;  wkc
const int TMP_NUM = 10;

int main()
{
    Manager manager;
    Host host[TMP_NUM];
    Table table[TMP_NUM];
    Kitchen kitchen[TMP_NUM];
    
    mainMenu(table, kitchen, manager, host);
    
	return 0;
}
