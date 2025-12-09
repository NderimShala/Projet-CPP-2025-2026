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
        if(getCode() != "default" and getCode() != "") throw OptionException("option déjà existante donc non modifiable");
        else if(c.length() != 4 and c != "default") throw OptionException("Mauvais code d'option");
        code = c;
    }

    void Option::setLabel(string l)
    {
        if(getLabel() != "default" and getLabel() != "") throw OptionException("option déjà existante donc non modifiable");
        else if(l.empty()) throw OptionException("l'option doit avoir un intitulé");
        label = l;
    }

    void Option::setPrice(float p)
    {
        if(p < 0) throw OptionException("une option ne peut avoir de prix négatif");
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
        string tmpc, tmpl, tmpp, tag;
        getline(s, tag); // <Option>
        getline(s, tag); // <code>
        getline(s, tmpc);
        getline(s, tag); // </code>
        getline(s, tag); // <label>
        getline(s, tmpl); 
        getline(s, tag); // </label>
        getline(s, tag); // <price>
        getline(s, tmpp);
        getline(s, tag); // </price>
        getline(s, tag); // </option>

        o.setCode(tmpc);
        o.setLabel(tmpl);
        o.setPrice(stof(tmpp));
        return s;
    }

    ostream& operator<<(ostream& s,const Option& o)
    {   
        s << "<Option>" << endl;
        s << "<code>" << endl;
        s << o.getCode() << endl;
        s << "</code>" << endl;
        s << "<label>" << endl;
        s << o.getLabel() << endl;
        s << "</label>" << endl;
        s << "<price>" << endl;
        s << o.getPrice() << endl;
        s << "</price>" << endl;
        s << "</Option>" << endl;
        return s;
    }

    Option Option::operator--()
    {
        if(this->price >= 50) this->price = this->price - 50;
        else throw OptionException("une option ne peut avoir de prix négatif");
        return (*this);
    }

    Option Option::operator--(int)
    {
        Option temp(*this);
        if(this->price >= 50) this->price = this->price - 50;
        else throw OptionException("une option ne peut avoir de prix négatif");
        return temp;
    }

}

