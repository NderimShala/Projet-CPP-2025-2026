#include "Car.h"

Car::Car()
{
    cout << "appel du constructeur par défaut de Car" << endl;

    setName("Default");


}

Car::Car(string n, const Model& m)
{
    cout << "appel du constructeur d'initialisation de Car" << endl;

    setName(n);
    
    setModel(m);


}

Car::Car(const Car& c)
{
    cout << "appel constructeur de copie de Car" << endl;

    setName(c.getName());

    setModel(c.getModel());

}

Car::~Car()
{
    cout << "début et fin du destructeur de Car" << endl;
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


void Car::display() const
{
    cout << "projet : "<< projectName << endl;
    model.display();
}
