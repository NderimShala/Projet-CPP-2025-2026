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

	Model::Model(const char* n, int p, Engine e, float bp) // constructeur d'initialisation
	{
		name = nullptr;
		setName(n);
		setPower(p);
		setEngine(e);
		setBasePrice(bp);
	}

	Model::Model(const Model& mod) // constructeur de copie
	{
		name = nullptr;
		setName(mod.getName());
		setPower(mod.getPower());
		setEngine(mod.getEngine());
		setBasePrice(mod.getBasePrice());
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

	void Model::display() const
	{
		cout << "Nom : " << name << endl;
		cout << "Puissace : " << power << endl;
		cout << "Moteur : " << engine << endl; // !!!
		cout << "Prix de base : " << basePrice << endl;
	}

	istream& operator>>(istream& s, Model& o)
	{
		string ntmp;
		int ptmp, m;
		Engine etmp;
		float btmp;
		cout << "Nom du model : " << endl;
		cin >> ntmp;
		cout << "Puissance en Ch : " << endl;
		cin >> ptmp;
		cout << "Motorisation (1 = Petrol, 2 = Diesel, 3 = Elec, 4 = Hybrid): " << endl;
		cin >> m;
		if(m == 1) etmp = Petrol;
		else if(m == 2) etmp = Diesel;
		else if(m == 3) etmp = Electric;
		else if(m == 4) etmp = Hybrid;
		cout << "Prix : " << endl;
		cin >> btmp;

		const char* nom = ntmp.c_str();

		o.setName(nom);
		o.setPower(ptmp);
		o.setEngine(etmp);
		o.setBasePrice(btmp);

		
		return s;
		
	}

	ostream& operator<<(ostream& s,const Model& o)
	{
		cout << " Nom du model : " << o.getName() << endl << "Puissance : " << o.getPower() << endl << "Motorisation : " << o.getEngine() << endl << "Prix : " << o.getBasePrice() << endl;
		
		return s;
	}

}

	