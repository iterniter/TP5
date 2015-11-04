#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>
#include <list>

#include "enumTypes.h"


class Personne
{
public:
// TP5 A COMPLETER
	// TP2
	bool operator==(const Personne& personne) const;
	bool operator< (const Personne& personne) const;
	friend std::ostream& operator<<(std::ostream& o, const Personne& personne);


	// TP1
	Personne();
	Personne(string nom, string prenom,unsigned int age,TYPE_GUSTATIF preferenceGout);

	~Personne();

	std::string getNom() const;
	void setNom(std::string nom);

	std::string getPrenom() const;
	void setPrenom(std::string prenom);

	unsigned int getAge() const;
	void setAge(unsigned int age);

	std::string getNumeroCellulaire() const;
	void setNumeroCellulaire(string nouveauNum);

	bool estALaMaison() const;
	void setEstALaMaison(bool estmaison);

	void attribuerCellulaire(std::string numeroCellulaire);
	
	TYPE_GUSTATIF getPreferenceGout() const;
	void setPreferenceGout(TYPE_GUSTATIF nouvellePreference);

	bool verifierAllergies(const string& allergie);
	void ajouterAllergies(const string& allergie);

	friend bool operator<(const string& nom, const string& nom2);
	

private:
	std::string nom_;
	std::string prenom_;
	std::string numeroCellulaire_;

	unsigned int age_;
	bool estALaMaison_;

	list<string> listeAllergies_;
	TYPE_GUSTATIF preferenceGout_;

};


#endif