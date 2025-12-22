#include "Car.h"

namespace carconfig {

    Car::Car()
    {
        //cout << "appel du constructeur par défaut de Car" << endl;
        for(int i = 0; i<5; i++) option[i] = nullptr;
        setnumOption(0);
        setName("Default");


    }

    Car::Car(string n, const Model& m)
    {
        //cout << "appel du constructeur d'initialisation de Car" << endl;

        for(int i = 0; i<5; i++) option[i] = nullptr;

        setName(n);
        
        setModel(m);

        setnumOption(0);


    }

    Car::Car(const Car& c)
    {
        //cout << "appel constructeur de copie de Car" << endl;
        
        for(int i = 0; i<5; i++) option[i] = nullptr;

        setName(c.getName());

        setModel(c.getModel());

        setnumOption(c.getnumOption());

        for (int i =0; i<getnumOption(); i++)
        {
            if(c.option[i] != nullptr)
                option[i] = new Option(*c.option[i]);
        }

    }

    Car::~Car()
    {
        //cout << "début et fin du destructeur de Car" << endl;

        
        for(int i = 0; i<5; i++) delete option[i];
        setnumOption(0);
    }

    void Car::setName(string N)
    {
        projectName = N;
    }

    void Car::setModel(const Model& m)
    {
        model.setName(m.getName());
        model.setPower(m.getPower());
        model.setEngine(m.getEngine());
        model.setBasePrice(m.getBasePrice());
        model.setImage(m.getImage());

    }

    void Car::setnumOption(int n)
    {
        numOption = n;
    }

    string Car::getName() const
    {
        return projectName;
    }

    Model Car::getModel() const
    {
        return model;
    }

    float Car::getPrice() const
    {
        float OptionsPrice = 0;
        for (int i=0; i<numOption; i++)
        {
            if(option[i] != nullptr) OptionsPrice += option[i]->getPrice();
        }
        return model.getBasePrice() + OptionsPrice;
    }

    int Car::getnumOption() const
    {
        return numOption;
    }


    void Car::display() const
    {
        cout << "projet : "<< projectName << endl;
        model.display();
        for(int i=0; i<getnumOption(); i++) option[i]->display();
    }

    void Car::addOption(const Option& option)
    {  
        for(int i= 0; i<getnumOption(); i++)
        {
            if(this->option[i]->getCode() == option.getCode()) throw OptionException("option déjà présente");
        }
        if(getnumOption() < 5)
        {
            this->option[getnumOption()] = new Option(option);
            setnumOption(getnumOption()+1);
        }
        else throw OptionException("nombre d'option max");
    }

    void Car::removeOption(const string code)
    {
        for (int i=0; i<getnumOption(); i++)
        {
            if(option[i] != nullptr && option[i]->getCode() == code)
            {
                delete option[i];

                for (int j=i; j<getnumOption() -1; j++)
                    option[j] = option[j+1];
                option[getnumOption() - 1] = nullptr;
                setnumOption(getnumOption()-1);
                cout << "Option " << code << " supprimée" << endl;
                cout << "Option " << code << " non trouvée" << endl;
                return;
            }
        }
        throw OptionException("l'option à supprimer n'est pas présente");
    }

    Car& Car::operator=(const Car& c)
    {
        if (this == &c) return *this;
        for(int i=0;i<5; i++) 
        {
            delete option[i];
            option[i] = nullptr;
        }
        setName(c.getName());
        setModel(c.getModel());
        setnumOption(0);

        for(int i=0; i<c.getnumOption() && i < 5; i++)
        {
            if(c.option[i] != nullptr) addOption(*(c.option[i]));
        }

        return *this;
    }

    Car Car::operator+(const Option& o) const
    {
        Car tmp(*this);
        tmp.addOption(o);
        return tmp;
    }

    Car operator+(const Option& o,const Car& c)
    {
        return c + o;
    }

    Car Car::operator-(const Option& o)
    {
        removeOption(o.getCode());
        return *this;
    }

    Car Car::operator-(const string& s)
    {
        Car tmp(*this);
        tmp.removeOption(s);
        return tmp;
    }

    bool Car::operator<(const Car& c) const
    {
        if(this->getPrice()<c.getPrice()) return true;
        return false;
    } 

    bool Car::operator>(const Car& c) const
    {
        if(this->getPrice()>c.getPrice()) return true;
        return false;
    }

    bool Car::operator==(const Car& c) const
    {
        if(this->getPrice()==c.getPrice()) return true;
        return false;
    }

    ostream& operator<<(ostream& s, const Car& c)
    {
        s << "<Car>" << endl;
        s << "<name>" << endl;
        s << c.getName() << endl;
        s << "</name>" << endl;
        s << "<model>" << endl;
        s << c.getModel() << endl;
        s << "</model>" << endl;
        s << "<options>" << endl;

        int i = 0;
        while(c.option[i] != nullptr && i < 5)
        {
            s << *c.option[i];
            i++;
        }
        s << "</options>" << endl;
        s << "</Car>" << endl;
        return s;
    }

    istream& operator>>(istream& s, Car& c)
    {
        // Remise à zéro avant de charger
        for(int i = 0; i < 5; i++)
        {
            delete c.option[i];
            c.option[i] = nullptr;
        }
        c.setnumOption(0);

        string NameTmp, numptmp, tag, ligne;
        getline(s, tag);
        getline(s, tag);
        getline(s, NameTmp);
        getline(s, tag);
        getline(s, tag);
        s >> c.model;
        getline(s, tag);
        getline(s, tag);

        int i = 0;
        while(i < 5)
        {
            streampos pos = s.tellg();
            if(!getline(s, ligne)) break;
            if(ligne == "</options>")
            {
                cout << "il n'y a plus d'option </options>" << endl;
                break;
            }
            if(ligne == "<Option>")
            {
                s.seekg(pos);
                Option tmp;
                s >> tmp;
                c.addOption(tmp);
                i++;
            }
            
        }
        getline(s, tag);

        c.setName(NameTmp);
        
        return s;

    }


    Option* Car::operator[](int i)
    {
        return this->option[i];
    }

    void Car::save()
    {
        string nom = getName() + ".xml";
        cout << nom;
        ofstream fichier(nom, ios::out);
        if (!fichier)
        {
            cerr << "Erreur : impossible de créer le fichier " << nom << endl;
            return;
        }
        fichier << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        fichier << *this;
    }

    void Car::load(string projectName)
    {
        projectName = projectName + ".xml";
        string tag;
        ifstream fichier(projectName, ios::in);
        if(!fichier.is_open())
        {
            cerr << "Erreur : impossible d'ouvrir le fichier " << projectName << endl;
            return;
        }
        getline(fichier, tag);
        Car tmp;
        fichier >> tmp;
        *this = tmp;
    }
} // end of carconfig
