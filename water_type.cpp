#include "./water_type.h"

using namespace std;

void Water_type::print_event() {

    cout << 'W';

}


/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
Water_type::Water_type() {

    name = "Mudkip";
    type = 1;

}

/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
int Water_type::grant_gift() {

    if(capture()) {
        srand(time(NULL));
        int choose = rand() % 10;
        if(choose < 5) {
            cout << "You caught Squirtle!" << endl;
            return 5;
        }
        else {
            cout << "You caught Mudkip!" << endl;
            return 6;
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
bool Water_type::capture() {

    srand(time(NULL));
    int gottem = rand() % 2;
    if(gottem == 0) {
        return true;
    }
    else
        return false;

}
