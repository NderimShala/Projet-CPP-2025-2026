#include "Car.h"

int numOption = 0;

Car::Car()
{
    cout << "appel du constructeur par défaut de Car" << endl;
    for(int i = 0; i<5; i++) option[i] = nullptr;
    setName("Default");


}

Car::Car(string n, const Model& m)
{
    cout << "appel du constructeur d'initialisation de Car" << endl;

    for(int i = 0; i<5; i++) option[i] = nullptr;

    setName(n);
    
    setModel(m);


}

Car::Car(const Car& c)
{
    cout << "appel constructeur de copie de Car" << endl;
    
    for(int i = 0; i<5; i++) option[i] = nullptr;

    setName(c.getName());

    setModel(c.getModel());

}

Car::~Car()
{
    cout << "début et fin du destructeur de Car" << endl;

    
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


void Car::display() const
{
    cout << "projet : "<< projectName << endl;
    model.display();
    for(int i=0; i<numOption; i++) option[i]->display();
}

void Car::addOption(const Option& option)
{  
    if(numOption < 5)
    {
        this->option[numOption] = new Option(option);
        numOption++;
    }
    else cout << "nombre d'option max" << endl;
}

void Car::removeOption(const string code)
{
    for (int i=0; i<5; i++)
    {
        if(option[i] != nullptr && option[i]->getCode() == code)
        {
            delete option[i];
            option[i] = nullptr;
            if (numOption > 0) numOption--;
            cout << "Option " << code << " supprimée" << endl;
            return;
        }
    }
    cout << "Option " << code << " non trouvée" << endl;
}
