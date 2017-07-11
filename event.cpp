#include "./event.h"
#include <iostream>

using namespace std;

bool Event::prof_good() {

    return false;

}

void Event::print_event() {

    cout << "+";

}

/****************************************************************
 * Function: grant_gift
 * Description: grants the player the type of event they have
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 0
 * ***************************************************************/
int Event::grant_gift() {

    return 0;

}

/****************************************************************
 * Function: hint
 * Description: virutal function that prints a message
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Event::hint() {

    return;

}

/****************************************************************
 * Function: destroy
 * Description: not sure why I have this function
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Event::destroy() {

    return;

}
