#ifndef CLIENT
#define CLIENT

#include <cstring>
#include <string>
#include <iostream>

#include "Actor.h"

using namespace std;

class Client : public Actor
{
    private :
        string GSM;
    
    public:
        Client();
        Client(string nom, string prenom, int id, string num);
        Client(const Client& c);
        ~Client();

        void setGsm(string num);
        string getGsm() const;

        string toString() const override;
        string tuple() const override;

        Client& operator=(const Client& c);

        friend ostream& operator<<(ostream& s, const Client& c);
        friend istream& operator>>(istream& s, Client& c);
};

#endif