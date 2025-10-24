#ifndef OPTION
#define OPTION

#include <cstring>
#include <iostream>

using namespace std;

namespace carconfig
{
    class Option
    {
        private:
            string code;
            string label;
            float price;

        public:
            Option();
            Option(string c, string l, float p);
            Option(const Option& o);
            ~Option();

            void setCode(string c);
            void setLabel(string l);
            void setPrice(float p);

            string getCode() const;
            string getLabel() const;
            float getPrice() const;

            void display() const;

            friend istream& operator>>(istream& s, Option& o);
            friend ostream& operator<<(ostream& s,const Option& o);
    };   
}


#endif