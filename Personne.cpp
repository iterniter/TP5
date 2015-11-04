#include <cstdio>
#include "Personne.h"



using namespace std;

///__________________________________________________________________________________________________________________________
/// TP5
///__________________________________________________________________________________________________________________________

// TP5 A COMPLETER
/****************************************************************************
* Fonction:	Personne::Personne
* Description: Constructeur par parametres
* Parametres:  - (string) nom : nom de la Personne
*			   - (string) prenom : prenom de la Personne
*              - (unsigned int) agePersonne : age de la Personne
*              - (TYPE_GUSTATIF) preferenceGout
* Retour:		aucun
****************************************************************************/
Personne::Personne(string nom, string prenom, unsigned int age, TYPE_GUSTATIF preferenceGout) : nom_(nom), prenom_(prenom), age_(age), preferenceGout_(preferenceGout), estALaMaison_(false), numeroCellulaire_(" ")
{
}

/****************************************************************************
* Fonction:	Personne::getPreferenceGout
* Description: Getter
* Parametres:	aucun
* Retour:		- (TYPE_GUSTATIF) preferenceGout_
****************************************************************************/
TYPE_GUSTATIF Personne::getPreferenceGout() const
{
	return preferenceGout_;
}

/****************************************************************************
* Fonction:	Personne::setPreferenceGout
* Description: Setter
* Parametres:	aucun
* Retour:		- (TYPE_GUSTATIF) preferenceGout_
****************************************************************************/
void Personne::setPreferenceGout(TYPE_GUSTATIF nouvellePreference)
{
	preferenceGout_ = nouvellePreference;
}

/****************************************************************************
* Fonction:	Personne::verifierAllergies
* Description: Vérifie si l'allergie passée en parametre est dans listeAllergies_
* Parametres:	- (const string&) allergie
* Retour:		- (bool) present
****************************************************************************/
bool Personne::verifierAllergies(const string& allergie)
{
	
	bool present = false;

	for (list<string>::iterator iter = listeAllergies_.begin(); iter != listeAllergies_.end(); ++iter)
	{
		if (*iter == allergie)
			present = true;
	}

	return present;
}

/****************************************************************************
* Fonction:	Personne::ajouterAllergies
* Description: Ajoute l'allergie passée en parametre dans listeAllergies_ si elle n'est pas dejà présente
* Parametres:	- (const string&) allergie
* Retour:		aucun
****************************************************************************/
void Personne::ajouterAllergies(const string& allergie)
{
	if (!verifierAllergies(allergie))
		listeAllergies_.push_back(allergie);
}

///__________________________________________________________________________________________________________________________
/// TP2
///__________________________________________________________________________________________________________________________
bool Personne::operator==(const Personne& personne) const
{
	bool identique =
		(age_ == personne.age_) &&
		(prenom_ == personne.prenom_) &&
		(nom_ == personne.nom_);

	return identique;
}


bool Personne::operator< (const Personne& personne) const
{
	bool plusPetit;

	if (nom_ == personne.nom_)
	{
		plusPetit = prenom_ < personne.prenom_;
	}
	else
	{
		plusPetit = nom_ < personne.nom_;
	}

	return plusPetit;
}

ostream& operator<<(ostream& o, const Personne& personne)
{
	return o << personne.nom_ << " , " << personne.prenom_
		<< "\t-\t" << personne.age_ << " ans\t\t#" << personne.numeroCellulaire_ << "\n";
}

///__________________________________________________________________________________________________________________________
/// TP1
///__________________________________________________________________________________________________________________________
Personne::Personne() : age_(0), estALaMaison_(false)
{
}

Personne::~Personne()
{

}

string Personne::getNom() const
{
	return nom_;
}


void Personne::setNom(string nom)
{
	nom_ = nom;
}


string Personne::getPrenom() const
{
	return prenom_;
}


void Personne::setPrenom(string prenom)
{
	prenom_ = prenom;
}


unsigned int Personne::getAge() const
{
	return age_;
}


void Personne::setAge(unsigned int age)
{
	age_ = age;
}


bool Personne::estALaMaison() const
{
	return estALaMaison_;
}


void Personne::setEstALaMaison(bool estmaison)
{
	estALaMaison_ = estmaison;
}


void Personne::attribuerCellulaire(string numeroCellulaire)
{
	numeroCellulaire_ = numeroCellulaire;
}


string Personne::getNumeroCellulaire() const
{
	return numeroCellulaire_;
}

void Personne::setNumeroCellulaire(string nouveauNum)
{
	numeroCellulaire_ = nouveauNum;
}
