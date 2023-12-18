#include <iostream>
#include "Angajat.h"
using namespace std;
Angajat::Angajat(double tarifOrar, int nrOre) : tarifOrar(tarifOrar), nrOre(nrOre){}
Angajat::Angajat(const Angajat& other) : tarifOrar(other.tarifOrar),nrOre(other.nrOre) {} 
Angajat::~Angajat(){}
Angajat& Angajat::operator=(const Angajat& other)
{
	this->tarifOrar = other.tarifOrar;
	this->nrOre = other.nrOre;
	return *this;
}
ostream& operator<<(ostream& os, const Angajat& angajat)
{
	os << "TarifOrar "<<angajat.tarifOrar << " ,Numar ore " << angajat.nrOre;
	return os;
}
istream& operator>>(istream& is, Angajat& angajat)
{
	is >> angajat.tarifOrar >> angajat.nrOre;
	return is;
}