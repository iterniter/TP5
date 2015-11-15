#include "Meteo.h"

using namespace std;

Meteo::Meteo()
{
}

// TP5 A COMPLETER

/****************************************************************************
* Fonction:	Meteo::ajouterVille
* Description:  Ajoute la ville passée en paramètre à mapTempVent_
* Parametres:   - (string) nomVille
				- (float) tempVille
				- (float) ventVille
* Retour:		aucun
****************************************************************************/
void Meteo::ajouterVille(string nomVille, float tempVille, float ventVille)
{
	mapTempVent_.insert(make_pair(nomVille,make_pair(tempVille, ventVille)));
}

/****************************************************************************
* Fonction:	Meteo::enleverVille
* Description:  Retire la ville passée en paramètre à mapTempVent_
* Parametres:   - (string) nomVille
* Retour:		- (bool) villeRetiree
****************************************************************************/
bool Meteo::enleverVille(string nomVille)
{
	bool villeRetiree = false;
	map<string, pair<float, float >> ::iterator it;
	it = mapTempVent_.find(nomVille);
	if (it != mapTempVent_.end())
	{
		mapTempVent_.erase(it);
		villeRetiree = true;
	}
	return villeRetiree;
}

/****************************************************************************
* Fonction:	Meteo::getTempVent
* Description:  Getter
* Parametres:   - (string) nomVille
* Retour:		- (pair<float, float>) tempVille et ventVille
****************************************************************************/
pair<float, float> Meteo::getTempVent(string nomVille) const
{
	map<string, pair<float, float >>::const_iterator it = mapTempVent_.find(nomVille);
	if (it != mapTempVent_.end())
	{
		return it->second;
	}
	pair<float, float> pair_null(0.0,0.0);
	return pair_null;
}

/****************************************************************************
* Fonction:	Meteo::setTempVent
* Description:  Setter
* Parametres:   - (string) nomVille
				- (float) tempVille
				- (float) ventVille
* Retour:		aucun
****************************************************************************/
void Meteo::setTempVent(string nomVille, float tempVille, float ventVille)
{
	map<string, pair<float, float >>::iterator it = mapTempVent_.find(nomVille); // utile pour vérifier que la ville est déjà dans mapTempVent_
	if (it != mapTempVent_.end())
	{
		pair<float, float> my_pair(tempVille, ventVille);
		mapTempVent_[nomVille] = my_pair;
	}
}

/****************************************************************************
* Fonction:	Meteo::obtenirNomClasse
* Description:  obtenirNomClasse qui hérite de la classe mère
* Parametres:   aucun
* Retour:		- (string) Meteo
****************************************************************************/
string Meteo::obtenirNomClasse() const
{
	return typeid(Meteo).name();
}

/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (ostream&) os
				- (const Meteo&) meteo
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, const Meteo& meteo)
{
	for (map<string, pair<float, float>>::const_iterator it = meteo.mapTempVent_.begin(); it != meteo.mapTempVent_.end(); it++)
	{
		os << "- " << it->first << "\t" << it->second.first << "°C" << "\t" << it->second.second << "km/h" << endl;
	}
	return os;
}

/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (ostream&) os
				- (Meteo*) meteo
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, Meteo* meteo)
{
	for (map<string, pair<float, float>>::const_iterator it = meteo->mapTempVent_.begin(); it != meteo->mapTempVent_.end(); it++)
	{
		os << "- " << it->first << "\t" << it->second.first << "°C" << "\t" << it->second.second << "km/h" << endl;
	}
	return os;
}