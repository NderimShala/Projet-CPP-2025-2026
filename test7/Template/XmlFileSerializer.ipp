



template<typename T>
const char XmlFileSerializer<T>::WRITE = 'W';

template<typename T>
const char XmlFileSerializer<T>::READ = 'R';

template<typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, char m, const string& cn)
{
    filename = fn;
    mode = m;
    collectionName = cn;
    if(mode == WRITE)
    {
        file.open(fn, ios::out | ios::trunc); // out = Ecriture trunc = efface si le fichier existe 
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<" << cn << ">\n" << endl;
    }
    else if(mode == READ)
    {
        file.open(fn, ios::in);
        if(!file.is_open()) throw XmlFileSerializerException("FILE_NOT_FOUND", XmlFileSerializerException::FILE_NOT_FOUND);
        string Balise, collection;
        getline(file, Balise);
        getline(file, collection);
    }
}

template<typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
    if(mode == WRITE) file << "</" << collectionName << ">\n" << endl;

    file.close();
}

template<typename T>
string XmlFileSerializer<T>::getFilename() const
{
    return filename;
}

template<typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
    return collectionName;
}

template<typename T>
void XmlFileSerializer<T>::write(const T& val)
{
    if(isWritable() == false) throw XmlFileSerializerException("NOT_ALLOWED", XmlFileSerializerException::NOT_ALLOWED);
    file << val;
}

template<typename T>
T XmlFileSerializer<T>::read()
{
    if(isReadable() == false) throw XmlFileSerializerException("NOT_ALLOWED", XmlFileSerializerException::NOT_ALLOWED);
    string ligne;
    streampos pos = file.tellg();
    getline(file, ligne);
    if(ligne == "</" + collectionName + ">") throw XmlFileSerializerException("END_OF_FILE", XmlFileSerializerException::END_OF_FILE);
    else 
    {
        file.clear();
        file.seekg(pos);
    }

    T val;
    file >> val;
    return val;
}

template<typename T>
bool XmlFileSerializer<T>::isReadable() const 
{
    if(mode == READ) return 1;
    else return 0;
}


template<typename T>
bool XmlFileSerializer<T>::isWritable() const 
{
    if(mode == WRITE) return 1;
    else return 0;
}
