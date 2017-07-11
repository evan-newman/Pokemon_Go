#include "./fire_type.h"

using namespace std;

void Fire_type::print_event() {

    cout << 'F';

}



/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
Fire_type::Fire_type() {

    name = "charmander";
    type = 0;

}

/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
int Fire_type::grant_gift() {

    if(capture()) {
        srand(time(NULL));
        int choose;
        choose = rand() % 10;
        if(choose < 5) {
            cout << "You caught Charmander!" << endl;
            return 3;
        }
        else {
            cout << "You caught Torchic!" << endl;
            return 4;
        }
    }
    else {
        cout << "Pokemon Escaped!" << endl;
        return 0;
    }

}

/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
bool Fire_type::capture() {

    srand(time(NULL));
    int gottem = rand() % 4;
    if(gottem == 0) {
        return true;
    }
    else
        return false;

}
