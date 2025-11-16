#include "Employee.h"
#include "PasswordException.h"

Employee::Employee(): Actor()
{
    setLogin("Default");
    resetPassword();

}

Employee::Employee(string nom, string prenom, int id, string log, string r)
{
    setLastName(nom);
    setFirstName(prenom);
    setId(id);
    setLogin(login);
    setRole(r);
    resetPassword();
}

Employee::Employee(const Employee& e)
{
    setLastName(e.getLastName());
    setFirstName(e.getFirstName());
    setId(e.getId());
    setLogin(e.getLogin());
    setRole(e.getRole());
    setPassword(e.getPassword());

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
    if(mdp.length()<6) throw PasswordException(1);
    int testd = 0;
    int testa = 0;
    for(char c : mdp)
    {
        if(isalpha(c) == 1) testa = 1;
        if(isdigit(c) == 1) testd = 1;
    }
    if (testa == 0) throw PasswordException(2);
    if (testd == 0) throw PasswordException(3);

    
    password = new string(mdp);
}

string Employee::getLogin() const
{
    return login;
}

const string Employee::getPassword() const
{
    if(password == nullptr) throw PasswordException(4);
    return *password;
}

void Employee::resetPassword()
{
    password = nullptr;
}


string Employee::toString() const
{
    string s = "Merde";
    if(getRole() == "Vendeur") s = "[v" + to_string(getId()) + "]" + " " + getLastName() + " " + getFirstName();
    else if(getRole() == "Administratif") s = "[a" + to_string(getId()) + "]" + " " + getLastName() + " "  +getFirstName();

    return s;
}

string Employee::tuple() const
{
    string s = to_string(getId())+";"+getLastName()+";"+getFirstName()+";"+getRole();
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

const string Employee::ADMINISTRATIVE = "Administratif";
const string Employee::SELLER = "Vendeur";

void Employee::setRole(string r)
{
    if(r == Employee::ADMINISTRATIVE) role = Employee::ADMINISTRATIVE;
    if(r == Employee::SELLER) role = Employee::SELLER;
}

string Employee::getRole() const
{
    return role;
}

ostream& operator<<(ostream& s, const Employee& p)
{
    cout << p.getLastName() << endl << p.getFirstName() << endl << p.getRole();

    return s;
}