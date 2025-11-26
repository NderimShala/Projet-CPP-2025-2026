#ifndef PASSWORDEXCEPTION
#define PASSWORDEXCEPTION

#include <cstring>
#include <iostream>

#include "Exception.h"

using namespace std;
using namespace carconfig;

class PasswordException : public Exception
{
    private:
        int code;
    public:

        PasswordException();
        PasswordException(int c);
        PasswordException(const PasswordException& p);
        ~PasswordException();

        void setPassCode(int c);
        int getPassCode() const;
};


#endif