#ifndef XML_FILE_SERIALIZER_H
#define XML_FILE_SERIALIZER_H

#include <iostream>
#include <fstream>
#include <sstream> // pour isstringstream dans read()
#include "XmlFileSerializerException.h"
using namespace std;

template<typename T>
class XmlFileSerializer
{
    private:
        fstream file;
        string filename;
        char mode;
        string collectionName;

    public:
        XmlFileSerializer() = delete;
        XmlFileSerializer(const string& fn, char m, const string& cn = "entities");
        XmlFileSerializer(const XmlFileSerializer& fs) = delete;
        ~XmlFileSerializer();

        string getFilename() const;
        string getCollectionName() const;

        XmlFileSerializer<T>& operator=(const XmlFileSerializer<T>&) = delete;

        void write(const T& val);
        T read();

        static const char READ;
        static const char WRITE;

        bool isReadable() const;
        bool isWritable() const;
};

#include "XmlFileSerializer.ipp"
#endif