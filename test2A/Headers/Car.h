#ifndef CAR
#define CAR

#include <cstring>
#include <iostream>

#include "Model.h"

using namespace std;

class Car
{
    private:
        string projectName;
        Model model;

    public:
        Car();
        Car(string n, const Model& m);
        Car(const Car& c);
        ~Car();

        void setName(string N);
        void setModel(const Model& m);

        string getName() const;
        Model getModel() const;

        void display() const;

};

#endif