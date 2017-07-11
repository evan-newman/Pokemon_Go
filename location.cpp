#include "./location.h"

using namespace std;

/****************************************************************
 * Function: Location
 * Description: constructore for loaction class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
Location::Location() {

    size = 0;
    loc = NULL;
    saved_loc = NULL;
    map = NULL;
    event = NULL;
    poke = NULL;
    fire = NULL;
    water = NULL;
    grass = NULL;
    cave = NULL;
    pc = NULL;
    nothing = NULL;
    prof_x = 0;
    prof_y = 0;

    player_inv = NULL;
    
}

/****************************************************************
 * Function: create_grid 
 * Description: creates the grid
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::create_grid() {

    loc = new Location *[size];
    for(int i=0; i<size; i++) {
        loc[i] = new Location [size];
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++){
            loc[i][j].event = NULL;
            loc[i][j].poke = NULL;
            loc[i][j].fire = NULL;
            loc[i][j].water = NULL;
            loc[i][j].grass = NULL;
            loc[i][j].cave = NULL;
            loc[i][j].pc = NULL;
            loc[i][j].nothing = NULL;
        }
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            loc[i][j].nothing = new Nothing;
            loc[i][j].event = loc[i][j].nothing;
        }
    }

}

/****************************************************************
 * Function: populate_grid
 * Description: fills grid with events
 * Parameters: none
 * Pre-Conditions: created grid
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::populate_grid() {

    int vert, horz;
    srand(time(NULL));
    for(int i=0; i<8; i++) {
        do {
            vert = rand() % size;
            horz = rand() % size;
        }while(loc[horz][vert].event != loc[horz][vert].nothing);
        delete loc[horz][vert].nothing;
        loc[horz][vert].nothing = NULL;
        loc[horz][vert].event = NULL;
        
        if(i==0){
            loc[horz][vert].cave = new Cave;
            loc[horz][vert].event = loc[horz][vert].cave;
            //cout << "CAVE\n" << "y: " << vert << "\nx: " << horz << endl;
        }else if(i==1) {
            loc[horz][vert].pc = new Pokecenter;
            loc[horz][vert].event = loc[horz][vert].pc;
            //cout << "POKECENTER\n" << "y: " << vert << "\nx: " << horz << endl;
        }else if(i==2 || i==3) {
            loc[horz][vert].fire = new Fire_type;
            loc[horz][vert].event = loc[horz][vert].fire;
            //cout << "FIRE\n" << "y: " << vert << "\nx: " << horz << endl;
        }else if(i==4 || i==5) {
            loc[horz][vert].water = new Water_type;
            loc[horz][vert].event = loc[horz][vert].water;
            //cout << "WATER\n" << "y: " << vert << "\nx: " << horz << endl;
        }else if(i==6 || i==7) {
            loc[horz][vert].grass = new Grass_type;
            loc[horz][vert].event = loc[horz][vert].grass;
            //cout << "GRASS\n" << "y: " << vert << "\nx: " << horz << endl;
        }
    }
}

/****************************************************************
 * Function: save_grid
 * Description: saves the previous grid so you can play again
 * Parameters: none
 * Pre-Conditions: already intilized and populated location grid
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::save_grid() {

    saved_loc = new Location *[size];
    for(int i=0; i<size; i++) {
        saved_loc[i] = new Location [size];
    }

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            saved_loc[i][j] = loc[i][j];
        }
    }

}

/****************************************************************
 * Function: pofessor_loc
 * Description: picks a location to end the game
 * Parameters: none
 * Pre-Conditions: already created grid filled with events
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::professor_loc() {

    int vert, horz;
    srand(time(NULL));
    do {
        vert = rand() % size;
        horz = rand() % size;
    }while(loc[horz][vert].event != loc[horz][vert].nothing);

    prof_x = vert;
    prof_y = horz;
    //cout << "prof y: " << prof_x << "\nprof x: " << prof_y << endl;

}

/****************************************************************
 * Function: create_map
 * Description: creates the visual map for player
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::create_map() {

    map = new char *[size];
    for(int i=0; i<size; i++) {
        map[i] = new char [size];
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            map[i][j] = '+';
        }
    }

}

/****************************************************************
 * Function: print_map
 * Description: prints the map with players location
 * Parameters: x and y the coordinates of player in grid
 * Pre-Conditions: initlized map
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::print_map(int x, int y) {

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++)  {
            if(i == y && j == x)
                cout << 'X';
            else if(i == prof_y && j == prof_x) {
                cout << '0';
            }
            else {
                //#ifdef DEBUG
                    loc[i][j].event->print_event();
                //#endif
                //cout << '+';
                //cout << map[i][j];
            }
        }
        cout << endl;
    }

}

/****************************************************************
 * Function: intilize_struct
 * Description: set all pokemon in players inventory to 0
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::initilize_struct() {

    player_inv = new struct pokemon_trainer;
    player_inv->pokeballs=5;
    player_inv->stones=0;

    player_inv->charmander=0;
    player_inv->charmeleon=0;
    player_inv->charizard=0;
    player_inv->torchic=0;
    player_inv->combuskin=0;
    player_inv->blaziken=0;
    player_inv->squirtle=0;
    player_inv->wartortle=0;
    player_inv->blastoise=0;
    player_inv->mudkip=0;
    player_inv->marshtomp=0;
    player_inv->swampert=0;
    player_inv->bulbasaur=0;
    player_inv->ivysaur=0;
    player_inv->venusaur=0;
    player_inv->treecko=0;
    player_inv->grovyle=0;
    player_inv->sceptile=0;

}

/****************************************************************
 * Function: new_game
 * Description: starts the game with new stuff
 * Parameters: s the size of the map
 * Pre-Conditions: command line argument for size
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::new_game(int s) {

    //make sure everything is deleted if gone through again and want new game NOT same
    size = s;
    create_grid();
    populate_grid();
    //save_grid();
    professor_loc();
    //create_map();
    initilize_struct();
    play_game();

}

/****************************************************************
 * Function: continue_game
 * Description: if player wants to play with same map when won
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: already made map
 * Return: none
 * ***************************************************************/
