#include "ObjetConnecte.h"
#include "Routeur.h"

using namespace std;

// Nouveau au TP5 :

/****************************************************************************
* Fonction:	ObjetConnecte::envoyerMessage
* Description: Envoie le message passé en parametre au routeur, à condition que cet objet soit connecte au routeur
* Parametres:	- (Message*) message
* Retour:		aucun
****************************************************************************/
void ObjetConnecte::envoyerMessage(Message *message)
{
	if (estConnecte_)
	{
		routeur_->acheminerMessage(message);
	}
}

// Avant TP5 :

ObjetConnecte::ObjetConnecte(unsigned int id) : id_(id), estConnecte_(false)
{
}

unsigned int ObjetConnecte::getId() const
{
	return id_;
}

bool ObjetConnecte::seConnecter(Routeur* routeur)
{
	if (!estConnecte_)
	{
		routeur->accepterConnexion(this);
		routeur_ = routeur;
		estConnecte_ = true;
		return true;
	}
	return false;
}

void ObjetConnecte::seDeconnecter()
{
	if (estConnecte_)
	{
		routeur_->retirerConnexion(id_);
		routeur_ = NULL;
		estConnecte_ = false;
	}
}



void ObjetConnecte::setIsConnected(bool value)
{
	estConnecte_ = value;
}

bool ObjetConnecte::isConnected() const
{
	return estConnecte_;
}