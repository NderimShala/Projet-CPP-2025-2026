#ifndef ACTOR
#define ACTOR

#include <cstring>
#include <iostream>

#include "Person.h"

using namespace std;

class Actor : public Person
{
    protected :
        int id;
    
    public:
        Actor();
        ~Actor();

        int getId() const;
        void setId(int);

        virtual string toString() const;
        virtual string tuple() const;

        Actor& operator=(const Actor& a);

        static int currentId;
};

#endif