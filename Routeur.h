#ifndef ROUTEUR_H
#define ROUTEUR_H

#include <vector>
#include "Cellulaire.h"
#include "Chauffage.h"
#include "Maison.h"
#include "Message.h"

class Routeur
{
public:
	// TP5 A COMPLETER!
	Routeur();
	void accepterConnexion(ObjetConnecte* obj) {};
	bool retirerConnexion(unsigned int id) { return true; };
	void acheminerMessage(Message* message) const {};

private:
	
};

#endif