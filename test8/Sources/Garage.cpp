#include "Garage.h"


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
    