#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <list>

#include "enumTypes.h"
#include <string>

using namespace std;

class Personne
{
public:
	// TP5 A COMPLETER
	Personne(string nom, string prenom, unsigned int age, TYPE_GUSTATIF preferenceGout); // Constructeur par parametres

	// Getter & Setter de preferenceGout_
	TYPE_GUSTATIF getPreferenceGout() const;
	void setPreferenceGout(TYPE_GUSTATIF nouvellePreference);

	bool verifierAllergies(const string& allergie); // Vérifie si l'allergie passée en paramètre fait partie de listeAllergies_
	void ajouterAllergies(const string& allergie); // Ajoute allergie à listeAllergies_ s'il n'y est pas déjà

	//friend bool operator<(const string& nom, const string& nom2);

	// TP2
	bool operator==(const Personne& personne) const;
	bool operator< (const Personne& personne) const;
	friend ostream& operator<<(ostream& o, const Personne& personne);

	// TP1
	Personne();
	~Personne();

	string getNom() const;
	void setNom(string nom);

	string getPrenom() const;
	void setPrenom(string prenom);

	unsigned int getAge() const;
	void setAge(unsigned int age);

	string getNumeroCellulaire() const;
	void setNumeroCellulaire(string nouveauNum);

	bool estALaMaison() const;
	void setEstALaMaison(bool estmaison);

	void attribuerCellulaire(std::string numeroCellulaire);

private:
	// Attributs
	string nom_;
	string prenom_;
	string numeroCellulaire_;

	unsigned int age_;
	bool estALaMaison_;

	list<string> listeAllergies_;
	TYPE_GUSTATIF preferenceGout_;
};


#endif