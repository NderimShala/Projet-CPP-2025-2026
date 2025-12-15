
#warning "Compilation de XmlFileSerializer.ipp"




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
        file << "<" << cn << ">\n";
    }
    else if(mode == READ)
    {
        file.open(fn, ios::in);
        if(!file.is_open()) throw XmlFileSerializerException("FILE_NOT_FOUND", XmlFileSerializerException::FILE_NOT_FOUND);
        string Balise, collection, entete;
        getline(file, entete); //entête XML
        getline(file, Balise);
        size_t start = Balise.find('<');
        size_t end = Balise.find('>');
        collectionName = Balise.substr(start+1, end - start - 1);
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
    file << val << "\n";
}


template <typename T>
T XmlFileSerializer<T>::read() {
    if (mode != READ) {
        throw XmlFileSerializerException("Fichier non ouvert en mode lecture.", XmlFileSerializerException::NOT_ALLOWED);
    }
    
    // Sauvegarder la position actuelle
    streampos pos = file.tellg();
    
    // Lire une ligne pour vérifier si c'est la balise de fin
    string ligne;
    file >> ligne;
    
    // Vérifier si c'est la balise de fermeture de la collection
    string closingTag = "</" + collectionName + ">";
    if (ligne == closingTag) {
        throw XmlFileSerializerException("Fin de fichier atteinte.", XmlFileSerializerException::END_OF_FILE);
    }
    
    // Faire marche arrière - revenir à la position avant la lecture
    file.seekg(pos);
    
    // Lire l'objet normalement
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
