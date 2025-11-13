#include "Actor.h"


Actor::Actor() : Person()
{
    setId(0);
}



Actor::~Actor()
{

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
