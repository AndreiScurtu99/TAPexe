#pragma once
#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
using namespace std;
class Angajat {
private :
	double tarifOrar ;
	int nrOre;
public:
	inline double getSalar(){return tarifOrar * nrOre;}
	inline double getTarifOrar(){ return tarifOrar;}
	Angajat(double tarifOrar=5.5, int nrOre=0);
	Angajat(const Angajat&);
	~Angajat();
	Angajat& operator=(const Angajat&);
	friend ostream& operator<<(ostream&, const Angajat&);
	friend istream& operator>>(istream&, Angajat&);
};
class Manager :public Angajat {
protected:
	int numarSubordonati;
public:
	Manager(double, int, int);
	Manager(const Manager&);
	~Manager();

};

#endif 