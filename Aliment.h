#ifndef ALIMENT_H
#define ALIMENT_H

#include <iostream>
#include <string>

#include "enumTypes.h"





class Aliment
{
public:
	
	Aliment(string nomAliment,TYPE_GUSTATIF saveur);
	~Aliment();

	string getNomAliment();
	TYPE_GUSTATIF getSaveur();

	bool operator==(const TYPE_GUSTATIF& saveur) const;
	friend ostream& operator<<(ostream& os, const Aliment& aliment);
	friend ostream& operator<<(ostream& os, Aliment * aliment);

private:
	string nomAliment_;
	TYPE_GUSTATIF saveur_;

};

#endif