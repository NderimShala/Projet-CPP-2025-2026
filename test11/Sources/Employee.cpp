#include "Employee.h"
#include "PasswordException.h"

Employee::Employee(): Actor(), password(nullptr)
{
    setLogin("Default");
}

Employee::Employee(string nom, string prenom, int id, string log, string r) : password(nullptr)
{
    setLastName(nom);
    setFirstName(prenom);
    setId(id);
    setLogin(log);
    setRole(r);
}

Employee::Employee(const Employee& e) : password(nullptr)
{
    setLastName(e.getLastName());
    setFirstName(e.getFirstName());
    setId(e.getId());
    setLogin(e.getLogin());
    setRole(e.getRole());
    // Copier le password seulement s'il existe dans 'e'
    if (e.password != nullptr) {
        // Utilise setPassword pour la validation et l'allocation correcte
        setPassword(*e.password);
    } else {
        password = nullptr;
    }
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
    // Validation
    if(mdp.length()<6) throw PasswordException(1, "INVALID_LENGTH");
    int testb = 0;
    int testa = 0;
    for(char c : mdp)
    {
        if(isalpha(static_cast<unsigned char>(c))) testa = 1;
        if(isdigit(static_cast<unsigned char>(c))) testb = 1;
    }
    if (testa == 0) throw PasswordException(2, "ALPHA_MISSING");
    if (testb == 0) throw PasswordException(3, "DIGIT_MISSING");

    // Supprimer l'ancien mot de passe s'il existe pour éviter les fuites
    if (password != nullptr) {
        delete password;
        password = nullptr;
    }

    password = new string(mdp);
}

string Employee::getLogin() const
{
    return login;
}

const string Employee::getPassword() const
{
    if(password == nullptr) throw PasswordException(4, "NO_PASSWORD");
    return *password;
}

void Employee::resetPassword()
{
    // Supprimer la mémoire et mettre à nullptr
    if (password != nullptr) {
        delete password;
    }
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
    if (this == &e) return *this;

    setLastName(e.getLastName());
    setFirstName(e.getFirstName());
    setId(e.getId());
    setLogin(e.getLogin());
    setRole(e.getRole());

    // Copier le password seulement s'il existe ; sinon réinitialiser
    if (e.password != nullptr) {
        setPassword(*e.password);
    } else {
        resetPassword();
    }

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