#include "Person.h"


Person::Person()
{
    setFirstName("Default");
    setLastName("Default");
}

Person::Person(string ln, string fn)
{
    setFirstName(fn);
    setLastName(ln);
}

Person::Person(const Person& p)
{
    setFirstName(p.getFirstName());
    setLastName(p.getLastName());
}

Person::~Person(){}


void Person::setFirstName(string fn)
{
    firstName = fn;
}

void Person::setLastName(string ln)
{
    lastName = ln;
}

string Person::getFirstName() const
{
    return firstName;
}

string Person::getLastName() const
{
    return lastName;
}

Person& Person::operator=(const Person& p)
{
    setLastName(p.getLastName());
    setFirstName(p.getFirstName());

    return *this;
}

istream& operator>>(istream& s, Person& p)
{
    string fn, ln;
    cout << "Nom : " << endl;
    cin >> ln;
    cout << "Prenom : " << endl;
    cin >> fn;

    p.setFirstName(fn);
    p.setLastName(ln);

    return s;
}

ostream& operator<<(ostream& s, const Person& p)
{
    cout << "Nom : " << p.getLastName() << endl << "Prénom : " << p.getFirstName() << endl;

    return s;
}
