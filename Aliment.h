#ifndef ALIMENT_H
#define ALIMENT_H

#include <string>
#include <iostream>

#include "enumTypes.h"
using namespace std;

class Aliment
{
public:
	Aliment(string nomAliment,TYPE_GUSTATIF saveur); // Constructeur par parametres
	~Aliment(); // Destructeur

	//Accesseurs
	string getNomAliment() const;
	TYPE_GUSTATIF getSaveur() const;

	//Surcharge d'operateurs
	bool operator==(const TYPE_GUSTATIF& saveur) const;
	friend ostream& operator<<(ostream& os, const Aliment& aliment);
	friend ostream& operator<<(ostream& os, Aliment * aliment);

private:
	//Attributs
	string nomAliment_;
	TYPE_GUSTATIF saveur_;

};

#endif