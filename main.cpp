#include <iostream>
#include "./location.h"

using namespace std;

void bad_input() {
	cout  << "Please rerun executable with ./game #\n"
	      << "ex) ./game 5\n"
	      << "make sure number is larger than 5 "
	      << "or will get error" << endl;

	return;
}

/****************************************************************
 * Function: main
 * Description: starts game and asks if you want to keep playing
 * Parameters: argc and argv - command line arguments
 * Pre-Conditions: command line argument
 * Post-Conditions: none
 * Return: 0 - end of program
 * ***************************************************************/
int main(int argc, char **argv) {

    int play=0, size=0;
    Location l;
	if(argc == 1 || argc > 2) {
		cout << "You have specified an incorrect amount of commands!\n"
		     << endl;
		bad_input();
		return 0;
	}
	else if(atoi(argv[1]) < 5) { 		
		cout << "second command you have entered is either too small "
		     << "or is not a number\n" << endl;
		bad_input();
		return 0;
	}
	
    size = atoi(argv[1]);		//converts second arg to int and store
    l.new_game(size);			//2.look at location.h and .cpp
    while(play != 3) {
        cout << "[1] Same Map" << endl
             << "[2] Different Map" << endl
             << "[3] Quit" << endl;
        cin >> play;
        if(play == 1) {
            l.continue_game();
        }
        else if(play == 2) { 
            cout << "Enter new grid size" << endl;
            cin >> size;
            l.~Location();		//remember what ~ means
            l.new_game(size);
        }
        else {
            cout << "thanks for playing" << endl;
            break;
        }

    }

    return 0;

}
