#include "./pokecenter.h"

using namespace std;

bool Pokecenter::prof_good() {

    return false;

}


void Pokecenter::print_event() {

    cout << "S";

}

/****************************************************************
 * Function: grant_gift
 * Description: type of event the user is in
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 2
 * ***************************************************************/
int Pokecenter::grant_gift() {

    return 2;

}

/****************************************************************
 * Function: hint
 * Description: print user message if near a pokecenter
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Pokecenter::hint() {

    cout << "There's a Pokecenter Nearby! :V" << endl;

}
