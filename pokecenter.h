#ifndef POKECENTER_H
#define POKECENTER_H

#include <iostream>
#include "./event.h"

using namespace std;

class Pokecenter : public Event {

    public:
        int grant_gift();
        void hint();
        void print_event();
        bool prof_good();

};

#endif
