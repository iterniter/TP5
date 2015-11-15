#ifndef METEO_H
#define METEO_H

#include "Observable.h"
#include <map>

using namespace std;

class Meteo : public Observable
{
public:
	Meteo(); // Constructeur par defaut

// TP5 A COMPLETER
	void ajouterVille(string nomVille, float tempVille, float ventVille); // Ajoute la ville pass�e en param�tre � mapTempVent_
	bool enleverVille(string nomVille); // Retire la ville pass�e en param�tre � mapTempVent_
	pair<float, float> getTempVent(string nomVille) const; // Getter
	void setTempVent(string nomVille, float tempVille, float ventVille); // Setter
	string obtenirNomClasse() const; // obtenirNomClasse qui h�rite de la classe m�re
	friend ostream& operator<<(ostream& os, const Meteo& meteo); // Surcharge de l'op�rateur <<
	friend ostream& operator<<(ostream& os, Meteo* meteo); // Surcharge de l'op�rateur <<

private:
	//Attribut
	map<string, pair<float, float>> mapTempVent_;
};
#endif