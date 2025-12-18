#include "Garage.h"

// Définition des membres statiques (obligatoire pour l'éditeur de liens)//
Garage Garage::instance{};               // l'unique instance de Garage
carconfig::Car Garage::currentProject{}; // projet courant, constructeur par défaut


void Garage::addModel(const Model& m)
{
    models.push_back(m);
}

void Garage::displayAllModels() const
{
    for(list<Model>::const_iterator it = models.begin(); it != models.end(); it++)
    {
        cout << it->toString() << endl;
    }
}

Model Garage::getModel(int index) const
{
    list<Model>::const_iterator it = models.begin();
    advance(it, index);

    return *it;
}

void Garage::addOption(const Option& o)
{
    options.push_back(o);
}

void Garage::displayAllOptions() const
{
    for(list<Option>::const_iterator it = options.begin(); it != options.end(); it++)
    {
        cout << it->toString() << endl;
    }
}

Option Garage::getOption(int index) const
{
    list<Option>::const_iterator it = options.begin();
    advance(it, index);

    return *it;
}

int Garage::addClient(string lastName, string firstName, string gsm)
{
    int id = Actor::currentId;
    clients.insert(Client(lastName, firstName, id, gsm));
    Actor::currentId++;
    return id;
}

void Garage::displayClients() const
{
    for(set<Client>::const_iterator it = clients.cbegin(); it != clients.cend(); it++)
    {
        cout << it->toString() << endl;
    }
}

void Garage::deleteClientByIndex(int index)
{
    set<Client>::iterator it = next(clients.begin(), index);
    clients.erase(it);
}

void Garage::deleteClientById(int id)
{
    for(set<Client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if(id == it->getId())
        {
            clients.erase(it);
            break;
        }
    }
}

Client Garage::findClientByIndex(int index) const
{
    set<Client>::iterator it = clients.begin();
    advance(it, index);
    return *it;
}

Client Garage::findClientById(int id) const
{
    for(set<Client>::const_iterator it = clients.begin(); it != clients.end(); it++)
    {
        if(it->getId() == id) return *it;
    }
    throw runtime_error("Client introuvable");
}

int Garage::addEmployee(string lastName, string firstName, string login, string role)
{
    int id = Actor::currentId;
    employees.insert(Employee(lastName, firstName, id, login, role));
    Actor::currentId++;
    return id;
}
//je commence à utiliser auto qui équivaut à set/list<XXX>::iterator 
void Garage::displayEmployees() const
{
    for(auto it = employees.begin(); it != employees.end(); it++)
    {
        cout << it->toString() << endl;
    }
}

void Garage::deleteEmployeeByIndex(int index)
{
    auto it = next(employees.begin(), index);
    employees.erase(it);
}

void Garage::deleteEmployeeById(int id)
{
    for(auto it = employees.begin(); it != employees.end(); it++)
    {
        if(it->getId() == id) 
        {
            employees.erase(it); 
            break;
        }
    }
}

Employee Garage::findEmployeeByIndex(int index) const
{
    auto it = employees.begin();
    advance(it, index);
    return *it;
}

Employee Garage::findEmployeeById(int id) const
{
    for(auto it= employees.begin(); it != employees.end(); it++)
    {
        if(it->getId() == id) return *it;
    }
    throw std::runtime_error("Client introuvable");
}

Garage& Garage::getInstance()
{
    static Garage instance;
    return instance;
}

Car& Garage::getCurrentProject()
{
    return getInstance().currentProject;
}

void Garage::resetCurrentProject()
{
    getInstance().currentProject = Car();
}

void Garage::importModelsFromCsv(string filename)
{  
    ifstream fichier(filename);
    if(!fichier) 
    {
        cerr << "Erreur lors de l'ouverture du fichier " << filename << endl;
        return;
    }
    string ligne;
    int compteurModel = 0;
    getline(fichier, ligne); //en-tête
    while(getline(fichier, ligne))
    {
        compteurModel++;
        string nom, puissance, moteur, image, prixDeBase;
        istringstream iss(ligne);
        getline(iss, nom, ';');
        getline(iss, puissance, ';');
        getline(iss, moteur, ';');
        getline(iss, image, ';');
        getline(iss, prixDeBase);

        Engine e;
        if(moteur == "petrol") e = Petrol;
        else if(moteur == "diesel") e = Diesel;
        else if(moteur == "electric") e = Electric;
        else if(moteur == "hybrid") e = Hybrid;

        Model M(nom.c_str(), stoi(puissance),e ,stof(prixDeBase), image);
        addModel(M);
    }
    setNbrModelsCsv(compteurModel);
}

void Garage::importOptionsFromCsv(string filename)
{
    ifstream fichier(filename);
    if(!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier" << filename << endl;
        return;
    }
    string ligne;
    int compteurOption = 0;
    getline(fichier, ligne); //en-tête
    while(getline(fichier, ligne))
    {
        compteurOption++;
        string code, intitule, prix;
        istringstream iss(ligne);
        getline(iss, code, ';');
        getline(iss, intitule, ';');
        getline(iss, prix);

        Option o(code, intitule, stof(prix));
        addOption(o);
    }
    setNbrOptionsCsv(compteurOption);
}

void Garage::setNbrModelsCsv(int i)
{
    nombreModelsCsv = i;
}

int Garage::getNbrModelsCsv() const
{
    return nombreModelsCsv;
}

void Garage::setNbrOptionsCsv(int i)
{
    nombreOptionsCsv = i;
}

int Garage::getNbrOptionsCsv() const
{
    return nombreOptionsCsv;
}

