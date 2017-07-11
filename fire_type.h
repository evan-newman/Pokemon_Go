#ifndef FIRE_TYPE_H
#define FIRE_TYPE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "./pokemon.h"

class Fire_type : public Pokemon {

    public:
        Fire_type();

        bool capture();
        int grant_gift();
        void print_event();

};

#endif