void Location::continue_game() {

    //delete struct
    delete player_inv;
    initilize_struct();
    play_game();

}

/****************************************************************
 * Function:  play_game
 * Description: where the player goes through the game and 
 *              checks to see if they leave and prints the message
 * Parameters: none
 * Pre-Conditions: created grid
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::play_game() {

    char move;
    int move_x = prof_x, move_y = prof_y, inv, count=0;
    cout << "Welcome to Pokemon CS!" << endl;
    cout << "WASD to move" << endl;
    cout << "[1] to check inventory" << endl;
    hint_message(move_x, move_y);
    while(check_end(move_x, move_y)) {
        print_map(move_x, move_y);
        cout << "Go Explore!" << endl;
        cin >> move;
        if(move == 'w') {
            if(out_of_bounds(move_x, move_y-1)) {
                move_y -= 1;
                cout << string(50, '\n');
                hint_message(move_x, move_y);
                inv = loc[move_y][move_x].event->grant_gift();
                change_inv(inv, move_x, move_y);
            }
        }
        else if(move == 'a') {
            if(out_of_bounds(move_x-1, move_y)) {
                move_x -= 1;
                cout << string(50, '\n');
                hint_message(move_x, move_y);
                inv = loc[move_y][move_x].event->grant_gift();
                change_inv(inv, move_x, move_y);
            }
        }
        else if(move == 's') {
            if(out_of_bounds(move_x, move_y+1)) {
                cout << string(50, '\n');
                move_y += 1;
                hint_message(move_x, move_y);
                inv = loc[move_y][move_x].event->grant_gift();
                change_inv(inv, move_x, move_y);
            }
        }
        else if(move == 'd') {
            if(out_of_bounds(move_x+1, move_y)) {
                cout << string(50, '\n');
                move_x += 1;
                hint_message(move_x, move_y);
                inv = loc[move_y][move_x].event->grant_gift();
                change_inv(inv, move_x, move_y);
            }
        }
        else if(move == '1') {
            cout << string(50, '\n');
            print_inventory();
        }
        else {
            cout << string(50, '\n');
            cout << "where are you going?" << endl;
        }
    }

}

void Location::print_inventory() {

    int i;
    cout << "-----------ALL ITEMS-------------" << endl;

    i = player_inv->pokeballs; 
    cout << "Pokeballs: " << i << endl;
    i = player_inv->stones; 
    cout << "Stones: " << i << endl << endl;
    i = player_inv->charmander; 
    cout << "Charmander: " << i << endl;
    i = player_inv->charmeleon; 
    cout << "Charmeleon: " << i << endl;
    i = player_inv->charizard; 
    cout << "Charizard: " << i << endl;
    i = player_inv->torchic; 
    cout << "Torchic: " << i << endl;
    i = player_inv->combuskin; 
    cout << "Combuskin: " << i << endl;
    i = player_inv->blaziken; 
    cout << "Blaziken: " << i << endl;
    i = player_inv->squirtle; 
    cout << "Squirtle: " << i << endl;
    i = player_inv->wartortle; 
    cout << "Wartortle: " << i << endl;
    i = player_inv->blastoise; 
    cout << "Blastoise: " << i<< endl;
    i = player_inv->mudkip; 
    cout << "Mudkip: " << i << endl;
    i = player_inv->marshtomp; 
    cout << "Marshtomp: " << i << endl;
    i = player_inv->swampert; 
    cout << "Swampert: " << i << endl;
    i = player_inv->bulbasaur; 
    cout << "Bulbasaur: " << i << endl;
    i = player_inv->ivysaur; 
    cout << "Ivysaur: " << i << endl;
    i = player_inv->venusaur; 
    cout << "Venusaur: " << i << endl;
    i = player_inv->treecko; 
    cout << "Treecko: " << i << endl;
    i = player_inv->grovyle; 
    cout << "Grovyle: " << i << endl;
    i = player_inv->sceptile; 
    cout << "Sceptile: " << i << endl;
   
}

/****************************************************************
 * Function: change_inv
 * Description: if player encounters an event change inventory
 * Parameters: v - players type of event they encounter
 * Pre-Conditions: chosen type of event
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::change_inv(int v, int x, int y) {

    if(v == 1) {
        cout << "you found a stone!" << endl;
        player_inv->stones += 1; 
        evolve();
    }
    else if(v == 2) {
        srand(time(NULL));
        int balls = rand() % 7 + 3;
        cout << "You got " << balls << " Pokeballs!" << endl;
        player_inv->pokeballs += balls;
    }
    else if(v == 3) {
        player_inv->charmander += 1;
        fire_evolve();
    }
    else if(v == 4) {
        player_inv->torchic += 1;
        fire_evolve();
    }
    else if(v == 5) {
        player_inv->squirtle += 1;
        water_evolve();
    }
    else if(v == 6) {
        player_inv->mudkip += 1;
        water_evolve();
    }
    else if(v == 7) {
        player_inv->bulbasaur += 1;
        grass_evolve();
    }
    else if(v == 8) {
        player_inv->treecko += 1;
        grass_evolve();
    }
    else if(v==0) {
        pokemon_run(x, y);
    }

}

void Location::pokemon_run(int x, int y) {

    int vert, horz;
    if(size > 3) {
            do {
                    vert = rand() % size;
                    horz = rand() % size;
            }while(loc[horz][vert].event != loc[horz][vert].nothing);

            delete loc[horz][vert].nothing;
            loc[horz][vert].nothing = NULL;
            loc[horz][vert].event = NULL;

            if(loc[y][x].fire != NULL) {
                delete loc[y][x].fire;
                loc[y][x].fire = NULL;
                loc[y][x].event = NULL;
                loc[y][x].nothing = new Nothing;
                loc[y][x].event = loc[y][x].nothing;
                loc[horz][vert].fire = new Fire_type;
                loc[horz][vert].event = loc[horz][vert].fire;
            }
            else if(loc[y][x].water != NULL) {
                delete loc[y][x].water;
                loc[y][x].water = NULL;
                loc[y][x].event = NULL;
                loc[y][x].nothing = new Nothing;
                loc[y][x].event = loc[y][x].nothing;
                loc[horz][vert].water = new Water_type;
                loc[horz][vert].event = loc[horz][vert].water;
            }
            else if(loc[y][x].grass != NULL){
                delete loc[y][x].grass;
                loc[y][x].grass = NULL;
                loc[y][x].event = NULL;
                loc[y][x].nothing = new Nothing;
                loc[y][x].event = loc[y][x].nothing;
                loc[horz][vert].grass = new Grass_type;
                loc[horz][vert].event = loc[horz][vert].grass;
            }

    }

}

void Location::fire_evolve() {

        if(player_inv->charmander >= 3) {
                player_inv->charmander -= 3;
                player_inv->charmeleon += 1;
                cout << "You evolved your charmander to Charmeleon (First Evolution)!!" << endl;
        }
        if(player_inv->torchic >= 3) {
                player_inv->torchic -= 3;
                player_inv->combuskin += 1;
                cout << "You evolved your Torchic to Combuskin (First Evolution)!!" << endl;
        }

}

void Location::water_evolve() {

        if(player_inv->squirtle >= 3) {
                player_inv->squirtle -= 3;
                player_inv->wartortle += 1;
                cout << "You evolved your Squirtle to Wartortle (First Evolution)!!" << endl;
        }
        if(player_inv->mudkip >= 3) {
                player_inv->mudkip -= 3;
                player_inv->marshtomp += 1;
                cout << "You evolved your Mudkip to Marshtomp (First Evolution)!!" << endl;
        }

}

void Location::grass_evolve() {

        if(player_inv->bulbasaur >= 3) {
                player_inv->bulbasaur -= 3;
                player_inv->ivysaur += 1;
                cout << "You evolved your Bulbasaur to Ivysaur (First Evolution)!!" << endl;
        }
        if(player_inv->treecko >= 3) {
                player_inv->treecko -= 3;
                player_inv->grovyle += 1;
                cout << "You evolved your Treecko to Grovyle (First Evolution)!!" << endl;
        }

}
/****************************************************************
 * Function: evolve
 * Description: changes players pokemon to level 2
 * Parameters: none
 * Pre-Conditions: more than one stone in players invintory
 * Post-Conditions: evolved pokemon in struct
 * Return: none
 * ***************************************************************/
