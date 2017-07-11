#include <iostream>
#include "./location.h"

using namespace std;

/****************************************************************
 * Function: main
 * Description: starts game and asks if you want to keep playing
 * Parameters: argc and argv - command line arguments
 * Pre-Conditions: command line argument
 * Post-Conditions: none
 * Return: 0 - end of program
 * ***************************************************************/
int main(int argc, char **argv) {

    int play=0;
    Location l;
    cout << "Welcome!" << endl;
    int size = atoi(argv[1]);
    l.new_game(size);
    while(play != 3) {
        cout << "[1] Same Map" << endl
             << "[2] Different Map" << endl
             << "[3] Quit" << endl;
        cin >> play;
        if(play == 1) {
            l.continue_game();
        }
        else if(play == 2) { 
            //delete shit
            cout << "Enter new grid size" << endl;
            cin >> size;
            l.~Location();
            l.new_game(size);
        }
        else {
            cout << "thanks for playing" << endl;
            break;
        }

    }

    return 0;

}
