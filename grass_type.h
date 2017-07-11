#ifndef GRASS_TYPE_H
#define GRASS_TYPE_H

#include <string>
#include <cstdlib>
#include <ctime>
#include "./pokemon.h"

class Grass_type : public Pokemon {

    public:
        Grass_type();

        bool capture();
        int grant_gift();
        void print_event();

};

#endif
