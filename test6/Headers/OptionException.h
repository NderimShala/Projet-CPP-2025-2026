#ifndef OPTIONEXCEPTION
#define OPTIONEXCEPTION

#include <cstring>
#include <iostream>

#include "Exception.h"

using namespace std;

namespace carconfig
{
    class OptionException : public Exception
    {
        public:
            OptionException();
            OptionException(string m);
            OptionException(const OptionException& o);
            ~OptionException();
    };
}

#endif