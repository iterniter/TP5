#include "Aliment.h"

#include <string>

/****************************************************************************
* Fonction: Aliment::Aliment
* Description: Constructeur par paramètres
* Parametres:  - (string) nomAliment
*              - (TYPE_GUSTATIF) saveur
* Retour:	   aucun
****************************************************************************/
Aliment::Aliment(string nomAliment, TYPE_GUSTATIF saveur) : nomAliment_(nomAliment), saveur_(saveur)
{
}

/****************************************************************************
* Fonction:	Aliment::~Aliment()
* Description: Destructeur
* Parametres:	aucun
* Retour:		aucun
****************************************************************************/
Aliment::~Aliment()
{
}

/****************************************************************************
* Fonction:	Aliment::getNomAliment
* Description: Getter
* Parametres:	aucun
* Retour:		- (string) nomAliment_
****************************************************************************/
string Aliment::getNomAliment() const
{
	return nomAliment_;
}

/****************************************************************************
* Fonction:	Aliment::getSaveur
* Description: Getter
* Parametres:	aucun
* Retour:		- (TYPE_GUSTATIF) saveur_
****************************************************************************/
TYPE_GUSTATIF Aliment::getSaveur() const
{
	return saveur_;
}

/****************************************************************************
* Fonction:	Aliment::operator==
* Description: Surcharge operator==
* Parametres:	- (const TYPE_GUSTATIF&) saveur
* Retour:		- (booleen) indiquant si la saveur courante est "==" à celle passée en parametre
****************************************************************************/
bool Aliment::operator==(const TYPE_GUSTATIF& saveur) const
{
	return (saveur_ == saveur);
}

/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (const Aliment&) aliment
				- (ostream&) os
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, const Aliment& aliment)
{
	return os << "Le nom de l'aliment est " << aliment.nomAliment_ << "." << endl;
}

/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (const Aliment*) aliment
				- (ostream&) os
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, Aliment* aliment)
{
	return os << "Le nom de l'aliment est " << aliment->nomAliment_ << "." << endl;
}
