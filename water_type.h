#ifndef WATER_TYPE_H
#define WATER_TYPE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "./pokemon.h"

class Water_type : public Pokemon {

    public:
        Water_type();

        bool capture();
        int grant_gift();
        void print_event();
        
};

#endif
