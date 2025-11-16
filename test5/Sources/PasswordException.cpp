#include "PasswordException.h"

using namespace carconfig;


PasswordException::PasswordException()
{
    setPassCode(0);
}

PasswordException::PasswordException(int c)
{
    setPassCode(c);
}

PasswordException::PasswordException(const PasswordException& p)
{
    setPassCode(p.getPassCode());
}

PasswordException::~PasswordException(){}

void PasswordException::setPassCode(int c)
{
    if(c <=4 && c >= 0) code = c;
}

int PasswordException::getPassCode() const
{
    return code;
}