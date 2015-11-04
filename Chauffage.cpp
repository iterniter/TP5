#include "Chauffage.h"
#include "Routeur.h"

using namespace std;

// Nouveau au TP5 :

/****************************************************************************
* Fonction:	Chauffage::recevoirMessage
* Description: Permet l'affichage d'un message reçu : Utilise polymorphisme de la classe Message
* Parametres:	- (Message*) message
* Retour:		aucun
****************************************************************************/
void Chauffage::recevoirMessage(Message* message)
{
	if ((message->getType() == ALLUMAGE_AUTOMATIQUE && automatique_ && !allume_))
	{
		cout << "Chauffage# " << id_ << ". Allume." << endl;
		allume_ = true;
	}
	else if (message->getType() == ALLUMER_CHAUFFAGE && !allume_)
	{
		cout << "Chauffage# " << id_ << ". Allume." << endl;
		allume_ = true;
	}
	else if (message->getType() == ETTEINDRE_CHAUFFAGE && allume_)
	{
		cout << "Chauffage# " << id_ << ". Etteint." << endl;
		allume_ = false;
	}
}

// Avant TP5 :

Chauffage::Chauffage(unsigned int id) : ObjetConnecte(id)
{
}

Chauffage::~Chauffage()
{
}

bool Chauffage::estAutomatique() const
{
	return automatique_;
}

void Chauffage::setAutomatique(bool value)
{
	automatique_ = value;
}