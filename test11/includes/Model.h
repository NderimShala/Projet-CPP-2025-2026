#ifndef MODEL_H
#define MODEL_H

enum Engine { Petrol, Diesel, Electric, Hybrid };

#include <cstring>
#include <iostream>
using namespace std;

namespace carconfig
{
	class Model
	{
	private:
		char* name;
		int power;
		Engine engine;
		float basePrice;
		string image;

	public:
		Model(); // constructeur par défaut
		Model(const char* n, int p, Engine e, float bp, string img); // constructeur d'initialisation
		Model(const Model& mod); // constructeur de copie

		~Model();

		void setPower(int p);
		int getPower() const;

		void setName(const char* n);
		const char* getName() const;

		void setEngine(Engine e);
		Engine getEngine() const;

		void setBasePrice(float bp);
		float getBasePrice() const;

		void setImage(string img);
		string getImage() const;

		void display() const;

		friend istream& operator>>(istream& s, Model& o);
        friend ostream& operator<<(ostream& s,const Model& o);

		string engineToString(Engine e) const;
		string toString() const;
	};	
}


#endif