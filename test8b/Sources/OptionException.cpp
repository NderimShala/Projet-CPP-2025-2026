#include "OptionException.h"
namespace carconfig
{
    OptionException::OptionException()
    {
        setMessage("message par défaut de OptionException");
    }

    OptionException::OptionException(string m)
    {
        setMessage(m);
    }

    OptionException::OptionException(const OptionException& o)
    {
        setMessage(o.getMessage());
    }

    OptionException::~OptionException() {}

    
}
