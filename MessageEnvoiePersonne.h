#ifndef MESSAGEENVOIEPERSONNE_H
#define MESSAGEENVOIEPERSONNE_H

#include <string>
#include <iostream>
#include "enumTypes.h"
#include "Message.h"
#include "Personne.h"

using namespace std;

class MessageEnvoiePersonne : public Message
{
public:
	MessageEnvoiePersonne(unsigned int src, unsigned int dest, TYPE_MESSAGE type, Personne* personne); // Constructeur par paramètres
	Personne* getPersonne() const; // Getter
	void setPersonne(Personne* personne); // Setter
	string obtenirNomClasse() const; // Renvoie un string contenant le nom de la classe

private:
	//Attributs
	Personne* personne_;
};

#endif