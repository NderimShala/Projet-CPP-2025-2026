#ifndef PERSON
#define PERSON

#include <cstring>
#include <iostream>

using namespace std;

class Person
{
    protected:
        string lastName;
        string firstName;

    public:
        Person();
        Person(string ln, string fn);
        Person(const Person& p);
        ~Person();

        void setLastName(string ln);
        void setFirstName(string fn);

        string getFirstName() const;
        string getLastName() const;

        Person& operator=(const Person& p);

        friend ostream& operator<<(ostream& s, const Person& p);
        friend istream& operator>>(istream& s, Person& p);

};


#endif