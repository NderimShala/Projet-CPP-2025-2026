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

ostream& operator<<(ostream& s, const Client& c)
{
    s << "<Client>" << endl;
    s << "<lastName>" << endl;
    s << c.getLastName() << endl;
    s << "</lastName>" << endl;
    s << "<firstName>" << endl;
    s << c.getFirstName() << endl;
    s << "</firstName>" << endl;
    s << "<id>" << endl;
    s << c.getId() << endl;
    s << "</id>" << endl;
    s << "<gsm>" << endl;
    s << c.getGsm() << endl;
    s << "</gsm>" << endl;
    s << "</Client>" << endl;
     return s;
}

istream& operator>>(istream& s, Client& c)
{
    string lastNameTmp, firstNameTmp, idTmp, GSMTmp, tag;
    getline(s, tag);
    getline(s, tag);
    getline(s, lastNameTmp);
    getline(s, tag);
    getline(s, tag);
    getline(s, firstNameTmp);
    getline(s, tag);
    getline(s, tag);
    getline(s, idTmp);
    getline(s, tag);
    getline(s, tag);
    getline(s, GSMTmp);
    getline(s, tag);
    getline(s, tag);

    c.setFirstName(firstNameTmp);
    c.setLastName(lastNameTmp);
    c.setId(stoi(idTmp));
    c.setGsm(GSMTmp);

    return s;
}