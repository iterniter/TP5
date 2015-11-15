//
//  maison.h
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//  Modified by Dominique Beaini on 2015-09-18.
//  Modified by Karim Keddam on 2015-09-26.
//

#ifndef MAISON_H
#define MAISON_H


#include <string>
#include "Personne.h"
#include "ObjetConnecte.h"
#include "Cellulaire.h"
#include "Observateur.h"
#include <list>

using namespace std;

class Maison : public ObjetConnecte, public Observateur
{
public:
	// Méthodes TP4
	void mettreAJour(Observable*);

	// Methodes TP5 A COMPLETER
	Maison(unsigned int id, string adresse = "Rue des 3 mages", float position = 0.0, int tempExt = 15, int tempAGarder = 20, string nomVille = "Montreal"); // Constructeur par paramètres
	string getNomVille() const; //Getter
	void setNomVille(string nomVille); //Setter
	void trierListeNomPersonne(); // const ?
	void trierListeAge(); // const ?

	// Méthodes TP2:
	~Maison();

	void ajouterOccupant(Personne* personne);

	// cette fonction permet de savoir si une personne, passee en parametre, fait partie des occupants de la maison.
	bool estOccupant(const Personne* personne) const;

	// cette fonction permet de savoir si la maison est vide, c'est-à-dire si aucun occupant n'est present dans la maison.
	bool estVide() const;

	// Méthodes TP1:
	// accesseurs et modificateurs
	string getAdresse() const;
	void setAdresse(string adresse);

	float getPosition() const;
	void setPosition(float position);

private:
	// Attributs TP5 A COMPLETER
	string nomVille_;
	list<Personne*> personnes_;

	//TP4
	int temperatureExterieure_;
	int temperatureAGarder_;

	// TP1 et TP2
	string adresse_;
	
	// position de la maison. La maison est positionnee simplement selon un chiffre.
	float position_;
};

#endif