#include "Actor.h"

int Actor::currentId = 1;

Actor::Actor() : Person()
{
    cout <<"appel du constructeur de Actor" << endl;
    setId(0);
}



Actor::~Actor()
{
    cout <<"appel du destructeur de Actor" << endl;
}

int Actor::getId() const
{
    return id;
}

void Actor::setId(int i)
{
    id = i;
}

Actor& Actor::operator=(const Actor& a)
{
    setId(a.getId());

    return *this;
}

string Actor::toString() const
{
    string s = "Actor";
    return s;
}
string Actor::tuple() const
{
    string s = "Actor";
    return s;
}
