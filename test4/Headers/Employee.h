/*#ifndef EMPLOYEE
#define EMPLOYEE

#include <cstring>
#include <iostream>

#include "Actor.h"

using namespace std;


class Employee : public Actor
{
    private:
        string login;
        string *password;
        string role;

    public:
        Employee();
        Employee(string nom, string prenom, )

        void setLogin(string);
        string getLogin() const;

        void setPassword(string mdp);
        const string* getPassword() const; 


};

#endif*/