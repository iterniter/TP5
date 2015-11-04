/*
Fichier: message.cpp
Auteur(s): Karim Keddam
Date de creation: 25 septembre 2015
Date de modification: 02 octobre 2015
Description: Cette classe represente un message permettant de communiquer entre deux objets de type ObjetConnecte.
*/

#include "Message.h"

using namespace std;

// Nouveau au TP5 :

/****************************************************************************
* Fonction:	Message::obtenirNomClasse
* Description: Retourne un string contenant le nom de la classe
* Parametres:	aucun
* Retour:		- (string) nom de la classe
****************************************************************************/
string Message::obtenirNomClasse() const
{
	return typeid(Message).name();
}

// Avant TP5 :

Message::Message(unsigned int src, unsigned int dest, TYPE_MESSAGE type)
	:idSrc_(src), idDest_(dest), type_(type)
{
}

Message::~Message()
{
}

unsigned int Message::getSrc() const
{
	return idSrc_;
}

unsigned int Message::getDest() const
{
	return idDest_;
}

TYPE_MESSAGE Message::getType() const
{
	return type_;
}