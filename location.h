#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "./event.h"
#include "./pokecenter.h"
#include "./pokemon.h"
#include "./struct.h"
#include "./cave.h"
#include "./fire_type.h"
#include "./water_type.h"
#include "./grass_type.h"
#include "./nothing.h"

class Location {

    private:
        int size;
        Location **loc;
        Location **saved_loc;
        char **map;
        Event *event;
        //~~~~~~~~~~~~~~~~~~~~
        Pokemon *poke;
        Fire_type *fire;
        Water_type *water;
        Grass_type *grass;
        //~~~~~~~~~~~~~~~~~~~
        Cave *cave;
        Pokecenter *pc;
        Nothing *nothing;
        int prof_x, prof_y;
        struct pokemon_trainer *player_inv;

    public:
        Location();
        
        Location(const Location &);
        void operator=(const Location &);
        ~Location();

        void create_grid();
        void populate_grid();
        void save_grid();
        void professor_loc();
        void create_map();
        void print_map(int, int);
        void remove_grid();
        void initilize_struct();
        void change_inv(int, int, int);
        void change_inv_pokemon(int);
        void evolve();

        void print_inventory();
        void grass_evolve();
        void fire_evolve();
        void water_evolve();
        void pokemon_run(int, int);
        
        void new_game(int);
        void continue_game();
        void play_game();
        void hint_message(int, int);
        bool out_of_bounds(int, int);
        bool check_end(int, int);
        void end_screen();

        void set_size(const int);
        int get_size() const;
        void set_loc(const Location **);
        Location ** get_loc() const;
        void set_saved_loc(const Location **);
        Location ** get_saved_loc() const;
        void set_map(const char **);
        char ** get_map() const;
        void set_event(const Event *);
        Event * get_event() const;
        void set_prof_x(const int);
        int get_prof_x() const;
        void set_prof_y(const int);
        int get_prof_y() const;

};

#endif
