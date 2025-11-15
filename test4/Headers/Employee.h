#ifndef EMPLOYEE
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

        const static string ADMINISTRATIVE;
        const static string SELLER;

        Employee(); //
        Employee(string nom, string prenom, int id, string log, string r);
        Employee(const Employee& e);//
        ~Employee();

        void setLogin(string l); //
        string getLogin() const;//

        void setPassword(string mdp); //
        const string getPassword() const; //
        void resetPassword(); //

        void setRole(string r); //
        string getRole() const; //

        string toString() const override;//
        string tuple() const override;//

        Employee& operator=(const Employee& e);

        friend ostream& operator<<(ostream& s, const Employee& p);
        friend istream& operator>>(istream& s, Employee& p);



};

#endif