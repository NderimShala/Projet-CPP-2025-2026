#include "Employee.h"

Employee::Employee(): Actor()
{
    setLogin("Default");
    resetPassword();
    setRole("Default");

}

Employee::Employee(string nom, string prenom, int id, string log, string role)
{
    setLastName(nom);
    setFirstName(prenom);
    setId(id);
    setLogin(login);
    setRole(role);
    resetPassword();
}

Employee::Employee(const Employee& e)
{
    setLastName(e.getLastName());
    setFirstName(e.getFirstName());
    setId(e.getId());
    setLogin(e.getLogin());
    setPassword(e.getPassword());
    setRole(e.getRole());
}

Employee::~Employee()
{
    if(password != nullptr) delete password;
}

void Employee::setLogin(string l)
{
    login = l;
}

void Employee::setPassword(string mdp)
{
    if (password != nullptr) delete password;
    password = new string(mdp);
}

string Employee::getLogin() const
{
    return login;
}

const string Employee::getPassword() const
{
    return *password;
}

void Employee::resetPassword()
{
    password = nullptr;
}

void Employee::setRole(string r)
{
    role = r;
}

string Employee::getRole() const
{
    return role;
}

string Employee::toString() const
{
    string s = "Merde";
    if(getRole() == "Vendeur") s = "[v" + to_string(id) + "]" + " " + getLastName() + getFirstName();
    else if(getRole() == "Administratif") s = "[a" + to_string(id) + "]" + " " + getLastName() + getFirstName();

    return s;
}

string Employee::tuple() const
{
    string s = getId()+";"+getLastName()+";"+getFirstName()+":"+getRole();
    return s;
}

Employee& Employee::operator=(const Employee& e)
{
    setLastName(e.getLastName());
    setFirstName(e.getFirstName());
    setId(e.getId());
    setLogin(e.getLogin());
    setPassword(e.getPassword());
    setRole(e.getRole());

    return *this;
}