void Location::evolve() {

        //Fire Type
        if(player_inv->charmeleon > 0) {
                player_inv->charmeleon -= 1;
                player_inv->charizard += 1;
                cout << "You evolved your Charmeleon to Charizard (Second Evoluation)!!" << endl;
        }

        if(player_inv->combuskin > 0) {
                player_inv->combuskin -= 1;
                player_inv->blaziken += 1;
                cout << "You evolved your Combuskin to Blaziken (Second Evolution)!!" << endl;
        }

        //Water Type
        if(player_inv->wartortle > 0) {
                player_inv->wartortle -= 1;
                player_inv->blastoise += 1;
                cout << "You evolved your Combuskin to Blaziken (Second Evolution)!!" << endl;
        }

        if(player_inv->marshtomp > 0) {
                player_inv->marshtomp -= 1;
                player_inv->swampert += 1;
                cout << "You evolved your Marshtomp to Swampert (Second Evolution)!!" << endl;
        }

        //Grass Type
        if(player_inv->ivysaur > 0) {
                player_inv->ivysaur -= 1;
                player_inv->venusaur += 1;
                cout << "You evolved your Ivysaur to Venusaur (Second Evolution)!!" << endl;
        }

        if(player_inv->grovyle > 0) {
                player_inv->grovyle -= 1;
                player_inv->sceptile += 1;
                cout << "You evolved your Grovyle to Sceptile (Second Evolution)!!" << endl;
        }

}
//DELETE THIS FUNCTION????
/****************************************************************
 * Function: change_inv_pokemon
 * Description: changes players pokemon number
 * Parameters: pie - type of pokemon they captured
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::change_inv_pokemon(int pie) {


        if(pie == 3) {
                player_inv->charmander += 1;
        }
        else if(pie == 4) {
                player_inv->torchic += 1;
        }
        else if(pie == 5) {
                player_inv->squirtle += 1;
        }
        else if(pie == 6) {
                player_inv->mudkip += 1;
        }
        else if(pie == 7) {
                player_inv->bulbasaur += 1;
        }
        else if(pie == 8) {
                player_inv->treecko += 1;
        }

}

/****************************************************************
 * Function: hint_message
 * Description: prints a message if player is close
 * Parameters: x and y - the players location
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ***************************************************************/
void Location::hint_message(int x, int y) {

        if(y+1 < size)
                loc[y+1][x].event->hint();
        if(x-1 >= 0)
                loc[y][x-1].event->hint();
        if(y-1 >= 0)
                loc[y-1][x].event->hint();
        if(x+1 < size)
                loc[y][x+1].event->hint();

}

