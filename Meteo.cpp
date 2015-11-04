#include "Meteo.h"

using namespace std;

Meteo::Meteo()
{
}

// TP5 A COMPLETER
string Meteo::obtenirNomClasse() const
{
	return typeid(Meteo).name();
}