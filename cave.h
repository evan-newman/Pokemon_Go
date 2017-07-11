#ifndef CAVE_H
#define CAVE_H

#include <iostream>
#include "./event.h"

class Cave : public Event {

    public:
        //Cave();

        int grant_gift();
        void hint();
        void print_event();
        bool prof_good();

};

#endif