/****************************************************************
 * Function: out_of_bounds
 * Description: checks to see if user goes out of bounds
 * Parameters: x and y - the players location
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: true or false depending if user is out of bounds
 * ***************************************************************/
bool Location::out_of_bounds(int x, int y) {

        if(x < 0 || x >= size) {
                cout << string(50, '\n');
                cout << "There's a time and a place for everything, but not now" << endl;
                return false;
        }
        else if(y < 0 || y >= size) {
                cout << string(50, '\n');
                cout << "There's a time and a place for everything, but not now" << endl;
                return false;
        }
        else{
                return true;
        }

}

/****************************************************************
 * Function: check_end
 * Description: see if player is back to prof and has all lvl 2
 * Parameters: x and y - players location
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: true or false if player has won or not
 * ***************************************************************/
bool Location::check_end(int x, int y) {

        if(x == prof_x && y == prof_y) {
                if(player_inv->charizard >= 1 && player_inv->blaziken >= 1 &&
                                player_inv->blastoise >= 1 && player_inv->swampert >= 1 &&
                                player_inv->venusaur >= 1 && player_inv->sceptile >= 1) {
                        return false;
                }
        }
        return true;

}

/****************************************************************
 * Function: remove_grid
 * Description: removes the grid if player wants to play with 
 *              a new grid
 * Parameters: none
 * Pre-Conditions: created grid
 * Post-Conditions: deleted grid
 * Return: none
 * ***************************************************************/
