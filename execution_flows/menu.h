//Lib to main menu methods
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

using namespace std;

/**
 * Method to print menu and return the selected option
 * @author caiosdeo 
 * @return unsigned selected option
 */
int menu();

/**
 * Executes the flow that is passed as parameter
 * @author caiosdeo
 * @param option unsigned selected option
 * @param size table size
*/
void select(int option, int size);


#endif //MENU_H_INCLUDED