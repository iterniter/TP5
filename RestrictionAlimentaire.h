#ifndef RESTRICTION_ALIMENTAIRE_H
#define RESTRICTION_ALIMENTAIRE_H

#include "Personne.h"
#include <string>

using namespace std;

template<typename T>

class RestrictionAlimentaire {
public:
	RestrictionAlimentaire(Personne* personne) : personne_(personne) {};
	bool operator()(T* element) { return (personne_->getPreferenceGout() == element->getSaveur()  && !(personne_->verifierAllergies(element))); }
private:
	Personne* personne_;
};

#endif