void Location::remove_grid() {

        for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                        if(loc[i][j].event != NULL)  {
                                loc[i][j].event->destroy();
                        }
                }
                delete [] loc[i];
        }
        delete [] loc;

}

/****************************************************************
 * Function: Location
 * Description: operator overload for copy function
 * Parameters: other - whats copied to location
 * Pre-Conditions: already made location class
 * Post-Conditions: a copied version of the location passed
 * Return: none
 * ***************************************************************/
Location::Location(const Location &other) {

        if(other.size == 0) {
                size = 0;
                loc = NULL;
                saved_loc = NULL;
                map = NULL;
                event = NULL;
                poke = NULL;
                fire = NULL;
                water = NULL;
                grass = NULL;
                cave = NULL;
                pc = NULL;
                nothing = NULL;
                prof_x = 0;
                prof_y = 0;

                player_inv = NULL;

        }
        else {
                size= other.size;

                loc = new Location *[size];
                saved_loc = new Location *[size];
                map = new char *[size];
                for(int i=0; i<size; i++) {
                        loc[i] = new Location [size];
                        saved_loc[i] = new Location [size];
                        map[i] = new char [size];
                }

                for(int i=0; i<size; i++) {
                        for(int j=0; j<size; j++) {
                                loc[i][j] = other.loc[i][j];
                                saved_loc[i][j] = other.saved_loc[i][j];
                                map[i][j] = other.map[i][j];
                        }
                }
                //event = NULL;
                prof_x = other.prof_x;
                prof_y = other.prof_y;
        }

}

