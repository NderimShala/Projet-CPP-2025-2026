#include "Client.h"

Client::Client() : Actor()
{
    setGsm("NULL");
}

Client::Client(string nom, string prenom, int id, string num)
{
    setLastName(nom), setFirstName(prenom), setId(id), setGsm(num);
}

Client::Client(const Client& c)
{
    setId(c.getId());
    setLastName(c.getLastName());
    setFirstName(c.getFirstName());
    setGsm(c.getGsm());
}
Client::~Client()
{
    
}

void Client::setGsm(string num)
{
    GSM = num;
}

string Client::getGsm() const
{
    return GSM;
}

string Client::toString() const
{
    string s;
    s = "[C" + to_string(id) + "]" + " " + getLastName() + " " + getFirstName();
    return s;
}

string Client::tuple() const
{
    string s;
    s = to_string(id) + ";" + getLastName() + ";"  + getFirstName() + ";" + getGsm();

    return s;
}

Client& Client::operator=(const Client& c)
{
    setId(c.getId());
    setLastName(c.getLastName());
    setFirstName(c.getFirstName());
    setGsm(c.getGsm());

    return *this;
}