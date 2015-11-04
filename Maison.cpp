#include <ctime>
#include <cstdio>
#include <iostream>
#include "Maison.h"
#include "Routeur.h"
#include "Meteo.h"

using namespace std;
// TP5 A COMPLETER

Maison::~Maison()
{

}

void Maison::mettreAJour(Observable* arg)
{
	string nom = arg->obtenirNomClasse();
	if (nom == typeid(Cellulaire).name())
	{
		Cellulaire *cell = (Cellulaire*)arg;
		Personne *proprio = cell->getProprietaire();
		if (cell->estProche(position_) && !proprio->estALaMaison())
		{
			
		}
		else if (!cell->estProche(position_) && proprio->estALaMaison())
		{
		
		}
	}
	else if (nom == typeid(Meteo).name())
	{
		Meteo *meteo = (Meteo*)arg;
		
	}
}



string Maison::getAdresse() const
{
	return adresse_;
}


void Maison::setAdresse(string adresse)
{
	adresse_ = adresse;
}

float Maison::getPosition() const
{
	return position_;
}

void Maison::setPosition(float position)
{
	position_ = position;
}