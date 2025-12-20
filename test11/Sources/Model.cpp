#include "Model.h"

namespace carconfig
{
	Model::Model() // constructeur par défaut
	{
		name = nullptr;
		setName("default");
		setPower(80);
		setEngine(Engine::Petrol);
		setBasePrice(15000);
	}

	Model::Model(const char* n, int p, Engine e, float bp, string img) // constructeur d'initialisation
	{
		name = nullptr;
		setName(n);
		setPower(p);
		setEngine(e);
		setBasePrice(bp);
		setImage(img);
	}

	Model::Model(const Model& mod) // constructeur de copie
	{
		name = nullptr;
		setName(mod.getName());
		setPower(mod.getPower());
		setEngine(mod.getEngine());
		setBasePrice(mod.getBasePrice());
		setImage(mod.getImage());
	}

	Model::~Model()
	{
		if (name != nullptr) delete name;
	}

	void Model::setPower(int p)
	{
		if(p >= 0) power = p;
	}

	int Model::getPower() const
	{
		return power;
	}

	void Model::setName(const char* n)
	{
		if (name != nullptr) delete name;
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}

	const char* Model::getName() const
	{
		return name;
	}

	void Model::setEngine(Engine e)
	{
		engine = e;
	}

	Engine Model::getEngine() const
	{
		return engine;
	}

	void Model::setBasePrice(float bp)
	{
		basePrice = bp;
	}

	float Model::getBasePrice() const
	{
		return basePrice;
	}

	void Model::setImage(string img)
	{
		image = img;
	}

	string Model::getImage() const
	{
		return image;
	}

	void Model::display() const
	{
		cout << "Nom : " << getName() << endl;
		cout << "Puissace : " << getPower() << endl;
		cout << "Moteur : " << getEngine() << endl; // !!!
		cout << "Prix de base : " << getBasePrice() << endl;
		cout << "image : " << getImage() << endl;
	}

	istream& operator>>(istream& s, Model& o)
	{
		
		string ntmp, ptmp, m, etmp, btmp, img, tag;
		getline(s, tag);
		getline(s, tag);
		getline(s, ntmp); //nom
		getline(s, tag);
		getline(s, tag);
		getline(s, ptmp); //puissance
		getline(s, tag);
		getline(s, tag);
		getline(s, etmp); //engine
		getline(s, tag);
		getline(s, tag);
		getline(s, btmp); //prix
		getline(s, tag);
		getline(s, tag);
		getline(s, img); //image
		getline(s, tag);
		getline(s, tag);


		o.setName(ntmp.c_str());
		o.setPower(stoi(ptmp));
		o.setBasePrice(stof(btmp));
		o.setEngine(static_cast<Engine>(stoi(etmp)));
		o.setImage(img);

		return s;
		
	}

	ostream& operator<<(ostream& s,const Model& o)
	{
		s << "<Model>" << endl;
		s << "<name>" << endl;
		s << o.getName() << endl;
		s << "</name>" << endl;
		s << "<power>" << endl;
		s << o.getPower() << endl;
		s << "</power>" << endl;
		s << "<engine>" << endl;
		s << o.getEngine() << endl;
		s << "</engine>" << endl;
		s << "<basePrice>" << endl;
		s << o.getBasePrice() << endl;
		s << "</basePrice>" << endl;
		s << "<image>" << endl;
		s << o.getImage() << endl;
		s << "</image>" << endl;
		s << "</Model>";
		
		return s;
	}

	string Model::engineToString(Engine e) const
	{
		switch(e)
		{
			case Petrol: return "Petrol";
			case Diesel: return "Diesel";
			case Electric: return "Electric";
			case Hybrid: return "Hybrid";
			default: return "Faute dans engineToString";
		}
	}

	string Model::toString() const
	{
		string s;
		s = string(getName()) + " // " + to_string(getPower()) + " // " + engineToString(engine) + " // " + to_string(getBasePrice()) + " // " + getImage();

		return s;
	}

}

	