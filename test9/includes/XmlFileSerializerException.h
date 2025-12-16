#ifndef XML_FILE_SERIALIZER_EXCEPTION
#define XML_FILE_SERIALIZER_EXCEPTION

#include <cstring>
#include <iostream>

#include "Exception.h"

using namespace std;
using namespace carconfig;


class XmlFileSerializerException : public Exception
{
    private: 
        int code;
    public:
        XmlFileSerializerException();
        XmlFileSerializerException(string m, int c);
        XmlFileSerializerException(const XmlFileSerializerException& e);
        ~XmlFileSerializerException();

        int getCode() const;
        void setCode(int c);

        static const int NOT_ALLOWED;
        static const int FILE_NOT_FOUND;
        static const int END_OF_FILE;
};

#endif