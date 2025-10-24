#ifndef CAR
#define CAR

#include <cstring>
#include <iostream>

#include "Model.h"
#include "Option.h"

using namespace std;

namespace carconfig
{
    class Car
    {
        private:
            string projectName;
            Model model;
            Option* option[5];
            int numOption;

            void setnumOption(int n);

        public:
            Car();
            Car(string n, const Model& m);
            Car(const Car& c);
            ~Car();

            void setName(string N);
            void setModel(const Model& m);

            string getName() const;
            Model getModel() const;
            float getPrice() const;//////////
            int getnumOption() const;

            void display() const;//////////
            void addOption(const Option& option);//////////
            void removeOption(const string code);//////////

            Car& operator=(const Car& c);

            Car operator+(const Option& o) const;
            friend Car operator+(const Option& o,const Car& c);

            Car operator-(const Option& o);
            Car operator-(const string& s);

            bool operator<(const Car& c) const;
            bool operator>(const Car& c) const;
            bool operator==(const Car& c) const;



    };   
}


#endif