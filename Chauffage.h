#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include "ObjetConnecte.h"

class Chauffage : public ObjetConnecte
{
public:
	Chauffage(unsigned int id);
	~Chauffage();
	void recevoirMessage(Message* message); // recevoirMessage prend un pointeur en parametre
	bool estAutomatique() const;
	void setAutomatique(bool value);

private:
	bool automatique_;
	bool allume_;
};

#endif