#include <ctime>
#include <cstdio>
#include <iostream>
#include "Maison.h"
#include "Routeur.h"
#include "Meteo.h"

using namespace std;
// TP5 A COMPLETER
/****************************************************************************
* Fonction: Maison::Maison
* Description: Constructeur par paramètres
* Parametres:  - (unsigned int) id
*              - (string) adresse
*              - (float) position
*              - (int) tempExt
*              - (int) tempAGarder
*              - (string) nomVille
* Retour:	   aucun
****************************************************************************/
Maison::Maison(unsigned int id, string adresse, float position, int tempExt, int tempAGarder, string nomVille) : ObjetConnecte(id), adresse_(adresse), position_(position), temperatureExterieure_(tempExt), temperatureAGarder_(tempAGarder), nomVille_(nomVille)
{
}

/****************************************************************************
* Fonction: Maison::getNomVille
* Description: Getter
* Parametres:  aucun
* Retour:	   - (string) nomVille
****************************************************************************/
string Maison::getNomVille() const
{
	return nomVille_;
}

/****************************************************************************
* Fonction: Maison::setNomVille
* Description: Setter
* Parametres:  - (string) nomVille
* Retour:	   aucun
****************************************************************************/
void  Maison::setNomVille(string nomVille)
{
	nomVille_ = nomVille;
}

void trierListeNomPersonne(); // const ?
void trierListeAge(); // const ?
void ajouterOccupant(Personne* personne);
// cette fonction permet de savoir si une personne, passee en parametre, fait partie des occupants de la maison.
bool estOccupant(const Personne* personne) const;
// cette fonction permet de savoir si la maison est vide, c'est-à-dire si aucun occupant n'est present dans la maison.
bool estVide() const;

// Méthodes à modifier :

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

// Méthodes avant le TP5, à ne pas modifier

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