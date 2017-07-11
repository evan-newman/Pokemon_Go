#include "./cave.h"

using namespace std;

bool Cave::prof_good() {

    return false;

}

void Cave::print_event() {

    cout << "C";

}

/****************************************************************
 * Function: grant_gift
 * Description: type of event the pointer is
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 1
 * ***************************************************************/
int Cave::grant_gift() {

    return 1;

}

/****************************************************************
 * Function: hint
 * Description: prints message of cave nearby
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Cave::hint() {

    cout << "There's a cave nearby! :O" << endl;

}
