#include "Routeur.h"
#include <iostream>

// TP5 A COMPLETER

/****************************************************************************
* Fonction:	Routeur::Routeur
* Description: Constructeur par défaut
* Parametres:   aucun
* Retour:		aucun
****************************************************************************/
Routeur::Routeur()
{
}

/****************************************************************************
* Fonction:	Routeur::accepterConnexion
* Description:  Ajoute l’objet, dont on vient d’accepter la connexion, au routeur
* Parametres:   - (ObjetConnecte*) obj
* Retour:		aucun
****************************************************************************/
void Routeur::accepterConnexion(ObjetConnecte* obj)
{
	mapObjetConnecte_.insert(pair<unsigned int, ObjetConnecte*>(obj->getId(), obj));
}

/****************************************************************************
* Fonction:	Routeur::retirerConnexion
* Description:  Retire du routeur l’objet connecté dont l’id correspond à celui reçu par paramètre
* Parametres:   - (unsigned int) id
* Retour:		- (bool) connexionRetiree
****************************************************************************/
bool Routeur::retirerConnexion(unsigned int id)
{
	bool connexionRetiree = false;
	map<unsigned int, ObjetConnecte*>::iterator it;
	it = mapObjetConnecte_.find(id);
	if (it != mapObjetConnecte_.end())
	{
		mapObjetConnecte_.erase(it);
		connexionRetiree = true;
	}
	
	return connexionRetiree;
}

/****************************************************************************
* Fonction:	Routeur::acheminerMessage
* Description:  Achemine le message passé en paramètre vers le bon objet connecte.
* Parametres:   - (Message*) message
* Retour:		aucun
****************************************************************************/
void Routeur::acheminerMessage(Message* message) const
{
	cout << "Routeur : Acheminement d un message de " << message->getSrc() << " vers " << message->getDest() << endl;
	bool idTrouvee = false;

	if (message->getDest() == 0)
	{
		for (map<unsigned int, ObjetConnecte*>::const_iterator it = mapObjetConnecte_.begin(); it != mapObjetConnecte_.end(); it++)
			it->second->recevoirMessage(message);
		idTrouvee = true;
	}
	else
	{
		mapObjetConnecte_.find(message->getDest())->second->recevoirMessage(message);
		idTrouvee = true;
	}

	if (!idTrouvee)
		cout << "Id non trouvee, rien ne se passe !" << endl;
}