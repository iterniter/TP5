#ifndef OBJETCONNECTE_H
#define OBJETCONNECTE_H

#include <string>
#include "Message.h"

class Routeur;
class ObjetConnecte
{
public:
	ObjetConnecte(unsigned int id);
	bool seConnecter(Routeur* routeur);
	void seDeconnecter();
	void envoyerMessage(Message* message); // envoyerMessage prend un pointeur en parametre
	virtual void recevoirMessage(Message* message) = 0; // recevoirMessage prend un pointeur en parametre

	unsigned int getId() const;
	bool isConnected() const;

	void setIsConnected(bool value);

protected:
	unsigned int id_;
	Routeur *routeur_;
	bool estConnecte_;
};
#endif