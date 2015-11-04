#ifndef CELLULAIRE_H
#define CELLULAIRE_H

#include <string>
#include "Personne.h"
#include "ObjetConnecte.h"
#include "gps.h"
#include "Observable.h"
using namespace std;

class Cellulaire : public ObjetConnecte, public Observable
{
public:
	Cellulaire(unsigned int id);
	Cellulaire(unsigned int id, string numero);
	~Cellulaire();
	void recevoirMessage(Message* message); // recevoirMessage prend un pointeur en parametre
	string obtenirNomClasse() const;

	// TP1
	bool estProche(float position);
	string getNumero() const;
	void setNumero(string numero);
	Personne* getProprietaire() const;
	void setProprietaire(Personne* personne);
	float getPosition() const;
	void setPosition(float position);

private:
	string numero_;
	Personne* proprietaire_;
	GPS gps_;
};

#endif