#ifndef CAR
#define CAR

#include <cstring>
#include <iostream>

#include "Model.h"
#include "Option.h"

using namespace std;

class Car
{
    private:
        string projectName;
        Model model;
        Option* option[5];
        int numOption;
        

    public:
        Car();
        Car(string n, const Model& m);
        Car(const Car& c);
        ~Car();

        void setName(string N);
        void setModel(const Model& m);
        void setnumOption(int n);

        string getName() const;
        Model getModel() const;
        float getPrice() const;//////////
        int getnumOption() const;

        void display() const;//////////
        void addOption(const Option& option);//////////
        void removeOption(const string code);//////////

};

#endif