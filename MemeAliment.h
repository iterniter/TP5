#ifndef MEMEALIMENT_H
#define MEMEALIMENT_H

#include "Aliment.h"
#include <string>

using namespace std;

template<typename T>

class MemeAliment {
public:
	MemeAliment(Aliment* aliment) : aliment_(aliment) {};
	bool operator()(T* element) { return (element->getSaveur() == this->aliment_->getSaveur() && element->getNomAliment() == this->aliment_->getNomAliment()); }
	string getNomAliment() const { return aliment_->getNomAliment(); }
private:
	Aliment* aliment_;
};

#endif