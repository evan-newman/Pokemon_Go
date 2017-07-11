#include "./pokemon.h"

using namespace std;

bool Pokemon::prof_good() {

    return false;

}

void Pokemon::print_event() {

    cout << 'P';

}

/****************************************************************
 * Function: Pokemon
 * Description: constructor for pokemon class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
Pokemon::Pokemon() {

    name = "None";
    type = 0;

}

/****************************************************************
 * Function: grant_gift
 * Description: type of event the user is doing
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 3
 * ***************************************************************/
int Pokemon::grant_gift() {

    return 3;

}

/****************************************************************
 * Function: hint
 * Description: virutal function that prints the message
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Pokemon::hint() {

    cout << "There's a pokemon nearby!" << endl;

}
