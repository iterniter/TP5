#ifndef FRIGO_H
#define FRIGO_H

#include <string>
#include <iostream>
#include <list>
#include "enumTypes.h"
#include "ObjetConnecte.h"
#include <algorithm>
#include "MemeAliment.h"
#include <functional>
#include "RestrictionAlimentaire.h"
#include "Message.h"
#include "MessageEnvoiePersonne.h"

using namespace std;

template<typename T, typename R>

class Frigo : public ObjetConnecte
{
public:
	Frigo(); // Constructeur par d�faut
	Frigo(unsigned int id); // Constructeur par parametre
	void ajouterContenu(T* nouveau); // Ajoute l'�l�ment pass� en param�tre dans listeContenu_
	void recevoirMessage(Message* message); // Va sugg�rer un menu � la personne du message
	bool retirerContenu(MemeAliment element); // Retire un �l�ment de listeContenu_ en fonction du foncteur unaire pass� en param�tre
	void suggererMenu(R restrictionAlim); // Affiche une liste d'aliments en respectant ses restrictions alimentaires de la personne pass�e en param�tre
	void suggererMenu2(R restrictionAlim1, R restrictionAlim2); // Affiche une liste d'aliments en respectant les restrictions alimentaires des personnes pass�es en param�tre

private:
	//Attributs
	List<T*> listeContenu_;
};

#endif

/****************************************************************************
* Fonction:	Frigo<T*>::Frigo
* Description: Constructeur par d�faut
* Parametres:   aucun
* Retour:		aucun
****************************************************************************/
template<typename T>
Frigo<T*>::Frigo()
{}

/****************************************************************************
* Fonction:	Frigo<T*>::Frigo
* Description: Constructeur par param�tre
* Parametres:   - (unsigned int) id : ID du frigo intelligent
* Retour:		aucun
****************************************************************************/
template<typename T>
Frigo<T*>::Frigo(unsigned int id) : ObjetConnecte(id)
{}

/****************************************************************************
* Fonction:	Frigo<T*>::ajouterContenu
* Description: Ajoute l'�l�ment pass� en param�tre dans listeContenu_
* Parametres:   - (const T&) nouveau : nouvel �l�ment � ajouter
* Retour:		aucun
****************************************************************************/
template<typename T>
void Frigo<T*>::ajouterContenu(T* nouveau)
{
	listeContenu_.push_back(nouveau);
}

/****************************************************************************
* Fonction:	Frigo<T*>::retirerContenu
* Description: Retire l'�l�ment pass� en param�tre de listeContenu_
* Parametres:   - (MemeAliment) element : element � retirer (ou pas)
* Retour:		- (bool) retireElement : si l element passe en parametre a �t� retire ou pas
****************************************************************************/
template<typename T>
bool Frigo<T*>::retirerContenu(MemeAliment element)
{
	bool retireElement = false;
	for (list<T*>::iterator it = listeContenu_.begin(); it != listeContenu_.end(); it++)
	{
		if (element(*it))
		{
			if (it != listeContenu_.end())
			{
				listeContenu_.erase(it);
				retireElement = true;
				cout << "L'aliment " << element.getNomAliment() << " a �t� retir�." << end;
			}
		}
	}

	if(!retireElement)
		cout << "L'aliment " << element->getName() << " n'a pas �t� trouv�." << end;

	return retireElement;
}

/****************************************************************************
* Fonction:	Frigo<T*>::suggererMenu
* Description: Affiche une liste d'aliments en respectant la restriction alimentaire pass�e en param�tre
* Parametres:   - (R) restrictionAlim : pr�dicat unaire g�n�rique
* Retour:		aucun
****************************************************************************/
template<typename T, typename R>
void Frigo<T*>::suggererMenu(R restrictionAlim)
{
	cout << "Le menu sugg�r� est :" << endl;
	copy_if(listeContenu_.begin(), listeContenu_.end(), ostream_iterator<T>(cout, "\n"), restrictionAlim());
}

/****************************************************************************
* Fonction:	Frigo<T*>::suggererMenu2
* Description: Affiche une liste d'aliments en respectant les restrictions alimentaires pass�es en param�tre
* Parametres:   - (R) restrictionAlim1 : pr�dicat unaire g�n�rique
				- (R) restrictionAlim2 : pr�dicat unaire g�n�rique
* Retour:		aucun
****************************************************************************/
template<typename T, typename R>
void Frigo<T*>::suggererMenu2(R restrictionAlim1, R restrictionAlim1)
{
	cout << "Le menu sugg�r� est :" << endl;
	copy_if(listeContenu_.begin(), listeContenu_.end(), ostream_iterator<T>(cout, "\n"), bind(logical_and<bool>(), restrictionAlim1(), restrictionAlim1()));
}

/****************************************************************************
* Fonction:	Frigo<T*>::recevoirMessage
* Description: Va sugg�rer un menu � la personne du message
* Parametres:   - (Message*) message
* Retour:		aucun
****************************************************************************/
template<typename T>
void Frigo<T*>::recevoirMessage(Message* message)
{
	if (message->getType() == NOTIFICATION_VISITEUR && message->obtenirNomClasse() == "MessageEnvoieMessage")) // Utiliser obtenirNomClasse ?
	{
		RestrictionAlimentaire restrictionAlim(message->getPersonne());
		suggererMenu(restrictionAlim);
	}
	else
	{
		cout << "else de Frigo<T*>::recevoirMessage" << endl;
	}
}


