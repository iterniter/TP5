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
	Frigo(); // Constructeur par défaut
	Frigo(unsigned int id); // Constructeur par parametre
	void ajouterContenu(T* nouveau); // Ajoute l'élément passé en paramètre dans listeContenu_
	void recevoirMessage(Message* message); // Va suggérer un menu à la personne du message
	bool retirerContenu(MemeAliment element); // Retire un élément de listeContenu_ en fonction du foncteur unaire passé en paramètre
	void suggererMenu(R restrictionAlim); // Affiche une liste d'aliments en respectant ses restrictions alimentaires de la personne passée en paramètre
	void suggererMenu2(R restrictionAlim1, R restrictionAlim2); // Affiche une liste d'aliments en respectant les restrictions alimentaires des personnes passées en paramètre

private:
	//Attributs
	List<T*> listeContenu_;
};

#endif

/****************************************************************************
* Fonction:	Frigo<T*>::Frigo
* Description: Constructeur par défaut
* Parametres:   aucun
* Retour:		aucun
****************************************************************************/
template<typename T>
Frigo<T*>::Frigo()
{}

/****************************************************************************
* Fonction:	Frigo<T*>::Frigo
* Description: Constructeur par paramètre
* Parametres:   - (unsigned int) id : ID du frigo intelligent
* Retour:		aucun
****************************************************************************/
template<typename T>
Frigo<T*>::Frigo(unsigned int id) : ObjetConnecte(id)
{}

/****************************************************************************
* Fonction:	Frigo<T*>::ajouterContenu
* Description: Ajoute l'élément passé en paramètre dans listeContenu_
* Parametres:   - (const T&) nouveau : nouvel élément à ajouter
* Retour:		aucun
****************************************************************************/
template<typename T>
void Frigo<T*>::ajouterContenu(T* nouveau)
{
	listeContenu_.push_back(nouveau);
}

/****************************************************************************
* Fonction:	Frigo<T*>::retirerContenu
* Description: Retire l'élément passé en paramètre de listeContenu_
* Parametres:   - (MemeAliment) element : element à retirer (ou pas)
* Retour:		- (bool) retireElement : si l element passe en parametre a été retire ou pas
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
				cout << "L'aliment " << element.getNomAliment() << " a été retiré." << end;
			}
		}
	}

	if(!retireElement)
		cout << "L'aliment " << element->getName() << " n'a pas été trouvé." << end;

	return retireElement;
}

/****************************************************************************
* Fonction:	Frigo<T*>::suggererMenu
* Description: Affiche une liste d'aliments en respectant la restriction alimentaire passée en paramètre
* Parametres:   - (R) restrictionAlim : prédicat unaire générique
* Retour:		aucun
****************************************************************************/
template<typename T, typename R>
void Frigo<T*>::suggererMenu(R restrictionAlim)
{
	cout << "Le menu suggéré est :" << endl;
	copy_if(listeContenu_.begin(), listeContenu_.end(), ostream_iterator<T>(cout, "\n"), restrictionAlim());
}

/****************************************************************************
* Fonction:	Frigo<T*>::suggererMenu2
* Description: Affiche une liste d'aliments en respectant les restrictions alimentaires passées en paramètre
* Parametres:   - (R) restrictionAlim1 : prédicat unaire générique
				- (R) restrictionAlim2 : prédicat unaire générique
* Retour:		aucun
****************************************************************************/
template<typename T, typename R>
void Frigo<T*>::suggererMenu2(R restrictionAlim1, R restrictionAlim1)
{
	cout << "Le menu suggéré est :" << endl;
	copy_if(listeContenu_.begin(), listeContenu_.end(), ostream_iterator<T>(cout, "\n"), bind(logical_and<bool>(), restrictionAlim1(), restrictionAlim1()));
}

/****************************************************************************
* Fonction:	Frigo<T*>::recevoirMessage
* Description: Va suggérer un menu à la personne du message
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


