

#include "../Headers/XmlFileSerializerException.h"

const int XmlFileSerializerException::NOT_ALLOWED = 0;
const int XmlFileSerializerException::FILE_NOT_FOUND = 1;
const int XmlFileSerializerException::END_OF_FILE = 2;


XmlFileSerializerException::XmlFileSerializerException()
{
    setMessage("message par défaut de XmlFileSerializerException");
    setCode(10);
}

XmlFileSerializerException::XmlFileSerializerException(string m, int c) : Exception(m)
{
    setCode(c);
}

XmlFileSerializerException::XmlFileSerializerException(const XmlFileSerializerException& e)
{
    setMessage(e.getMessage());
    setCode(e.getCode());
}

XmlFileSerializerException::~XmlFileSerializerException() {}

int XmlFileSerializerException::getCode() const
{
    return code;
}

void XmlFileSerializerException::setCode(int c)
{
    code = c;
}