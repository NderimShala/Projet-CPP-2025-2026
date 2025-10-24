#include "../Headers/Option.h"
namespace carconfig
{
    Option::Option()
    {
        //cout << "appel du constructeur par défaut" << endl;

        setCode("default");
        setLabel("default");
        setPrice(0);

        //cout << "fin du constructeur par défaut" << endl;
    }

    Option::Option(string c, string l, float p)
    {
        //cout << "appel du constructeur d'initialisation" << endl;

        setCode(c);
        setLabel(l);
        setPrice(p);


        //cout << "fin constructeur d'initialisation" << endl;
    }

    Option::Option(const Option& o)
    {
        //cout << "debut du constructeur de copie" << endl;

        setCode(o.getCode());
        setLabel(o.getLabel());
        setPrice(o.getPrice());

        //cout << "fin du constructeur de copie" << endl;
    }

    Option::~Option()
    {
        //cout << "appel destructeur de Option" << endl;
    }

    void Option::setCode(string c)
    {
        code = c;
    }

    void Option::setLabel(string l)
    {
        label = l;
    }

    void Option::setPrice(float p)
    {
        price = p;
    }

    string Option::getCode() const
    {
        return code;
    }

    string Option::getLabel() const
    {
        return label;
    }

    float Option::getPrice() const
    {
        return price;
    }

    void Option::display() const
    {
        cout << "code : " << code << endl << "label : " << label << endl << "prix : " << price << endl;
    }

    istream& operator>>(istream& s, Option& o)
    {
        string tmpc, tmpl;
        float tmpp;
        cout<<"Entrez code : " << endl;
        cin>>tmpc;
        cout<<"Entrez label : " << endl;
        cin>>tmpl;
        cout<<"Entrez prix : " << endl;
        cin>> tmpp;
        o.setCode(tmpc);
        o.setLabel(tmpl);
        o.setPrice(tmpp);

        return s;
    }

    ostream& operator<<(ostream& s,const Option& o)
    {   
        cout<<"Code : " << o.getCode() << endl << "Label : " << o.getLabel() << endl << "Prix : " << o.getPrice() << endl;
        return s;
    }
}