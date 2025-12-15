#include "Exception.h"

namespace carconfig
{
    Exception::Exception()
    {
        setMessage("Ceci est un message d'erreur par défaut");
    }

    Exception::Exception(string m)
    {
        setMessage(m);
    }

    Exception::Exception(Exception& e)
    {
        setMessage(e.getMessage());
    }

    Exception::~Exception(){}

    void Exception::setMessage(const string m)
    {
        message = m;
    }

    string Exception::getMessage() const
    {
        return message;
    }  
}
