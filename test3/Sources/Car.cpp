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
        if(getnumOption() < 5)
        {
            this->option[getnumOption()] = new Option(option);
            setnumOption(getnumOption()+1);
        }
        else cout << "nombre d'option max" << endl;
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
                return;
            }
        }
        cout << "Option " << code << " non trouvée" << endl;
    }

    Car& Car::operator=(const Car& c)
    {
        setnumOption(0);
        setName(c.getName());
        setModel(c.getModel());
        for(int i=0;i<5; i++) 
        {
            delete option[i];
            option[i] = nullptr;
        }

        for(int i=0; i<c.getnumOption(); i++)
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
        c.display();
        return s;
    }
} // end of carconfig
