#include "./grass_type.h"

using namespace std;

void Grass_type::print_event() {

    cout << 'G';

}


/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
Grass_type::Grass_type() {

    name = "Venasaur";
    type = 3;

}

/****************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
 * ***************************************************************/
int Grass_type::grant_gift() {

    if(capture()) {
        srand(time(NULL));
        int choose = rand() % 10;
        if(choose < 5) {
            cout << "You caught Bulbasaur!" << endl;
            return 7;
        }
        else {
            cout << "You caught Treecko!" << endl;
            return 8;
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
bool Grass_type::capture() {

    srand(time(NULL));
    int gottem = rand() % 4;
    if(gottem != 0) {
        return true;
    }
    else
        return false;

}
