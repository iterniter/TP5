#include "MessageEnvoiePersonne.h"

/****************************************************************************
* Fonction:	MessageEnvoiePersonne::MessageEnvoiePersonne
* Description: Constructeur par paramètres
* Parametres:   - (unsigned int) src : ID source
				- (unsigned int) dest : ID destinataire
				- (TYPE_MESSAGE) type : type message
				- (Personne*) personne
* Retour:		aucun
****************************************************************************/
MessageEnvoiePersonne::MessageEnvoiePersonne(unsigned int src, unsigned int dest, TYPE_MESSAGE type, Personne* personne) : Message(src, dest, type), personne_(personne)
{
}

/****************************************************************************
* Fonction:	MessageEnvoiePersonne::getPersonne
* Description: Getter
* Parametres:   aucun
* Retour:		- (Personne*)
****************************************************************************/
Personne* MessageEnvoiePersonne::getPersonne() const
{
	return personne_;
}

/****************************************************************************
* Fonction:	MessageEnvoiePersonne::setPersonne
* Description: Setter
* Parametres:   - (Personne*) personne
* Retour:		aucun
****************************************************************************/
void MessageEnvoiePersonne::setPersonne(Personne* personne)
{
	personne_ = personne;
}

/****************************************************************************
* Fonction:	MessageEnvoiePersonne::obtenirNomClasse
* Description: Renvoie le nom de la classe
* Parametres:   aucun
* Retour:		- (string)
****************************************************************************/
string MessageEnvoiePersonne::obtenirNomClasse() const
{
	return typeid(MessageEnvoiePersonne).name();
}