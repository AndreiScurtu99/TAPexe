#pragma once
#include <iostream>
#include <string>
#include <vector>
#ifndef CARTE_H
#define CARTE_H
using namespace std;

class Carte {
private:
	string autor;
	string titlu;
	string ISBN;
	double pret;
	static int nrInstante;
	static vector<Carte*> instante;
public:
	Carte(string autor, string titlu, string ISBN, double pret);
	Carte(string, string, string, double, int);
	Carte(const Carte& other);
	~Carte();

	inline string getAutor()const {
		return autor;
	}
	inline string getTitlu()const {
		return titlu;
	}
	inline string getISBN()const {
		return ISBN;
	}
	inline double getPret()const {
		return pret;
	}
	static int getNrInstante() {
		return nrInstante;
	}


	static void adaugaInstanta(Carte* carte);
	static void afisareCartiAutor(const string& autorCautat);
};


#endif // !CARTE_H