/****************************************************************
 * Function: Location
 * Description: operator overload for copy function
 * Parameters: other - whats copied to location
 * Pre-Conditions: already made location class
 * Post-Conditions: a copied version of the location passed
 * Return: none
 * ***************************************************************/
void Location::operator=(const Location &other) {

        if(size > 0) {
                size=0;
                for(int i=0; i<size; i++) {
                        delete [] loc[i];
                        delete [] saved_loc[i];
                        delete [] map[i];
                }
                delete [] loc;
                delete [] saved_loc;
                delete [] map;
                loc=NULL;
                saved_loc=NULL;
                map=NULL;
                delete event;
                event=NULL;
                prof_x=0;
                prof_y=0;
                delete pc;
        }
        else {
                size= other.size;

                loc = new Location *[size];
                saved_loc = new Location *[size];
                map = new char *[size];
                for(int i=0; i<size; i++) {
                        loc[i] = new Location [size];
                        saved_loc[i] = new Location [size];
                        map[i] = new char [size];
                }

                for(int i=0; i<size; i++) {
                        for(int j=0; j<size; j++) {
                                loc[i][j] = other.loc[i][j];
                                saved_loc[i][j] = other.saved_loc[i][j];
                                map[i][j] = other.map[i][j];
                                loc[i][j].event = other.loc[i][j].event;
                                loc[i][j].poke = other.loc[i][j].poke;
                                loc[i][j].cave = other.loc[i][j].cave;
                                loc[i][j].pc = other.loc[i][j].pc;
                        }
                }
                prof_x = other.prof_x;
                prof_y = other.prof_y;
                player_inv = new struct pokemon_trainer;
                player_inv = other.player_inv;
        }



}

/****************************************************************
 * Function: ~Location
 * Description: destructor for location class
 * Parameters: none
 * Pre-Conditions: created location class
 * Post-Conditions: deleted locaiton class
 * Return: none
 * ***************************************************************/
Location::~Location() {
        for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++)  {
                        if(loc[i][j].nothing == NULL) {
                                if(loc[i][j].cave != NULL) {
                                        delete loc[i][j].cave;
                                        loc[i][j].cave = NULL;
                                }
                                else if(loc[i][j].pc != NULL) {
                                        delete loc[i][j].pc;
                                        loc[i][j].pc = NULL;
                                }
                                else if(loc[i][j].fire != NULL) {
                                        delete loc[i][j].fire;
                                        loc[i][j].fire = NULL;
                                }
                                else if(loc[i][j].water != NULL) {
                                        delete loc[i][j].water;
                                        loc[i][j].water = NULL;
                                }
                                else{
                                        delete loc[i][j].grass;
                                        loc[i][j].grass = NULL;
                                }
                        }
                        else {
                                delete loc[i][j].nothing;
                                loc[i][j].nothing = NULL;
                        }
                }
        }
        delete player_inv;
        player_inv = NULL;
        for(int i=0; i<size; i++) {
                delete [] loc[i];
        }
        delete [] loc;
        size=0;
        loc=NULL;
        event=NULL;
        prof_x=0;
        prof_y=0;

}
