#ifndef NOTHING_H
#define NOTHING_H

#include "./event.h"

using namespace std;


class Nothing : public Event {

    public:
        int grant_gift();
        void hint();
        void destroy();
        void print_event();
        bool prof_good();

};

#endif
