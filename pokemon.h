#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "./event.h"

using namespace std;

class Pokemon : public Event {

    protected:
        string name;
        int type;

    public:
        Pokemon();

        void hint();
        virtual int grant_gift();
        virtual void print_event();
        bool prof_good();

};

#endif
