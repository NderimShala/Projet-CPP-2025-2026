#ifndef CREDENTIALS
#define CREDENTIALS

#include <iostream>
#include <string>

using namespace std;

struct Credentials
{
    char login[20];
    char password[20];

    void crypt();
    void decrypt();
};

#endif