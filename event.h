#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "./struct.h"

class Event {
        
    public:
        virtual int grant_gift();
        virtual void hint();
        virtual void destroy();
        virtual void print_event();
        virtual bool prof_good();

};

#endif
